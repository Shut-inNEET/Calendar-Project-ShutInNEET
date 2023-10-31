#include <iostream>
#include <string>

using namespace std;

class dayType
{
public:
  // Sets the current day
  // Precondition: dayName is a valid day of the week
  // Postcondition: currentDay is updated with the index of the input dayName
  void setDay(string);

  // Returns day of the week
  // Precondition: Input number 0-6
  // Postcondition: Returns the name of the day of the week
  static string getWeekDay(int);

  // Returns day of the week
  // Precondition: currentDay has been initialized
  // Postcondition: Returns the day number of the week
  int getDayNumber() const;

  // Returns the next day
  // Precondition: currentDay has been initialized
  // Postcondition: Returns the day of the week after the currentDay
  string getNextDay() const;
  
  // Returns the previous day
  // Precondition: currentDay has been initialized
  // Postcondition: Returns the day of the week before the currentDay
  string getPrevDay() const;

  // Adds days to the currentDay
  // Precondition: days is a positive integer, currentDay has been initialized
  // Postcondition: Changes the currentDay to days ahead in the week
  void addDays(int);
  
  // Prints the current day
  // Precondition: currentDay has been initialized
  // Postcondition: Prints the currentDay to the console
  void printDay() const;
  
  // Default constructor
  // Precondition: dayName is a valid day of the week or an empty string
  // Postcondition: currentDay is set to Sunday or the input dayName
  dayType(string dayName = "Sunday");

private:
  // List of static names of the week
  static string weekDays[7];
  
  // Int variable to store the current day
  int currentDay;
};

