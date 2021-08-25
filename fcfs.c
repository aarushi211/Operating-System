#include<stdio.h>
 
 int main()
 
{
    int n,burst[20],wait[20],turnaround[20],avwait=0,avturnaround=0,i,j;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
 
    printf("\nEnter Process Burst Time: ");
    for(i=0;i<n;i++)
    {
        printf("\nProcess [%d]:",i+1);
        scanf("%d",&burst[i]);
    }
 
    wait[0]=0;   
 
    for(i=1;i<n;i++)
    {
        wait[i]=0;
        for(j=0;j<i;j++)
            wait[i]+=burst[j];
    }
 
    printf("\nProcess\t Burst Time\t Waiting Time\t Turn around Time");
 
    for(i=0;i<n;i++)
    {
        turnaround[i]=burst[i]+wait[i];
        avwait+=wait[i];
        avturnaround += turnaround[i];
        printf("\nP[%d]\t    %d\t\t   %d\t\t    %d",i+1,burst[i],wait[i],turnaround[i]);
    }
 
    avwait/=i;
    avturnaround/=i;
    printf("\nAverage Waiting Time: %d",avwait);
    printf("\nAverage Turn Around Time: %d\n",avturnaround);
 
    return 0;
}
