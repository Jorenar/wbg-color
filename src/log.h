/* SPDX-License-Identifier:  MIT
 * Copyright 2024 Jorengarenar
 */

#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>
#include <string.h>

#include <ansi_esc_seq.h>

#define LOG_FMT_COLOR(color) \
    "[" color "%s" ANSI_RESET "] " ANSI_FG_GRAY "%s:%d: " ANSI_RESET
#define LOG_FMT_PLAIN \
    "[%s] %s:%d: "

#define LOG_MSG(color, class, fmt, ...) \
    do { \
        fprintf(stderr, \
                (isatty(STDERR_FILENO) ? LOG_FMT_COLOR(color) \
                                       : LOG_FMT_PLAIN), \
                class, __FILE__, __LINE__); \
        fprintf(stderr, fmt, ## __VA_ARGS__); \
        fprintf(stderr, "\n"); \
    } while(0)

#define LOG_ERR(fmt, ...)   LOG_MSG(ANSI_FG_RED,          "err",     fmt __VA_OPT__(,) __VA_ARGS__)
#define LOG_WARN(fmt, ...)  LOG_MSG(ANSI_FG_YELLOW,       "warning", fmt __VA_OPT__(,) __VA_ARGS__)
#define LOG_INFO(fmt, ...)  LOG_MSG(ANSI_FG_BRIGHT_WHITE, "info",    fmt __VA_OPT__(,) __VA_ARGS__)

#define LOG_ERRNO(fmt, ...) \
    LOG_ERR(fmt __VA_OPT__(,) __VA_ARGS__); \
    LOG_ERR("  errno: %s", strerror(errno))

#if defined(LOG_ENABLE_DBG) && LOG_ENABLE_DBG
#  define LOG_DBG(fmt, ...) LOG_MSG(ANSI_FG_CYAN, "debug", fmt __VA_OPT__(,) __VA_ARGS__)
#else
#  define LOG_DBG(...)
#endif

#endif // LOG_H_
