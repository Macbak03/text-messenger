#pragma once
#include "Main.h"
#include "users.h"
#include "messages.h"
#include <msclr\marshal_cppstd.h>

namespace Komunikator1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for Register
	/// </summary>
	ref class Register;
	ref class Start;
	public ref class Register : public System::Windows::Forms::Form
	{
	public:
		Register(UserDatabase^ u_db) : user_database(u_db)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Register()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbName;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tbSurname;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbLogin;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tbPassword;

	private: System::Windows::Forms::Button^ Regg;

	private: System::Windows::Forms::Button^ Back;

	private:
		Main^ main_form;
		Start^ start_form;
		UserDatabase^ user_database;
		MessageDatabase^ message_database;


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
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbSurname = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbLogin = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->Regg = (gcnew System::Windows::Forms::Button());
			this->Back = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(120, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Name";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(123, 47);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(291, 22);
			this->tbName->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(120, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Surname";
			// 
			// tbSurname
			// 
			this->tbSurname->Location = System::Drawing::Point(123, 100);
			this->tbSurname->Name = L"tbSurname";
			this->tbSurname->Size = System::Drawing::Size(291, 22);
			this->tbSurname->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(120, 135);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Login";
			// 
			// tbLogin
			// 
			this->tbLogin->Location = System::Drawing::Point(123, 154);
			this->tbLogin->Name = L"tbLogin";
			this->tbLogin->Size = System::Drawing::Size(291, 22);
			this->tbLogin->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(120, 189);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Password";
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(123, 208);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->Size = System::Drawing::Size(291, 22);
			this->tbPassword->TabIndex = 7;
			// 
			// Regg
			// 
			this->Regg->Location = System::Drawing::Point(288, 268);
			this->Regg->Name = L"Regg";
			this->Regg->Size = System::Drawing::Size(126, 47);
			this->Regg->TabIndex = 8;
			this->Regg->Text = L"Register";
			this->Regg->UseVisualStyleBackColor = true;
			this->Regg->Click += gcnew System::EventHandler(this, &Register::Regg_Click);
			// 
			// Back
			// 
			this->Back->Location = System::Drawing::Point(123, 268);
			this->Back->Name = L"Back";
			this->Back->Size = System::Drawing::Size(126, 47);
			this->Back->TabIndex = 9;
			this->Back->Text = L"Back";
			this->Back->UseVisualStyleBackColor = true;
			this->Back->Click += gcnew System::EventHandler(this, &Register::Back_Click);
			// 
			// Register
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(558, 366);
			this->Controls->Add(this->Back);
			this->Controls->Add(this->Regg);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tbLogin);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tbSurname);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label1);
			this->Name = L"Register";
			this->Text = L"Register";
			this->ResumeLayout(false);
			this->PerformLayout();
			
		}
#pragma endregion
	private: System::Void Back_Click(System::Object^ sender, System::EventArgs^ e);
		
	private: System::Void Regg_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ name = this->tbName->Text;
		System::String^ surname = this->tbSurname->Text;
		System::String^ login = this->tbLogin->Text;
		System::String^ password = this->tbPassword->Text;
		if (name->Length == 0 || surname->Length == 0 || login->Length == 0 || password->Length == 0)
		{
			MessageBox::Show("Please enter necessary data", "Some of the fields are empty", MessageBoxButtons::OK);
			return;
		}
		try
		{
			User^ user = gcnew User;
			user->name = name;
			user->surname = surname;
			user->login = login;
			user->password = password;
			user_database->save_user(user);
			main_form = gcnew Main(user_database, message_database, user);
			this->Hide();
			main_form->ShowDialog();
			this->Close();

		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message, "Database error", MessageBoxButtons::OK);
		}
	
	}
	};
}
