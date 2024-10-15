#include <gtk/gtk.h>

#include "app.h"
#include "appwindow.h"

struct _CurlyAppWindow
{
  GtkApplicationWindow parent;
};

G_DEFINE_TYPE (CurlyAppWindow, curly_app_window,
	       GTK_TYPE_APPLICATION_WINDOW)

static void
curly_app_window_init (CurlyAppWindow *window)
{
}

static void
curly_app_window_class_init (CurlyAppWindowClass *klass)
{
}

GtkWidget *
curly_app_window_new (CurlyApp *app)
{
  return g_object_new (CURLY_TYPE_APP_WINDOW,
		       "application", app,
		       "title", "Curly",
		       "default-width", 800,
		       "default-height", 600,
		       NULL);
}
