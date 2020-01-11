#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// example input:
/* Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year.
 For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night.
 And he also happened to be a wizard. */


int main(void)
{
    // L - average number of letters per 100 words
    // S - average number of sentences per 100 words
    // word = chars until space, sentences - words until .!?
    // min 1 grade, max 16 grade.
    int L = 0, S = 0, words = 1, index;


    // ask the user for some text
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

    // math formula. index = the grade that the person should be in.
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
