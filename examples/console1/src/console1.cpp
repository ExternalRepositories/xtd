#include <console/console.hpp>

#include <string>

using namespace gammasoft;
using namespace std;

// The main entry point for the application.
int main(int argc, char* argv[]) {
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
