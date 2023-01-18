#include "Start.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::SQLite;
using namespace System::Text;

//To do:
//przesuwanie konwersacji na dol
//odswierzanie w czasie rzeczywistim
[STAThread]
void main(array<String^>^ args)
{
	SQLiteConnection^ db = gcnew SQLiteConnection();
	UserDatabase^ user_database = gcnew UserDatabase(db);
	MessageDatabase^ message_database = gcnew MessageDatabase(db);
	try
	{
		db->ConnectionString = "Data Source=example.db;Version=3;New=True;foreign keys=true";
		db->Open();
		user_database->create_table();
		message_database->create_table();
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Komunikator1::Start form(user_database, message_database);
		Application::Run(% form);

		db->Close();
	}
	finally
	{
		delete (IDisposable^)db;
	}
}