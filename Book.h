#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;
#include "Resource.h"
#include <string>

class Book : public Resource {
public:
    Book(const string &id,
         const string &title,
         const vector<string> &authors,
         int publicationYear,
         const string &category,
         const string &description,
         const string &isbn,
         const string &publisher,
         int numberOfPages);

    // Getters
    string getIsbn() const;
    string getPublisher() const;
    int getNumberOfPages() const;

    // Override details method to include book-specific info
    string getDetails() const override;

private:
    string m_isbn;
    string m_publisher;
    int m_numberOfPages;
};

#endif // BOOK_H
