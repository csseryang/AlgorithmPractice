// Simple O(n^2)

#include<stdio.h>

int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    int i,j;
    
    for(i = 0; i < n-1; i++)
        for(j = i+1; j<n; j++)
            if(arr[i] > arr[j])
                inv_count ++;
    return inv_count;
}

int main(int argv, char ** args)
{
    int arr[] = {1, 20, 6, 4, 5};
    printf(" Number of inversions are %d \n", getInvCount(arr, 5));
    return 0;
}