#include "Main.h"
#include "Start.h"
namespace Komunikator1 {

	System::Void Main::LogOut_Click(System::Object^ sender, System::EventArgs^ e) {
		start_form = gcnew Start(user_database);
		this->Hide();
		start_form->ShowDialog();
		this->Close();
	}

}