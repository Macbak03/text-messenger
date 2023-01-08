#include "users.h"
#include <iostream>

#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System::Data::SQLite;
using namespace System::Text;
using namespace msclr::interop;

UserDatabase::UserDatabase(SQLiteConnection^db) : DB(db) {}

void UserDatabase::create_user_table() {
    System::String^ sql = "CREATE TABLE IF NOT EXISTS USERS("
                 "LOGIN    TEXT PRIMARY KEY NOT NULL, "
                 "PASSWORD TEXT             NOT NULL, "
                 "NAME     TEXT             NOT NULL, "
                 "SURNAME  TEXT             NOT NULL); ";
    SQLiteCommand exec(sql, DB);
    exec.ExecuteNonQuery();
}


bool UserDatabase::find_user(System::String^ login, System::String^ password, User &user) {
    System::String^ sql = "select * from users "
                 "where login = '" +
                 login +
                 "' "
                 "and password = '" +
                 password +
                 "';";
    SQLiteCommand exec(sql, DB);
    SQLiteDataReader^ rdr = exec.ExecuteReader();
    
    if (rdr->Read())
    {
        user.login = marshal_as<std::string>(rdr->GetString(0));
        user.password = marshal_as<std::string>(rdr->GetString(1));
        user.name = marshal_as<std::string>(rdr->GetString(2));
        user.surname = marshal_as<std::string>(rdr->GetString(3));
        return true;
    }
    else
    {
        return false;
    }
}

User UserDatabase::save_user(User user) {
    string raw_sql = "insert into users values('" + user.login + "', '" + user.password + "', '" + user.name + "', '" +
                 user.surname + "');";
    System::String^ sql = gcnew System::String(raw_sql.c_str());
    SQLiteCommand exec(sql, DB);
    exec.ExecuteNonQuery();
    return user;
}