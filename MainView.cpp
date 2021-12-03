/*
 * Copyright 2020, Alex Hitech <ahitech@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */

#include "MainView.h"



MainView::MainView (BRect frame)
	: 	BView (frame, "main View",
				B_FOLLOW_ALL_SIDES,
				B_WILL_DRAW | B_NAVIGABLE),
		sourceView(NULL),
		targetView(NULL)
{
	this->SetViewColor (ui_color(B_MENU_BACKGROUND_COLOR));
	BGroupLayout* group = new BGroupLayout(B_VERTICAL);
	group->SetInsets(10, 10, 10, 10);
	this->SetLayout(group);
		
	mainMenuBar = new BMenuBar(frame, "MainMenuBar");
	BLayoutItem* menuBarLayoutItem = group->AddView (mainMenuBar);
	menuBarLayoutItem->SetExplicitAlignment(BAlignment(B_ALIGN_USE_FULL_WIDTH,
												  B_ALIGN_VERTICAL_UNSET));
	
	BRect upper = frame.InsetByCopy(10, 10);
	BRect lower = upper;
	BRect textFrame = upper.InsetByCopy(5, 5);
	
	upper.bottom = upper.Height() / 2;
	this->sourceView = new SourceTextView (upper, textFrame,
								 "Source");
	sourceScrollView = new BScrollView("Source Scroll", sourceView,
									B_FOLLOW_LEFT | B_FOLLOW_TOP,
									0,
									true,
									true,
									B_FANCY_BORDER);

	BLayoutItem* sourceViewItem = group->AddView (sourceScrollView);
	sourceViewItem->SetExplicitAlignment(BAlignment(B_ALIGN_USE_FULL_WIDTH,
												  B_ALIGN_USE_FULL_HEIGHT));

	lower.top = lower.Height() / 2;												  
	this->targetView = new SourceTextView (lower, textFrame,
								 "Target");
	targetScrollView = new BScrollView("Target Scroll", targetView,
									B_FOLLOW_LEFT | B_FOLLOW_TOP,
									0,
									true,
									true,
									B_FANCY_BORDER);

	BLayoutItem* targetViewItem = group->AddView (targetScrollView);
	targetViewItem->SetExplicitAlignment(BAlignment(B_ALIGN_USE_FULL_WIDTH,
												  B_ALIGN_USE_FULL_HEIGHT));
}


MainView::~MainView ()
{
	if (sourceScrollView) {
		sourceScrollView->RemoveSelf();
		sourceView->RemoveSelf();
		delete sourceView;
		delete sourceScrollView;
		sourceView = NULL;
	}
	if (targetScrollView) {
		targetScrollView->RemoveSelf();
		targetView->RemoveSelf();
		delete targetView;
		delete targetScrollView;
		targetView = NULL;
	}
}



void MainView::AttachedToWindow() 
{
   if ( Parent() )
      SetViewColor(Parent()->ViewColor());
   BView::AttachedToWindow();
}
