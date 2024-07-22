#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
    char ch, newch;
    int offset;
    scanf("%d %c", &offset, &ch);
    newch = ch + offset;
    printf("%c", newch);
    return 0;
}