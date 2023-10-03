// the program takes input from the user using getchar() and uses the while loop to keep taking characters until the user inputs enter. The program uses the isdigit(), isalpha(), and isspace() functions from the ctype.h library to check the type of character in the input. The program encrypts digits by adding 6 to their ASCII value and taking the modulo 10, encrypts alphabets by adding 6 to their ASCII value and taking the modulo 26, and skips whitespaces. Any other special characters are replaced with '_'. The encrypted string is then printed on the screen.//

#include <stdio.h>
#include <ctype.h>

int main() {
    char c; // initialize char
    printf("Enter input: "); 
    while ((c = getchar()) != '\n'){ // input from user using getchar
      
      if (isdigit(c)) { // check if the input is a digit
        
        c = (c - '0' + 6) % 10 + '0';
        printf("%c", c);
          
        }
      else if (isalpha(c)){ // check if the input is a character
        if(isupper(c)){ // check if input is upper case or not
        c = (c - 'A' + 6) % 26 + 'A';
        }else{
          c = (c - 'a' + 6) % 26 + 'a';
        }
        printf("%c", c);
          
      }
      else if (isspace(c)) { 
            // used to skip whitespace
      }
      else{
        printf("_");
      }
    }
    printf("\n");
    return 0;
}
