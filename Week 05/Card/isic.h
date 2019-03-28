#ifndef ISIC_H
#define ISIC_H

#include <cmath>
#include <string.h>
#include "date.h"

using namespace std;

class ISIC
{
public:
    ISIC(const char* university = "SU", const char* name = "unnamed", const char* EGN = "0000000000", const char* faculty = "FMI", const int facultyNumber = 31000,
         const char* ID = "SDF6565QWERT1235", unsigned int month = 0, unsigned int year = 0);

    ISIC(const ISIC&);

    ISIC& operator=(const ISIC&);

    ~ISIC();

    const char* getUniversity() const;

    void setUniversity(const char* nUniversity);

    const char* getName() const;

    void setName(const char* nName);

    const char* getEGN() const;

    void setEGN(const char* EGN);

    const char* getFaculty() const;

    void setFaculty(const char* nFaculty);

    int getFacultyNumber() const;

    void setFacultyNumber(int nFacultyNumber);

    const char* getID() const;

    void setID(const char* nID);

    Date getDate() const;

    void setDate(const Date nDate);

    bool isValid(const Date date) const;

private:
    char* university;
    char* name;
    char EGN[11];
    char* faculty;
    int facultyNumber;
    char ID[17];
    Date date;
};

#endif // ISIC_H
