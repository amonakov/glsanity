#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include "common.h"

int main(int argc, char *argv[])
{
  const char *msg1 = "libGL.so.1";
  void *libgl = dlopen("libGL.so.1", RTLD_LAZY);
  if (!libgl)
    die("loading with dlopen failed:\n%s", dlerror());
  void *libgl_sym = dlsym(libgl, "glXQueryVersion");
  if (!libgl_sym)
    die("dlsym failed: %s", dlerror());
  Dl_info libgl_info;
  if (!dladdr(libgl_sym, &libgl_info))
    die("dladdr failed");
  inform("loaded from: %s", libgl_info.dli_fname);

  char *real_path = canonicalize_file_name(libgl_info.dli_fname);
  if (strcmp(real_path, libgl_info.dli_fname))
    inform("symlink to:  %s", real_path);
  free(real_path);

  return 0;
}
