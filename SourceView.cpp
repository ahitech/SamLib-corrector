/*
 * Copyright 2020, Alex Hitech <ahitech@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#include <Clipboard.h>

#include "SourceView.h"



SourceTextView::SourceTextView (BRect rect,
								const char *name)
	: BTextView(rect,
				name,
				rect.InsetBySelf(5,5),
				B_FOLLOW_ALL_SIDES,
				B_WILL_DRAW | B_FULL_UPDATE_ON_RESIZE | B_NAVIGABLE)
{
	rgb_color textColor = ui_color(B_DOCUMENT_TEXT_COLOR);
	this->SetFontAndColor(be_fixed_font, B_FONT_ALL, &textColor);
						  
	return;
	
}

bool SourceTextView::AcceptsDrop(BMessage *archive)
{
	return true;		
}



bool SourceTextView::AcceptsPaste(BClipboard *clipboard)
{
	if (! clipboard->Lock())
		return false;
/*	
	BMessage* clip = clipboard->Data();
	if (clip) {
		int index = 0;
		char* nameFound,
		type_code* typeFound,
		int32* countFound;
		status_t returnStatus = B_OK;

		returnStatus =	clip->GetInfo(B_MIME_TYPE, index, nameFound, typeFound, countFound);
		
		if (nameFound
		clip->FindData("text/html", B_MIME_TYPE,
          				(const void **)text, textlen)2;

	} */
	clipboard->Unlock();
		
	return true;
}




/*		scrollBars = new BScrollView("scroller",
									textView,
									B_FOLLOW_LEFT | B_FOLLOW_TOP,
									0,
									true,
									true,
									B_FANCY_BORDER);
*/
