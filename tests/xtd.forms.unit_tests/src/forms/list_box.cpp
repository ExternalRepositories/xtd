#include <xtd/xtd.forms>
#include <xtd/xtd.tunit>
#if defined(__XTD_FORMS_NATIVE_WXWIDGETS__)
#include <xtd/forms/native/wxwidgets/wx_list_box.hpp>
#endif

using namespace std;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_list_box) {
  public:
    void test_method_(create_list_box) {
      form form;
      list_box list_box;
      list_box.parent(form);
      assert::is_not_zero_(list_box.handle());
    }
    
    void test_method_(unsorted_add_items) {
      form form;
      list_box list_box;
      list_box.parent(form);
      list_box.items().push_back_range({"d", "a", "c", "b"});
      
      assert::are_equal_(4, list_box.items().size());
      assert::are_equal_("d", list_box.items()[0]);
      assert::are_equal_("a", list_box.items()[1]);
      assert::are_equal_("c", list_box.items()[2]);
      assert::are_equal_("b", list_box.items()[3]);
     
#if defined(__XTD_FORMS_NATIVE_WXWIDGETS__)
      assert::are_equal_(4, static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetCount());
      assert::are_equal_("d", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(0));
      assert::are_equal_("a", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(1));
      assert::are_equal_("c", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(2));
      assert::are_equal_("b", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(3));
#endif
    }
    
    void test_method_(unsorted_add_items_with_tags) {
      form form;
      list_box list_box;
      list_box.parent(form);
      list_box.items().push_back_range({{"d", 4}, {"a", 1}, {"c", 3}, {"b", 2}});
      
      assert::are_equal_(4, list_box.items().size());
      assert::are_equal_("d", list_box.items()[0]);
      assert::are_equal_(4, any_cast<int>(list_box.items()[0].tag()));
      assert::are_equal_("a", list_box.items()[1]);
      assert::are_equal_(1, any_cast<int>(list_box.items()[1].tag()));
      assert::are_equal_("c", list_box.items()[2]);
      assert::are_equal_(3, any_cast<int>(list_box.items()[2].tag()));
      assert::are_equal_("b", list_box.items()[3]);
      assert::are_equal_(2, any_cast<int>(list_box.items()[3].tag()));
    }
     
    void test_method_(sorted_add_items) {
      form form;
      list_box list_box;
      list_box.parent(form);
      list_box.sorted(true);
      list_box.items().push_back_range({"d", "a", "c", "b"});

      assert::are_equal_(4, list_box.items().size());
      assert::are_equal_("a", list_box.items()[0]);
      assert::are_equal_("b", list_box.items()[1]);
      assert::are_equal_("c", list_box.items()[2]);
      assert::are_equal_("d", list_box.items()[3]);

#if defined(__XTD_FORMS_NATIVE_WXWIDGETS__)
      assert::are_equal_(4, static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetCount());
      assert::are_equal_("a", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(0));
      assert::are_equal_("b", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(1));
      assert::are_equal_("c", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(2));
      assert::are_equal_("d", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(3));
#endif
    }

    void test_method_(unsorted_add_items_then_make_sorted) {
      form form;
      list_box list_box;
      list_box.parent(form);
      list_box.items().push_back_range({"d", "a", "c", "b"});
      list_box.sorted(true);
      
      assert::are_equal_(4, list_box.items().size());
      assert::are_equal_("a", list_box.items()[0]);
      assert::are_equal_("b", list_box.items()[1]);
      assert::are_equal_("c", list_box.items()[2]);
      assert::are_equal_("d", list_box.items()[3]);

#if defined(__XTD_FORMS_NATIVE_WXWIDGETS__)
      assert::are_equal_(4, static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetCount());
      assert::are_equal_("a", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(0));
      assert::are_equal_("b", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(1));
      assert::are_equal_("c", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(2));
      assert::are_equal_("d", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(3));
#endif
    }

    void test_method_(unsorted_add_items_then_make_std_sorted) {
      form form;
      list_box list_box;
      list_box.parent(form);
      list_box.items().push_back_range({"d", "a", "c", "b"});
      std::sort(list_box.items().begin(), list_box.items().end());
      
      assert::are_equal_(4, list_box.items().size());
      assert::are_equal_("a", list_box.items()[0]);
      assert::are_equal_("b", list_box.items()[1]);
      assert::are_equal_("c", list_box.items()[2]);
      assert::are_equal_("d", list_box.items()[3]);

#if defined(__XTD_FORMS_NATIVE_WXWIDGETS__)
      assert::are_equal_(4, static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetCount());
      assert::are_equal_("a", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(0));
      assert::are_equal_("b", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(1));
      assert::are_equal_("c", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(2));
      assert::are_equal_("d", static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(list_box.handle())->control())->GetString(3));
#endif
    }
  };
}
