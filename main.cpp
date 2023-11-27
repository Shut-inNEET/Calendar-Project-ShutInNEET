#include <iostream>
#include <string>

#include "calendarType.h"

using namespace std;

int main() 
{
  int month, year;

  while(true) 
  {
    try
    {
      cout << "Enter the month (1-12) and the year (YYYY) (enter -1 -1 to quit): ";
      cin >> month >> year;

      if(month == -1 && year == -1)
      {
        break; // Exit the loop
      }

      calendarType calendar(month, year); // Creates a calendar for user-defined month and year
      
      cout << endl;
      calendar.printCalendar(); // Print the calendar
    }
      
    catch (dateType::invalidYear e)
    {
      cout << "Exception: " << e.what() << "\n" << endl;
    }
    catch (dateType::invalidMonth e)
    {
      cout << "Exception: " << e.what() << "\n" << endl;
    }
  }
  cout << endl;
}