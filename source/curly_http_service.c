#include <curl/curl.h>
#include <gtk/gtk.h>

#include "curly_http_service.h"

struct _CurlyHttpService {
    GObject parent;

    GtkTextBuffer *request_body_buffer;
    GtkTextBuffer *response_body_buffer;
    
    CURL *curl;
};

G_DEFINE_TYPE(CurlyHttpService, curly_http_service, G_TYPE_OBJECT)

static gboolean select_curl_http_verb(CURL *curl, const char *verb) {
    switch (verb[0]) {
    case 'D':
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
        return TRUE;

    case 'G':
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        return TRUE;

    case 'P':
        switch (verb[1]) {
        case 'A':
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PATCH");
            return TRUE;

        case 'O':
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            return TRUE;

        case 'U':
            curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
            return TRUE;
        }
    }
    return FALSE;
}

static size_t read_from_curl_callback(char *data, size_t member_size, size_t members_count, void *user) {
    GtkTextBuffer *buffer = (GtkTextBuffer *)user;
    GtkTextIter end;
    gtk_text_buffer_get_end_iter(buffer, &end);
    size_t size = member_size * members_count;
    gtk_text_buffer_insert(buffer, &end, data, size);
    return size;
}

static void curly_http_service_init(CurlyHttpService *http) {
    http->curl = curl_easy_init();
}

static void curly_http_service_finalize(CurlyHttpService *http) {
    curl_easy_cleanup(http->curl);
    
    http->request_body_buffer = NULL;
    http->response_body_buffer = NULL;
}

static void curly_http_service_class_init(CurlyHttpServiceClass *class) {
    G_OBJECT_CLASS(class)->finalize = (void(*)(GObject *))curly_http_service_finalize;
}

CurlyHttpService *curly_http_service_new(void) {
    return g_object_new(CURLY_TYPE_HTTP_SERVICE, NULL);
}

gboolean curly_http_service_perform(CurlyHttpService *http, const char *verb, const char *address) {
    curl_easy_reset(http->curl);
    curl_easy_setopt(http->curl, CURLOPT_URL, address);
    if (!select_curl_http_verb(http->curl, verb)) {
        g_printerr("Unknown HTTP verb: %s\n", verb);
        return FALSE;
    }

    char *request_body = NULL;
    if (http->request_body_buffer != NULL) {
        GtkTextIter iter_start;
        GtkTextIter iter_end;
        gtk_text_buffer_get_bounds(http->request_body_buffer, &iter_start, &iter_end);
        request_body = gtk_text_buffer_get_text(http->request_body_buffer, &iter_start, &iter_end, FALSE);
        curl_easy_setopt(http->curl, CURLOPT_POSTFIELDS, request_body);
        curl_easy_setopt(http->curl, CURLOPT_POSTFIELDSIZE, strlen(request_body));
    }

    if (http->response_body_buffer != NULL) {
        gtk_text_buffer_set_text(http->response_body_buffer, "", 0);
        curl_easy_setopt(http->curl, CURLOPT_WRITEFUNCTION, read_from_curl_callback);
        curl_easy_setopt(http->curl, CURLOPT_WRITEDATA, http->response_body_buffer);
    }
    
    CURLcode result = curl_easy_perform(http->curl);

    if (result != CURLE_OK) {
        g_printerr("Request failed with error #%d: %s\n", result, curl_easy_strerror(result));
    }

    if (request_body != NULL) {
        g_free(request_body);
    }

    return result == CURLE_OK;
}

void curly_http_service_set_request_body_buffer(CurlyHttpService *http, GtkTextBuffer *buffer) {
    http->request_body_buffer = buffer;
}

void curly_http_service_set_response_body_buffer(CurlyHttpService *http, GtkTextBuffer *buffer) {
    http->response_body_buffer = buffer;
}
