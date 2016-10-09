#include "quick_sort.h"

//echange le contenu de deux variables
void mem_swap(void* x1, void* x2, size_t size);

void *partition_pivot(void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *));

void quick_sort(void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *)) {

      if (nmemb == 0 || size == 0) {
        return ;
      }
      char *j = (char *) base;
      char *k = (char *) base + (nmemb - 1) * size;
      while (j < k) {
        char *p = partition_pivot(j ,(size_t) (k - j) / size + 1 , size , compar);
        if (j - p < k - p) {
          quick_sort(j , (size_t) (p - j) / size , size , compar);
          j = p + size;
        } else {
            quick_sort(p + size ,(size_t) (k - p) / size , size , compar);
            k = p - size;
          }
      }

}

void mem_swap(void* x1, void* x2, size_t size) {
  if (size != 0) {
    char c = *((char*) x1);
    *((char*) x1) = *((char*) x2);
    *((char*) x2) = c;
    mem_swap((char*) x1 + 1, (char*) x2 + 1, size - 1);
  }

}

void *partition_pivot(void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *)) {
      if (nmemb == 0 || size == 0) {
        return NULL;
      }
      char *pivot = (char*) base + (nmemb - 1) * size;
      char *p = (char*) base;
      char *q = (char*) base;
      size_t k = 0;
      while (k < nmemb) {
        if (compar(q, pivot) < 0) {
          mem_swap(p, q, size);
          p = p + size;
        }
        q = q + size;
        ++k;
      }
      mem_swap(p, pivot, size);
      return p;
}



