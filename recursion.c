#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef enum { false,
               true } bool;
void towerOfHanoi(int n, int *sourceArr, int *destArr, int *auxArr);
void sort(int *arr, int val, int n, int size);
void Binary(int n);
void k_string(int n, int k);
int findMax(int **intArr, bool **boolArr, int r, int c);
int boundsChecker(int r, int c, int bound_r, int bound_c, bool **boolArr);
int *convertToArr(int number, int max);
int recursiance_funct(int **intArr, bool **boolArr, int r, int c, int bound_c, int bound_r);
int findMax(int **intArr, bool **boolArr, int max_r, int max_c);
char *A;

void print(bool matrix[1][5])
{
    int i, j;
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 5; j++)
            if (matrix[i][j] == true)
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
        printf("\n");
    }
}
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
    int n = (int)(log10(inArr[0])) + 1;
    int *twoD[arrSize];
    bool *visArr[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        twoD[i] = (int *)malloc(n * sizeof(int));
        visArr[i] = (bool *)malloc(n * sizeof(bool));
    }

    for (int i = 0; i < arrSize; i++)
    {
        int *t = convertToArr(inArr[i], n);
        for (int j = 0; j < n; j++)
        {
            twoD[i][j] = t[j];
            visArr[i][j] = false;
        }
    }
    int max = findMax(twoD, visArr, arrSize, n);
    printf("%d\n", max);
}
int findMax(int **intArr, bool **boolArr, int max_r, int max_c)
{
    int max = 0;
    for (int i = 0; i < max_r; i++)
    {
        for (int j = 0; j < max_c; j++)
        {
            int tmpMax = recursiance_funct(intArr, boolArr, i, j, max_r, max_c);
            if (max < tmpMax)
            {
                max = tmpMax;
            }
        }
    }
    return max;
}
int boundsChecker(int r, int c, int bound_r, int bound_c, bool **boolArr)
{
    if ((r >= bound_r) || (r < 0))
    {
        return 0;
    }
    if ((c >= bound_c) || (c < 0))
    {
        return 0;
    }
    if (boolArr[r][c] == true)
    {
        return 0;
    }
    else
    {
        boolArr[r][c] = true;
    }
    return 1;
}
int recursiance_funct(int **intArr, bool **boolArr, int r, int c, int bound_r, int bound_c)
{
    if (boundsChecker(r, c, bound_r, bound_c, boolArr) && (intArr[r][c]))
    {

        int max = 0;
        max += 1 + recursiance_funct(intArr, boolArr, r - 1, c, bound_r, bound_c) + recursiance_funct(intArr, boolArr, r, c - 1, bound_r, bound_c) + recursiance_funct(intArr, boolArr, r - 1, c - 1, bound_r, bound_c) + recursiance_funct(intArr, boolArr, r, c + 1, bound_r, bound_c) + recursiance_funct(intArr, boolArr, r + 1, c, bound_r, bound_c) + recursiance_funct(intArr, boolArr, r + 1, c + 1, bound_r, bound_c) + recursiance_funct(intArr, boolArr, r + 1, c - 1, bound_r, bound_c) + recursiance_funct(intArr, boolArr, r - 1, c + 1, bound_r, bound_c);
        return max;
    }
    return 0;
}

int *convertToArr(int number, int max)
{
    int n = (int)(log10(number)) + 1;
    int *numArr = calloc(max, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int remainder = number % 10;
        int ind = (max - 1) - i;
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
    int num[5] = {11000, 1100, 101, 10001, 1011};
    problem5(num, 5);

    return 0;
}