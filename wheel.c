#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int spin(int count)
{
    int seed;
    seed = time(NULL);
    srand(seed);
    return rand() % count;
}

int main()
{
    char choices[100][50];
    int count;
    printf("Type the number of your choices:");
    scanf("%d", &count);

    printf("Type your choices:\n");

    for (int i = 0; i < count; i++)
    {
        // Add a space before %c to skip any leading whitespace characters
        scanf("%s", choices[i]);
    }

    printf("Your choices:\n");

    // for (int j = 0; j < count; j++)
    // {
    //     printf("%s\n", choices[j]);
    // }

    int ch = spin(count);
    printf("The %dth choice is selected\n", ch + 1);
    printf("Your choice is: %s\n", choices[ch]);
}