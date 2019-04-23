#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "suffix-tree.h"

suffix_tree head;

static unsigned char *rand_string(unsigned char *str, int size)
{
    const unsigned char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_().";

    for (int n = 0; n < size; n++) {
        int key = rand() % (int) (sizeof charset - 1);
        str[n] = charset[key];
    }

    str[size] = '\0';

    return str;
}

unsigned char* rand_string_alloc(int size)
{
     unsigned char *s = malloc(size + 1);
     rand_string(s, size);
     return s;
}

void check_test(unsigned char *s) {
    int length = strlen((char *)s);

    if (!suffix_tree_find(&head, s, length)) {
        printf("not found\n");
    }
}

int main() {
    suffix_tree_init(&head);

    unsigned char *tests[100];
    int i, length = 60, total = 100;

    printf("Adding\n");

    for (i = 0; i < total; i++) {
        tests[i] = rand_string_alloc(length);
        suffix_tree_add(&head, tests[i], length);
    }

    printf("Checking\n");

    for (i = 0; i < 100000; i++) {
        check_test(tests[i%100]);
    }

    // rax *t = raxNew();
    // raxInsert(t,(unsigned char*)"FOO",3,(void*)(long)1,NULL);
    // void *old, *val;
    // raxTryInsert(t,(unsigned char*)"FOO",3,(void*)(long)2,&old);
    // if (old != (void*)(long)1) {
    //     printf("Old value not returned correctly by raxTryInsert(): %p",
    //         old);
    //     return 1;
    // }

    // val = raxFind(t,(unsigned char*)"FOO",3);
    // if (val != (void*)(long)1) {
    //     printf("FOO value mismatch: is %p intead of 1", val);
    //     return 1;
    // }

    // raxInsert(t,(unsigned char*)"FOO",3,(void*)(long)2,NULL);
    // val = raxFind(t,(unsigned char*)"FOO",3);
    // if (val != (void*)(long)2) {
    //     printf("FOO value mismatch: is %p intead of 2", val);
    //     return 1;
    // }

    // raxFree(t);
    // return 0;

    // struct bin_entry_head head;
    // STAILQ_INIT(&head);

    // struct entry *n1 = malloc(sizeof(struct entry));
    // struct entry *n2  = malloc(sizeof(struct entry));
    // n1->num = 4;
    // n2->num = 5;

    // STAILQ_INSERT_TAIL(&head, n1, entries);
    // STAILQ_INSERT_TAIL(&head, n2, entries);

    // STAILQ_FOREACH(np, &head, entries) {
    //     printf("%d", np->num);
    // }

    // while (!STAILQ_EMPTY(&head))
    //     STAILQ_REMOVE_HEAD(&head, entries);

    return 0;

}
