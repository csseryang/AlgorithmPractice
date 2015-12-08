#include <stdio.h>
#include<limits.h>

int max(int a, int b){ return (a > b)?a:b;}

int eggDrop(int n, int k)
{
    if(k==1 || k ==0)
        return k;
    
    if(n==1)
        return k;
    
    int min = INT_MAX, res, x;
    
    for(x = 1; x <=k; x++)
    {
        res = max(eggDrop(n-1, x-1), eggDrop(n, k-x));
        if(res < min)
            min = res;
    }
    return min+1;
}

/* Driver program to test to pront printDups*/
int main()
{
    int n = 2, k = 10;
    printf ("\nMinimum number of trials in worst case with %d eggs and "
             "%d floors is %d \n", n, k, eggDrop(n, k));
    return 0;
}