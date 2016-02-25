#include<stdio.h>
#include<string.h>
void RightShift(int A[],int Q[],int cnt,int c);
void Display(int A[],int Q[]);
void AddBin(int A[],int M[], int cnt, int c);
void SubBin(int A[],int M[],int cnt, int c);
signed int M[10],Q[10],A[10];
char Multiplicand[100],Multiplier[100];
void main()
{
	int cnt=0,n,b,a,m,i,j,c=0,count=0,QQ=0;
	printf("\nEnter no.of bits in Multiplicand:");
	scanf("%d",&cnt);
	printf("\nEnter the bits one by one");	
	for(i=0;i<cnt;i++)
	scanf("%d",&M[i]);

	printf("\nEnter no.of bits in Multiplier:");
	scanf("%d",&c);
	printf("\nEnter the bits one by one");	
	for(i=0;i<c;i++)
	scanf("%d",&Q[i]);

	
	/*while(Multiplicand!='\0')
	{
		cnt++;//counting no.of digits in Multiplicand
	}
	while(Multiplier!='\0')
	{
		c++;//counting no.of digits in Multiplier
	}*/



	for(i=0;i<cnt;i++)
	A[i]=0;//assigning A as 0(size of A = M) 
	/*for(i=0;i<cnt;i++)
	{
		M[i]=(int)Multiplicand[i];
		printf(" %d",M[i]);
	}
	for(i=0;i<c;i++)
	{
		Q[i]=(int)Multiplier[i];
		printf(" %d",Q[i]);
	}*/
	Q[c]=0;
	printf("\n");
		printf(" A       Q     Q-1       M\n\n");
		for(j=0;j<cnt;j++)
		printf("%d",A[j]);
		printf("\t");
		for(j=0;j<c;j++)
		printf("%d",Q[j]);
		printf("\t%d",Q[c]);
		printf("\t");		
		for(j=0;j<cnt;j++)
		printf("%d",M[j]);
		printf("\n");
	    
		/*RightShift(A,Q,cnt,c);	
		for(j=0;j<cnt;j++)
		printf("%d",A[j]);
		printf("\t");
		for(j=0;j<c;j++)
		printf("%d",Q[j]);
		printf("\t%d",Q[c]);
		printf("\t");		
		for(j=0;j<cnt;j++)
		printf("%d",M[j]);
		printf("\n");	
	
		AddBin(A,M,cnt);
		for(j=0;j<cnt;j++)
		printf("%d",A[j]);
		printf("\t");
		for(j=0;j<c;j++)
		printf("%d",Q[j]);
		printf("\t%d",Q[c]);
		printf("\t");		
		for(j=0;j<cnt;j++)
		printf("%d",M[j]);
		printf("\n");		
		
		SubBin(A,M,cnt);
		for(j=0;j<cnt;j++)
		printf("%d",A[j]);
		printf("\t");
		for(j=0;j<c;j++)
		printf("%d",Q[j]);
		printf("\t%d",Q[c]);
		printf("\t");		
		for(j=0;j<cnt;j++)
		printf("%d",M[j]);
		printf("\n");*/		
	while(count!=0)
	{
		for(i=c-1;i<=c;i++)
		{	
			QQ=(QQ*10)+Q[i];
		}
		//printf("%d",QQ);
		if(QQ==00)
		{		
			RightShift(A,Q,cnt,c);
		}		
		else if(QQ==11)
		{		
			RightShift(A,Q,cnt,c);
		}
		else if(QQ==10)
		{		
			AddBin(A,Q,cnt,c);
			RightShift(A,Q,cnt,c);		
		}
		else if(QQ==01)
		{		
			SubBin(A,Q,cnt,c);
			RightShift(A,Q,cnt,c);
		}
		count--;
	}
}

