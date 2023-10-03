#include <stdio.h>

/* Muhammad Zain Ali - U64584914 
This program checks the package selection and validates the hours and 
number of people using if-else statements. Using the information given 
in the packages, the program calculates the total cost of the event and 
outputs the complete final cost. The program also checks whether the number of 
guests is less than or greater than the minimum or maximum for the package 
selected. If any of the options' input is invalid, the program will show an 
error message and exit the program (return 0). */

int main(){

    int package, hours, people;


    // Printing out the package options, asking for an input from the user and validating it
    printf("Please select from three packages: 1, 2, and 3 \n");
    printf("Enter package selection: ");
    scanf("%d", &package);
    if(package < 1 || package > 3){
        printf("Invalid selection. Select from 1 to 3. \n");
        return 0;
    }

    // Asking for an input from the user and validating it
    printf("Enter hours: ");
    scanf("%d", &hours);
    if(hours < 1 || hours > 4){
        printf("Invalid input. Enter a positive number less than or equal to 4 for number of hours. \n");
        return 0;
    }

    int firsthour_rent, hourlycost_after1hour, maxcost_perevent, max_people, min_people, cost_perperson;

    // Different packages with different rates

    if (package == 1){
        firsthour_rent = 50;
        hourlycost_after1hour = 25;
        maxcost_perevent = 95;
        max_people = 200;
        min_people = 50;
        cost_perperson = 25;

    }
    else if (package == 2){
        firsthour_rent = 30;
        hourlycost_after1hour = 15;
        maxcost_perevent = 55;
        max_people = 300;
        min_people = 80;
        cost_perperson = 22;

    }

    else if (package == 3){
        firsthour_rent = 20;
        hourlycost_after1hour = 12;
        maxcost_perevent = 40;
        max_people = 150;
        min_people = 30;
        cost_perperson = 20;

    }
    // Asking the user to input the number of people
    printf("Enter number of people: ");
    scanf("%d", &people);

    //validating the number of people 
    if(people > max_people || people < min_people){
        if (people > max_people){
            printf("Exceeded maximum number of guests.");
            return 0;
        }
        else if (people < min_people){
            printf("Not meeting minimum requirement for number of guests.");
            return 0;
        }

    }

    int extra_hours, extra_hours_cost, room_cost, food_activites_cost, complete_cost;

    //Calculating the cost of the event

    extra_hours = hours - 1;
    extra_hours_cost = extra_hours * hourlycost_after1hour;
    room_cost = firsthour_rent + extra_hours_cost;

    if (room_cost > maxcost_perevent){
        room_cost = maxcost_perevent;

    }
    
    food_activites_cost = people * cost_perperson;
    complete_cost = room_cost + food_activites_cost;
    printf("Charge($): $%d\n", complete_cost);


    return 0;

}