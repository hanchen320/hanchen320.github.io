//--------------------------------------------------------------------------*
// 文件名: LCD.h                                                            *
// 说  明: LCD驱动程序头文件                                                *
//--------------------------------------------------------------------------*
 
#ifndef LCD_H
#define LCD_H

//头文件包含，及宏定义区

    //头文件包含 
    #include    "GPIO.h"         //普通IO口构件头文件
/*    
    //液晶显示寄存器及标志位定义
    //LCD数据线所用的寄存器
    #define  LCD_P0                  PAD1
    #define  LCD_P1                  PAD1
    #define  LCD_P2                  PAD1
    #define  LCD_P3                  PAD1
    #define  LCD_P4                  PAD1
    #define  LCD_P5                  PJ
    #define  LCD_P6                  PJ
    #define  LCD_P7                  PS
    //LCD数据线所用寄存器的引脚
    #define  LCD_B0                  3      
    #define  LCD_B1                  4
    #define  LCD_B2                  5
    #define  LCD_B3                  6
    #define  LCD_B4                  7
    #define  LCD_B5                  7
    #define  LCD_B6                  6
    #define  LCD_B7                  3
    //LCD寄存器选择信号
    #define  LCDRS_P                  PP
    #define  LCDRS_B                  4      
    //LCD读写信号
    #define  LCDRW_P                  PP
    #define  LCDRW_B                  5
    //LCD使能信号
    #define  LCDE_P                   PP
    #define  LCDE_B                   7
 */   
      //液晶显示寄存器及标志位定义
    //LCD数据线所用的寄存器
    #define  LCD_P0                  PT
    #define  LCD_P1                  PT
    #define  LCD_P2                  PT
    #define  LCD_P3                  PT
    #define  LCD_P4                  PT
    #define  LCD_P5                  PT
    #define  LCD_P6                  PT
    #define  LCD_P7                  PT
    //LCD数据线所用寄存器的引脚
    #define  LCD_B0                  0      
    #define  LCD_B1                  1
    #define  LCD_B2                  2
    #define  LCD_B3                  3
    #define  LCD_B4                  4
    #define  LCD_B5                  5
    #define  LCD_B6                  6
    #define  LCD_B7                  7
    //LCD寄存器选择信号
    #define  LCDRS_P                  PK
    #define  LCDRS_B                  2      
    //LCD读写信号
    #define  LCDRW_P                  PK
    #define  LCDRW_B                  1
    //LCD使能信号
    #define  LCDE_P                   PK
    #define  LCDE_B                   0

//构件函数声明区

    //LCDInit:初始化LCD函数----------------------------------------------------*
    //功  能:初始化Lcd(HD44780),设置显示方式,清屏,AC自动+1                     *
    //参  数:无                                                                *
    //返  回:无                                                                *
    //内部调用函数:LCD_Command                                                 *
    //-------------------------------------------------------------------------*
    void LCDInit(void);                                             
                                               
    //LCDShow:在HD44780显示屏上显示数据----------------------------------------*
    //功  能:在HD44780显示屏显示str所指向的32个数据                            *
    //参  数:str=待显示的数组                                                  *
    //返  回:无                                                                *
    //内部调用函数:LCD_Command                                                 *
    //-------------------------------------------------------------------------*
    void LCDShow(uint8 str[]);      

    //LCD_Command:执行给定的cmd命令--------------------------------------------*
    //功  能:执行给定的cmd命令,且延时                                          *
    //参  数:cmd=待执行的命令                                                  *
    //返  回:无                                                                *
    //-------------------------------------------------------------------------*
    void LCD_Command(uint8 cmd);

#endif   
