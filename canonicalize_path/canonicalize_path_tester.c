#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "canonicalize_path.h"

#define MAX_OUTPUT 100

static void test(const char *src, const char *wd)
{
	char dest[PATH_MAX];
	char real[PATH_MAX];

	int fail1 = canonicalize_path(src, dest, wd, strlen(wd)) == 0;
	int fail2 = realpath(src, real) == NULL;

	if (fail1 != fail2)
	{
		printf("[FAIL] '%s' -> '%d'\nexpected: '%d'\n", src, fail1, fail2);
	}
	else if (fail1)
	{
		printf("[OK] '%.*s' -> [NOT POSIBLE]\n", MAX_OUTPUT, src);
	}
	else if (strcmp(dest, real))
	{
		printf("[FAIL] '%s' -> '%s'\nexpected: '%s'\n", src, dest, real);
	}
	else
	{
		printf("[OK] '%.*s' -> '%.*s'\n", MAX_OUTPUT, src, MAX_OUTPUT, dest);
	}
}

// static void bench(const char **tests, int tests_len, const char *wd)
// {
//     char dest[PATH_MAX];
//     clock_t start;
//     double time1, time2;
//     int wd_len = strlen(wd);

// 	for (int i = 0; i < tests_len; i++) {
//         start = clock();

//         for (int j = 0; j < TESTS_TIMES; j++)
//             canonicalize_path(tests[i], dest, wd, wd_len);

//         time1 = ((double) (clock() - start)) / CLOCKS_PER_SEC;

//         start = clock();

//         for (int j = 0; j < TESTS_TIMES; j++)
//             realpath(tests[i], dest);

//         time2 = ((double) (clock() - start)) / CLOCKS_PER_SEC;
//         printf("%f vs %f diff %f on %.*s\n", time1, time2, time2 - time1, MAX_OUTPUT, tests[i]);
// 	}
// }

int main(void)
{
	char wd[PATH_MAX];
	char root[PATH_MAX];
	char big_path[PATH_MAX];

	memset(root, '/', sizeof(root));
	memset(big_path, 'a', sizeof(big_path));
	root[PATH_MAX-1] = big_path[PATH_MAX-1] = 0;

	if (!getcwd(wd, PATH_MAX))
	{
		fprintf(stderr, "getcwd()");
		return 1;
	}

	const char *tests[] = {
		".", "..", "../", "../..", "../../",
		"../../../../../../../../../../../../",
		"/bin", "/bin/./", "/./bin/./", "/./bin/../",
		"////////////bin", "/bin//////////",
		"/usr/bin", "/usr/bin/../", "/usr/lib", "/usr/bin",
		"/usr/lib/./././././././",
		wd, root, big_path
	};

	printf("Tests...\n");
	for (unsigned int i = 0; i < sizeof(tests)/sizeof(char *); i++)
		test(tests[i], wd);

	// printf("\nBenchmarks...\n");
	// bench(tests, sizeof(tests)/sizeof(char *), wd);

	return 0;
}
