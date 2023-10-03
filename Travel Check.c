// This program calculates the number of days it takes for a spacecraft (B) to catch up to another spacecraft (A) in terms of speed. The user is prompted to enter the number of test cases to be run, and for each case, the speeds of the two spacecraft (A and B) are inputted by the user. If spacecraft B's speed is already greater than spacecraft A's speed, the program outputs that it takes 0 days for B to catch up to A. Otherwise, the program enters a loop where it continuously multiplies spacecraft A's speed by 2 and spacecraft B's speed by 3, and increases a counter for the number of days, until B's speed becomes greater than or equal to A's speed. The program then outputs the number of days it took for B to catch up to A. //


#include <stdio.h>

int main() {
  
    int test_Cases; // variable to store the number of cases
    printf("Number of cases: ");
    scanf("%d", &test_Cases);
    int i;
    for (i = 1; i <= test_Cases; i++) { // loop to test the number of cases
        int speed_of_A, speed_of_B;
        printf("Speed of A: ");
        scanf("%d", &speed_of_A);
        printf("Speed of B: ");
        scanf("%d", &speed_of_B);
      
        int no_of_days = 0;
        if (speed_of_B>speed_of_A)
        {
          printf("Case #%d: %d day(s)\n", i, no_of_days);
          continue; // skip the rest of the loop 
          
          }
      
        while (speed_of_A >= speed_of_B) { // loop to validate and increase the speeds of A and B 
            speed_of_A = speed_of_A * 2;
            speed_of_B = speed_of_B * 3;
            no_of_days++;
        }
        printf("Case #%d: %d day(s)\n", i, no_of_days);
    }
    return 0;
}
