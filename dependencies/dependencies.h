/////////////////////////////////////////////////////////////////////////////
// dependencies.h - Support file and directory operations                       //
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
 *
 * Public Interface:
 * =================
 *Converter obj; //creating an object of Converter class
 * std::vector<std::string> list=obj.cppToHtml(std::string filesToProcess);  //accessing the function cppToHTML function using object of Converter class
 *												 which converts cpp file to valid HTML file
 *Fuction new are -- dependenciesFetch, HandlingComments, DivTagsAdded, SwitchFn.
 * Maintenance History:
 * ====================
 * ver 1.1 : 7 March 2019
 * ver 1.0 : 5 Jan 2019
 * - first release
 */

#pragma once

#include <vector>
#include <map>
#include "../CppParser/Parser/ConfigureParser.h"
#include "../CppParser/Parser/Parser.h"
#include "../CppParser/Parser/ActionsAndRules.h"
#include "../CppParser/AbstractSyntaxTree/AbstrSynTree.h"
#include "../CppParser/ScopeStack/ScopeStack.h"
#include "../CppCommWithFileXfer/Utilities/Utilities.h"
#define Util StringHelper

class dependencies
{
public:
	dependencies();
	~dependencies();
	enum TypeInfo { none, classes, function, end, singleLineFn };
	std::map<std::string, std::vector<std::string>> summonParser(std::vector<std::string> files);
	void analyzeDepT(std::map < std::string, std::vector<std::string>> & depT);
	void DepTable(std::vector<std::string> files, CodeAnalysis::ASTNode* pGlobalScope, std::string fileSpec, std::map<std::string, std::vector<std::string>>& dependencyMap);
	void newInfoTable(CodeAnalysis::ASTNode * pGlobalScope, std::string file);
	TypeInfo findTypeInfo(CodeAnalysis::ASTNode* pGlobalScope);
	std::map<std::string, std::map<std::size_t, dependencies::TypeInfo>> returnTypeInfoTable() { return typeInfoTable_; }

private:
	std::map<std::string, std::map<std::size_t, dependencies::TypeInfo>> typeInfoTable_;
};

