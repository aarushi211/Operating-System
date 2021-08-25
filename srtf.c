#include<stdio.h>
#include<conio.h>

int main()
{
    int i, j, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];
    float avg_wt, av_totl;
    printf(" enter the no. of process: ");
    scanf("%d", &j);
    y = j;
for(i=0; i<j; i++)
{
printf("\n enter arrival and burst time of process_%d\n", i+1);
printf(" Arrival time is: \t");
scanf("%d", &at[i]);
printf(" \nBurst time is: \t");
scanf("%d", &bt[i]);
temp[i] = bt[i];
}
printf("enter time quantum process: \t");
scanf("%d", &quant);
printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
for(sum=0, i = 0; y!=0; )
{
if(temp[i] <= quant && temp[i] > 0)
{
    sum = sum + temp[i];
    temp[i] = 0;
    count=1;
    }
    else if(temp[i] > 0)
    {
        temp[i] = temp[i] - quant;
        sum = sum + quant;
    }
    if(temp[i]==0 && count==1)
    {   y--;
        printf("\nprocess no is[%d] \t\t %d\t\t%d\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);
        wt = wt+sum-at[i]-bt[i];
        tat = tat+sum-at[i];
        count =0;
    }
    if(i==j-1)
    {
        i=0;
    }
    else if(at[i+1]<=sum)
    {
        i++;
    }
    else
    {
        i=0;
    }
}
avg_wt = wt * 1.0/j;
av_totl = tat * 1.0/j;
printf("\n avg turn around time: \t%f", avg_wt);
printf("\n avg waiting time: \t%f", av_totl);
getch();
}

