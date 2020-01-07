#pragma once
#include <random>
#include <xtd/xtd.forms>
#include "grid.hpp"

namespace game_of_life {
  class form_main : public xtd::forms::form {
    using figure_delegate = xtd::delegate<void()>;
  public:
    form_main() {
      text("John Conway's Game of Life");
      client_size({715, 485});
      
      button_run_.parent(*this);
      button_run_.text("Run");
      button_run_.location({10, 10});
      button_run_.click += [&] {
        timer_run_.enabled(!timer_run_.enabled());
        button_run_.text(timer_run_.enabled() ? "Stop" : "Run");
      };
      
      button_next_.parent(*this);
      button_next_.text("Next");
      button_next_.location({100, 10});
      button_next_.click += {*this, & form_main::next};
      
      button_clear_.parent(*this);
      button_clear_.text("Clear");
      button_clear_.location({190, 10});
      button_clear_.click += {*this, & form_main::clear};
      
      choice_figures_.parent(*this);
      choice_figures_.items().push_back_range({{"Figure", figure_delegate(*this, &form_main::nothing)}, {"Random cells", figure_delegate(*this, &form_main::random)}, {"Blinker", figure_delegate(*this, &form_main::blinker)}, {"Toad", figure_delegate(*this, &form_main::toad)}, {"beacon", figure_delegate(*this, &form_main::beacon)}, {"galaxy", figure_delegate(*this, &form_main::galaxy)}, {"Pulsar", figure_delegate(*this, &form_main::pulsar)}, {"Penta-decathlon", figure_delegate(*this, &form_main::penta_decathlon)}, {"Glider", figure_delegate(*this, &form_main::glider)}, {"Small exploder", figure_delegate(*this, &form_main::small_exploder)}, {"Exploder", figure_delegate(*this, &form_main::exploder)}, {"Lightweight spaceship", figure_delegate(*this, &form_main::lightweight_spaceship)}, {"Middleweight spaceship", figure_delegate(*this, &form_main::middleweight_spaceship)}, {"Heavyweight spaceship", figure_delegate(*this, &form_main::heavyweight_spaceship)}, {"Tumbler", figure_delegate(*this, &form_main::tumbler)}, {"Gosper glider gun", figure_delegate(*this, &form_main::gosper_glider_gun)}});
      choice_figures_.location({280, 11});
      choice_figures_.selected_index(0);
      choice_figures_.width(200);
      choice_figures_.selected_index_changed += [&] {
        std::any_cast<figure_delegate>(choice_figures_.items()[choice_figures_.selected_index()].tag())();
        choice_figures_.selected_index(0);
      };
      
      label_iterations_.parent(*this);
      label_iterations_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      label_iterations_.font(xtd::drawing::font(xtd::drawing::font_family::generic_monospace(), label_iterations_.font().size()));
      label_iterations_.text_align(xtd::forms::content_alignment::middle_right);
      label_iterations_.text(xtd::strings::format("Iterations : {}", iterations_));
      label_iterations_.width(150);
      label_iterations_.location({555, 15});
      
      label_zoom_.parent(*this);
      label_zoom_.location({10, 45});
      label_zoom_.text(xtd::strings::format("Zoom : {}", zoom_));
      
      track_bar_zoom_.parent(*this);
      track_bar_zoom_.auto_size(false);
      track_bar_zoom_.location({90, 40});
      track_bar_zoom_.minimum(1);
      track_bar_zoom_.maximum(50);
      track_bar_zoom_.tick_style(xtd::forms::tick_style::none);
      track_bar_zoom_.value(zoom_);
      track_bar_zoom_.value_changed += [&] {
        if ((track_bar_zoom_.value() * grid::columns) < panel_grid_.client_size().width())
          track_bar_zoom_.value(panel_grid_.client_size().width() / grid::columns + 1);
        if ((track_bar_zoom_.value() * grid::rows) < panel_grid_.client_size().height())
          track_bar_zoom_.value(panel_grid_.client_size().height() / grid::rows + 1);
        zoom_ = track_bar_zoom_.value();
        panel_grid_.invalidate();
        label_zoom_.text(xtd::strings::format("Zoom : {}", zoom_));
      };
      track_bar_zoom_.size({200, 25});
      
      label_speed_.parent(*this);
      label_speed_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      label_speed_.location({425, 45});
      label_speed_.text(xtd::strings::format("Speed : {}", speed_));
      
      track_bar_speed_.parent(*this);
      track_bar_speed_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      track_bar_speed_.auto_size(false);
      track_bar_speed_.location({505, 40});
      track_bar_speed_.minimum(1);
      track_bar_speed_.maximum(100);
      track_bar_speed_.tick_style(xtd::forms::tick_style::none);
      track_bar_speed_.value(speed_);
      track_bar_speed_.value_changed += [&] {
        speed_ = track_bar_speed_.value();
        timer_run_.interval(1000 / speed_);
        label_speed_.text(xtd::strings::format("Speed : {}", speed_));
      };
      track_bar_speed_.size({200, 25});
      
      panel_grid_.parent(*this);
      panel_grid_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom | xtd::forms::anchor_styles::right);
      panel_grid_.back_color(empty_color_);
      panel_grid_.border_style(xtd::forms::border_style::fixed_single);
      panel_grid_.location({10, 75});
      panel_grid_.size({695, 395});
      
