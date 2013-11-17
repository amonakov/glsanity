glsanity
========

Absence of 32-bit OpenGL libraries on 64-bit Linux distributions or mismatch
between OpenGL client library and Xorg GLX module implementations on systems
using proprietary OpenGL drivers is a well-known source of problems.

'glsanity' aims to help in diagnosing such problems by providing a few test
programs in one package.

Both 32-bit and 64-bit tests are included with prebuilt binaries.  To download,
navigate to [releases page](https://github.com/amonakov/glsanity/releases) and
grab the `glsanity-bin.zip` file.

Most users should run the `./glsanity` script.  Users of laptops with hybrid
graphics using Bumblebee and primus for offloading can use `./glsanity-bbee`.

What is tested
--------------

The following tests are performed:

 - What OpenGL library (libGL.so.1) is loaded by default
 - That GLX extension is available on the X connection
 - That direct rendering is available

The last test also tries to detect software rendering by matching `GL_RENDERER`
for 'llvmpipe' and 'Software' (for Mesa swrast).

Sample output
-------------

**NVIDIA drivers, Gentoo**


```
Running 32-bit tests
info:  libGL.so.1:      loaded from: /usr/lib32/libGL.so.1
info:  libGL.so.1:      symlink to:  /usr/lib32/opengl/nvidia/lib/libGL.so.325.15
info:  X display:       :0.0
info:  X Ext. "GLX":    present
info:  X Ext. "NV-GLX": present
info:  GLX server:      NVIDIA Corporation
info:  GLX client:      NVIDIA Corporation
info:  GL vendor:       NVIDIA Corporation
info:  GL renderer:     GeForce GTX 460/PCIe/SSE2
info:  GL version:      4.3.0 NVIDIA 325.15
Running 64-bit tests
info:  libGL.so.1:      loaded from: /usr/lib64/libGL.so.1
info:  libGL.so.1:      symlink to:  /usr/lib64/opengl/nvidia/lib/libGL.so.325.15
info:  X display:       :0.0
info:  X Ext. "GLX":    present
info:  X Ext. "NV-GLX": present
info:  GLX server:      NVIDIA Corporation
info:  GLX client:      NVIDIA Corporation
info:  GL vendor:       NVIDIA Corporation
info:  GL renderer:     GeForce GTX 460/PCIe/SSE2
info:  GL version:      4.3.0 NVIDIA 325.15
```

**Hybrid graphics with primus**

(showing 64-bit tests only)

```
Checking native (usually Mesa/i965) GL
Running 64-bit tests
info:  libGL.so.1:      loaded from: /usr/lib64/libGL.so.1
info:  libGL.so.1:      symlink to:  /usr/lib64/opengl/xorg-x11/lib/libGL.so.1.2.0
info:  X display:       :0.0
info:  X Ext. "GLX":    present
info:  X Ext. "NV-GLX": not present; OK for non-nVidia drivers
info:  GLX server:      SGI
info:  GLX client:      Mesa Project and SGI
info:  GL vendor:       Intel Open Source Technology Center
info:  GL renderer:     Mesa DRI Intel(R) Ivybridge Mobile 
info:  GL version:      3.0 Mesa 9.1.3
Checking secondary (usually NVIDIA) GL
Running 64-bit tests
info:  libGL.so.1:      loaded from: /usr/lib64/opengl/nvidia/lib/libGL.so.1
info:  libGL.so.1:      symlink to:  /usr/lib64/opengl/nvidia/lib/libGL.so.325.15
info:  X display:       :8
info:  X Ext. "GLX":    present
info:  X Ext. "NV-GLX": present
info:  GLX server:      NVIDIA Corporation
info:  GLX client:      NVIDIA Corporation
info:  GL vendor:       NVIDIA Corporation
info:  GL renderer:     GeForce GT 650M/PCIe/SSE2
info:  GL version:      4.3.0 NVIDIA 325.15
Testing offloading with primus
Running 64-bit tests
info:  libGL.so.1:      loaded from: /usr/lib/primus/libGL.so.1
info:  libGL.so.1:      symlink to:  /usr/lib64/primus/libGL.so.1
info:  X display:       :0.0
info:  X Ext. "GLX":    present
info:  X Ext. "NV-GLX": not present; OK for non-nVidia drivers
info:  GLX server:      NVIDIA Corporation
info:  GLX client:      primus
info:  GL vendor:       NVIDIA Corporation
info:  GL renderer:     GeForce GT 650M/PCIe/SSE2
info:  GL version:      4.3.0 NVIDIA 325.15
```
