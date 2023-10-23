#include <iostream>
#include <string>
using namespace std;
class dateType
{
public:
  
  // Set the date
  // Precondition: Inputs are integers
  // Postcondition: The currentMonth, currentDay, and currentYear are set
  void setDate(int, int, int);
  
  // Set the month
  // Precondition: Input is an integer
  // Postcondition: The currentMonth is set
  void setMonth(int);
  
  // Set the day
  // Precondition: Input is an integer
  // Postcondition: The currentDay is set
  void setDay(int);
  
  // Set the year
  // Precondition: Input is an integer
  // Postcondition: The currentYear is set
  void setYear(int);
  
  // Get the month
  // Precondition: None
  // Postcondition: Return the currentMonth
  int getMonth() const;
  
  // Get the day
  // Precondition: None
  // Postcondition: Return the currentDay
  int getDay() const;
  
  // Get the year
  // Precondition: None
  // Postcondition: Return the currentYear
  int getYear() const;
  
  // Identify if the year is a leap year
  // Precondition: currentYear has been intialized
  // Postcondition: Return true if the year is a leap year and false if not
  bool leapYear() const;
  
  // Get the number of days in the current month
  // Precondition: currentMonth has been initialized
  // Postcondition: Return the number of days in the currentMonth
  int getDaysinMonth() const;
  
  // Get the number of days remaining in the year
  // Precondition: currentMonth, currentDay, and currentYear have been initialized
  // Postcondition: Return the number of days left in the year
  int getdaysLeft();
  
  // Get the number of days that have passed in the year
  // Precondition: currentMonth, currentDay, and currentYear have been initialized
  // Postcondition: Return the number of days that have passed in the year
  int getdaysPassed();
  
  // Add days to the current date
  // Precondition: Input is an integer
  // Postcondition: The current date is updated by adding the inputed number of days
  void addDays(int);
  
  // Prints the current date
  // Precondition: currentMonth, currentDay, and currentYear have been initialized
  // Postcondition: Prints the currentMonth, currentDay, and currentYear to the console
  void printDate() const;
  
  // Default constructor
  // Precondition: Input are integers
  // Postcondition: The dateType object is created with the inputed month, day, and year
  dateType(int = 1, int = 1, int = 1900);

private:
  
  //List of total days in non-leap year
  static int daysInMonths[12];
  
  // Int variables to store the current month, day, and year
  int currentMonth;
  int currentDay;
  int currentYear;
};