      panel_grid_.mouse_down += [&](control& sender, const xtd::forms::mouse_event_args& e) {
        current_state_ = grid_.cells()[offset_y_ + e.location().y() / zoom_][offset_x_ + e.location().x() / zoom_] == cell::populated ? cell::empty : cell::populated;
        grid_.cells()[offset_y_ + e.location().y() / zoom_][offset_x_ + e.location().x() / zoom_] = current_state_;
        panel_grid_.invalidate(xtd::drawing::rectangle(e.location().x() / zoom_ * zoom_, e.location().y() / zoom_ * zoom_, zoom_, zoom_), false);
      };
      
      panel_grid_.mouse_move += [&](control& sender, const xtd::forms::mouse_event_args& e) {
        if (e.button() == xtd::forms::mouse_buttons::left) {
          grid_.cells()[offset_y_ + e.location().y() / zoom_][offset_x_ + e.location().x() / zoom_] = current_state_;
          panel_grid_.invalidate(xtd::drawing::rectangle(e.location().x() / zoom_ * zoom_, e.location().y() / zoom_ * zoom_, zoom_, zoom_), false);
        }
      };
      
      panel_grid_.paint += [&](control& sender, xtd::forms::paint_event_args& e) {
        e.graphics().clear(back_color());
        if ((track_bar_zoom_.value() * grid::columns) >= panel_grid_.client_size().width() && (track_bar_zoom_.value() * grid::rows) >= panel_grid_.client_size().height())
          for (auto y = 0; y < panel_grid_.client_size().height(); y += zoom_)
            for (auto x = 0; x < panel_grid_.client_size().width(); x += zoom_)
              if (grid_.cells()[offset_y_ + y / zoom_][offset_x_ + x / zoom_] != cell::empty)
                e.graphics().fill_rectangle(xtd::drawing::solid_brush(populated_color_), x, y, zoom_, zoom_);
        if (zoom_ > 3) {
          for (auto index = 0; index < panel_grid_.client_size().width(); index += zoom_)
            e.graphics().fill_rectangle(xtd::drawing::solid_brush(line_color_), index, 0, 1, panel_grid_.client_size().height());
          for (auto index = 0; index < panel_grid_.client_size().height(); index += zoom_)
            e.graphics().fill_rectangle(xtd::drawing::solid_brush(line_color_), 0, index, panel_grid_.client_size().width(), 1);
        }
      };
      
      panel_grid_.resize += [&] {
        if ((track_bar_zoom_.value() * grid::columns) < panel_grid_.client_size().width()) {
          zoom_ = panel_grid_.client_size().width() / grid::columns + 1;
          track_bar_zoom_.value(zoom_);
        }
        if ((track_bar_zoom_.value() * grid::rows) < panel_grid_.client_size().height()) {
          zoom_ = panel_grid_.client_size().height() / grid::rows + 1;
          track_bar_zoom_.value(zoom_);
        }
      };
      
      timer_run_.interval(1000 / speed_);
      timer_run_.tick += {*this, &form_main::next};
      
      grid_.cell_changed += [&](grid& sender, const cell_event_args& e) {
        panel_grid_.invalidate(xtd::drawing::rectangle((e.x() - offset_x_) * zoom_, (e.y() - offset_y_) * zoom_, zoom_, zoom_), false);
      };
    }
    
  private:
    void clear() {
      grid_.clear();
      iterations_ = 0;
      label_iterations_.text(xtd::strings::format("Iterations : {}", iterations_));
      panel_grid_.invalidate();
    }
    
    void nothing() {}
    
    void next() {
      grid_.next();
      label_iterations_.text(xtd::strings::format("Iterations : {}", ++iterations_));
    }
    
