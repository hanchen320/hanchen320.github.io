        //--------------------------------------------------------------------------*
// 文件名 : isr.c                                                           *
// 说  明 : 该文件为中断处理文件，用于写中断服务程序。                      *
//          在需要的中断位置开启中断并书写相应的中断服务程序。              *
//--------------------------------------------------------------------------*

    //头文件包含，及宏定义区

    // 头文件包含 
    #include "Includes.h"                   //总头文件
    
    //变量定义区 
    uint8 TimInterCount;  //中断次数
                                 
    extern uint8 time[3];                               //存放时,分,秒
   // extern uint8 keyint;
    extern uint8 distance[1];
    #pragma CODE_SEG __NEAR_SEG NON_BANKED
    

    //中断服务程序区

    //未定义的中断处理函数,本函数不能删除,默认
    __interrupt void isr_default(void)
    {   
       DisableInterrupt();
       //此处放中断代码
       EnableInterrupt();
    }

    //串口接受中断 
    __interrupt void SCI0_Recv(void)
    {   
        uint8 i; 
       	DisableInterrupt();                              //禁止总中断
        i=SCIReN(0,1,distance);                              //接收数据
    	  EnableInterrupt();                               //开放总中断
    }

    //定时器溢出中断处理程序 
    __interrupt void isrTimOver(void)
    {
        DisableInterrupt();      //关总中断
        if(PTP_PTP0==1)     //判断拨码开关的第一位是否拨开
        {
          TimInterCount++;         //中断次数加一,中断4次为一秒
          if (TimInterCount >= 4)
          {
              calculate(time);       //定时器更新
              TimInterCount=0;
    	    }
    	 }  
    	  TFLG2 = 0x80;            //清除定时器溢出标志位
        EnableInterrupt();       //开总中断
    }
      //键盘中断 
    __interrupt void isrKeyBoard(void)
    {   
       
        uint8 valve;
        uint16 i;
        DisableInterrupt();
        DisableKBint();
        for (i=0 ; i<20000; i++);                    //延时
        valve = KBScanN(10);                         //扫描键值,存于value中
        KBInit();                                    //键盘初始化
        EnableKBint();                               //开放键盘中断
        EnableInterrupt();                           //开放总中断
        
    }
    

    #pragma CODE_SEG DEFAULT


    //中断矢量表对应区

    //中断处理子程序类型定义
    typedef void (*near tIsrFunc)(void);
    
    //中断矢量表，如果需要定义其它中断函数，请修改下表中的相应项目
    const tIsrFunc _InterruptVectorTable[] @0xFF10 = { 
      /* ISR name                           No.   Address  Pri Name            */
      isr_default,                       /* 0x08  0xFF10   -   ivVsi           */
      isr_default,                       /* 0x09  0xFF12   -   ivVsyscall      */
      isr_default,                       /* 0x0A  0xFF14   1   ivVReserved118  */
      isr_default,                       /* 0x0B  0xFF16   1   ivVReserved117  */
      isr_default,                       /* 0x0C  0xFF18   1   ivVReserved116  */
      isr_default,                       /* 0x0D  0xFF1A   1   ivVReserved115  */
      isr_default,                       /* 0x0E  0xFF1C   1   ivVReserved114  */
      isr_default,                       /* 0x0F  0xFF1E   1   ivVReserved113  */
      isr_default,                       /* 0x10  0xFF20   1   ivVReserved112  */
      isr_default,                       /* 0x11  0xFF22   1   ivVReserved111  */
      isr_default,                       /* 0x12  0xFF24   1   ivVReserved110  */
      isr_default,                       /* 0x13  0xFF26   1   ivVReserved109  */
      isr_default,                       /* 0x14  0xFF28   1   ivVReserved108  */
      isr_default,                       /* 0x15  0xFF2A   1   ivVReserved107  */
      isr_default,                       /* 0x16  0xFF2C   1   ivVReserved106  */
      isr_default,                       /* 0x17  0xFF2E   1   ivVReserved105  */
      isr_default,                       /* 0x18  0xFF30   1   ivVReserved104  */
      isr_default,                       /* 0x19  0xFF32   1   ivVReserved103  */
      isr_default,                       /* 0x1A  0xFF34   1   ivVReserved102  */
      isr_default,                       /* 0x1B  0xFF36   1   ivVReserved101  */
      isr_default,                       /* 0x1C  0xFF38   1   ivVReserved100  */
      isr_default,                       /* 0x1D  0xFF3A   1   ivVReserved99   */
      isr_default,                       /* 0x1E  0xFF3C   1   ivVReserved98   */
      isr_default,                       /* 0x1F  0xFF3E   1   ivVatd0compare  */
      isr_default,                       /* 0x20  0xFF40   1   ivVReserved96   */
      isr_default,                       /* 0x21  0xFF42   1   ivVReserved95   */
      isr_default,                       /* 0x22  0xFF44   1   ivVReserved94   */
      isr_default,                       /* 0x23  0xFF46   1   ivVReserved93   */
      isr_default,                       /* 0x24  0xFF48   1   ivVReserved92   */
      isr_default,                       /* 0x25  0xFF4A   1   ivVReserved91   */
      isr_default,                       /* 0x26  0xFF4C   1   ivVReserved90   */
      isr_default,                       /* 0x27  0xFF4E   1   ivVReserved89   */
      isr_default,                       /* 0x28  0xFF50   1   ivVReserved88   */
      isr_default,                       /* 0x29  0xFF52   1   ivVReserved87   */
      isr_default,                       /* 0x2A  0xFF54   1   ivVReserved86   */
      isr_default,                       /* 0x2B  0xFF56   1   ivVReserved85   */
      isr_default,                       /* 0x2C  0xFF58   1   ivVReserved84   */
      isr_default,                       /* 0x2D  0xFF5A   1   ivVReserved83   */
      isr_default,                       /* 0x2E  0xFF5C   1   ivVReserved82   */
      isr_default,                       /* 0x2F  0xFF5E   1   ivVReserved81   */
      isr_default,                       /* 0x30  0xFF60   1   ivVReserved79   */
      isr_default,                       /* 0x31  0xFF62   1   ivVReserved78   */
      isr_default,                       /* 0x32  0xFF64   1   ivVReserved77   */
      isr_default,                       /* 0x33  0xFF66   1   ivVReserved76   */
      isr_default,                       /* 0x34  0xFF68   1   ivVReserved75   */
      isr_default,                       /* 0x35  0xFF6A   1   ivVReserved74   */
      isr_default,                       /* 0x36  0xFF6C   1   ivVReserved73   */
      isr_default,                       /* 0x37  0xFF6E   1   ivVReserved72   */
      isr_default,                       /* 0x38  0xFF70   1   ivVReserved71   */
      isr_default,                       /* 0x39  0xFF72   1   ivVReserved70   */
      isr_default,                       /* 0x3A  0xFF74   1   ivVpit3         */
      isr_default,                       /* 0x3B  0xFF76   1   ivVpit2         */
      isr_default,                       /* 0x3C  0xFF78   1   ivVpit1         */
      isr_default,                       /* 0x3D  0xFF7A   1   ivVpit0         */
      isr_default,                       /* 0x3E  0xFF7C   1   ivVhti          */
      isr_default,                       /* 0x3F  0xFF7E   1   ivVapi          */
      isr_default,                       /* 0x40  0xFF80   1   ivVlvi          */
      isr_default,                       /* 0x41  0xFF82   1   ivVReserved62   */
      isr_default,                       /* 0x42  0xFF84   1   ivVReserved61   */
      isr_default,                       /* 0x43  0xFF86   1   ivVReserved60   */
      isr_default,                       /* 0x44  0xFF88   1   ivVReserved59   */
      isr_default,                       /* 0x45  0xFF8A   1   ivVReserved58   */
      isr_default,                       /* 0x46  0xFF8C   1   ivVpwmesdn      */
      isr_default,                       /* 0x47  0xFF8E   1   ivVportp        */
      isr_default,                       /* 0x48  0xFF90   1   ivVReserved55   */
      isr_default,                       /* 0x49  0xFF92   1   ivVReserved54   */
      isr_default,                       /* 0x4A  0xFF94   1   ivVReserved53   */
      isr_default,                       /* 0x4B  0xFF96   1   ivVReserved52   */
      isr_default,                       /* 0x4C  0xFF98   1   ivVReserved51   */
      isr_default,                       /* 0x4D  0xFF9A   1   ivVReserved50   */
      isr_default,                       /* 0x4E  0xFF9C   1   ivVReserved49   */
      isr_default,                       /* 0x4F  0xFF9E   1   ivVReserved48   */
      isr_default,                       /* 0x50  0xFFA0   1   ivVReserved47   */
      isr_default,                       /* 0x51  0xFFA2   1   ivVReserved46   */
      isr_default,                       /* 0x52  0xFFA4   1   ivVReserved45   */
      isr_default,                       /* 0x53  0xFFA6   1   ivVReserved44   */
      isr_default,                       /* 0x54  0xFFA8   1   ivVReserved43   */
      isr_default,                       /* 0x55  0xFFAA   1   ivVReserved42   */
      isr_default,                       /* 0x56  0xFFAC   1   ivVReserved41   */
      isr_default,                       /* 0x57  0xFFAE   1   ivVReserved40   */
      isr_default,                       /* 0x58  0xFFB0   1   ivVcan0tx       */
      isr_default,                       /* 0x59  0xFFB2   1   ivVcan0rx       */
      isr_default,                       /* 0x5A  0xFFB4   1   ivVcan0err      */
      isr_default,                       /* 0x5B  0xFFB6   1   ivVcan0wkup     */
      isr_default,                       /* 0x5C  0xFFB8   1   ivVflash        */
      isr_default,                       /* 0x5D  0xFFBA   1   ivVflashfd      */
      isr_default,                       /* 0x5E  0xFFBC   1   ivVReserved33   */
      isr_default,                       /* 0x5F  0xFFBE   1   ivVReserved32   */
      isr_default,                       /* 0x60  0xFFC0   1   ivVReserved31   */
      isr_default,                       /* 0x61  0xFFC2   1   ivVReserved30   */
      isr_default,                       /* 0x62  0xFFC4   1   ivVcrgscm       */
      isr_default,                       /* 0x63  0xFFC6   1   ivVcrgplllck    */
      isr_default,                       /* 0x64  0xFFC8   1   ivVReserved27   */
      isr_default,                       /* 0x65  0xFFCA   1   ivVReserved26   */
      isr_default,                       /* 0x66  0xFFCC   1   ivVporth        */
      isr_default,                       /* 0x67  0xFFCE   1   ivVportj        */
      isr_default,                       /* 0x68  0xFFD0   1   ivVReserved23   */
      isr_default,                       /* 0x69  0xFFD2   1   ivVatd0         */
      isr_default,                       /* 0x6A  0xFFD4   1   ivVsci1         */
      SCI0_Recv,                         /* 0x6B  0xFFD6   1   ivVsci0         */
      isr_default,                       /* 0x6C  0xFFD8   1   ivVspi0         */
      isr_default,                       /* 0x6D  0xFFDA   1   ivVtimpaie      */
      isr_default,                       /* 0x6E  0xFFDC   1   ivVtimpaaovf    */
      isrTimOver,                        /* 0x6F  0xFFDE   1   ivVtimovf       */
      isr_default,                       /* 0x70  0xFFE0   1   ivVtimch7       */
      isr_default,                       /* 0x71  0xFFE2   1   ivVtimch6       */
      isr_default,                       /* 0x72  0xFFE4   1   ivVtimch5       */
      isr_default,                       /* 0x73  0xFFE6   1   ivVtimch4       */
      isr_default,                       /* 0x74  0xFFE8   1   ivVtimch3       */
      isr_default,                       /* 0x75  0xFFEA   1   ivVtimch2       */
      isr_default,                       /* 0x76  0xFFEC   1   ivVtimch1       */
      isr_default,                       /* 0x77  0xFFEE   1   ivVtimch0       */
      isr_default,                       /* 0x78  0xFFF0   1   ivVrti          */
      isr_default,                       /* 0x79  0xFFF2   1   ivVirq          */
      isr_default,                       /* 0x7A  0xFFF4   -   ivVxirq         */
      isr_default,                       /* 0x7B  0xFFF6   -   ivVswi          */
      isr_default                        /* 0x7C  0xFFF8   -   ivVtrap         */
    };

    







