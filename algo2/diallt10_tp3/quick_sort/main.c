#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "quick_sort.h"
//comparer les chaines...cool
int int_compar(const int *x1, const int *x2);

#define LENGTH  25

int main(void) {
  srand(0);
  while (1) {
    int a[LENGTH];
    for (size_t k = 0; k < sizeof a / sizeof *a; ++k) {
      a[k] = rand() % 100;
    }
    for (size_t k = 0; k < sizeof a / sizeof *a; ++k) {
      printf("%3d", a[k]);
    }
    printf("\n");
    quick_sort(a, sizeof a / sizeof *a, sizeof *a,
        (int (*) (const void *, const void *)) int_compar);
    for (size_t k = 0; k < sizeof a / sizeof *a; ++k) {
      printf("%3d", a[k]);
    }
    printf("\n>");
    while (1) {
      int c = getchar();
      if (c == EOF || toupper(c) == 'Q') {
        return EXIT_SUCCESS;
      }
      if (c == '\n') {
        break;
      }
    }
  }
}

int int_compar(const int *x1, const int *x2) {
  return (*x1 > *x2) - (*x1 < *x2);
}
