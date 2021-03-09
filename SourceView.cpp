/*
 * Copyright 2020, Alex Hitech <ahitech@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */


#include "SourceView.h"



SourceTextView::SourceTextView (BRect rect,
								const char *name)
	: BTextView(rect,
				name,
				rect,
				B_FOLLOW_LEFT | B_FOLLOW_TOP,
				B_WILL_DRAW | B_FULL_UPDATE_ON_RESIZE | B_NAVIGABLE)
{
	return;
	
}

bool SourceTextView::AcceptsDrop(BMessage *archive)
{
	return true;		
}



bool SourceTextView::AcceptsPaste(BClipboard *clip)
{
	return true;
}





SourceView::SourceView (BRect rect,
						const char* name)
	: textView(NULL), scrollBars(NULL)
{
	textView = new SourceTextView(rect, "textView");
	if (textView)
	{
		scrollBars = new BScrollView("scroller",
									textView,
									B_FOLLOW_LEFT | B_FOLLOW_TOP,
									0,
									true,
									true,
									B_FANCY_BORDER);
	}
}



SourceView::~SourceView()
{
	if (textView) {
		textView->RemoveSelf();
		if (scrollBars) {
			delete scrollBars;
		}
		delete textView;
	}
}
