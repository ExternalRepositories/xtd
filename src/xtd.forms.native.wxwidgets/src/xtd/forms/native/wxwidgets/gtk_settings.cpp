#if defined(__WXGTK__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses"
#include <gtk/gtk.h>
#pragma GCC diagnostic pop

void __gtk_button_images__(bool enable) {
  g_object_set(gtk_settings_get_default(), "gtk-button-images", enable, nullptr);
}

void __gtk_menu_images__(bool enable) {
  g_object_set(gtk_settings_get_default(), "gtk-menu-images", enable, nullptr);
}

void __gtk_application_prefer_dark_theme__(bool prefer_dark_theme) {
  g_object_set(gtk_settings_get_default(), "gtk-application-prefer-dark-theme", prefer_dark_theme, nullptr);
}
#endif
