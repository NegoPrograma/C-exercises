#include <stdio.h>
#include <stdlib.h>

void merge(char* arq1, char* arq2){
    FILE* final;
    final = fopen("merge.txt","w");
    FILE* f1 = fopen(arq1,"rt");
    FILE* f2 = fopen(arq2,"rt");
    if(!f1 || !f2) exit(1);
    int n1,n2,r1,r2,equal;
    r1 = fscanf(f1,"%d",&n1);
    r2 = fscanf(f2,"%d",&n2);
    while(r1 > 0 || r2 > 0){
         if((r1 < 1) || (n2 < n1)){
            fprintf(final,"%d ",n2);
            r2 = fscanf(f2,"%d",&n2);
        }else if((r2 < 1) || (n1 < n2)){
            fprintf(final,"%d ",n1);
            r1 = fscanf(f1,"%d",&n1);
        }else{
            equal = n1;
            fprintf(final,"%d ",equal);
            while(n1 == equal && r1 > 0) r1 = fscanf(f1,"%d",&n1);
            while(n2 == equal && r2 > 0) r2 = fscanf(f2,"%d",&n2);
        }
    }
    fclose(final);
    fclose(f1);
    fclose(f2);
}

int main(int argc, char const *argv[]){
    merge("merge1.txt","merge2.txt"); 

    return 0;
}
