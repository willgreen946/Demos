#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Multiline_Output.H>
#include "Window.hpp"
#include "System.h"

namespace WIN
{
	void
	Window::CreateMenuBar(void)
	{
		Fl_Menu_Bar * menuBar;
		Fl_Menu_Item menuItems[] = {
				/* File sub menu */
				{ "&File", 0, 0, 0, FL_SUBMENU },
				{ "&New File", 0, (Fl_Callback *) NULL },
				{0},
				/* Edit sub menu */
				{ "&Edit", 0, 0, 0, FL_SUBMENU },
				{ "&New File", 0, (Fl_Callback *) NULL },
				{0},
				/* Program settings sub menu */
				{ "&Program", 0, 0, 0, FL_SUBMENU },
				{ "&Quit", 0, (Fl_Callback *) NULL },
				{0},
				/* End of the menu */
				{0},
			};

		menuBar = new Fl_Menu_Bar(
			0, 0, WIN::MAX_X, WIN::MAX_Y / 16);

		menuBar->box(BOX_TYPE);
		menuBar->copy(menuItems);
	}

	void
	Window::MakeSystemInfo(int x, int y, int w, int h)
	{
		Fl_Multiline_Output * o =
			new Fl_Multiline_Output(x, (y + 15), (w - 20), (h - 20));
	}

	void
	Window::CreateTabs(void)
	{
		int y = 40;
		int x = 10;
		int w = WIN::MAX_X - 20;
		int h = WIN::MAX_Y - 50;

		Fl_Tabs * tabs =
			new Fl_Tabs(x, y, w, h);
		{
			Fl_Group * grpMain =
				new Fl_Group((x * 2), (y + 20), w, (h - 30), "System");
			{
				WIN::Window::MakeSystemInfo((x * 2), (y + 20), w, (h - 30));
			}

			grpMain->end();

			Fl_Group * grpProcess =
				new Fl_Group((x * 2), (y + 20), w, (h - 30), "Processes");
			{	
			}

			grpProcess->end();
		}

		tabs->box(BOX_TYPE);
		//tabs->selection_color(FL_DARK3);
		tabs->end();
	}

	void
	Window::SetAttributes(void)
	{
		WIN::Window::CreateMenuBar();
		WIN::Window::CreateTabs();
	}

	int
	Window::CreateWindow(int argc, char ** argv)
	{
		Fl_Window * rootWindow;

		/* Create the root window */
		rootWindow =
			new Fl_Window(WIN::MAX_X, WIN::MAX_Y);

		SetAttributes();

		rootWindow->end();
		rootWindow->show(argc, argv);

		return Fl::run();
	}
}
