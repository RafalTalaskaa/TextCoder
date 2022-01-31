#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    int mode;
    printf("Odszyfrowanie Cezara - 1\nSzyfrowanie Cezara - 2\nSzyfrowanie Afiniczne - 3\nDeszyfrowanie Afiniczne - 4\n");
    scanf("%d", &mode);

    switch (mode)
    {
    case 1:
        decryptCaesar();
        break;
    case 2:
        encryptCaesar();
        break;
    case 3:
        encryptAffine();
        break;
    }
}

void encryptAffine()
{
    int i, j, k, gcd, key, key2, numInput[100], numCipher[100];
    char input[100], cipher[100];
    printf("Podaj słowo do zaszyforwaniaxd:\n");
    gets(input);

    for (i = 0, j = 0; i < strlen(input); i++)
    {
        if (input[i] != ' ')
        {
            input[j] = toupper(input[i]);
            j++;
        }
        else
        {
            input[j] = ' ';
            j++;
        }
    }
    input[j] = '\0';
    printf("Entered string is : %s \n", input);
    printf("Wprowadź klucz z przedziału od 1 do 25\n");
    scanf("%d", &key);
    
    if (key < 1 || key > 25)
    {
        printf("klucz powinien być z przedziału od 1 do 25\nSpróbuj ponownie\n");
        exit(0);
    }
    gcd = greatestCommonDivisor(key);
    if (gcd != 1)
    {
        printf("Nwd(key,26)=1 ,a Nwd(%d,26)=%d\nSpróbuj ponownie\n", key, gcd);
        exit(0);
    }
    printf("Wprowadź klucz 2 z przedziału od 0 do 25\n");
    scanf("%d", &key2);
    if (key2 < 0 || key2 > 25)
    {
        printf("klucz powinien być z przedziału od 0 do 25\nSpróbuj ponownie\n");
        exit(0);
    }
    

    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] != ' ')
            numInput[i] = input[i] - 'A';
        else
            numInput[i] = -20;
    }
    

    printf("Szyfr afiniczny słowa to: \n");
    for (i = 0; i < strlen(input); i++)
    {
        if (numInput[i] != -20)
        {
            numCipher[i] = ((key * numInput[i]) + key2) % 26;
            printf("%c", (numCipher[i] + 'A'));
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");
}

int greatestCommonDivisor(int key)
{
    int x;
    int temp1 = key;
    int temp2 = 26;

    while (temp2 != 0)
    {
        x = temp2;
        temp2 = temp1 % temp2;
        temp1 = x;
    }
    return (temp1);
}


void encryptCaesar()
{

    char input[100];
    char temp;
    int i, j, key;

    printf("Podaj słowo do zaszyforwania: ");
    scanf("%s", input);
    printf("Podaj klucz: ");
    scanf("%d", &key);
    for (i = 0; input[i] != '\0'; ++i)
    {
        temp = input[i];

        if (temp >= 'a' && temp <= 'z')
        {

            temp = temp + key;

            if (temp > 'z')
            {

                temp = temp - 'z' + 'a' - 1;
            }

            input[i] = temp;
        }
        else if (temp >= 'A' && temp <= 'Z')
        {

            temp = temp + key;

            if (temp > 'Z')
            {

                temp = temp - 'Z' + 'A' - 1;
            }

            input[i] = temp;
        }
    }
    printf("Zaszyfrowana wiadomość to: %s", input);
}

void decryptCaesar()
{

    char input[100];
    char temp;
    int i, j, key;

    printf("Podaj słowo do odszyforwania: ");
    scanf("%s", input);
    printf("Podaj klucz: ");
    scanf("%d", &key);
    for (i = 0; input[i] != '\0'; ++i)
    {
        temp = input[i];

        if (temp >= 'a' && temp <= 'z')
        {

            temp = temp - key;

            if (temp < 'a')
            {

                temp = temp + 'z' - 'a' + 1;
            }

            input[i] = temp;
        }
        else if (temp >= 'A' && temp <= 'Z')
        {

            temp = temp - key;

            if (temp < 'A')
            {

                temp = temp + 'Z' - 'A' + 1;
            }

            input[i] = temp;
        }
    }
    printf("Odszyfrowana wiadomość to: %s", input);
}