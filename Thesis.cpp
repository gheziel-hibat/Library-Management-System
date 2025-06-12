#include <iostream>
using namespace std;
#include "Thesis.h"
#include <sstream>

Thesis::Thesis(const string &id,
               const string &title,
               const vector<string> &authors,
               int publicationYear,
               const string &category,
               const string &description,
               const string &university,
               const string &degree,
               const string &advisor)
    : Resource(id, title, authors, publicationYear, category, description),
      m_university(university),
      m_degree(degree),
      m_advisor(advisor)
{}

string Thesis::getUniversity() const {
    return m_university;
}

string Thesis::getDegree() const {
    return m_degree;
}

string Thesis::getAdvisor() const {
    return m_advisor;
}

string Thesis::getDetails() const {
    ostringstream oss;
    oss << Resource::getDetails() << "\n"
        << "University: " << m_university << "\n"
        << "Degree: " << m_degree << "\n"
        << "Advisor: " << m_advisor;
    return oss.str();
}
