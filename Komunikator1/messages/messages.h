#pragma once

#include <string>
#include <vector>
using namespace System::Data::SQLite;
using namespace System::Text;

struct Message {
    std::string sender;
    std::string recipient;
    std::string message;
    std::string date;
};

ref class MessageDatabase {
private:
    SQLiteConnection^DB;

public:
    explicit MessageDatabase(SQLiteConnection^db);
    void create_message_table();
    Message save_message(Message message);
    std::vector <Message> get_messages(const std::string& user, const std::string& interlocutor);
    std::vector <std::string> get_interlocutors(const std::string& user);
};