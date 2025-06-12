#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class Resource;  // Forward declaration
class Loan;
class Reservation;

class User {
public:
    User(const string &userId,
         const string &name,
         const string &email,
         const string &phoneNumber,
         const string &address,
         int maxBorrowLimit);

    ~User() = default;

    // Getters
    string getUserId() const;
    string getName() const;
    string getEmail() const;
    string getPhoneNumber() const;
    string getAddress() const;
    int getMaxBorrowLimit() const;

    vector<shared_ptr<Loan>> getCurrentLoans() const;
    vector<shared_ptr<Reservation>> getReservationList() const;

    // User actions
    void borrowResource(shared_ptr<Resource> resource);
    void returnResource(shared_ptr<Resource> resource);
    void renewLoan(shared_ptr<Loan> loan);
    void makeReservation(shared_ptr<Resource> resource);
    void cancelReservation(shared_ptr<Reservation> reservation);
    vector<shared_ptr<Loan>> viewBorrowHistory() const;

    // Modifiers to update contact info
    void setEmail(const string &email);
    void setPhoneNumber(const string &phoneNumber);
    void setAddress(const string &address);

private:
    string m_userId;
    string m_name;
    string m_email;
    string m_phoneNumber;
    string m_address;
    int m_maxBorrowLimit;

    vector<shared_ptr<Loan>> m_currentLoans;
    vector<shared_ptr<Reservation>> m_reservationList;
    vector<shared_ptr<Loan>> m_borrowHistory;
};

#endif // USER_H
