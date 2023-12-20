#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

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
#include "System.h"

#define BOX_TYPE FL_PLASTIC_UP_BOX 

namespace WIN
{
	enum { MAX_X = 500, MAX_Y = 500 };

	class Window {
	private:
		void MakeSystemInfo(int, int, int, int);
		void CreateTabs(void);
		void CreateMenuBar(void);
		void SetAttributes(void);
	public:
		int CreateWindow(int, char **);
	};
}

#endif /* __WINDOW_HPP__ */
