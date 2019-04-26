Copy of [glibc](https://github.com/lattera/glibc/blob/master/stdlib/canonicalize.c) that differs on:
- Does not follow symlinks
- Does not do mallocs
- Uses a provided workspace instead of the current one.