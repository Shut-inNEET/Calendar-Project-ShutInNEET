#include <iostream>
#include <string>

#include "dateType.h"

using namespace std;

int dateType::longMonths[7] = {1, 3, 5, 7, 8, 10, 12};
int dateType::shortMonths[4] = {4, 6, 9, 11};
int dateType::daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30,
31, 30, 31};
int dateType::daysInLeapMonths[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30,
31, 30, 31};

dateType::dateType(int Month, int Day, int Year) 
{
  setDate(Month, Day, Year);
}

void dateType::setDate(int Month, int Day, int Year)
{
  for(int i = 0; i < 7; i++)
  {
    if(Day <= 31 && longMonths[i] == Month && Year >= 1900)
    {
      currentMonth = longMonths[i];
      currentDay = Day;
      currentYear = Year;
      return;
    }
    else if(Day <= 30 && Month == shortMonths[i] && Year >= 1900)
    {
      currentMonth = shortMonths[i];
      currentDay = Day;
      currentYear = Year;
      return;
    }
    else if(Day <= 29 && Month == 2 && Year >= 1900)
    {
      if(Year % 100 == 0 && Year % 400 == 0)
      {
        currentMonth = Month;
        currentDay = Day;
        currentYear = Year;
        return;
      }
      else if(Day <= 28 && Year % 100 == 0 && Year % 400 != 0)
      {
        currentMonth = Month;
        currentDay = Day;
        currentYear = Year;
        return;
      }
      else if(Year % 100 != 0 && Year % 4 == 0)
      {
        currentMonth = Month;
        currentDay = Day;
        currentYear = Year;
        return;
      }  
      else if(Day <= 28 && Year % 4 != 0)
      {
        currentMonth = Month;
        currentDay = Day;
        currentYear = Year;
        return;
      }
    }
  }
}

void dateType::setMonth(int Month)
{ 
  if(Month >= 1 && Month <= 12 && currentYear >= 1900)
  {
    for(int i = 0; i < 4; i++)
    {
        if(shortMonths[i] == Month && currentDay > 30)
        {
          currentMonth = Month;
          currentDay = 30;
          cout << "Setting month: " << Month << " (Adjusting days to month)" << endl;
          return;
        }      
    }      
    if(Month == 2 && currentYear % 100 == 0 && currentYear % 400 == 0 && currentDay > 29)
    {
      currentMonth = Month;
      currentDay = 29;
      cout << "Setting month: " << Month << " (Adjusting days to month)" << endl;
      return;
    }
    else if(Month == 2 && currentYear % 100 == 0 && currentYear % 400 != 0 && currentDay > 28)
    {
      currentMonth = Month;
      currentDay = 28;
      cout << "Setting month: " << Month << " (Adjusting days to month)" << endl;
      return;
    }
    else if(Month == 2 && currentYear % 100 != 0 && currentYear % 4 == 0 && currentDay > 29)
    {
      currentMonth = Month;
      currentDay = 29;
      cout << "Setting month: " << Month << " (Adjusting days to month)" << endl;
      return;
    }
    else if(Month == 2 && currentYear % 4 != 0 && currentDay > 28)
    {
      currentMonth = Month;
      currentDay = 28;
      cout << "Setting month: " << Month << " (Adjusting days to month)" << endl;
      return;
    } 
    else
    {
      currentMonth = Month;
      cout << "Setting month: " << Month << endl;
      return;
    }
  }
  else
  {
    cout << "Invalid month or invalid date needs to be changed first." << endl;
  }
}

void dateType::setDay(int Day)
{ 
  if(Day >= 1 && Day <= 31 && currentYear >= 1900)
  {
    for(int i = 0; i < 4; i++)
    {
        if(shortMonths[i] == currentMonth && Day > 30)
        {
          currentDay = 30;
          cout << "Setting day: " << Day << " (Adjusting days to month)" << endl;
          return;
        }      
    }      
    if(currentMonth == 2 && currentYear % 100 == 0 && currentYear % 400 == 0 && Day > 29)
    {
      currentDay = 29;
      cout << "Setting day: " << Day << " (Adjusting days to month)" << endl;
      return;
    }
    else if(currentMonth == 2 && currentYear % 100 == 0 && currentYear % 400 != 0 && Day > 28)
    {
      currentDay = 28;
      cout << "Setting day: " << Day << " (Adjusting days to month)" << endl;
      return;
    }
    else if(currentMonth == 2 && currentYear % 100 != 0 && currentYear % 4 == 0 && Day > 29)
    {
      currentDay = 29;
      cout << "Setting day: " << Day << " (Adjusting days to month)" << endl;
      return;
    }
    else if(currentMonth == 2 && currentYear % 4 != 0 && Day > 28)
    {
      currentDay = 28;
      cout << "Setting day: " << Day << " (Adjusting days to month)" << endl;
      return;
    } 
    else
    {
      currentDay = Day;
      cout << "Setting day: " << Day << endl;
      return;
    }
  }
  else
  {
    cout << "Invalid day or invalid date needs to be changed first." << endl;
  }
}

