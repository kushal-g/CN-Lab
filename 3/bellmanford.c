#include <stdio.h>

struct node
{
	int distance[10];
	int from[10];
} nodes[10];

int main()
{
	int costMatrix[10][10];
	int n;

	printf("Enter number of nodes");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			scanf("%d", &temp);
			costMatrix[i][j] = temp;
			costMatrix[i][i] = 0;
			nodes[i].distance[j] = costMatrix[i][j];
			nodes[i].from[j] = i;
		}
	}

	int count = 0;
	do
	{
		count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					if (nodes[i].distance[j] > nodes[i].distance[k] + costMatrix[k][j])
					{
						nodes[i].distance[j] = nodes[i].distance[k] + costMatrix[k][j];
						nodes[i].from[j] = k;
						count++;
					}
				}
			}
		}
	} while (count > 0);

	for (int i = 0; i < n; i++)
	{
		printf("For node %d\n", i);
		for (int j = 0; j < n; j++)
		{
			printf("Distance to node %d is %d from node %d\n", j, nodes[i].distance[j], nodes[i].from[j]);
		}
	}
}