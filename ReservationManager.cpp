#include "ReservationManager.h"
#include <stdexcept>
#include <chrono>

void ReservationManager::createReservation(std::shared_ptr<User> user, std::shared_ptr<Resource> resource, const std::string &reservationId) {
    auto now = std::chrono::system_clock::now();
    auto reservation = std::make_shared<Reservation>(reservationId, resource, user, now);
    m_reservations.push_back(reservation);
    user->makeReservation(reservation);
}

void ReservationManager::cancelReservation(const std::string &reservationId) {
    auto it = std::find_if(m_reservations.begin(), m_reservations.end(),
                           [&reservationId](const std::shared_ptr<Reservation> &res) {
                               return res->getReservationId() == reservationId;
                           });
    if (it == m_reservations.end()) {
        throw std::runtime_error("Reservation ID not found.");
    }
    (*it)->cancelReservation();
    auto user = (*it)->getReserver();
    user->cancelReservation(*it);
    m_reservations.erase(it);
}

void ReservationManager::fulfillReservation(const std::string &reservationId) {
    auto it = std::find_if(m_reservations.begin(), m_reservations.end(),
                           [&reservationId](const std::shared_ptr<Reservation> &res) {
                               return res->getReservationId() == reservationId;
                           });
    if (it == m_reservations.end()) {
        throw std::runtime_error("Reservation ID not found.");
    }
    (*it)->fulfillReservation();
}

std::vector<std::shared_ptr<Reservation>> ReservationManager::getReservationsForResource(const std::string &resourceId) const {
    std::vector<std::shared_ptr<Reservation>> results;
    for (const auto &res : m_reservations) {
        if (res->getResource()->getId() == resourceId && res->getStatus() == ReservationStatus::Active) {
            results.push_back(res);
        }
    }
    return results;
}
