#include <stdio.h>
#include <string.h>
#include <ctype.h>
char keyTable[5][5];
void generateKeyTable()
{
    char key[] = "MONARCHY";
    char alphabet[] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; 
    int used[26] = {0};
    int i, j, k = 0;
    used['J' - 'A'] = 1;
    for (i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);
        if (!used[ch - 'A'])
        {
            keyTable[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
    for (i = 0; alphabet[i] != '\0'; i++)
    {
        char ch = alphabet[i];
        if (!used[ch - 'A'])
        {
            keyTable[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
}
void findPosition(char ch, int *row, int *col)
{
    int i, j;
    if (ch == 'J')
        ch = 'I';
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (keyTable[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
int main()
{
    char text[100];
    int i, r1, c1, r2, c2;
    generateKeyTable();
    printf("Playfair Key Matrix:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%c %c %c %c %c\n",
               keyTable[i][0], keyTable[i][1],
               keyTable[i][2], keyTable[i][3],
               keyTable[i][4]);
    }
    printf("\nEnter plaintext (even number of letters): ");
    scanf("%s", text);
    for (i = 0; text[i] != '\0'; i += 2)
    {
        char a = toupper(text[i]);
        char b = toupper(text[i + 1]);

        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);
        if (r1 == r2)
        {
            printf("%c%c",
                   keyTable[r1][(c1 + 1) % 5],
                   keyTable[r2][(c2 + 1) % 5]);
        }
        else if (c1 == c2)
        {
            printf("%c%c",
                   keyTable[(r1 + 1) % 5][c1],
                   keyTable[(r2 + 1) % 5][c2]);
        }
        else
        {
            printf("%c%c",
                   keyTable[r1][c2],
                   keyTable[r2][c1]);
        }
    }
    return 0;
}
