/*
Q.1 Write a C program to implement the shell. It should display the command prompt “myshell$”. Tokenize 
sthe command line and execute the given command by creating the child process. Additionally it should
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
Q.2 Write the program to simulate preemptive Shortest Job First (SJF)scheduling. The arrival time and first
CPU-burst of different jobs should be input to the system. Accept no. of Processes, arrival time and burst
time. The output should give Gantt chart, turnaround time and waiting time for each process.Also find the
average waiting time and turnaround time
*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
     int i,n,j;
     printf("\n Enter number of processes : ");
     scanf("%d",&n);
     int at[n],bt[n],rt[n],ct,small,remain=0,time,temp;
     float avwt=0,avatat=0;  
     for (i=0;i<n;i++)
     { 
        printf("\n Enter arival time for process  %d:  ",i+1);
        scanf("%d",&at[i]);    
     }        
     for (i=0;i<n;i++)
     {
        printf("\n\n Enter burst time for processs %d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];        
     }     
     printf("\n pro\tat\tbt\twt\ttat ");
     for(time=0;remain != n;time++)
     {
        for(i=0;i<n;i++)
        {
          if(at[i] <= time && rt[i])
            small=i;
        }
          rt[small]--;
          if(rt[small]==0)
          {
            remain++;
            ct=time+1;
            printf("\n P%d\t%d\t%d\t%d\t%d",small+1,at[small],bt[small],ct-bt[small]-at[small],ct-at[small]);
            avatat=avatat+ ct-at[small];
            avwt=avwt+ct-bt[small]-at[small];         
          }       
      }
      avwt/=n;
      avatat/=n;
      printf("\n Average waiting time : %f ",avwt);
      printf("\n Average turn around  time : %f \n",avatat);         
}
