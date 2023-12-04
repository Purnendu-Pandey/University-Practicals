/*
Q.1 Write the simulation program for demand paging and show the page scheduling and total number of page
faults according the MRU page replacement algorithm. Assume the memory of n frames.
Reference String : 8, 5, 7, 8, 5, 7, 2, 3, 7, 3, 5, 9, 4, 6, 2 
*/
#include <stdio.h>
int MRU(int time[],int f) 
{
    int max=time[0],pos=0;
    for (int i=1;i<f;i++)
    {
        if (max<time[i]) 
        {
            max=time[i];
            pos=i;
        }
    }
    return pos;
}
int main() 
{
    int n,f,rs[100],time[20],frame[20],flag1,flag2,fault=0,hit=0;

    printf("Enter Size of Reference String: ");
    scanf("%d", &n);

    printf("Enter Reference String:");
    for (int i = 0; i < n; i++) 
    {
      scanf("%d", &rs[i]);
    }

    printf("Enter Frame Size: ");
    scanf("%d", &f);

    for (int i = 0; i < f; i++)
    {
      frame[i] = -1;
      time[i] = -1; // Initialize time to -1
    }

    for (int i=0;i<n;i++) 
    {
        flag1=flag2=0;

        for (int j=0;j<f;j++) 
        {
            if (frame[j] == rs[i])
            {
                hit++;
                flag1=flag2=1;
                time[j]=i+1;
                break;
            }
        }
	  if(flag1==0)
	  {
		    for(int j=0; j<f; j++)
		    {
			      if(frame[j]==-1)
			      {
				      flag2=1;
				      frame[j]=rs[i];
				      fault++;
				      time[j]=i+1;
				      break;
			      }
		    }
	  }
    if (flag2 == 0)
    {
      int pos = MRU(time, f);
      frame[pos] = rs[i];
      time[pos] = i+1;
      fault++;
    }
    printf("\n");
    for (int j=0;j<f;j++)
    {
      if(frame[j]!=-1)
      {
        printf("%d\t", frame[j]);
      }
      else
      {
        printf("-\t");
      }
    }
    }
    printf("\nNo of Page Faults: %d\nNo of Page Hits: %d", fault, hit);
    return 0;
}
/*
Q.2 Write a programto implement the shell. It should display the command prompt “myshell$”. Tokenize the
command line and execute the given command by creating the child process. Additionally it should interpret
the following commands. 
myshell$ search f filename pattern :- To display first occurrence of pattern in the file.
myshell$ search a filename pattern :- To search all the occurrence of pattern in the file
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