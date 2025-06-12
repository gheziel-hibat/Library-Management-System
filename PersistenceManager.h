#ifndef PERSISTENCEMANAGER_H
#define PERSISTENCEMANAGER_H

#include <string>
#include <vector>
#include <memory>
#include "Resource.h"
#include "User.h"
#include "Loan.h"
#include "Reservation.h"

class PersistenceManager {
public:
    PersistenceManager() = default;
    ~PersistenceManager() = default;

    // Save data
    void saveResources(const std::vector<std::shared_ptr<Resource>>& resources, const std::string& filepath);
    void saveUsers(const std::vector<std::shared_ptr<User>>& users, const std::string& filepath);
    void saveLoans(const std::vector<std::shared_ptr<Loan>>& loans, const std::string& filepath);
    void saveReservations(const std::vector<std::shared_ptr<Reservation>>& reservations, const std::string& filepath);

    // Load data
    std::vector<std::shared_ptr<Resource>> loadResources(const std::string& filepath);
    std::vector<std::shared_ptr<User>> loadUsers(const std::string& filepath);
    std::vector<std::shared_ptr<Loan>> loadLoans(const std::string& filepath);
    std::vector<std::shared_ptr<Reservation>> loadReservations(const std::string& filepath);

private:
    // Helpers for serialization/deserialization could be added here
};

#endif // PERSISTENCEMANAGER_H
