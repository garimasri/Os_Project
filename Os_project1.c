#include<stdio.h>
int col=5,row=4;
int i,j;
int main()
{
int process[5]={0,1,2,3,4};
int allocation[5][4]={{0,0,1,2},{1,0,0,0},{1,3,5,4},{0,6,3,2},{0,0,1,4}};
int available[4]={1,5,2,0};
int max[5][4]={{0,0,1,2},{1,7,5,6},{2,3,5,6},{0,6,5,2},{0,6,5,6}};
int need[5][4];
for(i=0;i<col;i++)
{
for(j=0;j<row;j++)
{
need[i][j]=max[i][j]-allocation[i][j];
}
}
display(allocation,max,process,available,need);
Find_Safe_Sequence(process,available,allocation,max,need);
}
void display(int allocation[col][row],int max[col][row],int process[col],int available[row],int need[col][row])
{
printf("PROCESS\n");
printf("P\n");
for(i=0;i<col;i++)
{
printf("%d\n",process[i]);
}
printf("\nMAXIMUM\n");
printf("A B C D\t\n");
for(i=0;i<col;i++)
{
for(j=0;j<row;j++)
{
printf("%d ",max[i][j]);
}
printf("\n");
}
printf("\nALLOCATION\n");
printf("A B C D\t\n");
for(i=0;i<col;i++)
{
for(j=0;j<row;j++)
{
printf("%d ",allocation[i][j]);
}
printf("\n");
}
printf("\nNEED=[MAXIMUM-AVAILABLE]\n");
printf("A B C D\t\n");
for(i=0;i<col;i++)
{
for(j=0;j<row;j++)
{
printf("%d ",need[i][j]);
}
printf("\n");
}
printf("\nAVAILABLE\n");
printf("A B C D\t\n");
for(j=0;j<row;j++)
{
printf("%d ",available[j]);
}
}

void Find_Safe_Sequence(int process[col],int available[row],int allocation[col][row],int max[col][row],int need[col][row])
{
int a;
int finish[5]={0,0,0,0,0};
int Safe_seq[col], work[row];
for(a=0;a<row;a++)
{
work[a]=available[a];
}
int c=0;
while(c<col)
{
int find=0;
for(i=0;i<col;i++)
{
if(finish[i]==0)
{
for(j=0;j<row;j++)
{
if(need[i][j]>work[j])
{
break;
}
}
int k;
if(j==row)
{
for(k=0;k<row;k++)
{ 
work[k]=work[k]+allocation[i][k];
}
Safe_seq[c++]=i;
finish[i]=1;
find=1;
}
}
}
if(find==0)
{
printf("\nSystem is not safe\n");
break;
}
}
printf("\nSystem is Safe\nSafe Sequence is:P=>");
for(i=0;i<col;i++)
{
printf("%d ",Safe_seq[i]);
}
}



