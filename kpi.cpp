#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "kpi.h"

using namespace std;

// read text file and
// load the KPI data into a vector //
void KPI::loadKPIvector(string KPIfilename, vector<Record> &book)
{
  string line, line1;
  Record b;
  ifstream fin;
  fin.open(KPIfilename.c_str());

  if (fin.fail())
  {
    cout << "Error in loading data." << endl;
    exit(1);
  }

  while (getline(fin, line))
  {
    b.name = line1 + line;
    fin >> b.employeeID;
    fin >> b.w1 >> b.w2 >> b.w3 >> b.w4 >> b.w5;
    book.push_back(b);
    fin >> line1;
  }

  fin.close();
}

// calculate the total KPI score -> addition //
void KPI::addScore(vector<Record> &book)
{
  for (int i = 0; i < book.size(); i++)
  {
  //  cout << book[i].w1 << " "<<book[i].w2<<" "<<book[i].w3<<" "<<book[i].w4<<" "<<book[i].w5 <<endl;
    book[i].total = book[i].w1 + book[i].w2 + book[i].w3 + book[i].w4 + book[i].w5;
  }
}

// compares two books according to the total value //
bool KPI::compareTotal(const Record &lhs, const Record &rhs)
{
  return lhs.total > rhs.total;
}

// sort the vector list, from highest to lowest//
void KPI::sortVector(vector<Record> &book)
{
  sort(book.begin(), book.end(), compareTotal);
}

// print out the KPI leader board //
void KPI::showKPIboard(vector<Record> &book, string KPIfilename)
{
  loadKPIvector(KPIfilename, book);
  addScore(book);
  sortVector(book);
  cout << "**************************** KPI LEADER BOARD ****************************"  << endl;
  for (int i = 0; i < book.size(); i++)
  {
    cout << setw(4) << i+1 << ". ";
    cout << right << setw(45) << book[i].name << " " << setw(10) << book[i].employeeID << " " <<
    setw(7) << book[i].total << endl;
  }
  cout << "**************************************************************************" << endl;
}
