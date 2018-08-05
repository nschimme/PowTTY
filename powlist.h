/* public definitions from list.c */

#ifndef _LIST_H_
#define _LIST_H_

int cmp_vtime		 (time_t *t1, time_t *t2);
void add_vtime		 (time_t *t1, time_t *t2);
long diff_vtime		 (time_t *t1, time_t *t2);

int rev_sort		 (defnode *node1, defnode *node2);
int ascii_sort		 (defnode *node1, defnode *node2);
int rev_ascii_sort	 (defnode *node1, defnode *node2);
int time_sort		 (defnode *node1, defnode *node2);
int rev_time_sort	 (defnode *node1, defnode *node2);

int hash		 (char *name);

void add_node		 (defnode *newnode, defnode **base, function_sort sort);
void reverse_sortedlist  (sortednode **base);

void add_aliasnode	 (char *name, char *subst);
void add_actionnode	 (char *pattern, char *command, char *label, int active, int type, void *qregexp);
void add_promptnode	 (char *pattern, char *command, char *label, int active, int type, void *qregexp);
void add_marknode	 (char *pattern, int attrcode, char mbeg, char wild);
void add_keynode (char *name, char *sequence, int seqlen, function_str funct, char *call_data);
delaynode *add_delaynode  (char *name, char *command, time_t *when, int is_dead);
varnode *add_varnode	 (char *name, int type);

aliasnode  **lookup_alias	 (char *name);
actionnode **lookup_action	 (char *label);
actionnode **lookup_prompt	 (char *label);
actionnode **lookup_action_pattern  (char *pattern);
marknode   **lookup_marker	 (char *pattern, char mbeg);
keynode    **lookup_key		 (char *name);
delaynode  **lookup_delay	 (char *name, int is_dead);
varnode    **lookup_varnode	 (char *name, int type);

void delete_aliasnode	 (aliasnode **base);
void delete_actionnode	 (actionnode **base);
void delete_promptnode	 (promptnode **base);
void delete_marknode	 (marknode **base);
void delete_keynode	 (keynode **base);
void delete_delaynode	 (delaynode **base);
void delete_varnode	 (varnode **base, int type);

#endif /* _LIST_H_ */

