#include <string.h>
#include "str_rec.h"

char *str_chr(const char *s, int c) {

  if (s == NULL) {
    return NULL;
  }
  if (*s == (char) c) {
      return (char*) s;
  }
  if (*s == '\0') {
    return NULL;
  }

  return str_chr(s + 1, c);

}



char *str_pbrk(const char *s1, const char *s2) {

  if (s1 == NULL || s2 == NULL) {
    return NULL;
  }
  if (str_chr(s2, *s1) != NULL) {
      return (char*) s1;
  }

  return str_pbrk(s1 + 1, s2);

}

static char *str_rchr_aux(char *r, const char *s1, int c);

char *str_rchr(const char *s, int c) {

  return str_rchr_aux(NULL, s, c);

}
char *str_rchr_aux(char *r, const char *s1, int c) {

  if (s1 == NULL) {
    return NULL;
  }
  if (*s1 == (char) c) {
      return r = (char*) s1;
  }
  if (s1 == '\0') {
    return NULL;
  }

  return str_rchr_aux(r, s1 + 1, c);

}

static size_t str_spn_aux(size_t n, const char *s1, const char *s2);

size_t str_spn(const char *s1, const char *s2) {

  return str_spn_aux(0, s1, s2);

}

size_t str_spn_aux(size_t n, const char *s1, const char *s2) {
  if (str_chr(s2, *s1) == NULL) {
    return n;
  }

  return str_spn_aux(n + 1, (char *) s1 + 1, s2);

}
