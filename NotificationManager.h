#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <vector>
#include <memory>
#include <string>
#include "Notification.h"
#include "User.h"
#include "Loan.h"
#include "Reservation.h"
#include "Event.h"

class NotificationManager {
public:
    NotificationManager() = default;
    ~NotificationManager() = default;

    void sendDueDateReminder(std::shared_ptr<User> user, std::shared_ptr<Loan> loan);
    void sendReservationAvailable(std::shared_ptr<User> user, std::shared_ptr<Reservation> reservation);
    void sendEventNotification(std::shared_ptr<User> user, std::shared_ptr<Event> event);

    std::vector<std::shared_ptr<Notification>> getNotificationsForUser(const std::string& userId) const;

private:
    std::vector<std::shared_ptr<Notification>> m_notifications;

    void addNotification(const std::shared_ptr<Notification>& notification);
};

#endif // NOTIFICATIONMANAGER_H
