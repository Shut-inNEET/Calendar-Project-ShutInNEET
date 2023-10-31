#include <iostream>
#include <string>

#include "calendarType.h"

using namespace std;

int main() 
{
  calendarType calendar(1, 2022); // Creates a calendar for January 2022
  calendar.printCalendar(); // Prints the calendar
  
  calendar.setMonth(2); // Set the month to Febuary
  calendar.setYear(2024); // Set the year to 2024
  calendar.printCalendar(); // Print the calendar
  
  return 0;
}