#include "gelasia_sort.h"

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#ifdef INCPP
#include <algorithm>
#include <vector>
#endif

int main(int argc, char const *argv[]) {

    // Set random seed.
    srand(time(NULL));
    clock_t tim;

    int valn=0x0001000;
    while(valn<=0x4000000){

        printf ("running with n=%d\n",valn);
        // Add random numbers to vals;
        itype *vals= (itype *) malloc(sizeof(itype)*valn);
        for(int k=0;k<valn;k++) vals[k]= rand();

        itype *valscopy;


        // Test gelasia_sort
        valscopy= (itype *) malloc(sizeof(itype)*valn);
        for(int k=0;k<valn;k++) valscopy[k]=vals[k];

        printf("\tgelasia_sort\n");
        tim= clock();
        gelasia_sort(valscopy,valn);
        tim= clock()-tim;
        printf("\t\tdone in %li.\n",tim);

        free(valscopy);


        //Test qsort
        valscopy= (itype *) malloc(sizeof(itype)*valn);
        for(int k=0;k<valn;k++) valscopy[k]=vals[k];

        printf("\tpure qsort\n");
        tim= clock();
        qsort(valscopy,valn,sizeof(itype),compare);
        tim= clock()-tim;
        printf("\t\tdone in %li.\n",tim);

        free(valscopy);

        #ifdef INCPP
        //Test std::sort
        std::vector<int> valsvector;
        for(int k=0;k<valn;k++) valsvector.push_back(vals[k]);

        printf("\tpure std::sort\n");
        tim= clock();
        std::sort(valsvector.begin(),valsvector.end());
        tim= clock()-tim;
        printf("\t\tdone in %li.\n",tim);

        valsvector.clear();
        #endif

        //Duplicate values count
        free(vals);
        valn*=2;
    }


    return 0;
}

/*
for(int k=0;k<valn;k++) printf("%li ",valscopy[k]);
printf("\n");
*/
