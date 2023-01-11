#pragma once
#include "ConversationView.h"
#include "users.h"
#include "messages.h"

namespace Komunikator1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for Main
	/// </summary>
	ref class Main;
	ref class Start;
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(UserDatabase^ u_db, MessageDatabase^ m_db, User^ user) : user_database(u_db), message_database(m_db), user(user)
		{
			InitializeComponent();
			List<System::String^>^ intorlocutors = message_database->get_interlocutors(user->login);
			this->tbChooseFromUsers->Items->AddRange(intorlocutors->ToArray());
			//
			//TODO: Add the constructor code here
			//
		}
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbAddUser;
	private: System::Windows::Forms::Button^ LogOut;
	private: System::Windows::Forms::ListBox^ tbChooseFromUsers;
	private: System::Windows::Forms::Button^ Select;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ Add;

	private:
		Start^ start_form;
		ConversationView^ convo_form;
		UserDatabase^ user_database;
		MessageDatabase^ message_database;
		User^ user;
	

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbAddUser = (gcnew System::Windows::Forms::TextBox());
			this->LogOut = (gcnew System::Windows::Forms::Button());
			this->tbChooseFromUsers = (gcnew System::Windows::Forms::ListBox());
			this->Select = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			//label1
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(178, 9);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Add user";
			//tbAddUser
			this->tbAddUser->Location = System::Drawing::Point(91, 25);
			this->tbAddUser->Margin = System::Windows::Forms::Padding(2);
			this->tbAddUser->Name = L"tbAddUser";
			this->tbAddUser->Size = System::Drawing::Size(216, 20);
			this->tbAddUser->TabIndex = 1;
			this->tbAddUser->TextChanged += gcnew System::EventHandler(this, &Main::tbAddUser_change_text);
			//LogOut
			this->LogOut->Location = System::Drawing::Point(359, 19);
			this->LogOut->Margin = System::Windows::Forms::Padding(2);
			this->LogOut->Name = L"LogOut";
			this->LogOut->Size = System::Drawing::Size(80, 26);
			this->LogOut->TabIndex = 2;
			this->LogOut->Text = L"Log out";
			this->LogOut->UseVisualStyleBackColor = true;
			this->LogOut->Click += gcnew System::EventHandler(this, &Main::LogOut_Click);
			//tbChooseFromUsers
			this->tbChooseFromUsers->FormattingEnabled = true;
			this->tbChooseFromUsers->Location = System::Drawing::Point(63, 109);
			this->tbChooseFromUsers->Margin = System::Windows::Forms::Padding(2);
			this->tbChooseFromUsers->Name = L"tbChooseFromUsers";
			this->tbChooseFromUsers->Size = System::Drawing::Size(272, 186);
			this->tbChooseFromUsers->TabIndex = 3;
			//Select
			this->Select->Enabled = false;
			this->Select->Location = System::Drawing::Point(137, 299);
			this->Select->Margin = System::Windows::Forms::Padding(2);
			this->Select->Name = L"Select";
			this->Select->Size = System::Drawing::Size(126, 27);
			this->Select->TabIndex = 4;
			this->Select->Text = L"Select";
			this->Select->UseVisualStyleBackColor = true;
			this->Select->Click += gcnew System::EventHandler(this, &Main::Select_Click);
			//label2
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(145, 94);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(94, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Choose from users";
			//Add
			this->Add->Enabled = false;
			this->Add->Location = System::Drawing::Point(137, 50);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(126, 27);
			this->Add->TabIndex = 6;
			this->Add->Text = L"Add";
			this->Add->UseVisualStyleBackColor = true;
			this->Add->Click += gcnew System::EventHandler(this, &Main::Add_Click);
			//Main
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(450, 353);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Select);
			this->Controls->Add(this->tbChooseFromUsers);
			this->Controls->Add(this->LogOut);
			this->Controls->Add(this->tbAddUser);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Main";
			this->Text = L"Main";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void LogOut_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void Select_Click(System::Object^ sender, System::EventArgs^ e) {
		convo_form = gcnew ConversationView(user_database, user);
		this->Hide();
		convo_form->ShowDialog();
		this->Close();
	}
	private: System::Void tbAddUser_change_text(System::Object^ sender, System::EventArgs^ e)
	{
		System::String^ add = this->tbAddUser->Text;
		if (System::String::IsNullOrEmpty(add))
		{
			this->Add->Enabled = false;
		}
		else
		{
			this->Add->Enabled = true;
		}
	}
	private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ add = this->tbAddUser->Text;
		
		try
		{
			User^ user = gcnew User;
			if (user_database->find_user(add, user))
			{
				this->tbChooseFromUsers->Items->Add(user->login);
			}
			else
			{
				MessageBox::Show("Couldn't find user with login \""+add+"\"", "User not found", MessageBoxButtons::OK);
			}
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message, "Database error", MessageBoxButtons::OK);
		}
	}
};
}
