#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // L - avg number of letters per 100 words
    // S - avg number of sentences per 100 words
    // word = chars until space, sentences - words until .!?
    // max 16, min 1
    int L = 0, S = 0, words = 1, index;


    // ask the user for a text
    string text = get_string("Text: ");


    // until the end of the text...
    for (int i = 0; i < strlen(text); i++)
    {
        // letters
        if (toupper(text[i]) >= 65 && toupper(text[i]) <= 90)
        {
            L++;
        }

        // words
        if (text[i] == ' ')
        {
            words++;
        }


        // sentences.
        // if the symbol is '!', '.', '?' then it's safe to say that is
        // the end of the sentence
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            S++;
        }
    }

    // if there are too few or too many words (the formula needs 100), the program calculates a multiplier to make the formula work
    double multiplyBy = 1;

    if (words < 100)
    {
        multiplyBy = (float) 100 / words;
    }

    if (words > 100)
    {
        multiplyBy = (float) words / 100;
    }


    index = round(0.0588 * (L * multiplyBy) - 0.296 * (S * multiplyBy) - 15.8);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}