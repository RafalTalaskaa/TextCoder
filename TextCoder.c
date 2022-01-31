#include <stdio.h> 
int main(){
    int mode = 1;
    
    switch(mode){
        case 1 : decryptCaesar();
        break;
        case 2 : encryptCaesar();
        break;

    
    }



}
void encryptCaesar(){

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

void decryptCaesar(){
    
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