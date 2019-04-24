#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "suffix-tree.h"

static unsigned char ***create_tests();

#define TESTS_CASES_COUNT 2
#define STRINGS_COUNT_PER_TEST 1000
#define STRING_LENGTH_PER_TEST 200

int main() {
    int i, j;
    int total = 100000;
    int length = STRING_LENGTH_PER_TEST / 2;

    clock_t start;
    double cpu_time_used;
    unsigned char ***tests = create_tests();

    suffix_tree head;
    suffix_tree_init(&head);


    ///////////////////////////////////////////////////////////
    printf("Adding %d random elements of length %d -> ", STRINGS_COUNT_PER_TEST, length);

    start = clock();

    for (i = 0; i < STRINGS_COUNT_PER_TEST; i++)
        suffix_tree_add(&head, tests[0][i], length);

    cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("done in %f\n", cpu_time_used);


    ///////////////////////////////////////////////////////////
    printf("Checking %d times using strncmp -> ", total);

    start = clock();

    for (i = 0; i < total; i++)
        for (j = 0; j < total; j++)
        if (strncmp((char *)tests[0][i%STRINGS_COUNT_PER_TEST], (char *)tests[0][i%STRINGS_COUNT_PER_TEST], length))
            printf("TEST FAILED\n");

    cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("done in %f\n", cpu_time_used);


    ///////////////////////////////////////////////////////////
    printf("Checking %d times using preffix tree -> ", total);

    start = clock();

    for (i = 0; i < total; i++)
        if (!suffix_tree_find(&head, tests[0][i%STRINGS_COUNT_PER_TEST], length))
            printf("TEST FAILED\n");

    cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("done in %f\n", cpu_time_used);


    ///////////////////////////////////////////////////////////
    printf("Checking %d times bigger preffix using preffix tree -> ", total);

    start = clock();

    for (i = 0; i < total; i++)
        if (!suffix_tree_find(&head, tests[0][i%STRINGS_COUNT_PER_TEST], length * 2))
            printf("TEST FAILED\n");

    cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("done in %f\n", cpu_time_used);


    ///////////////////////////////////////////////////////////
    printf("Checking %d times smaller preffix using preffix tree -> ", total);

    start = clock();

    for (i = 0; i < total; i++)
        if (suffix_tree_find(&head, tests[0][i%STRINGS_COUNT_PER_TEST], length / 2))
            printf("TEST FAILED\n");

    cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("done in %f\n", cpu_time_used);


    ///////////////////////////////////////////////////////////
    printf("Checking %d times smaller different preffix using preffix tree -> ", total);

    start = clock();

    for (i = 0; i < total; i++)
        if (suffix_tree_find(&head, tests[1][i%STRINGS_COUNT_PER_TEST], length / 2))
            printf("TEST FAILED\n");

    cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("done in %f\n", cpu_time_used);

    return 0;
}

static unsigned char *random_string(int size) {
    const unsigned char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_().";
    unsigned char *str = malloc(size + 1);

    for (int n = 0; n < size; n++) {
        int key = rand() % (int) (sizeof charset - 1);
        str[n] = charset[key];
    }

    str[size] = '\0';
    return str;
}

static unsigned char ***create_tests()
{
    int i, j, match;
    unsigned char * tmp;
    unsigned char ***tests = malloc(TESTS_CASES_COUNT * sizeof(unsigned char **));

    for (i = 0; i < TESTS_CASES_COUNT; i++)
        tests[i] = malloc(STRINGS_COUNT_PER_TEST * sizeof(unsigned char *));

    for (i = 0; i < STRINGS_COUNT_PER_TEST; i++)
        tests[0][i] = random_string(STRING_LENGTH_PER_TEST);

    for (i = 0; i < STRINGS_COUNT_PER_TEST; i++) {
        do{
            match = 0;
            tmp = random_string(STRING_LENGTH_PER_TEST / 1.5);

            for (j = 0; j < STRINGS_COUNT_PER_TEST && !match; j++)
                if (!strncmp((char *)tmp, (char *)tests[0][j], STRING_LENGTH_PER_TEST / 2)) {
                    free(tmp);
                    match = 1;
                }

        } while(match);

        tests[1][i] = tmp;
    }

    return tests;
}