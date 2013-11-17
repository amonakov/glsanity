#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include "common.h"

int main(int argc, char *argv[])
{
  const char *msg1 = "X display";
  char *dpyname = getenv("DISPLAY");
  if (!dpyname)
    die("DISPLAY not set");
  inform("%s", dpyname);

  Display *dpy = XOpenDisplay(dpyname);
  if (!dpy)
    die("failed to open connection");

  msg1 = "X Ext. \"GLX\"";
  int dummy;
  if (!XQueryExtension(dpy, "GLX", &dummy, &dummy, &dummy))
    die("not present; see the Xorg log for details");
  inform("present");

  msg1 = "X Ext. \"NV-GLX\"";
  if (!XQueryExtension(dpy, "NV-GLX", &dummy, &dummy, &dummy))
    inform("not present; OK for non-nVidia drivers");
  else
    inform("present");

  return 0;
}
