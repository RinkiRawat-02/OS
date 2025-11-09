//Best Fit Memory Allocation

#include <stdio.h>
int main()
{
    int n, p;
    printf("Enter number of blocks: ");
    scanf("%d", &n);

    int block[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &block[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &p);

    int process[p], allocation[p];
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    for (int i = 0; i < p; i++)
    {
        int best = -1;
        for (int j = 0; j < n; j++)
        {
            if (block[j] >= process[i])
            {
                if (best == -1 || block[j] < block[best])
                {
                    best = j;
                }
            }
        }
        if (best != -1)
        {
            allocation[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\nAllocation Result (Best Fit):\n");
    for (int i = 0; i < p; i++)
    {
        if (allocation[i] != -1)
        {
            printf("Process %d allocated to Block %d\n", i + 1, allocation[i] + 1);
        }
        else
        {
            printf("Process %d: no free block available\n", i + 1);
        }
    }
    return 0;
}
