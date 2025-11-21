#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

// Level log: DEBUG
#define LOG_DEBUG(fmt, ...) \
    fprintf(stderr, "[DEBUG]: %s:%d:%s(): " fmt "\n", \
    __FILE__, __LINE__, __func__, ##__VA_ARGS__)

// Level log: INFO
#define LOG_INFO(fmt, ...) \
        fprintf(stdout, "[INFO]: %s:%d:%s(): " fmt "\n", \
        __FILE__, __LINE__, __func__, ##__VA_ARGS__)

#endif