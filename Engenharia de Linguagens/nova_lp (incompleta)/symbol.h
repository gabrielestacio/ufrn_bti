#include <string.h>
#include "table.h"

typedef struct symbol *symbol;
struct symbol symbol(string);
string name(symbol);

typedef struct table *symtable;
struct symtable empty(void);
void enter(symtable t, symbol s, void *value);
void * lookup(symtable t, symbol s);
void beginScope(symtable t);
void endScope(symtable t); 