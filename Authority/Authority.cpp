#include <iostream>
#include <string>
#include <iomanip>
#include "Authority.h"

using namespace std;

// Menu display for normal employees with restricted access //
int Authority::menu_display_unauthorized()
{
  int selection;
  cout << endl;
  cout << "---------------------- Staff Management System ----------------------" << endl;
  cout << "1. Search by name." << endl;
  cout << "2. Search by employee ID." << endl;
  cout << "3. Search by age." << endl;
  cout << "4. Search by job position." << endl;
  cout << "5. Show KPI leaderboard." << endl;
  cout << "0. Exit." << endl;
  cout << endl << "Enter your choice: ";

  cin >> selection;
  while (selection < 0 || selection > 5)
  {
    cout << "Please choose an option from the menu." << endl;
    cout << "Enter option: ";
    cin >> selection;
    cout << endl;
  }
  if ((selection == 4) || (selection == 5)) { selection++; }
  cout << endl;
  
  return selection;
}

// Menu display for employees with full access //
int Authority::menu_display_authorized()
{
  int selection;
  cout << endl;
  cout << "--------------- High Authority Staff Management System ---------------" << endl;
  cout << "1. Search by name." << endl;
  cout << "2. Search by employee ID." << endl;
  cout << "3. Search by age." << endl;
  cout << "4. Search by salary." << endl;
  cout << "5. Search by job position." << endl;
  cout << "6. Show KPI leaderboard." << endl;
  cout << "7. Create New Employee." << endl;
  cout << "8. Delete employee details." << endl;
  cout << "9. Edit employee details." << endl;
  cout << "0. Exit." << endl;
  
  cout << endl << "Enter your choice: ";
  cin >> selection;
  cout << endl;
  while (selection < 0 || selection > 9)
  {
    cout << "Please choose an option from the menu." << endl;
    cout << "Enter option: ";
    cin >> selection;
    cout << endl;
  }

  return selection;
}
