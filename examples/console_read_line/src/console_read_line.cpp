#include <xtd/console>
#include <string>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  console::write("Hello ");
  console::write_line("World!");
  console::write("Enter your name: ");
  string name = console::read_line();
  console::write("Good day, ");
  console::write(name);
  console::write_line("!");
}

// This code produces the following output:
//
// Hello World!
// Enter your name: James
// Good day, James!
