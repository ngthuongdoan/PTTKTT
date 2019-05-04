#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int a[]={500000,200000,100000,50000,20000,10000};
    int withdraw;
    
    do
    {
        printf("Withdraw: ");
        scanf("%d", &withdraw);
        if (!(withdraw>10000 && withdraw%10000==0))
        {
            printf("Wrong input!\n");
        }
        
    } while (!(withdraw>10000 && withdraw%10000==0));
    
        
        int count = 0;
        for (int i = 0; i < 6; i++)
        {
            int temp=withdraw/a[i];
            printf("We got %d  %d dong\n", temp, a[i]);
            withdraw-=(a[i]*temp);
            count+=temp;
        }
        printf("Total: %d", count);
    
    return 0;
}
