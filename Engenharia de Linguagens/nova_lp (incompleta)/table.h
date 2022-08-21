typedef struct binder *binder;

typedef struct table *table;

table tEmpty(void);

void tEnter(table t, void *key, void *value);

void * tLookup(table t, void *key);

void * tPop(table t);