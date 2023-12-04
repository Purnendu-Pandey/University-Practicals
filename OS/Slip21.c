/*
Q.1 Write a C Program to create a child process using fork (), display parent and  child process id.
Child process will display the message “I am Child Process” and the parent process should display 
“I am Parent Process”. [15] 
*/
#include<stdio.h>
#include<sys/types.h>
void ChildProcess();
void ParentProcess();
int main()
{
	 pid_t pid;
	 pid=fork();
	 if (pid==0)
	    ChildProcess(pid);
	 else
	    if (pid>0)
	    ParentProcess(pid);
	 else
	    printf("unsuccessful");  
}
	 void ChildProcess(int pid)
	 { 
	    printf("\n I Am Child Process");
	    printf("\n My ID : %d",getpid());
	    printf("\n My Parent Id :%d",getppid());
	 }
	 void ParentProcess(int pid)
	 {
	    printf("\n I Am Parent Processs");
	    printf("\n My ID : %d",getpid());
	    printf("\n My Parent Id : %d\n",getppid());
	 }
/*
Q.2 Write a C program to simulate Preemptive Priority scheduling. The arrival time and first CPU-burst and
priority for different n number of processes should be input to the algorithm. Assume the fixed IO 
waiting time (2 units). The next CPU-burst should be generated randomly. The output should give Gantt chart,
turnaround time and waiting time for each process. Also find the average waiting time and turnaround time.
*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i,n,j;
	float avwt=0,avtat=0;
	
	printf("Enter the numbere of process :");
	scanf("%d",&n);
	int p[n],pr[n],at[n],bt[n],wt[n],tat[n],ct[n],t[n],tt[n];
	
	printf("Enter the process :");
	for(i=0;i<n;i++)
      scanf("%d",&p[i]);
           
  printf("Enter the priority :");
	for(i=0;i<n;i++)
	{
    scanf("%d",&pr[i]);
  }         
  printf("Enter the burst time :");
	for(i=0;i<n;i++)
	{
    scanf("%d",&bt[i]);
    t[i]=bt[i];
  }  
  printf("\n Enter arrival time :");
  for(i=0;i<n;i++)
	{
    scanf("%d",&bt[i]);
    tt[i]=at[i];
  }  
  printf("\n Before Shorting :\n");
  printf("\npro\tpr\tat\tbt :\n");
  for(i=0;i<n;i++)
  {
    printf("\np[%d]\t%d\t%d\t%d\n",p[i],pr[i],at[i],bt[i]);
  }
  for(i=0;i<n;i++)
    for(j=1+1;j<n;j++)
    {
      if((pr[i]>pr[j]) && at[i]==0)
      {
        int temp=pr[i];
        pr[i]=pr[j];
        pr[j]=temp;
                     
        temp=bt[i];
        bt[i]=bt[j];
        bt[j]=temp;
                     
        temp=at[i];
        at[i]=at[j];
        at[j]=temp;
      }
    }
	  int start[n];
	  start[0]=0;
	  for(i=1;i<n;i++)
	  {
	    start[i]=start[i-1]+bt[i-1];
	  }        
    for(i=0;i<n;i++)
    {
      wt[i]=start[i]-tt[i];
      avwt==wt[i];
    }
    avwt/=n;
    for(i=0;i<n;i++)
	  {
	    tat[i]=wt[i]+t[i];
	    ct[i]=tat[i]+tt[i];
	    avtat+=tat[i];
	  }
	  avtat/=n;
	  printf("\npro\tpri\tat\tbt\twt\ttat \n");
	  for(i=0;i<n;i++)
	  {
	    printf("\np[%d]\t%d\t%d\t%d\t%d\t%d\n",p[i],pr[i],at[i],bt[i],wt[i],tat[i]);
	  }
	  printf("Average Waiting Time :%2f\n",avwt);
    printf("Average Turnaround Time :%2f\n",avtat); 
}