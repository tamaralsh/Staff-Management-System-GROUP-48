#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "kpi.h"
#include "Function.h"
#include "Authority.h"

using namespace std;

const string normal_user = "You are not authorised.";
struct Details
{
  string name;
  string employeeID;
  string dateofbirth;
  string joiningtime;
  string position;
  string contactnumber;
  string email;
  string status;
  string attendance;
  vector<string> history;
  double salary;
  vector<string> attribute;
  vector<string> attributevalue;
};

struct IDpass
{
  string employeeID;
  string password;
};


int main()
{
  // Print welcome message //
  cout << "**************************************************************************" << endl;
  cout << "----------------- Welcome to the Staff Management System -----------------" << endl;
  cout << "**************************************************************************" << endl;
  cout << endl;

  // Initialize //
  const string KPIfilename = "kpi.txt", employeeData_filename = "Employee_Details.txt";
  string IDpass_filename = "UserIDpass.txt";
  vector<KPI::Record> book;

  // Declare variable //
  int selection,continue_choice;
  string authoritylevel;
  vector <Function::Details> Employee_details;
  vector <Function::IDpass> UserIDpass;
  vector <string> Positions;

  // Collect data from Employee Details file and ID file//
  Function::load_details(employeeData_filename, Employee_details);
  Function::load_IDpass(IDpass_filename, UserIDpass);
  Function::get_Positions(Employee_details,Positions);

  // Print log-in page and get "authority level"//
  authoritylevel = Function::login_page(UserIDpass);
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
          while (Function::search_byName(name,Employee_details) == -1)
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
          i = Function::search_byEmployeeID(employeeID,Employee_details);
          if (i == -1)
          {
            while (i == -1)
            {
              cout << "There is no record of the employee ID entered." << endl;
              cout << "Please enter a valid employee ID or enter 0 to exit: ";
              cin >> employeeID;
              if (employeeID == "0") { continue_choice = 2; break; }
              cout << endl;
              i = Function::search_byEmployeeID(employeeID,Employee_details);
            }
          }
          Function::print_details(Employee_details[i]);
          break;
        }
        case 3:
        {
          string yearofBirth;
          cout << "Enter a year of birth(four digit) of employees to be deleted: ";
          cin >> yearofBirth;
          cout << endl;
          Function::search_byAge(yearofBirth,Employee_details);          
          break;
        }
        
        case 4:
        {
          double salary;
          string high_or_low;
          cout << "Enter salary: ";
          cin >> salary;
          cout << endl << "Choose higher or lower" << endl;
          cout << "Enter H for high or L for low: ";
          cin >> high_or_low;
          Function::search_bySalary(salary,Employee_details,high_or_low);
          break;
        }
        case 5:
        {
          string position = Function::show_Positions(Positions);
          Function::search_byPosition(position,Employee_details);
          break;
        }
        case 6:
        {
          KPI::showKPIboard(book, KPIfilename);
          break;
        }
        case 7:
        {
          Function::createEmployee(Employee_details,UserIDpass);
          break;
        }
        case 8:
        {
          string choice;
          cout << "Choose the attribute for searching to delete" << endl;
          cout << "Enter 'N' for name, 'E' for employee ID, 'A' for age, 'R' for role/position : ";
          cin >> choice;
          cout << endl;
          if (choice == "N")
          {
            string name;
            cout << "Enter the name to delete: ";
            cin >> name;
            cout << endl;
            Function::delete_byName(Employee_details, name);
          }
          if (choice == "E")
          {
            string employeeID;
            cout << "Enter the employee ID to delete: ";
            cin >> employeeID;
            cout << endl;
            Function::delete_byEmployeeID(Employee_details, employeeID);
          }
          if (choice == "A")
          {
            string age;
            cout << "Enter the year of birth to delete: ";
            cin >>age;
            cout << endl;
            Function::delete_byAge(Employee_details,age);
          }
          if (choice == "R")
          {
            Function::delete_byPositions(Positions, Employee_details);
            Function::get_Positions(Employee_details,Positions);
          }
          break;
        }
        case 9:
        {
          string employeeID;
          Details buffer;
          cout << "Enter the employee ID to edit: ";
          cin >> employeeID;
          cout << endl;
          
          int i = Function::search_byEmployeeID(employeeID,Employee_details);
          if (i == -1)
          {
            while (i == -1)
            {
              cout << "There is no record of the employee ID entered." << endl;
              cout << "Please enter a valid employee ID or enter 0 to exit: ";
              cin >> employeeID;
              if (employeeID == "0") { continue_choice = 2; break; }
              cout << endl;
              i = Function::search_byEmployeeID(employeeID,Employee_details);
            }
          }
          Function::edit_details(Employee_details,Employee_details[i]);
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
        if (edit_selection == 6) 
        { 
          cout << "Enter 1 to go back to menu";
          cin >> continue_choice;
          if (continue_choice == 1) { continue_choice = 2; }
        }
        else 
        {
          cout << endl << "1. Continue" << endl;
          cout << "2. Back to menu" << endl;
          cout << "Enter choice : ";
          cin >> continue_choice;
          cout << endl;
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
      }
  }
  Function::save_details("Employee_Details_saved.txt",Employee_details);
  return 0;
}
