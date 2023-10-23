#include <iostream>
#include <string>

#include "dayType.h"

using namespace std;

string dayType::weekDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

dayType::dayType(string dayName) 
{
  setDay(dayName);
}

void dayType::setDay(string dayName)
{
  for(int i = 0; i < 7; i++)
  {
    if(weekDays[i] == dayName)
    {
      currentDay = i;
      return;
    }
  }
  
  cout << "Invalid day name. Setting to Sunday." << endl;
  currentDay = 0;
}

string dayType::getPrevDay() const
{
  return weekDays[(currentDay - 1 + 7) % 7];
}

string dayType::getNextDay() const
{
  return weekDays[(currentDay + 1) % 7];
}

void dayType::addDays(int days) 
{
  currentDay = (currentDay + days) % 7;
}

void dayType::printDay() const
{
  cout << weekDays[currentDay] << endl;
}