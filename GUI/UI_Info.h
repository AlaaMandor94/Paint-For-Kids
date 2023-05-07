#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_COLOR, //Color mode
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SQUR,		//Square item in menu
	ITM_ELPS,		//Ellipse item in menu
	ITM_TRI,		//Ellipse item in menu
	ITM_HEX,		//Ellipse item in menu
	ITM_SLCT,
	ITM_DELETE,
	ITM_CHNG_DRAW_CLR,
	ITM_CHNG_BK_CLR,
	ITM_CHNG_FILL_CLR,
	ITM_TO_PLAY,

	
	//TODO: Add more items names here

	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum ColorMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_Black,		//
	ITM_Red,		//
	ITM_White,		//
	ITM_Blue,		//
	ITM_Green,		//
	ITM_Yellow,

	COLOR_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	ITM_BY_TYPE,	//Play and hide by type item in menu
	ITM_BY_COLOR,	//Play and hide by color item in menu
	ITM_BY_BOTH,	//Play and hide by both color and type item in menu
	ITM_TO_DRAW,	// RETURN To draw mode item in menu

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	bool isFilled;
	/// Add more members if needed
	
}UI;	//create a global object UI

#endif