#include <stdio.h> 
void towerOfHanoi(int n, int *sourceArr, int *destArr, int *auxArr);
void problem1(int n){
    //recursive problem 1
    int A[n]; 
    int B[n]; 
    int C[n]; 
    for(int i = 0; i < n; i++){
        A[i] = (n - i); 
    }
    towerOfHanoi(n, A, B, C); 
    for(int i = 0; i < n; i++){
        printf("%i\n", B[i]); 
    }
}

void towerOfHanoi(int n, int *sourceArr, int *destArr, int *auxArr){
    if(n <= 0){
        int tmp = destArr[n];
        destArr[n] = sourceArr[n];  
        sourceArr[n] = tmp;  
        return;
    }
    towerOfHanoi(n-1, sourceArr, auxArr, destArr); 
    int tmp = destArr[n];
    destArr[n] = sourceArr[n];  
    sourceArr[n] = tmp;  
    towerOfHanoi(n-1, auxArr, destArr, sourceArr); 

}
int main(){
    problem1(4); 

    return 0; 
}