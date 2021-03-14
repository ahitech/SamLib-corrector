/*!	\file	SourceView.h
 *	\brief	Declaration of the SourceTextView class
 * Copyright 2020, Alex Hitech <ahitech@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef SOURCE_VIEW_H
#define SOURCE_VIEW_H

#include <SupportDefs.h>

#include <Rect.h>
#include <ScrollView.h>
#include <String.h>
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
		virtual bool AcceptsDrop (BMessage *archive);
		virtual bool AcceptsPaste(BClipboard *clipboard);
		
		virtual void Paste(BClipboard* clipboard);
		virtual void MessageReceived(BMessage* in);
	protected:
		int DoesMessageHaveMIMEtype(BMessage* , BString);
};


#endif // SOURCE_VIEW_H
