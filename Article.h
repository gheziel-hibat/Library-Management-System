#ifndef ARTICLE_H
#define ARTICLE_H
#include <iostream>
using namespace std;
#include "Resource.h"
#include <string>

class Article : public Resource {
public:
    Article(const string &id,
            const string &title,
            const vector<string> &authors,
            int publicationYear,
            const string &category,
            const string &description,
            const string &journalName,
            const string &volume,
            const string &issue,
            const string &doi);

    // Getters
    string getJournalName() const;
    string getVolume() const;
    string getIssue() const;
    string getDOI() const;

    // Override for details including article fields
    string getDetails() const override;

private:
    string m_journalName;
    string m_volume;
    string m_issue;
    string m_doi;
};

#endif // ARTICLE_H
