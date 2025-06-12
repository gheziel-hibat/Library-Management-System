#include <iostream>
using namespace std;
#include "DigitalContent.h"
#include <sstream>
#include <iomanip>

DigitalContent::DigitalContent(const string &id,
                               const string &title,
                               const vector<string> &authors,
                               int publicationYear,
                               const string &category,
                               const string &description,
                               const string &fileFormat,
                               double fileSize,
                               const string &downloadUrl)
    : Resource(id, title, authors, publicationYear, category, description),
      m_fileFormat(fileFormat),
      m_fileSize(fileSize),
      m_downloadUrl(downloadUrl)
{}

string DigitalContent::getFileFormat() const {
    return m_fileFormat;
}

double DigitalContent::getFileSize() const {
    return m_fileSize;
}

string DigitalContent::getDownloadUrl() const {
    return m_downloadUrl;
}

string DigitalContent::getDetails() const {
    ostringstream oss;
    oss << Resource::getDetails() << "\n"
        << "File Format: " << m_fileFormat << "\n"
        << "File Size: " << fixed << setprecision(2) << m_fileSize << " MB\n"
        << "Download URL: " << m_downloadUrl;
    return oss.str();
}
