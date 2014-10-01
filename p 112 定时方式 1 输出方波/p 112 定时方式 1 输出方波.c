#include <reg51.h>
#include "kid-51.c"

sbit P2_0 = P2^0;

main()
{
    TMOD = b("0001 0000");   // 定时器模式 + 方式 1
    TH1 = 0xfc, TL1 = 0x18;  // 计数初值
    EA = ET1 = 1;  // 开中断
    TR1 = 1;       // 开始计时

    while( true );
}


t1() interrupt 3
{
    P2_0 = !P2_0;
    TH1 = 0xfc, TL1 = 0x18;
}