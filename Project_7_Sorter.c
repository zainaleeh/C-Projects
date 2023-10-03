
//Muhammad Zain Ali - U64584914
///The code reads the data from the input file into a struct array, sorts the data by the total_score field using recursive selection sort function, and writes the sorted data into a new file with a "sorted_" prefix. The code includes comments to explain each step of the program.///



#include <stdio.h>
#include <string.h>

// Define a struct called "coffee"
struct coffee {
    char country[150];
    char region[150];
    char owner[150];
    char variety[150];
    double total_score;
};

// Implement selection sort on coffee inventory array
//sort in descending order using the smallest value
void selection_sort_coffee(struct coffee inventory[], int n){
    int i, smallest = 0;
    struct coffee temp;
  
    if (n == 1)
        return;

    for(i = 0; i < n; i++){
        if (inventory[i].total_score < inventory[smallest].total_score){
            smallest = i;
        }
    }
  
    if(smallest < n - 1){
        temp = inventory[n-1];
        inventory[n-1] = inventory[smallest];
        inventory[smallest] = temp;
    }
    
    selection_sort_coffee(inventory, n - 1);
}

int main(){
    FILE *pfile; //declaring file pointers
    FILE *outfile;
    char file_name[30];
    

    // Ask user for input file name
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Open the input file in read mode
    pfile = fopen(file_name, "r");

    if (pfile == NULL){
        printf("Error opening the file \n");
        return 1;
    }

    struct coffee inventory[100]; //array of structs

    int read = 0;
    int data = 0;

    // Read input file line by line and store data in inventory array
    while(!feof(pfile)){
        read = fscanf(pfile, "%[^,],%[^,],%[^,],%[^,], %lf\n", inventory[data].country, inventory[data].region, inventory[data].owner, inventory[data].variety, &inventory[data].total_score);
    
        if (read == 5){
            data++;
        }
        if (read != 5 && read != feof(pfile)){
            printf("File format incorrect. \n");
            return 1;
        }   
    }

    // Sort inventory array by total score
    selection_sort_coffee(inventory, data);
  
    fclose(pfile);

    // Create output file name with "sorted_" prefix
    char pre_fix[44] = "sorted_";
    strcat(pre_fix, file_name);

    // Print output file name
    printf("Output file name:\n%s\n", pre_fix);

    // Open the output file in write mode
    outfile = fopen(pre_fix, "w");

    if (outfile == NULL){
        printf("Error opening the output file \n");
        return 1;
    }

    // Write the sorted inventory array data to the output file
    for (int i = 0; i < data; i++){
        fprintf(outfile, "%s,%s,%s,%s,%.2f\n", inventory[i].country, inventory[i].region, inventory[i].owner, inventory[i].variety, inventory[i].total_score);
    }

    fclose(outfile);

    return 0;
}
