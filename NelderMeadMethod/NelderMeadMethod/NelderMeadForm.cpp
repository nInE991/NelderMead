#include "NelderMeadForm.h"
#include <string>

System::Void NelderMeadMethod:: NelderMeadForm::sizeEditTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {

}

System::Void NelderMeadMethod::NelderMeadForm::focus(System::Object^ sender, System::EventArgs^ e) {
	try {
		NeldearMead nelderMead;
		nelderMead.size = Int32::Parse(sizeEditTextBox->Text);
		dataGridViewX->ColumnCount = nelderMead.size+1;
		for (int i = 0; i < nelderMead.size; i++) {
			dataGridViewX->Columns[i]->Name = "y" + i;
		}
		allXnSelectRadioButton->Enabled = true;
		everyXnSelectRadioButton->Enabled = true;
		/*
		for (int i = 0; i < nelderMead.size + 1; i++) {
			dataGridViewX->Columns[i]->Name = "x" + i;
			for (int j = 0; j < nelderMead.size + 1; j++) {
				dataGridViewX->Columns[i]->Cell;
			}
			
		}
	*/
	}
	catch (FormatException^ err) {
		MessageBox::Show(err->Message);
	}

}

System::Void NelderMeadMethod::NelderMeadForm::seachButton_Click(System::Object^  sender, System::EventArgs^  e) {
}

System::Void NelderMeadMethod::NelderMeadForm::CleanButton_Click(System::Object^  sender, System::EventArgs^  e) {
	dataGridViewX->Columns->Clear();
	dataGridViewX->Rows->Clear();


}



