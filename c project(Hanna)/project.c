#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "term.h"
#include "polynomial.h"
#include "basiclist.h"

#define BUFFERLEN 100

/* Parses a string into a term data structure */
term_t * string_to_term(char * buff) {
    term_t * ret = malloc(sizeof(term_t));
    ret->coefficient = atoi(strtok(buff, " "));
    ret->var = *strtok(NULL, " ");
    ret->exponent = atoi(strtok(NULL, " "));
    return ret;
}

/* Reads a text file and adds terms to a basiclist */
void read_terms_from_file(node_t ** term_list) {
    FILE *fp;
    char buffer[BUFFERLEN];

    if ((fp = fopen("terms.txt", "r")) == NULL) {
        fprintf(stderr, "\nERROR: Missing terms.txt\n\n");
        exit(-1);
    }

    while (fgets(buffer, BUFFERLEN, fp)) {
        if (buffer[0] < '0' || buffer[0] > '9') {
            continue;
        }

        term_t * this_term = string_to_term(buffer);
        list_add(term_list, this_term);
    }
    fclose(fp);
}

int main(void) {
    term_t testterm1 = {1, 'x', 0};
    term_t testterm2 = {2, 'x', 1};
    term_t testterm3 = {3, 'x', 2};

    poly_t * poly1 = new_polynomial();  // Initialize poly1
    poly_t * poly2;
    node_t * curr;

    /* Read terms into term_list */
    node_t * term_list = NULL;
    read_terms_from_file(&term_list);

    /* Add terms to the polynomial */
    curr = term_list;
    while (curr != NULL) {
        add_to_polynomial(poly1, (term_t *) curr->data);
        curr = curr->next;
    }

    /* Test term code */
    printf("NAME: Hanna\n");
    printf("Testing term.c/h:\n");
    printf("testterm1: %s\n", term_to_string(&testterm1));
    printf("testterm2: %s\n", term_to_string(&testterm2));
    printf("testterm3: %s\n", term_to_string(&testterm3));

    /* ADD THE TERMS IN term_list TO A NEW POLYNOMIAL  */
    printf("\nTesting basic polynomial functions: Adding terms & testing print_poly\n");
    poly_t * test_poly = new_polynomial();
    add_to_polynomial(test_poly, &testterm1);
    add_to_polynomial(test_poly, &testterm2);
    add_to_polynomial(test_poly, &testterm3);
    printf("Polynomial of degree 2: ");
    print_polynomial(test_poly); // Expected: 3x^2 + 2x + 1
    printf("\n");

    /* Polynomial test code */
    printf("\nTesting polynomial.c/h : \n");
    printf("Original: Polynomial of degree 4: ");
    print_polynomial(poly1);  // Print original polynomial
   
    poly2 = combine_like_terms(poly1);  // Combine like terms
    sort_polynomial(poly2);  // Sort by exponent (highest to lowest)
    printf("\nCombined: Polynomial of degree 4: ");
    print_polynomial(poly2);  // Print combined polynomial
    printf("\nNAME: Hanna\n");

    // Cleanup memory
    delete_polynomial(&poly1);
    delete_polynomial(&poly2);
    delete_polynomial(&test_poly);


    return 0;
}
