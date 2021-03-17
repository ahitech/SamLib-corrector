/*
 * Copyright 2020, Alex Hitech <ahitech@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H

#include <View.h>
#include <LayoutBuilder.h>
#include <SupportDefs.h>

#include "SourceView.h"


class MainView :
	public BView
{
public:
	MainView (BRect);
	~MainView ();
	
	void AttachedToWindow();
private:
	SourceTextView* sourceView;
	BScrollView*	sourceScrollView;
	
	SourceTextView*	targetView;
	BScrollView*	targetScrollView;
};


#endif // SOURCE_VIEW_H
