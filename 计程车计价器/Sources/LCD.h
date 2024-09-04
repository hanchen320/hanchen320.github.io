//--------------------------------------------------------------------------*
// �ļ���: LCD.h                                                            *
// ˵  ��: LCD��������ͷ�ļ�                                                *
//--------------------------------------------------------------------------*
 
#ifndef LCD_H
#define LCD_H

//ͷ�ļ����������궨����

    //ͷ�ļ����� 
    #include    "GPIO.h"         //��ͨIO�ڹ���ͷ�ļ�
/*    
    //Һ����ʾ�Ĵ�������־λ����
    //LCD���������õļĴ���
    #define  LCD_P0                  PAD1
    #define  LCD_P1                  PAD1
    #define  LCD_P2                  PAD1
    #define  LCD_P3                  PAD1
    #define  LCD_P4                  PAD1
    #define  LCD_P5                  PJ
    #define  LCD_P6                  PJ
    #define  LCD_P7                  PS
    //LCD���������üĴ���������
    #define  LCD_B0                  3      
    #define  LCD_B1                  4
    #define  LCD_B2                  5
    #define  LCD_B3                  6
    #define  LCD_B4                  7
    #define  LCD_B5                  7
    #define  LCD_B6                  6
    #define  LCD_B7                  3
    //LCD�Ĵ���ѡ���ź�
    #define  LCDRS_P                  PP
    #define  LCDRS_B                  4      
    //LCD��д�ź�
    #define  LCDRW_P                  PP
    #define  LCDRW_B                  5
    //LCDʹ���ź�
    #define  LCDE_P                   PP
    #define  LCDE_B                   7
 */   
      //Һ����ʾ�Ĵ�������־λ����
    //LCD���������õļĴ���
    #define  LCD_P0                  PT
    #define  LCD_P1                  PT
    #define  LCD_P2                  PT
    #define  LCD_P3                  PT
    #define  LCD_P4                  PT
    #define  LCD_P5                  PT
    #define  LCD_P6                  PT
    #define  LCD_P7                  PT
    //LCD���������üĴ���������
    #define  LCD_B0                  0      
    #define  LCD_B1                  1
    #define  LCD_B2                  2
    #define  LCD_B3                  3
    #define  LCD_B4                  4
    #define  LCD_B5                  5
    #define  LCD_B6                  6
    #define  LCD_B7                  7
    //LCD�Ĵ���ѡ���ź�
    #define  LCDRS_P                  PK
    #define  LCDRS_B                  2      
    //LCD��д�ź�
    #define  LCDRW_P                  PK
    #define  LCDRW_B                  1
    //LCDʹ���ź�
    #define  LCDE_P                   PK
    #define  LCDE_B                   0

//��������������

    //LCDInit:��ʼ��LCD����----------------------------------------------------*
    //��  ��:��ʼ��Lcd(HD44780),������ʾ��ʽ,����,AC�Զ�+1                     *
    //��  ��:��                                                                *
    //��  ��:��                                                                *
    //�ڲ����ú���:LCD_Command                                                 *
    //-------------------------------------------------------------------------*
    void LCDInit(void);                                             
                                               
    //LCDShow:��HD44780��ʾ������ʾ����----------------------------------------*
    //��  ��:��HD44780��ʾ����ʾstr��ָ���32������                            *
    //��  ��:str=����ʾ������                                                  *
    //��  ��:��                                                                *
    //�ڲ����ú���:LCD_Command                                                 *
    //-------------------------------------------------------------------------*
    void LCDShow(uint8 str[]);      

    //LCD_Command:ִ�и�����cmd����--------------------------------------------*
    //��  ��:ִ�и�����cmd����,����ʱ                                          *
    //��  ��:cmd=��ִ�е�����                                                  *
    //��  ��:��                                                                *
    //-------------------------------------------------------------------------*
    void LCD_Command(uint8 cmd);

#endif   
