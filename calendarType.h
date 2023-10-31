#include "dayType.h"
#include "extDateType.h"

using namespace std;

class calendarType 
{
public:
  // Sets the month
  // Precondition: month should be between 1-12
  // Postcondition: The month of the calendarType object is set
  void setMonth(int);

  // Sets the year
  // Precondition: year should be at or after the year 1900
  // Postcondition: The year of the calendarType object is set
  void setYear(int);
  
  // Returns the month
  // Precondition: month of the calendarType object has been set
  // Postcondition: returns the integer representation of the current month
  int getMonth() const;
  
  // Returns the year
  // Precondition: year of the calendarType object has been set
  // Postcondition: returns the current year
  int getYear() const;
  
  // Prints full month calendar of the current month and year
  // Precondition: month and year of the calendarType object has been set
  // Postcondition: prints the full calendar for the current month and year
  void printCalendar();
  
  // Constructor to initialize the calendarType object with a month and a year
  // Precondition: month should be between 1-12, year should be at or after the year 1900
  // Postcondition: calendarType object is initialized with the given month and year
  calendarType(int month, int year);

private:
  // Day of the week for the first day of the current month
  // Precondition: Day, month and year has been set
  // Postcondition: The first day of the month is calculated
  dayType firstDay;
  
  // First day of the current month and year
  // Precondition: Day, month and year has been set
  // Postcondition: The first date of the current month and year is calculated
  extDateType firstDate;
  
  // Sets the first day of the month
  // Precondition: month and year has been set
  // Postcondition: The firstDay variable is updated with the correct day of the week
  void firstDayOfMonth();
  
  // Prints the header of the calendar including the month and year
  // Precondition: month and year has been set
  // Postcondition: The header of the calendar for the current month and year is printed
  void printCalendarHeader();
  
  // Prints the full calendar for the current month (numbers of the days only)
  // Precondition: month, year, and first day of the month has been set
  // Postcondition: The full calendar for the current month is printed
  void printMonth();
};


