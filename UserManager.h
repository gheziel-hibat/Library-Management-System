#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "User.h"

class UserManager {
public:
    UserManager() = default;
    ~UserManager() = default;

    void addUser(std::shared_ptr<User> user);
    void removeUser(const std::string &userId);
    std::shared_ptr<User> findUserById(const std::string &userId) const;
    std::vector<std::shared_ptr<User>> searchUsersByName(const std::string &name) const;
    std::vector<std::shared_ptr<User>> getAllUsers() const;

    void updateUser(std::shared_ptr<User> updatedUser);

    bool authenticateUser(const std::string &email, const std::string &password) const;

private:
    // In a real system, passwords would be hashed and stored securely.
    std::vector<std::shared_ptr<User>> m_users;
};

#endif // USERMANAGER_H
