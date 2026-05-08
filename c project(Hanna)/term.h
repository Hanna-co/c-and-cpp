#ifndef TERM_H
#define TERM_H

typedef struct {
    int coefficient;  // The coefficient of the term
    char var;         // The variable (assumed to be a single character)
    int exponent;     // The exponent
} term_t;

// Converts a term to a string format
char * term_to_string(const term_t * term);

#endif
