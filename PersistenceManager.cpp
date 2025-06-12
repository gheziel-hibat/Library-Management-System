#include "PersistenceManager.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.h> // For JSON serialization - you need to add this dependency

using json = nlohmann::json;

// NOTE: These implementations are simplified placeholders and assume
// Resource/User/Loan/Reservation have to_json/from_json methods defined.

void PersistenceManager::saveResources(const std::vector<std::shared_ptr<Resource>>& resources, const std::string& filepath) {
    json jResources = json::array();
    for (const auto &res : resources) {
        // Assuming to_json overloads exist
        jResources.push_back(*res);
    }
    std::ofstream ofs(filepath);
    if (!ofs) {
        throw std::runtime_error("Unable to open file for writing: " + filepath);
    }
    ofs << jResources.dump(4);
    ofs.close();
}

std::vector<std::shared_ptr<Resource>> PersistenceManager::loadResources(const std::string& filepath) {
    std::ifstream ifs(filepath);
    if (!ifs) {
        std::cerr << "File not found or cannot be opened: " << filepath << std::endl;
        return {};
    }
    json jResources;
    ifs >> jResources;
    std::vector<std::shared_ptr<Resource>> resources;
    for (const auto &item : jResources) {
        // Here you would deserialize specific Resource subclass by category or type info
        // Simplified as just Resource for example
        auto res = std::make_shared<Resource>(
            item.at("id").get<std::string>(),
            item.at("title").get<std::string>(),
            item.at("authors").get<std::vector<std::string>>(),
            item.at("publicationYear").get<int>(),
            item.at("category").get<std::string>(),
            item.at("description").get<std::string>()
        );
        resources.push_back(res);
    }
    return resources;
}

void PersistenceManager::saveUsers(const std::vector<std::shared_ptr<User>>& users, const std::string& filepath) {
    // Similar as saveResources — serialize users to JSON and write to file
}

std::vector<std::shared_ptr<User>> PersistenceManager::loadUsers(const std::string& filepath) {
    // Similar as loadResources — deserialize and return vector<User>
    return {};
}

void PersistenceManager::saveLoans(const std::vector<std::shared_ptr<Loan>>& loans, const std::string& filepath) {
    // Similar as saveResources
}

std::vector<std::shared_ptr<Loan>> PersistenceManager::loadLoans(const std::string& filepath) {
    // Similar as loadResources
    return {};
}

void PersistenceManager::saveReservations(const std::vector<std::shared_ptr<Reservation>>& reservations, const std::string& filepath) {
    // Similar as saveResources
}

std::vector<std::shared_ptr<Reservation>> PersistenceManager::loadReservations(const std::string& filepath) {
    // Similar as loadResources
    return {};
}
