#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string input);
int count_words(string input);
int count_sentences(string input);

int main(void)
{
    string text = get_string("Text: ");
    printf("%s\n", text);
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int index;
    float l = ((float)letters / (float)words) * 100;
    float s = ((float)sentences / (float)words) * 100;
    float i = 0.0588 * l - 0.296 * s - 15.8;
    int j = (int)(i - 0.5);

    if (j < (int)i)
    {
        index = (int)i;
    }
    else
    {
        index = (int)i + 1;
    }

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if ((index >= 1) && (index <= 15))
    {
        printf("Grade %d\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }

}

int count_letters(string input)
{
    int count = strlen(input);
    int letters = 0;

    for (int i = 0; i < count; i++)
    {
        if ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122))
        {
            letters += 1;
        }
    }
    return letters;
}

int count_words(string input)
{
    int count = strlen(input);
    int words = 1;

    for (int i = 0; i < count; i++)
    {
        if (input[i] == 32)
        {
            words += 1;
        }
    }
    return words;
}

int count_sentences(string input)
{
    int count = strlen(input);
    int sentences = 0;

    for (int i = 0; i < count; i++)
    {
        if ((input[i] == 33) || (input[i] == 46) || (input[i] == 63))
        {
            sentences += 1;
        }
    }
    return sentences;
}