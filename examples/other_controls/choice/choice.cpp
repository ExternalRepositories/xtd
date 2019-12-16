#include <xtd/xtd.forms>

using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Choice example");

      choice1.parent(*this);
      choice1.location({10, 10});
      choice1.items().push_back_range({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"});
      choice1.selected_index(0);
      choice1.selected_index_changed += [this] {
        choice2.selected_index(choice1.selected_index());
      };

      choice2.parent(*this);
      choice2.location({10, 50});
      choice2.items().push_back_range({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"});
      choice2.selected_index(0);
      choice2.selected_index_changed += [this] {
        choice1.selected_index(choice2.selected_index());
      };
    }
    
  private:
    choice choice1;
    choice choice2;
  };
}

int main() {
  application::run(examples::form1());
}
