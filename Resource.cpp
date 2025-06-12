#include <iostream>
using namespace std;
#include "Resource.h"
#include <sstream>

Resource::Resource(const string &id,
                   const string &title,
                   const vector<string> &authors,
                   int publicationYear,
                   const string &category,
                   const string &description)
    : m_id(id),
      m_title(title),
      m_authors(authors),
      m_publicationYear(publicationYear),
      m_category(category),
      m_description(description),
      m_isAvailable(true) // default to available
{}

string Resource::getId() const {
    return m_id;
}

string Resource::getTitle() const {
    return m_title;
}

vector<string> Resource::getAuthors() const {
    return m_authors;
}

int Resource::getPublicationYear() const {
    return m_publicationYear;
}

string Resource::getCategory() const {
    return m_category;
}

string Resource::getDescription() const {
    return m_description;
}

bool Resource::isAvailable() const {
    return m_isAvailable;
}

void Resource::setAvailability(bool available) {
    m_isAvailable = available;
}

void Resource::setDescription(const string &description) {
    m_description = description;
}

string Resource::getDetails() const {
    ostringstream oss;
    oss << "Title: " << m_title << "\n"
        << "Authors: ";
    for (size_t i = 0; i < m_authors.size(); ++i) {
        oss << m_authors[i];
        if(i != m_authors.size() -1) oss << ", ";
    }
    oss << "\nPublication Year: " << m_publicationYear << "\n"
        << "Category: " << m_category << "\n"
        << "Description: " << m_description << "\n"
        << "Available: " << (m_isAvailable ? "Yes" : "No");
    return oss.str();
}

void Resource::borrowResource() {
    if(m_isAvailable) {
        m_isAvailable = false;
    } else {
        throw runtime_error("Resource is not available for borrowing.");
    }
}

void Resource::returnResource() {
    m_isAvailable = true;
}
