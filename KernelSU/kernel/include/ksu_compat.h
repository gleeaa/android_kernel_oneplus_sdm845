/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _KSU_COMPAT_H
#define _KSU_COMPAT_H

#include <linux/version.h>

#ifndef untagged_addr
#define untagged_addr(addr) ((unsigned long)(addr))
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0)
#include <linux/uaccess.h>

static inline long strncpy_from_user_nofault(char *dst, const void __user *src,
					     long count)
{
	return strncpy_from_user(dst, src, count);
}
#endif

#endif /* _KSU_COMPAT_H */
