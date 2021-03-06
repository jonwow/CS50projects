// Example input (26 letter a-Z key):
// ./substitution VcHpRzGjNtLsKfBdQwAxEuYmOi

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// variables
string abc = "abcdefghijklmnopqrstuvwxyz";
char cipherText[888] = {};
int index = 0;

// functions
void lookForAMatch(char temp, string key[]);



int main(int argc, string key[])
{
    // TESTS:
    // argument count validity
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }

    // key validity
    if (strlen(key[1]) < 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }

    // duplicate key characters or non a-Z characters
    for (int i = 0; i < strlen(key[1]); i++)
    {
        if (key[1][i] == key[1][i - 1])
        {
            printf("Bad key. Duplicate characters.");
            return 1;
        }

        // letter z value is: 122, A: 65.
        if (key[1][i] > 'z' || key[1][i] < 'A')
        {
            printf("Bad key. Incorrect characters. (Accepting only a-Z)");
            return 1;
        }
    }
    // END OF TESTS

    
    // ask the user for input
    string plainText = get_string("plaintext:  ");


    // while there are letters in the plainText
    for (int i = 0; i < strlen(plainText); i++)
    {
        char temp = plainText[i];
        bool isCapital = false;

        // if plainText[i] is capital, make a copy of its small version 'temp'
        if (plainText[i] >= 65 && plainText[i] <= 90)
        {
            temp += 32;
            isCapital = true;
        }

        // call a function to find the letter's index in the alphabet and do some more there
        lookForAMatch(temp, key);


        // making the letter capitalized or not depending on its initial state.
        if (isCapital == true)
        {
            cipherText[index - 1] -= 32;
        }

    }

    printf("ciphertext: %s\n", cipherText);

    return 0;
}



void lookForAMatch(char temp, string key[])
{
    // a variable to determine if a match was found or not (if it was not, the 'temp' character is a comma, a space or etc.
    bool foundIt = false;

    // from 'a' to 'z'
    for (int counter = 0; counter < strlen(abc); counter++)
    {
        // if the small letter of plainText[i] matches with a letter from the alphabet
        if (temp == abc[counter])
        {
            // counter = the index of the alphabet where the letter should be. usable in the key too
            cipherText[index] = key[1][counter];

            // if the key letter is capital, make it lowercase
            if (key[1][counter] >= 65 && key[1][counter] <= 90)
            {
                cipherText[index] += 32;
            }

            index++;
            foundIt = true;
        }
    }

    // if the program didn't find a match, this block of code gets executed (typically for characters such as 'space', comma or period.
    if (foundIt == false)
    {
        cipherText[index] = temp;
        index++;
    }
}
