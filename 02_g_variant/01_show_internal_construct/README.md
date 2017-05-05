This code here is used to show gvariant internal structure which is used in SGM358, therefore needs to include/link to the specific glib other than that in Ubuntu.

Build it with following command:

    g++ tuple.cpp -std=c++0x  -I${HOME}/bin/glib-2.30.3/include/glib-2.0 -I${HOME}/bin/glib-2.30.3/lib/glib-2.0/include /home/uidj4668/bin/glib-2.30.3/lib/libglib-2.0.so
