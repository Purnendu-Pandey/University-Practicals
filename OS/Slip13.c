/*
Q.1 Write a C program to implement the shell which displays the command prompt “myshell$”. It accepts 
the command, tokenize the command line and execute it by creating the child process. Also implement
the additional command ‘typeline’ as 
typeline -a filename :- To print all lines in the file.
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void make_toks(char *s, char *tok[])
{
   int i=0;
   char *p;

   p=strtok(s, " ");
   while (p!=NULL)
   {
      tok[i++]=p;
      p=strtok(NULL, " ");
   }
   tok[i]=NULL;
}
void typeline(char *fn, char *op)
{
   int fh,i,j,n;
   char c;

   fh=open(fn, O_RDONLY);
   if (fh==-1)
   {
      printf("File %s not found.\n", fn);
      return;
   }
   if (strcmp(op,"a")==0)
   {
        while (read(fh,&c,1)>0)
          printf("%c",c);
         close(fh);
         return;
   }
   n=atoi(op);
   if (n > 0)
   {
      i=0;
      while (read(fh,&c,1)>0)
      {
         printf("%c",c);
         if (c=='\n')
            i++;
         if (i==n)
            break;
      }
   }
   if (n<0)
   {
         i=0;
         while (read(fh,&c,1)>0)
         {
            if (c=='\n')
                i++;
         }
         lseek(fh,0,SEEK_SET);
         j=0;
         while (read(fh,&c,1)>0)
         {
            if (c=='\n')
                j++;
            if (j==i+n)
                break;
        }
        while (read(fh,&c,1)>0)
        {
            printf("%c",c);
        }
    }
    close(fh);
}
int main()
{
    char buff[80], *args[10];
    int pid;

    while(1)
    {
        printf("myshell$ ");
        fflush(stdin);
        fgets(buff,80,stdin);
        buff[strlen(buff)-1] ='\0';
        make_toks(buff,args);
        if (strcmp(args[0],"typeline")==0)
            typeline(args[2],args[1]);
        /*else
        {
            pid = fork();
            if (pid > 0)
                wait(NULL);
            else
            {
                if (execvp(args[0], args) == -1)
                    printf("Bad command.\n");
            }
        }*/
    }
    return 0;
}
/*
Q.2 Write the simulation program for Round Robin scheduling for given time quantum. The arrival time
and first CPU-burst of different jobs should be input to the system. Accept no. of Processes, arrival
time and burst time. The output should give the Gantt chart, turnaround time and waiting time for each 
process. Also display the average turnaround time and average waiting time.
*/
#include<stdio.h>
struct times
{
	int p,art,but,wtt,tat,rnt;
};
void sortart(struct times a[],int pro)
{
	int i,j;
	struct times temp;
	for(i=0;i<pro;i++)
	{
	   for(j=i+1;j<pro;j++)
	   {
	     if(a[i].art>a[j].art)
	     {
	       temp=a[i];
	       a[i]=a[j];
	       a[j]=temp;
	     }
	   }
	}
	return;
}
int main()
{
	int i,j,pro,time,remain,flag=0,ts;
	struct times a[100];
	float avgwt=0,avgtt=0;
	printf("Round Roubin Scheduling Algorithm \n");
	printf("Enter the number of process :");
	scanf("%d",&pro);
	remain=pro;
	for(i=0;i<pro;i++)
	{
	   printf("Enter arrival time for process:",i+1);
  	   scanf("%d",&a[i].art);

  	   printf("Enter burst time for the process:");
  	   scanf("%d",&a[i].but);
  	   a[i].p=i;
  	   a[i].rnt=a[i].but;
  	}
  	sortart(a,pro);
  	printf("Enter time quantum :");
  	scanf("%d",&ts);
  	printf("\n-----------------------------------------\n");
  	printf("Gantt chart \n");
  	printf("0");
  	   
  	for(time=0,i=0;remain!=0;)
  	{
	   if(a[i].rnt<=ts && a[i].rnt>0)
	   {
	      time=time+a[i].rnt;
	      printf("->[p%d]<-%d",a[i].p,time);
	      a[i].rnt=0;
	      flag=1;
	   }
	   else if(a[i].rnt>0)
	   {
	      a[i].rnt=a[i].rnt-ts;
	      time=time+ts;
	      printf("-->[p%d]<--%d",a[i].p,time);
	   }
	   if(a[i].rnt==0 && flag==1)
	   {
	   	remain--;
	   	a[i].tat=time-a[i].art;
	   	a[i].wtt=time-a[i].art-a[i].but;
	   	avgwt=avgwt+time-a[i].art-a[i].but;
	   	avgtt=avgtt+time-a[i].art;
	   	flag=0;
	   }
	   if(i==pro-1)
	      i=0;
	      else if(a[i+1].art<=time)
	         i++;
	      else
	         i=0;  	   
       }
       printf("\n\n");
       printf("\n-----------------------------------------\n");
       printf("PID \tAT \tBT \tTAT \tWT \n");
       printf("\n-----------------------------------------\n");
       for(i=0;i<pro;i++)
       {
          printf("P%d\t%d\t%d\t%d\t%d\n",a[i].p,a[i].art,a[i].but,a[i].tat,a[i].wtt);
       }
       printf("\n-----------------------------------------\n");
       avgwt=avgwt/pro;
       avgtt=avgtt/pro;
       printf("Average Waiting Time :%2f\n",avgtt);
       printf("Average Turnaround Time :%2f\n",avgwt); 
}