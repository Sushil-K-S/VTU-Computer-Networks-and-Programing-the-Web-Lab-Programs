#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

char t[128],cs[128],g[10];

int a,l,c,n;

void xor(){

	for( c = 1 ; c < n ; c++ )
		cs[c] = ((cs[c] == g[c])?'0':'1');
}

void crc(){

	for( l = 0 ; l < n ; l++)
		cs[l] = t[l];
		
	do{
	
		if( cs[0] == '1' )
			xor();
			
		for( c = 0 ; c < n-1 ; c++ )
			cs[c] = cs[c+1];
			
		cs[c] = t[l++];
	}while(l <= a+n-1);
}

int main(){

	printf("\nEnter the polynomial : ");
	scanf("%s",t);
	
	printf("\nEnter generating polynomial : ");
	scanf("%s",g);
	
	n = strlen(g);
	a = strlen(t);
	
	for( l = a ; l < a+n-1 ; l++ )
		t[l] = '0';
		
	printf("\n Modified t[u] is %s ",t);
	
	crc();
	
	printf("\nChecksum is  %s",cs);
	
	for( l = a ; l < a+n ; l++ )
		t[l] = cs[l-a];
	
	printf("\nFinal codeword is %s\n",t);
	
	printf("\nTest error detection 0:yes , 1:no\n");
	scanf("%d",&l);
	
	if( l == 0 ){
		printf("\nEnter position where error is inserted\n");
		scanf("%d",&l);
		
		t[l] = (t[l] == '0')?'1':'0';
		
		printf("erroneous data : %s\n",t);
	}
	
	crc();
	
	for( l = 0 ; (l < n-1) && (cs[l]!='1'); l++);
	
	if( l < n-1 )
		printf("ERROR!!!\n");
	else
		printf("NO ERROR!!!\n");

	return 0;
}
