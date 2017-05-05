/*************************************************************************
 Author: Zhaoting Weng
 Created Time: Tue 15 Mar 2016 02:33:44 PM CST
 File Name: a.cpp
 Description: 
        compile: $ g++ a.cpp `pkg-config --cflags --libs glib-2.0` 
 ************************************************************************/

#include "glib.h"
#include <iostream>

int main()
{
    /* Example 1: G_GINT16_MODIFIER */
    gint16 value = 123;
    g_print("Hexdecimal: " "%#" G_GINT16_MODIFIER "x\n", value);
    g_print("Octal     : " "%#" G_GINT16_MODIFIER "o\n", value);

    /* Example 2: G_GINT16_FORMAT */
    gint16 in;
    gint32 out;
    sscanf("42", "%" G_GINT16_FORMAT, &in);
    out = in * 1000;
    g_print("%" G_GINT32_FORMAT "\n", out);

    /* Example 3: G_STRUCT_MEMBER */

    typedef struct{
        gint16 i;
        gint32 ii;
    } MyStruct;

    MyStruct my_struct;
    my_struct.i = 0x0123;
    my_struct.ii = 0x456789ab;
    g_print("%#" G_GINT16_MODIFIER "x\n%#" G_GINT32_MODIFIER "x\n", my_struct.i, my_struct.ii);
    /*
       OUTPUT:
           0x123
           0x456789ab
     */

    gint16 i1;
    gint32 i2;
    i1 = G_STRUCT_MEMBER(gint16, &my_struct, 0);
    i2 = G_STRUCT_MEMBER(gint32, &my_struct, 4);   // Remember the address allignment (sizeof(my_structuer) == 8)
    g_print("%#" G_GINT16_MODIFIER "x\n%#" G_GINT32_MODIFIER "x\n", i1, i2);
    /*
       OUTPUT:
           0x123
           0x456789ab
     */

    /* Example 4: G_STRUCT_OFFSET() */
    int i, ii; // no effect
    g_print("Offset of member 'i' in MyStruct: %" G_GINT64_FORMAT "\n", G_STRUCT_OFFSET(MyStruct, i));
    g_print("Offset of member 'ii' in MyStruct: %" G_GINT64_FORMAT "\n", G_STRUCT_OFFSET(MyStruct, ii));

}


