#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Function.h"

using namespace std;

// Search for employee ID //
int Function::employeeID_search(string employeeID, vector<Function::IDpass> UserIDpass)
{
  for (int i = 0; i < UserIDpass.size(); i++)
  {
    if (UserIDpass[i].employeeID == employeeID)
    { return i; }
  }
  return -1;
}

// Add attribute to vector //
void Function::addUserAttribute(vector<Function::Details> & Employee_details, string attribute)
{
  for (int i = 0; i < Employee_details.size(); i++)
  {
    (Employee_details[i].attribute).push_back(attribute);
    (Employee_details[i].attribute).push_back("");
  }
}

// Delete employee by role/position //
void Function::delete_byPositions(vector<string> Positions, vector <Function::Details> Employee_details)
{
  int position_number,count;
  string confirmation;
  for (int i = 0; i < Positions.size(); i++)
  {
    cout << i+1 << "  " << Positions[i] << endl;
  }
  cout << "Enter choice of position to delete : ";
  cin >> position_number;
  cout << endl;
  for (int i = 0 ; i < Employee_details.size() ; i ++)
  {
    if (Employee_details[i].position == Positions[position_number-1])
    {
      Function::print_details(Employee_details[i]);
      cout << "Enter Y to confirm, N to cancel : ";
      cin >> confirmation;
      count++;
      if (confirmation == "Y")
      {
        Employee_details.erase(Employee_details.begin()+i);
        i--;
      }
      else
      {
        cout << "Cancelled" << endl;
        continue;
      }
    }
  }
}

// Print added attributes //
void Function::print_attributes(vector<string> attribute, vector<string> attributevalue)
{
  for (int i = 0; i < attribute.size(); i++)
  {
    cout << "    - " << attribute[i] << " : " << attributevalue[i] << endl;
  }
}

// Check if the password entered is correct //
bool Function::IDpass_check(int i, vector<Function::IDpass> UserIDpass, string password)
{
  if (UserIDpass[i].password == password) { return true; }
  else { return false; }
}

void Function::print_history(vector<string> history)
{
  for (int i = 0; i < history.size(); i++)
  {
    cout << "    - " << history[i] << endl;
  }
}

// Password generator for new employees //
string Function::password_randomizer()
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


string Function::store_UserIDpass(vector<Function::IDpass> & UserIDpass, string employeeID)
{
  string password = password_randomizer();
  IDpass newUser;
  newUser.employeeID = employeeID;
  newUser.password = password;
  UserIDpass.push_back(newUser);

  return password;
}

void Function::save_UserIDpass(vector<Function::IDpass> UserIDpass,string UserIDpass_filename)
{
  ofstream fout;
  fout.open(UserIDpass_filename);
  if (fout.fail()) { cout << "Error in opening file."; exit(1); }
  for (int i = 0 ; i < UserIDpass.size() ; i++)
  {
    fout << UserIDpass[i].employeeID << endl;
    fout << UserIDpass[i].password << endl;
    fout << endl;
  }
  fout.close();
}

void Function::print_history_delete(vector<string> history)
{
  int count = 1;
  for (int i = 0; i < history.size(); i++)
  {
    cout << count++ << ".  " << history[i] << endl;
  }
}
// login page //
string Function::login_page(vector<Function::IDpass> UserIDpass)
{
  string employeeID,password,authoritylevel;
  int i;
  cout << "Enter your employee ID" << " : ";
  cin >> employeeID;
  cout << endl;
  authoritylevel = employeeID[0];
  i =Function::employeeID_search(employeeID,UserIDpass);

  while (i == -1)
  {
    cout << "Please enter a valid employee ID" << " : ";
    cin >> employeeID;
    cout << endl;
    i = Function::employeeID_search(employeeID,UserIDpass);
  }

  if (i != -1)
  {
    cout << "Enter password" << " : ";
    cin >> password;
    cout << endl;
    while (!(Function::IDpass_check(i,UserIDpass,password))) {
      cout << "Wrong password, please enter your password again" << " : ";
      cin >> password;
      cout << endl;
    }
  }
  return authoritylevel;
}



