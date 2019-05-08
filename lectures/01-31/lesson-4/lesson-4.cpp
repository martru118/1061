#include <iostream>
#include "menu.h"

using namespace std;

void add()
{
  int n1, n2;
  
  cout << "== add == " << endl;
  cout << "enter 1st number: "; cin >> n1;
  cout << "enter 2nd number: "; cin >> n2;
  cout << "result = " << n1 + n2 << endl;
}

void square()
{
  int n;
  cout << "== square == " << endl;
  cout << "enter number: ";
  cin >> n;
  cout << "result = " << x*x << endl;
}

void negate1()
{
  int n;
  cout << "== negate == " << endl;
  cout << "enter number: ";
  cin >> n;
  cout << "result = " << -n << endl;
}

int main()
{
  add_menu_item("addition", add);
  add_menu_item("square", square);
  add_menu_item("negate", negate1);
  run_menu_loop();
  clear_menu_items();
  
  return 0;
}
