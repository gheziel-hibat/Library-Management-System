#include <iostream>
using namespace std;
#include "Event.h"
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>

Event::Event(const string &eventId,
             const string &title,
             const string &description,
             const chrono::system_clock::time_point &eventDate,
             const string &location)
    : m_eventId(eventId),
      m_title(title),
      m_description(description),
      m_eventDate(eventDate),
      m_location(location)
{}

string Event::getEventId() const {
    return m_eventId;
}

string Event::getTitle() const {
    return m_title;
}

string Event::getDescription() const {
    return m_description;
}

chrono::system_clock::time_point Event::getEventDate() const {
    return m_eventDate;
}

string Event::getLocation() const {
    return m_location;
}

string Event::getDetails() const {
    ostringstream oss;

    // Format the event date as YYYY-MM-DD HH:MM
    time_t time_t_date = chrono::system_clock::to_time_t(m_eventDate);
    tm tm_date{};
#if defined(_MSC_VER)
    localtime_s(&tm_date, &time_t_date);
#else
    localtime_s(&time_t_date, &tm_date);
#endif
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &tm_date);

    oss << "Event ID: " << m_eventId << "\n"
         << "Title: " << m_title << "\n"
         << "Description: " << m_description << "\n"
         << "Date: " << buffer << "\n"
         << "Location: " << m_location;

    return oss.str();
}
