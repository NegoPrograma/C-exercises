#include <stdio.h>

void copy_content(FILE* original,FILE* copy);


int main(void){
    FILE* original = fopen("string.txt","r");
    FILE* copy = fopen("copy_string.txt","w");
    copy_content(original,copy);
    fclose(original);
    fclose(copy);
    return 0;
}

void copy_content(FILE* original,FILE* copy){
    char line[100];
    while(fgets(line,100,original)!= NULL){
        fprintf(copy,line);

    }
}
