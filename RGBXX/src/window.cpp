#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>
#include "window.hpp"

namespace scr {

	Fl_Window * mainWindow;
	Fl_Window * settingsWindow;
	Fl_Menu_Bar * menuBar;
	Fl_Value_Slider * colorSlider;
	Fl_Color windowColor;

	/*
	 * The items for the menu bar at the top
	 */
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
			{0},
			/* End of the menu */
			{0},
		};

	void
	ChangeColor(Fl_Widget *, void * v)
	{
		double val = colorSlider->value();

		windowColor = val;
		colorSlider->color(windowColor);
		mainWindow->color(windowColor);
		mainWindow->redraw();
	}

	/*
	 * Creates the menu bar at the top of the window
	 * Uses the menuItems array to add the elements
	 */
	void
	MakeMenuBar(void)
	{
		menuBar = new Fl_Menu_Bar(
			0, 0, scr::WIN_X, scr::WIN_Y / 16);

		menuBar->box(BOX_TYPE);
		menuBar->copy(scr::menuItems);
	}

	void
	Quit(Fl_Widget *, void * v)
	{
		exit(0);
	}

	/*
	 * Sets up the color sliders 
	 */
	void
	MakeColorSliders(void)
	{
		colorSlider = new Fl_Value_Slider(
			8, (scr::WIN_Y / 2) - (128 + 64),
			32, scr::WIN_Y - 64);

		colorSlider->box(BOX_TYPE);
		colorSlider->color(FL_RED);
		colorSlider->value((double) 0);
		colorSlider->minimum((double) 0);
		colorSlider->maximum((double) 255);
		colorSlider->callback(
			(Fl_Callback *) scr::ChangeColor);
	}

	/*
	 * Creates a new window, adding elements in through,
	 * Window class methods like MakeMenuBar()
	 */
	int
	CreateWindow(int argc, char ** argv)
	{
		mainWindow =
			new Fl_Window(scr::WIN_X, scr::WIN_Y);

		MakeMenuBar();
		MakeColorSliders();
		ChangeColor((Fl_Widget *) 0, (void *) 0);

		mainWindow->end();
		mainWindow->show(argc, argv);

		return Fl::run();
	}

	int
	start(int argc, char ** argv)
	{
		return CreateWindow(argc, argv);
	}
}
