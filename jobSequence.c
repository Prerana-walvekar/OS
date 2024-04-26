#include<stdio.h>

int main()
{
	int n,i,j;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	int pid[n],profit[n],deadline[n];
	int maxD,totalProfit=0;
	
	for(i=0;i<n;i++)
	{
		printf("Enter process no.: ");
		scanf("%d",&pid[i]);
		printf("Enter process profit: ");
		scanf("%d",&profit[i]);
		printf("Enter process deadline: ");
		scanf("%d",&deadline[i]);
	}
	
	printf("\nEnter Max Deadline: ");
	scanf("%d",&maxD);
	
	//sorting
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(profit[j]<profit[j+1]){
				int temp = profit[j];
				profit[j]=profit[j+1];
				profit[j+1]=temp;
				
				temp = pid[j];
				pid[j]=pid[j+1];
				pid[j+1]=temp;
				
				temp = deadline[j];
				deadline[j]=deadline[j+1];
				deadline[j+1]=temp;
			}
		}
	}
	
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\n",pid[i],profit[i],deadline[i]);
	}
	
	printf("\nSequence:\n");
	i=0;
	while(maxD!=0){
		if(deadline[i]<=maxD){
			maxD-=deadline[i];
			printf("Job %d\t",pid[i]);
			totalProfit+=profit[i];
			i++;
		}
		else{
			i++;
		}
	}
	printf("\nTotal Profit Earned=%d",totalProfit);
}
