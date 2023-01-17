#pragma once

using namespace System::Data::SQLite;
using namespace System::Text;
using namespace System::Collections::Generic;

public ref class DatabaseTable abstract
{
protected:
	SQLiteConnection^ DB;

public:
	DatabaseTable(SQLiteConnection^ db) : DB(db) {}
	virtual void create_table() abstract;
};