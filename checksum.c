//This code is a simple implementation of a checksum algorithm that adds up the digits of a given number recursively. The function takes an integer number as an argument and returns the sum of its digits. If the number is less than 10, it returns the number itself, otherwise it separates the last digit of the number using the modulo operator % and adds it to the sum of the other digits obtained by calling the function again. The main function takes user input and calls the function to obtain the checksum, which is then displayed. //

#include <stdio.h>
int function(number);

int main(){
  
  long int number;
  long int checksum;
  printf("Input: ");
  scanf("%ld", &number);
  checksum = function(number); //call to function
  printf("Checksum: %ld \n", checksum); 
  return 0;
}

  int function(long int number){
  long int x;
    if (number < 10){ // if the number is 1 digit
      return number;
  }
    else{
    
      x = number % 10; // storing the last number
      number /= 10; // separating digits
      return function((x + function(number))); // recursive function to store values
  }
}