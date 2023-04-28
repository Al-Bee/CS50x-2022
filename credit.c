#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    long i;
    int j;
    int k;
    int l;
    int m;
    int n = 0;
    int firsttotal = 0;
    int secondtotal = 0;
    int sumtotal = 0;
    int count = 0;
    int cardtype;

    card = get_long("Enter card number: ");

    i = card;
    //Establish how many digits are in the card number, and store it in 'count'
    while (i != 0)
    {
        i = i / 10;
        count++;
    }

    //check if card length is valid
    if (count >= 13 & count <= 16)
    {
        //starting from the second to last digit and working left, multiply every second digit by 2, split into single digits, and summate
        i = card / 10;
        for (k = count; k > 0; k--)
        {
            l = i % 10;
            i = i / 100;
            l = l * 2;

            if (l > 9)
            {
                m = l % 10;
                l = l / 10;
                l = l + m;
            }

            firsttotal += l;
        }

        //starting from the last digit and working left, summate
        i = card;
        for (k = count; k > 0; k--)
        {
            l = i % 10;
            i = i / 100;
            secondtotal += l;
        }

        sumtotal = firsttotal + secondtotal;

        //if card is valid (sum total finishes with 0), calculate card type (visa, mastercard, amex)

        if (sumtotal % 10 == 0)
        {
            //gets first 1-4 digits to check against
            cardtype = card / 1000000000000;
            i = cardtype;
            while (i != 0)
            {
                i /= 10;
                n++;
            }

            if (n == 3 && ((cardtype / 10) % 10 == (4 | 7)) && (cardtype / 100 == 3))
            {
                cardtype = 1;
                printf("AMEX\n");
            }

            if ((n == 1 && cardtype == 4) || (n == 4 && (cardtype / 1000 == 4)))
            {
                cardtype = 2;
                printf("VISA\n");
            }

            if (n == 4 && (cardtype / 100 == 51 || cardtype / 100 == 55))
            {
                cardtype = 3;
                printf("MASTERCARD\n");
            }

            if (cardtype < 1 | cardtype > 3)
            {
                goto invalid;
            }
        }

        else
        {
            goto invalid;
        }
    }
    else
    {
invalid:
        printf("INVALID\n");
    }
}