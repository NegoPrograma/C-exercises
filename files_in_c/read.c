#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE* file;
    file = fopen("read.txt","r");
    if (!file) {
        printf("coe lek deu merda");
        return -1;
    }
    
    int a,b,c;

    //aparentemente o fscanf() da um split e pega as informações por espaço
    fscanf(file, "%d %d %d",&a,&b,&c);
    printf("%d%d%d",a,b,c);
    
    return 0;
}
