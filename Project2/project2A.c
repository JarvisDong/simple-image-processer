/*
  Compile: gcc -o pointer_test pointerTest.c
  Run: ./pointer_test
*/

#include <stdio.h> //for printf

int main()
{
  //This should generally work, but if the hard-coded 
  //address ever interferes with another part of your program,
  //then may not get the exact address...
  int *A = (int *)0x8000;
 
  //Note: this is an array of (int *) pointers, not values
  //So, for example, if you subtract an element
  //of B from int pointer A, then you're subtracting two pointers.
  //The result is another pointer.
  int *B[3] = {A, A+7, A+14};

  int *C = A + 4;
  int *D = (int *)(B[0] + 4); //A + 4
  int *diff = (int *)(D - C);

  printf("A = %p\n", A); //0x8000
  printf("C = %p\n", C); //0x8010
  printf("D = %p\n", D); //0x8010
  printf("diff = %p\n", diff); //should be null pointer (nil)
  
  if (diff == NULL)
    printf("The pointer math seems OK\n");

  return 0;
}  