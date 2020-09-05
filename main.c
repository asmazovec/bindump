#include <stdio.h>
#include <stdint.h>

#define bindump(ptr) ({                                  \
    int n = (sizeof (*ptr)) * 8;                         \
    while (n) printf ("%i", (int)((*(ptr) >> --n) & 1)); \
    printf ("\n");\
})

int main () {
    int8_t  i1 = 222;
    int16_t i2 = -222;
    int32_t i3 = 222;
    bindump (&i1);
    bindump (&i2);
    bindump (&i3);

    uint8_t  ui1 = 222;
    uint16_t ui2 = 222;
    uint32_t ui3 = 222;
    bindump (&ui1);
    bindump (&ui2);
    bindump (&ui3);
    
    float  fl = 123;
    double db = 123;
    bindump ((int*)&fl);
    bindump ((long int*)&db);

    return 0;
}

