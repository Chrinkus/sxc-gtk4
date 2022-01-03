#include "example_app.h"
#include "example_app_win.h"

struct _ExampleApp {
	GtkApplication parent;
};

G_DEFINE_TYPE(ExampleApp, example_app, GTK_TYPE_APPLICATION);

static void example_app_init(ExampleApp* app)
{
	// Nothing yet..
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// gear-menu actions

static void preferences_activated(GSimpleAction* action, GVariant* parameter,
		gpointer app)
{
	// Nothing yet..
}

static void quit_activated(GSimpleAction* action, GVariant* parameter,
		gpointer app)
{
	g_application_quit(G_APPLICATION(app));
}

static GActionEntry app_entries[] = {
	{ "preferences", preferences_activated, NULL, NULL, NULL },
	{ "quit", quit_activated, NULL, NULL, NULL }
};

static void example_app_startup(GApplication* app)
{
	const char* quit_accels[2] = { "<Ctrl>Q", NULL };

	G_APPLICATION_CLASS(example_app_parent_class)->startup(app);

	g_action_map_add_action_entries(G_ACTION_MAP(app),
			app_entries, G_N_ELEMENTS(app_entries),
			app);
	gtk_application_set_accels_for_action(GTK_APPLICATION(app), "app.quit",
			quit_accels);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

static void example_app_activate(GApplication* app)
{
	ExampleAppWindow* win = example_app_window_new(EXAMPLE_APP(app));
	gtk_window_present(GTK_WINDOW(win));
}

static void example_app_open(GApplication* app, GFile** files, int num_files,
		const char* hint)
{
	GList* windows = gtk_application_get_windows(GTK_APPLICATION(app));

	ExampleAppWindow* win;
	if (windows)
		win = EXAMPLE_APP_WINDOW(windows->data);
	else
		win = example_app_window_new(EXAMPLE_APP(app));

	for (int i = 0; i < num_files; ++i)
		example_app_window_open(win, files[i]);

	gtk_window_present(GTK_WINDOW(win));
}

static void example_app_class_init(ExampleAppClass* class)
{
	G_APPLICATION_CLASS(class)->startup = example_app_startup;
	G_APPLICATION_CLASS(class)->activate = example_app_activate;
	G_APPLICATION_CLASS(class)->open = example_app_open;
}

ExampleApp* example_app_new(void)
{
	return g_object_new(EXAMPLE_APP_TYPE,
			"application-id",
			"org.gtk.exampleapp",
			"flags",
			G_APPLICATION_HANDLES_OPEN,
			NULL);
}

