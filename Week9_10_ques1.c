//Sequential File Allocation

#include <stdio.h>
#include <string.h>

#define MAX 50

struct File
{
    char name[20];
    int start;
    int size;
    int blocks[MAX];
};

int main()
{
    int n, i, j;
    char search[20];
    struct File f[MAX];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter file name: ");
        scanf("%s", f[i].name);

        printf("Enter starting block number: ");
        scanf("%d", &f[i].start);

        printf("Enter number of blocks required: ");
        scanf("%d", &f[i].size);

        for (j = 0; j < f[i].size; j++)
        {
            f[i].blocks[j] = f[i].start + j;
        }
    }

    printf("\nEnter file name to search: ");
    scanf("%s", search);

    for (i = 0; i < n; i++)
    {
        if (strcmp(search, f[i].name) == 0)
        {
            printf("\nFile Found ✅\n");
            printf("File Name: %s\n", f[i].name);
            printf("Starting Block: %d\n", f[i].start);
            printf("Number of Blocks: %d\n", f[i].size);
            printf("Allocated Blocks: ");

            for (j = 0; j < f[i].size; j++)
            {
                printf("%d ", f[i].blocks[j]);
            }

            printf("\n");
            return 0;
        }
    }

    printf("\nFile Not Found ❌\n");
    return 0;
}
