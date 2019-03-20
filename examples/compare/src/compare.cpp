#include <xtd/strings>
#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;

// The main entry point for the application.
int main() {
  int result = strings::compare("Aaa", "Baa");
  if (result < 0)
    cout << "Aaa < Baa" << endl;
  else if (result > 0)
    cout << "Aaa > Baa" << endl;
  else
    cout << "Aaa == Baa" << endl;
}

// This code produces the following output:
//
// Aaa < Baa
