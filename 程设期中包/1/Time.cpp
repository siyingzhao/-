#include <stdio.h>
#pragma warning(disable:4996)

int to_second(int h, int m, int s)
{
    int totalsecond;
    totalsecond = 3600 * h + 60 * m + s;
    return totalsecond;
}

int ori_to_hour(int ts)
{
    return ((ts - (ts % 3600)) / 3600);
}

int ori_to_minute(int ts)
{
    int k;
    k = ts % 3600;
    return ((k - (k % 60)) / 60);
}

int ori_to_second(int ts)
{
    return(ts % 60);
}

int main()
{
    struct time
    {
        int hh;
        int mm;
        int ss;
    }time1, time2;
    scanf("%d:%d:%d", &time1.hh, &time1.mm, &time1.ss);
    scanf("%d:%d:%d", &time2.hh, &time2.mm, &time2.ss);
    int dvalue;
    if (to_second(time1.hh, time1.mm, time1.ss) > to_second(time2.hh, time2.mm, time2.ss))
        dvalue = to_second(time1.hh, time1.mm, time1.ss) - to_second(time2.hh, time2.mm, time2.ss);
    else dvalue = to_second(time2.hh, time2.mm, time2.ss) - to_second(time1.hh, time1.mm, time1.ss);
    printf("%02d:%02d:%02d", ori_to_hour(dvalue), ori_to_minute(dvalue), ori_to_second(dvalue));
    return 0;
}