void Function::print_details(Function::Details Employee_details)
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
  cout << setw(30) <<"10. Salary" << " : $" << Employee_details.salary << endl;
  cout << setw(30) <<"11. Education and work history" << " : " << endl;
  Function::print_history(Employee_details.history);
  if (Employee_details.attribute.empty())
    cout << setw(30) <<"12. Additional user attributes" << " : " << "None"<< endl;
  else
  {
    cout << setw(30) <<"12. Additional user attributes" << " : " << endl;
    Function::print_attributes(Employee_details.attribute, Employee_details.attributevalue);
  }
  cout << endl;
}

void Function::load_details(string employeeData_filename, vector <Function::Details> &Employee_details)
{
  string input;
  Function::Details buffer;
  double salary_buffer;

  ifstream fin;
  fin.open(employeeData_filename);
  if (fin.fail())
  {
    cout << "Error in loading data" << endl;
    exit(1);
  }

  while (getline(fin,input))
  {
    (buffer.history).clear();
    for (int i = 0; i < 12; i++)
    {
      switch (i)
      {
        case 0:
          buffer.name = input;
          break;
        case 1:
          buffer.employeeID = input;
          break;
        case 2:
          buffer.dateofbirth = input;
          break;
        case 3:
          buffer.joiningtime = input;
          break;
        case 4:
          buffer.position = input;
          break;
        case 5:
          buffer.contactnumber = input;
          break;
        case 6:
          buffer.email = input;
          break;
        case 7:
          buffer.status = input;
          break;
        case 8:
          buffer.attendance = input;
          break;
        case 9:
          salary_buffer = stod(input);
          buffer.salary = salary_buffer;
          break;
        case 10:
        {
          if (input == "/")
            break;
          (buffer.history).push_back(input);
          while (getline(fin,input))
          {
            if (input == "/") { break; }
            (buffer.history).push_back(input);
          }
          break;
        }
        case 11:
        {
          int i = 0;
          if (input == "//") { break; }
          (buffer.attribute).push_back(input);
          while(getline(fin,input))
          {
            if (input == "//") { break; }
            if ((i % 2) == 0)
            {
              (buffer.attributevalue).push_back(input);
            }
            else
            {
              (buffer.attribute).push_back(input);
            }
            i++;
          }
        }
        break;
      }
      getline(fin,input);
    }
    Employee_details.push_back(buffer);
    buffer = {};
  }
  fin.close();
}

void Function::search_byAge(string yeaRofBirth, vector<Function::Details> Employee_details)
{
  int count = 0;
  for (int i = 0; i < Employee_details.size() ; i++)
  {
    if ((Employee_details[i].dateofbirth).substr(6,4) == yeaRofBirth)
    {
      count++;
      Function::print_details(Employee_details[i]);
    }
  }
  if (count == 0) { cout << "There are no employees with year of birth entered" << endl; }
}

void Function::search_bySalary(double salary, vector<Function::Details> Employee_details,string high_or_low)
{
  int count = 0;
  cout << left;
  for (int i = 0; i < Employee_details.size(); i++)
  {
    if (high_or_low == "L") //if lower
    {
      if (Employee_details[i].salary < salary) {
        cout << ++count << "." << endl;
        cout << setw(15) << "Name" << " : " << Employee_details[i].name << endl;
        cout << setw(15) << "Employee ID" << " : " << Employee_details[i].employeeID << endl;
        cout << setw(15) << "Salary" << " : " << Employee_details[i].salary << endl;
        cout << endl;
      }
    }
    else if (high_or_low ==  "H") // if higher
    {
      if (Employee_details[i].salary > salary) {
        cout << ++count << "." << endl;
        cout << setw(15) << "Name" << " : " << Employee_details[i].name << endl;
        cout << setw(15) << "Employee ID" << " : " << Employee_details[i].employeeID << endl;
        cout << setw(15) << "Salary" << " : " << Employee_details[i].salary << endl;
        cout << endl;
      }
    }
  }
  if ((count == 0) && (high_or_low == "L")) { cout << endl << "There are no employees with salaries lower than the value entered."; }
  if ((count == 0) && (high_or_low == "H")) { cout << endl << "There are no employees with salaries higher than the value entered."; }
}