void RightShift(int A[10], int Q[10], int cnt, int c)
{
	int j,i,temp1[20],temp2[20];
	for(i=0;i<cnt;i++)
		temp1[i]=A[i];
	for(j=0;j<c+1;j++)
		temp2[j]=Q[j];
	for(i=1;i<cnt;i++)
		A[i]=temp1[i-1];	
	for(j=1;j<c+1;j++)
		Q[j]=temp2[j-1];
	Q[0]=temp1[cnt-1];
	
	for(j=0;j<cnt;j++)
		printf("%d",A[j]);
		printf("\t");
		for(j=0;j<c;j++)
		printf("%d",Q[j]);
		printf("\t%d",Q[c]);
		printf("\t");		
		for(j=0;j<cnt;j++)
		printf("%d",M[j]);
		printf("\n");	
	

	/*for(i=0;i<cnt;i++)
		printf(" %d",A[i]);
	printf("\n");
	for(j=0;j<c;j++)
		printf("%d",Q[j]);
	printf(" %d",Q[c]);*/
}

void AddBin(int A[20],int M[20],int cnt,int c)
{
	int i=0,rem =0,sum[20],j;
	for(i=0;i<20;i++)
	sum[i]=0;
	for(i=cnt-1;i>=0;i--)
	{
	 	sum[i]=(A[i]+M[i]+rem)%2;
		//printf(" %d",sum[i]);
	    rem=(A[i]+M[i]+rem)/2;
		//printf(" %d",rem);	
	}
	for(i=0;i<cnt;i++)
	A[i]=sum[i];	
	for(j=0;j<cnt;j++)
		printf("%d",A[j]);
		printf("\t");
		for(j=0;j<c;j++)
		printf("%d",Q[j]);
		printf("\t%d",Q[c]);
		printf("\t");		
		for(j=0;j<cnt;j++)
		printf("%d",M[j]);
		printf("\n");	
	
}
		
void SubBin(int A[],int M[],int cnt,int c)
{
	int i=0,rem1=0,rem2=0,sumM[20],M2[20],C[20],sum[20],j;
	for(i=0;i<cnt;i++)//for adding 1 after the 1's complement
	{
		if(i==cnt-1)
		C[i]=1;
		else
		C[i]=0;
	}	
	/*for(i=0;i<cnt;i++)
	printf(" %d",C[i]);*/
	for(i=0;i<20;i++)//sum array=0
	sum[i]=0;
	for(i=0;i<20;i++)//sumM array=0
	sumM[i]=0;
		
	for(i=cnt-1;i>=0;i--)//taking 1's complement
	{
		if(M[i]==0)
		M2[i]=1;
		else
		M2[i]=0;
	}
	/*for(i=0;i<cnt;i++)
	printf(" %d",M2[i]);*/
	for(i=cnt-1;i>=0;i--)//Finalising the 2's complement,Adding C[] and M2[]
	{
	 	sumM[i]=(C[i]+M2[i]+rem1)%2;
		//printf(" %d",sum[i]);
	    rem1=(C[i]+M2[i]+rem1)/2;
		//printf(" %d",rem);	
	}
	/*for(i=0;i<cnt;i++)
		printf(" %d",sumM[i]);*/
	
	for(i=cnt-1;i>=0;i--)//Finalising the addition of 2's complement and the A[],Adding A[] and sumM[]
	{
	 	sum[i]=(A[i]+sumM[i]+rem2)%2;
		//printf(" %d",sum[i]);
	    rem2=(A[i]+sumM[i]+rem2)/2;
		//printf(" %d",rem);	
	}
	
	
	for(i=0;i<cnt;i++)
	{
		A[i]=sum[i];
	}

	for(j=0;j<cnt;j++)
		printf("%d",A[j]);
		printf("\t");
		for(j=0;j<c;j++)
		printf("%d",Q[j]);
		printf("\t%d",Q[c]);
		printf("\t");		
		for(j=0;j<cnt;j++)
		printf("%d",M[j]);
		printf("\n");	
	
}


	
	
		
	

	

     
