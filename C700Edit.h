/*
 *  C700Edit.h
 *  Chip700
 *
 *  Created by osoumen on 12/10/01.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#if AU
#include "plugguieditor.h"
#else
#include "aeffguieditor.h"
#endif

#include "ctooltipsupport.h"

#include "vstgui.h"
#include "C700GUI.h"
#include "Chip700defines.h"
#include "EfxAccess.h"

class C700Edit : public AEffGUIEditor, CControlListener
{
public:
					C700Edit( void *pEffect );
	virtual			~C700Edit();
	
	void			SetEfxAccess(EfxAccess* efxacc);
	void			SetParameterInfo(long index, float minValue, float maxValue, float defaultValue );
	void			SetLoopPoint( int lp );
	void			SetProgramName( const char *pgname );
	void			SetBRRData( const BRRData *brr );
	void			UpdateXMSNESText();
	void			SetTrackSelectorValue( int track );
	void			SetBankSelectorValue( int bank );
	
	virtual bool	getRect(ERect **);
	virtual bool	open(void *ptr);
	virtual void	close();
	
	virtual void	setParameter(long index, float value);
	virtual void	valueChanged(CControl *pControl);	
	long			getTag();

private:
	CBitmap				*m_pBackground;
	C700GUI				*m_pUIView;
	CTooltipSupport		*m_pTooltipSupport;
	
	EfxAccess			*efxAcc;
};
