/*
Q.1 Write a C program to implement the shell. It should display the command prompt “myshell$”. Tokenize
the command line and execute the given command by creating the child process. Additionally it should
interpret the following ‘list’ commands as 
myshell$ list f dirname :- To print names of all the files in current directory.
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
void make_toks(char *s, char *tok[])
{
     int i=0;
     char *p;

     p=strtok(s," ");
     while(p!=NULL)
     {
       tok[i++]=p;
       p=strtok(NULL," ");
     }
      tok[i]=NULL;
}
void list(char *dn, char op)
{
     DIR *dp;
     struct dirent *entry;
     int dc=0,fc=0;

    dp=opendir(".");
    if(dp==NULL)
    {
      printf("Dir %s not found.\n",dn);
      return;
    }
    switch(op)
    {
         case 'f':
                 while(entry=readdir(dp))
                 {
                    if(entry->d_type==DT_REG)
                    printf("%s\n",entry->d_name);
                 }
                 break;
        case 'n':
                while(entry=readdir(dp))
                {
                   if(entry->d_type==DT_DIR) 
                   dc++;
                   if(entry->d_type==DT_REG) 
                   fc++;
                }
                printf("%d Dir(s)\t%d File(s)\n",dc,fc);
                break;
       case 'i':
               while(entry=readdir(dp))
               {
                  if(entry->d_type==DT_REG)
                  printf("%s\t%d\n",entry->d_name,entry->d_fileno);
               }
    }
    closedir(dp);
}
int main()
{
       char buff[80],*args[10];
       int pid;
       while(1)
       {
          printf("myshell$");
  	      fflush(stdin);
   	      fgets(buff,80,stdin);
  	      buff[strlen(buff)-1]='\0';
          make_toks(buff,args);
          
          if(strcmp(args[0],"list")==0)
             list(args[2],args[1][0]);
          else
          {
            pid = fork();
            if(pid>0)
              wait();
            else
             {
                if(execvp(args[0],args)==-1)
                printf("Bad command.\n");
             }
          }
       }
       return 0; 
}

/*
Q.2 Write the simulation program for Round Robin scheduling for given time quantum. The arrival time and
first CPU-burst of different jobs should be input to the system. Accept no. of Processes, arrival time
and burst time. The output should give the Gantt chart, turnaround time and waiting time for each process.
Also display the average turnaround time and average waiting time.
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