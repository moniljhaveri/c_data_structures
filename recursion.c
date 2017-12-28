#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void towerOfHanoi(int n, int *sourceArr, int *destArr, int *auxArr);
void sort(int *arr, int val, int n, int size);
void Binary(int n);
void k_string(int n, int k);
int *convertToArr(int number);
char *A;

void problem1(int n)
{
    //recursive problem 1
    int A[n];
    int B[n];
    int C[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = (n - i);
    }
    towerOfHanoi(n, A, B, C);
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", B[i]);
    }
}

void problem2(int n)
{
    int A[n];
    int B[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = (n - i);
        B[i] = i;
    }
    sort(A, *(A), 0, n);
    sort(B, *(B), 0, n);
}

void problem3(int n)
{
    A = (char *)malloc(sizeof(char) * n);
    Binary(n);
}

void problem4(int n, int k)
{
    A = (char *)malloc(sizeof(char) * n);
    k_string(n, k);
}

void problem5(int *inArr, int arrSize)
{
    int *numArr = convertToArr(101011);
    for (int i = 0; i < 6; i++)
    {
        printf("%i", numArr[i]);
    }
}

int *convertToArr(int number)
{
    double n = (int)(log10(number)) + 1;
    int *numArr = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int remainder = number % 10;
        int ind = (n - 1) - i;
        numArr[ind] = remainder;
        number /= 10;
    }
    return numArr;
}
void k_string(int n, int k)
{
    if (n < 1)
    {
        printf("%s\n", A);
        return;
    }
    int i;
    for (i = 0; i < k; i++)
    {
        A[n - 1] = i + 65;
        k_string(n - 1, k);
    }
}

void Binary(int n)
{
    // This is the function to find all binary strings
    // The big O of this function is I think  2*T(n - 1)
    // That equals O(2^n) %need to figure this out

    if (n == 0)
    {
        printf("%s\n", A);
        return;
    }
    A[n - 1] = '0';
    Binary(n - 1);
    A[n - 1] = '1';
    Binary(n - 1);
}

void sort(int *arr, int val, int n, int size)
{
    if (n == size)
    {
        printf("In order\n");
        return;
    }
    if (val < *(arr))
    {
        printf("Not in order\n");
        return;
    }
    sort(arr, *(arr + n), n + 1, size);
}

void towerOfHanoi(int n, int *sourceArr, int *destArr, int *auxArr)
{
    if (n <= 0)
    {
        int tmp = destArr[n];
        destArr[n] = sourceArr[n];
        sourceArr[n] = tmp;
        return;
    }
    towerOfHanoi(n - 1, sourceArr, auxArr, destArr);
    int tmp = destArr[n];
    destArr[n] = sourceArr[n];
    sourceArr[n] = tmp;
    towerOfHanoi(n - 1, auxArr, destArr, sourceArr);
}

int main()
{
    int num[1] = {101};
    problem5(num, 0);

    return 0;
}