#include <stdio.h>

int main(void)
{
    //get height amnt
    int noh;
    printf("Give me your height baka: ");
    scanf("%d", &noh);

    //reprompt if incorrect input
    if (noh == -1)
    {
        printf("Give me your height *correctly* baka: ");
        scanf("%d", &noh);
    }
    else if (noh > 8 || noh < 1)
    {
        printf("Please put a positive integer between 1 and 8 for da height.\n");
        scanf("%d", &noh);
    }

    // for each line identical to height
    for (int line = 0; line < noh; line++)
    {
        //print spaces equal to the noh - the lines so that the hashes line up
        for (int spaces = noh - line; spaces > 1; spaces--)
        {
            printf(" ");
        }

        // print #'s until hash1 equal to number of hashes
        int hash1 = 0;
        do
        {
            printf("#");
            hash1++;
        } while (hash1 <= line);

        //2 spaces between the hashes
        printf("  ");

        // print #'s until hash2 equal to number of hashes
        int hash2 = 0;
        do
        {
            printf("#");
            hash2++;
        } while (hash2 <= line);

        //newline
        printf("\n");
    }
}