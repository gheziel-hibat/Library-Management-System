#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
using namespace std;
#include <string>
#include <chrono>
#include <memory>

class Resource; // Forward declaration
class User;

enum class ReservationStatus {
    Active,
    Fulfilled,
    Cancelled
};

class Reservation {
public:
    Reservation(const string &reservationId,
                shared_ptr<Resource> resource,
                shared_ptr<User> reserver,
                const chrono::system_clock::time_point &reservationDate);

    string getReservationId() const;
    shared_ptr<Resource> getResource() const;
    shared_ptr<User> getReserver() const;
    chrono::system_clock::time_point getReservationDate() const;
    ReservationStatus getStatus() const;

    void cancelReservation();
    void fulfillReservation();

private:
    string m_reservationId;
    shared_ptr<Resource> m_resource;
    shared_ptr<User> m_reserver;
    chrono::system_clock::time_point m_reservationDate;
    ReservationStatus m_status;
};

#endif // RESERVATION_H
