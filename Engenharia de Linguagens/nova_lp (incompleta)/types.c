#include <stdio.h>
#include "symbol.h"
#include "types.h"

struct type{
	enum{null, int, real, string, char, boolean, void, array, name} kind;
	union{type array; struct{symbol s; type t;} name;} u;
	};

struct field{
	symbol name;
	type t;
};

static struct{
	type null = {null};
};

type null(void){
		return &null;
};

static struct{
	type int = {int};
};

type int(void){
		return &int;
};

static struct{
	type real = {real};
};

type real(void){
		return &real;
};

static struct{
	type string = {string};

};

type string(void){
		return &string;
};

static struct{
	type char = {char};

};

type char(void){
		return &char;
};

static struct{
	type boolean = {boolean};

};

type boolean(void){
		return &boolean;
};

static struct{
	type void = {void};

};

type void(void){
		return &void;
};

type array(type t){
	type p = malloc(sizeof(*p));
	p->kind = array;
	p->u.array = t;

	return p;
}

type name(symbol s, type t){
	type p = malloc(sizeof(*p));
	p->kind = name;
	p->u.name.s = s;
	p->u.name.t = t;

	return p;
}

type field(symbol name, type t){
	field p = malloc(sizeof(*p));
	p->name = name;
	p->t = t;

	return p;
}