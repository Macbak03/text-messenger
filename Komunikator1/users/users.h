#pragma once

#include <string>
#include "../DatabaseTable.h"

using namespace System::Data::SQLite;
using namespace System::Text;
using namespace System::Collections::Generic;

public ref struct User {
    System::String^ login;
    System::String^ password;
    System::String^ name;
    System::String^ surname;
};

public ref class UserDatabase : public DatabaseTable{
public:
    explicit UserDatabase(SQLiteConnection^ db);

    void create_table() override;

    void delete_user(User^ user);

    bool find_user(System::String^ login, System::String^ password, User^ user);

    User^ save_user(User^ user);

    bool find_user(System::String^ login, User^ user);
};

