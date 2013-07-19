

#ifndef		_APPCRYPT_H
#define		_APPCRYPT_H

#ifndef		APPCRYPT_DATA
#define		APPCRYPT_DATA	extern
#endif


#include	<TermActAnalysis.h>
#include	<EMVDef.h>
#ifdef		__cplusplus
extern	"C"
{
#endif




#define			SCRIPTNOTPERFORMED	0x00
#define			SCRIPTPROCESSFAILED	0x01
#define			SCRIPTPROCESSSUCCESS	0x02

#define			ADVICEREQUIRED			0x08
#define			SERVICENOTALLOWED		0x01
#define			PINTRYLIMITEXCEED		0x02
#define			ISSUERAUTHFAILED		0x03

#define			ARC_OFFLINEAPPROVED	"Y1"
#define			ARC_OFFLINEDECLINED	"Z1"
#define			ARC_REFERRALAPPROVED	"Y2"
#define			ARC_REFERRALDECLINED	"Z2"
#define			ARC_ONLINEFAILOFFLINEAPPROVED	"Y3"
#define			ARC_ONLINEFAILOFFLINEDECLINED	"Z3"

typedef		enum {FIRSTGACPHASE,SECONDGACPHASE}GACPHASE;
typedef		struct
{
    UCHAR  	ucSeqNumber : 4,
            ucScriptResult : 4;
	UCHAR	aucScriptID[SCRIPTIDLEN];
}SCRIPTRESULT;

typedef		struct
{
	UCHAR	ucScriptTag;
	USHORT	uiScriptLen;
	UCHAR	aucScriptData[MAXSCRIPTDATALEN];
}ISSURESCRIPT,*PISSURESCRIPT;
APPCRYPT_DATA	UCHAR	CDOL1Data[MAXCDOLDATALEN];
APPCRYPT_DATA	UCHAR	CDOL1DataLen;
APPCRYPT_DATA	UCHAR	CDOL2Data[MAXCDOLDATALEN];
APPCRYPT_DATA	UCHAR	CDOL2DataLen;
APPCRYPT_DATA	UCHAR	GACRespLen;
APPCRYPT_DATA	UCHAR	GACRespData[MAXGACDATALEN];
APPCRYPT_DATA	UCHAR	IssureScriptNum;
APPCRYPT_DATA	ISSURESCRIPT	IssureScript[MAXSCRIPTNUMS];


UCHAR	APPCRYPT_CheckGACMandaData(UCHAR ucGACPHASE,BOOL bCDAFlag);
UCHAR	APPCRYPT_GenerateAC(UCHAR ucGACPHASE,CRYPTTYPE reqCrypt,BOOL bCDAFlag);
UCHAR	APPCRYPT_OfflineProcess(CRYPTTYPE reqCrypt);
UCHAR	APPCRYPT_ICTransDataPack(PUCHAR pTransDol,UCHAR ucTransDolLen,PUCHAR pTransDolData,USHORT *puiTransDolDataLen);
BOOL	APPCRYPT_CheckScriptValid(PUCHAR pScript,UCHAR ucScriptLen);
UCHAR	APPCRYPT_ScriptProcess(PUCHAR pScriptTag);
UCHAR	APPCRYPT_OnlineProcess(BOOL bConnectSuccess/*,UCHAR ucAuthRespCode,PUCHAR pICTransData,USHORT uiICTransDataLen*/);
UCHAR	APPCRYPT_GetGACData(PUCHAR	pIccData,USHORT uiDataLen);
UCHAR	APPCRYPT_OnlineRespDataProcess(PUCHAR pAuthCode,PUCHAR	pRespData,USHORT	uiRespDataLen);
UCHAR	APPCRIPT_AppendScript(UCHAR ucTag,PUCHAR pScriptData,USHORT uiScriptLen);

#ifdef		__cplusplus
}
#endif

#endif
