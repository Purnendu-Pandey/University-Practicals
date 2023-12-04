/*
Q.1 Write a C program that accepts an integer array. Main function forks child process. Parent process
sorts an integer array and passes the sorted array to child process through the command line arguments 
of execve() system call.The child process uses execve() system call to load new program that uses this
sorted array for performing the binary search to search the particular item in the array. [15]
*/
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#define max 100
void bubblesort(int arr[],int n)
{
      int i,j,temp;
      for(i=0;i<n;i++)
        for(j=0;j<n-1;j++)
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
}
int main(int argc,char *argv[])
{
        int n,i,arr[max];
        printf("Enter the size of array element :");
        scanf("%d",&n);
        printf("Enter the elements in array :");
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
            pid_t pid=fork();

            if (pid < 0)
            {
                printf("Forking Faild");
                return 1;
            }
            else if(pid==0)
            {
              sleep(5);
              execv("./ex2",argv);
            }
            else
            { 
                  wait(NULL);
                  bubblesort(arr,n);
                  printf("\n Sorted Element using bubble sort by process :");
                  for (int i=0;i<n;i++)
                      printf("%5d",arr[i]);
                  printf("\n");
            }
            return 0;
}


/*
Q.2 Write a programto implement the shell. It should display the command prompt “myshell$”. Tokenize the
command line and execute the given command by creating the child process. Additionally it should interpret 
the following commands. 
myshell$ search f filename pattern :- To display first occurrence of pattern in the file. [15]
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void make_toks(char *s, char *tok[])
{
    int i=0;
    char *p;

    p=strtok(s, " ");
    while (p!=NULL)
    {
        tok[i++]=p;
        p=strtok(NULL," ");
    }
    tok[i]=NULL;
}
void search(char *fn, char op, char *pattern)
{
    int fh,count=0,i=0,j=0;
    char buff[255],c,*p;

    fh=open(fn,O_RDONLY);
    if (fh==-1)
    {
        printf("File %s Not Found\n", fn);
        return;
    }
    switch(op) 
    {
        case 'f':
            while (read(fh,&c,1))
            {
                buff[j++]=c;
                if (c=='\n')
                {
                    buff[j]='\0';
                    j=0;
                    i++;
                    if (strstr(buff,pattern))
                    {
                        printf("%d: %s",i,buff);
                        break;
                    }
                }
            }
            break;
        case 'c':
            while (read(fh,&c,1))
            {
                buff[j++]=c;
                if (c=='\n')
                {
                    buff[j]='\0';
                    j=0;
                    p=buff;
                    while (p=strstr(p,pattern))
                    {
                        count++;
                        p++;
                    }
                }
            }
            printf("Total No.of Occurrences = %d\n", count);
            break;
        case 'a':
            while (read(fh,&c,1))
            {
                buff[j++]=c;
                if (c=='\n') 
                {
                    buff[j]='\0';
                    j=0;
                    i++;
                    if (strstr(buff,pattern))
                        printf("%d: %s",i,buff);
                }
            }
            break;
    }
    close(fh);
}
int main()
{
    char buff[80], *args[10];
    int pid;

    while (1)
    {
        printf("myshell$");
        fflush(stdin);
        fgets(buff,80,stdin);
        buff[strlen(buff)-1]='\0';
        make_toks(buff,args);
        if (strcmp(args[0],"search")==0)
            search(args[3],args[1][0],args[2]);
        else
        {
            pid=fork();
            if (pid>0)
                wait();
            else
            {
                if (execvp(args[0],args)==-1)
                    printf("Bad command.\n");
            }
        }
    }
    return 0;
}