    void random() {
      std::random_device rand;
      auto max = std::uniform_int_distribution<int>{ 50, 200 }(rand);
      auto max_x = panel_grid_.client_size().width() / zoom_;
      auto max_y = panel_grid_.client_size().height() / zoom_;
      for (auto counter = 0; counter < max; counter++) {
        auto x = std::uniform_int_distribution<int>(0, max_x)(rand);
        auto y = std::uniform_int_distribution<int>(0, max_y)(rand);
        grid_.cells()[offset_y_ + y][offset_x_ + x] = cell::populated;
        panel_grid_.invalidate(xtd::drawing::rectangle(x * zoom_, y * zoom_, zoom_, zoom_), false);
      }
    }
    
    void fill_figure(const std::vector<std::string>& figure) {
      auto height = static_cast<int>(figure.size());
      auto width = 0;
      for (auto line : figure)
        if (line.length() > width) width = static_cast<int>(line.length());
      
      auto start_x = (panel_grid_.client_size().width() / zoom_ / 2) - (width / 2);
      auto y = (panel_grid_.client_size().height() / zoom_ / 2) - (height / 2);
      
      if (start_x < 5) start_x = 5;
      if (y < 5) y = 5;
      
      for (auto line : figure) {
        auto x = start_x;
        for (auto cell : line) {
          grid_.cells()[offset_y_ + y][offset_x_ + x] = cell != ' ' ? cell::populated : cell::empty;
          panel_grid_.invalidate(xtd::drawing::rectangle(x * zoom_, y * zoom_, zoom_, zoom_), false);
          x++;
        }
        y++;
      }
    }
    
    void beacon() {
      fill_figure({
        "**  ",
        "*   ",
        "   *",
        "  **"
      });
    }
    
    void blinker() {
      fill_figure({
        "*",
        "*",
        "*"
      });
    }
    
    void exploder() {
      fill_figure({
        "* * *",
        "*   *",
        "*   *",
        "*   *",
        "* * *"
      });
    }
    
    void galaxy() {
      fill_figure({
        "****** **",
        "****** **",
        "       **",
        "**     **",
        "**     **",
        "**     **",
        "**       ",
        "** ******",
        "** ******",
      });
    }
    void glider() {
      fill_figure({
        " * ",
        "  *",
        "***"
      });
    }
    
    void gosper_glider_gun() {
      fill_figure({
        "                       **         **  ",
        "                      * *         **  ",
        "**       **           **              ",
        "**      * *                           ",
        "        **      **                    ",
        "                * *                   ",
        "                *                     ",
        "                                   ** ",
        "                                   * *",
        "                                   *  ",
        "                                      ",
        "                                      ",
        "                        ***           ",
        "                        *             ",
        "                         *            "
      });
    }
    void heavyweight_spaceship() {
      fill_figure({
        "  **   ",
        "*    * ",
        "      *",
        "*     *",
        " ******"
      });
    }
    
    void lightweight_spaceship() {
      fill_figure({
        "*  * ",
        "    *",
        "*   *",
        " ****"
      });
    }
    
    void middleweight_spaceship() {
      fill_figure({
        "  *   ",
        "*   * ",
        "     *",
        "*    *",
        " *****"
      });
    }
    
    void penta_decathlon() {
      fill_figure({
        "**********"
      });
    }
    void pulsar() {
      fill_figure({
        "  ***   ***  ",
        "             ",
        "*    * *    *",
        "*    * *    *",
        "*    * *    *",
        "  ***   ***  ",
        "             ",
        "  ***   ***  ",
        "*    * *    *",
        "*    * *    *",
        "*    * *    *",
        "             ",
        "  ***   ***  "
      });
    }
    
    void small_exploder() {
      fill_figure({
        " * ",
        "***",
        "* *",
        " * "
      });
    }
    
    void toad() {
      fill_figure({
        " ***",
        "*** "
      });
    }
    
    void tumbler() {
      fill_figure({
        " ** ** ",
        " ** ** ",
        "  * *  ",
        "* * * *",
        "* * * *",
        "**   **"
      });
    }
    
    cell current_state_ = cell::empty;
    grid grid_;
    int iterations_ = 0;
    int zoom_ = 15;
    int speed_ = 25;
    int offset_x_ = 200;
    int offset_y_ = 200;
    
    xtd::forms::button button_run_;
    xtd::forms::button button_next_;
    xtd::forms::button button_clear_;
    xtd::forms::choice choice_figures_;
    xtd::forms::label label_iterations_;
    xtd::forms::label label_zoom_;
    xtd::forms::track_bar track_bar_zoom_;
    xtd::forms::label label_speed_;
    xtd::forms::track_bar track_bar_speed_;
    xtd::forms::panel panel_grid_;
    xtd::forms::timer timer_run_;
    xtd::drawing::color line_color_ = xtd::drawing::system_colors::window_text();
    xtd::drawing::color empty_color_ = xtd::drawing::system_colors::window();
    xtd::drawing::color populated_color_ = xtd::drawing::system_colors::window_text();
  };
}
