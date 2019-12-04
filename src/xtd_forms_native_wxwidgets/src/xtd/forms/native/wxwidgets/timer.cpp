#include <stdexcept>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/timer.hpp>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_timer.hpp"

using namespace xtd;
using namespace xtd::forms::native;

intptr_t timer::create(int32_t interval, const delegate<void(const event_args&)>& tick) {
  application::initialize(); // Must be first
  wx_timer* timer = new class wx_timer(tick);
  timer->timer().Start(interval);
  return reinterpret_cast<intptr_t>(timer);
}

void timer::destroy(intptr_t handle) {
  wx_timer* timer = reinterpret_cast<class wx_timer*>(handle);
  timer->timer().Stop();
  delete timer;
}
