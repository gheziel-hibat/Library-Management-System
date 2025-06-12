#ifndef LOAN_H
#define LOAN_H
#include <iostream>
using namespace std;
#include <string>
#include <chrono>
#include <memory>

class Resource; // Forward declaration
class User;

class Loan {
public:
    Loan(shared_ptr<Resource> resource, shared_ptr<User> user);

    // Getters
    string getLoanId() const;
    shared_ptr<Resource> getResource() const;
    shared_ptr<User> getUser() const;
    chrono::system_clock::time_point getLoanDate() const;
    chrono::system_clock::time_point getDueDate() const;
    bool isReturned() const;

    // Actions
    void extendDueDate(int days = 14); // Default extension of 2 weeks
    void closeLoan();

private:
    string m_loanId;
    shared_ptr<Resource> m_resource;
    shared_ptr<User> m_user;
    chrono::system_clock::time_point m_loanDate;
    chrono::system_clock::time_point m_dueDate;
    bool m_isReturned;
};

#endif // LOAN_H
