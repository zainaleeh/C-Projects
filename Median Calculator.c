//Muhammad Zain Ali - U64584914
//The program declares an array of size n and prompts the user to enter the n elements of the array. It then calls the compute_median function to sort the array in ascending order, calculate the median element, and count its occurrences. The count of occurrences is returned to the main function and printed as the output. The compute_median function uses bubble sort to sort the array in ascending order, calculates the median element of the sorted array, and counts its occurrences in the array.

#include <stdio.h>

// function declaration for compute_median
int compute_median(int *a, int n);

int main()
{
  int i, n;
  int output;

  // prompt user to enter array size
  printf("Enter array size: ");

  // read in array size from user
  scanf("%d", &n);

  // declare an array of size n
  int a[n];

  // prompt user to enter array elements
  printf("Enter array elements: ");

  // read in the n elements of the array from user
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // call compute_median function with the array and array size as arguments
  output = compute_median(a,n);

  // print the output returned by compute_median function
  printf("Output: %d \n", output);

  return 0;
}

// function definition for compute_median
int compute_median(int *a, int n)
{
  int temp;
  int count = 0;
  int median;
  int *p = a;
  int *q = a;

  // sort the array in ascending order using bubble sort
  for (p = a; p < a + n - 1; p++){
    for (q = p+1; q < a+n; q++){
      if (*q < *p){
        temp = *p;
        *p = *q;
        *q = temp;
      }
    }
  }

  // calculate the median element of the sorted array
  median = *(a + n/2);

  // count the number of occurrences of the median element in the array
  for (p = a; p < a + n; p++){
    if(*p == median){
      count++;
    }
  }

  // return the count of occurrences of the median element in the array
  return count;
}
