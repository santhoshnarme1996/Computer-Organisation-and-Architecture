#include<stdio.h>

int BinaryMultiplicaion(int a,int b);

void main()
{
long int bin1,bin2,multiply=0;
int digit,factor=1;

printf("\nEnter the first Binary number : ");
scanf("%ld",&bin1);
printf("\nEnter the second Binary number : ");
scanf("%ld",&bin2);

while(bin2!=0)
{
	digit = bin2%10;
   	if(digit ==1)
    {
    	bin1=bin1*factor;
        multiply = BinaryMultiplicaion(bin1,multiply);
    }
    else
       	bin1=bin1*factor;
            
        bin2 = bin2/10;
        factor = 10;
}
printf("\nProduct of two binary numbers: %ld\n",multiply);
}

int BinaryMultiplicaion(int bin1,int bin2)
{
int i=0,rem = 0,sum[20];
int prod=0;

while(bin1!=0||bin2!=0)
{
 	sum[i++] =  ((bin1 % 10) + (bin2 % 10) + rem ) % 2;
    rem = ((bin1 % 10) + (bin2 % 10) + rem ) / 2;
    bin1 = bin1/10;
    bin2 = bin2/10;
}

if(rem!=0)
    sum[i++] = rem;
    --i;
    
while(i>=0)
   	prod = prod*10 + sum[i--];

return prod;
}
