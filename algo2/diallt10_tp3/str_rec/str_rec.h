#ifndef STR_REC_H
#define STR_REC_H

#include <stddef.h>

char *str_chr(const char *s, int c);
char *str_pbrk(const char *s1, const char *s2);
char *str_rchr(const char *s, int c);
size_t str_spn(const char *s1, const char *s2);

#endif  // STR_REC_H
