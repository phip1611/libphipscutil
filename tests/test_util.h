#pragma once

#include <stdio.h>
#include <string.h>

#define ANSI_RED "\x1b[31m"
#define ANSI_CLEAR "\x1b[0m"


#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define FMT_PRFX "TEST FAILED [%15s:%03d] %15s(): "
#define fail_test(msg) \
    printf(ANSI_RED FMT_PRFX ANSI_CLEAR"%s\n", __FILENAME__, __LINE__, __func__, msg); \
    exit(-1);
