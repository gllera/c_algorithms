#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "suffix_matcher.h"

static char ***create_tests(void);
static char *random_string(int size);

#define TESTS_CASES_COUNT 2
#define STRINGS_COUNT_PER_TEST 10000
#define STRING_LENGTH_PER_TEST 200

int main(void) {
    int i, j;
    int total = STRINGS_COUNT_PER_TEST;
    int length = STRING_LENGTH_PER_TEST / 3;

    clock_t start;
    double cpu_time_used;

    struct suffix_matcher head;
    suffix_matcher_init(&head);

    printf("Generating random elements...\n");

    char ***tests = create_tests();

    ///////////////////////////////////////////////////////////
    printf("Adding %d random elements of length %d -> ", STRINGS_COUNT_PER_TEST, length);

    start = clock();

    for (i = 0; i < STRINGS_COUNT_PER_TEST; i++)
        suffix_matcher_add(&head, tests[0][i], length);

    cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("done in %f\n", cpu_time_used);


    ///////////////////////////////////////////////////////////
    printf("Checking %d times using 'strncmp' equivalent simulation for worst case -> ", total);

    start = clock();

    for (i = 0; i < total; i++)
        for (j = 0; j < total; j++)
            if (strncmp(tests[0][(i+j)%STRINGS_COUNT_PER_TEST], tests[0][(i+j)%STRINGS_COUNT_PER_TEST], length))
                printf("TEST FAILED\n");

    cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("done in %f\n", cpu_time_used);


    ///////////////////////////////////////////////////////////
    printf("Checking %d times using 'simple suffix' -> ", total);

    start = clock();

    for (i = 0; i < total; i++)
        if (!suffix_matcher_find(&head, tests[0][i%STRINGS_COUNT_PER_TEST], length))
            printf("TEST FAILED\n");

    cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("done in %f\n", cpu_time_used);


    ///////////////////////////////////////////////////////////
    printf("Checking %d times using 'simple suffix' and a bigger suffix than stored -> ", total);

    start = clock();

    for (i = 0; i < total; i++)
        if (!suffix_matcher_find(&head, tests[0][i%STRINGS_COUNT_PER_TEST], length * 2))
            printf("TEST FAILED\n");

    cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("done in %f\n", cpu_time_used);


    ///////////////////////////////////////////////////////////
    printf("Checking %d times using 'simple suffix' and a smaller suffix than stored -> ", total);

    start = clock();

    for (i = 0; i < total; i++)
        if (suffix_matcher_find(&head, tests[0][i%STRINGS_COUNT_PER_TEST], length / 2))
            printf("TEST FAILED\n");

    cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("done in %f\n", cpu_time_used);


    ///////////////////////////////////////////////////////////
    printf("Checking %d times using 'simple suffix' and a different suffixs than stored -> ", total);

    start = clock();

    for (i = 0; i < total; i++)
        if (suffix_matcher_find(&head, tests[1][i%STRINGS_COUNT_PER_TEST], length / 2))
            printf("TEST FAILED\n");

    cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("done in %f\n", cpu_time_used);


    ///////////////////////////////////////////////////////////
    for (i = 0; i < TESTS_CASES_COUNT; i++) {
        for (j = 0; j < STRINGS_COUNT_PER_TEST; j++)
            free(tests[i][j]);
        free(tests[i]);
    }
    free(tests);

    suffix_matcher_free(&head);

    return 0;
}

static char *random_string(int size) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_().";
    char *str = malloc(size + 1);

    for (int n = 0; n < size; n++) {
        int key = rand() % (int) (sizeof charset - 1);
        str[n] = charset[key];
    }

    str[size] = '\0';
    return str;
}

static char ***create_tests(void)
{
    int i;
    char ***tests = malloc(TESTS_CASES_COUNT * sizeof(char **));

    for (i = 0; i < TESTS_CASES_COUNT; i++)
        tests[i] = malloc(STRINGS_COUNT_PER_TEST * sizeof(char *));

    for (i = 0; i < STRINGS_COUNT_PER_TEST; i++) {
        tests[0][i] = random_string(STRING_LENGTH_PER_TEST);
        tests[1][i] = random_string(STRING_LENGTH_PER_TEST);
    }

    return tests;
}