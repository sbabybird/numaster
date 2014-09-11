// Specker.h: interface for the CSpecker class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPECKER_H__CE61C512_B40F_4223_AB61_849F65FD4BF7__INCLUDED_)
#define AFX_SPECKER_H__CE61C512_B40F_4223_AB61_849F65FD4BF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSpecker  
{
public:
	CSpecker();
	virtual ~CSpecker();

	void Test();

	void SpeckerNumber(int iNumber);

	BOOL PlaySoundWithName(LPCSTR sName);
};

#endif // !defined(AFX_SPECKER_H__CE61C512_B40F_4223_AB61_849F65FD4BF7__INCLUDED_)
