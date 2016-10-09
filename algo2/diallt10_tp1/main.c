#include <stdio.h>
#include <stdlib.h>
#include "natural.h"
#include "natural_opr.h"

int main(void) {
  natural a = 0;
  natural b = 0;
  while ( scanf( "%" NATURAL_SCN "%" NATURAL_SCN, &a, &b ) == 2) {
    printf( "Somme : " );
    printf( "%" NATURAL_PRI, sum( a, b ) );
    printf( "\nProduit : " );
    printf( "%" NATURAL_PRI, prod( a, b ) );
    printf( "\nQuotient : " );
    printf( "%" NATURAL_PRI, quo( a, b ) );
    printf( "\nReste de la division : " );
    printf( "%" NATURAL_PRI, rest_div( a, b ) );
    printf( "\nDistance : " );
    printf( "%" NATURAL_PRI, dist( a, b ) );
    printf( "\nMaximum : " );
    printf( "%" NATURAL_PRI, max( a, b ) );
    printf( "\nMinimum : " );
    printf( "%" NATURAL_PRI, min( a, b ) );
    printf( "\nSont égaux : " );
    printf( "%" NATURAL_PRI, is_eq( a, b ) );
    printf( "\nInférieur ou égal : " );
    printf( "%" NATURAL_PRI, is_leq( a, b ) );
    printf( "\nInférieur strict : " );
    printf( "%" NATURAL_PRI, is_lth( a, b ) );
    printf( "\nNe sont pas égaux : ");
    printf( "%" NATURAL_PRI, is_neq( a, b ) );
    printf( "\nSupérieur ou égal : ");
    printf( "%" NATURAL_PRI, is_gth( a, b ) );
    printf( "\nSupérieur strict : " );
    printf( "%" NATURAL_PRI, is_geq( a, b ) );

  }
  return EXIT_SUCCESS;
}
