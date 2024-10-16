#include <gtk/gtk.h>

#include "app.h"
#include "appwindow.h"
#include "reqinput.h"

struct _AppWindow
{
  GtkApplicationWindow parent;
};

G_DEFINE_TYPE (AppWindow, app_window,
               GTK_TYPE_APPLICATION_WINDOW)

static void
app_window_init (AppWindow *window)
{
  GtkWidget *req = req_input_new ();
  gtk_window_set_child (GTK_WINDOW (window), req);
}

static void
app_window_class_init (AppWindowClass *klass)
{
}

GtkWidget *
app_window_new (CurlyApp *app)
{
  return g_object_new (APP_WINDOW_TYPE,
                       "application", app,
                       "title", "Curly",
                       "default-width", 800,
                       "default-height", 600,
                       NULL);
}
