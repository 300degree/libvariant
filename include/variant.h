#ifndef _VARIANT_H
#define _VARIANT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern void variant_set_int(int);
extern void variant_set_string(const char *);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _VARIANT_H */
