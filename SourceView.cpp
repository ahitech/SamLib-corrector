/*!	\file
 *	\brief	Implementation of the SourceTextView class.
 * Copyright 2020, Alex Hitech <ahitech@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#include <Clipboard.h>

#include "SourceView.h"



/*!	\brief		Constructor
 *	\param[in]	rect	The frame of the text box
 *	\param[in]	name	The name of the BView
 *	\details	Sets the color of the text to `B_DOCUMENT_TEXT_COLOR` and the
 *				font to `be_fixed_font`.
 */
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



/*!	\brief		Checks whether the message dropped onto view contains supported format.
 *	\param[in]	data	The message to be checked
 *	\returns	`true`	If a data of supported format is found<BR>
 *				`false`	Otherwise
 */
bool SourceTextView::AcceptsDrop(BMessage *data)
{
	bool toReturn;
	BString htmlType("text/html");
	
	int countFound, i = 0;
		// Perform the check
	countFound = DoesMessageHaveMIMEtype(data, htmlType);
	if (countFound > 0) {
		toReturn = true;		// There is something supported
	} else {
		BTextView::AcceptsDrop(data);	// Otherwise we check with the base function
	}
	return toReturn;
}



/*!	\brief		Checks whether the clipboard contains supported data type.
 *	\param[in]	clipboard	The clipboard to be checked
 *	\returns	`true`	If the data type is supported<BR>
 *				`false`	Otherwise
 *	\details	Calls the SourceTextView#AcceptsDrop() function.
 */
bool SourceTextView::AcceptsPaste(BClipboard *clipboard)
{
	BMessage*	data(NULL);
	bool toReturn = false;
	
	clipboard->Lock();			// Lock the clipboard - now the data inside won't change
	data = clipboard->Data();	// Obtain the data inside
	toReturn = this->AcceptsDrop(data);	// Code reuse
	clipboard->Unlock();				// Unlock the clipboard
	return toReturn;
}



/*!	\brief		Checks whether the type encoded in BString is contained in the message.
 *	\param[in]	data		The message to be checked
 *	\param[in]	type		The type to be searched for
 *	\returns	number of items of this type in the message<BR>
 *				`0` in case there are none.
 */
int	SourceTextView::DoesMessageHaveMIMEtype(BMessage *data,
											BString type)
{
	int toReturn = 0;
	if (data) {
		status_t	res;
		type_code	typeInMessage;
		int32		countFound;
		res = data->GetInfo(type.String(), &typeInMessage, &countFound);
		if (B_OK == res && B_MIME_TYPE == typeInMessage) {
			toReturn = (int )countFound;
		}
	}
	return toReturn;
}



/**	\brief	This function is called when "Paste" is clicked in the window.
 *	\param[in]	clipboard	The clipboard to paste from.
 */
void SourceTextView::Paste(BClipboard* clipboard)
{
	clipboard->Lock();
	BMessage* data = clipboard->Data();
	BString htmlType("text/html");
	clipboard->Unlock();
	if (data &&
		DoesMessageHaveMIMEtype(data, htmlType))
	{	// There is some HTML inside that we should read
		char text[1024];
		ssize_t	textLen;
		if (B_OK == data->FindData(htmlType.String(), B_MIME_TYPE, (const void**)text, &textLen))
		{	// Successfully got the data
			BString textString(text);
			int32 start, finish;
			GetSelection(&start, &finish);
			DeleteText(start, finish);
			InsertText(textString.String(), (int32)textLen, start, NULL);
		}
	}
	else
	{
		BTextView::Paste(clipboard);		// Calling the base class implementation to paste 
	}
}



void SourceTextView::MessageReceived(BMessage* in)
{
	BTextView::MessageReceived(in);	
}

/*		scrollBars = new BScrollView("scroller",
									textView,
									B_FOLLOW_LEFT | B_FOLLOW_TOP,
									0,
									true,
									true,
									B_FANCY_BORDER);
*/
