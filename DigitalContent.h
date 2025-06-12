#ifndef DIGITALCONTENT_H
#define DIGITALCONTENT_H
#include <iostream>
using namespace std;
#include "Resource.h"
#include <string>

class DigitalContent : public Resource {
public:
    DigitalContent(const string &id,
                   const string &title,
                   const vector<string> &authors,
                   int publicationYear,
                   const string &category,
                   const string &description,
                   const string &fileFormat,
                   double fileSize, // in MB
                   const string &downloadUrl);

    // Getters
    string getFileFormat() const;
    double getFileSize() const;
    string getDownloadUrl() const;
    string getDetails() const override;

private:
    string m_fileFormat;
    double m_fileSize;
    string m_downloadUrl;
};

#endif // DIGITALCONTENT_H
