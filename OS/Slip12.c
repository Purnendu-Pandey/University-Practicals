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
Q.2 Write a program to implement the shell. It should display the command prompt “myshell$”. Tokenize 
the command line and execute the given command by creating the child process. Additionally it should 
interpret the following ‘list’ commands as 
myshell$ list f dirname :- To print names of all the files in current directory.
myshell$ list n dirname :- To print the number of all entries in the current directory 
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
