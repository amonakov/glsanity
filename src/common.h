#pragma once

#define die(fmt, ...) ({printf("fatal: %s:\t"fmt"\n", msg1, ## __VA_ARGS__); exit(1);})
#define inform(fmt, ...) printf("info:  %s:\t"fmt"\n", msg1, ## __VA_ARGS__)
