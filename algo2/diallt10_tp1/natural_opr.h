//  déclarations de fonctions binaires sur le type natural

#ifndef NATNBR_OPR_H
#define NATNBR_OPR_H

#include <stdbool.h>
#include "natural.h"

extern natural sum(natural a, natural b);
extern natural dist(natural a, natural b);
extern natural min(natural a, natural b);
extern natural max(natural a, natural b);
extern natural prod(natural a, natural b);
extern natural quo(natural a, natural b);
extern natural rest_div(natural a, natural b);

extern bool is_eq(natural a, natural b);
extern bool is_leq(natural a, natural b);
extern bool is_lth(natural a, natural b);
extern bool is_neq(natural a, natural b);
extern bool is_geq(natural a, natural b);
extern bool is_gth(natural a, natural b);

#endif  // NATNBR_OPR_H
