#include <stdlib.h>
#include <string.h>
#include "suffix-matcher.h"

#define LENGTH_OFFSET sizeof(int)

int suffix_matcher_init(struct suffix_matcher *head) {
	head->n = 0;
	head->max = 100;
	head->suffixs = malloc(head->max * sizeof(char *));
	return head->suffixs == NULL;
}

void suffix_matcher_free(struct suffix_matcher *head) {
	suffix_matcher_clear(head);
	free(head->suffixs);
}

void suffix_matcher_clear(struct suffix_matcher *head) {
	int i;
	for (i = 0; i < head->n; i++)
		free(head->suffixs[i]);
	head->n = 0;
}

int suffix_matcher_add(struct suffix_matcher *head, const char *txt, int len) {
	if (head->n + 1 >= head->max) {
		int new_max = head->max * 2;
		char ** new_suffixs = realloc(head->suffixs, new_max * sizeof(char *));

		if (!new_suffixs)
			return 1;

		head->max = new_max;
		head->suffixs = new_suffixs;
	}

	char *cp = malloc(len + 1 + LENGTH_OFFSET);

	if (!cp)
		return 1;

	*((int *)cp) = len;

	memcpy(cp + LENGTH_OFFSET, txt, len);
	cp[len + LENGTH_OFFSET] = '\0';

	head->suffixs[head->n++] = cp;
	return 0;
}

int suffix_matcher_find(const struct suffix_matcher *head, const char *txt, int len) {
	int i, n = head->n;
	char **suffixs = head->suffixs;

	for (i = 0; i < n; i++) {
		int suffix_size = *((int *)suffixs[i]);
		if (suffix_size <= len && !strncmp(suffixs[i] + LENGTH_OFFSET, txt, suffix_size))
			return 1;
	}

	return 0;
}