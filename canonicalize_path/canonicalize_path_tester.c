#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>

#define PATH_SEPARATOR '/'
#define PATH_MAX 4000

// int canonicalize_path(const char *src, const char *dest, const char *wd, int wd_len) {
//     const char *start, *end;
//     const char *limit = dest + PATH_MAX;
//     char *cur;

//     if (src[0] != PATH_SEPARATOR)
//     {
//         memcpy(dest, wd, wd_len);
//         cur = dest + wd_len;
//     }
//     else
//     {
//         dest[0] = PATH_SEPARATOR;
//         cur = dest + 1;
//     }

//     for (start = src; *start; start = end)
//     {
//         while (*start == PATH_SEPARATOR)
//             start++;

//         for (end = start; *end && *end != PATH_SEPARATOR; end++);

//         if (end - start == 0)
//             break;

//         if (end - start == 1 && start[0] == '.')
//             continue;

//         if (end - start == 2 && start[0] == '.' && start[1] == '.')
//         {
//             /* Ignore if at root already.  */
//             if (cur > dest + 1)
//                 while ((--cur)[-1] != PATH_SEPARATOR);

//         }
//         else
//         {
//             if (cur[-1] != PATH_SEPARATOR)
//                 *cur++ = PATH_SEPARATOR;

//             if (cur + (end - start) >= limit)
//                 return 0;

//             cur = memcpy(cur, start, end - start);
//             *cur = '\0';
//         }
//     }

//     return cur - dest;
// }

int main(void) {

    return 0;
}
