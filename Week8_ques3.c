#include <stdio.h>

int main()
{
    int b, p;
    printf("Enter number of blocks: ");
    scanf("%d", &b);

    int block[b];
    for (int i = 0; i < b; i++)
        scanf("%d", &block[i]);

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
        int worst = -1;
        for (int j = 0; j < b; j++)
        {
            if (block[j] >= process[i])
            {
                if (worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }
        if (worst != -1)
        {
            allocation[i] = worst;
            block[worst] -= process[i];
        }
    }

    printf("\nAllocation Result (Worst Fit):\n");
    for (int i = 0; i < p; i++)
    {
        if (allocation[i] != -1)
            printf("Process %d allocated to Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d: no free block available\n", i + 1);
    }
    return 0;
}
