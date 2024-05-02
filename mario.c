#include <stdio.h>

void print_grid(int size);
int get_size(void);

int main(void)
{
    int n = get_size();
    print_grid(n);
    return 0;
}

int get_size(void)
{
    int n;
    do
    {
        printf("Size: ");
        scanf("%d", &n);
    while (n < 1);
    return n;
}

void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}