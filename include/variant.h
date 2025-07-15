/*
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * For more information, please refer to <http://unlicense.org/>
 */

#ifndef _VARIANT_H
#define _VARIANT_H

#if defined(__cplusplus) && __cplusplus < 201703L
#error "This code requires at least C++17"
#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define VEXTERN extern __attribute__((visibility("default")))

#include <stdint.h>

typedef struct variant_t variant_t;
typedef uint32_t variant_int;
typedef const char *variant_string;

VEXTERN variant_t *variant_create(void);
VEXTERN void variant_destroy(variant_t *object);
VEXTERN void variant_store_int(variant_t *object, variant_int value);
VEXTERN void variant_store_string(variant_t *object, variant_string value);
VEXTERN variant_int variant_load_int(variant_t *object);
VEXTERN variant_string variant_load_string(variant_t *object);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _VARIANT_H */
