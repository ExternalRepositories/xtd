#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Colored Tab pages example");
    controls().push_back(tab_control_colored);
    client_size({390, 270});
    
    tab_control_colored.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
    tab_control_colored.controls().push_back_range({tab_page_red, tab_page_green, tab_page_blue, tab_page_yellow});
    tab_control_colored.location({10, 10});
    tab_control_colored.size({370, 250});

    tab_page_red.text("Red");
    tab_page_red.back_color(drawing::color::red);

    tab_page_green.text("Green");
    tab_page_green.back_color(drawing::color::green);

    tab_page_blue.text("Blue");
    tab_page_blue.back_color(drawing::color::blue);

    tab_page_yellow.text("Yellow");
    tab_page_yellow.back_color(drawing::color::yellow);
  }
  
private:
  tab_control tab_control_colored;
  tab_page tab_page_red;
  tab_page tab_page_green;
  tab_page tab_page_blue;
  tab_page tab_page_yellow;
};

int main() {
  application::run(form1());
}
