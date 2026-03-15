#include <gtk/gtk.h>

#include "curly_app.h"

int main(int argc, char **argv) {
    CurlyApp *app = curly_app_new();
    return g_application_run(G_APPLICATION(app), argc, argv);
}
