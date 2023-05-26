#include <stdio.h>

void bits_set(int value)
{
    printf("bits: ");
    for (int i = 0; i < 32; i++)
    {
        if (value & (1 << i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(void)
{
    int value;
    do
    {
        printf("enter value (0 to exit): ");

        scanf("%x", &value);
        if (value == 0)
            goto exit;

        bits_set(value);
    } while (value != 0);

    return -1;

exit:
    return 0;
}
