Basic usage:

```
struct suffix_matcher matcher;

suffix_matcher_init(&matcher);
suffix_matcher_add(&matcher, "GABOX", 5);

if (suffix_matcher_find(&matcher, "GABOX OK", 8))
     printf("Found\n");       // Expected to be printed
     
suffix_matcher_free(&matcher);
```
