//  définitions du type natural, de sa valeur maximale, des macroconstantes
//    servant pour le formatage et le déformatage

//  la macroconstante NATURAL peut être définie à la compilation au moyen de
//    l'option -DNATURAL=VALEUR. Les valeurs valides pour VALEUR sont : UINT8,
//    UINT16, UINT32, UINT64 et UINTMAX. Ces valeurs correspondent à certaines
//    des possibilités offertes par le langage C quant au codage des entiers non
//    signés. Si la macroconstante NATURAL n'est pas définie à la compilation,
//    c'est la valeur UINT32 qui est prise par défaut

#ifndef NATURAL_H
#define NATURAL_H

#define UINT8   8
#define UINT16  16
#define UINT32  32
#define UINT64  64
#define UINTMAX 999

#ifndef NATURAL
#define NATURAL UINT32
#endif

#include <inttypes.h>

#if NATURAL == UINT8

typedef uint8_t natural;

#define NATURAL_MAX UINT8_MAX
#define NATURAL_MIN UINT8_MIN
#define NATURAL_PRI PRIu8
#define NATURAL_SCN SCNu8

#elif NATURAL == UINT16

typedef uint16_t natural;

#define NATURAL_MAX UINT16_MAX
#define NATURAL_MIN UINT16_MIN
#define NATURAL_PRI PRIu16
#define NATURAL_SCN SCNu16

#elif NATURAL == UINT32

typedef uint32_t natural;

#define NATURAL_MAX UINT32_MAX
#define NATURAL_MIN UINT32_MIN
#define NATURAL_PRI PRIu32
#define NATURAL_SCN SCNu32

#elif NATURAL == UINT64

typedef uint64_t natural;

#define NATURAL_MAX UINT64_MAX
#define NATURAL_MIN UINT64_MIN
#define NATURAL_PRI PRIu64
#define NATURAL_SCN SCNu64

#elif NATURAL == UINTMAX

typedef uintmax_t natural;

#define NATURAL_MAX UINTMAX_MAX
#define NATURAL_MIN UINTMAX_MIN
#define NATURAL_PRI PRIuMAX
#define NATURAL_SCN SCNuMAX

#else
#error "bad value for NATURAL"
#endif

#endif  // NATURAL_H
