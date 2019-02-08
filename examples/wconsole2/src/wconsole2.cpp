#include <console/console>
#include <string>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  wconsole::out << L"Hello ";
  wconsole::out << L"World!" << endl;
  wconsole::out << L"Enter your name: ";
  wstring name;
  wconsole::in >> name;
  wconsole::out << L"Good day, ";
  wconsole::out << name;
  wconsole::out << L"!" << endl;
}

// This code produces the following output:
//
// Hello World!
// Enter your name: James
// Good day, James!
