#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glx.h>
#include "common.h"

int main(int argc, char *argv[])
{
  const char *msg1 = "X display";
  Display *dpy = XOpenDisplay(NULL);
  if (!dpy)
    die("failed to open connection");

  //FIXME: screen 0 hard-coded
  int screen = 0;
  msg1 = "GLX server";
  const char *glx_srv_vnd = glXQueryServerString(dpy, screen, GLX_VENDOR);
  if (!glx_srv_vnd)
    die("lookup failed");
  inform("%s", glx_srv_vnd);

  msg1 = "GLX client";
  const char *glx_lib_vnd = glXGetClientString(dpy, GLX_VENDOR);
  inform("%s", glx_lib_vnd);

  msg1 = "GLX DB RGBA FBConfig";
  int nconfigs, fbattrs[]
   = {GLX_CONFIG_CAVEAT, GLX_NONE,
      GLX_DOUBLEBUFFER, True,
      GLX_RENDER_TYPE, GLX_RGBA_BIT,
      GLX_DRAWABLE_TYPE, GLX_PBUFFER_BIT,
      0};
  GLXFBConfig *fbconfigs = glXChooseFBConfig(dpy, screen, fbattrs, &nconfigs);
  if (!fbconfigs)
    die("none reported");

  //FIXME: some errors will be reported via the X11 protocol
  msg1 = "GLX Pbuffer";
  int pbattrs[] = {GLX_PBUFFER_WIDTH, 32, GLX_PBUFFER_HEIGHT, 32, 0};
  GLXPbuffer pbuf = glXCreatePbuffer(dpy, fbconfigs[0], pbattrs);

  msg1 = "GLX Context";
  GLXContext ctx = glXCreateNewContext(dpy, fbconfigs[0], GLX_RGBA_TYPE, 0, True);
  if (!ctx)
    die("failed");

  if (!glXIsDirect(dpy, ctx))
    inform("direct rendering not available");

  if (!glXMakeCurrent(dpy, pbuf, ctx))
    die("glXMakeCurrent failed");

  msg1 = "GL vendor";
  const char *gl_vnd = (const char *)glGetString(GL_VENDOR);
  inform("%s", gl_vnd);
  msg1 = "GL renderer";
  const char *gl_rnd = (const char *)glGetString(GL_RENDERER);
  inform("%s", gl_rnd);
  msg1 = "GL version";
  const char *gl_ver = (const char *)glGetString(GL_VERSION);
  inform("%s", gl_ver);

  // Direct rendering != hardware accelerated rendering
  msg1 = "GL hw accelerated";
  if (strstr(gl_rnd, "llvmpipe") || strstr(gl_rnd, "Software"))
    inform("no");

  return 0;
}
