//--------------------------------------------------------------------------*
//文件名: Includes.h                                                        *
//说  明: 总头文件,本文件包含:                                              *
//        主函数(main)文件中用到的头文件、外部函数声明                      *
//--------------------------------------------------------------------------*
#ifndef INCLUDES_H
#define INCLUDES_H

//通用头文件
  #include         "Type.h"                   //类型别名定义头文件
  #include         "GeneralFun.h"             //通用函数头文件
//主芯片头文件  
  #include         "MC9S12XS128.h"            //芯片宏定义头文件
  #include         "MCUInit.h"                //芯片初始化头文件                 
//包含面向硬件对象头文件(即构件模块)       
  #include         "GPIO.h"                   //普通IO口构件头文件
  #include         "Light.h"                  //小灯构件头文件
  #include         "SCI.h"                    //SCI串口构件头文件
  #include         "LCD.h"                    //LCD构件头文件

#endif