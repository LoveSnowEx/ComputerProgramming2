#include "basic.h"

size_t fgets_n(char *str, int size, FILE *stream) {
    char *ptr = fgets(str, size, stream);
    if(ptr){
        char *end = strchr(ptr, '\n');
        if(end) *end = '\0';
        return strlen(ptr);
    }
    return 0;
}