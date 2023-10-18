#include <iostream>
#include <string>
#include "dateType.h"

using namespace std;

int main() 
{
  dateType date1;

  cout << "From default constructor: ";
  date1.printDate();

  dateType date2(4, 30, 1904);
  
  cout << "From constructor with parameter: ";
  date2.printDate();
  
  date2.setMonth(1);
  date2.getMonth();
  date2.printDate();
  
  date2.setDay(20);
  date2.getDay();
  date2.printDate();
  
  date2.setYear(2004);
  date2.getYear();
  date2.printDate();

  date2.leapYear();
  date2.getDaysinMonth();
  
  date2.getdaysLeft();
  date2.getdaysPassed();
  
  date2.addDays(30);
  cout << "After adding 30 days: ";
  date2.printDate();

  return 0;
}
