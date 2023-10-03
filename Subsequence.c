//Muhammad Zain Ali - U64584914
//This program prompts the user to enter two words and then checks whether the words are identical. It achieves this by using character arrays to store the user input, and pointers to iterate over the characters in the two words. The program first converts any uppercase characters in both words to lowercase characters, and then compares the characters in each word to determine whether they are the same using a while loop. If the characters in both words are identical, the program outputs "YES", otherwise it outputs "NO". 


#include <stdio.h>

int main()
{
    char word1[1000];
    char word2[1000];
    int len = 0;  // Initialize length variable to 0
    
    // Get input from user
    printf("Enter first word: ");
    scanf("%s", word1);
    
    printf("Enter second word: ");
    scanf("%s", word2);
    
    // Convert word1 to lowercase and count its length
    char *p = word1;
    while(*p != '\0'){
        if(*p >= 'A' && *p <= 'Z'){
            *p = *p - 'A' + 'a';  // Convert uppercase letters to lowercase
        }
        p++;
        len++;  // Increment length for each character
    }
    
    // Convert word2 to lowercase
    char *q = word2;
    while(*q != '\0'){
        if(*q >= 'A' && *q <= 'Z'){
            *q = *q - 'A' + 'a';  // Convert uppercase letters to lowercase
        }
        q++;
    }
    
    // Compare word1 and word2 character by character
    char *r = word1;
    char *s = word2;
    
    int count = 0;
    while(*r != '\0' && *s != '\0'){
        if(*r == *s){  // If characters match, increment count and move to next character
            count++;
            r++;
        }
        s++;
    }
    
    // Check if all characters in word1 and word2 are the same
    if(count == len){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
        
    return 0;
}
