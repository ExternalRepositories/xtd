#include <console/console>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main(int argc, char* argv[]) {
  int x = 0;
  //
  if ((argc == 2) && (x = atoi(argv[1])) && ((x >= 1) && (x <= 9)))
    for (int i = 1; i <= x; i++)
      console::out << format("Beep number %d.", i) << beep() << endl;
  else
    console::out << "Usage: Enter the number of times (between 1 and 9) to beep." << endl;
}
