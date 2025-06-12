#ifndef RESOURCE_H
#define RESOURCE_H
#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Resource {
public:
    Resource(const string &id,
             const string &title,
             const vector<string> &authors,
             int publicationYear,
             const string &category,
             const string &description);

    virtual ~Resource() = default;

    // Getters
    string getId() const;
    string getTitle() const;
    vector<string> getAuthors() const;
    int getPublicationYear() const;
    string getCategory() const;
    string getDescription() const;
    bool isAvailable() const;

    // Setters
    void setAvailability(bool available);
    void setDescription(const string &description);

    // Virtual method to get detailed info, override in child classes
    virtual string getDetails() const;

    // Borrow and return actions
    virtual void borrowResource();
    virtual void returnResource();

protected:
    string m_id;
    string m_title;
    vector<string> m_authors;
    int m_publicationYear;
    string m_category;
    bool m_isAvailable;
    string m_description;
};

#endif // RESOURCE_H
