#include <gtk/gtk.h>

#include "curly_http_service.h"
#include "curly_request_field.h"

struct _CurlyRequestField {
    GtkBox parent;

    GtkDropDown *verbs_drop_down;
    GtkText *address_text;

    CurlyHttpService *http_service;
};

static const char *const http_verbs[] = {
    "GET",
    "POST",
    "PATCH",
    "PUT",
    "DELETE",
    NULL,
};

G_DEFINE_TYPE(CurlyRequestField, curly_request_field, GTK_TYPE_BOX)
     
static void perform_request_callback(GtkWidget *sender, CurlyRequestField *field) {
    guint selected_verb = gtk_drop_down_get_selected(field->verbs_drop_down);
    if (selected_verb >= ((sizeof http_verbs / sizeof http_verbs[0]) - 1)) {
        g_error("Invalid HTTP verb index is selected: %u (minimum = 0, maximum = %lu)\n", selected_verb, sizeof http_verbs[0] - 1);
        return;
    }
    const char *verb = http_verbs[selected_verb];
    
    GtkEntryBuffer *address_buffer = gtk_text_get_buffer(field->address_text);
    const char *address = "";
    if (gtk_entry_buffer_get_length(address_buffer) != 0) {
        address = gtk_entry_buffer_get_text(address_buffer);
    } else {
        address = gtk_text_get_placeholder_text(field->address_text);
    }

    curly_http_service_perform(field->http_service, verb, address);
}

static void curly_request_field_init(CurlyRequestField *field) {
    {
        GtkStringList *verbs_string_list = gtk_string_list_new(http_verbs);
        GtkExpression *expression = NULL;
        field->verbs_drop_down = (GtkDropDown *)gtk_drop_down_new(G_LIST_MODEL(verbs_string_list), expression);
        gtk_box_append(GTK_BOX(field), GTK_WIDGET(field->verbs_drop_down));
    }

    {
        field->address_text = (GtkText *)gtk_text_new();
        gtk_widget_set_hexpand(GTK_WIDGET(field->address_text), TRUE);
        gtk_text_set_placeholder_text(field->address_text, "http://localhost:8080/");
        g_signal_connect(field->address_text, "activate", G_CALLBACK(perform_request_callback), field);
        gtk_box_append(GTK_BOX(field), GTK_WIDGET(field->address_text));
    }

    {
        GtkButton *send_button = (GtkButton *)gtk_button_new_with_label("Send");
        g_signal_connect(send_button, "clicked", G_CALLBACK(perform_request_callback), field);
        gtk_box_append(GTK_BOX(field), GTK_WIDGET(send_button));
    }

    field->http_service = curly_http_service_new();
}

static void curly_request_field_class_init(CurlyRequestFieldClass *class) {
}

CurlyRequestField *curly_request_field_new(void) {
    return g_object_new(
        CURLY_TYPE_REQUEST_FIELD,
        "orientation", GTK_ORIENTATION_HORIZONTAL,
        "spacing", 0,
        NULL);
}

void curly_request_field_set_request_body_buffer(CurlyRequestField *field, GtkTextBuffer *buffer) {
    curly_http_service_set_request_body_buffer(field->http_service, buffer);
}

void curly_request_field_set_response_body_buffer(CurlyRequestField *field, GtkTextBuffer *buffer) {
    curly_http_service_set_response_body_buffer(field->http_service, buffer);
}
