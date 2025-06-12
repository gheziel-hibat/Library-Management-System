#include "NotificationManager.h"
#include <chrono>
#include <sstream>

void NotificationManager::sendDueDateReminder(std::shared_ptr<User> user, std::shared_ptr<Loan> loan) {
    std::ostringstream message;
    message << "Reminder: Your loan for \"" << loan->getResource()->getTitle() 
            << "\" is due on a soon approaching date.";
    auto notification = std::make_shared<Notification>(
        "N-" + std::to_string(m_notifications.size() + 1),
        message.str(),
        NotificationType::LoanDue,
        std::chrono::system_clock::now()
    );
    addNotification(notification);
    // In a real system, would trigger sending message/email here
}

void NotificationManager::sendReservationAvailable(std::shared_ptr<User> user, std::shared_ptr<Reservation> reservation) {
    std::ostringstream message;
    message << "Good news: The resource \"" << reservation->getResource()->getTitle()
            << "\" you reserved is now available.";
    auto notification = std::make_shared<Notification>(
        "N-" + std::to_string(m_notifications.size() + 1),
        message.str(),
        NotificationType::ReservationAvailable,
        std::chrono::system_clock::now()
    );
    addNotification(notification);
    // Similarly, trigger delivery of notification
}

void NotificationManager::sendEventNotification(std::shared_ptr<User> user, std::shared_ptr<Event> event) {
    std::ostringstream message;
    message << "Upcoming Event: " << event->getTitle() << " on scheduled date.";
    auto notification = std::make_shared<Notification>(
        "N-" + std::to_string(m_notifications.size() + 1),
        message.str(),
        NotificationType::General,
        std::chrono::system_clock::now()
    );
    addNotification(notification);
    // Trigger notify user about event
}

void NotificationManager::addNotification(const std::shared_ptr<Notification>& notification) {
    m_notifications.push_back(notification);
}

std::vector<std::shared_ptr<Notification>> NotificationManager::getNotificationsForUser(const std::string& userId) const {
    // In a real app, link notifications to users explicitly
    // Here, simply returning all for demo purposes
    return m_notifications;
}
