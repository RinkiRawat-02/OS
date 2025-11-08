// FIFO Page Replacement Algorithm

#include <stdio.h>
int main()
{
    int frames, n;
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of page requests: ");
    scanf("%d", &n);

    int pages[n], memory[frames];
    printf("Enter page reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    for (int i = 0; i < frames; i++)
        memory[i] = -1;

    int page_faults = 0;
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = 0; j < frames; j++)
        {
            if (memory[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            memory[index] = pages[i];
            index = (index + 1) % frames;
            page_faults++;
        }
    }

    printf("\nTotal Page Faults = %d\n", page_faults);
    return 0;
}
