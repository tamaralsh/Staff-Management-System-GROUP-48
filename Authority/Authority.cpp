#include <iostream>
#include <string>
#include <iomanip>
#include "Authority.h"

using namespace std;

int Authority::menu_display_unauthorized()
{
  //name,employee ID,age,length of time at the company,position,contact details//
  //working shift,attendance,work and education history,kpi,salary//
  int selection;
  cout << endl;
  cout << "----------------- Staff Management System -----------------" << endl;
  cout << "1. Search by name" << endl;
  cout << "2. Search by employee ID" << endl;
  cout << "3. Search by position/department" << endl;
  cout << "4. Show KPI leaderboard" << endl;
  cout << "0. Exit" << endl;
  cout << endl << "Enter your choice: ";

  cin >> selection;
  while (selection > 4)
  {
    cout << "Please enter a valid option from the menu : ";
    cin >> selection;
    cout << endl;
  }
  if (selection == 3) { selection++; }
  if (selection == 4) { selection++; }
  cout << endl;

  return selection;
}

int Authority::menu_display_authorized()
{
  int selection;
  cout << endl;
  cout << "--------- High Authority Staff Management System ---------" << endl;
  cout << "1. Search by name" << endl;
  cout << "2. Search by employee ID" << endl;
  cout << "3. Search by salary" << endl;
  cout << "4. Search by position/department" << endl;
  cout << "5. Show KPI leaderboard" << endl;
  cout << "6. Create New Employee" << endl;
  cout << "7. Delete employee details" << endl;
  cout << "8. Edit employee details" << endl;
  cout << "0. Exit" << endl;
  cout << endl << "Enter your choice: ";

  cin >> selection;
  cout << endl;

  return selection;
}
