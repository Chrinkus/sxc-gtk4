#pragma once

#include <gtk/gtk.h>
#include "example_app_win.h"

#define EXAMPLE_APP_PREFS_TYPE (example_app_prefs_get_type())
G_DECLARE_FINAL_TYPE(ExampleAppPrefs, example_app_prefs, EXAMPLE, APP_PREFS,
		GtkDialog);

ExampleAppPrefs* example_app_prefs_new(ExampleAppWindow* win);

