#include <stdio.h>
#include <stdlib.h>
#include "sg.h"

#define WIDTH 600
#define HEIGHT 600

typedef struct {
  double x;
  double y;
} point;

void carre(int n, point a, point b, point c, point d);
point decal(point a, point b, double v);

int main(void) {
  sg_open(WIDTH, HEIGHT, BLACK, WHITE, "Simple Graph Trial");
  do {
    sg_set_fgcolor(YELLOW);

    int n = 50;

    point a = {0, 0};
    point b = {WIDTH, 0};
    point c = {WIDTH, HEIGHT};
    point d = {0, HEIGHT};

    carre(n, a, b, c, d);

  } while (sg_get_key() != 'q');
  sg_close();

  return EXIT_SUCCESS;

}
/* Fonction récursive */
void carre(int n, point a, point b, point c, point d) {
  sg_get_key();

  /* Relier les quatres points*/
  sg_draw_line((int) a.x, (int) a.y, (int) b.x, (int) b.y);
  sg_draw_line((int) b.x, (int) b.y, (int) c.x, (int) c.y);
  sg_draw_line((int) c.x, (int) c.y, (int) d.x, (int) d.y);
  sg_draw_line((int) d.x, (int) d.y, (int) a.x, (int) a.y);

  /*Ordre de décalage*/
  double s = 0.06;

  if(n != 0) {
    carre(n - 1, decal(a, b, s), decal(b, c, s), decal(c, d, s),
          decal(d, a, s));
  }
}

/*Fonction de décalage*/
point decal(point a, point b, double v) {
  point  z;

  z.x = (1 - v) * a.x + v * b.x;
  z.y = (1 - v) * a.y + v * b.y;

  return z;

}


