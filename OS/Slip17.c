/*
Q.1 Write the simulation program for demand paging and show the page scheduling and total number of page 
faults according the Optimal page replacement algorithm. Assume the memory of n frames.
Reference String : 7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6,
*/
#include<stdio.h>
int main()
{
    int fr,np,frames[10],pages[30],temp[10],flag1,flag2,flag3;
    int i,j,k,pos,max,faults=0;
    printf("Enter number of frames: ");
    scanf("%d",&fr);
    
    printf("Enter number of pages: ");
    scanf("%d", &np);
    
    printf("Enter page reference string: ");
    for(i=0;i<np;++i)
    {
      scanf("%d",&pages[i]);
    }
    for(i = 0; i < fr; ++i)
    {
      frames[i] = -1;
    }
    printf("\n-------Page Frames--------\n ");
    printf("\nFr1\tFr2\tFr3\n");
    printf("\n------------------------------------");
    for(i=0;i<np;++i)
    {
      flag1=flag2=0;
      for(j=0;j<fr;++j)
      {
        if(frames[j] == pages[i])
        {
          flag1=flag2=1;
          break;
        }
      }
      if(flag1 == 0)
      {
        for(j=0;j<fr;++j)
        {
            if(frames[j] == -1)
            {
              faults++;
              frames[j]=pages[i];
              flag2 = 1;
              break;
            }
        }    
      }        
      if(flag2 == 0)
      {
        flag3 =0;
        for(j=0;j<fr;++j)
        {
          temp[j]=-1;
          for(k=i+1;k<np;++k)
          {
            if(frames[j]==pages[k])
            {
            	temp[j] = k;              
            	break;
            }
          }
        }
        for(j=0;j<fr;++j)
        {
          if(temp[j]==-1)
          {
            pos = j;
            flag3 = 1;
            break;
          }
        } 
        if(flag3==0)
        {
          max=temp[0];
          pos=0;
          for(j=1;j<fr;++j)
          {
            if(temp[j]>max)
            {
            	max = temp[j];
            	pos = j;
            }
          }            	
        }	
		    frames[pos]=pages[i];
		    faults++;
      }
      printf("\n");
      for(j = 0; j < fr; ++j)
      {
        printf("%d\t", frames[j]);
      }
    }
    printf("\n------------------------------------");
    int hit=np-faults;
    printf("\n\nTotal Page Faults = %d",faults);
    printf("\n\nTotal Page Hits = %d",hit);  
    return 0;
}
/*
Q.2 Write the program to simulate FCFS CPU-scheduling. The arrival time and first CPU-burst of different 
jobs should be input to the system.Accept no. of Processes,arrival time and burst time.The output should 
give Gantt chart,turnaround time and waiting time for each process. Also find the average 
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
