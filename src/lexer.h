#ifndef LEXER_H_
#define LEXER_H_

#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum {
// Arithmetic operators
TOK_PLUS, // +
TOK_MINUS, // -
TOK_STAR, // *
TOK_SLASH, // /
TOK_PLUS_EQUAL, // +=
TOK_MINUS_EQUAL, // -=
TOK_STAR_EQUAL, // *=
TOK_SLASH_EQUAL, // /=

// Logical operators
TOK_EQUAL_EQUAL, // ==
TOK_GREATER_THAN, // >
TOK_LESS_THAN, // <
TOK_GREATER_EQUAL, // >=
TOK_LESS_EQUAL, // <=
TOK_EXCLAMATION, // !
TOK_NOT_EQUAL, // !=
TOK_AND_AND, // &&
TOK_PIPE_PIPE, // ||

// Bitwise operators
TOK_AND, // &
TOK_PIPE, // |
TOK_TILDE, // ~
TOK_AND_EQUAL, // &=
TOK_PIPE_EQUAL, // |=
TOK_TILDE_EQUAL, // ~=
TOK_SHIFT_LEFT, // <<
TOK_SHIFT_RIGHT, // >>
TOK_RIGHT_ARROW, // ->

// Literals
TOK_NUMBER_LITERAL,
TOK_STRING_LITERAL,
TOK_IDENTIFIER,
TOK_BOOL_LITERAL, // true/false

// Symbols
TOK_EQUAL, // =
TOK_COLON, // :
TOK_SEMI_COLON, // ;
TOK_RIGHT_PAREN, // )
TOK_LEFT_PAREN, // (
TOK_RIGHT_CURLY, // }
TOK_LEFT_CURLY, // {
TOK_QUESTION_MARK, // ?

// Keywords
TOK_LET, // let
TOK_IF, // if
TOK_FOR, // for
TOK_WHILE, // while
TOK_FN, // fn
TOK_ASM, // asm

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
