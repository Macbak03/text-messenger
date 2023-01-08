#include "messages.h"
#include <iostream>

#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System::Data::SQLite;
using namespace System::Text;
using namespace msclr::interop;

MessageDatabase::MessageDatabase(SQLiteConnection^db) : DB(db) {}




void MessageDatabase::create_message_table() {
    System::String^ sql = "CREATE TABLE IF NOT EXISTS MESSAGES("
                 "SENDER    TEXT  NOT NULL, "
                 "RECIPIENT TEXT  NOT NULL, "
                 "MESSAGE   TEXT  NOT NULL, "
                 "DATE      TEXT  NOT NULL, "
                 "FOREIGN KEY (SENDER) REFERENCES USERS (LOGIN),"
                 "FOREIGN KEY (RECIPIENT) REFERENCES USERS (LOGIN));";
    SQLiteCommand exec(sql, DB);
    exec.ExecuteNonQuery();
}

Message MessageDatabase::save_message(Message message) {
    string raw_sql = "insert into messages values('" + message.sender + "', '" + message.recipient + "', '" + message.message + "', '" +
                 message.date + "');";
    System::String^ sql = gcnew System::String(raw_sql.c_str());
    SQLiteCommand exec(sql, DB);
    exec.ExecuteNonQuery();
    return message;
}

vector<Message> MessageDatabase::get_messages(const string& user, const string& interlocutor) {
    string raw_sql = "SELECT * FROM MESSAGES "
                 "where sender = '" +
                 user +
                 "' "
                 "and recipient = '" +
                 interlocutor +
                 "'"
                 "or recipient = '" +
                 user +
                 "' "
                 "and sender = '" +
                 interlocutor +
                 "';";
    System::String^ sql = gcnew System::String(raw_sql.c_str());
    SQLiteCommand exec(sql, DB);
    SQLiteDataReader^ rdr = exec.ExecuteReader();
    auto messages = vector<Message>();
    while (rdr->Read())
    {
        Message message;
        message.sender = marshal_as<std::string>(rdr->GetString(0));
        message.recipient = marshal_as<std::string>(rdr->GetString(1));
        message.message = marshal_as<std::string>(rdr->GetString(2));
        message.date = marshal_as<std::string>(rdr->GetString(3));
        messages.push_back(message);
    }
    return messages;
}

vector<string> MessageDatabase::get_interlocutors(const std::string& user) {
    string raw_sql = "select distinct RECIPIENT as interlocutor from MESSAGES "
                 "where SENDER = '" +
                  user +
                 "' "
                 "union select distinct SENDER as interlocutor from MESSAGES "
                 "where RECIPIENT = '" +
                  user +
                 "';";
    System::String^ sql = gcnew System::String(raw_sql.c_str());
    SQLiteCommand exec(sql, DB);
    SQLiteDataReader^ rdr = exec.ExecuteReader();
    auto interlocutors = vector<string>();
    while (rdr->Read())
    {
        interlocutors.push_back(marshal_as<std::string>(rdr->GetString(0)));
    }
    return interlocutors;
}






