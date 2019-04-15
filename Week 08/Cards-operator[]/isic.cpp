#include "isic.h"

ISIC::ISIC(const char* university, const char* name, const char* EGN
           , const char* faculty, const int facultyNumber,
           const char* ID, unsigned int month, unsigned int year)
    : date(Date(month, year)),name(NULL),university(NULL),faculty(NULL)
{
    this->setUniversity(university);
    setName(name);
    setEGN(EGN);
    setFaculty(faculty);
    setFacultyNumber(facultyNumber);
    setID(ID);
}

ISIC::~ISIC()
{
    delete[] name;
    delete[] faculty;
    delete[] university;

}

ISIC::ISIC(const ISIC& other) : name(NULL), university(NULL), faculty(NULL)
{
    this->setUniversity(other.university);
    this->setName(other.name);
    this->setEGN(other.EGN);
    this->setFaculty(other.faculty);
    this->facultyNumber = other.facultyNumber;
    this->setID(other.ID);
    this->date = other.date;
}

ISIC& ISIC::operator=(const ISIC& other)
{
    if (this != &other)
    {
        this->setUniversity(other.university);
        this->setName(other.name);
        this->setEGN(other.EGN);
        this->setFaculty(other.faculty);
        this->facultyNumber = other.facultyNumber;
        this->setID(other.ID);
        this->date = other.date;

    }
    return *(this);
}

const char* ISIC::getUniversity() const
{
    return university;
}

void ISIC::setUniversity(const char* nUniversity)
{
    delete[] university;
    university = new char[strlen(nUniversity) + 1];
    strcpy(university, nUniversity);
}

const char* ISIC::getName() const
{
    return name;
}

void ISIC::setName(const char* nName)
{
    delete[]name;
    name = new char[strlen(nName) + 1];
    strcpy(name, nName);
}

const char* ISIC::getEGN() const
{
    return EGN;
}

void ISIC::setEGN(const char* EGN)
{
    if (strlen(EGN) != 10)
    {
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (EGN[i] < '0' || EGN[i] > '9')
        {
            return;
        }
    }

    strcpy(this->EGN, EGN);
}

const char* ISIC::getFaculty() const
{
    return faculty;
}

void ISIC::setFaculty(const char* nFaculty)
{
    delete[]faculty;
    faculty = new char[strlen(nFaculty) + 1];
    strcpy(faculty, nFaculty);
}

int ISIC::getFacultyNumber() const
{
    return facultyNumber;
}

void ISIC::setFacultyNumber(int nFacultyNumber)
{
    facultyNumber = nFacultyNumber;
}

const char* ISIC::getID() const
{
    return ID;
}

void ISIC::setID(const char* nID)
{
    strcpy(ID, nID);
}

Date ISIC::getDate() const
{
    return date;
}

void ISIC::setDate(const Date nDate)
{
    date = nDate;
}

bool ISIC::isValid(const Date date) const
{
    if (date.getYear() > this->date.getYear())
    {
        return false;
    }

    if (date.getYear() < this->date.getYear())
    {
        return true;
    }

    if (date.getMonth() > this->date.getMonth())
    {
        return false;
    }

    return true;
}

