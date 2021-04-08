#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  cout << strings::formatf("%f", 12.345) << endl;
  cout << strings::formatf("%F", 12.345) << endl;
  cout << strings::formatf("%e", 12.345) << endl;
  cout << strings::formatf("%E", 12.345) << endl;
  cout << strings::formatf("%g", 12.345) << endl;
  cout << strings::formatf("%G", 12.345) << endl;
  cout << strings::formatf("0x%a", 12.345) << endl;
  cout << strings::formatf("0x%A", 12.345) << endl;
  cout << strings::formatf("%f", std::numeric_limits<double>::infinity()) << endl;
  cout << strings::formatf("%f", std::numeric_limits<double>::quiet_NaN()) << endl;
  cout << strings::formatf("%f", std::numeric_limits<double>::signaling_NaN()) << endl;
}

// This code produces the following output :
//
// 12.345000
// 12.345000
// 1.234500e+01
// 1.234500E+01
// 12.345
// 12.345
// 0x0x1.8b0a3d70a3d71p+3
// 0x0X1.8B0A3D70A3D71P+3
// inf
// nan
// nan
