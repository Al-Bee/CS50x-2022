#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //int length = strlen(argv[1]);
    char key[26] = {0};
    int offset[26];

    //Check correct argc count = 1
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //Check key is 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //Check key contains letters only
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if ((argv[1][i] < 'a' || argv[1][i] > 'z') && (argv[1][i] < 'A' || argv[1][i] > 'Z'))
        {
            printf("Letters only, please.\n");
            return 1;
        }
    }

    //Check for duplicate letters
    int check[26] = {0};

    for (int j = 0; j < strlen(argv[1]); j++)
    {
        int ch = toupper(argv[1][j]);

        if (check[ch - 65] == 0)
        {
            check[ch - 65] = ch;
            key[j] = ch;
        }

        else
        {
            return 1;
        }
    }

    string plaintext = get_string("plaintext:  ");
    char plainupper[strlen(plaintext)];
    char ciphertext[strlen(plaintext)];

    //Convert text to uppercase
    for (int x = 0; x <= strlen(plaintext); x++)
    {
        plainupper[x] = toupper(plaintext[x]);
    }

    //Check text against key and return upper, lower, or other
    for (int y = 0; y <= strlen(plaintext); y++)
    {
        if ((plainupper[y] >= 65) && (plainupper[y] <= 90))
        {
            ciphertext[y] = key[plainupper[y] - 65];

            if (islower(plaintext[y]))
            {
                ciphertext[y] = tolower(ciphertext[y]);
            }
        }

        else
        {
            ciphertext[y] = plainupper[y];
        }

    }

    printf("ciphertext: %s\n", ciphertext);
}
