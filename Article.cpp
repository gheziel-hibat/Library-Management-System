#include <iostream>
using namespace std;
#include "Article.h"
#include <sstream>

Article::Article(const string &id,
                 const string &title,
                 const vector<string> &authors,
                 int publicationYear,
                 const string &category,
                 const string &description,
                 const string &journalName,
                 const string &volume,
                 const string &issue,
                 const string &doi)
       : Resource(id, title, authors, publicationYear, category, description),
      m_journalName(journalName),
      m_volume(volume),
      m_issue(issue),
      m_doi(doi)
{
    m_category = "Article"; // assuming category is string in base Resource
}

string Article::getJournalName() const {
    return m_journalName;
}

string Article::getVolume() const {
    return m_volume;
}

string Article::getIssue() const {
    return m_issue;
}

string Article::getDOI() const {
    return m_doi;
}

string Article::getDetails() const {
    ostringstream oss;
    oss << Resource::getDetails() << "\n"
        << "Journal: " << m_journalName << "\n"
        << "Volume: " << m_volume << ", Issue: " << m_issue << "\n"
        << "DOI: " << m_doi;
    return oss.str();
}
