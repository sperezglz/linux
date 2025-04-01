/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_KERNEL_SPRINTF_H_
#define _LINUX_KERNEL_SPRINTF_H_

#include <linux/compiler_attributes.h>
#include <linux/types.h>

int num_to_str(char *buf, int size, unsigned long long num, unsigned int width);

__printf(2, 3) int sprintf(char *buf, const char * fmt, ...);
__printf(2, 0) int vsprintf(char *buf, const char *, va_list);
__printf(3, 4) int snprintf(char *buf, size_t size, const char *fmt, ...);
__printf(3, 0) int vsnprintf(char *buf, size_t size, const char *fmt, va_list args);
__printf(3, 4) int scnprintf(char *buf, size_t size, const char *fmt, ...);
__printf(3, 0) int vscnprintf(char *buf, size_t size, const char *fmt, va_list args);
__printf(2, 3) __malloc char *kasprintf(gfp_t gfp, const char *fmt, ...);
__printf(2, 0) __malloc char *kvasprintf(gfp_t gfp, const char *fmt, va_list args);
__printf(2, 0) const char *kvasprintf_const(gfp_t gfp, const char *fmt, va_list args);

__scanf(2, 3) int sscanf(const char *, const char *, ...);
__scanf(2, 0) int vsscanf(const char *, const char *, va_list);

extern bool hash_pointers;
int hash_pointers_disable(void);
/*
 * Hash pointers policy selected in cmd line
 *
 * `auto`   - Hash pointers will be disabled if slub_debug_enabled is true, otherwhise enable hash pointers
 * `always` - Hash pointers enabled unconditionally
 * `never`  - Hash pointers disabled unconditionally
 */
enum pointer_hashing_policy {
	AUTO = 0,
	ALWAYS,
	NEVER
};
extern enum pointer_hashing_policy hash_pointers_mode;
#endif	/* _LINUX_KERNEL_SPRINTF_H */
