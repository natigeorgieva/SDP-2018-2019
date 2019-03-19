#include "date.h"

Date::Date(unsigned int nMonth, unsigned int nYear)
    : month(nMonth), year(nYear)
{}

unsigned int Date::getMonth() const
{
    return this->month;
}

unsigned int Date::getYear() const
{
    return this->year;
}
