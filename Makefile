all:
	$(MAKE) -C compressed_suffix_tree
	$(MAKE) -C suffix_matcher
	$(MAKE) -C suffix_tree

clean:
	$(MAKE) clean -C compressed_suffix_tree
	$(MAKE) clean -C suffix_matcher
	$(MAKE) clean -C suffix_tree