/* SPDX-License-Identifier:  MIT
 * Copyright 2020 Daniel Eklöf
 * Copyright 2024 Jorengarenar
 */

#ifndef STRIDE_H_
#define STRIDE_H_

#include <pixman.h>

static inline int stride_for_format_and_width(pixman_format_code_t format, int width)
{
    return (((PIXMAN_FORMAT_BPP(format) * width + 7) / 8 + 4 - 1) & -4);
}

#endif // STRIDE_H_
