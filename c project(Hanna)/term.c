#include <stdio.h>
#include <stdlib.h>
#include "term.h"

char * term_to_string(const term_t * term) {
    size_t buffer_size;
    char * buffer;

    if (term->exponent == 0) {
        // If exponent is 0, print just the coefficient
        buffer_size = snprintf(NULL, 0, "%d", term->coefficient) + 1;
        buffer = malloc(buffer_size);
        snprintf(buffer, buffer_size, "%d", term->coefficient);
    } 
    else if (term->exponent == 1) {
        // If exponent is 1, omit the ^1
        buffer_size = snprintf(NULL, 0, "%d%c", term->coefficient, term->var) + 1;
        buffer = malloc(buffer_size);
        snprintf(buffer, buffer_size, "%d%c", term->coefficient, term->var);
    } 
    else {
        // Standard format: coefficient + variable + exponent
        buffer_size = snprintf(NULL, 0, "%d%c^%d", term->coefficient, term->var, term->exponent) + 1;
        buffer = malloc(buffer_size);
        snprintf(buffer, buffer_size, "%d%c^%d", term->coefficient, term->var, term->exponent);
    }

    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return buffer;
}
