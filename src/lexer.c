#include "lexer.h"

token_t *parse(char *source)
{
    token_t *current_token = (token_t*)malloc(sizeof(token_t));
    token_t *head = current_token;
    current_token->ty = TOK_HEAD;
    current_token->lexeme = "head";

    uint32_t source_len = strlen(source);

    uint32_t current_line = 1, current_col = 1;

    uint32_t skip = 0;

    for (int i=0; i < source_len; i++) {
        char c = source[i];

        if (c == ' ') {
            continue;
        }

        if (skip > 0) {
            skip--;
            continue;
        }


        file_position_t at = {.line = current_line, .column = current_col};
        token_t *new_token = (token_t*)malloc(sizeof(token_t));

        switch (c) {
            case '\n':
                current_line++;
                current_col = 1;
            break;
            // Arithmetic operators
            case '+':
                if (source[i+1] == '=') {
                    new_token->ty = TOK_PLUS_EQUAL;
                    new_token->lexeme = "+=";
                    skip++;
                } else {
                    new_token->ty = TOK_PLUS;
                    new_token->lexeme = "+";
                }
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '-':
                if (source[i+1] == '=') {
                    new_token->ty = TOK_MINUS_EQUAL;
                    new_token->lexeme = "-=";
                    skip++;
                } else if (source[i+1] == '>') {
                    new_token->ty = TOK_RIGHT_ARROW;
                    new_token->lexeme = "->";
                    skip++;
                } else {
                    new_token->ty = TOK_MINUS;
                    new_token->lexeme = "-";
                }
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '*':
                if (source[i+1] == '=') {
                    new_token->ty = TOK_STAR_EQUAL;
                    new_token->lexeme = "*=";
                    skip++;
                } else {
                    new_token->ty = TOK_STAR;
                    new_token->lexeme = "*";
                }
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '/':
                if (source[i+1] == '=') {
                    new_token->ty = TOK_SLASH_EQUAL;
                    new_token->lexeme = "/=";
                    skip++;
                } else {
                    new_token->ty = TOK_SLASH;
                    new_token->lexeme = "/";
                }
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;

            // Logical operators
            case '=':
                if (source[i+1] == '=') {
                    new_token->ty = TOK_EQUAL_EQUAL;
                    new_token->lexeme = "=";
                    skip++;
                } else {
                    new_token->ty = TOK_EQUAL;
                    new_token->lexeme = "=";
                }
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '>':
                if (source[i+1] == '=') {
                    new_token->ty = TOK_GREATER_EQUAL;
                    new_token->lexeme = ">=";
                    skip++;
                } else if (source[i+1] == '>') {
                    new_token->ty = TOK_SHIFT_RIGHT;
                    new_token->lexeme = ">>";
                    skip++;
                } else {
                    new_token->ty = TOK_GREATER_THAN;
                    new_token->lexeme = ">";
                }
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '<':
                if (source[i+1] == '=') {
                    new_token->ty = TOK_LESS_EQUAL;
                    new_token->lexeme = "<=";
                    skip++;
                } else if (source[i+1] == '<') {
                    new_token->ty = TOK_SHIFT_LEFT;
                    new_token->lexeme = "<<";
                    skip++;
                } else {
                    new_token->ty = TOK_LESS_THAN;
                    new_token->lexeme = "<";
                }
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '!':
                if (source[i+1] == '=') {
                    new_token->ty = TOK_NOT_EQUAL;
                    new_token->lexeme = "!=";
                    skip++;
                } else {
                    new_token->ty = TOK_EXCLAMATION;
                    new_token->lexeme = "!";
                }
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '&':
                if (source[i+1] == '=') {
                    new_token->ty = TOK_AND_EQUAL;
                    new_token->lexeme = "&=";
                    skip++;
                } else if (source[i+1] == '&') {
                    new_token->ty = TOK_AND_AND;
                    new_token->lexeme = "&&";
                    skip++;
                } else {
                    new_token->ty = TOK_AND;
                    new_token->lexeme = "&";
                }
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '|':
                if (source[i+1] == '=') {
                    new_token->ty = TOK_PIPE_EQUAL;
                    new_token->lexeme = "|=";
                    skip++;
                } else if (source[i+1] == '|') {
                    new_token->ty = TOK_PIPE_PIPE;
                    new_token->lexeme = "||";
                    skip++;
                } else {
                    new_token->ty = TOK_PIPE;
                    new_token->lexeme = "|";
                }
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '~':
                if (source[i+1] == '=') {
                    new_token->ty = TOK_TILDE_EQUAL;
                    new_token->lexeme = "~=";
                    skip++;
                } else {
                    new_token->ty = TOK_TILDE;
                    new_token->lexeme = "~";
                }
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case ':':
                new_token->ty = TOK_COLON;
                new_token->lexeme = ":";
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case ';':
                new_token->ty = TOK_SEMI_COLON;
                new_token->lexeme = ";";
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '(':
                new_token->ty = TOK_LEFT_PAREN;
                new_token->lexeme = "(";
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case ')':
                new_token->ty = TOK_RIGHT_PAREN;
                new_token->lexeme = ")";
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '{':
                new_token->ty = TOK_LEFT_CURLY;
                new_token->lexeme = "{";
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '}':
                new_token->ty = TOK_RIGHT_CURLY;
                new_token->lexeme = "}";
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '?':
                new_token->ty = TOK_QUESTION_MARK;
                new_token->lexeme = "?";
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
        }

        if (isdigit(c)) {
            char *n = calloc(2, sizeof(char));
            n[0] = c;
            uint32_t current_char = i+1;
            char d = source[current_char];
            while (isdigit(d)) {
                strncat(n, &d, 1);
                char *nn = calloc(current_char - i + 1, sizeof(char));
                strcpy(nn, n);
                n = nn;
                current_char++;
                d = source[current_char];
            }

            n[current_char - i + 1] = '\0';
            new_token->ty = TOK_NUMBER_LITERAL;
            new_token->lexeme = n;
            new_token->at = at;
            current_token->next = new_token;
            current_token = new_token;
            current_col++;
            skip += current_char - i - 1;
            continue;
        }

        if (isalnum(c)) {
            char *id = calloc(2, sizeof(char));
            id[0] = c;
            uint32_t current_char = i+1;
            char nc = source[current_char];
            while (isalnum(nc)) {
                strncat(id, &nc, 1);
                char *nid = calloc(current_char - i + 1, sizeof(char));
                strcpy(nid, id);
                id = nid;
                current_char++;
                nc = source[current_char];
            }

            id[current_char - i + 1] = '\0';

            if (!strcmp(id, "let")) {
                new_token->ty = TOK_LET;
            } else if (!strcmp(id, "if")) {
                new_token->ty = TOK_IF;
            } else if (!strcmp(id, "for")) {
                new_token->ty = TOK_FOR;
            } else if (!strcmp(id, "while")) {
                new_token->ty = TOK_WHILE;
            } else if (!strcmp(id, "fn")) {
                new_token->ty = TOK_LET;
            } else if (!strcmp(id, "asm")) {
                new_token->ty = TOK_ASM;
            } else if (!strcmp(id, "true") || !strcmp(id, "false")) {
                new_token->ty = TOK_BOOL_LITERAL;
            } else {
                new_token->ty = TOK_IDENTIFIER;
            }

            new_token->lexeme = id;
            new_token->at = at;
            current_token->next = new_token;
            current_token = new_token;
            current_col++;
            skip += current_char - i - 1;
            continue;
        }

        if (c == '"') {
            char *id = calloc(2, sizeof(char));
            uint32_t current_char = i+1;
            char nc = source[current_char];
            id[0] = nc;
            current_char++;
            nc = source[current_char];
            while (nc != '"') {
                strncat(id, &nc, 1);
                char *nid = calloc(current_char - i + 1, sizeof(char));
                strcpy(nid, id);
                id = nid;
                current_char++;
                nc = source[current_char];
            }

            id[current_char - i + 1] = '\0';

            new_token->ty = TOK_STRING_LITERAL;
            new_token->lexeme = id;
            new_token->at = at;
            current_token->next = new_token;
            current_token = new_token;
            current_col++;
            skip += current_char - i;
            continue;
        }

        current_col++;
    }

    return head;
}
