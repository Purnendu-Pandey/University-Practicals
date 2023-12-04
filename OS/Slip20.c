/*
Q.1 Write a C program to implement the shell which displays the command prompt “myshell$”. It accepts
the command, tokenize the command line and execute it by creating the child process. Also implement the 
additional command ‘typeline’ as 
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
Q.2 Write the program to simulate Non-preemptive Shortest Job First (SJF)scheduling. The arrival time and
first CPU-burst of different jobs should be input to the system. Accept no. of Processes, arrival time and
burst time. The output should give Gantt chart, turnaround time and waiting time for each process.
Also find the average waiting time and turnaround time
*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
     int i,n;
     float avwt=0,avgtat=0;
     printf("Enter no of process : \n");
     scanf("%d",&n);
     int p[n],at[n],bt[n],wt[n],tat[n];
     for (i=0;i<n;i++)
          p[i]=i;
     printf("enter arrival time : \n");
     for (i=0;i<n;i++)
         scanf("%d",&at[i]);
     printf("enter burst time : \n");
     for (i=0;i<n;i++)
         scanf("%d",&bt[i]);
     int temp,j;       
     
     
     for (i=1;i<n;i++)
      {   for (j=i+1;j<n;j++)
        {
          if(bt[i]>bt[j])
          {
             temp=bt[i];
             bt[i]=bt[j];
             bt[j]=temp;
             
             temp=p[i];
             p[i]=p[j];
             p[j]=temp;
             
             temp=at[i];
             at[i]=at[j];
             at[j]=temp;
          }
        }  
      } 
      int start[10];
      start[0]=0;
      for(i=1;i<n+1;i++)
      {
        start[i]=start[i-1]+bt[i-1];
        printf("\t %d",start[i]); 
      }   
      for(i=0;i<n;i++)
      {
        wt[i]=start[i]-at[i];         
        avwt+=wt[i];
        tat[i]=wt[i]+bt[i];
        avgtat+=tat[i];
      }
      avwt/=n;
      avgtat/=n;
      printf("\nPro \tAt\tBt\twt\ttat\n");
      for (i=0;i<n;i++)
      
      printf("\nP%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],wt[i],tat[i]);

      printf("\n Average waiting time : %f ",avwt);
      printf("\n Average turn around  time : %f \n",avgtat);    
}
