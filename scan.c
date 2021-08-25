#include<stdio.h>
int absolute(int x)
{
	if(x>0)
	{
		return x;
	}
	else
	{
		return x*(-1);
	}
}

void main()
{
	int queue[50], n, head, i, j, k, seek = 0, maxrange, diff, temp, queue1[50], queue2[50], temp1=0, temp2=0, a;
	float av_seek_time;
	
	printf("Enter the maximum range of the disk: ");
	scanf("%d", &maxrange);
	printf("Enter the total number of queue requests: ");
	scanf("%d", &n);
	printf("Enter the head position: ");
	scanf("%d", &head);
	
	
	printf("**Types of Disk Scheduling Algorithm Available**\n 1. SCAN\n 2. LOOK\n >>");
	scanf("%d", &a);
	printf("Enter the requests in the queue: ");
	for(i = 1; i<=n; i++)
	{
		scanf("%d", &temp);
		if(temp>head)
		{
			queue1[temp1] = temp;
			temp1++;
		}
		else
		{
			queue2[temp2] = temp;
			temp2++;
		}
	}
	switch(a)
	{
		case 1:
		{
			// Sorting queue1[] array in ascending order
			for(i=0; i<temp1-1; i++)
			{
				for(j=i+1; j<temp1; j++)
				{
					if(queue1[i]>queue1[j])
					{
						temp=queue1[i];
						queue1[i] = queue1[j];
						queue1[j] = temp;
					}
				}
			}
			// Sorting queue2[] array in descending order
			for(i=0; i<temp2-1; i++)
			{
				for(j=i+1; j<temp2; j++)
				{
					if(queue2[i]<queue2[j])
					{
						temp = queue2[i];
						queue2[i] = queue2[j];
						queue2[j] = temp;
					}
				}
			}
			
			int dir;
			printf("Enter the order in which you wish to move-\n 1. Increasing\n 2. Decreasing\n >> ");
			scanf("%d", &dir);
			if(dir == 1)
			{
				//Copying array queue1[] into queue[]
				for(i=1,j=0; j<temp1; i++, j++)
				{
					queue[i] = queue1[j];
				}
				//Since head goes to end of the disk and then comes back
				queue[i] = maxrange;
				// Copying array queue2[] into queue
				for(i=temp1+2, j=0; j<temp2; i++, j++)
				{
					queue[i] = queue2[j];
				}
				// Setting queue[i] to 0 as it is the innermost cylinder
				queue[i] = 0;
			}
			else if(dir == 2)
			{
				// Copying array queue2[] into queue
				for(i=1, j=0; j<temp2; i++, j++)
				{
					queue[i] = queue2[j];
				}
				// Setting queue[i] to 0 as it is the innermost cylinder
				queue[i] = 0;
				//Copying array queue1[] into queue[]
				for(i=temp2+2,j=0; j<temp1; i++, j++)
				{
					queue[i] = queue1[j];
				}
				//Since head goes to end of the disk and then comes back
				queue[i] = maxrange;
			}
			else
			{
				printf("Error: Enter either 1 or 2");
			}
				
			// Setting the first index of queue to head position
			queue[0] = head;
			printf("\n\nMovement of Disk\t\t Seek Time\n");
			for(j=0; j<=n; j++)
			{
				// Calculating seek time.
				diff = absolute(queue[j+1] - queue[j]);
				seek += diff;

				printf("%d --> %d\t\t\t %d\n", queue[j], queue[j+1], diff);
				av_seek_time = (float)seek/n;
			}	
			break;
		}
		case 2:
		{
			// Sorting queue1[] array in ascending order
			for(i=0; i<temp1; i++)
			{
				for(j=i+1; j<temp1; j++)
				{
					if(queue1[i]>queue1[j])
					{
						temp=queue1[i];
						queue1[i] = queue1[j];
						queue1[j] = temp;
						 
					}
				}
			}
			// Sorting queue2[] array in descending order
			for(i=0; i<temp2; i++)
			{
				for(j=i+1; j<temp2; j++)
				{
					if(queue2[i]<queue2[j])
					{
						temp = queue2[i];
						queue2[i] = queue2[j];
						queue2[j] = temp;
						
					}
				}
			}
			
			int dir;
			printf("Enter the order in which you wish to move-\n 1. Increasing\n 2. Decreasing\n >> ");
			scanf("%d", &dir);
			if(dir == 1)
			{
				//Copying array queue1[] into queue[]
				for(i=1,j=0; j<temp1; i++, j++)
				{
					queue[i] = queue1[j];
				}
				// Copying array queue2[] into queue
				for(i=temp1+1, j=0; j<temp2; i++, j++)
				{
					queue[i] = queue2[j];
				}
				// Setting queue[i] to 0 as it is the innermost cylinder
				queue[i] = 0;
			}
			else if(dir == 2)
			{
				// Copying array queue2[] into queue
				for(i=1, j=0; j<temp2; i++, j++)
				{
					queue[i] = queue2[j];
				}
				//Copying array queue1[] into queue[]
				for(i=temp2+1,j=0; j<temp1; i++, j++)
				{
					queue[i] = queue1[j];
				}
				// Setting queue[i] to maxrange as it is the outermost cylinder
				queue[i] = maxrange;
			}
			else
			{
				printf("Error: Enter either 1 or 2");
			}
			
			// Setting the first index of queue to head position
			queue[0] = head;
			printf("\n\nMovement of Disk\t\t Seek Time\n");
			for(j=0; j<n; j++)
			{
				// Calculating seek time.
				diff = absolute(queue[j+1] - queue[j]);
				seek += diff;

				printf("%d --> %d\t\t\t %d\n", queue[j], queue[j+1], diff);
				av_seek_time = (float)seek/n;
			}
			break;
		}
			
		default:
		{
			printf("Error: Please enter either 1 or 2");
		}
	
	}
	
	printf("\nTotal seek time = %d\n", seek);
	printf("Average seek time = %.2f\n", av_seek_time);		
} 
