#include <string.h>
#include "canonicalize_path.h"

int canonicalize_path(const char *src, char *dest, const char *wd, int wd_len)
{
	const char *start, *end;
	const char *limit = dest + PATH_MAX;
	char *cur;

	if (src[0] != PATH_SEPARATOR)
	{
		memcpy(dest, wd, wd_len);
		cur = dest + wd_len;
	}
	else
	{
		dest[0] = PATH_SEPARATOR;
		cur = dest + 1;
	}

	for (start = src; *start; start = end)
	{
		while (*start == PATH_SEPARATOR)
			start++;

		for (end = start; *end && *end != PATH_SEPARATOR; end++);

		if (end - start == 0)
			break;

		if (end - start == 1 && start[0] == '.')
			continue;

		if (end - start == 2 && start[0] == '.' && start[1] == '.')
		{
			/* Ignore if at root already.  */
			if (cur > dest + 1)
				while ((--cur)[-1] != PATH_SEPARATOR);

		}
		else
		{
			if (cur[-1] != PATH_SEPARATOR)
				*cur++ = PATH_SEPARATOR;

			if (cur + (end - start) >= limit)
			{
				*cur = 0;
				return 0;
			}

			memcpy(cur, start, end - start);
			cur += end - start;
			*cur = 0;
		}
	}

	if (cur > dest + 1 && cur[-1] == PATH_SEPARATOR)
		--cur;

	*cur = 0;
	return cur - dest;
}