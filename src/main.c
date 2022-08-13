#include<stdio.h>
#include <stdio.h>
#include "lexer.h"

int main(void)
{
    token_t *tokens = parse("2+2");

    printf("%s\n", tokens->next->lexeme);
}
