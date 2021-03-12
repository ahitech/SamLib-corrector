/*
 * Copyright 2020, Alex Hitech <ahitech@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */

#include "MainView.h"



MainView::MainView (BRect frame)
	: 	BView (frame, "main View",
				B_FOLLOW_ALL_SIDES,
				B_WILL_DRAW | B_NAVIGABLE),
		sourceView(NULL)
{
	this->SetViewColor (ui_color(B_MENU_BACKGROUND_COLOR));
	BGroupLayout* group = new BGroupLayout(B_VERTICAL);
	group->SetInsets(5, 5, 5, 5);
	this->SetLayout(group);
	
	this->sourceView = new SourceTextView (frame.InsetBySelf(5, 5),
								 "Source");
	scrollView = new BScrollView("Source Scroll", sourceView,
									B_FOLLOW_LEFT | B_FOLLOW_TOP,
									0,
									true,
									true,
									B_FANCY_BORDER);

	BLayoutItem* sourceViewItem = group->AddView (scrollView);
	sourceViewItem->SetExplicitAlignment(BAlignment(B_ALIGN_USE_FULL_WIDTH,
												  B_ALIGN_USE_FULL_HEIGHT));
}


MainView::~MainView ()
{
	if (scrollView) {
		scrollView->RemoveSelf();
		sourceView->RemoveSelf();
		delete sourceView;
		delete scrollView;
		sourceView = NULL;
	}
}



void MainView::AttachedToWindow() 
{
   if ( Parent() )
      SetViewColor(Parent()->ViewColor());
   BView::AttachedToWindow();
}
