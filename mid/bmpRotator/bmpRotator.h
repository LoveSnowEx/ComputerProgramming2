#pragma once

#include "basic.h"
#include "bmp.h"
#include "coord.h"
#define abs(x) ((x < 0) ? -x : x)

typedef struct _sColor {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} __attribute__((__packed__)) sColor;

const sColor white = {
    .blue = 255,
    .green = 255,
    .red = 255,
};
