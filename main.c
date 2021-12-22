#include<stdio.h>
#include<stdlib.h>

// Check if the character is Capital leter
int Maj(char c)
{
    return c>='A' && c<='Z' ? 1:0;
}
// check if lower-case leter
int Min(char c)
{
    return c>='a' && c <= 'z' ? 1 : 0;
}
// check if is a number
int Chiffre(char c)
{
    return c>='0' && c<='9' ? 1:0;
}
// Shifting based on d variable
char ShiftRight(char c,size_t d)
{
    if(Maj(c) == 1) return 'A' + (c-'A'+d)%26;
    if(Min(c) == 1) return 'a' + (c-'a'+d)%26;
    if(Chiffre(c) == 1) return '0' + (c-'0' + d ) %10;
    return c;
}

// décalage par le nombre demander
char ShiftLeft(char c,int d)
{
    if(Maj(c) == 1) return 'Z' - (c+'Z'-d)%26;
    if(Min(c) == 1) return 'z' - (c+'z'-d)%26;
    if(Chiffre(c) == 1) return '9' - (c+ '9' - d)%10;
    return c;
}


void ChiffrerFile(FILE *ft,FILE *fd,FILE *fr)
{
    int d,c;
    int ch;
    while(fscanf(fd,"%d",&d)!=EOF)
    {
        fprintf(fr,"Chiffrement %d \n",d);
        while((c=fgetc(ft))!=EOF)
        {
            ch = ShiftRight(c,d);
            fputc(ShiftRight(c,d),fr);
        }
        fprintf(fr,"\n********************\n");
        rewind(ft);
    }
}


int main(void)
{    
    FILE *ft,*fn,*fr;
    ft = fopen("text.txt","r");
    fn = fopen("nombre.txt","r");
    fr = fopen("textchiffrerb.txt","w");
    ChiffrerFile(ft,fn,fr);
    printf("%c \n",ShiftRight('9',2));
    return 0;
}
