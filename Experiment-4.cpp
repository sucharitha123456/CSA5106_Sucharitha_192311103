#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char plaintext[100], key[100], ciphertext[100];
    int i, j = 0;
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    printf("Enter the key: ");
    scanf("%s", key);
    int keyLen = strlen(key);
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char p = toupper(plaintext[i]);
            char k = toupper(key[j % keyLen]);

            ciphertext[i] = ((p - 'A' + k - 'A') % 26) + 'A';
            j++;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
    printf("Encrypted Text: %s\n", ciphertext);
    return 0;
}
