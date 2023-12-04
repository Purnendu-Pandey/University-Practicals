/*
Q.1 Write a C program that demonstrates the use of nice() system call. After a child Process is started
using fork (), assign higher priority to the child using nice () system call.
*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
     int pid,r;
     pid=fork();
     for (int i=1;;i++)
     {
        if (pid==0)
        {
           r=nice(-20);
           printf("Child gets higher CPU priority %d \n",r);
           sleep(4);
           
        }
        else
        {
           r=nice(19);
           printf("Parent gets higher CPU priority %d \n",r);
           sleep(4);
        }
     }
}
/*
Q.2 Write a C program to simulate Non preemptive priority scheduling. The arrival time and first CPU-burst
of different jobs should be input to the system. Accept no. of Processes, arrival time and burst time.
The output should give Gantt chart, turnaround time and waiting time for each process. Also find the
average waiting time and turnaround time.
*/
#include<stdio.h>
#include<stdlib.h>
#define max 10

typedef struct process
{ 
  int pid,cpu_bt,pri,tat,wt,at;
}process;
void swap (process *a,process *b)
{
    process temp = * a;
    *a = *b ;
    *b = temp;
} 
void sort(process pro[],int n)
{ 
    for (int i=0;i<n-1;i++)
    {
      for (int j=0;j<n-i-1;j++)
      {
        if (pro[j].pri > pro[j+1].pri)
          swap(&pro[j],&pro[j+1]);
      }
    }
}  
void calculate_tat(process pro[],int n)
{
    int total_wt = 0,ttat=0;
    for (int i=0;i<n;i++)
    {
      pro[i].tat=pro[i].wt+pro[i].cpu_bt;
      total_wt+=pro[i].wt;
      ttat+=pro[i].tat;
    }
    double avwt = (double)total_wt/n;
    printf("\nAverage Waiting Time : %2f\n",avwt);
    printf("\nAverage TAT  : %2f\n",ttat);
}   
void calculate_wt(process pro[],int n)
{
        pro[0].wt=0;
        for (int i=1;i<n;i++)
            pro[i].wt=pro[i-1].wt+pro[i-1].cpu_bt;
}
void main()
{
     int n;
     process pro[max];
     
      printf("\nEnter The No of Processes :\n");
      scanf("%d",&n);
      for (int i=0;i<n;i++)
             pro[i].pid=i+1;
      printf("enter priority of process : \n");
      for (int i=0;i<n;i++)
          scanf("%d",&pro[i].pri);
      
      printf("enter arrival time of process : \n");
      for (int i=0;i<n;i++)
          scanf("%d",&pro[i].at);
      
      printf("enter burst time of process : \n");
      for (int i=0;i<n;i++)
            scanf("%d",&pro[i].cpu_bt);

      sort(pro,n);
      calculate_wt(pro,n);
      calculate_tat(pro,n);
      printf("\n------GANTT CHART------\n");
      for (int i=0;i<n;i++) 
      {
        printf("P--->%d\t",pro[i].pid);
      }
      printf("\n");
      
      printf("\nPro\tAT\tBT\tPrio\tTAT\t WT\n");
      printf("------------------------------------------------");
      for (int i=0;i<n;i++)
      printf("\nP[%d]\t %d\t %d\t %d\t %d\t %d\n",i+1,pro[i].at,pro[i].cpu_bt,pro[i].pri,pro[i].tat,pro[i].wt);
      printf("----------------------------------------------");         
}
