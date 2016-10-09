#include <stdlib.h>
#include <stdio.h>
#include "str_rec.h"

#define TEST_PTR(fun, text, arg, fmt)           \
  {                                             \
    printf("# " #fun "\n");                     \
    printf("%s\n", text);                       \
    char *p = fun(text, arg);                   \
    if (p == NULL) {                            \
      printf("*");                              \
    } else {                                    \
      printf("%*c", (int) (p - text + 1), '|'); \
    }                                           \
    printf("%" fmt "\n", arg);                  \
  }

#define TEST_SIZE(fun, text, arg, fmt)  \
  {                                     \
    printf("# " #fun "\n");             \
    printf("%s\n", text);               \
    size_t n = fun(text, arg);          \
    if (n > 0) {                        \
      ++n;                              \
    }                                   \
    printf("%*c", (int) n, '|');        \
    printf("%" fmt "\n", arg);          \
  }

#define TEST_CHAR_PTR(fun,  text, arg)  TEST_PTR(fun,   text, arg, "d")
#define TEST_STR_PTR(fun,   text, arg)  TEST_PTR(fun,   text, arg, "s")
#define TEST_STR_SIZE(fun,  text, arg)  TEST_SIZE(fun,  text, arg, "s")

int main(void) {
  char *text = "http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf";
  TEST_CHAR_PTR(str_chr,  text, 'd');
  TEST_CHAR_PTR(str_chr,  text, 'a');
  TEST_CHAR_PTR(str_chr,  text, '\0');
  TEST_CHAR_PTR(str_rchr, text, 'd');
  TEST_CHAR_PTR(str_rchr, text, 'a');
  TEST_CHAR_PTR(str_rchr, text, '\0');
  TEST_STR_PTR(str_pbrk,  text, ".:/");
  TEST_STR_PTR(str_pbrk,  text, "0123456789");
  TEST_STR_PTR(str_pbrk,  text, "abiklmquvxyz");
  TEST_STR_SIZE(str_spn,  text, "abcdefghijklmnopqrstuvwxyz");
  TEST_STR_SIZE(str_spn,  text, ".:/");
  return EXIT_SUCCESS;
}
