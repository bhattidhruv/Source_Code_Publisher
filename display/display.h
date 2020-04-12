#pragma once
#include<vector>
/////////////////////////////////////////////////////////////////////////////
// display.h - Support file and directory operations                       //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyright © Dhruv G Bhatti, 2018                                        //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2017                             //
// Platform:    HP Envy x360 , Ryzen 7, Windows 10                         //
// Application: Spring Project, 2018                                       //
// Author:      Dhruv G BHatti, class 2018-2020, Syracuse University       //
//              (571) 635 0862, dgbhatti@syr.edu                           //
/////////////////////////////////////////////////////////////////////////////
/*
 * Module Operations:
 * ==================
 * This module provide functionality to display the HTML file.
 *
 * Required Files:
 * ===============
 * Process.h, Process.cpp
 *
 * Public Interface:
 * =================
 *	display d;				 //creating an object of display class
 * d.showWebPage(htmlFiles);  // a function which takes an argument of vector <string>and display a valid HTML file using 
 *								proces class
 *
 * Maintenance History:
 * ====================
 * ver 1.0 : 5 Jan 2018
 * - first release
 */

class display
{
public:
	display();
	~display();
	//a function to display valid HTMl files using process class in the web browser
	void showWebPage(std::vector<std::string> convertedFiles);
};

