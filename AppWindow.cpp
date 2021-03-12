#include <stdio.h>
#include <Font.h>
#include <Rect.h>
#include <String.h>


#include "MainView.h"
#include "Application.h"

AppWindow::AppWindow () :
	BWindow (BRect (100, 100, 500, 500),
			 "SamLib Helper",
			 B_TITLED_WINDOW,
			 B_NOT_ZOOMABLE | B_ASYNCHRONOUS_CONTROLS)
{
	BGroupLayout* group = new BGroupLayout(B_VERTICAL);
	group->SetInsets(0, 0, 0, 0);
	this->SetLayout(group);
	mainView = new MainView (Bounds());
	BLayoutItem* mainViewItem = group->AddView (mainView);
	mainViewItem->SetExplicitAlignment(BAlignment(B_ALIGN_USE_FULL_WIDTH,
												  B_ALIGN_USE_FULL_HEIGHT));
}


bool AppWindow::QuitRequested() {
	be_app->PostMessage(B_QUIT_REQUESTED);
	return BWindow::QuitRequested();
}


AppWindow::~AppWindow ()
{

}


void AppWindow::WindowActivated (bool active)
{
	BWindow::WindowActivated(active);
}


void AppWindow::MessageReceived (BMessage *in)
{
	BWindow::MessageReceived(in);
	switch (in->what)
	{
		case B_UNMAPPED_KEY_DOWN:
			break;
		case B_MODIFIERS_CHANGED:
			break;
	};
}
