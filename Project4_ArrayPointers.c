//Muhammad Zain Ali - U64584914
//This program calculates how many minutes that an average viewer will watch a TV show, given the interesting minutes. The program takes user input of the number of interesting minutes and the interesting minutes themselves. It then calls the find_minute function to calculate the earliest possible minute, and prints the output. If the earliest possible minute is after 45 minutes, it sets it to 45.

#include <stdio.h>

// function declaration for find_minute
int find_minute(int *minutes, int n);

int main()
{
  int i, n;
  int output;

  // prompt user to enter number of interesting minutes
  printf("Enter the number of interesting minutes: ");

  // read in number of interesting minutes from user
  scanf("%d", &n);

  // declare an array of size n+1 and initialize last element to 45
  int a[n+1];
  a[n] = 45;

  // prompt user to enter interesting minutes
  printf("Enter the interesting minutes: ");

  // read in the n interesting minutes from user
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // call find_minute function with the array and number of interesting minutes as arguments
  output = find_minute(a,n);

  // print the output returned by find_minute function
  printf("Output: %d \n", output);

  return 0;
}

// function definition for find_minute
int find_minute(int *minutes, int n)
{
  int i;
  int count = 0;
  int *p = minutes;

  // check if the first interesting minute is more than 7 minutes away from the start time
  if (*p > 7){
    // if yes, return 7 as the earliest possible minute
    return 7;
  }

  // iterate through the array to find the earliest minute after which there is a gap of more than 7 minutes
  for (p = minutes; p < minutes + n; p++) {
      if (*(p+1) - *p > 7){
          count = *p + 7;
          break;
      }
      else if(*(p+1) - *p <= 7)
          count = *(p+1) + 7;
  }

  // if the earliest minute is after 45 minutes, set it to 45
  if(count>45){
      count = 45;
  }
  return count;
}
