/// @file
/// @brief Contains main_form class.
#pragma once
#include "project_type_item_control.h"
#include "project_type_items_control.h"
#include "xtd_example_item.h"
#include <limits>
#include <memory>
#include <vector>
#include <xtd/forms/background_worker.h>
#include <xtd/forms/button.h>
#include <xtd/forms/check_box.h>
#include <xtd/forms/choice.h>
#include <xtd/forms/form.h>
#include <xtd/forms/label.h>
#include <xtd/forms/list_box.h>
#include <xtd/forms/panel.h>
#include <xtd/forms/picture_box.h>
#include <xtd/forms/progress_dialog.h>
#include <xtd/forms/tab_control.h>
#include <xtd/forms/tab_page.h>
#include <xtd/forms/text_box.h>

namespace xtdc_gui {
  /// @brief Represents the main form
  class main_form : public xtd::forms::form {
  public:
    /// @brief Initializes a new instance of the main_form class.
    main_form();

    /// @brief The main entry point for the application.
    static void main();
    
  private:
    void add_to_create_recent_projects(size_t create_project_items_index);
    void add_to_open_recent_projects(const std::string& project_path);
    void delete_from_create_recent_projects(size_t create_project_items_index);
    void delete_from_open_recent_projects(const std::string& project_path);
    void init();
    void init_create_create_recent_projects_list_box();
    void init_startup_open_recent_projects_list_box();
    void new_project(const std::string& project_path, size_t project_type_items_index);
    void new_project(const std::string& project_path, project_type type, project_language language, project_sdk sdk);
    void open_project(const std::string& project_path);
    void run_project(const std::string& project_path);

    std::unique_ptr<xtd::forms::background_worker> background_worker_;
    std::unique_ptr<xtd::forms::progress_dialog> progress_dialog_;
    xtd::forms::panel startup_panel_;
    xtd::forms::label startup_title_label_;
    xtd::forms::label startup_open_recent_project_title_label_;
    xtd::forms::list_box startup_open_recent_projects_list_box_;
    xtd::forms::label startup_get_started_title_label_;
    xtd::forms::button startup_open_project_button_;
    xtd::forms::button startup_run_project_button_;
    xtd::forms::button startup_new_project_button_;
    xtd::forms::button startup_open_xtd_examples_button_;

    xtd::forms::panel open_xtd_examples_panel_;
    xtd::forms::label open_xtd_examples_title_label_;
    xtd::forms::tab_control open_xtd_example_tab_control_;
    xtd::forms::tab_page open_xtd_example_core_tab_page_;
    xtd::forms::tab_page open_xtd_example_forms_tab_page_;
    xtd::forms::tab_page open_xtd_example_tunit_tab_page_;
    xtd::forms::tab_page open_xtd_example_cmake_tab_page_;
    xtd::forms::picture_box open_xtd_example_core_picture_box_;
    xtd::forms::picture_box open_xtd_example_forms_picture_box_;
    xtd::forms::picture_box open_xtd_example_tunit_picture_box_;
    xtd::forms::picture_box open_xtd_example_cmake_picture_box_;
    xtd::forms::label open_xtd_example_cmake_title_label_;
    xtd::forms::label open_xtd_example_core_title_label_;
    xtd::forms::label open_xtd_example_forms_title_label_;
    xtd::forms::label open_xtd_example_tunit_title_label_;
    xtd::forms::list_box open_xtd_example_cmake_list_box_;
    xtd::forms::list_box open_xtd_example_core_list_box_;
    xtd::forms::list_box open_xtd_example_forms_list_box_;
    xtd::forms::list_box open_xtd_example_tunit_list_box_;
    xtd::forms::text_box open_xtd_examples_information_text_box_;
    xtd::forms::picture_box open_xtd_examples_information_picture_box_;

    xtd::forms::panel create_panel_;
    xtd::forms::label create_title_label_;
    xtd::forms::label create_recent_project_title_label_;
    xtd::forms::list_box create_create_recent_projects_list_box_;
    xtd::forms::choice create_language_choice_;
    xtd::forms::choice create_platform_choice_;
    xtd::forms::choice create_type_choice_;
    project_type_items_control create_project_type_items_control_;

    xtd::forms::panel configure_panel_;
    xtd::forms::label configure_title_label_;
    xtd::forms::label configure_project_type_title_label_;
    xtd::forms::label configure_project_name_label_;
    xtd::forms::text_box configure_project_name_text_box_;
    xtd::forms::label configure_project_location_label_;
    xtd::forms::text_box configure_project_location_text_box_;
    xtd::forms::button configure_project_location_button_;

    xtd::forms::check_box auto_close_check_box_;
    xtd::forms::button previous_button_;
    xtd::forms::button next_button_;
    
    size_t current_project_type_index_ = std::numeric_limits<size_t>::max();
    size_t current_open_xtd_example_core_list_box_index_ = 0;
    size_t current_open_xtd_example_forms_list_box_index_ = 0;
    size_t current_open_xtd_example_tunit_list_box_index_ = 0;
    size_t current_open_xtd_example_cmake_list_box_index_ = 0;
  };
}
