#pragma once
#include "Main.h"
#include "Register.h"
#include "users.h"

namespace Komunikator1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	

	/// <summary>
	/// Summary for Start
	/// </summary>
	public ref class Start : public System::Windows::Forms::Form
	{
	public:
		Start(UserDatabase^ u_db, MessageDatabase^ m_db) : user_database(u_db), message_database(m_db)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void CloseForm()
		{
			this->Close();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Start()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tbUsername;
	private: System::Windows::Forms::TextBox^ tbPassword;
	protected:


	private: System::Windows::Forms::Button^ Log_in;
	private: System::Windows::Forms::Button^ Reg;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private:
		Main^ main_form;
		Register^ register_form;
		UserDatabase^ user_database;
		MessageDatabase^ message_database;
	

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tbUsername = (gcnew System::Windows::Forms::TextBox());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->Log_in = (gcnew System::Windows::Forms::Button());
			this->Reg = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// tbUsername
			// 
			this->tbUsername->Location = System::Drawing::Point(116, 60);
			this->tbUsername->Margin = System::Windows::Forms::Padding(2);
			this->tbUsername->Name = L"tbUsername";
			this->tbUsername->Size = System::Drawing::Size(239, 20);
			this->tbUsername->TabIndex = 0;
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(116, 106);
			this->tbPassword->Margin = System::Windows::Forms::Padding(2);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(239, 20);
			this->tbPassword->TabIndex = 1;
			this->tbPassword->Tag = L"";
			// 
			// Log_in
			// 
			this->Log_in->Location = System::Drawing::Point(116, 150);
			this->Log_in->Margin = System::Windows::Forms::Padding(2);
			this->Log_in->Name = L"Log_in";
			this->Log_in->Size = System::Drawing::Size(238, 26);
			this->Log_in->TabIndex = 2;
			this->Log_in->Text = L"Log in";
			this->Log_in->UseVisualStyleBackColor = true;
			this->Log_in->Click += gcnew System::EventHandler(this, &Start::Log_in_Click);
			// 
			// Reg
			// 
			this->Reg->Location = System::Drawing::Point(166, 188);
			this->Reg->Margin = System::Windows::Forms::Padding(2);
			this->Reg->Name = L"Reg";
			this->Reg->Size = System::Drawing::Size(138, 37);
			this->Reg->TabIndex = 3;
			this->Reg->Text = L"Register";
			this->Reg->UseVisualStyleBackColor = true;
			this->Reg->Click += gcnew System::EventHandler(this, &Start::Reg_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(114, 45);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Enter username";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(115, 90);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Enter password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(142, 126);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(196, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"You typed wrong username or password";
			this->label3->Visible = false;
			// 
			// Start
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 281);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Reg);
			this->Controls->Add(this->Log_in);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->tbUsername);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Start";
			this->Text = L"Start";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Reg_Click(System::Object^ sender, System::EventArgs^ e) {
		register_form = gcnew Register(user_database, message_database);
		this->Hide();
		register_form->ShowDialog();
		this->Close();
	}
	private: System::Void Log_in_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ user_name = this->tbUsername->Text;
		String^ password = this->tbPassword->Text;
		if (user_name->Length == 0 || password->Length == 0)
		{
			MessageBox::Show("Please enter your login and password", "Login or passsword are empty", MessageBoxButtons::OK);
			return;
		}
		try
		{
			User^ user = gcnew User;
			if (user_database->find_user(user_name, password, user))
			{
				main_form = gcnew Main(user_database, message_database, user);
				this->Hide();
				main_form->ShowDialog();
				this->Close();
			}
			else
			{
				this->label3->Visible = true;
			}
		}
		catch(Exception^ e)
		{
			MessageBox::Show(e->Message, "Database error", MessageBoxButtons::OK);
		}
		
	}
	};
}
