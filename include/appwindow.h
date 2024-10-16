#ifndef CURLY_APPWINDOW_H
#define CURLY_APPWINDOW_H

#include <gtk/gtk.h>

#include "app.h"

G_BEGIN_DECLS

#define APP_WINDOW_TYPE (app_window_get_type ())

G_DECLARE_FINAL_TYPE (AppWindow, app_window,
                      APP, WINDOW,
                      GtkApplicationWindow)

GtkWidget *app_window_new (CurlyApp *app);
     
G_END_DECLS

#endif // CURLY_APPWINDOW_H
