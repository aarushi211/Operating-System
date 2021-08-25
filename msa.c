#include<stdio.h>
void main()
{
	int frag[25], b[25], f[25], i, j, nb, nf, temp, lowest=10000, highest = 0; 	
	static int bf[25], ff[25];
	int used = 0, wasted = 0, total = 0, left;
	
	printf("Enter the number of blocks: ");
	scanf("%d", &nb);
	printf("Enter the number of files: ");
	scanf("%d", &nf);
	printf("\nEnter the size of the blocks-\n");
	for(i=1;i<=nb;i++)
	{
		printf("Block %d:",i);
		scanf("%d",&b[i]);
	}
	printf("\nEnter the size of the files-\n");
	for(i=1;i<=nf;i++)
	{
		printf("File %d:",i);
		scanf("%d",&f[i]);
	}
	for(i=1; i<=nb; i++)
	{
		total += b[i];	
	}
	printf("Types of Memory Allocation - ");
	printf("1. Best Fit\n2. Worst Fit");
	int choice;
	printf("\nEnter your choice(1 or 2): \n");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1:
		{
			// For Best Fit
			for(i=1; i<=nf; i++)
			{
				for(j=1; j<=nb; j++)
				{
					if(bf[j]!=1)
					{
						temp = b[j] - f[i];
						if(temp>=0)
						if(lowest>temp)
						{
							ff[i] = j;
							lowest = temp;
						}
					}
				}
				frag[i] = lowest;
				bf[ff[i]] = 1;
				lowest= 10000;
			}
			printf("**For Best Fit**");
			printf("\nFile No.\tFile Size\tBlock No.\tBlock Size\tfragment");
			for(i=1; i<=nf && ff[i]!=0; i++)
			{
				printf("\n%d\t\t %d\t\t %d\t\t %d\t\t %d", i, f[i], ff[i], b[ff[i]], frag[i]);
				used += f[i];
				wasted += frag[i];
			}
			left = total - wasted - used;
			
			printf("\n");
			printf("Memory Space Utilization = %d\n", used);
			printf("Memory wasted = %d\n",wasted); 
			printf("Total Memory Space Left: %d\n", left);
			break;
		}
			
		case 2:
		{
			// For Worst Fit
			for(i=1; i<=nf; i++)
			{
				for(j=1; j<=nb; j++)
				{
					if(bf[j]!=1)
					{
						temp = b[j] - f[j];
						if(temp>=0)
						if(highest< temp)
						{
							ff[i] = j;
							highest = temp;
						}
					}
				}
				frag[i] = highest;
				bf[ff[i]] = 1;
				highest = 0;
			}
			printf("**For Worst Fit**");
			printf("\nFile No.\tFile Size\tBlock No.\tBlock Size\tfragment");
			for(i=1; i<=nf && ff[i]!=0; i++)
			{
				printf("\n%d\t\t %d\t\t %d\t\t %d\t\t %d", i, f[i], ff[i], b[ff[i]], frag[i]);
				used += f[i];
				wasted += frag[i];
			}
			left = total - wasted - used;
			
			printf("\n");
			printf("Memory Space Utilization = %d\n", used);
			printf("Memory wasted = %d\n",wasted); 
			printf("Total Memory Space Left: %d\n", left);
			break;
		default:
			printf("Error: Enter either 1 or 2");
		}
	}			
} 
