#pragma once
#include "Main.h"
#include "Register.h"

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
		Start(void)
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
	private: System::Windows::Forms::TextBox^ Username;
	private: System::Windows::Forms::TextBox^ Password;
	private: System::Windows::Forms::Button^ Log_in;
	private: System::Windows::Forms::Button^ Reg;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private:
		Main^ main_form;
		Register^ register_form;

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
			this->Username = (gcnew System::Windows::Forms::TextBox());
			this->Password = (gcnew System::Windows::Forms::TextBox());
			this->Log_in = (gcnew System::Windows::Forms::Button());
			this->Reg = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Username
			// 
			this->Username->Location = System::Drawing::Point(155, 74);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(317, 22);
			this->Username->TabIndex = 0;
			// 
			// Password
			// 
			this->Password->Location = System::Drawing::Point(155, 130);
			this->Password->Name = L"Password";
			this->Password->PasswordChar = '*';
			this->Password->Size = System::Drawing::Size(317, 22);
			this->Password->TabIndex = 1;
			this->Password->Tag = L"";
			// 
			// Log_in
			// 
			this->Log_in->Location = System::Drawing::Point(155, 184);
			this->Log_in->Name = L"Log_in";
			this->Log_in->Size = System::Drawing::Size(317, 32);
			this->Log_in->TabIndex = 2;
			this->Log_in->Text = L"Log in";
			this->Log_in->UseVisualStyleBackColor = true;
			this->Log_in->Click += gcnew System::EventHandler(this, &Start::Log_in_Click);
			// 
			// Reg
			// 
			this->Reg->Location = System::Drawing::Point(222, 231);
			this->Reg->Name = L"Reg";
			this->Reg->Size = System::Drawing::Size(184, 46);
			this->Reg->TabIndex = 3;
			this->Reg->Text = L"Register";
			this->Reg->UseVisualStyleBackColor = true;
			this->Reg->Click += gcnew System::EventHandler(this, &Start::Reg_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(152, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Enter username";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(153, 111);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Enter password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(190, 155);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(247, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"You typed wrong username or password";
			this->label3->Visible = false;
			// 
			// Start
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(646, 346);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Reg);
			this->Controls->Add(this->Log_in);
			this->Controls->Add(this->Password);
			this->Controls->Add(this->Username);
			this->Name = L"Start";
			this->Text = L"Start";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Reg_Click(System::Object^ sender, System::EventArgs^ e) {
		register_form = gcnew Register;
		this->Hide();
		register_form->ShowDialog();
		this->Close();
	}
	private: System::Void Log_in_Click(System::Object^ sender, System::EventArgs^ e) {
		main_form = gcnew Main;
		this->Hide();
		main_form->ShowDialog();
		this->Close();
	}
	};
}
