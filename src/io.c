#include "io.h"

char *read_file(char *path)
{
    FILE *fp = fopen(path, "r");

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buf = malloc(size);

    fread(buf, 1, size, fp);

    fclose(fp);

    return buf;
}
