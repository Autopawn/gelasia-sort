#ifndef GELASIA_SORT_H
#define GELASIA_SORT_H

#include <assert.h>
#include <math.h>
#include <stdlib.h>

typedef INTEGER_TYPE itype;

void gelasia_sort(itype *vals, int valn);

int compare (const void * a, const void * b);

#endif
