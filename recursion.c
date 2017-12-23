#include <stdio.h> 
void towerOfHanoi(int n, char sourcePeg, char auxPeg, char toPeg){
    if(n ==1){
        printf("%c to %c", sourcePeg, toPeg); 
    }
    towerOfHanoi(n-1, sourcePeg ,toPeg, auxPeg);
    printf("%c to %c", sourcePeg, auxPeg); 
    towerOfHanoi(n-1, auxPeg, sourcePeg, toPeg); 
}
int main(void){
    towerOfHanoi(1, 'A', 'B', 'C'); 
    return 0; 
}