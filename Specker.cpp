// Specker.cpp: implementation of the CSpecker class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NumMaster.h"
#include "Specker.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSpecker::CSpecker()
{

}

CSpecker::~CSpecker()
{

}

BOOL CSpecker::PlaySoundWithName(LPCSTR sName)
{
	HINSTANCE hRes=AfxGetInstanceHandle();
	
	HRSRC hr=FindResource(hRes,sName,"WAVE");
	
	HGLOBAL hg=LoadResource(hRes,hr);
	
	LPSTR lp=(LPSTR)LockResource(hg);
	
	BOOL bRet = sndPlaySound(lp,SND_MEMORY|SND_SYNC/*SND_ASYNC*/);
	
	FreeResource(hg);
	
	return bRet;
}

void CSpecker::Test()
{
	PlaySoundWithName("IDR_0");
}

void CSpecker::SpeckerNumber(int iNumber)
{
	BOOL bRe = FALSE;

	BOOL bw = FALSE;

	BOOL bq = FALSE;

	BOOL bb = FALSE;
	
	if (iNumber/10000 > 0)
	{
		SpeckerNumber(iNumber/10000);

		PlaySoundWithName("IDR_WAN");
		bw = TRUE;

		SpeckerNumber(iNumber%10000);
	}

	else if (iNumber/1000 > 0)
	{
		SpeckerNumber(iNumber/1000);

		PlaySoundWithName("IDR_QIAN");
		bq = TRUE;

		SpeckerNumber(iNumber%1000);
	}

	else if (iNumber/100 > 0)
	{
		if (bw && !bq)
			PlaySoundWithName("IDR_0");

		SpeckerNumber(iNumber/100);

		PlaySoundWithName("IDR_BAI");
		
		bb = TRUE;

		SpeckerNumber(iNumber%100);
	}

	else if (iNumber/10 > 0)
	{
		if (bw||bq && !bb)
			PlaySoundWithName("IDR_0");

		SpeckerNumber(iNumber/10);

		PlaySoundWithName("IDR_10");
		
		bRe = TRUE;

		SpeckerNumber(iNumber%10);
	}

	else {
		if (bw||bq||bb && !bRe)
			PlaySoundWithName("IDR_0");
		switch(iNumber) 
		{
		case 0:
			{
				PlaySoundWithName("IDR_0");
				break;
			}
			
		case 1:
			{
				PlaySoundWithName("IDR_1");
				break;
			}
			
		case 2:
			{
				PlaySoundWithName("IDR_2");
				break;
			}
			
		case 3:
			{
				PlaySoundWithName("IDR_3");
				break;
			}
			
		case 4:
			{
				PlaySoundWithName("IDR_4");
				break;
			}
			
		case 5:
			{
				PlaySoundWithName("IDR_5");
				break;
			}
			
		case 6:
			{
				PlaySoundWithName("IDR_6");
				break;
			}
			
		case 7:
			{
				PlaySoundWithName("IDR_7");
				break;
			}
			
		case 8:
			{
				PlaySoundWithName("IDR_8");
				break;
			}
			
		case 9:
			{
				PlaySoundWithName("IDR_9");
				break;
			}
			
		default: break;
		}
	}
}
