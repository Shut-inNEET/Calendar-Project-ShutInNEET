#include <iostream>
#include <string>

#include "calendarType.h"

using namespace std;

int main() 
{
  int month, year;
  
  while(true) 
  {
    cout << "Enter the month (1-12) and the year (YYYY) (enter -1 -1 to quit): ";
    cin >> month >> year;
    cout << endl;
    
    if(month == -1 && year == -1)
    {
      break; // Exit the loop
    }
    
    calendarType calendar(month, year); // Creates a calendar for user-defined month and year
    calendar.printCalendar(); // Print the calendar
  }
  cout << endl;
  
  return 0;
}