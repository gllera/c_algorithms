#include "suffix-tree.h"
#include <stdlib.h>

typedef struct suffix_tree_entry entry_type;

entry_type *new_tail(suffix_tree *head);

int suffix_tree_init(suffix_tree *head) {
	STAILQ_INIT(head);
	new_tail(head);
	return 0;
}

int suffix_tree_clear(suffix_tree *head) {
	while (!STAILQ_EMPTY(head)) {
		entry_type *act = STAILQ_FIRST(head);
    	STAILQ_REMOVE_HEAD(head, _);
		free(act);
	}

	return 0;
}

void suffix_tree_add(suffix_tree *head, const unsigned char *txt, int len) {
	int pos = 0;
	entry_type *act = STAILQ_FIRST(head);

	while(pos != len) {
		unsigned char c = txt[pos];
		if (!act->childs[c])
			act->childs[c] = new_tail(head);
		act = act->childs[c];
		pos++;
	}

	act->match = 1;
}

int suffix_tree_find(const suffix_tree *head, const unsigned char *txt, int len) {
	int pos = 0;
	entry_type *act = STAILQ_FIRST(head);

	while(pos != len) {
		unsigned char c = txt[pos];
		if (!act->childs[c])
			return 0;
		act = act->childs[c];
		if (act->match)
			return 1;
		pos++;
	}

	return 0;
}

entry_type *new_tail(suffix_tree *head) {
	entry_type *e = calloc(1, sizeof(entry_type));

	STAILQ_INSERT_TAIL(head, e, _);

	return e;
}