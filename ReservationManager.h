#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "Reservation.h"
#include "User.h"
#include "Resource.h"

class ReservationManager {
public:
    ReservationManager() = default;
    ~ReservationManager() = default;

    void createReservation(std::shared_ptr<User> user, std::shared_ptr<Resource> resource, const std::string &reservationId);
    void cancelReservation(const std::string &reservationId);
    void fulfillReservation(const std::string &reservationId);
    std::vector<std::shared_ptr<Reservation>> getReservationsForResource(const std::string &resourceId) const;

private:
    std::vector<std::shared_ptr<Reservation>> m_reservations;
};

#endif // RESERVATIONMANAGER_H
