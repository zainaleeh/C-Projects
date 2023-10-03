//Muhammad Zain Ali U64584914
//This program takes command line arguments and encodes each argument according to a specific pattern. The program uses a function called encode which takes two strings, the input string and the output string, and encodes the input string into the output string. The program loops through each command line argument and passes it to the encode function. Inside the encode function, each character in the input string is checked to determine whether it is a letter, a digit, a space or any other character. If it is a letter, it is encoded based on its case and shifted by a specific value. If it is a digit, it is encoded by adding a specific value to it. Spaces are ignored, and any other character is replaced with an underscore. The encoded character is added to the output string. Finally, the program prints the encoded output string. The program uses various string and character manipulation functions from the C standard library, such as strlen(), isalpha(), isupper(), isdigit(), and continue.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function to encode input and store the result in output
void encode(char *input, char *output);

int main(int argc, char *argv[]){
    
    // check if number of arguments is greater than or equal to 2
    if (argc < 2) { 
        printf("Invalid input!\n");
        return 0;
    }
    
    char output[1000] = ""; // initialize output
    
    // loop through each element in argv
    for (int i = 1; i < argc; i++) { 
        char *input = argv[i];
        encode(input, output); // encode input and store the result in output
    }
    
    printf("Output: %s\n", output); // print the final output with a newline
    
    return 0;

}

// function to encode input and store the result in output
void encode(char *input, char *output){
    char c;
    int output_index = strlen(output); // keep track of the index in output
    
    for (int j = 0; j < strlen(input); j++) {
        c = input[j];
            
        if (isalpha(c)){
            if(isupper(c)){ 
                c = (c - 'A' + 6) % 26 + 'A'; // encode uppercase letters
            } else{
                c = (c - 'a' + 6) % 26 + 'a'; // encode lowercase letters
            }
        } else if(isdigit(c)) {
            c = (c - '0' + 6) % 10 + '0'; // encode digits
        } else if (isspace(c)) { 
            continue; // skip spaces
        } else{
            c = ('_'); // replace other characters with underscore
        }
        
        output[output_index++] = c; // add c to output and increment the index
    }
}
