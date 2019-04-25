#include "queue.h"

STAILQ_HEAD(suffix_tree_head, suffix_tree_entry);

struct suffix_tree_entry {
	unsigned char match;
	struct suffix_tree_entry *childs[256];
	STAILQ_ENTRY(suffix_tree_entry) _;
};

typedef struct suffix_tree_head suffix_tree;

int suffix_tree_init(suffix_tree *head);
int suffix_tree_clear(suffix_tree *head);
void suffix_tree_add(suffix_tree *head, const unsigned char *txt, int len);
int suffix_tree_find(const suffix_tree *head, const unsigned char *txt, int len);