int Function::delete_byEmployeeID(vector<Function::Details> &Employee_details, string employeeID)
{
  int count = 0;
  string confirmation;
  for (int i = 0; i < Employee_details.size(); i ++)
  {
    if (employeeID == Employee_details[i].employeeID)
    {
      Function::print_details(Employee_details[i]);
      cout << "Enter Y to confirm, N to cancel";
      cin >> confirmation;
      cout << endl;
      if (confirmation == "Y")
      {
        Employee_details.erase(Employee_details.begin()+i);
        count++;
        cout << "Employee details are successfully deleted." << endl;
      }
      else if (confirmation == "N")
      {
        cout << "Cancelled." << endl;
        continue;
      }
    }
  }
  if (count == 0) { cout << "There is no employee with the employee ID entered."; }
  return 0;
}

int Function::delete_byName(vector<Function::Details> &Employee_details, string name)
{
  int count = 0;
  string confirmation;
  for (int i = 0; i < Employee_details.size(); i ++)
  {
    if (name == Employee_details[i].name)
    {
      Function::print_details(Employee_details[i]);
      cout << "Enter Y to confirm, N to cancel";
      cin >> confirmation;
      cout << endl;
      if (confirmation == "Y")
      {
        Employee_details.erase(Employee_details.begin()+i);
        count++;
        cout << "Employee details are successfully deleted." << endl;
      }
      else if (confirmation == "N")
      {
        cout << "Cancelled." << endl;
        continue;
      }
    }
  }
  if (count == 0) { cout << "There are no employees with the name entered."; }
  return 0;
}

int Function::search_byName(string name, vector<Function::Details> Employee_details)
{
  int count = 0;
  for (int i = 0; i < Employee_details.size(); i++)
  {
    if (Employee_details[i].name == name)
    {  Function::print_details(Employee_details[i]); count++; }
  }
  if (count == 0) { return -1; }

  return 0;
}

int Function::search_byEmployeeID(string employee_ID, vector<Function::Details> Employee_details)
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

string Function::largestEmployeeID(vector<Function::Details> Employee_details,string authority)
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


int Function::edit_details(vector<Function::Details> &Employee_details, Function::Details &details)
{
  int edit_selection;
  string input;
  Function::print_details(details);
  cout << endl << "Enter numbers 1-12 to change their respective details : ";
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
          cout << "Enter new date of birth (dd/mm/yyyy): ";
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
          cout << "Enter new job position: " ;
          cin.ignore();
          getline(cin,input);
          cout << endl;
          details.position = input;
          break;
        }
      case 6:
        {
          cout << "Enter new contact number: " ;
          cin >> input;
          cout << endl;
          details.contactnumber = input;
          break;
        }
      case 7:
        {
          cout << "Enter new email: " ;
          cin >> input;
          cout << endl;
          details.email = input;
          break;
        }
      case 8:
        {
          cout << endl << "E = employed, R = resigned, F = fired, L = laid off" << endl;
          cout << "Enter new status, E/R/F/L: ";
          cin >> input;
          if (input == "E")
              { input = "Employed"; }
          else if (input == "R")
              { input = "Resigned"; }
          else if (input == "F")
              { input = "Fired"; }
          else if (input == "L")
              { input = "Laid off"; }
          cout << endl;
          details.status = input;
          break;
        }
      case 9:
        {
          cout << "Enter new attendance: " ;
          cin >> input;
          cout << endl;
          details.attendance = input;
          break;
        }
      case 10:
        {
          cout << "Enter new salary: ";
          cin >> input;
          cout << endl;
          double salarybuffer = stod(input);
          details.salary = salarybuffer;
          break;
        }
      case 11:
        {
          int add_or_delete;
          cout << "Enter 1 to add, 2 to delete: " ;
          cin >> add_or_delete;
          cout << endl;
          if (add_or_delete == 1)
          {
            cout << "Enter new work and education history (company/education startingtime-endingtime): ";
            cin.ignore();
            getline(cin,input);
            cout << endl;
            (details.history).push_back(input);
          }
          if (add_or_delete == 2)
          {
            int choice;
            Function::print_history_delete(details.history);
            cout << "Enter choice to delete: ";
            cin >> choice;
            cout << endl;
            (details.history).erase((details.history).begin()+choice-1);
            cout << "Successfully deleted.";
          }
        break;
        }
      case 12:
        {
          int add_or_delete;
          cout << "Enter 1 to add, 2 to delete, 3 to edit attribute value : " ;
          cin >> add_or_delete;
          cout << endl;
          if (add_or_delete == 1)
          {
            cout << "Enter new attribute : ";
            cin.ignore();
            getline(cin,input);
            cout << endl;
            (details.attribute).push_back(input);
            add_attribute_toAll(Employee_details,input);
            cout << "Enter the corresponding attribute value : ";
            getline(cin,input);
            cout << endl;
            (details.attributevalue).push_back(input);
          }
          if (add_or_delete == 2)
          {
            int choice;
            if ((details.attribute).empty()) 
            { 
              cout << "There are currently no attributes to be deleted"; 
              break; 
            }
            Function::print_attribute_delete(details.attribute,details.attributevalue);
            cout << "WARNING: Deleting this attribute deletes the similar attribute for all employees" << endl;
            cout << "Enter choice of attribute to delete or enter 0 to exit : ";
            cin >> choice;
            cout << endl;
            if (choice == 0)
            { break; }
            for (int i = 0; i < Employee_details.size(); i++)
            {
              (Employee_details[i].attribute).erase((Employee_details[i].attribute).begin()+choice-1);
              (Employee_details[i].attributevalue).erase((Employee_details[i].attributevalue).begin()+choice-1);
            }
          }
          if (add_or_delete == 3)
          {
            int choice;
            string newvalue;
            if ((details.attribute).empty())
            { 
              cout << "There are currently no attributes to be deleted" << endl; 
              break;
            }
            Function::print_attribute_delete(details.attribute,details.attributevalue);
            cout << "Enter choice of attribute value to edit : ";
            cin >> choice;
            cout << endl;
            cout << "Enter new attribute value : ";
            cin >> newvalue;
            cout << endl;
            (details.attributevalue)[choice-1] = newvalue;
          }
          break;
        }
      }
    if (edit_selection == 2 || edit_selection == 4)
    {
      cout << endl << "Enter, numbers 1-12 to change their respective details." << endl;
      cout << "Or if you wish to exit, enter 0 : ";
      cin >> edit_selection;
      cout << endl;
    }
    if (edit_selection != 2 && edit_selection != 4)
      {
        Function::print_details(details);
        cout << endl << "Check for the changes." << endl;
        cout << "If you wish to exit, enter 0. " << endl;
        cout << "Else, enter numbers 1-12 to change their respective details : ";
        cin >> edit_selection;
        cout << endl;
        
      }
    }
  if (edit_selection == 0) 
  {
    save_details("Employee_Details.txt",Employee_details);
    return 0;
  }
 return 0;
}

