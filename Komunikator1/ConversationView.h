#pragma once
#include "users.h"


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
		ConversationView(UserDatabase^ u_db) : user_database(u_db)
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
		~ConversationView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ tbMessage;

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ Return;
	private: System::Windows::Forms::RichTextBox^ tbConversation;
	private: System::Windows::Forms::Label^ label2;

	private:
		Main^ main_form;
		UserDatabase^ user_database;

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
			this->tbMessage = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Return = (gcnew System::Windows::Forms::Button());
			this->tbConversation = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Message
			// 
			this->tbMessage->Location = System::Drawing::Point(119, 286);
			this->tbMessage->Name = L"tbMessage";
			this->tbMessage->Size = System::Drawing::Size(428, 101);
			this->tbMessage->TabIndex = 0;
			this->tbMessage->Text = L"";
			this->tbMessage->TextChanged += gcnew System::EventHandler(this, &ConversationView::richTextBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(286, 267);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Type message";
			// 
			// Return
			// 
			this->Return->Location = System::Drawing::Point(12, 12);
			this->Return->Name = L"Return";
			this->Return->Size = System::Drawing::Size(106, 32);
			this->Return->TabIndex = 2;
			this->Return->Text = L"Return";
			this->Return->UseVisualStyleBackColor = true;
			this->Return->Click += gcnew System::EventHandler(this, &ConversationView::Return_Click);
			// 
			// Conversation
			// 
			this->tbConversation->Enabled = false;
			this->tbConversation->Location = System::Drawing::Point(119, 54);
			this->tbConversation->Name = L"tbConversation";
			this->tbConversation->ReadOnly = true;
			this->tbConversation->Size = System::Drawing::Size(428, 191);
			this->tbConversation->TabIndex = 3;
			this->tbConversation->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(299, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Conversation";
			// 
			// ConversationView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(679, 439);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbConversation);
			this->Controls->Add(this->Return);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tbMessage);
			this->Name = L"ConversationView";
			this->Text = L"ConversationView";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Return_Click(System::Object^ sender, System::EventArgs^ e);

};
}
