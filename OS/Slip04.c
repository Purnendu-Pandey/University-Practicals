/*
Q.1 Write the simulation program for demand paging and show the page scheduling and total number of page 
faults according the MFU page replacement algorithm. Assume the memory of n frames.
Reference String : 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2 
*/
#include<stdio.h>
struct frame
{
    int pno;
    int freq;
} 
	frames [5];
	int ref_str[30];
	int np,n,i,j,frequency,currtime;

int pagefound (int pno1)
{
  	int i;
  	for(i=0;i<n;i++)
      if (frames[i].pno==pno1)
       return i;
       return -1;
}
int free_fr()
{
    for(i=0; i<n; i++)
        if (frames[i].pno==-1)
            return i;
    return -1;
}
int get_mfu()
{
    int max=0;
    for(i=0; i<n; i++)
        if(frames[i].freq > frames[max].freq)
            max=i;
    return max;
}
int main()
{
    int i,j,pno1,p,page_fault=0, flag,cnt=0;;
    float hr,mr;
    printf("\n Enter how many frames: ");
    scanf("%d",&n);
    printf("\n Enter  length of referencestring: ");
    scanf("%d",&np);
    int len=np;
    printf("\n Enter referencestring: ");
    for(i=0; i<np; i++)
        scanf("%d",&ref_str[i]);

    for(i=0; i<n; i++)
    {
        frames[i].pno=-1;
        frames[i].freq=0;
    }
    printf("\n Page No.\tFrames \t\tPage Fault");
    printf("\n------------------------------- ");
    currtime=1;
    for (p=0; p<np; p++)
    {
        flag=0;
        frequency=0;
        pno1=ref_str[p];
        j=pagefound (pno1);
        if(j==-1)
        {
            page_fault++;
            j=free_fr();
            if (j==-1)
                j=get_mfu();
            frames[j].pno=pno1;
            frames[j].freq=1;
            flag=1;
        }
        else
            frames[j].freq++;
        printf("\n%5d\t",pno1);
        for (i=0; i<n; i++)
            printf("  %d ", frames[i].pno);

        if(flag==1)
            printf("\t YES");
        else
        {
            printf("\t NO");
            cnt++;
        }
    }
    printf("\n-----------------------------------------------------------");
  
    printf("\nNo. of page fault: %d ",page_fault);
    printf("\nNo. of page Hits: %d ",cnt);
}


/*
Q.2 Write a program to implement the shell. It should display the command prompt “myshell$”. Tokenize the
command line and execute the given command by creating the child process. Additionally it should interpret
the following commands. 
myshell$ search a filename pattern :- To search all the occurrence of pattern in the file. 
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