void Function::add_attribute_toAll(vector<Function::Details> & Employee_details, string attribute)
{
  for (int i = 0; i < Employee_details.size(); i++)
  {
    (Employee_details[i].attribute).push_back(attribute);
    (Employee_details[i].attributevalue).push_back("N/A");
  }
}

void Function::createEmployee(vector<Function::Details> &Employee_details,vector<Function::IDpass> & UserIDpass)
{
  string input, employeeID;
  int confirmation;
  Details buffer;
  int numberofHistory;
  double salary_input;

  for (int i = 0; i < 12 ; i++)
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
        employeeID = Function::largestEmployeeID(Employee_details,input);
        buffer.employeeID = employeeID;
        break;
      case 2:
        cout << "Date of birth (dd/mm/yyyy)" << " : ";
        cin >> input;
        buffer.dateofbirth = input;
        break;
      case 3:
        cout << "Joining time (mm/yyyy)" << ": ";
        cin >> input;
        buffer.joiningtime = input;
        break;
      case 4:
        cout << "Job position" << ": " ;
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
            if ((buffer.history).size() > 0) 
            { 
              cout << "History details added : " << endl;
              Function::print_history(buffer.history); 
            }
            cout << endl << "Enter 1 to continue or 0 to exit: " ;
            cin >> continue_choice;
            cout << endl;
            while (continue_choice != 1 && continue_choice != 0)
              {
                cout << endl << "Enter 1 to continue or 0 to exit: " ;
                cin >> continue_choice;
                cout << endl;
              }
          }
          break;
        }
      case 11:
        {
          int continue_choice = 1;
          add_attribute_toNew_employee(Employee_details[0].attribute, buffer);
          while (continue_choice !=0)
          {
            cout << "Enter any additional attributes : ";
            cin.ignore();
            getline(cin,input);
            cout << endl;
            (buffer.attribute).push_back(input);
            add_attribute_toAll(Employee_details,input);
            cout << "Enter the attribute value : ";
            cin >> input;
            cout << endl;
            (buffer.attributevalue).push_back(input);
            if (buffer.attribute.size() > 0)
            { 
              cout << endl << "Additional attributes added : " << endl;
              Function::print_attributes(buffer.attribute,buffer.attributevalue);
            }
            
            cout << "Enter 1 to continue or 0 to exit: " ;
            cin >> continue_choice;
            cout << endl;

            while (continue_choice != 1 && continue_choice != 0)
              {
                cout << "Enter 1 to continue or 0 to exit: " ;
                cin >> continue_choice;
                cout << endl;
              }
            }
            break;
          }
        }

  }
  Function::print_details(buffer);
  cout << "Check details entered. If you wish to edit, enter 1, else, enter 0 to confirm : ";
  cin >> confirmation;
  cout << endl;
  while (confirmation != 0)
  {
    if (confirmation == 1)
    {
      confirmation = Function::edit_details(Employee_details,buffer);
    }
  }
  Employee_details.push_back(buffer);
  cout << "Employee details succesfully stored." << endl;
  cout << "Your Employee ID is " << employeeID << endl;
  cout << "Your password is " << Function::store_UserIDpass(UserIDpass,employeeID) << endl;
  save_details("Employee_Details.txt",Employee_details);
}

