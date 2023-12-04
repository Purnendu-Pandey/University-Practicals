/*
Q.1 Write a C program to accept n integers to be sorted. Main function creates child process using fork
system call. Parent process sorts the integers using bubble sort and waits for child process using wait
system call. Child process sorts the integers using insertion sort. [15]
*/
#include<stdio.h> 
#include<unistd.h>
//#include<sys/wait.h>
int n, a[10];
void bubble();
void insertion();
int main()
{
    int i;
    printf("Enter the array size : ");
    scanf("%d",&n);
    
    printf("Enter the elements : ");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    int pid=fork();
    if (pid==0)
    {
       printf("Child process id %d\n",getpid());
       insertion();
       printf("The array elements are :");
       for (i=0;i<n;i++)
           printf(" %d ",a[i]);
       printf("\n");
    }
    else
    {
       wait(NULL);
       printf("Parent process id %d\n",getppid());
       bubble();
       printf("The array elements are :");
       for (i=0;i<n;i++)
           printf(" %d ",a[i]);
       printf("\n");
    }
}
void bubble()
{
     int i,j,temp;
     for (i=0;i<n;i++)
     {
         for (j=i+1;j<n;j++)
         {
             if (a[i]>a[j])
             {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
             }
         }
     }
}
void insertion()
{
     int i,j,k;
     for (i=1;i<n;i++)
     {
         k=a[i];
         j=j-1;
         while (j>=0 && a[j]>k)
         {
               a[j+1]=a[j];
               j--;
         }
         a[j+1]=k;
     }
} 

/* 
Q.2 Write a C program to implement the toy shell. It should display the command prompt “myshell$”. 
Tokenize the command line and execute the given command by creating the child process. Additionally 
it should interpret the following commands. 
count c filename :- To print number of characters in the file.
count w filename :- To print number of words in the file.
count l filename :- To print number of lines in the file. [15]
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
