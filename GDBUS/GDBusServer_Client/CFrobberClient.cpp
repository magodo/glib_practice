/*************************************************************************
 Author: Zhaoting Weng
 Created Time: Tue 11 Oct 2016 05:53:01 PM CST
 File Name: CFrobberClient.cpp
 Description: 
 ************************************************************************/

#include <iostream>
#include <gio.h>
#include <glib.h>
#include "myapp-generated.h"

using namespace std;

class CFrobberClient {

    public:

        /**
         * C'tor
         */

        FrobberClient(){

            GError *error;

            /* create proxy */
            m_proxy =  my_app_frobber_proxy_new_for_bus_sync (
                            GBusType        G_BUS_TYPE_SESSION,
                            GDBusProxyFlags G_DBUS_PROXY_FLAGS_NONE,
                            const gchar     "net.Corp.MyApp",               /* bus name of the interface implementer*/
                            const gchar     "/net/Corp/MyApp/SomeFrobber",  /* object of interface implementer */
                            GCancellable    NULL,                           /* GCancellable* */
                            GError          &error);

            /* connect signal handler */
            g_signal_connect(m_proxy, "handle-notification", G_CALLBACK(onHandlerNotification), NULL);

        }

        /**
         * Callback of signal: notification
         */

        static gboolean onHandlerNotification (MyAppFrobber *object,
                                               GDBusMethodInvocation *invocation,
                                               const gchar *arg_greeting) {
            cout << "Signal content: " << arg_greeting << endl;
            return TRUE;
        }

        /**
         * Method to invoke: HelloWorld
         */

        void callHelloWorld() {
            gchar *out_response;
            GError *error;

            my_app_frobber_call_hello_world_sync (
                    m_proxy,
                    "Greeting1",
                    &out_response,
                    NULL,
                    &error);
            cout << "Response: " << out_response << endl;
        }

        /**
         * Method to get/set property: Verbose
         */

        void setVerbose(gboolean value){
            my_app_frobber_set_verbose(m_proxy, value);
        }

        void showCurrentVerbose() {
            cout << "Current verbose mode is: " << my_app_frobber_get_verbose(m_proxy) << endl;
        }


    private:
        MyAppFrobber *m_proxy;
};
