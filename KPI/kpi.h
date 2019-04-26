#ifndef KPI_H
#define KPI_H

#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class KPI
{
public:
  class Record
  {
  public:
    string name;
    int employeeID;
    double w1 = 0.0;
    double w2 = 0.0;
    double w3 = 0.0;
    double w4 = 0.0;
    double w5 = 0.0;
    double total = 0.0;
  };
  static void loadKPIvector(string KPIfilename, vector<Record> &book);
  static void addScore(vector<Record> &book);
  static bool compareTotal(const Record &lhs, const Record &rhs);
  static void sortVector(vector<Record> &book);
  static void showKPIboard(vector<Record> &book, string KPIfilename);
};

#endif
