typedef struct type *type;
typedef struct field *field;

type null(void);
type int(void);
type real(void);
type string(void);
type char(void);
type boolean(void);
type void(void);

type array(type);
type name(symbol, type);

field field(symbol, type);