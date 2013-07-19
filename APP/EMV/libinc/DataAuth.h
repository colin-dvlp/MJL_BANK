

#ifndef		_DATAAUTH_H
#define		_DATAAUTH_H


#ifndef		DATAAUTH_DATA
#define		DATAAUTH_DATA		extern
#endif

#include	<TypeDef.h>
#include	<EMVDef.h>
#include	<AppCrypt.h>


#ifdef __cplusplus
extern "C" {
#endif

#define			PKALGOINDICATOR			0x01
#define			HASHALGOINDICATOR			0x01
#define			CERTIFICATIONTRAILER		0xBC
#define			CERTIFICATIONHEADER		0x6A
#define			IPKCERTIFICATIONFORMAT	0x02
#define			STATICDATASIGNEDFORMAT	0x03
#define			ICCCERTIFICATIONFORMAT	0x04
#define			SIGNEDYNAMICDATAFORMAT	0x05

typedef	enum{AUTHSTYLE_NONE,AUTHSTYLE_SDA,AUTHSTYLE_DDA,AUTHSTYLE_CDA} AUTHSTYLE;

typedef struct
{
    UCHAR       aucRID[RIDDATALEN];
    UCHAR       ucCAPKI;
    UCHAR       ucHashInd;
    UCHAR       ucArithInd;
    UCHAR       ucIndex;
    UCHAR       ucModulLen;
    UCHAR       aucModul[MAXMODULLEN];
    UCHAR       ucExponentLen;
    UCHAR       aucExponent[MAXEXPONENTLEN];
    UCHAR       aucExpireDate[8];
    UCHAR       aucCheckSum[HASHDATALEN];
}CAPK, *PCAPK;

typedef struct {
	UCHAR 		aucRID[RIDDATALEN];
	UCHAR		ucCAPKI;
	UCHAR	    aucCertSerial[CERTSERIALLEN];
}IPKREVOKE,*PIPKREVOKE;


DATAAUTH_DATA	USHORT		AuthDataLen;
DATAAUTH_DATA	UCHAR		AuthData[MAXAUTHDATALEN];
DATAAUTH_DATA	USHORT		IPKModuleLen;
DATAAUTH_DATA	UCHAR		IPKModule[MAXMODULLEN];
DATAAUTH_DATA	USHORT		ICCModuleLen;
DATAAUTH_DATA	UCHAR		ICCModule[MAXMODULLEN];
DATAAUTH_DATA	UCHAR		ICCExponentLen;
DATAAUTH_DATA	UCHAR		ICCExponent[MAXEXPONENTLEN];
DATAAUTH_DATA	USHORT		ICCPinModuleLen;
DATAAUTH_DATA	UCHAR		ICCPinModule[MAXMODULLEN];
DATAAUTH_DATA	UCHAR		ICCPinExponentLen;
DATAAUTH_DATA	UCHAR		ICCPinExponent[MAXEXPONENTLEN];

void		DATAAUTH_Init(void);
AUTHSTYLE	DATAAUTH_Style(PUCHAR pucAIP);
void	DATAAUTH_SetErrorStatus(BOOL bMissData);
UCHAR	DATAAUTH_Process(void);
UCHAR	DATAAUTH_SDAProcess(void);
UCHAR	DATAAUTH_RetrievalCAPK(PUCHAR pucRID,UCHAR ucCAPKI);
UCHAR	DATAAUTH_RecoveryIPK(void);
UCHAR	DATAAUTH_VerifyStaticAppData(void);
UCHAR	DATAAUTH_DDAProcess(void);
UCHAR	DATAAUTH_CDAProcess(GACPHASE enGACPhase,CRYPTTYPE enRespCID);
UCHAR	DATAAUTH_RetrievalICCPK(void);
BOOL	DATAAUTH_CheckDDADDOLValid(void);
UCHAR	DATAAUTH_DynamicDataAuth(void);
UCHAR	DATAAUTH_RetrievalICCPinPK(void);
BOOL	DATAAUTH_CheckDDADataObject(void);
BOOL	DATAAUTH_CheckAppCryptDataObject(void);
BOOL	DATAAUTH_CheckSDADataObject(void);
UCHAR	DATAAUTH_RecoveryICCPK(void);
BOOL	DATAAUTH_CheckCDOLValid(PUCHAR pucCDOL);
BOOL	DATAAUTH_CheckCertVaild(UCHAR	 aucSerial[CERTSERIALLEN]);
#ifdef __cplusplus
}
#endif
#endif


