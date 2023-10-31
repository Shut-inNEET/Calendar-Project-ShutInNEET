#include <iostream>
#include <string>

#include "calendarType.h"

using namespace std;

int main() 
{
  calendarType calendar(1, 2022); // Creates a calendar for January 2022
  
  calendar.printCalendar(); // Print the calendar
  
  return 0;
}