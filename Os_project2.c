#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int i,j;
void prime(int n)
{

int k = 3;
if ( n >= 1 )
   {
      printf("First %d prime numbers are :\n",n);
      printf("\n");
   }
  for (i=2;i<=n;)
   {
      for (j=2;j<=k-1;j++)
      {
         if (k%j==0)
            break;
      }
      if (j==k)
      {
         printf("%d\n", k);
         i++;
      }
      k++;
   }
}
int main()
{
	pthread_t p;
	int a;
	int n,g=0,r=0,b[10],m,ready_queue[10],id[10],waiting_time[10],turnaround_time[10],arrival_time[10],burst_time[10],TimeQuantum=3;
    printf("Enter number of processes");
	scanf("%d",&n);
	int temp=n;
	for(i=0;i<n;i++)
	{
		id[i]=i;
		printf("Enter Arrival time for process P%d ",i+1);
		scanf("%d",&arrival_time[i]);
		printf("\nEnter Burst time for process P%d ",i+1);
		scanf("%d",&burst_time[i]);
	}
	for(i=0;i<n;i++)
	{
		b[i]=burst_time[i];
	}
	int k=0;
	while(1)
	{
		int d=1;
		for(i=0;i<n;i++)
		{
			if(b[i]>0)
			{
				d=0;
				if(b[i]>TimeQuantum)
				{
					k=k+TimeQuantum;
					b[i]=b[i]-TimeQuantum;
				}
				else
				{
					k=k+b[i];
					waiting_time[i]=k-b[i];
					b[i]=0;
				}
			}
		}
		if(d==1)
		{
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		if(waiting_time[i]==0)
		{
			ready_queue[i]=id[i];
		}
	}
	printf("Waiting time\n");
	for(i=0;i<n;i++)
	{
	printf("P%d ",i+1);
	printf("%d\n",waiting_time[i]);
}
for(i=0;i<n;i++)
{
	turnaround_time[i]=burst_time[i]+waiting_time[i];
}
printf("Turnaround Time\n");
for(i=0;i<n;i++)
{
	printf("P%d ",i+1);
	printf("%d\n",turnaround_time[i]);
}
for(i=0;i<n;i++)
{
	r=r+waiting_time[i];
	g=g+turnaround_time[i];	
}
printf("Average Waiting Time\n");
printf("%f",(float)r/(float)n);
printf("\nAverage Turnaround Time\n");
printf("%f",(float)g/(float)n);
printf("\nSecond Iteration.....\n");
TimeQuantum=6;
for(i=0;i<n;i++)
{
	if(waiting_time[i]!=0)
	{
	while(1)
	{
		int d=1;
		for(i=0;i<n;i++)
		{
			if(b[i]>0)
			{
				d=0;
				if(b[i]>TimeQuantum)
				{
					k=k+TimeQuantum;
					b[i]=b[i]-TimeQuantum;
				}
				else
				{
					k=k+b[i];
					waiting_time[i]=k-b[i];
					b[i]=0;
				}
			}
		}
		if(d==1)
		{
			break;
		}
	}
}
}
for(i=0;i<n;i++)
{
	if(waiting_time[i]==0)
	{
		ready_queue[i]=id[i];
	}
}
printf("\nLast Iteration....\n");
for(i=0;i<n;i++)
{
	if(burst_time[i]!=0)
	{
		m=burst_time[i];
	}
}
if(m!=0)
{
	for(i=0;i<n;i++)
	{
		if(burst_time[i]<m && burst_time[i]!=0)
		{
		TimeQuantum=m;
	}
}
while(1)
	{
		int d=1;
		for(i=0;i<n;i++)
		{
			if(b[i]>0)
			{
				d=0;
				if(b[i]>TimeQuantum)
				{
					k=k+TimeQuantum;
					b[i]=b[i]-TimeQuantum;
				}
				else
				{
					k=k+b[i];
					waiting_time[i]=k-b[i];
					b[i]=0;
				}
			}
		}
		if(d==1)
		{
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		if(waiting_time[i]==0)
		{
			ready_queue[i]=id[i];
		}
	}
}
printf("\nIterations are done and all processes are in ready queue\n");
printf("\n******************* PRIME NUMBER*****************************\n");
printf("Enter the number of prime numbers required\n");
scanf("%d",&a);
pthread_create(&p,NULL,prime,a);
pthread_join(p,NULL);
}
