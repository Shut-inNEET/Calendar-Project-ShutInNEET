#include <iostream>
#include <string>
#include "dateType.h"

using namespace std;

int main() 
{
  dateType date1;

  cout << "From default constructor: ";
  date1.printDate();

  dateType date2(1, 30, 1904);
  
  cout << "From constructor with parameter: ";
  date2.printDate();
  
  date2.setMonth(12);
  cout << "Month: " << date2.getMonth() << endl;
  date2.printDate();
  
  date2.setDay(2);
  cout << "Day: " << date2.getDay() << endl;
  date2.printDate();

  date2.setYear(1902);
  cout << "Year: " << date2.getYear() << endl;
  date2.printDate();

  cout << "Days in month: " << date2.getDaysinMonth() << endl;
  
  cout << "Days left in the year: " << date2.getdaysLeft() << endl;
  cout << "Days passed in the year: " << date2.getdaysPassed() << endl;
  
  date2.addDays(30);
  cout << "After adding 30 days: ";
  date2.printDate();

  return 0;
}
