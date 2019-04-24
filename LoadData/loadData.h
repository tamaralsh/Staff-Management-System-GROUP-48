#ifndef LOADDATA_H
#define LOADDATA_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class loadData
{
  public:
    static struct Details
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
      double salary;
      vector <string> history;
    };
    
    static struct IDpass
    {
      string employeeID;
      string password;
    };
    
    static void load_details(string employeeData_filename, vector <Details> &Employee_details);
    static void load_IDpass(string IDpass_filename, vector<IDpass> &UserIDpass);
};

#endif // LOADDATA_H
