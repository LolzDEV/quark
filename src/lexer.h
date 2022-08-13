#ifndef LEXER_H_
#define LEXER_H_

#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum {
TOK_PLUS,
TOK_MINUS,
TOK_STAR,
TOK_SLASH,
TOK_NUMBER,
TOK_HEAD,
} token_type;

typedef struct file_position {
    uint32_t line;
    uint32_t column;
} file_position_t;

typedef struct token {
    token_type ty;
    char *lexeme;
    file_position_t at;
    struct token *next;
} token_t;

token_t *parse(char *source);

#endif // LEXER_H_
