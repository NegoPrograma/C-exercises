/*. 2. Write a program in C to calculate the sum of numbers from 1 to n using recursion. Go to the editor
Test Data : 
Input the last number of the range starting from 1 : 5 
Expected Output :

The sum of numbers from 1 to 5 : 
15  */

#include <stdio.h>
#include <stdlib.h>

int sequential_recursive_sum(int n){
  if(n == 1){
    return 1;
  }
  else{
    return n + sequential_recursive_sum(n-1);
  }
  
  
};

int main(void){
  printf("%d",sequential_recursive_sum(5));

return 0;
}; 