#include "messages.h"
#include <iostream>

#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System::Data::SQLite;
using namespace System::Text;
using namespace msclr::interop;
using namespace System::Collections::Generic;

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

Message^ MessageDatabase::save_message(Message^ message) {
    System::String^ sql = "insert into messages values('" + message->sender + "', '" + message->recipient + "', '" + message->message + "', '" +
                 message->date + "');";
    SQLiteCommand exec(sql, DB);
    exec.ExecuteNonQuery();
    return message;
}

List<Message^>^ MessageDatabase::get_messages(System::String^ user, System::String^ interlocutor) {
    System::String^ sql = "SELECT * FROM MESSAGES "
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
    SQLiteCommand exec(sql, DB);
    SQLiteDataReader^ rdr = exec.ExecuteReader();
    List<Message^>^ messages;
    while (rdr->Read())
    {
        Message^ message;
        message->sender = rdr->GetString(0);
        message->recipient = rdr->GetString(1);
        message->message = rdr->GetString(2);
        message->date = rdr->GetString(3);
        messages->Add(message);
    }
    return messages;
}

List<System::String^>^MessageDatabase::get_interlocutors(System::String^ user) {
    System::String^ sql = "select distinct RECIPIENT as interlocutor from MESSAGES "
                 "where SENDER = '" +
                  user +
                 "' "
                 "union select distinct SENDER as interlocutor from MESSAGES "
                 "where RECIPIENT = '" +
                  user +
                 "';";
    SQLiteCommand exec(sql, DB);
    SQLiteDataReader^ rdr = exec.ExecuteReader();
    List<System::String^>^ interlocutors = gcnew List<System::String^>;
    while (rdr->Read())
    {
        interlocutors->Add(rdr->GetString(0));
    }
    return interlocutors;
}






