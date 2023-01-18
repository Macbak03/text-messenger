#pragma once

#include <string>
#include <list>
#include "../DatabaseTable.h"
using namespace System::Data::SQLite;
using namespace System::Text;
using namespace System::Collections::Generic;

public ref struct UserMessage {
    System::String^ sender;
    System::String^ recipient;
    System::String^ message;
    System::String^ date;
};

public ref class MessageDatabase : public DatabaseTable {
public:
    explicit MessageDatabase(SQLiteConnection^db);
    void create_table() override;
    void delete_messages(UserMessage^ user_message);
    UserMessage^ find_messages(UserMessage^ user_message);
    UserMessage^ save_message(UserMessage^ message);
    List <UserMessage^>^ get_messages(System::String^ user, System::String^ interlocutor);
    List <System::String^>^ get_interlocutors(System::String^ user);
};