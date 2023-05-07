#include "GUI.h"

//constructor make necessary initializations
GUI::GUI()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames
	UI.isFilled = false;
	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
	
}


//======================================================================================//
//								Input Functions										    //
//======================================================================================//


void GUI::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType GUI::MapInputToActionType() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SQUR: return DRAW_SQUARE;
			case ITM_ELPS: return DRAW_ELPS;
			case ITM_TRI: return DRAW_TRI;
			case ITM_HEX: return DRAW_HEX;
			case ITM_SLCT: return DRAW_SLCT;
			case ITM_DELETE: return DRAW_DELETE;
			case ITM_CHNG_DRAW_CLR: return CHNG_DRAW_CLR;
			case ITM_CHNG_BK_CLR: return CHNG_BK_CLR;
			case ITM_CHNG_FILL_CLR: return CHNG_FILL_CLR;
			case ITM_TO_PLAY:return TO_PLAY;
			case ITM_EXIT: return EXIT;	
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}	

}
//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white Square
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	
	MenuItemImages[ITM_SQUR] = "images\\MenuItems\\Menu_Sqr.jpg";
	MenuItemImages[ITM_ELPS] = "images\\MenuItems\\Menu_Elps.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_Hex.jpg";
	MenuItemImages[ITM_CHNG_DRAW_CLR] = "images\\MenuItems\\Menu_DRAW_CLR.jpg";
	MenuItemImages[ITM_CHNG_BK_CLR] = "images\\MenuItems\\Menu_BK_CLR.jpg";
	MenuItemImages[ITM_CHNG_FILL_CLR] = "images\\MenuItems\\Menu_FILL_CLR.jpg";
	MenuItemImages[ITM_SLCT] = "images\\MenuItems\\Menu_SLCT.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_DELETE.jpg";
	MenuItemImages[ITM_TO_PLAY] = "images\\MenuItems\\game.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

		

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
void GUI::CreatePlayToolBar() const
{
	CreateToolBar();
	UI.InterfaceMode = MODE_PLAY;
	
	string PlayMenuItems[PLAY_ITM_COUNT];
	PlayMenuItems[ITM_BY_TYPE] = "images\\MenuItems\\byType.jpg";
	PlayMenuItems[ITM_BY_COLOR] = "images\\MenuItems\\byClr.jpg";
	PlayMenuItems[ITM_BY_BOTH] = "images\\MenuItems\\byBoth.jpg";
	PlayMenuItems[ITM_TO_DRAW] = "images\\MenuItems\\back.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PlayMenuItems[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}// end of play menu
//////////////////////////////////////////////////////////////////////////////////////////


void GUI::CreateColorToolBar() const
{
	//UI.InterfaceMode = MODE_DRAW;
	
		pWind->DrawImage("images\\MenuItems\\Menu_Colors.jpg", 560, 50, 240, 100);	

}
//////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);	
	
}

void GUI::CreateToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearColorArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(560,50, 800, 150);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int GUI::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

void GUI::setCrntFillColor(color c) {
	UI.FillColor = c;
	UI.isFilled = true;
	pWind->SetBrush(UI.FillColor);
}
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void GUI::DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width
	
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P1.x +length, P1.y+length, style);
	//pWind->DrawLine(P1.x, P1.y, P1.x + length, P1.y + length, style);

}

void GUI::DrawEllipse(Point P1,Point P2, GfxInfo ElpsGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = ElpsGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, ElpsGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (ElpsGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(ElpsGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::DrawHexagon(Point P1, Point P2, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, HexGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;
	
	int lengthx = abs(P1.x - P2.x) ;
	int lengthy = abs(P1.y - P2.y) ;

	int arrx[6] = {P1.x,P1.x + lengthx, P1.x + 1.5 * lengthx,P1.x + lengthx,P1.x,P1.x - 0.5 * lengthx};
	int arry[6] = {P1.y,P1.y,P1.y + 0.5 * lengthy,P1.y + lengthy,P1.y + lengthy,P1.y + 0.5 * lengthy};

	pWind->DrawPolygon(arrx, arry,6, style);

}


void GUI::DrawTriangle(Point P1, Point P2,Point P3, GfxInfo ElpsGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = ElpsGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, ElpsGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (ElpsGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(ElpsGfxInfo.FillClr);
	}
	else
		style = FRAME;

	
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

