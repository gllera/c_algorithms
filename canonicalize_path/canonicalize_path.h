#ifndef _CANONICALIZE_PATH_H_
#define _CANONICALIZE_PATH_H_

#ifndef PATH_MAX
#include <linux/limits.h>
#endif /* PATH_MAX */

#define PATH_SEPARATOR '/'

int canonicalize_path(const char *src, char *dest, const char *wd, int wd_len);

#endif /* _CANONICALIZE_PATH_H_ */