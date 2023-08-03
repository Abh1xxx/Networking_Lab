#include<stdio.h>
#define inf 9999
struct table
{ int dist[10];
int from[10];
}rt[10];
void main()
{ int n,e,start,en,cost,i,j,k,c;
//int costmat[10][10];
printf("Enter the number of nodes : ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{ for(j=1;j<=n;j++)
rt[i].dist[j]=inf;
rt[i].dist[i]=0;
rt[i].from[i]=i;
}
printf("Enter the number of connections : ");
scanf("%d",&e);
printf("Node Number should start from 1\nStartNode EndNode Cost\n");
for(i=1;i<=e;i++)
{ scanf("%d%d%d",&start,&en,&cost);
// costmat[start][en]=cost;
//costmat[en][start]=cost;
rt[start].dist[en]=cost;
rt[en].dist[start]=cost;
rt[start].from[en]=en;
rt[en].from[start]=start;
}
do
{
for(i=1;i<=n;i++)
{ c=0;
for(j=1;j<=n;j++)
for(k=1;k<=n;k++)
if(rt[i].dist[j]>rt[i].dist[k]+rt[k].dist[j])
{ rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
rt[i].from[j]=k;
c++;
}
}
}while(c>0);
for(i=1;i<=n;i++)
{ printf("\nRouting table %d\n",i);
for(j=1;j<=n;j++)
printf("node%d\t",j);
printf("\n");
for(j=1;j<=n;j++)
printf("dist%d\t",rt[i].dist[j]);
printf("\n");
for(j=1;j<=n;j++)
printf("via%d\t",rt[i].from[j]);
}
}