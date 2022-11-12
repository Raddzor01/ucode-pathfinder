#include "libmx.h"

char *mx_strndup(const char *str, size_t n) {
    char *duplicate = NULL;
    size_t length = mx_strlen(str);

    if (n < length) {
        length = n;
    }

    duplicate = mx_strnew(length);
    mx_strncpy(duplicate, str, length);
    
    return duplicate;
}
