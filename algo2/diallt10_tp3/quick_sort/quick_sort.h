#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stddef.h>

extern void quick_sort(void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *));

#endif  // QUICK_SORT_H
