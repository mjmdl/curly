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

    GtkLabel *label = (GtkLabel *)gtk_label_new("Request Body");
    gtk_label_set_xalign(label, 0.0);
    gtk_box_append(column, GTK_WIDGET(label));

    GtkTextView *request_body_view = (GtkTextView *)gtk_text_view_new();
    gtk_box_append(column, GTK_WIDGET(request_body_view));
    
    GtkLabel *response_label = (GtkLabel *)gtk_label_new("Response Body");
    gtk_label_set_xalign(response_label, 0.0);
    gtk_box_append(column, GTK_WIDGET(response_label));

    GtkTextView *response_body_view = (GtkTextView *)gtk_text_view_new();
    gtk_box_append(column, GTK_WIDGET(response_body_view));
    gtk_text_view_set_editable(response_body_view, FALSE);

    curly_request_field_set_request_body_buffer(request_field, gtk_text_view_get_buffer(request_body_view));
    curly_request_field_set_response_body_buffer(request_field, gtk_text_view_get_buffer(response_body_view));
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
