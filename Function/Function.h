#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Function
{
public:
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
  static int employeeID_search(string employeeID, vector<IDpass> UserIDpass);
  static bool IDpass_check(int i, vector<IDpass> UserIDpass, string password);
  static void print_history(vector<string> history);
  static void print_history_delete(vector<string> history);
  static string login_page(vector<IDpass> UserIDpass);
  static void print_details(Details Employee_details);
  static void load_details(string employeeData_filename, vector <Details> &Employee_details);
  static void search_bySalary(double salary, vector<Details> Employee_details,string high_or_low);
  static int delete_employee(vector<Details> &Employee_details, string employeeID);
  static int search_byName(string name, vector<Details> Employee_details);
  static int search_byEmployeeID(string employee_ID, vector<Details> Employee_details);
  static string largestEmployeeID(vector<Details> Employee_details,string authority);
  static int edit_details(vector<Details>&Employee_details, Details &details);
  static void createEmployee(vector<Details> &Employee_details, vector<IDpass> &UserIDpass);
  static void load_IDpass(string IDpass_filename, vector<IDpass> &UserIDpass);
  static string show_Positions(vector<string> Positions);
  static void search_byPosition(string Position,vector<Details> Employee_details);
  static void get_Positions(vector<Details> Employee_details,vector<string> &Positions);
  static void save_details(string employeeData_filename, vector<Details> Employee_details);
  static void save_UserIDpass(vector<IDpass> UserIDpass,string UserIDpass_filename);
  static string store_UserIDpass(vector<IDpass> & UserIDpass, string employeeID);
  static string password_randomizer();
  static void addUser_defined_attribute(vector<Details> & Employee_details, string attribute);
  static void print_attributes(vector<string> attribute, vector<string> attributevalue);
  static void print_attribute_delete(vector<string> attribute, vector<string> attributevalue);
  static void delete_byAge(vector <Details> &Employee_details, string DOB_yeartodelete);
  static void delete_byPositions(vector<string> Positions, vector <Details> Employee_details);
  static int delete_byEmployeeID(vector<Details> &Employee_details, string employeeID);
  static int delete_byName(vector<Details> &Employee_details, string name);
  static void addUserAttribute(vector<Details> & Employee_details, string attribute);
  static void add_attribute_toAll(vector<Details> & Employee_details, string attribute);
  static void search_byAge(string yeaRofBirth,vector<Details> Employee_details);


};

#endif
