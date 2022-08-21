#include <stdio.h>
#include "hashtable.h"

#define SIZE 109

typedef struct binder *binder;

struct binder{
	void *key;
	void *value;
	binder next;
	void *p_top;
};

struct table{
	binder table[SIZE];
	void *top;
};

static binder Binder(void *key, void *value, binder next, void *p_top){
	binder temp = malloc(sizeof(*temp));

	temp->key = key;
	temp->value = value;
	temp->next = next;
	temp->p_top = p_top;

	return temp;
}

static unsigned int hash(void *key){
	unsigned int code = 0;
	void *k;

	for(k = key; *k; k++){
		code = code*65999 + s*;
	}

	return code;
}

table tEmpty(void){
	table t = malloc(sizeof(*t));
	
	t->top = NULL;

	for(int i = 0; i < SIZE; i++){
		t->table[i] = NULL;
	}

	return t;
}

void tEnter(table t, void *key, void *value){
	int index = hash(key) % SIZE;

	assert(t && key);
	t->table[index] = Binder(key, value, t->table[index], t->top);
	t->top = key;
}

void * tLookup(table t, void *key){
	int index = hash(key) % SIZE;
	assert(t && key);
	binder temp;

	for(temp = t->table[index]; temp; temp = temp->next){
		if(temp->key == key){
			return temp->value;
		}
	}
	return NULL;	
}

void * tPop(table t){
	void *key;
	binder temp;

	assert(t);
	key = t->top;
	assert(key);

	int index = hash(key) % SIZE;

	temp = t->table[index];
	assert(temp);
	t->table[index] = temp->next;
	t->top = temp->p_top;

	return temp->key;
}