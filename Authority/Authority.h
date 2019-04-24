#ifndef AUTHORITY_H
#define AUTHORITY_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Authority
{
public:
  static int menu_display_authorized();
  static int menu_display_unauthorized();
};

#endif // AUTHORITY_H
