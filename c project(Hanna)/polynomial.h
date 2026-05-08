#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "term.h"
#include "basiclist.h"

typedef struct {
    node_t *terms;  // Pointer to the linked list of terms
    int degree;     // Highest exponent in the polynomial
} poly_t;

// Function prototypes
poly_t * new_polynomial(void);
void print_polynomial(const poly_t * poly);
void add_to_polynomial(poly_t * poly, const term_t * term);
poly_t * combine_like_terms(const poly_t * poly);
void sort_polynomial(poly_t *poly);
void delete_polynomial(poly_t ** poly);

#endif


