#include <stdio.h>

void copy_str(char copy[],char original[]);


int main(int argc, char const *argv[]){

    char original[] = "eita string original aqui mlk";
    char copy[60];
    copy_str(copy,original);
    printf("%s",copy);
    return 0;
}

void copy_str(char copy[],char original[]){
    char* copy_index = copy;
    char* index = original;
    do{
        *copy_index = *index;
        index++;
        copy_index++;
    } while ( *index != '\0');
    *copy_index = '\0';
}
