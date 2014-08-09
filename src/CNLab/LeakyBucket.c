#include<stdio.h>


int rand(int a){
	int rn = (random() % 10) % a;
	
	return rn == 0 ? 1 : rn;
}

int main(){

	int packet_sz[5], i , clk, b_size, o_rate, p_sz_rm = 0, p_sz,p_time;
	
	for( i = 0 ; i < 5 ; i++ )
		packet_sz[i] = rand(6) * 10;
		
	for( i = 0 ; i < 5 ; i++ )
		printf("\nPacket[%d] : %d bytes\t",i,packet_sz[i]);
		
	printf("\nEnter the output rate : ");
	scanf("%d",&o_rate);
	
	printf("\nEnter the Bucket Size : ");
	scanf("%d",&b_size);
	
	for( i = 0 ; i < 5 ; i++ ){
		
		if( ( packet_sz[i] + p_sz_rm )  > b_size )
			if( packet_sz[i] > b_size )
				printf("\nIncomming packet size (%d) is greater than bucket capacity - PACKET REJECTED",packet_sz[i]);
			else
				printf("\nBucket Capacity exceeded - REJECTED!!!");
		else{
		
			p_sz_rm += packet_sz[i];
			
			printf("\nIncomming packet size : %d",packet_sz[i]);
			printf("\nBytes remaining to Transmit : %d",p_sz_rm);
			
			p_time = rand(4) * 10;
			
			printf("\nTime left for transmission : %d units",p_time);
			
			for( clk = 10 ; clk <= p_time ; clk+=10 ){
			
				sleep(1);
				
				if( p_sz_rm ){
					if( p_sz_rm <= o_rate ){
					
						printf("\nPacket of size %d transmitted", p_sz_rm);
						p_sz_rm = 0;
					}else{
				
						printf("\nPacket of size %d transmitted",o_rate);
						p_sz_rm -= o_rate;
					
						printf("\n---Bytes Remaining after Transmission : %d",p_sz_rm);
					}
				}else{
					
					printf("\nNo packets to transmit");
					printf("\nTime left : %d",p_time - clk);
				}
			}
		
		}
			
	}
	
	return 0;
}
