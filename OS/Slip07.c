/*
Q.1 Write the simulation program for demand paging and show the page scheduling and total number of 
page faults according the Optimal page replacement algorithm. Assume the memory of n frames.
Reference String : 7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6, 2 [15]
*/
#include<stdio.h>
int main()
{
    int fr,np,frames[10],pages[30],temp[10],flag1,flag2,flag3;
    int i,j,k,pos,max,faults=0;
    printf("Enter number of frames: ");
    scanf("%d",&fr);
    
    printf("Enter number of pages: ");
    scanf("%d", &np);
    
    printf("Enter page reference string: ");
    for(i=0;i<np;++i)
    {
      scanf("%d",&pages[i]);
    }
    for(i = 0; i < fr; ++i)
    {
      frames[i] = -1;
    }
    printf("\n-------Page Frames--------\n ");
    printf("\nFr1\tFr2\tFr3\n");
    printf("\n------------------------------------");
    for(i=0;i<np;++i)
    {
      flag1=flag2=0;
      for(j=0;j<fr;++j)
      {
        if(frames[j] == pages[i])
        {
          flag1=flag2=1;
          break;
        }
      }
      if(flag1 == 0)
      {
        for(j=0;j<fr;++j)
        {
            if(frames[j] == -1)
            {
              faults++;
              frames[j]=pages[i];
              flag2 = 1;
              break;
            }
        }    
      }        
      if(flag2 == 0)
      {
        flag3 =0;
        for(j=0;j<fr;++j)
        {
          temp[j]=-1;
          for(k=i+1;k<np;++k)
          {
            if(frames[j]==pages[k])
            {
            	temp[j] = k;              
            	break;
            }
          }
        }
        for(j=0;j<fr;++j)
        {
          if(temp[j]==-1)
          {
            pos = j;
            flag3 = 1;
            break;
          }
        } 
        if(flag3==0)
        {
          max=temp[0];
          pos=0;
          for(j=1;j<fr;++j)
          {
            if(temp[j]>max)
            {
            	max = temp[j];
            	pos = j;
            }
          }            	
        }	
		    frames[pos]=pages[i];
		    faults++;
      }
      printf("\n");
      for(j = 0; j < fr; ++j)
      {
        printf("%d\t", frames[j]);
      }
    }
    printf("\n------------------------------------");
    int hit=np-faults;
    printf("\n\nTotal Page Faults = %d",faults);
    printf("\n\nTotal Page Hits = %d",hit);  
    return 0;
}
/*
Q.2 Write a program to implement shell. It should display the command prompt “myshell$”. Tokenize the
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