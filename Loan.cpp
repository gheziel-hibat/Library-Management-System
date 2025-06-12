#include <iostream>
using namespace std;
#include "Loan.h"
#include "Resource.h"
#include "User.h"
#include <sstream>
#include <iomanip>
#include <random>

Loan::Loan(shared_ptr<Resource> resource, shared_ptr<User> user)
    : m_resource(resource),
      m_user(user),
      m_loanDate(chrono::system_clock::now()),
      m_dueDate(chrono::system_clock::now() + chrono::hours(24 * 30)), // Default due in 30 days
      m_isReturned(false)
{
    // Generate a unique Loan ID
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(100000, 999999);
    m_loanId = "L-" + to_string(distrib(gen));
}

string Loan::getLoanId() const {
    return m_loanId;
}

shared_ptr<Resource> Loan::getResource() const {
    return m_resource;
}

shared_ptr<User> Loan::getUser() const {
    return m_user;
}

chrono::system_clock::time_point Loan::getLoanDate() const {
    return m_loanDate;
}

chrono::system_clock::time_point Loan::getDueDate() const {
    return m_dueDate;
}

bool Loan::isReturned() const {
    return m_isReturned;
}

void Loan::extendDueDate(int days) {
    if (m_isReturned) {
        throw runtime_error("Cannot extend due date for a returned loan.");
    }
    m_dueDate += chrono::hours(24 * days);
}

void Loan::closeLoan() {
    m_isReturned = true;
}
