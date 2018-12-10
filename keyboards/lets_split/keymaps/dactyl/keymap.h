#include "lets_split.h"

#ifdef LAYOUT
#undef LAYOUT
#define LAYOUT( \
    R01, R02, R03, R04, R05, R06, R07, \
    R08, R09, R10, R11, R12, R13, R14, \
    R15, R16, R17, R18, R19, R20, R21, \
    R22, R23, R24, R25, R26, R27, R28, \
    R29, R30, R31, R32, R33, R34, R35, \
    L01, L02, L03, L04, L05, L06, L07, \
    L08, L09, L10, L11, L12, L13, L14, \
    L15, L16, L17, L18, L19, L20, L21, \
    L22, L23, L24, L25, L26, L27, L28, \
    L29, L30, L31, L32, L33, L34, L35  \
) \
{ \
    { R35,    R28,    R21,    R14,    R07 }, \
    { R34,    R27,    R20,    R13,    R06 }, \
    { R33,    R26,    R19,    R12,    R05 }, \
    { R32,    R25,    R18,    R11,    R04 }, \
    { R31,    R24,    R17,    R10,    R03 }, \
    { R30,    R23,    R16,    R09,    R02 }, \
    { R29,    R22,    R15,    R08,    R01 }, \
    { L29,    L22,    L15,    L08,    L01 }, \
    { L30,    L23,    L16,    L09,    L02 }, \
    { L31,    L24,    L17,    L10,    L03 }, \
    { L32,    L25,    L18,    L11,    L04 }, \
    { L33,    L26,    L19,    L12,    L05 }, \
    { L34,    L27,    L20,    L13,    L06 }, \
    { L35,    L28,    L21,    L14,    L07 }  \
}
#endif
