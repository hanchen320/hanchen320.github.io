//--------------------------------------------------------------------------*
// �ļ���: GeneralFun.h (ͨ�ú���ͷ�ļ�)                                    *
// ˵  ��: ͨ�ú���ͷ�ļ�                                                   *
//--------------------------------------------------------------------------*

#ifndef GENERALFUN_H          
#define GENERALFUN_H

//ͷ�ļ����������궨����
    #include        "Type.h"                   //���ͱ�������
  
//�Ĵ���λ�����궨��
    
    //���üĴ�����ĳһλΪ1
    #define BSET(bit,Register)     ((Register)|= (1<<(bit)))
    //���üĴ�����ĳһλΪ0  
    #define BCLR(bit,Register)     ((Register) &= ~(1<<(bit))) 
    //�õ��Ĵ�����ĳһλ״̬
    #define BGET(bit,Register)     (((Register) >> (bit)) & 1)  
  
//��������
    void Delay(uint16 count);                  //��ʱ
    
#endif
