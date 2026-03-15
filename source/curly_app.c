#include <gtk/gtk.h>

#include "curly_app.h"
#include "curly_app_window.h"

struct _CurlyApp {
    GtkApplication parent;
};

G_DEFINE_TYPE(CurlyApp, curly_app, GTK_TYPE_APPLICATION)
     
static void curly_app_init(CurlyApp *app) {
}

static void curly_app_activate(CurlyApp *app) {
    CurlyAppWindow *window = curly_app_window_new(app);
    gtk_window_present(GTK_WINDOW(window));
}

static void curly_app_class_init(CurlyAppClass *class) {
    G_APPLICATION_CLASS(class)->activate = (void(*)(GApplication *))curly_app_activate;
}

CurlyApp *curly_app_new(void) {
    return g_object_new(
        CURLY_TYPE_APP,
        "application-id", "com.github.mjmdl.curly",
        "flags", G_APPLICATION_DEFAULT_FLAGS,
        NULL);
}
