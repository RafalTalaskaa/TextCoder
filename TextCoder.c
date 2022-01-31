#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    int mode;
    int i;
    printf("Szyfrowanie Cezara - 1\nOdszyfrowywanie Cezara - 2\nSzyfrowanie Afiniczne - 3\nOdszyfrowywanie Afiniczne - 4\nSzyforwanie Morsa - 5\nOdszyfrowywanie Morsa - 6\n");
    scanf("%d", &mode);
    getchar();

    switch (mode)
    {
    case 1:
        encryptCaesar();
        break;
    case 2:
        decryptCaesar();
        break;
    case 3:
        encryptAffine();
        break;
    case 4:
        decryptAffine();
        break;
    case 5:
        encryptMorse();
        break;
    case 6:
        decryptMorse();
        break;
    }
}
void decryptMorse()
{
    char *input[100];
    char *morseAlpha[100];

    FILE *fp;
    fp = fopen("C:\\Users\\rafal\\Documents\\GitHub\\TextCoder\\morse.txt", "r");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fgets(input, 100, fp);
    fclose(fp);

    morseAlpha[0] = ".-";
    morseAlpha[1] = "-...";
    morseAlpha[2] = "-.-.";
    morseAlpha[3] = "-..";
    morseAlpha[4] = "."; //E
    morseAlpha[5] = "..-.";
    morseAlpha[6] = "--.";
    morseAlpha[7] = "....";
    morseAlpha[8] = "..";
    morseAlpha[9] = ".---"; //J
    morseAlpha[10] = "-.-";
    morseAlpha[11] = ".-..";
    morseAlpha[12] = "--";
    morseAlpha[13] = "-.";
    morseAlpha[14] = "---"; //O
    morseAlpha[15] = ".--.";
    morseAlpha[16] = "--.-";
    morseAlpha[17] = ".-.";
    morseAlpha[18] = "...";
    morseAlpha[19] = "-"; //T
    morseAlpha[20] = "..-";
    morseAlpha[21] = "...-";
    morseAlpha[22] = ".--";
    morseAlpha[23] = "-..-";
    morseAlpha[24] = "-.--"; //Y
    morseAlpha[25] = "--.-";
    morseAlpha[26] = " ";
    char *normalAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ-";

    int i;
    for (i = 0; i < 26; i++)
    {
        if (strcmp(input, morseAlpha[i]) == 0)
        {
            printf("%c", normalAlpha[i]);
        }
    }
}

void encryptMorse()
{
    int i;
    int j = 0;
    char input[100];
    char inputMorse[100];
    FILE *fp;
    fp = fopen("C:\\Users\\rafal\\Documents\\GitHub\\TextCoder\\message.txt", "r");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fgets(input, sizeof(input), fp);
    fclose(fp);

    for (int i = 0; i <= strlen(input); i++)
    {
        switch (toupper(input[i]))
        {
        case 'A':
            inputMorse[j++] = '.';
            inputMorse[j++] = '-';
            inputMorse[j] = ' ';
            break;

        case 'B':
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j] = ' ';
            break;

        case 'C':
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j] = ' ';
            break;

        case 'D':
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j] = ' ';
            break;

        case 'E':
            inputMorse[j++] = '.';
            inputMorse[j] = ' ';
            break;

        case 'F':
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j] = ' ';
            break;

        case 'G':
            inputMorse[j++] = '-';
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j] = ' ';
            break;

        case 'H':
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j] = ' ';
            break;

        case 'I':
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j] = ' ';
            break;

        case 'J':
            inputMorse[j++] = '.';
            inputMorse[j++] = '-';
            inputMorse[j++] = '-';
            inputMorse[j++] = '-';
            inputMorse[j] = ' ';
            break;

        case 'K':
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j++] = '-';
            inputMorse[j] = ' ';
            break;

        case 'L':
            inputMorse[j++] = '.';
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j] = ' ';
            break;

        case 'M':
            inputMorse[j++] = '-';
            inputMorse[j++] = '-';
            inputMorse[j] = ' ';
            break;

        case 'N':
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j] = ' ';
            break;

        case 'O':
            inputMorse[j++] = '-';
            inputMorse[j++] = '-';
            inputMorse[j++] = '-';
            inputMorse[j] = ' ';
            break;

        case 'P':
            inputMorse[j++] = '.';
            inputMorse[j++] = '-';
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j] = ' ';
            break;

        case 'Q':
            inputMorse[j++] = '-';
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j++] = '-';
            inputMorse[j] = ' ';
            break;

        case 'R':
            inputMorse[j++] = '.';
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j] = ' ';
            break;

        case 'S':
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j] = ' ';
            break;

        case 'T':
            inputMorse[j++] = '-';
            inputMorse[j] = ' ';
            break;

        case 'U':
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j++] = '-';
            inputMorse[j] = ' ';
            break;

        case 'V':
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j++] = '-';
            inputMorse[j] = ' ';
            break;

        case 'W':
            inputMorse[j++] = '.';
            inputMorse[j++] = '-';
            inputMorse[j++] = '-';
            inputMorse[j] = ' ';
            break;

        case 'X':
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j++] = '-';
            inputMorse[j] = ' ';
            break;

        case 'y':
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j++] = '-';
            inputMorse[j++] = '-';
            inputMorse[j] = ' ';
            break;

        case 'Z':
            inputMorse[j++] = '-';
            inputMorse[j++] = '-';
            inputMorse[j++] = '.';
            inputMorse[j++] = '.';
            inputMorse[j] = ' ';
            break;

        case ' ':
            inputMorse[j++] = ' ';
            inputMorse[j++] = ' ';
            inputMorse[j++] = ' ';
            inputMorse[j] = ' ';
            break;
        }

        j++;
    }

    puts(inputMorse);
}

