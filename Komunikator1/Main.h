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
			intorlocutors = message_database->get_interlocutors(user->login);
			this->tbChooseFromUsers->Items->AddRange(intorlocutors->ToArray());
			this->CenterToParent();
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
		List<System::String^>^ intorlocutors;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ accountToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ logOutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteAcountToolStripMenuItem;
	private: System::Windows::Forms::Label^ label3;


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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->accountToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->logOutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteAcountToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(201, 53);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Add user";
			this->tbAddUser->Location = System::Drawing::Point(116, 68);
			this->tbAddUser->Margin = System::Windows::Forms::Padding(2);
			this->tbAddUser->Name = L"tbAddUser";
			this->tbAddUser->Size = System::Drawing::Size(216, 20);
			this->tbAddUser->TabIndex = 1;
			this->tbAddUser->TextChanged += gcnew System::EventHandler(this, &Main::tbAddUser_change_text);
			this->LogOut->Location = System::Drawing::Point(359, 19);
			this->LogOut->Margin = System::Windows::Forms::Padding(2);
			this->LogOut->Name = L"LogOut";
			this->LogOut->Size = System::Drawing::Size(80, 26);
			this->LogOut->TabIndex = 2;
			this->LogOut->Text = L"Log out";
			this->LogOut->UseVisualStyleBackColor = true;
			//this->LogOut->Click += gcnew System::EventHandler(this, &Main::LogOut_Click);
			this->tbChooseFromUsers->FormattingEnabled = true;
			this->tbChooseFromUsers->Location = System::Drawing::Point(82, 138);
			this->tbChooseFromUsers->Margin = System::Windows::Forms::Padding(2);
			this->tbChooseFromUsers->Name = L"tbChooseFromUsers";
			this->tbChooseFromUsers->Size = System::Drawing::Size(272, 186);
			this->tbChooseFromUsers->TabIndex = 3;
			this->tbChooseFromUsers->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::tbChooseFromUsers_SelectedIndexChanged);
			this->tbChooseFromUsers->DoubleClick += gcnew System::EventHandler(this, &Main::tbChooseFromUsers_DoubleClick);
			this->Select->Enabled = false;
			this->Select->Location = System::Drawing::Point(158, 328);
			this->Select->Margin = System::Windows::Forms::Padding(2);
			this->Select->Name = L"Select";
			this->Select->Size = System::Drawing::Size(126, 27);
			this->Select->TabIndex = 4;
			this->Select->Text = L"Select";
			this->Select->UseVisualStyleBackColor = true;
			this->Select->Click += gcnew System::EventHandler(this, &Main::Select_Click);
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(175, 123);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(94, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Choose from users";
			this->Add->Enabled = false;
			this->Add->Location = System::Drawing::Point(158, 93);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(126, 27);
			this->Add->TabIndex = 6;
			this->Add->Text = L"Add";
			this->Add->UseVisualStyleBackColor = true;
			this->Add->Click += gcnew System::EventHandler(this, &Main::Add_Click);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->accountToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(450, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			this->accountToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->logOutToolStripMenuItem,
					this->deleteAcountToolStripMenuItem
			});
			this->accountToolStripMenuItem->Name = L"accountToolStripMenuItem";
			this->accountToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->accountToolStripMenuItem->Text = L"Account";
			this->logOutToolStripMenuItem->Name = L"logOutToolStripMenuItem";
			this->logOutToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->logOutToolStripMenuItem->Text = L"Log out";
			this->logOutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::logOutToolStripMenuItem_Click);
			this->deleteAcountToolStripMenuItem->Name = L"deleteAcountToolStripMenuItem";
			this->deleteAcountToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->deleteAcountToolStripMenuItem->Text = L"Delete acount";
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(183, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 8;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(450, 413);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Select);
			this->Controls->Add(this->tbChooseFromUsers);
			this->Controls->Add(this->LogOut);
			this->Controls->Add(this->tbAddUser);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Main";
			this->Text = L"Main";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	//private: System::Void LogOut_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void Select_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ interlocutor = (System::String^)(this->tbChooseFromUsers->SelectedItem);
		convo_form = gcnew ConversationView(user_database, message_database, user, interlocutor);
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
			if(this->tbChooseFromUsers->Items->Contains(add)) {
				MessageBox::Show("User already added \"" + add + "\"", "Couldn't add user", MessageBoxButtons::OK);
			}
			else {
				User^ user = gcnew User;
				if (user_database->find_user(add, user))
				{
					this->tbChooseFromUsers->Items->Add(user->login);
				}
				else
				{
					MessageBox::Show("Couldn't find user with login \"" + add + "\"", "User not found", MessageBoxButtons::OK);
				}
			}
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message, "Database error", MessageBoxButtons::OK);
		}
	}
	private: System::Void tbChooseFromUsers_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (tbChooseFromUsers->SelectedItems->Count > 0)
		{
			Select->Enabled = true;
		}
	}
	private: System::Void tbChooseFromUsers_DoubleClick(System::Object^ sender,System::EventArgs^ e)
	{
		Select_Click(sender, e);
	}
	private: System::Void logOutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

};
}
