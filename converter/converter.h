/////////////////////////////////////////////////////////////////////////////
// converter.h - Support file and directory operations                       //
// ver 1.1                                                                 //
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
 * This module provide functionality to convert code files like .h,.cpp & etc to HTML file. It will then store the converted files
 * to the allocated or destination folder.
 *
 * Required Files:
 * ===============
 * FileSystem.h, FileSystem.cpp
 * display.h, display.cpp
 * dependencies.h, dependencies.cpp
 *
 * Public Interface:
 * =================
 *converter obj; //creating an object of converter class
 * std::vector<std::string> list=obj.cppToHtml(std::string filesToProcess);  //accessing the function cppToHTML function using object of converter class
 *												 which converts cpp file to valid HTML file
 *Fuction new are -- dependenciesFetch, HandlingComments, DivTagsAdded, SwitchFn.
 * Maintenance History:
 * ====================
 * ver 1.1 : 7 March 2019
 * ver 1.0 : 5 Jan 2019
 * - first release
 */

#pragma once
#include<vector>
#include<iostream>
#include "../DirectoryNavigator/FileSystem/FileSystem.h"
#include "../display/display.h"
#include <fstream>
#include<string>
#include <algorithm>
#include <map>
#include"../dependencies/dependencies.h"

using TypeInfoT = std::map<std::string, std::map<std::size_t, dependencies::TypeInfo>>;
namespace HTML
{
	class converter
	{
	public:

		converter();
		~converter();

		std::string cppToHtml(std::string filesToProcess_, std::map<std::string, std::vector<std::string>> depT, const TypeInfoT &typeTable);
		void dependenciesFetch(std::string &filesToProcess, const std::map<std::string, std::vector<std::string>> &depTable, std::ofstream &webpageOutput);
		void HandlingComments(std::vector<std::string> &filedata, const TypeInfoT &typeTable);
		void DivTagsAdded(std::string &file, std::vector<std::string> &filedata, const TypeInfoT &typeTable);
		void SwitchFn(size_t &i, std::vector<std::string> &filedata, std::map<std::size_t, dependencies::TypeInfo>::const_iterator &iter2, size_t lineNo);
		void HandlingClasses(size_t &i, std::vector<std::string> &filedata, size_t &lineNo);
		void HandlingFunctions(size_t &i, std::vector<std::string> &filedata, size_t &lineNo);
		void HandlingSingleLnFOpen(size_t &i, std::vector<std::string> &filedata, size_t &lineNo);
		void HandlingSingleLnFClose(size_t &i, std::vector<std::string> &filedata, size_t &lineNo);
	};
}

