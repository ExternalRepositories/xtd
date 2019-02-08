#include <console/console>

using namespace xtd;

// The main entry point for the application.
int main() {
  console::write_line("The current buffer height is %d rows.", console::buffer_height());
  console::write_line("The current buffer width is %d columns.", console::buffer_width());
}

// This code produces the following output:
//
// The current buffer height is 300 rows.
// The current buffer width is 85 columns.
