#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "kpi.h"
#include "loadData.h"
#include "Authority.h"
#include "functions.h"

using namespace std;

const string normal_user = "You are not authorised.";

// FUNCTION - log-in page //
string login_page(vector<IDpass> UserIDpass)
{
  string employeeID,password,authoritylevel;
  int i;
  cout << "Please enter your employee ID" << ": ";
  cin >> employeeID;
  cout << endl;
  authoritylevel = employeeID[0];
  i = employeeID_search(employeeID,UserIDpass);

  while (i == -1)
  {
    cout << "ID not found." << endl;
    cout << "Please enter a valid employee ID" << ": ";
    cin >> employeeID;
    cout << endl;
    i = employeeID_search(employeeID,UserIDpass);
  }

  if (i != -1)
  {
    cout << "Please enter your password" << ": ";
    cin >> password;
    cout << endl;
    while (!(IDpass_check(i,UserIDpass,password))) {
      cout << "Incorrect password. Please enter your password again" << ": ";
      cin >> password;
      cout << endl;
    }
  }
  return authoritylevel;
}

int main()
{
  // Print welcome message //
  cout << "**************************************************************************" << endl;
  cout << "----------------- Welcome to the Staff Management System -----------------" << endl;
  cout << "**************************************************************************" << endl;
  cout << endl;

  // Initialize //
  string KPIfilename = "kpi,txt", employeeData_filename = "Employee_Details.txt";
  string IDpass_filename = "UserIDpass.txt";
  vector<KPI::Record> book;

  // Declare variable //
  int selection,continue_choice;
  string authoritylevel;
  vector <Details> Employee_details;
  vector <IDpass> UserIDpass;
  vector <Details> Employee_details;

  // Collect data from Employee Details file and ID file//
  loadData::load_details(employeeData_filename, Employee_details);
  loadData::load_IDpass(IDpass_filename, UserIDpass);
  get_Positions(Employee_details,Positions);

  // Print log-in page and get "authority level"//
  authoritylevel = login_page(UserIDpass);
  if (authoritylevel == "1")
  {
    selection = Authority::menu_display_unauthorized();
  }
  else if (authoritylevel == "2")
  {
    selection = Authority::menu_display_authorized();
  }

  // Function based on selection //
  while (selection != 0)
  {
    continue_choice = 0;
    switch (selection)
    {
      case 1:
        {
          string name;
          cout << "Enter name: ";
          cin.ignore();
          getline(cin,name);
          cout << endl;
          while (FUNCTION::search_byName(name,Employee_details) == -1)
          {
            cout << "There is no record of the name entered."<< endl;
            cout << "Please enter a valid name or enter 0 to exit: ";
            cout << endl;
            getline(cin,name);
            if (name == "0") { continue_choice = 2; break ; }
            cout << endl;
          }
          break;
        }
        case 2:
        {
          int i;
          string employeeID;
          cout << "Enter employee ID: ";
          cin >> employeeID;
          cout << endl;
          i = FUNCTION::search_byEmployeeID(employeeID,Employee_details);
          if (i == -1)
          {
            while (i == -1)
            {
              cout << "There is no record of the employee ID entered." << endl;
              cout << "Please enter a valid employee ID or enter 0 to exit: ";
              cin >> employeeID;
              if (employeeID == "0") { continue_choice = 2; break; }
              cout << endl;
              i = FUNCTION::search_byEmployeeID(employeeID,Employee_details);
            }
          }
          FUNCTION::print_details(Employee_details[i]);
          break;
        }
        case 3:
        {
          double salary;
          string high_or_low;
          cout << "Enter salary: ";
          cin >> salary;
          cout << endl << "Choose higher or lower" << endl;
          cout << "Enter H for high and L for low: ";
          cin >> high_or_low;
          FUNCTION::search_bySalary(salary,Employee_details,high_or_low);
        }
        case 4:
        {
          string position = FUNCTION::show_Positions(Positions);
          FUNCTION::search_byPosition(position,Employee_details);
          break;
        }
        case 5:
        {
          KPI::showKPIboard(book, KPIfilename);
        }
        case 6:
        {
          FUNCTION::createEmployee(Employee_details);

          break;
        }
        case 7:
        {
          string employeeID;
          cout << "Enter the employee ID to delete: ";
          cin >> employeeID;
          cout << endl;
          int i = FUNCTION::delete_employee(Employee_details,employeeID);
          if (i == -1)
          {
            while (i == -1)
            {
              cout << "There is no record of the employee ID entered." << endl;
              cout << "Please enter a valid employee ID or enter 0 to exit: ";
              cin >> employeeID;
              if (employeeID == "0") { continue_choice = 2; break; }
              cout << endl;
              i = FUNCTION::delete_employee(Employee_details,employeeID);
            }
          }
          break;
        }
        case 8:
        {
          string employeeID;
          Details buffer;
          cout << "Enter the employee ID to edit: ";
          cin >> employeeID;
          cout << endl;
          int i = FUNCTION::search_byEmployeeID(employeeID,Employee_details);
          if (i == -1)
          {
            while (i == -1)
            {
              cout << "There is no record of the employee ID entered." << endl;
              cout << "Please enter a valid employee ID or enter 0 to exit: ";
              cin >> employeeID;
              if (employeeID == "0") { continue_choice = 2; break; }
              cout << endl;
              i = FUNCTION::search_byEmployeeID(employeeID,Employee_details);
            }
          }
          FUNCTION::edit_details(Employee_details[i]);
        }
        case 9:
        {
          break;
        }
      }

      if (continue_choice == 2)
      {
        if (authoritylevel == "1")
        {
          selection = Authority::menu_display_unauthorized();
        }
        else if (authoritylevel == "2")
        {
          selection = Authority::menu_display_authorized();
        }
      }
      else
      {
        cout << endl << "1. Continue" << endl;
        cout << "2. Back to menu" << endl;
        cout << "Enter choice : ";
        cin >> continue_choice;
        cout << endl;

        if (continue_choice == 2)
        {
          if (authoritylevel == "1")
          {
            selection = Authority::menu_display_unauthorized();
          }
          else if (authoritylevel == "2")
          {
            selection = Authority::menu_display_authorized();
          }
        }
      }
  }
  FUNCTION::save_details("Employee_Details_saved.txt",Employee_details);
  return 0;
}
