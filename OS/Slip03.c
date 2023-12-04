/*
Q.1 Write the simulation program to implement demand paging and show the page scheduling and total number
of page faults according to the LRU (using counter method)page replacement algorithm Assume the memory of n 
frames. Reference String : 3,5,7,2,5,1,2,3,1,3,5,3,1,6,2 
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
Q.2 Write a program to implement the toy shell. It should display the command prompt “myshell$”. Tokenize
the command line and execute the given command by creating the child process. Additionally it should
interpret the following commands. 
count c filename :- To print number of characters in the file.
count w filename :- To print number of words in the file.
count l filename :- To print number of lines in the file.
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void maketoks(char *s,char*tok[])
{
	int i=0;
	char *p;
	p=strtok(s,"  ");
	while(p!=NULL)
	{ 
	    tok[i++]=p;
	    p=strtok(NULL,"   ");
	}
	tok[i]=NULL;
}
void count(char *fn,char op)
{
	int fh,cc=0,wc=0,lc=0;
	char c;
	fh=open(fn,O_RDONLY);
	if(fh==-1)
	{
	  printf("Files %s not found \n",fn);
	  return;
	}
	while(read(fh,&c,1>0))
	{
	   if(c==' ')
	     wc++;
	   else if(c=='\n')
           { 
             wc++;
             lc++;
           }
           cc++;
        }
        close(fh);
        switch(op)
        {
          case 'c':
                 printf("Number of character :%d\n",cc-1);
                 break;
          case 'w':
                 printf("Number of words :%d\n",wc);
                 break;
          case 'l':
                 printf("Number of lines :%d\n",lc+1);
                 break;
        }
}
void main()
{
       char buff[80],*args[10];
       int pid;
       while(1)
       {
          printf("myshell$");
          fflush(stdin);
          fgets(buff,80,stdin);
          buff[strlen(buff)-1]='\0';
          maketoks(buff,args);
          if(strcmp(args[0],"count")==0)
             count(args[2],args[1][0]);
          else
          {
              pid=fork();
              if(pid>0)
                wait();
              else
              {
                  if(execvp(args[0],args)==-1)
                     printf("Bad Command");
              }
           }
         }
}
