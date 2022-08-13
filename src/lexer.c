#include "lexer.h"

token_t *parse(char *source)
{
    token_t *current_token = (token_t*)malloc(sizeof(token_t));
    token_t *head = current_token;
    current_token->ty = TOK_HEAD;

    uint32_t source_len = strlen(source);

    uint32_t current_line = 1, current_col = 1;

    uint32_t skip = 0;

    for (int i=0; i < source_len; i++) {
        char c = source[i];

        while (skip > 0) {
            skip--;
            continue;
        }


        file_position_t at = {.line = current_line, .column = current_col};
        token_t *new_token = (token_t*)malloc(sizeof(token_t));

        switch (c) {
            case '\n':
                current_line++;
                current_col = 1;
            case '+':
                new_token->ty = TOK_PLUS;
                new_token->lexeme = "+";
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '-':
                new_token->ty = TOK_MINUS;
                new_token->lexeme = "-";
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '*':
                new_token->ty = TOK_STAR;
                new_token->lexeme = "*";
                new_token->at = at;
                current_token->next = new_token;
                current_token = new_token;
                current_col++;
                continue;
            case '/':
                new_token->ty = TOK_MINUS;
                new_token->lexeme = "/";
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
            new_token->ty = TOK_NUMBER;
            new_token->lexeme = n;
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
