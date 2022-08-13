#include<stdio.h>
#include <stdio.h>
#include "lexer.h"
#include "io.h"

int main(void)
{
    char *source = read_file("../examples/operations.qk");

    token_t *tokens = parse(source);

    while (tokens != NULL) {
        printf("%s\n", tokens->lexeme);
        tokens = tokens->next;
    }
}
