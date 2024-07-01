/* SPDX-License-Identifier:  MIT
 * Copyright 2024 Jorengarenar
 */

#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>
#include <string.h>

#include <ansi_esc_seq.h>

#define LOG_MSG(color, class, fmt, ...) \
    do { \
        fprintf(stderr, \
                ( \
                    isatty(STDERR_FILENO) \
                    ? ("[" color "%s" ANSI_RESET "] " ANSI_RESET) \
                    : ("[%s] ") \
                ), \
                class); \
        fprintf(stderr, fmt __VA_OPT__(,) __VA_ARGS__); \
        fprintf(stderr, "\n"); \
    } while(0)

#define LOG_ERR(fmt, ...)   LOG_MSG(ANSI_FG_RED,    "err",     fmt __VA_OPT__(,) __VA_ARGS__)
#define LOG_WARN(fmt, ...)  LOG_MSG(ANSI_FG_YELLOW, "warning", fmt __VA_OPT__(,) __VA_ARGS__)
#define LOG_INFO(fmt, ...)  LOG_MSG(ANSI_FG_GRAY,   "info",    fmt __VA_OPT__(,) __VA_ARGS__)

#define LOG_ERRNO(fmt, ...) \
    LOG_ERR(fmt __VA_OPT__(,) __VA_ARGS__); \
    LOG_ERR("  errno: %s", strerror(errno))

#ifndef NDEBUG
#  define LOG_DEBUG(fmt, ...) \
    LOG_MSG(ANSI_FG_CYAN, "debug", "# %s:%d @ %s", __FILE__, __LINE__, __func__); \
    LOG_MSG(ANSI_FG_CYAN, "debug", fmt __VA_OPT__(,) __VA_ARGS__)
#else
#  define LOG_DEBUG(...)
#endif

#endif // LOG_H_
