#ifndef THESIS_H
#define THESIS_H
#include <iostream>
using namespace std;
#include "Resource.h"
#include <string>

class Thesis : public Resource {
public:
    Thesis(const string &id,
           const string &title,
           const vector<string> &authors,
           int publicationYear,
           const string &category,
           const string &description,
           const string &university,
           const string &degree,
           const string &advisor);

    // Getters
    string getUniversity() const;
    string getDegree() const;
    string getAdvisor() const;

    // Override details method to include thesis-specific info
    string getDetails() const override;

private:
    string m_university;
    string m_degree;
    string m_advisor;
};

#endif // THESIS_H
