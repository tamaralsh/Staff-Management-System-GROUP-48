#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "functions.h"
#include "loadData.h"

using namespace std;

// Check if the password matches the ID //
bool FUNCTION::IDpass_check(int i, vector<IDpass> UserIDpass, string password)
{
  if (UserIDpass[i].password == password) { return true; }
  else { return false; }
}

// Search employee ID in User ID and password database //
int FUNCTION::employeeID_search(string employeeID, vector<IDpass> UserIDpass)
{
  for (int i = 0; i < UserIDpass.size(); i++)
  {
    if (UserIDpass[i].employeeID == employeeID)
    { return i; }
  }
  return -1;
}

// Search by salary, outputs names and employeeID which are higher or lower than entered value //
void FUNCTION::search_bySalary(double salary, vector<Details> Employee_details,string high_or_low)
{
  for (int i = 0; i < Employee_details.size(); i++)
  {
    if (high_or_low == "L") //if lower
    {
      if (Employee_details[i].salary < salary) {
        cout << Employee_details[i].name << endl;
        cout << Employee_details[i].employeeID << endl;
        cout << Employee_details[i].salary << endl;
        cout << endl;
      }
    }
    else if (high_or_low ==  "H") // if higher
    {
      if (Employee_details[i].salary > salary) {
        cout << Employee_details[i].name << endl;
        cout << Employee_details[i].employeeID << endl;
        cout << Employee_details[i].salary << endl;
        cout << endl;
      }
    }
  }
}

// Search by Name //
int FUNCTION::search_byName(string name, vector<Details> Employee_details)
{
  int count = 0;
  for (int i = 0; i < Employee_details.size(); i++)
  {
    if (Employee_details[i].name == name)
    {  print_details(Employee_details[i]); count++; }
  }
  if (count == 0) { return -1; }

  return 0;
}

// Search for Employee ID and return index of the employee ID //
int FUNCTION::search_byEmployeeID(string employee_ID, vector<Details> Employee_details)
{
  int count = 0;
  for (int i = 0; i < Employee_details.size(); i++)
  {
    if (Employee_details[i].employeeID == employee_ID)
    {  return i; count++; }
  }
  if (count == 0) { return -1; }

  return 0;
}

// Store new user ID and password into "UserIDpass.txt" //
string FUNCTION::store_UserIDpass(string UserIDpass_filename, string employeeID)
{
  string password = password_randomizer();
  ofstream fout;
  fout.open(UserIDpass_filename,ios_base::app);
  if (fout.fail()) { cout << "Error in opening file."; exit(1); }

  fout << endl;
  fout << employeeID << endl;
  fout << password;

  fout.close();

  return password;
}

// Print education and work history //
void FUNCTION::print_history(vector<string> history)
{
  for (int i = 0; i < history.size(); i++)
  {
    cout << "    - " << history[i] << endl;
  }
}

// Print education and work history for edit_details function when delete is called //
void FUNCTION::print_history_delete(vector<string> history)
{
  int count = 1;
  for (int i = 0; i < history.size(); i++)
  {
    cout << count++ << ".  " << history[i] << endl;
  }
}

// Login Page //
string FUNCTION::login_page(vector<IDpass> UserIDpass)
{
  string employeeID,password,authoritylevel;
  int i;
  cout << "Enter your employee ID" << " : ";
  cin >> employeeID;
  cout << endl;
  authoritylevel = employeeID[0];
  i = employeeID_search(employeeID,UserIDpass);

  while (i == -1)
  {
    cout << "Please enter a valid employee ID" << " : ";
    cin >> employeeID;
    cout << endl;
    i = employeeID_search(employeeID,UserIDpass);
  }

  if (i != -1)
  {
    cout << "Enter password" << " : ";
    cin >> password;
    cout << endl;
    while (!(IDpass_check(i,UserIDpass,password))) {
      cout << "Wrong password, please enter your password again" << " : ";
      cin >> password;
      cout << endl;
    }
  }
  return authoritylevel;
}

// Print employee details //
void FUNCTION::print_details(Details Employee_details)
{
  cout << left;
  cout << setw(30) <<"1.  Name" << " : " << Employee_details.name << endl;
  cout << setw(30) <<"2.  Employee ID" << " : " << Employee_details.employeeID << endl;
  cout << setw(30) <<"3.  Date of birth" << " : " << Employee_details.dateofbirth << endl;
  cout << setw(30) <<"4.  Joining time" << " : " << Employee_details.joiningtime << endl;
  cout << setw(30) <<"5.  Position" << " : " << Employee_details.position << endl;
  cout << setw(30) <<"6.  Contact number" << " : " << Employee_details.contactnumber << endl;
  cout << setw(30) <<"7.  Email" << " : " << Employee_details.email << endl;
  cout << setw(30) <<"8.  Status" << " : " << Employee_details.status << endl;
  cout << setw(30) <<"9.  Attendance" << " : " << Employee_details.attendance << endl;
  cout << setw(30) <<"10. Salary" << " : " << Employee_details.salary << endl;
  cout << setw(30) <<"11. Education and work history" << " : " << endl;
  print_history(Employee_details.history);
  cout << endl;
}

