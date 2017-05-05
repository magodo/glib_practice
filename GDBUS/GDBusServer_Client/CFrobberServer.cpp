/*************************************************************************
 Author: Zhaoting Weng
 Created Time: Tue 11 Oct 2016 06:11:46 PM CST
 File Name: CFrobberServer.cpp
 Description: 
 ************************************************************************/

/* System header */
#include <iostream>

/* Glib related header */
#include <gio/gio.h>
#include <glib-2.0/glib.h>

/* Generated header */
#include "myapp-generated.h"

using namespace std;

class CFrobberServer {

    public:

        CFrobberServer(){}
        ~CFrobberServer(){}

        void init()
        {
            g_type_init();

            m_g_main_loop = g_main_loop_new(NULL, FALSE);

            // create dbus connection
            g_bus_own_name(
                G_BUS_TYPE_SESSION,                 // bus type
			    "net.Corp.MyApp",                   // bus name
			    G_BUS_NAME_OWNER_FLAGS_NONE,        // flag
			    &busAcquiredCallback,               // bus acquired callback
			    &nameAcquiredCallback,              // name acquired callback
			    &nameLostCallback,                  // name lost callback
			    NULL,                               // user data
			    NULL);

            g_main_loop_run(m_g_main_loop);
            g_main_loop_unref(m_g_main_loop);
        }

        /**
         * Callback for gbus_own_name
         */

        static void busAcquiredCallback(GDBusConnection *connection, const gchar* bus_name, gpointer user_data)
        {
            // new skeleton, set property, connect signal, export skeleton
            m_interface = my_app_frobber_skeleton_new();
            my_app_frobber_set_verbose(m_interface, TRUE);

            g_signal_connect(m_interface,
                             "handle-hello-world",
                             G_CALLBACK(onHandleHelloWorld),
                             NULL);

            GError *error = NULL;
            g_dbus_interface_skeleton_export (G_DBUS_INTERFACE_SKELETON(m_interface),
                                              connection,
                                              "/net/Corp/MyApp/SomeFrobber",
                                              &error);
            if (error != NULL)
            {
                cout << "Error: Failed to export object. Reason: " << error->message << endl;
                g_error_free(error);
            }
        }

        static void nameAcquiredCallback(GDBusConnection *connection, const gchar* bus_name, gpointer user_data) {}
        static void nameLostCallback(GDBusConnection *connection, const gchar* bus_name, gpointer user_data) {}

        /**
         * Handler of method: HelloWorld
         */

        static gboolean onHandleHelloWorld (
                            MyAppFrobber *object,
                            GDBusMethodInvocation *invocation,
                            const gchar *arg_greeting)// FIXME: if it works without last argument "gpointer user_data"
        { 
            gchar *response;
            response = g_strdup_printf("You said %s", arg_greeting);
            my_app_frobber_complete_hello_world(m_interface, invocation, response);
            g_free(response);

            return TRUE;
        }

        /**
         * Method to emit signal: notification
         */

        void emitNotification(const gchar *arg_icon_blob,
                              gint arg_height,
                              const gchar *const *arg_messages)
        {
            my_app_frobber_emit_notification(m_interface, arg_icon_blob, arg_height, arg_messages);
        }

    private:
        GMainLoop *m_g_main_loop;
        static MyAppFrobber *m_interface;
};

MyAppFrobber *CFrobberServer::m_interface;

int main()
{
    CFrobberServer server;
    server.init();
}
