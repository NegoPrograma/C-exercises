    
#include <stdio.h>
#include <stdlib.h>

typedef struct orders{
    int osNumber;
    float price;
    char clientName[50];
    int orderType;
}Orders;

int main(int argc, char const *argv[]){
    int i=0;
    int orderQuantity;
    Orders* orders;
    float highestPrice, averagePrice = 0;
    scanf("%d",&orderQuantity);
    orders = (Orders*) malloc(sizeof(Orders)*orderQuantity);
    for (; i < orderQuantity; i++){
        scanf("%d",&orders[i].osNumber);
        scanf("%d",&orders[i].orderType);
        scanf("%s",orders[i].clientName);
        scanf("%f",&orders[i].price);
        if(i == 0 ||  orders[i].price > highestPrice)
            highestPrice = orders[i].price;
        averagePrice += orders[i].price;            
    }
    averagePrice = averagePrice/orderQuantity;
    printf(" preço médio: %f\n",averagePrice);
    for (i=0; i < orderQuantity; i++){
        if(orders[i].price > averagePrice){       
            printf("Este cliente pagou acima da média: %s\n",orders[i].clientName);
            if(orders[i].price == highestPrice)
                printf("Este cliente não só pagou acima da média, como pagou o valor mais caro.\n");
            }
    }
    
    
    return 0;
}
