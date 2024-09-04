//包含头文件
#include "Includes.h"     //包含总头文件

//在此添加全局变量定义
void delay() ;//延时函数
uint8 time[3]=0;       //时分秒变量
uint8 distance[1]=10;//当前行驶距离
//uint8 keyint=0xFF;//按下键值
uint8 str[32];//LCD显示数组变量
uint8 tex[9]="Distance:";
uint8 text[4]="Sum:";
uint8 o=0;
uint8 sum=0;//当前需付金额
uint8 t=0;   //停留分钟数
uint8 valve;
void main()
{
    //0.1 主程序使用的变量定义
    uint32 mRuncount=0;       //运行计数器
    //0.2 关总中断
    DisableInterrupt();  
       
    //0.3 芯片初始化
    MCUInit(FBUS_32M);
    TimerInit();                         //(1)定时器1初始化 
    KBInit();                                       //键盘初始化
    GPIO_Init(PK,7,1,0)  ;

 //0.4 模块初始化
    Light_Init(Light_Run_PORT,Light_Run,Light_OFF); //RUN指示灯初始化为暗
    SCIInit(0,FBUS_32M,9600);                   //串口0初始化
    LCDInit();
    LCDShow((uint8 *)"Wait Receiving.. Dxxy.Shiep 2015");    // LCD显示初始化  
    TSCR2 |=  1<<7 ;  //开放定时器溢出中断                       
    PIEH |= 0x0F ;                                  //开放键盘中断
    EnableInterrupt();                   //(3)开放总中断
    DDRP=0x00;  //把P口定义为输入

    
    // 主循环
    for(;;)
    {
      valve = KBScanN(5);
      if(KBScanN(5)!=0xFF)//判断按键是否按下 
      {
      GPIO_Set(PK,PRT,7,1); //打开蜂鸣器
      delay();//延时
      GPIO_Set(PK,PRT,7,0);//关闭蜂鸣器
      
      t=time[0]*60+time[1];
        if(distance[0]<3) 
        {
          sum=12+3*(t/5);
        }
        else {
          sum=12+3*(distance[0]-3+t/5);
        }
      str[11]=distance[0];
      str[21]=sum;
      str[31]=time[2];
      str[30]=time[1];
      str[29]=time[0]; 
      for (o = 0;o < 9;o++)
        {
            str[o]= tex[o] ;
        }
      for (o = 16;o < 20;o++)
        {
            str[o]=text[o-16];
        }
      
     LCDShow(str); 
    }
    }
}


/*************************************************************/
/*                        延时函数                           */
/*************************************************************/
void delay() 
{
    unsigned int i,j;
    for(i=0;i<10;i++)
      for(j=0;j<500;j++);
}









