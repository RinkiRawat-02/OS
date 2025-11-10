//Indexed File Allocation

#include <stdio.h>
#include <string.h>

#define MAX 50

struct File
{
    char name[20];
    int indexBlock;
    int size;
    int blocks[MAX];
};

int main()
{
    int n;
    char search[20];
    struct File f[MAX];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter file name: ");
        scanf("%s", f[i].name);

        printf("Enter index block number: ");
        scanf("%d", &f[i].indexBlock);

        printf("Enter number of blocks required: ");
        scanf("%d", &f[i].size);

        printf("Enter the %d block numbers (data blocks): ", f[i].size);
        for (int j = 0; j < f[i].size; j++)
        {
            scanf("%d", &f[i].blocks[j]);
        }
    }

    printf("\nEnter file name to search: ");
    scanf("%s", search);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(search, f[i].name) == 0)
        {
            printf("\nFile Found ✅\n");
            printf("File Name: %s\n", f[i].name);
            printf("Index Block: %d\n", f[i].indexBlock);
            printf("Number of Blocks: %d\n", f[i].size);

            printf("Data Blocks: ");
            for (int j = 0; j < f[i].size; j++)
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
