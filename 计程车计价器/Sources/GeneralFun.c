//-------------------------------------------------------------------------*
// 文件名: GeneralFun.c                                                    *
// 说  明: 通用函数文件,包含一些通用函数,可自行添加函数                    *
//-------------------------------------------------------------------------*


//头文件包含，及宏定义区
 
    //头文件包含
    #include      "GeneralFun.h"           //通用函数头文件

//构件函数实现

    //---------------------------------------------------------------------*
    //函数名:Delay                                                         *
    //功  能:用程序的方法延时一段时间                                      *
    //参  数:k=延时长度(0-65535)                                           *
    //返  回:无                                                            *
    //---------------------------------------------------------------------*
    void Delay(uint16 k)
    {
        uint16 i,j;
        for (i=0; i<k; i++)
            for (j=0; j<=500; j++);
    }
