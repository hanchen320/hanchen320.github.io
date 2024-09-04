//--------------------------------------------------------------------------*
//文件名: LCD.c                                                             *
//说  明: LCD构件函数源文件                                                 *
//--------------------------------------------------------------------------*

//头文件包含，及宏定义区

    // 头文件包含 
    #include         "LCD.h"                    //LCD构件头文件

//构件函数实现

    //---------------------------------------------------------------------*
    //函数名:LCDInit:初始化LCD函数                                         *
    //功  能:初始化Lcd(HD44780),设置显示方式,清屏,AC自动+1                 *
    //参  数:无                                                            *
    //返  回:无                                                            *
    //内部调用函数:LCD_Command                                             *
    //---------------------------------------------------------------------*
    void LCDInit(void)
    {
        uint16 i;
        // 定义数据口为输出
        GPIO_Set(LCD_P0,DDR,LCD_B0,1);
        GPIO_Set(LCD_P1,DDR,LCD_B1,1);
        GPIO_Set(LCD_P2,DDR,LCD_B2,1);
        GPIO_Set(LCD_P3,DDR,LCD_B3,1);
        GPIO_Set(LCD_P4,DDR,LCD_B4,1);
        GPIO_Set(LCD_P5,DDR,LCD_B5,1);
        GPIO_Set(LCD_P6,DDR,LCD_B6,1);
        GPIO_Set(LCD_P7,DDR,LCD_B7,1);
      
        // 定义控制口为输出 
        GPIO_Set(LCDRS_P,DDR,LCDRS_B,1);
        GPIO_Set(LCDRW_P,DDR,LCDRW_B,1);
        GPIO_Set(LCDE_P,DDR,LCDE_B,1);
        
        // 设置指令,RS,R/W = 00, 写指令代码
        GPIO_Set(LCDRS_P,PRT,LCDRS_B,0);
        GPIO_Set(LCDRW_P,PRT,LCDRW_B,0);
       
        // 功能设置
        LCD_Command(0b00111000);
                   //||||||||____ 可设任意值(0/1)
                   //||||||______ F  = 0,5*7点阵模式
                   //|||||_______ N  = 1,2行显示
                   //||||________ DL = 1,8位数据总线
                   //|||_________ 固定为001
                   
        // 显示开关控制 
        LCD_Command(0b00001000);
                   //||||||||____ B = 0,不闪烁
                   //|||||||_____ C = 0,关光标显示
                   //||||||______ D = 0,关显示
                   //|||||_______ 固定为00001
                   
        // 清屏
        
        // 清DD RAM内容,光标回原位,清AC
        LCD_Command(0b00000001);
        
        // 等待清屏完毕,时间 > 1.6ms
        for (i=0; i<20000; i++);                     
        
        // 输入方式设置 
        LCD_Command(0b00000110);
                   //||||||||____ 显示不移动,光标左移(A = 1)
                   //|||||||_____ 数据读写操作后,AC自动增1
                   //||||||______ 固定为000001
                   
        // 光标或画面移位设置
        LCD_Command(0b00010100);
                   //||||||||____ 可设任意值(0/1)
                   //||||||______ 光标右移一个字符位,AC自动加1
                   //||||________ 固定为0001
                   
        // 显示开关控制
        LCD_Command(0b00001100);
                   //||||||||____ B = 0,不闪烁
                   //|||||||_____ C = 0,关光标显示
                   //||||||______ D = 1,开显示
                   //|||||_______ 固定为00001
    }
    //---------------------------------------------------------------------*
    //函数名:Delay1                                                        *
    //功  能:用程序的方法延时一段时间                                      *
    //参  数:k=延时长度(0-65535)                                           *
    //返  回:无                                                            *
    //---------------------------------------------------------------------*
    void Delay1(uint16 k)
    {
        uint16 i,j;
        for (i=0; i<k; i++)
            for (j=0; j<=500; j++);
    }

    //LCDShow:在HD44780显示屏上显示数据------------------------------------*
    //功  能:在HD44780显示屏显示str所指向的32个数据                        *
    //参  数:str=待显示的数组                                              *
    //返  回:无                                                            *
    //内部调用函数:LCD_Command                                             *
    //---------------------------------------------------------------------*
    void LCDShow(uint8 str[])
    {
        uint8 i;
        // LCD初始化 
        LCDInit();
        
        // 显示第1行16个字符
                                                  //设置显示首地址                               
        GPIO_Set(LCDRS_P,PRT,LCDRS_B,0);          //RS,R/W = 00(写的是指令)
        GPIO_Set(LCDRW_P,PRT,LCDRW_B,0);
        
        LCD_Command(0x80);                        //后7位为DD RAM地址(0x00)
        
        //2.2写16个数据到DD RAM                            
        GPIO_Set(LCDRS_P,PRT,LCDRS_B,1);          //RS,R/W = 10(写的是数据)
        GPIO_Set(LCDRW_P,PRT,LCDRW_B,0);
        
        
        // 将要显示在第1行上的16个数据逐个写入DD RAM中 
        for (i = 0;i < 16;i++)
        {
            LCD_Command(str[i]);
        }
        
        // 显示第2行16个字符 
       	                                          //设置显示首地址
        GPIO_Set(LCDRS_P,PRT,LCDRS_B,0);          //RS,R/W = 00(写的是指令)
        GPIO_Set(LCDRW_P,PRT,LCDRW_B,0);
        
        LCD_Command(0xC0);                        //后7位为DD RAM地址(0x40)
        
        // 再写16个数据到DD RAM 
        GPIO_Set(LCDRS_P,PRT,LCDRS_B,1);          //RS,R/W = 10(写的是数据)
        GPIO_Set(LCDRW_P,PRT,LCDRW_B,0);
        
        // 将要显示在第2行上的16个数据逐个写入DD RAM中 
        for (i = 16;i < 32;i++)
        {
            LCD_Command(str[i]);
        }
    }

    //LCD_Command:执行给定的cmd命令----------------------------------------*
    //功  能:执行给定的cmd命令,且延时                                      *
    //参  数:cmd=待执行的命令                                              *
    //返  回:无                                                            *
    //---------------------------------------------------------------------*
    void LCD_Command(uint8 cmd)
    {	 	
        uint8 i;   
        // 等待 > 40us 
        Delay1(5);

        // 数据送到LCD的数据线上
       
        GPIO_Set(LCD_P0,PRT,LCD_B0,((cmd >> 0) & 0x01));
        GPIO_Set(LCD_P1,PRT,LCD_B1,((cmd >> 1) & 0x01));
        GPIO_Set(LCD_P2,PRT,LCD_B2,((cmd >> 2) & 0x01));
        GPIO_Set(LCD_P3,PRT,LCD_B3,((cmd >> 3) & 0x01));
        GPIO_Set(LCD_P4,PRT,LCD_B4,((cmd >> 4) & 0x01));
        GPIO_Set(LCD_P5,PRT,LCD_B5,((cmd >> 5) & 0x01));
        GPIO_Set(LCD_P6,PRT,LCD_B6,((cmd >> 6) & 0x01));
        GPIO_Set(LCD_P7,PRT,LCD_B7,((cmd >> 7) & 0x01));

        // 给出E信号的下降沿,使数据写入LCD
        GPIO_Set(LCDE_P,PRT,LCDE_B,1);

        for(i=0;i<10;i++)    //延时
          asm("NOP");
           
        // Lcd结束接收数据
        GPIO_Set(LCDE_P,PRT,LCDE_B,0);
        
        // 等待 > 40us
        Delay1(5);
    }
