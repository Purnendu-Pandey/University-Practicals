/*
Q.1 Write the simulation program for demand paging and show the page scheduling and total number of
page faults according the FIFO page replacement algorithm. Assume the memory of n frames.
Reference String : 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2
*/
#include<stdio.h>
#include<stdlib.h>
struct fnode
{
    int pno;
};
struct fnode frames[10];
int fr;
int pagefound (int pno1)
{
    for (int i=0; i<fr; i++)
        if(frames[i].pno==pno1)
            return 1;
    return 0;
}
void main()
{
    int ref_str[30];
    int pfct=0,i,pno1, p, flag=0;
    int len,cnt=0;
    printf("\n Enter no. of frames: ");
    scanf("%d", &fr);
    printf("\n Enter length of referencestring: ");
    scanf("%d",&len);
    printf("\n Enter  referencestring: ");
    for (i=0; i<len; i++)
        scanf("%d",&ref_str[i]);

    for (i=0; i<fr; i++)
        frames[i].pno=-1;

    printf("\nPageNo\t  pageframes\t\tpagefault");

    printf("\n-----------------------------------------");
    for (p=0;p<len;p++)
    {
        pno1=ref_str[p];
        flag=0;

        if (pagefound (pno1)==0)
        {
            frames[pfct%fr].pno=pno1;
            pfct++;
            flag=1;
        }
        printf("\n %d \t",pno1);
        for (i=0; i<fr; i++)
            printf(" %d  ", frames[i]);

        if(flag==1)
            printf("\t  \t YES");
        else
        {
            printf("\t  \t  NO");
            cnt++;
        }
   }
   printf("\n-----------------------------------------");
   printf("\n Total No of page fault : %d", pfct);
   printf("\n Total No of page Hits : %d", cnt);
}

/*
Q.2 Write a program to implement the shell. It should display the command prompt “myshell$”. Tokenize 
the command line and execute the given command by creating the child process. Additionally it should
interpret the following commands. 
myshell$ search f filename pattern :- To display first occurrence of pattern in the file.
myshell$ search a filename pattern :- To search all the occurrence of pattern in the file. 
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