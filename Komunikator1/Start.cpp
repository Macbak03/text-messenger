#include "Start.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)

{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Komunikator1::Start form;
	Application::Run(% form);
}