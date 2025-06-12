#include <iostream>
using namespace std;
#include "Notification.h"

Notification::Notification(const string &notificationId,
                           const string &message,
                           NotificationType type,
                           const chrono::system_clock::time_point &timestamp)
    : m_notificationId(notificationId),
      m_message(message),
      m_type(type),
      m_timestamp(timestamp)
{}

string Notification::getNotificationId() const {
    return m_notificationId;
}

string Notification::getMessage() const {
    return m_message;
}

NotificationType Notification::getType() const {
    return m_type;
}

chrono::system_clock::time_point Notification::getTimestamp() const {
    return m_timestamp;
}
