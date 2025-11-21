#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

#ifdef ENABLE_DEBUG
    #define LOG_DEBUG(fmt, ...) do { \
        fprintf(stderr, "[DEBUG] %s:%d:%s(): ", __FILE__, __LINE__, __func__); \
        fprintf(stderr, fmt, ##__VA_ARGS__); \
        fprintf(stderr, "\n"); \
    } while(0)
#else
    #define LOG_DEBUG(fmt, ...) do {} while(0)
#endif

#define LOG_INFO(fmt, ...) do { \
    fprintf(stdout, "[INFO] %s:%d:%s(): ", __FILE__, __LINE__, __func__); \
    fprintf(stdout, fmt, ##__VA_ARGS__); \
    fprintf(stdout, "\n"); \
} while(0)

#define LOG_ERROR(fmt, ...) do { \
    fprintf(stderr, "[ERROR] %s:%d:%s(): ", __FILE__, __LINE__, __func__); \
    fprintf(stderr, fmt, ##__VA_ARGS__); \
    fprintf(stderr, "\n"); \
} while(0)

#endif
