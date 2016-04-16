#include "gelasia_sort.h"

// Compare function for qsort
int compare (const void * a, const void * b){
    return (*(itype*)a-*(itype*)b);
}

void get_min_max(itype *vals, int valn, itype *min, itype *max){
    // min and max are determinated by the first number.
    *min=vals[0],*max=vals[0];
    // for each value, update the min and max values.
    for(int k=1;k<valn;k++){
        if(vals[k]>*max) *max=vals[k];
        else if(vals[k]<*min) *min=vals[k];
    }
}

void gelasia_sort(itype *vals, int valn){

    if(valn<32){ // I need to do the math to known the right value for this.
        qsort(vals,valn,sizeof(itype),compare);
        return;
    }

    // Return if there aren't values.
    if(valn==0) return;
    assert(valn>=0);
    // Get the min and max of the values
    itype min,max;
    get_min_max(vals,valn,&min,&max);

    // Calculate the range
    itype rangeminus1= max-min;
    // If the range is 1, vals is sorted as it contain only one value, repeated or not.
    if(rangeminus1==0) return;
    // Get the sqrt +1 of the range.
    itype rsqrt= (itype)sqrt((double)(rangeminus1)+1.0)+1;
    // The number of sublists:
    int sublistn= rsqrt;
    // But the rsqrt shall never be equal or larger than the range (or else every number will fall on the same sublist):
    if(rsqrt+1>=rangeminus1){
        rsqrt=1;
        sublistn= (int)rangeminus1+1;
    }
    // Prepare the creation of sublistn sublists.
    int *valn4subs= malloc(sizeof(int)*sublistn);
    for(int s=0;s<sublistn;s++) valn4subs[s]=0;
    // Count how many vals will land on each to known how much memory will each need.
    for(int k=0;k<valn;k++){
        int land= (vals[k]-min)/rsqrt;
        assert(land<sublistn);
        valn4subs[land]++;
    }

    // Create the rqrst sublists.
    itype **subvals= malloc(sizeof(itype*)*sublistn);
    for(int s=0;s<sublistn;s++) subvals[s]= malloc(sizeof(itype)*valn4subs[s]);

    // Create a list to store the count currently added to the list.
    int *currentvaln4subs= malloc(sizeof(int)*sublistn);
    for(int s=0;s<sublistn;s++) currentvaln4subs[s]= 0;

    // Distribute the values to the sublists
    for(int k=0;k<valn;k++){
        int land= (vals[k]-min)/rsqrt;
        assert(land<sublistn);
        // Send the value to the sublist.
        subvals[land][currentvaln4subs[land]]= vals[k];
        // Update the current valn of the sublist
        currentvaln4subs[land]++;
    }

    // Delete the current sublists valns since they are not longer necessary.
    for(int s=0;s<sublistn;s++) assert(currentvaln4subs[s]==valn4subs[s]);
    free(currentvaln4subs);

    // Rewrite the vals list, sorted.
    int currentvaln=0;
    for(int s=0;s<sublistn;s++){
        // Sort the values of the current sublist.
        gelasia_sort(subvals[s], valn4subs[s]);
        // Add the sorted values of this sublist to vals.
        for(int k=0;k<valn4subs[s];k++){
            vals[currentvaln]= subvals[s][k];
            currentvaln++;
        }
        // Free the current sublist memory
        free(subvals[s]);
    }
    assert(currentvaln==valn);

    // Free remaining arrays.
    free(subvals);
    free(valn4subs);

}
