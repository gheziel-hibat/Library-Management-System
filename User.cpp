#include <iostream>
using namespace std;
#include "User.h"
#include "Resource.h"
#include "Loan.h"
#include "Reservation.h"
#include <stdexcept>

User::User(const string &userId,
           const string &name,
           const string &email,
           const string &phoneNumber,
           const string &address,
           int maxBorrowLimit)
    : m_userId(userId),
      m_name(name),
      m_email(email),
      m_phoneNumber(phoneNumber),
      m_address(address),
      m_maxBorrowLimit(maxBorrowLimit)
{}

string User::getUserId() const {
    return m_userId;
}

string User::getName() const {
    return m_name;
}

string User::getEmail() const {
    return m_email;
}

string User::getPhoneNumber() const {
    return m_phoneNumber;
}

string User::getAddress() const {
    return m_address;
}

int User::getMaxBorrowLimit() const {
    return m_maxBorrowLimit;
}

vector<shared_ptr<Loan>> User::getCurrentLoans() const {
    return m_currentLoans;
}

vector<shared_ptr<Reservation>> User::getReservationList() const {
    return m_reservationList;
}

void User::borrowResource(shared_ptr<Resource> resource) {
    if (static_cast<int>(m_currentLoans.size()) >= m_maxBorrowLimit) {
        throw runtime_error("Borrow limit reached.");
    }
    if (!resource->isAvailable()) {
        throw runtime_error("Resource is not available.");
    }
    resource->borrowResource();
    // Create new loan record (assuming Loan ctor sets loan date etc.)
    // This code assumes a Loan constructor that takes user and resource pointers
    m_currentLoans.push_back(make_shared<Loan>(resource, shared_ptr<User>(this, [](User*){})));
}

void User::returnResource(shared_ptr<Resource> resource) {
    // Find the loan for this resource and mark it returned
    auto it = find_if(m_currentLoans.begin(), m_currentLoans.end(),
                           [&resource](const shared_ptr<Loan>& loan) {
                               return loan->getResource()->getId() == resource->getId();
                           });
    if (it == m_currentLoans.end()) {
        throw runtime_error("No active loan found for this resource.");
    }
    (*it)->closeLoan();
    m_currentLoans.erase(it);
    resource->returnResource();
}

void User::renewLoan(shared_ptr<Loan> loan) {
    loan->extendDueDate();
}

void User::makeReservation(shared_ptr<Resource> resource) {
    // Create reservation for the resource
    m_reservationList.push_back(make_shared<Reservation>(resource, shared_ptr<User>(this, [](User*){})));
}

void User::cancelReservation(shared_ptr<Reservation> reservation) {
    auto it = find(m_reservationList.begin(), m_reservationList.end(), reservation);
    if (it != m_reservationList.end()) {
        (*it)->cancelReservation();
        m_reservationList.erase(it);
    } else {
        throw runtime_error("Reservation not found.");
    }
}

vector<shared_ptr<Loan>> User::viewBorrowHistory() const {
    return m_borrowHistory;
}

void User::setEmail(const string &email) {
    m_email = email;
}

void User::setPhoneNumber(const string &phoneNumber) {
    m_phoneNumber = phoneNumber;
}

void User::setAddress(const string &address) {
    m_address = address;
}
