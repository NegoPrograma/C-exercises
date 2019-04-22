/*. Write a program in C to Print Fibonacci Series using recursion. Go to the editor
Test Data : 
Input number of terms for the Series (< 20) : 10
Expected Output :

 Input number of terms for the Series (< 20) : 10                                
 The Series are :                                                                
 1  1  2  3  5  8  13  21  34  55  */

#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int n){
   if(n == 0)
     return n;
   if(n == 1)
     return n; 
   if((Fibonacci(n-2)+ Fibonacci(n-1)) == n)
      printf("%d",n);
      
  
}

int main(void){
Fibonacci(20);

return 0;
}; 