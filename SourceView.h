/*
 * Copyright 2020, Alex Hitech <ahitech@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef SOURCE_VIEW_H
#define SOURCE_VIEW_H

#include <SupportDefs.h>

#include <Rect.h>
#include <ScrollView.h>
#include <TextView.h>

/*!	\class		SourceTextView	SourceView.h
 *	\brief		This class holds the data to be processed.
 *	\details	Pasting from the text editor is performed into this View.
 *				Therefore, it has to accept HTML and support drag-n-drop.
 */
class SourceTextView : public BTextView 
{
	public:
		SourceTextView(BRect frame, const char *name);
		virtual ~SourceTextView() {};

		// This BTextView accepts HTML
		bool AcceptsDrop (BMessage *archive);
		bool AcceptsPaste(BClipboard *clipboard);
};

/*!	\class		SourceView	SourceView.h
 *	\brief		SourceTextView with scrollbars.
 */
class SourceView : public BScrollView
{
public:
	SourceView(BRect frame,
			   const char* name);
	~SourceView();
	
	void RemoveSelf() { BScrollView::RemoveSelf(); }
protected:
	SourceTextView		*textView;
	BScrollView 		*scrollBars;
};


#endif // SOURCE_VIEW_H
