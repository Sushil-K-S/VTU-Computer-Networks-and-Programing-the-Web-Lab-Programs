#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int gcd(long m,long n){

	long r;
	
	while( n != 0 ){
	
		r = m % n;
		
		m = n;
		
		n = r;
	}
	
	return m;
}

int main(){

	char msg[60];
	
	long p = 0 , q = 0 , n = 0, e = 0, d = 0 , phi = 0;
	
	long num[100] = {0};
	
	long enc[100] = {0}, dec[100] = {0};
	
	long i = 0 , j = 0 , nof = 0;
	
	printf("\nEnter the message to be enrypted : ");
	gets(msg);
	
	printf("\nEnter the value of p and q : ");
	scanf("%ld %ld",&p,&q);
	
	n = p * q;
	
	phi = (p-1)*(q-1);
	
	for( i = 2 ; i < phi ; i++ ){
	
		if(gcd(i,phi) == 1)
		break;
	}
	
	e = i;
	
	for( i = 2 ; i < phi ; i++ )
		if( (e*i-1)%phi == 0 )
			break;
			
	d = i;
	
	
	for( i = 0 ; i < strlen(msg);i++)
		num[i] = msg[i];
		
	nof = strlen(msg);
	
	for( i = 0 ; i < nof ; i++ ){
	
		enc[i] = 1;
		
		for( j = 0 ; j < e ; j++ )
			enc[i] = (enc[i] * num[i]) % n; 
	}
	
	printf("\nEncrypted msg is \n");
	
	for( i = 0 ; i < nof ; i++ )
		printf("%ld",enc[i]);
	
	for( i = 0 ; i < nof ; i++ ){
	
		dec[i] = 1;
		
		for( j = 0 ; j < d ; j++ )
			dec[i] = (dec[i] * enc[i]) % n; 
	}
	
	printf("\nDecrypted msg is \n");
	
	for( i = 0 ; i < nof ; i++ )
		printf("%c",(char)dec[i]);
		
	return 0;
}