void encryptAffine()
{

    int i, j, k, gcd, key, key2;
    int numInput[100], numCipher[100];
    char input[100], cipher[100];
    char *str = malloc(sizeof(char) * 100);
    FILE *fp;
    fp = fopen("C:\\Users\\rafal\\Documents\\GitHub\\TextCoder\\message.txt", "r");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fgets(input, sizeof(input), fp);

    fclose(fp);

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

void decryptAffine()
{
    int i, j, k, gcd, key, key2, keyInverse;
    int numInput[100], numCipher[100];
    char input[100], cipher[100];
    FILE *fp;
    fp = fopen("C:\\Users\\rafal\\Documents\\GitHub\\TextCoder\\message.txt", "r");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fgets(input, sizeof(input), fp);

    fclose(fp);

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

    keyInverse = inverseKey(key);
    printf("Odwrócony klucz to:%d \n", keyInverse);
    printf("Odszyfrowane afinicznie słowo to: \n");
    for (i = 0; i < strlen(input); i++)
    {
        if (numInput[i] != -20)
        {
            numCipher[i] = (keyInverse * (numInput[i] - key2)) % 26;
            if (numCipher[i] < 0)
            {
                numCipher[i] = numCipher[i] + 26;
            }
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

int inverseKey(int key)
{
    int i, inverse;
    for (i = 1; i <= key; i++)
    {
        inverse = ((i * 26) + 1);
        if (inverse % key == 0)
        {
            break;
        }
    }
    inverse = inverse / key;
    return (inverse);
}

void encryptCaesar()
{

    char input[100];
    char temp;
    int i, j, key;

    FILE *fp;
    FILE *fp2;
    fp = fopen("C:\\Users\\rafal\\Documents\\GitHub\\TextCoder\\message.txt", "r");
    fp2 = fopen("C:\\Users\\rafal\\Documents\\GitHub\\TextCoder\\savecypher.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fgets(input, sizeof(input), fp);

    fclose(fp);
    printf("Podaj klucz: ");
    scanf("%d", &key);
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
    for (i = 0; input[i] != '\0'; ++i)
    {
        temp = input[i];

        if (temp >= 'A' && temp <= 'Z')
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
    fputs(input,fp2);
}

void decryptCaesar()
{

    char input[100];
    char temp;
    int i, j, key;

    FILE *fp;
    fp = fopen("C:\\Users\\rafal\\Documents\\GitHub\\TextCoder\\savecypher.txt", "r");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fgets(input, sizeof(input), fp);

    fclose(fp);
    printf("Podaj klucz: ");
    scanf("%d", &key);

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

    for (i = 0; input[i] != '\0'; ++i)
    {
        temp = input[i];

        if (temp >= 'A' && temp <= 'Z')
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