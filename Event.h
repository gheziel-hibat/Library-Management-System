#ifndef EVENT_H
#define EVENT_H
#include <iostream>
using namespace std;
#include <string>
#include <chrono>

class Event {
public:
    Event(const string &eventId,
          const string &title,
          const string &description,
          const chrono::system_clock::time_point &eventDate,
          const string &location);

    // Getters
    string getEventId() const;
    string getTitle() const;
    string getDescription() const;
    chrono::system_clock::time_point getEventDate() const;
    string getLocation() const;

    string getDetails() const;

private:
    string m_eventId;
    string m_title;
    string m_description;
    chrono::system_clock::time_point m_eventDate;
    string m_location;
};

#endif // EVENT_H
