#include "Register.h"
#include "Start.h"
namespace Komunikator1 {

	System::Void Register::Back_Click(System::Object^ sender, System::EventArgs^ e) {
		start_form = gcnew Start(user_database, message_database);
		this->Hide();
		start_form->ShowDialog();
		this->Close();
	}
}
