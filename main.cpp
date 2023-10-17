#include <iostream>
#include <string>
#include "dayType.h"

using namespace std;

int main() 
{
  dayType day1;

  cout << "From default constructor: ";
  day1.printDay();

  cout << "Previous day: ";
  day1.setDay(day1.getPrevDay());
  day1.printDay();
  day1.setDay(day1.getNextDay());

  cout << "Next day: ";
  day1.setDay(day1.getNextDay());
  day1.printDay();
  day1.setDay(day1.getPrevDay());

  dayType day2("Monday");
  
  cout << "From constructor with parameter: ";
  day2.printDay();

  day2.addDays(3);
  cout << "After adding 3 days: ";
  day2.printDay();

  day2.addDays(30);
  cout << "After adding another 30 days: ";
  day2.printDay();
  
  day2.addDays(365);
  cout << "After adding another 365 days: ";
  day2.printDay();

  return 0;
}
