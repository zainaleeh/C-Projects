// This code inputs values from the user and stores it in an array. Then using for loops and if statements, it checks wheather the elements in the array are sorted or not, and if the element is a multiple of the next one // 

#include <stdio.h>
#include <stdbool.h> // header files for boolean values

int main(){


  int n;
  

  printf("Enter the length of the input array: ");
  scanf("%d", &n); //

  int numbers[n];
  printf("Enter the array elements: ");
  for (int i = 0; i < n; i++){
    scanf("%d", &numbers[i]); // stores the values in the array
    
  }
  bool flag = true; 

  for(int i = 0; i < n - 1; i++){
    if(numbers[i] > numbers[i+1]){ // checks if numbers are sorted or not
      flag = false; // change of statement as the result doesn't meet the requirement
      break;
    }

  }
  for(int i = 1; i < n - 1; i++){
    if(numbers[i+1] % numbers[i] == 0){ // checks if the adjacent elements are multiples of eachother or not
      flag = false; //change of statement as the result doesn't meet the requirement
      break;}
    }
  if (flag){
    printf("Output: yes \n");
  }
  else{
    printf("Output: no \n");
  }
  
  
  
  
  return 0;
    
  
  
  

  
  
  

  
}