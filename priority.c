#include<stdio.h>

int main()
{
    int bt[50],p[50],wt[50],tat[50],pr[50],i,j,n,t=0,l,tp,avg_wt,avg_tat;
    printf("enter theh no. of process:");
    scanf("%d",&n);

    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        l=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[l])
               l=j;
        }

        tp=pr[i];
        pr[i]=pr[l];
        pr[l]=tp;

        tp=bt[i];
        bt[i]=bt[l];
        bt[l]=tp;

        tp=p[i];
        p[i]=p[l];
        p[l]=tp;
    }

    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        t+=wt[i];
    }

    avg_wt=t/n;
    t=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        t+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }

    avg_tat=t/n;
    printf("\n\navg waiting time=%d",avg_wt);
    printf("\navg turnaround time=%d\n",avg_tat);

	return 0;
}
