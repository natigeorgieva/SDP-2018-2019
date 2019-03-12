#ifndef DATE_H
#define DATE_H


class Date
{
public:
    Date(unsigned int nMonth = 1, unsigned int nYear = 1999);

    unsigned int getMonth()const;
    unsigned int getYear() const;

private:
    unsigned int month;
    unsigned int year;
};

#endif // DATE_H
