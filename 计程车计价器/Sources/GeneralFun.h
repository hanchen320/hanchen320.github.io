//--------------------------------------------------------------------------*
// 文件名: GeneralFun.h (通用函数头文件)                                    *
// 说  明: 通用函数头文件                                                   *
//--------------------------------------------------------------------------*

#ifndef GENERALFUN_H          
#define GENERALFUN_H

//头文件包含，及宏定义区
    #include        "Type.h"                   //类型别名定义
  
//寄存器位操作宏定义
    
    //设置寄存器中某一位为1
    #define BSET(bit,Register)     ((Register)|= (1<<(bit)))
    //设置寄存器中某一位为0  
    #define BCLR(bit,Register)     ((Register) &= ~(1<<(bit))) 
    //得到寄存器中某一位状态
    #define BGET(bit,Register)     (((Register) >> (bit)) & 1)  
  
//函数声明
    void Delay(uint16 count);                  //延时
    
#endif
