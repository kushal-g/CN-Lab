#include <stdio.h>
#define infinity 999

void dij(int n, int source, int costMatrix[10][10])
{
	int distance[10];
	int flag[10];

	for (int i = 0; i < n; i++)
	{
		distance[i] = costMatrix[source][i];
		flag[i] = 0;
	}

	int count = 2;

	while (count <= n)
	{
		int min = infinity;
		int selectedNode;
		for (int i = 0; i < n; i++)
		{
			if (distance[i] < min && !flag[i])
			{
				min = distance[i];
				selectedNode = i;
			}
		}

		flag[selectedNode] = 1;
		count++;

		for (int i = 0; i < n; i++)
		{
			if (distance[selectedNode] + costMatrix[selectedNode][i] < distance[i] && !flag[i])
			{
				distance[i] = distance[selectedNode] + costMatrix[selectedNode][i];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("Distance to %d: %d\n", i, distance[i]);
	}
}

int main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	int costMatrix[10][10];
	int source;
	printf("Enter source node: ");
	scanf("%d", &source);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &costMatrix[i][j]);
			if (costMatrix[i][j] == 0)
			{
				costMatrix[i][j] = infinity;
			}
		}
	}

	dij(n, source, costMatrix);
}