void Function::load_IDpass(string IDpass_filename, vector<Function::IDpass> &UserIDpass)
{
  string input;
  IDpass buffer;

  ifstream fin;
  fin.open(IDpass_filename);
  if (fin.fail())
  {
    cout << "Error in loading data" << endl;
    exit(1);
  }

  while (getline(fin,input))
  {
    if (input == "") continue;
    buffer.employeeID = input;
    getline(fin,input);
    buffer.password = input;
    UserIDpass.push_back(buffer);
  }
  fin.close();
}

string Function::show_Positions(vector<string> Positions)
{
  int position_number;
  for (int i = 0; i < Positions.size(); i++)
  {
    cout << i+1 << ".  " << Positions[i] << endl;
  }
  cout << "Enter choice of position to search : ";
  cin >> position_number;
  cout << endl;
  return Positions[position_number-1];
}

void Function::search_byPosition(string Position,vector<Function::Details> Employee_details)
{
  for (int i = 0 ; i < Employee_details.size() ; i ++)
  {
    if (Employee_details[i].position == Position)
    {
      Function::print_details(Employee_details[i]);
    }
  }
}


void Function::get_Positions(vector<Function::Details> Employee_details,vector<string> &Positions)
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


void Function::save_details(string employeeData_filename, vector<Function::Details> Employee_details)
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
    save << "/" << endl;
    for (int k = 0; k <(Employee_details[i].attribute).size(); k++)
    {
      save << (Employee_details[i].attribute)[k] << endl;
      save << (Employee_details[i].attributevalue)[k] << endl;
    }
    save << "//" << endl << endl;
  }
  save.close();
}


void Function::delete_byAge(vector <Function::Details> &Employee_details, string DOB_yeartodelete)
{
  string confirmation = "";
  cout << "Showing all employees with year of birth entered: " << endl;
  int count = 0;
  for (int i = 0; i < Employee_details.size(); i++)
  {
    if ((Employee_details[i].dateofbirth).substr(6,4) == DOB_yeartodelete)
    {
      Function::print_details(Employee_details[i]);
      count++;
      cout << "Enter Y to confirm delete, N to cancel: ";
      cin >> confirmation;
      cout << endl;
      if (confirmation == "Y")
      {
        Employee_details.erase(Employee_details.begin()+i);
        i--;
      }
      else if (confirmation == "N")
      {
        cout << "Cancelled." << endl;
        continue;
      }
    }
  }
  if (count == 0) { cout << "There are no employees with the year of birth entered"; }
}


void Function::print_attribute_delete(vector<string> attribute, vector<string> attributevalue)
{
 int count = 1;
 for (int i =0; i < attribute.size(); i++)
 {
   cout << count++ << ".  " << attribute[i] << " : " << attributevalue[i] << endl;
 }
}

int Function::add_attribute_toNew_employee(vector<string> attribute, Function::Details & buffer)
{
  if (attribute.empty()) { return 0; }
  else
  {
    for (int i = 0; i < attribute.size(); i++)
    {
      (buffer.attribute).push_back(attribute[i]);
      (buffer.attributevalue).push_back("");
    }
  }
}
  
