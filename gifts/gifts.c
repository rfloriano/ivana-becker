#include <stdio.h>
#include <stdbool.h>

int main()
{
    int bag[3] = {20, 20, 20};
    int boxQnt;
    scanf("%d", &boxQnt);
    bool boxes[boxQnt];
    for (int i = 0; i < boxQnt; i++)
    {
        int width, height, depth;
        scanf("%d %d %d", &width, &height, &depth);
        bool isGood = width <= bag[0] && height <= bag[1] && depth <= bag[2];
        boxes[i] = isGood;
    }
    for (int i = 0; i < boxQnt; i++)
    {
        bool isGood = boxes[i];
        printf("Caso %d:  %s\n", i + 1, isGood ? "good" : "bad");
    }

    return 0;
}
