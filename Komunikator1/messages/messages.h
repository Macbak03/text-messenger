#pragma once

#include <string>
#include <vector>
using namespace System::Data::SQLite;
using namespace System::Text;
using namespace System::Collections::Generic;

public ref struct Message {
    System::String^ sender;
    System::String^ recipient;
    System::String^ message;
    System::String^ date;
};

public ref class MessageDatabase {
private:
    SQLiteConnection^DB;

public:
    explicit MessageDatabase(SQLiteConnection^db);
    void create_message_table();
    Message^ save_message(Message^ message);
    List <Message^>^ get_messages(System::String^ user, System::String^ interlocutor);
    List <System::String^>^ get_interlocutors(System::String^ user);
};