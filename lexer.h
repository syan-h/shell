#ifndef LEXER_H
#define LEXER_H



typedef struct token_arr_type{
    char name[100];
    int token_id;
}token_arr_type;

enum Token{
    token_PIPE = -1,
    token_GREAT = -2,
    token_LESS = -3,
    token_AMPERSAND = -4,
    token_WORD = -5,
    token_GREATGREAT = -6,
    token_SYMBOL = -7

};



extern token_arr_type token_array[100];
extern int COUNT;

void lexer(char *);




#endif
