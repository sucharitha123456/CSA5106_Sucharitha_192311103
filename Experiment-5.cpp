#include <stdio.h>
#include <string.h>
#include <ctype.h>
int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main()
{
    char text[100];
    int a, b, i;
    printf("Enter the plaintext (uppercase): ");
    scanf("%s", text);
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);
    if (gcd(a, 26) != 1)
    {
        printf("Invalid value of a! It must be coprime with 26.\n");
        return 0;
    }
    printf("Encrypted Text: ");
    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            char ch = toupper(text[i]);
            int p = ch - 'A';
            int c = (a * p + b) % 26;
            printf("%c", c + 'A');
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    return 0;
}
