//--------------------------------------------------------------------------*
// �ļ���: Type.h (�������ͱ����ļ�)                                        *
// ˵  ��: ����������͵ı���,Ŀ��:                                         *
//         (1)���̱���������д����;                                         *
//         (2)���������ֲ,���Ը�����Ҫ�������.                            *                       
//--------------------------------------------------------------------------*

#ifndef TYPE_H           
#define TYPE_H

	typedef unsigned char         uint8;             //  8 λ�޷�����
	typedef unsigned short int    uint16;            // 16 λ�޷�����
	typedef unsigned long int     uint32;            // 32 λ�޷�����
	typedef char                  int8;              //  8 λ�з�����
	typedef short int             int16;             // 16 λ�з����� 
	typedef int                   int32;             // 32 λ�з�����
	 
//���Ż���������,�ؼ���volatile
	typedef volatile uint8        vuint8;            //  8 λ�޷����� 
	typedef volatile uint16       vuint16;           // 16 λ�޷����� 
	typedef volatile uint32       vuint32;           // 32 λ�޷����� 
	typedef volatile int8         vint8;             //  8 λ�з����� 
	typedef volatile int16        vint16;            // 16 λ�з����� 
	typedef volatile int32        vint32;            // 32 λ�з����� 
	
#endif

