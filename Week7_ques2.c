// LRU (Least Recently Used) Page Replacement Algorithm

#include <stdio.h>
int main()
{
    int frames, n;
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of page requests: ");
    scanf("%d", &n);

    int pages[n], memory[frames], recent[frames];
    printf("Enter page reference string: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < frames; i++)
    {
        memory[i] = -1;
        recent[i] = 0;
    }

    int page_faults = 0;

    for (int i = 0; i < n; i++)
    {
        int found = -1;
        for (int j = 0; j < frames; j++)
        {
            if (memory[j] == pages[i])
            {
                found = j;
                break;
            }
        }

        if (found == -1)
        { 
            // Page Fault
            int lru_index = 0;
            for (int j = 1; j < frames; j++)
            {
                if (recent[j] < recent[lru_index])
                {
                    lru_index = j;
                }
            }

            memory[lru_index] = pages[i];
            recent[lru_index] = i + 1;
            page_faults++;
        }
        else
        {
            recent[found] = i + 1;
        }
    }

    printf("\nTotal Page Faults = %d\n", page_faults);
    return 0;
}
