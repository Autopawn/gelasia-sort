#include "gelasia_sort.h"

#include <stdio.h>

int main(int argc, char const *argv[]) {
    long vals[]={1212,123,1,2,1,4124,125,125,8,7,5,4,223,4,5};
    gelasia_sort(vals,15);
    for(int k=0;k<15;k++) printf("%li ",vals[k]);
    printf("\n");
    return 0;
}
