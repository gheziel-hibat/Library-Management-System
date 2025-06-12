#include "UserManager.h"
#include <stdexcept>

void UserManager::addUser(std::shared_ptr<User> user) {
    m_users.push_back(user);
}

void UserManager::removeUser(const std::string &userId) {
    auto it = std::remove_if(m_users.begin(), m_users.end(),
                             [&userId](const std::shared_ptr<User> &user) {
                                 return user->getUserId() == userId;
                             });
    if (it != m_users.end()) {
        m_users.erase(it, m_users.end());
    } else {
        throw std::runtime_error("User with ID not found: " + userId);
    }
}

std::shared_ptr<User> UserManager::findUserById(const std::string &userId) const {
    auto it = std::find_if(m_users.begin(), m_users.end(),
                           [&userId](const std::shared_ptr<User> &user) {
                               return user->getUserId() == userId;
                           });
    if (it != m_users.end()) {
        return *it;
    }
    return nullptr;
}

std::vector<std::shared_ptr<User>> UserManager::searchUsersByName(const std::string &name) const {
    std::vector<std::shared_ptr<User>> results;
    for (const auto &user : m_users) {
        if (user->getName().find(name) != std::string::npos) {
            results.push_back(user);
        }
    }
    return results;
}

std::vector<std::shared_ptr<User>> UserManager::getAllUsers() const {
    return m_users;
}

void UserManager::updateUser(std::shared_ptr<User> updatedUser) {
    auto it = std::find_if(m_users.begin(), m_users.end(),
                           [&updatedUser](const std::shared_ptr<User> &user) {
                               return user->getUserId() == updatedUser->getUserId();
                           });
    if (it != m_users.end()) {
        *it = updatedUser;
    } else {
        throw std::runtime_error("User to update not found: " + updatedUser->getUserId());
    }
}

bool UserManager::authenticateUser(const std::string &email, const std::string &password) const {
    // NOTE: This method is a stub. Password managing requires secure hashing.
    for (const auto &user : m_users) {
        if (user->getEmail() == email) {
            // Accept any password for demonstration
            return true;
        }
    }
    return false;
}