// Delete employee //
int FUNCTION::delete_employee(vector<Details> &Employee_details, string employeeID)
{
  int count = 0;
  for (int i = 0; i < Employee_details.size(); i ++)
  {
    if (employeeID == Employee_details[i].employeeID)
    {
      Employee_details.erase(Employee_details.begin()+i);
      count++;
      cout << "Employee details are successfully deleted." << endl;
    }
  }
  if (count == 0) { return -1; }
  return 0;
}

// Output newest employeeID to be added in create function //
string FUNCTION::largestEmployeeID(vector<Details> Employee_details,string authority)
{
  string max = "000000",authoritycheck;
  int buffer;
  if (authority == "H")
  {
    for (int i = 0; i < Employee_details.size();i++)
    {
      authoritycheck = (Employee_details[i].employeeID)[0];
      if (authoritycheck == "2")
        {
          if (Employee_details[i].employeeID > max)
            max = Employee_details[i].employeeID;
        }
    }
  }

  else if (authority == "N")
  {
    for (int i = 0; i < Employee_details.size();i++)
    {
      authoritycheck = (Employee_details[i].employeeID)[0];
      if (authoritycheck == "1")
        {
          if (Employee_details[i].employeeID > max)
            max = Employee_details[i].employeeID;
        }
    }
  }
  buffer = stod(max);
  buffer++;
  max = to_string(buffer);
  return max;
}

// Edit details //
int FUNCTION::edit_details(Details &details)
{
  int edit_selection;
  string input;
  print_details(details);
  cout << endl << "Enter numbers 1-11 to change their respective details : ";
  cin >> edit_selection;
  cout << endl;
  while (edit_selection != 0)
  {
    switch (edit_selection)
    {
      case 1:
        {
          cout << "Enter new name : ";
          cin.ignore();
          getline(cin,input);
          cout << endl;
          details.name = input;
          break;
        }
      case 2:
        {
          cout << "Employee ID cannot be changed." << endl;
          break;
        }
      case 3:
        {
          cout << "Enter new date of birth (dd/mm/yyyy) : ";
          cin >> input;
          cout << endl;
          details.dateofbirth = input;
          break;
        }
      case 4:
        {
          cout << "Time started working in the company cannot be changed." << endl;
          break;
        }
      case 5:
        {
          cout << "Enter new position : " ;
          cin.ignore();
          getline(cin,input);
          cout << endl;
          details.position = input;
          break;
        }
      case 6:
        {
          cout << "Enter new contact number : " ;
          cin >> input;
          cout << endl;
          details.contactnumber = input;
          break;
        }
      case 7:
        {
          cout << "Enter new email : " ;
          cin >> input;
          cout << endl;
          details.email = input;
          break;
        }
      case 8:
        {
          cout << endl << "E = employed, R = resigned, F = fired L = laid off" << endl;
          cout << "Enter new status, E/R/F/L : ";
          cin >> input;
          cout << endl;
          details.status = input;
          break;
        }
      case 9:
        {
          cout << "Enter new attendance : " ;
          cin >> input;
          cout << endl;
          details.attendance = input;
          break;
        }
      case 10:
        {
          cout << "Enter new salary : ";
          cin >> input;
          cout << endl;
          //double salarybuffer = stod(input);
          //details.salary = salarybuffer;
          break;
        }
      case 11:
        {
          int add_or_delete;
          cout << "Enter 1 to add, 2 to delete : " ;
          cin >> add_or_delete;
          cout << endl;
          if (add_or_delete == 1)
          {
            cout << "Enter new work and education history (company/education startingtime-endingtime) : ";
            cin.ignore();
            getline(cin,input);
            cout << endl;
            (details.history).push_back(input);
          }
          if (add_or_delete == 2)
          {
            int choice;
            print_history_delete(details.history);
            cout << "Enter choice to delete : ";
            cin >> choice;
            cout << endl;
            (details.history).erase((details.history).begin()+choice-1);
            cout << "Successfully deleted.";
          }
        break;
        }
      }

    if (edit_selection != 2 && edit_selection != 4)
      {
        print_details(details);
        cout << endl << "Check for the changes." << endl;
        cout << "If you wish to exit, enter 0. " << endl;
        cout << "Else, enter numbers 1-11 to change their respective details : ";
        cin >> edit_selection;
        cout << endl;
        if (edit_selection == 0) return 0;
      }
    }
  save_details("Employee_Details.txt", Employee_details);
  return 0;
}

