/*
Q.1 Write a C program to illustrate the concept of orphan process. Parent process creates a child and 
terminates before child has finished its task. So child process becomes orphan process. 
(Use fork(), sleep(), getpid(), getppid()). [15]
*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
	pid_t child_pid;
	child_pid=fork();
	if(child_pid<0)
	{
	  perror("fork error");
	  exit(1);
	}
	 else if(child_pid==0)
	 {
	    printf("\n Child Process");
	    printf("\n PID :%d",getpid());
	    printf("\n Parent PID :%d",getppid());
	    printf("\n Child process is sleeping For 5sec");
	    sleep(5);
	    printf("\n Child process is completed...");
	 }
	 else
	 {
	    printf("\n Parent Process");
	    printf("\n PID :%d\n",getpid());
	    printf("\n Parent PId :%d",getppid());
	    printf("\n Child process is Terminated...");
	 }
	 return 0;  
}

/*
Q.2 Write the simulation program for demand paging and show the page scheduling and total number of page
faults according the Optimal page replacement algorithm. Assume the memory of n frames.
Reference String : 7, 5, 4, 8, 5, 7, 2, 3, 1, 3, 5, 9, 4, 6, [15]
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