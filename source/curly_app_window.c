#include <gtk/gtk.h>

#include "curly_app.h"
#include "curly_app_window.h"
#include "curly_request_field.h"

struct _CurlyAppWindow {
    GtkApplicationWindow parent;
};

G_DEFINE_TYPE(CurlyAppWindow, curly_app_window, GTK_TYPE_APPLICATION_WINDOW)

static void curly_app_window_init(CurlyAppWindow *window) {
    GtkBox *column = (GtkBox *)gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_window_set_child(GTK_WINDOW(window), GTK_WIDGET(column));
    
    CurlyRequestField *request_field = curly_request_field_new();
    gtk_box_append(column, GTK_WIDGET(request_field));
}

CurlyAppWindow *curly_app_window_new(CurlyApp *app) {
    return g_object_new(
        CURLY_TYPE_APP_WINDOW,
        "application", app,
        "title", "Curly",
        "default-width", 800,
        "default-height", 600,
        NULL);
}

static void curly_app_window_class_init(CurlyAppWindowClass *class) {
}