// Create employee //
void FUNCTION::createEmployee(vector<Details> &Employee_details)
{
  string input,employeeID;
  int confirmation;
  Details buffer;
  int numberofHistory;
  double salary_input;

  for (int i = 0; i < 11 ; i++)
  {
    switch (i)
    {
      case 0:
        cout << "Name" << ": ";
        cin.ignore();
        getline(cin,input);
        buffer.name = input;
        break;
      case 1:
        cout << "Employee authority, H = high, N = normal" << ": ";
        cin >> input;
        employeeID = largestEmployeeID(Employee_details,input)
        buffer.employeeID = employeeID;
        break;
      case 2:
        cout << "Date of birth (dd/mm/yyyy)" << " : ";
        cin >> input;
        buffer.dateofbirth = input;
        break;
      case 3:
        cout << "Joining time (dd/mm/yyyy)" << ": ";
        cin >> input;
        buffer.joiningtime = input;
        break;
      case 4:
        cout << "Position" << ": " ;
        cin.ignore();
        getline(cin,input);
        buffer.position = input;
        break;
      case 5:
        cout << "Contact number" << ": " ;
        cin >> input;
        buffer.contactnumber = input;
        break;
      case 6:
        cout << "Email" << ": " ;
        cin >> input;
        buffer.email = input;
        break;
      case 7:
        buffer.status = "Employed";
        break;
      case 8:
        buffer.attendance = "N/A";
        break;
      case 9:
        cout << "Salary" << ": ";
        cin >> salary_input;
        buffer.salary = salary_input;
        break;
      case 10:
        {
          int continue_choice = 1;

          while (continue_choice != 0)
          {
            cout << "Enter work and education history (work/education (startyear-endyear)): " << endl;
            cin.ignore();
            getline(cin,input);
            (buffer.history).push_back(input);
            if ((buffer.history).size() > 0) { print_history(buffer.history); }

            cout << "Enter 1 to continue or 0 to exit: " ;
            cin >> continue_choice;
            cout << endl;
          }
          break;
        }
    }
  }
  print_details(buffer);
  cout << "Check details entered. If you wish to edit, enter 1, else, enter 0 to confirm : ";
  cin >> confirmation;
  cout << endl;
  while (confirmation != 0)
  {
    if (confirmation == 1)
    {
      confirmation = edit_details(buffer);
    }
  }
  Employee_details.push_back(buffer);
  save_details("Employee_Details.txt", Employee_details);
  cout << "Employee details succesfully stored." << endl;
  cout << "Your Employee ID is " << employeeID << endl;
  cout << "Your password is " << store_UserIDpass("UserIDpass.txt",employeeID) << endl;
}

// Save changes made //
void FUNCTION::save_details(string employeeData_filename, vector<Details> Employee_details)
{
  ofstream save;
  save.open(employeeData_filename);
  if (save.fail()) { cout << "Error in saving data" ; exit(1); }
  for (int i = 0; i < Employee_details.size(); i++)
  {
    save << Employee_details[i].name << endl;
    save << Employee_details[i].employeeID << endl;
    save << Employee_details[i].dateofbirth << endl;
    save << Employee_details[i].joiningtime << endl;
    save << Employee_details[i].position << endl;
    save << Employee_details[i].contactnumber << endl;
    save << Employee_details[i].email << endl;
    save << Employee_details[i].status << endl;
    save << Employee_details[i].attendance << endl;
    save << Employee_details[i].salary << endl;
    for (int j = 0; j < (Employee_details[i].history).size(); j++)
    {
      save << (Employee_details[i].history)[j] << endl;
    }
    save << "//" << endl << endl;
  }
  save.close();
}

// Collect position data //
void FUNCTION::get_Positions(vector<Details> Employee_details,vector<string> &Positions)
{
  for (int i = 0; i < Employee_details.size(); i++)
  {
    int count = 0;
    for (int j = 0; j < Positions.size(); j++)
    {
      if (Employee_details[i].position == Positions[j])
      {
        count++;
      }
    }
    if (count == 0) { Positions.push_back(Employee_details[i].position); }
  }
}

// Show all positions in the company //
string FUNCTION::show_Positions(vector<string> Positions)
{
  int position_number;
  for (int i = 0; i < Positions.size(); i++)
  {
    cout << i+1 << "  " << Positions[i] << endl;
  }
  cout << "Enter choice of position to search : ";
  cin >> position_number;
  cout << endl;
  return Positions[position_number-1];
}

// Password randomizer //
string FUNCTION::password_randomizer()
{
  srand(time(0));
  string password = "";
  vector <string> letter = {"abcdefghijklmnopqrstuvwxyz",
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                            "0123456789"};
  for (int i = 0 ; i < 7 ; i++)
  {
    int rand_1 = rand()%3;
    if (rand_1 == 2) { password += letter[rand_1][rand()%10];  }
    else { password += letter[rand_1][(rand())%26]; }
  }
  return password;
}

