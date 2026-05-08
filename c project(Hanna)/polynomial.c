#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

poly_t * new_polynomial(void) {
    poly_t * poly = malloc(sizeof(poly_t));
    if (!poly) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    poly->terms = NULL;
    poly->degree = 0;
    return poly;
}

void print_polynomial(const poly_t * poly) {
    if (!poly || !poly->terms) {
        printf("0\n");
        return;
    }

    node_t * curr = poly->terms;
    int first = 1;  

    while (curr != NULL) {
        term_t * term = (term_t *) curr->data;
        
        if (term->coefficient == 0) {
            curr = curr->next;
            continue;
        }

        if (!first && term->coefficient > 0) {
            printf(" + ");
        }

        if (term->exponent == 0) {
            printf("%d", term->coefficient);
        } else if (term->exponent == 1) {
            printf("%dx", term->coefficient);
        } else {
            printf("%dx^%d", term->coefficient, term->exponent);
        }

        first = 0;
        curr = curr->next;
    }

    printf("\n");
}

void add_to_polynomial(poly_t * poly, const term_t * term) {
    term_t *new_term = malloc(sizeof(term_t));
    if (!new_term) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    *new_term = *term;
    
    list_add(&poly->terms, new_term);  
    if (term->exponent > poly->degree) {
        poly->degree = term->exponent;
    }
}

poly_t * combine_like_terms(const poly_t * poly) {
    poly_t * new_poly = new_polynomial();
    node_t * curr = poly->terms;
    
    while (curr) {
        term_t * term = (term_t *)curr->data;
        
        node_t * new_curr = new_poly->terms;
        term_t * existing = NULL;
        
        while (new_curr) {
            term_t * new_term = (term_t *)new_curr->data;
            if (new_term->exponent == term->exponent) {
                existing = new_term;
                break;
            }
            new_curr = new_curr->next;
        }
        
        if (existing) {
            existing->coefficient += term->coefficient;
        } else {
            term_t * new_term = malloc(sizeof(term_t));
            if (!new_term) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            *new_term = *term;
            add_to_polynomial(new_poly, new_term);
        }
        
        curr = curr->next;
    }
    
    return new_poly;
}

void sort_polynomial(poly_t *poly) {
    if (!poly || !poly->terms || !poly->terms->next) return;  // Nothing to sort

    node_t *sorted = NULL;  // Sorted list
    node_t *curr = poly->terms;

    while (curr) {
        node_t *next = curr->next;  // Save next node
        if (!sorted || ((term_t *)curr->data)->exponent >((term_t *)sorted->data)->exponent) {
            curr->next = sorted;
            sorted = curr;
        } else {
            // Find correct position in sorted list
            node_t *temp = sorted;
            while (temp->next && ((term_t *)temp->next->data)->exponent >= ((term_t *)curr->data)->exponent) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;  // Move to next node
    }
    poly->terms = sorted;  // Update sorted list
}

void delete_polynomial(poly_t ** poly) {
    if (!poly || !(*poly)) return;

    node_t *curr = (*poly)->terms;
    while (curr) {
        node_t *temp = curr;
        free((void*)temp->data);  
        curr = curr->next;
        free(temp);
    }

    free(*poly);
    *poly = NULL;
}
