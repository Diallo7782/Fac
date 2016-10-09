#include "natural_opr.h"

natural sum(natural a, natural b) {

  if (a == 0) {
    return b;
  } else {
      return sum(a - 1, b + 1);
    }

}

natural dist(natural a, natural b) {

  if (a == 0) {
    return b;
  } else if (b == 0) {
      return a;
    } else {
        return dist(a - 1, b - 1);
      }

}
natural min(natural a, natural b) {

  if (a == 0) {
    return a;
  } else if (b == 0) {
      return b;
    } else {
        return 1 + min(a - 1, b - 1);
      }

}
natural max(natural a, natural b) {

  if (a == 0) {
    return b;
  } else if (b == 0) {
      return a;
    } else {
        return 1 + max(a - 1, b - 1);
      }

}

natural prod(natural a, natural b) {

  if (a == 0 || b == 0) {
    return a;
  } else {
      return sum(prod(a - 1, b), b);
    }

}

natural quo(natural a, natural b) {

  if (is_lth(a, b)) {
    return 0;
  } else {
      return sum(quo(dist(a, b), b), 1);
    }

}

natural rest_div(natural a, natural b) {
  if ( a == 0 || b == 1 || is_eq(a ,b) == true) {
    return 0;
  } else if (is_lth(a,b)) {
    return a;
  } else {
    return rest_div(dist(a , b) , b);
  }
}

bool is_eq(natural a, natural b) {

  if (a == 0) {
    return (b == 0);
  } else if (b == 0) {
      return (a == 0);
    } else {
        return is_eq(a - 1, b - 1);
      }

}

bool is_leq(natural a, natural b) {

  if (a == 0) {
    return true;
  } else if (b == 0) {
      return false;
    } else {
        return is_leq(a - 1, b - 1);
      }

}

bool is_lth(natural a, natural b) {

  if (a == 0) {
    return (b != 0);
  } else if (b == 0) {
      return false;
    } else {
        return is_lth(a - 1, b - 1);
      }

}

bool is_neq(natural a, natural b) {

  if (a == 0) {
    return (b != 0);
  } else if (b == 0) {
      return (a != 0);
    } else {
        return is_neq(a - 1, b - 1);
      }

}
bool is_geq(natural a, natural b) {

  if (b == 0) {
    return true;
  } else if (a == 0) {
      return false;
    } else {
        return is_geq(a - 1, b - 1);
      }

}

bool is_gth(natural a, natural b) {

  if (b == 0) {
    return (a != 0);
  } else if (a == 0) {
      return false;
    } else {
        return is_gth(a - 1, b - 1);
      }

}

