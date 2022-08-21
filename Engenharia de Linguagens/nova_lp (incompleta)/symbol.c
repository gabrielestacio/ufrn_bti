#include <stdio.h>
#include <string.h>
#include "symbol.h"

#define SIZE 109 /*Primo mais próximo de 100*/

struct symbol{
	string name;
	symbol next;
};

static symbol createSymbol(string name, symbol next){
	symbol s = malloc(sizeof(*s));
	s->name = name; s->next = next;

	return s;
}

static symbol hashtable[SIZE];

static unsigned int hash(char *key){
	unsigned int code = 0;
	char *s;

	for(s = key; *s; s++){
		code = code*65599 + *s;
	}

	return code;
}

struct symbol Symbol(string name){
	int index = hash(name) % SIZE;
	symbol s1 = hashtable[index], s2;
	
	for(s2 = s1; s2; s2 = s2->next){
		if(0 == strcmp(s2->name, name)){
			return s2;
		}
	}
	
	s2 = createSymbol(name, s1);
	hashtable[index] = s2;
	
	return s2;
}

string name(symbol s){
	return s->name;
}



struct symtable empty(void){
	return tEmpty;
}

void enter(symtable t, symbol s, void *value){
	tEnter(t, s, value);
}

void * lookup(symtable t, symbol s){
	return tLook(t, s);
}

static struct symbol mark_symbol = {"<mark>", 0};

void beginScope(symtable t){
	enter(t, &mark_symbol, NULL);
}

void endScope(symtable t){
	symbol s;
	do{
		s = tPop(t);
	} while(s != &mark_symbol);
}