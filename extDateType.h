#include "dateType.h"

using namespace std;

class extDateType : public dateType
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
  
  // Add days to the current date
  // Precondition: Input is an integer
  // Postcondition: The current date is updated by adding the inputed number of days
  void addDays(int);
  
  // Print contents of the date in the format of Month Day, Year
  // Precondition: None
  // Postcondition: The contents of the date are printed in the format of Month Day, Year
  void printLongDate() const;

  // Print contents of the date in the format of Month Year
  // Precondition: None
  // Postcondition: The contents of the date are printed in the format of Month Year
  void printLongMonthYear() const;
  
  // Constructor
  // Precondition: Inputs are integers
  // Postcondition: The currentMonth, currentDay, and currentYear are set
  extDateType(int month = 1, int day = 1, int year = 1900);

private:
  
  // monthString array will contain string representations of months
  static string monthString[13];
  
  // Representation of the current month as a string
  string strMonth;
};