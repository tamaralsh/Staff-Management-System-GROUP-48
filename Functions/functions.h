#ifndef CREATENEDIT_H
#define CREATENEDIT_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "loadData.h"

using namespace std;

class FUNCTION
{
public:
  static bool IDpass_check(int i, vector<IDpass> UserIDpass, string password);
  static int employeeID_search(string employeeID, vector<IDpass> UserIDpass);
  static void search_bySalary(double salary, vector<Details> Employee_details,string high_or_low);
  static int search_byName(string name, vector<Details> Employee_details);
  static int search_byEmployeeID(string employee_ID, vector<Details> Employee_details);
  static void print_history(vector<string> history);
  static string password_randomizer();
  static void print_history_delete(vector<string> history);
  static string login_page(vector<IDpass> UserIDpass);
  static void print_details(Details Employee_details);
  static int delete_employee(vector<Details> &Employee_details, string employeeID);
  static string largestEmployeeID(vector<Details> Employee_details,string authority);
  static int edit_details(Details &details);
  static void createEmployee(vector<Details> &Employee_details);
  static void save_details(string employeeData_filename, vector<Details> Employee_details);
  static void get_Positions(vector<Details> Employee_details,vector<string> &Positions);
  static string store_UserIDpass(string UserIDpass_filename, string employeeID);
  
};

#endif // CREATENEDIT_H
