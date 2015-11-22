#include<stdio.h>

int getMedianRec(int ar1[], int ar2[], int left, int right, int n);

int getMedian(int ar1[], int ar2[], int n)
{
    return getMedianRec(ar1, ar2, 0, n-1, n);
}

int getMedianRec(int ar1[], int ar2[], int left, int right, int n)
{
    int i, j;
    
    if(left > right)
        return getMedianRec(ar2, ar1, 0, n-1, n);
    i = (left + right )/2;
    j = n - i - 1;
    
    if(ar1[i] > ar2[j] && (j == n-1 || ar1[i] < ar2[j+1]))
    {
        if(i==0 || ar2[j] > ar1[i-1])
            return (ar1[i] + ar2[j])/2;
        else
            return (ar1[i] + ar1[i-1])/2;
    }
    else if(ar1[i] > ar2[j] && j != n-1 &&ar1[i] > ar2[j+1])
        return getMedianRec(ar1, ar2, left, i-1, n);
    else
        return   getMedianRec(ar1, ar2, i+1, right, n);
}
/* Driver program to test above function */
int main()
{
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
        printf("Median is %d", getMedian(ar1, ar2, n1));
    else
        printf("Doesn't work for arrays of unequal size");
 
    return 0;
}