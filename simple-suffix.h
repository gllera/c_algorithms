struct suffix_matcher {
	int n, max;
	char **suffixs;
};

int suffix_matcher_init(struct suffix_matcher *head);
void suffix_matcher_free(struct suffix_matcher *head);
void suffix_matcher_clear(struct suffix_matcher *head);
int suffix_matcher_add(struct suffix_matcher *head, const char *txt, int len);
int suffix_matcher_find(const struct suffix_matcher *head, const char *txt, int len);