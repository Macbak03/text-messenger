#include "ConversationView.h"
#include "Main.h"
namespace Komunikator1 {
	System::Void ConversationView::Return_Click(System::Object^ sender, System::EventArgs^ e)
	{
		main_form = gcnew Main;
		this->Hide();
		main_form->ShowDialog();
		this->Close();
	}
}

