/*Program On Own Encryption*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SIZE 50

void encrypt(char plain[], char encrypted[], int key, int len, int n)
{
	int i,j,x,posx,posy;
	char c;
	posx=n-len;
	
	for(i=posx,j=0;i<=n-1,j<=len-1;i++,j++)
	{
		encrypted[i]=plain[(j+key)%len];
	}
	
	for(i=0;i<posx;i++)
	{
		x=(rand()%25)+97;;
		c=x;
		encrypted[i]=c;
	}
	
	printf("\nEncrypted Text : %s",encrypted);
} 

void decryption(char encrypted[], int key, int n)
{
	int i,j,posx,len,x;
	len=n-key;
	posx=key;
	char decrypt[len],str[len],c;
	
	
	for(j=0,i=posx;i<n,j<len;i++,j++)
	{
		decrypt[j]=encrypted[i];
	}
	decrypt[i-1]='\0';
	 
	x=len-key;
	for(i=0;i<len;i++)
	{
		str[i]=decrypt[(i+x)%len];
	}
	
	printf("\nPlain Text Is : ");
	for(i=0;i<len;i++)
		printf("%c",str[i]);	
}

int main()
{
	char plain[SIZE],encrypted[SIZE];
	int key=5;
	int n,len;
	
	printf("\nEnter the plain text : ");
	scanf("%s",plain);
	
	printf("\nPlain Text Entered : %s",plain);
	printf("\nKey Is : %d",key);
	
	len=strlen(plain);
	n=key+len;
	
	encrypt(plain,encrypted,key,len,n);
	decryption(encrypted,key,n);
	
	return 0;
}
/*
OUTPUT:
Enter the plain text : chinmayparalkar

Plain Text Entered : chinmayparalkar
Key Is : 5
Encrypted Text : qrjatayparalkarchinm
Plain Text Is : chinmayparalkar
*/
