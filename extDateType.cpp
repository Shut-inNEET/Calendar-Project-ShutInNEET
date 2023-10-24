#include <iostream>
#include <string>

#include "extDateType.h"

using namespace std;

string extDateType::monthString[13] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

extDateType::extDateType(int month, int day, int year) : dateType(month, day, year)
{
  strMonth = monthString[month];
}

void extDateType::setDate(int month, int day, int year)
{
  dateType::setDate(month, day, year);
  strMonth = monthString[month];
}

void extDateType::setMonth(int month)
{
  dateType::setMonth(month);
  strMonth = monthString[month];
}

void extDateType::addDays(int days)     
{
  dateType::addDays(days);
  strMonth = monthString[dateType::getMonth()];
}

void extDateType::printLongDate() const
{
    cout << strMonth << " " << getDay() << ", " << getYear() << endl;
}

void extDateType::printLongMonthYear() const
{
    cout << strMonth << " " << getYear() << endl;
}