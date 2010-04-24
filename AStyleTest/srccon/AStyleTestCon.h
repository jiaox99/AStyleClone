// AStyleTestCon tests the ASConsole class only. This class is used only in
// the console build. It also tests the parseOption function for options used
// by only by the console build (e.g. recursive, preserve-date, verbose). It
// does not explicitely test the ASStreamIterator class or any other part
// of the program.

#ifndef ASTYLE_TESTCON_H
#define ASTYLE_TESTCON_H

//-------------------------------------------------------------------------
// headers
//-------------------------------------------------------------------------


#include <stdlib.h>
#include <vector>
#include <iostream>  // for cout
#include <fstream>
#include <errno.h>

#include "gtest/gtest.h"
#include "astyle_main.h"

using namespace astyle;

//-------------------------------------------------------------------------
// extern global variables in astyle_main.cpp
//-------------------------------------------------------------------------

// global variables in astyle_main.cpp
// NOTE: the Embarcadero compiler needs the astyle:: qualifier for some reason
namespace astyle
{
extern astyle::ASConsole* g_console;
extern ostream* _err;
}

//-------------------------------------------------------------------------
// declarations
//-------------------------------------------------------------------------

// functions in AStyleTestCon_Main.cpp
// char** buildArgv(const vector<string>& argIn);
void cleanTestDirectory(const string &directory);
void createConsoleGlobalObject(ASFormatter& formatter);
void createTestDirectory(const string &dirName);
void createTestFile(const string& testFilePath, const char* testFileText, int size = 0);
void deleteConsoleGlobalObject();
string getCurrentDirectory();
string getTestDirectory();
void removeTestDirectory(const string &dirName);
void removeTestFile(const string& testFileName);
void setTestDirectory(char *argv);
void systemAbort(const string& message);
void systemPause(const string& message);
bool writeOptionsFile(const string& optionsFileName, const char* fileIn);

//-------------------------------------------------------------------------
// macro
//-------------------------------------------------------------------------

// ASTYLE_ABORT(message) macro
// Print an error message, including the file and line number,
//  and then abort the program.
#define ASTYLE_ABORT(message) \
	{ \
		(*_err) << endl << __FILE__ << " (" << __LINE__ << ")" << endl; \
		(*_err) << message << endl; \
		(*_err) << "\nArtistic Style has terminated!\n" << endl; \
		exit(EXIT_FAILURE); \
	}

//-------------------------------------------------------------------------

#endif // closes ASTYLE_TESTCON_H