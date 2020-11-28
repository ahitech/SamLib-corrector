/*
 * Copyright 2020, Alex Hitech <ahitech@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */


#include "SourceView.h"



SourceTextView::SourceTextView (BRect rect,
								const char *name)
	: BTextView(rect,
				name,
				frame.InsetBy(5, 5),
				be_fixed_font,
				(rgb_color){0, 0, 0, 255},
				B_FOLLOW_LEFT | B_FOLLOW_TOP,
				B_WILL_DRAW | B_PULSE_NEEDED | B_FRAME_EVENTS | B_NAVIGABLE);
{
	
	
}

bool SourceTextView::AcceptsDrop(BMessage *archive)
{
		
}



bool SourceTextView::AcceptsPaste(BClipboard *clip)
{
	
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
						            B_FANCY_BORDER)
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
