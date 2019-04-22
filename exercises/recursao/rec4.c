/*. 
4. Write a program in C to print the array elements using recursion. Go to the editor
Test Data : 
Input the number of elements to be stored in the array :6 
Input 6 elements in the array : 
element - 0 : 2 
element - 1 : 4 
element - 2 : 6 
element - 3 : 8 
element - 4 : 10
element - 5 : 12
Expected Output :

The elements in the array are : 2  4  6  8  10  12 
Click me to see the solution*/

#include <stdio.h>
#include <stdlib.h>

int rec_show_element(int array[], int index){
  if(index == 0 ){
    return array[index];
  }else{
     return rec_show_element(array, index-1);
  }
}

int main(void){

  int v[5] = {839,029,729,762,9173};
  printf("%d",rec_show_element(v, 5));


return 0;
}; 