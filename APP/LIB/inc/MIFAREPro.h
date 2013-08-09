#ifndef _MIFAREPRO_H
#define _MIFAREPRO_H
#include "new_drv.h"
#include "fsync_drvs.h"
/*
param : ucDataBlockIndex
type:   unsigned char 
Mifare Classic 4k Blocks - Minimum Index : 0
						 - Maximum Index : 255
*/
unsigned char MIFARE_readCardNo(DRV_OUT *pxMifare,unsigned char ucDataBlockIndex,unsigned char *pucOutCardNo,unsigned short *puiOutLen);
/*
return value List:
typedef enum MIFARE_ERR_INDEX
{
     HALMIFAREERR_SUCCESS    =  0,  //��ȷ
     HALMIFAREERR_NOTAG      =  1,  //�޿�
     HALMIFAREERR_CRC        =  2,  //��ƬCRC У�����
     HALMIFAREERR_EMPTY      =  3, //��ֵ�������
     HALMIFAREERR_AUTH       =  4, //��֤���ɹ�
     HALMIFAREERR_PARITY     =  5, //��Ƭ��żУ�����
     HALMIFAREERR_CODE       =  6, //ͨѶ����(BCC У���) 
     HALMIFAREERR_SERNR      =  8, //��Ƭ���кŴ���(anti-collision ����) 
     HALMIFAREERR_SELECT     =  9, //��Ƭ���ݳ����ֽڴ���(SELECT ����) 
     HALMIFAREERR_NOTAUTH    =  10, //��Ƭû��ͨ����֤
     HALMIFAREERR_BITCOUNT   =  11, //�ӿ�Ƭ���յ���λ������
     HALMIFAREERR_BYTECOUNT  =  12, //�ӿ�Ƭ���յ����ֽ������󣨽���������Ч��
     HALMIFAREERR_REST       =  13, //����restore ��������
     HALMIFAREERR_TRANS      =  14, //����transfer ��������
     HALMIFAREERR_WRITE		 =  15, //����write ��������
     HALMIFAREERR_INCR		 =  16, //����increment ��������
     HALMIFAREERR_DECR       =  17, //����decrement ��������
     HALMIFAREERR_READ       =  18, //����read ��������
     HALMIFAREERR_LOADKEY    =  19, //����LOADKEY ��������
     HALMIFAREERR_FRAMING    =  20, //FM1715 ֡����
     HALMIFAREERR_RESQ       =  21, //����req ��������
     HALMIFAREERR_SEL        =  22, //����sel ��������
     HALMIFAREERR_ANTICOLL   =  23, //����anticoll ��������
     HALMIFAREERR_INTIVAL    =  24, //���ó�ʼ����������
     HALMIFAREERR_READVAL    =  25, //���ø߼�����ֵ��������
     HALMIFAREERR_DESELECT   =  26, //ȡ��ѡ������
     HALMIFAREERR_CMD        =  42, //�������
     HALMIFAREERR_INIT       =  43,  //��ʼ��ʧ��
     HALMIFAREERR_UNKNOWN    =  44, //δ�ҵ�Ӳ��
     HALMIFAREERR_COLLISION  =  45, //λ��ͻ
     HALMIFAREERR_FRAME      =  46, //Frame ����
     HALMIFAREERR_ATS_LEN    =  47, //Ats ���ȴ���
     HALMIFAREERR_ATS_ERR    =  48, //Ats ȡats���� 
	 HALMIFAREERR_APP_ERR    =  49, //Ӧ���쳣


	 MIFARE_UNKNOWN_ERR      =  0xFF
}MifareErrIndex;
	

	for English instance:
	
		mifareErrTab[]=
    {
	{HALMIFAREERR_SUCCESS,				{"SUCCESS !"}},
	{HALMIFAREERR_NOTAG,				{"No Tag"}},
	{HALMIFAREERR_CRC,					{"CRC Err"}},
	{HALMIFAREERR_EMPTY,				{"DATA ABORT!"}},
	{HALMIFAREERR_AUTH,					{"AUTH FAIL"}},
	{HALMIFAREERR_PARITY,				{"PARITY Err"}},
	{HALMIFAREERR_CODE,					{"BCC Err"}},
	{HALMIFAREERR_SERNR,				{"anti-collision Err"}},
	{HALMIFAREERR_SELECT,				{"SELECT Err"}},
	{HALMIFAREERR_NOTAUTH,				{"Not Auth yet"}},
	{HALMIFAREERR_BITCOUNT,				{"INVALID BITS"}},
    {HALMIFAREERR_BYTECOUNT,			{"INVALID BYTES"}},
	{HALMIFAREERR_REST,					{"Restore Err"}},
	{HALMIFAREERR_TRANS,				{"transfer Err"}},
	{HALMIFAREERR_WRITE,				{"Write Err"}},
	{HALMIFAREERR_INCR,					{"increment Err"}},
	{HALMIFAREERR_DECR,					{"decrement Err"}},
	{HALMIFAREERR_READ,					{"read File Err"}},
	{HALMIFAREERR_LOADKEY,				{"LoadKey Err"}},
	{HALMIFAREERR_FRAMING,				{"FM1715 Fail"}},
	{HALMIFAREERR_RESQ,					{"Request Err"}},
	{HALMIFAREERR_SEL,					{"sel Err"}},
	{HALMIFAREERR_ANTICOLL,				{"anticoll Err"}},
	{HALMIFAREERR_INTIVAL,				{"INITIAL Err"}},
	{HALMIFAREERR_READVAL,				{"Err READVAL"}},
	{HALMIFAREERR_DESELECT,				{"Deselect Err"}},
	{HALMIFAREERR_CMD,					{"CMD Err"}},
	{HALMIFAREERR_INIT,					{"INITIAL FAIL"}},
	{HALMIFAREERR_UNKNOWN,				{"HARDWARE NOT FND"}},
	{HALMIFAREERR_COLLISION,			{"COLLISION !"}},
	{HALMIFAREERR_FRAME,				{"WRONG FRAME"}},
	{HALMIFAREERR_ATS_LEN,			    {"Invalid Ats"}},
	{HALMIFAREERR_ATS_ERR,			    {"Ats Err"}},
	{MIFARE_UNKNOWN_ERR,				{"UNKNOWN ERR"}}
};
*/



#endif
