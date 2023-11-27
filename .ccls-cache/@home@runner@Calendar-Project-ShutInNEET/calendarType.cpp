#include<iostream>
#include<iomanip>

#include "calendarType.h"

using namespace std;

calendarType::calendarType(int month, int year)
{
  firstDay.setDay("Monday");
  firstDate.setDate(month, 1, year);
  firstDayOfMonth();
}

void calendarType::firstDayOfMonth()
{
    int numOfLeapYears = ((firstDate.getYear() - 1) / 4) - ((firstDate.getYear() - 1) / 100) + ((firstDate.getYear() - 1) / 400) - ((1900 - 1) / 4) + ((1900 - 1) / 100) - ((1900 - 1) / 400);
    int numOfDays = ((firstDate.getYear() - 1900) * 365) + numOfLeapYears + firstDate.getdaysPassed(); 
    firstDay.setDay(dayType::getWeekDay(numOfDays % 7));
}

void calendarType::setMonth(int month)
{
    firstDate.setMonth(month);
    firstDayOfMonth();
}

void calendarType::setYear(int year)
{
    firstDate.setYear(year);
    firstDayOfMonth();
}

int calendarType::getMonth() const
{
  return firstDate.getMonth();
}

int calendarType::getYear() const
{
  return firstDate.getYear();
}

void calendarType::printCalendar()
{
    printCalendarHeader();
    printMonth();
}

void calendarType::printCalendarHeader()
{
  string monthName; 
  int year = firstDate.getYear();
  switch (getMonth()) 
  {
    case 1:
      monthName = "January";
      break;

    case 2:
      monthName = "February";
      break;   

    case 3:
      monthName = "March";
      break;

    case 4:
      monthName = "April";
      break;

    case 5:
      monthName = "May";
      break;

    case 6:
      monthName = "June";
      break;

    case 7:
      monthName = "July";
      break;

    case 8:
      monthName = "August";
      break;

    case 9:
      monthName = "September";
      break;

    case 10:
      monthName = "October";
      break;

    case 11:
      monthName = "November";
      break;

    case 12:
      monthName = "December";       
      break;

    default:
      monthName = "Invalid month";       
  }  
  
  cout << setw(22) << monthName << " " << year << endl;
  cout << "---------------------------------------------" << endl;
  cout << "   Sun   Mon   Tue   Wed   Thu   Fri   Sat" << endl;
  cout << "---------------------------------------------" << endl;
}

void calendarType::printMonth()
{
    int monthDays = firstDate.getDaysinMonth();
    int dayOfWeek = firstDay.getDayNumber();
    int day = 1;
    for(int i = 0; i < 6; i++) 
    {
        for(int j = 0; j < 7; j++) 
        {
            if( (i > 0 || j >= dayOfWeek) && day <= monthDays)
            {
                cout << setw(6) << day;
                day++;
            } 
            else 
            {
                cout << setw(6) << " ";
            }
            
            // Print a newline after every seventh day (end of the week)
            if(j == 6)
            {
                cout << endl;
            }
        }
    }
    cout << "---------------------------------------------\n" << endl;
}