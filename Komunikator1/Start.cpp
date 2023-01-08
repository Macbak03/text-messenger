#include "Start.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::SQLite;
using namespace System::Text;


[STAThread]
void main(array<String^>^ args)
{
	SQLiteConnection^ db = gcnew SQLiteConnection();
	UserDatabase^ user_database = gcnew UserDatabase(db);
	try
	{
		db->ConnectionString = "Data Source=example.db;Version=3;New=True;";
		db->Open();

		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Komunikator1::Start form(user_database);
		Application::Run(% form);

		db->Close();
	}
	finally
	{
		delete (IDisposable^)db;
	}
}