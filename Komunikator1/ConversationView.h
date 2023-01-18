#pragma once
#include "users.h"
#include "messages.h"
#include <msclr\marshal_cppstd.h>
#include <math.h>


namespace Komunikator1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	


	/// <summary>
	/// Summary for ConversationView
	/// </summary>
	ref class ConversationView;
	ref class Main;
	public ref class ConversationView : public System::Windows::Forms::Form
	{
	public:
		ConversationView(UserDatabase^ u_db, MessageDatabase^ m_db, User^ user, System::String^ ilc) : user_database(u_db), message_database(m_db), user(user), interlocutor(ilc)
		{
			InitializeComponent();
			User^ conv_user = gcnew User;
			if (user_database->find_user(interlocutor, conv_user))
			{
				this->label2->Text = conv_user->name + " " + conv_user->surname;
			}
			else
			{
				this->label2->Text = L"ERROR";
			}
			List<UserMessage^>^ messages = message_database->get_messages(user->login, ilc);
			for each (UserMessage ^ message in messages)
				this->lbConversation->Items->Add(message->date + " " + message->sender + " sent: " + message->message + "\n");
			this->lbConversation->TopIndex = -1;
			this->CenterToParent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Button^ Send;
	private: System::Windows::Forms::TextBox^ tbMessage;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ Return;
	private: System::Windows::Forms::ListBox^ lbConversation;
	private: System::Windows::Forms::Label^ label2;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ConversationView()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Main^ main_form;
		UserDatabase^ user_database;
		MessageDatabase^ message_database;
		User^ user;
		System::String^ interlocutor;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tbMessage = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Return = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Send = (gcnew System::Windows::Forms::Button());
			this->lbConversation = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			//tbMessage
			this->tbMessage->Location = System::Drawing::Point(89, 220);
			this->tbMessage->Margin = System::Windows::Forms::Padding(2);
			this->tbMessage->Multiline = true;
			this->tbMessage->Name = L"tbMessage";
			this->tbMessage->Size = System::Drawing::Size(322, 43);
			this->tbMessage->TabIndex = 0;
			this->tbMessage->TextChanged += gcnew System::EventHandler(this, &ConversationView::tbMessage_change_text);
			//label1
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(217, 205);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Type message";
			//Return
			this->Return->Location = System::Drawing::Point(9, 10);
			this->Return->Margin = System::Windows::Forms::Padding(2);
			this->Return->Name = L"Return";
			this->Return->Size = System::Drawing::Size(80, 26);
			this->Return->TabIndex = 2;
			this->Return->Text = L"Return";
			this->Return->UseVisualStyleBackColor = true;
			this->Return->Click += gcnew System::EventHandler(this, &ConversationView::Return_Click);
			//label2
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(224, 28);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 4;
			//Send
			this->Send->Location = System::Drawing::Point(199, 268);
			this->Send->Name = L"Send";
			this->Send->Size = System::Drawing::Size(110, 36);
			this->Send->TabIndex = 2;
			this->Send->Text = L"Send";
			this->Send->UseVisualStyleBackColor = true;
			this->Send->Enabled = false;
			this->Send->Click += gcnew System::EventHandler(this, &ConversationView::Send_Click);
			//lbConversation
			this->lbConversation->ColumnWidth = 15;
			this->lbConversation->FormattingEnabled = true;
			this->lbConversation->HorizontalScrollbar = true;
			this->lbConversation->Location = System::Drawing::Point(89, 44);
			this->lbConversation->Name = L"lbConversation";
			this->lbConversation->ScrollAlwaysVisible = true;
			this->lbConversation->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->lbConversation->Size = System::Drawing::Size(322, 147);
			this->lbConversation->TabIndex = 5;
			//ConversationView
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 357);
			this->Controls->Add(this->lbConversation);
			this->Controls->Add(this->Send);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Return);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tbMessage);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"ConversationView";
			this->Text = L"ConversationView";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Return_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void tbMessage_change_text(System::Object^ sender, System::EventArgs^ e)
	{
		System::String^ mess = this->tbMessage->Text;
		if (System::String::IsNullOrEmpty(mess))
		{
			this->Send->Enabled = false;
		}
		else
		{
			this->Send->Enabled = true;
		}
	}
	private: System::Void Send_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ mess = this->tbMessage->Text;
		try
		{
			DateTime DateTimeNow = DateTime::Now;
			System::String^ date = DateTimeNow.ToShortDateString() + " " + DateTimeNow.ToShortTimeString();
			UserMessage^ user_message = gcnew UserMessage;
			user_message->message = mess;
			user_message->recipient = interlocutor;
			user_message->sender = user->login;
			user_message->date = date;
			message_database->save_message(user_message);
			lbConversation->TopIndex = lbConversation->Items->Add(date + " " + user->login + " sent: " + mess + "\n");
			this->tbMessage->Clear();
			
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message, "Database error", MessageBoxButtons::OK);
		}
	}
};
}
