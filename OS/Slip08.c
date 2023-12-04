/*Q.1 Write the simulation program for demand paging and show the page scheduling and total number of
page faults according the LRU page replacement algorithm. Assume the memory of n frames.
Reference String : 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2 
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
Q.2 Write a programto implement the shell. It should display the command prompt “myshell$”. Tokenize 
the command line and execute the given command by creating the child process. Additionally it should 
interpret the following commands. 
myshell$ search f filename pattern :- To display first occurrence of pattern in the file.
myshell$ search c filename pattern :- To count the number of occurrence of pattern in the file. 
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