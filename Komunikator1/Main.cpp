#include "Main.h"
#include "Start.h"
namespace Komunikator1 {
	System::Void Main::logOutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		start_form = gcnew Start(user_database, message_database);
		this->Hide();
		start_form->ShowDialog();
		this->Close();
	}
	System::Void Main::deleteAcountToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult dialog_result = MessageBox::Show("Delete account?", "Delete account", MessageBoxButtons::YesNo);
		if (dialog_result == System::Windows::Forms::DialogResult::Yes)
		{
			UserMessage^ user_message = gcnew UserMessage;
			message_database->find_messages(user_message);
			message_database->delete_messages(user_message);
			user_database->delete_user(user);
			start_form = gcnew Start(user_database, message_database);
			this->Hide();
			start_form->ShowDialog();
			this->Close();
		}
		else
		{
			return;
		}
	}
}