void dateType::setYear(int Year)
{ 
  if(Year >= 1900)
  {
    if(currentMonth == 2 && Year % 100 == 0 && Year % 400 != 0 && currentDay > 28)
    {
      currentYear = Year;
      currentDay = 28;
      cout << "Setting year: " << currentYear << " (Adjusting days to Year)" << endl;
      return;
    }
    else if(currentMonth == 2 && Year % 4 != 0 && currentDay > 28)
    {
      currentYear = Year;
      currentDay = 28;
      cout << "Setting year: " << currentYear << " (Adjusting days to Year)" << endl;
      return;
    }
    else
    {
      currentYear = Year;
      cout << "Setting year: " << currentYear << endl;
      return;
    }
  }
  else
  {
    cout << "Invalid year or invalid date needs to be changed first." << endl;
  }
}

int dateType::getMonth() const
{
  cout << "Month: " << currentMonth << endl;
  return currentMonth;
}

int dateType::getDay() const
{
  cout << "Day: " << currentDay << endl;
  return currentDay;
}

int dateType::getYear() const
{
  cout << "Year: " << currentYear << endl;
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
  bool x = leapYear();
  if(x == true)
  {
    for(int i = 0; i < 12; i++)
    {
      if(i + 1 == currentMonth)
      {
        cout << "Days in month: " << daysInLeapMonths[i] << endl;
        return daysInLeapMonths[i];
      }
    }
  }
  else
  {
    for(int i = 0; i < 12; i++)
    {
      if(i + 1 == currentMonth)
      {
        cout << "Days in month: " << daysInMonths[i] << endl;
        return daysInMonths[i];
      }
    }
  }
}

int dateType::getdaysLeft()
{ 
  daysLeft = 0;
  daysPassed = 0;
  
  bool x = leapYear();
  if(x == true)
  {
    cout << "Leap Year: True" << endl;
    
    for(int i = 0; i < currentMonth - 1; i++) 
    {
      daysPassed += daysInLeapMonths[i]; 
    }
    daysPassed += currentDay;  // include the days of the current month
    daysLeft = 366 - daysPassed;
    cout << "Days left in the year: " << daysLeft << endl; 
    return daysLeft;
  }
  else if(x == false)
  {
    cout << "Leap Year: False" << endl;
    
    for(int i = 0; i < currentMonth - 1; i++)
    {
      daysPassed += daysInMonths[i]; 
    }
    daysPassed += currentDay;  // include the days of the current month
    daysLeft = 365 - daysPassed;
    cout << "Days left in the year: " << daysLeft << endl;
    return daysLeft;
  }
}

int dateType::getdaysPassed()
{ 
  daysLeft = 0;
  daysPassed = 0;
  
  bool x = leapYear();
  if(x == true)
  { 
    for(int i = 0; i < currentMonth - 1; i++) 
    {
      daysPassed += daysInLeapMonths[i]; 
    }
    daysPassed += currentDay;  // include the days of the current month
    cout << "Days passed in the year: " << daysPassed << endl;
    return daysPassed;
  }
  else if(x == false)
  {
    for(int i = 0; i < currentMonth - 1; i++)
    {
      daysPassed += daysInMonths[i]; 
    }
    daysPassed += currentDay;  // include the days of the current month
    cout << "Days passed in the year: " << daysPassed << endl;
    return daysPassed;
  }
}
  
void dateType::addDays(int days) 
{
  while(days > 0)
  {
    int daysInCurrentMonth;

    if(leapYear() && currentMonth == 2)
    {
        daysInCurrentMonth = 29;
    }
    else
    {
      daysInCurrentMonth = daysInMonths[currentMonth-1];
    }

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
  if(abs(currentMonth) > 12 || abs(currentDay) > 31)
  {
    cout << "Invalid date." << endl;
    return;
  }
  else
  {
    cout << currentMonth << "-" << currentDay << "-" << currentYear << endl;
  }
}
