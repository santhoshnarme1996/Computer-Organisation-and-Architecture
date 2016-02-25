#include<stdio.h>
void dectohex(int num);

void main()
{    
	int a,b,sum,product;
	
	/*For accepting the first integer and to convert the decimal no. into hexadecimal equivalent*/
	printf("\nEnter the first integer:");
	scanf("%d",&a);
    printf("\nThe equivalent hexadecimal number is:");
	dectohex(a);

	/*For accepting the first integer and to convert the decimal no. into hexadecimal equivalent*/
	printf("\n\nEnter the second integer:");
	scanf("%d",&b);
    printf("\nThe equivalent hexadecimal number is:");
	dectohex(b);
	    
	/*Performing the addition of the two integers*/    
	sum=a+b;
	/*Performing the multiplication of the two integers*/
	product=a*b;
	/*Displaying the Addition of the numbers in hexadecimal format*/
	printf("\n\nThe sum of the two integers in hexadecimal is:");
	dectohex(sum);
	/*Displaying the Product of the numbers in hexadecimal format*/
	printf("\n\nThe product of the two integers in hexadecimal is:");
	dectohex(product);/*calling the fuction to convert the decimal to hexadecimal*/ 
	printf("\n");
}//End of main

void dectohex(int num)/*Function for converting the decimal to hexadecimal equivalent*/
{
	int i=0,rem[100],len=0;
    while(num>0)/*While loop for storing the number by taking the mod in each iteration by 16 (base of hexadecimal)*/
	{
		rem[i]=num%16;
		num=num/16;
		i++;
		len++;
	}//End of while loop

	for(i=len-1;i>=0;i--)/*For loop for converting the numerals in the range from 10-15 and to hexadecimal equivalent and display them*/
	{
		switch(rem[i])//Switch case to convert the numerals from 10-15 to A-F
		{
			
			case 10:
			printf("A");
			break;

			case 11:
			printf("B");
			break;

            case 12:
			printf("C");
			break;

			case 13:
			printf("D");
			break;

			case 14:
			printf("E");
			break;

			case 15:
			printf("F");
			break;

			default:
			printf("%d",rem[i]);
		}
	}//End of for loop
}//End of dectohex function

		       
