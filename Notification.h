#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <iostream>
using namespace std;
#include <string>
#include <chrono>

enum class NotificationType {
    LoanDue,
    ReservationAvailable,
    General
};

class Notification {
public:
    Notification(const string &notificationId,
                 const string &message,
                 NotificationType type,
                 const chrono::system_clock::time_point &timestamp);

    // Getters
    string getNotificationId() const;
    string getMessage() const;
    NotificationType getType() const;
    chrono::system_clock::time_point getTimestamp() const;

private:
    string m_notificationId;
    string m_message;
    NotificationType m_type;
    chrono::system_clock::time_point m_timestamp;
};

#endif // NOTIFICATION_H
