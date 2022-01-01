#include "example_app.h"
#include "example_app_win.h"

struct _ExampleAppWindow {
	GtkApplicationWindow parent;
};

G_DEFINE_TYPE(ExampleAppWindow, example_app_window,
		GTK_TYPE_APPLICATION_WINDOW);

static void example_app_window_init(ExampleAppWindow* win)
{
	gtk_widget_init_template(GTK_WIDGET(win));
}

static void example_app_window_class_init(ExampleAppWindowClass* class)
{
	gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class),
			"/home/chrinkus/Repos/sxc-gtk4/src/example-5/window.ui");
}

ExampleAppWindow* example_app_window_new(ExampleApp* app)
{
	return g_object_new(EXAMPLE_APP_WINDOW_TYPE, "application", app, NULL);
}

void example_app_window_open(ExampleAppWindow* win, GFile* file)
{
	// Nothing yet..
}

