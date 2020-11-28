/*
 * Copyright 2020, Alex Hitech <ahitech@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef SOURCE_VIEW_H
#define SOURCE_VIEW_H

#include <SupportDefs.h>

#include <ScrollView.h>
#include <TextView.h>


class SourceTextView : public BTextView 
{
	public:
		SourceTextView(BRect frame, const char *name);
		~SourceTextView();

		// This BTextView accepts HTML
		bool AcceptsDrop (BMessage *archive);
		bool AcceptsPaste(BClipboard *clipboard);
}


class SourceView
{
public:
	SourceView(BRect frame,
			   const char* name);
	~SourceView();
protected:
	SourceTextView		*textView;
	BScrollView 		*scrollBars;
};


#endif // SOURCE_VIEW_H
