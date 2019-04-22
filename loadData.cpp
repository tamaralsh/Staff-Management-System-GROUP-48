#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "loadData.h"

using namespace std;

//load data from Employee data file
void loadData::load_details(string employeeData_filename, vector <Details> &Employee_details)
{
  string input;
  Details buffer;
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
    for (int i = 0; i < 11; i++)
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
          (buffer.history).push_back(input);
          while (getline(fin,input))
          {
            if (input == "//") { break; }
            (buffer.history).push_back(input);
          }
          break;
        }
      }
      getline(fin,input);
    }
    Employee_details.push_back(buffer);
  }
}


// load ID and Password credentiala
void loadData::load_IDpass(string IDpass_filename, vector<IDpass> &UserIDpass)
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
    if (input=="") continue;
      
    buffer.employeeID = input;
    getline(fin,input);
    buffer.password = input;
      
    UserIDpass.push_back(buffer);
  }
  fin.close();
}
