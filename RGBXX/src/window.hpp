#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>

#define BOX_TYPE FL_PLASTIC_UP_BOX

namespace scr {
	enum { 
		WIN_X = 500, WIN_Y = 500,
	};

	extern Fl_Menu_Item menuItems[];

	extern Fl_Window * mainWindow;
	extern Fl_Window * settingsWindow;

	extern Fl_Menu_Bar * menuBar;

	extern Fl_Value_Slider * colorSlider;

	extern Fl_Color windowColor;

	void MakeMenuBar(void);

	void MakeColorSliders(void);

	void Quit(Fl_Widget *, void *);

	void ChangeColor(Fl_Widget *, void *);

	int CreateWindow(int, char **);

	int start(int, char **);
}

#endif /* __WINDOW_HPP__ */
