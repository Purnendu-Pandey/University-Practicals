/*
Q.1 Write the simulation program for demand paging and show the page scheduling and total number of page 
faults according the LRU page replacement algorithm. Assume the memory of n frames.
Reference String : 3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6 
*/
#include<stdio.h>
struct frame 
{
    int pno;
    int counter;
}
frames [5];
int ref_str[30];
int np, n, i, j, currtime;

int pagefound(int pno1) 
{
    int i;
    for (i = 0; i < n; i++)
        if (frames[i].pno == pno1)
            return i;
    return -1;
}
int get_lru() 
{
    int min = 0;
    for (i=0;i<n;i++)
        if (frames[i].counter<frames[min].counter)
            min=i;
    return min;
}
int main() 
{
    int i,j,pno1,p,page_fault=0,flag,cnt=0;
    float hr,mr;
    printf("\n Enter how many frames: ");
    scanf("%d", &n);
    printf("\n Enter  length of referencestring: ");
    scanf("%d", &np);
    int len=np;
    printf("\n Enter referencestring: ");
    for (i=0;i<np;i++)
        scanf("%d", & ref_str[i]);
    for (i=0;i<n;i++) 
    {
        frames[i].pno=-1;
        frames[i].counter=-1;
    }
    printf("\n Page No.\tFrames\t\tPage Fault");
    printf("\n-------------------------------------------------");
    currtime=1;
    for (p=0;p<np;p++) 
    {
        flag=0;
        pno1=ref_str[p];
        j=pagefound(pno1);
        if (j==-1) 
        {
            page_fault++;
            j=get_lru();
            frames[j].pno=pno1;
            flag=1;
        }
        frames[j].counter = currtime;
        currtime++;
        printf("\n %5d \t", pno1);
        for (i=0;i<n;i++)
            printf("    %d",frames[i]);

        if (flag==1)
            printf(" \t  YES");
        else 
        {
            printf(" \t  NO");
            cnt++;
        }
    }
    printf("\n----------------------------------------------");
    printf("\nNo. of page fault: %d ", page_fault);
    printf("\nNo. of page Hits: %d ", cnt);
}
/*
Q.2 Write a C program to simulate FCFS CPU-scheduling. The arrival time and first CPU-burst of different
jobs should be input to the system. Accept no. of Processes, arrival time and burst time. The output
should give Gantt chart,turnaround time and waiting time for each process. Also find the average 
waiting time and turnaround time.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int n;
    printf("Enter the Number of proceses:");
    scanf("%d",&n);
    int at[n],bt[n],wt[n],tat[n],ct[n];
    float wtavg=0,tatavg=0;
    srand(time(NULL));
	for(int i=0; i<n; i++)	
    {
    printf("Arrival time for process %d:",i+1);
  	scanf("%d",&at[i]);
								
	printf("Fist burst time for process %d:",i+1);
	scanf("%d",&bt[i]);
	}
    ct[0]=at[0]+bt[0]+2;
	for(int i=1; i<n; i++)
	{
		int io_delay=(at[i]>ct[i-1]) ? at[i]-ct[i-1]:0;
		ct[i]=ct[i-1]+io_delay+bt[i];
	}
	for(int i=0; i<n; i++)
	{
	    int io_delay=(at[i]>ct[i-1])?at[i]-ct[i-1]:0;
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i]-io_delay;
		wtavg+=wt[i];
		tatavg+=tat[i];
	}
	wtavg/=n;
	tatavg/=n;
    printf("Gantt chart:\n");
	for(int i=0; i<n; i++)
	{
		printf("P%d\t",i+1);
	}
	printf("\n");
	for(int i=0; i<n; i++)
	{
		printf("%d\t",at[i]);	
	}
	printf("%d\n",ct[n-1]);
	printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");
	for(int i=0; i<n; i++)
	{
		printf("p%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],wt[i],tat[i]);
	}
	printf("Average Waiting time:%.2f\nAverage Turn around time:%.2f",wtavg,tatavg);
	return 0;
}
