/////////////////////////////////////////////////////////////////////////////
// Executive.h - Support file and directory operations                     //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyright © Dhruv G Bhatti, 2018                                        //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2017                             //
// Platform:    HP Envy x360 , Ryzen 7, Windows 10                         //
// Application: Fall Project, 2018                                         //
// Author:      Dhruv G BHatti, class 2018-2020, Syracuse University       //
//              (571) 635 0862, dgbhatti@syr.edu                           //
/////////////////////////////////////////////////////////////////////////////
/*
 * Module Operations:
 * ==================
 * This module acts as entry point of the project. It controlls all packages like display and Converter.
 *
 * Required Files:
 * ===============
 * Process.h, Process.cpp
 * Converter.h, Converter.cpp
 * codeUtilities.h, codeUtilities.cpp
 * DirExplorerN.h, DirExplorerN.cpp
 * display.h, display.cpp
 * ConfigureParser.h, ConfigureParser.cpp 
 * Parser.h, Parser.cpp
 * ActionsAndRules.h, ActionsAndRules.cpp
 * AbstrSynTree.h, AbstrSynTree.cpp
 * ScopeStack.h, ScopeStack.cpp
 * dependencies.h, dependencies.cpp
 * IExecutive.h, IExecutive.cpp
 *
 * Build Command:
 * ==============
 * cl /EHa /DTEST_FILESYSTEM FileSystem.cpp
 *
 * Maintenance History:
 * ====================
 * ver 1.0 : 5 Jan 2018
 * - first release
 */

#pragma once
#include "../Converter/Converter.h"
#include "../display/display.h"
#include "../DirectoryNavigator/Utilities/CodeUtilities/CodeUtilities.h"
#include "../DirectoryNavigator/DirExplorer-Naive/DirExplorerN.h"
#include "../CppCommWithFileXfer/Utilities/Utilities.h"
#include "../CppParser/Parser/ConfigureParser.h"
#include "../CppParser/Parser/Parser.h"
#include "../CppParser/Parser/ActionsAndRules.h"
#include "../CppParser/AbstractSyntaxTree/AbstrSynTree.h"
#include "../CppParser/ScopeStack/ScopeStack.h"
#include "../dependencies/dependencies.h"
#include "IExecutive.h"
#include<conio.h>
#include<vector>
#define Util StringHelper


class Executive : public IExecutiveClass
{
public:
	Executive();
	~Executive();
	void Req3();
	std::vector<std::string> initialization(int argc, char ** argv) override;
	void displayFiles(std::vector<std::string> Files);
	//int publish(int argc, char** argv);
};

IExecutiveClass* ObjectFactory::createClient()
{
	return new Executive;
}