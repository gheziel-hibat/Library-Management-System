#include <iostream>
using namespace std;
#include "Book.h"
#include <sstream>

Book::Book(const string &id,
           const string &title,
           const vector<string> &authors,
           int publicationYear,
           const string &category,
           const string &description,
           const string &isbn,
           const string &publisher,
           int numberOfPages)
    : Resource(id, title, authors, publicationYear, category, description),
      m_isbn(isbn),
      m_publisher(publisher),
      m_numberOfPages(numberOfPages)
{}

string Book::getIsbn() const {
    return m_isbn;
}

string Book::getPublisher() const {
    return m_publisher;
}

int Book::getNumberOfPages() const {
    return m_numberOfPages;
}

string Book::getDetails() const {
    ostringstream oss;
    oss << Resource::getDetails() << "\n"
        << "ISBN: " << m_isbn << "\n"
        << "Publisher: " << m_publisher << "\n"
        << "Pages: " << m_numberOfPages;
    return oss.str();
}
