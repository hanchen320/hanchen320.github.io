//����ͷ�ļ�
#include "Includes.h"     //������ͷ�ļ�

//�ڴ����ȫ�ֱ�������
void delay() ;//��ʱ����
uint8 time[3]=0;       //ʱ�������
uint8 distance[1]=10;//��ǰ��ʻ����
//uint8 keyint=0xFF;//���¼�ֵ
uint8 str[32];//LCD��ʾ�������
uint8 tex[9]="Distance:";
uint8 text[4]="Sum:";
uint8 o=0;
uint8 sum=0;//��ǰ�踶���
uint8 t=0;   //ͣ��������
uint8 valve;
void main()
{
    //0.1 ������ʹ�õı�������
    uint32 mRuncount=0;       //���м�����
    //0.2 �����ж�
    DisableInterrupt();  
       
    //0.3 оƬ��ʼ��
    MCUInit(FBUS_32M);
    TimerInit();                         //(1)��ʱ��1��ʼ�� 
    KBInit();                                       //���̳�ʼ��
    GPIO_Init(PK,7,1,0)  ;

 //0.4 ģ���ʼ��
    Light_Init(Light_Run_PORT,Light_Run,Light_OFF); //RUNָʾ�Ƴ�ʼ��Ϊ��
    SCIInit(0,FBUS_32M,9600);                   //����0��ʼ��
    LCDInit();
    LCDShow((uint8 *)"Wait Receiving.. Dxxy.Shiep 2015");    // LCD��ʾ��ʼ��  
    TSCR2 |=  1<<7 ;  //���Ŷ�ʱ������ж�                       
    PIEH |= 0x0F ;                                  //���ż����ж�
    EnableInterrupt();                   //(3)�������ж�
    DDRP=0x00;  //��P�ڶ���Ϊ����

    
    // ��ѭ��
    for(;;)
    {
      valve = KBScanN(5);
      if(KBScanN(5)!=0xFF)//�жϰ����Ƿ��� 
      {
      GPIO_Set(PK,PRT,7,1); //�򿪷�����
      delay();//��ʱ
      GPIO_Set(PK,PRT,7,0);//�رշ�����
      
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
/*                        ��ʱ����                           */
/*************************************************************/
void delay() 
{
    unsigned int i,j;
    for(i=0;i<10;i++)
      for(j=0;j<500;j++);
}









