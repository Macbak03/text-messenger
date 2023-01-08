#pragma once

#include<string>

using namespace System::Data::SQLite;
using namespace System::Text;

struct User {
    std::string login;
    std::string password;
    std::string name;
    std::string surname;
};

public ref class UserDatabase {
private:
    SQLiteConnection^ DB;

public:
    explicit UserDatabase(SQLiteConnection^ db);

    void create_user_table();

    bool find_user(System::String^ login, System::String^ password, User &user);

    User save_user(User user);
};

