#pragma once
#include "ConversationView.h"

namespace Komunikator1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	ref class Start;
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
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
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ Search_for_user;
	private: System::Windows::Forms::Button^ LogOut;
	private: System::Windows::Forms::ListBox^ ChooseFromUsers;
	private: System::Windows::Forms::Button^ Select;
	private: System::Windows::Forms::Label^ label2;

	private:
		Start^ start_form;
		ConversationView^ convo_form;

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
			this->Search_for_user = (gcnew System::Windows::Forms::TextBox());
			this->LogOut = (gcnew System::Windows::Forms::Button());
			this->ChooseFromUsers = (gcnew System::Windows::Forms::ListBox());
			this->Select = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(214, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Search for user";
			// 
			// Search_for_user
			// 
			this->Search_for_user->Location = System::Drawing::Point(121, 31);
			this->Search_for_user->Name = L"Search_for_user";
			this->Search_for_user->Size = System::Drawing::Size(286, 22);
			this->Search_for_user->TabIndex = 1;
			// 
			// LogOut
			// 
			this->LogOut->Location = System::Drawing::Point(473, 21);
			this->LogOut->Name = L"LogOut";
			this->LogOut->Size = System::Drawing::Size(106, 32);
			this->LogOut->TabIndex = 2;
			this->LogOut->Text = L"Log out";
			this->LogOut->UseVisualStyleBackColor = true;
			this->LogOut->Click += gcnew System::EventHandler(this, &Main::LogOut_Click);
			// 
			// ChooseFromUsers
			// 
			this->ChooseFromUsers->FormattingEnabled = true;
			this->ChooseFromUsers->ItemHeight = 16;
			this->ChooseFromUsers->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"User1", L"User2", L"User3", L"User4", L"User5" });
			this->ChooseFromUsers->Location = System::Drawing::Point(83, 98);
			this->ChooseFromUsers->Name = L"ChooseFromUsers";
			this->ChooseFromUsers->Size = System::Drawing::Size(361, 228);
			this->ChooseFromUsers->TabIndex = 3;
			// 
			// Select
			// 
			this->Select->Enabled = false;
			this->Select->Location = System::Drawing::Point(169, 341);
			this->Select->Name = L"Select";
			this->Select->Size = System::Drawing::Size(174, 53);
			this->Select->TabIndex = 4;
			this->Select->Text = L"Select";
			this->Select->UseVisualStyleBackColor = true;
			this->Select->Click += gcnew System::EventHandler(this, &Main::Select_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(202, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Choose from users";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 434);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Select);
			this->Controls->Add(this->ChooseFromUsers);
			this->Controls->Add(this->LogOut);
			this->Controls->Add(this->Search_for_user);
			this->Controls->Add(this->label1);
			this->Name = L"Main";
			this->Text = L"Main";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void LogOut_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void Select_Click(System::Object^ sender, System::EventArgs^ e) {
		convo_form = gcnew ConversationView;
		this->Hide();
		convo_form->ShowDialog();
		this->Close();
	}
};
}
