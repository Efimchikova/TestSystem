// Project_Curs.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include "Form_start.h"
using namespace Project_Curs;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form_start());
	return 0;
}
