#include <iostream>
#include <string>

#include "dateType.h"

using namespace std;

int dateType::daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30,
31, 30, 31};

dateType::dateType(int Month, int Day, int Year) 
{
  setDate(Month, Day, Year);
}

void dateType::setDate(int Month, int Day, int Year) 
throw (invalidYear, invalidMonth, invalidDay)
{
  daysInMonths[1] = leapYear() ? 29 : 28; // adjust February days based on leap year
  
  if (Year < 1900)
  {
    throw invalidYear();
  }
  else
  {
    currentYear = Year;
  }
  
  if (Month < 1 || Month > 12)
  {
    throw invalidMonth();
  }
  else
  {
    currentMonth = Month;
  }
  
  if (Day < 1 || Day > daysInMonths[Month-1])
  {
    throw invalidDay();
  }
  else
  {
    currentDay = Day;
  }
}

void dateType::setMonth(int Month)
{ 
  setDate(Month, currentDay, currentYear);
}

void dateType::setDay(int Day)
{ 
  setDate(currentMonth, Day, currentYear);
}

void dateType::setYear(int Year)
{
  setDate(currentMonth, currentDay, Year);
}

int dateType::getMonth() const
{
  return currentMonth;
}

int dateType::getDay() const
{
  return currentDay;
}

int dateType::getYear() const
{
  return currentYear;
}

bool dateType::leapYear() const
{
  if(currentYear % 100 == 0 && currentYear % 400 == 0)
  {
    return true;
  }
  else if(currentYear % 100 == 0 && currentYear % 400 != 0)
  {
    return false;
  }
  else if(currentYear % 100 != 0 && currentYear % 4 == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int dateType::getDaysinMonth() const
{
  daysInMonths[1] = leapYear() ? 29 : 28; // adjust February days based on leap year
  
  return daysInMonths[currentMonth - 1];
}

int dateType::getdaysLeft()
{ 
  int daysPassed = getdaysPassed();
  
  int daysLeft = leapYear() ? 366 - daysPassed : 365 - daysPassed; 
  
  return daysLeft;
}

int dateType::getdaysPassed()
{ 
  getDaysinMonth();
  int daysPassed = 0;
  
  for(int i = 0; i < currentMonth - 1; i++) 
  {
    daysPassed += daysInMonths[i]; 
  }
  
  daysPassed += currentDay;  // include the days of the current month 
  return daysPassed;
}
  
void dateType::addDays(int days) 
{
  while(days > 0)
  {
    int daysInCurrentMonth = getDaysinMonth();

    if(currentDay + days <= daysInCurrentMonth)
    {
      currentDay += days;
      days = 0;
    }  
    else 
    {  
      days -= (daysInCurrentMonth - currentDay + 1);
      currentDay = 1;
      currentMonth += 1;

      if(currentMonth > 12)
      {
        currentMonth = 1;
        currentYear += 1;
      }
    }
  }
}

void dateType::printDate() const
{
  cout << currentMonth << "-" << currentDay << "-" << currentYear << endl;
}
