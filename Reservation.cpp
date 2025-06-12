#include <iostream>
using namespace std;
#include "Reservation.h"
#include <stdexcept>

Reservation::Reservation(const string &reservationId,
                         shared_ptr<Resource> resource,
                         shared_ptr<User> reserver,
                         const chrono::system_clock::time_point &reservationDate)
    : m_reservationId(reservationId),
      m_resource(resource),
      m_reserver(reserver),
      m_reservationDate(reservationDate),
      m_status(ReservationStatus::Active)
{}

string Reservation::getReservationId() const {
    return m_reservationId;
}

shared_ptr<Resource> Reservation::getResource() const {
    return m_resource;
}

shared_ptr<User> Reservation::getReserver() const {
    return m_reserver;
}

chrono::system_clock::time_point Reservation::getReservationDate() const {
    return m_reservationDate;
}

ReservationStatus Reservation::getStatus() const {
    return m_status;
}

void Reservation::cancelReservation() {
    if (m_status == ReservationStatus::Cancelled) {
        throw runtime_error("Reservation already cancelled.");
    }
    if (m_status == ReservationStatus::Fulfilled) {
        throw runtime_error("Cannot cancel a fulfilled reservation.");
    }
    m_status = ReservationStatus::Cancelled;
}

void Reservation::fulfillReservation() {
    if (m_status == ReservationStatus::Cancelled) {
        throw runtime_error("Cannot fulfill a cancelled reservation.");
    }
    if (m_status == ReservationStatus::Fulfilled) {
        throw runtime_error("Reservation already fulfilled.");
    }
    m_status = ReservationStatus::Fulfilled;
}
