#include<stdio.h>
#include<stdlib.h>
#define nodes 10
int n;

struct node
{
  int a[nodes][4];
}router[nodes];

void input()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		printf("\n");
		printf("enter the distance from %d node to all other nodes\n",i);
		printf("enter 999 if no direct path exists\n");
		for(j=1;j<=n;j++)
		{
				if(i!=j)
			{
				printf("enter distance to %d:",j);
				scanf("%d",&router[i].a[j][2]);
				//router[j].a[i][2]=router[i].a[j][2];
			}
				router[i].a[j][1]=j;
                                router[i].a[j][3]=i;

		}
	}
}

void dv_alg()
{
	int i,j,k,cnt,sum;
	do
	{
		cnt=0;
		 for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				for(k=1;k<=n;k++)
					if(router[i].a[j][2]>(sum=router[i].a[k][2]+router[k].a[j][2]))
					{
					router[i].a[j][2]=sum;
					router[i].a[j][3]=k;
					cnt++;
					}			
	}while(cnt!=0);
}

void display()
{
	int i,j,k;
	printf("\tdestination\tdistance\tnexthop\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(router[i].a[j][2]>=999)
				printf("\t%d\t\tno link\t\tno hop\n",router[i].a[j][3]);
			else
				printf("\t%d\t\t%d\t\t%d\n",router[i].a[j][1],router[i].a[j][2],router[i].a[j][3]);
		}
		printf("\n");
	}
}

int main()
{
	int i,j,x,y,ch;
	printf("enter no. of nodes\n");
	scanf("%d",&n);
	printf("\n");
	input();
	printf("initial configuration\n");
	display();
	dv_alg();
	printf("final config\n");
	display();
	while(1)
	{
		printf("enter 0 to exit  or 1 to continue\n");
		scanf("%d",&ch);
		if(ch!=1)
			break;
		printf("enter the nodes bw required path\n");
		scanf("%d%d",&x,&y);
		printf("length of shortest path is %d",router[x].a[y][2]);
		printf("\n");
	}	
	return 0;
}		
	
	

