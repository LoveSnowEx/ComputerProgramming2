#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

typedef int32_t i32;
typedef int64_t i64;
typedef uint64_t u64;
typedef uint32_t u32;

size_t fgets_n(char *str, int size, FILE *stream);
