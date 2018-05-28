#include "NelderMeadForm.h"
#include <string>

System::Void NelderMeadMethod::NelderMeadForm::focus(System::Object^ sender, System::EventArgs^ e) {
	try {
		allXnSelectRadioButton->Enabled = false;
		everyXnSelectRadioButton->Enabled = false;
		AddXButton->Enabled = false;
		DelXButton->Enabled = false;
		try {
			size = Int32::Parse(sizeEditTextBox->Text);
		}
		catch (System::Exception^ ferr) {
			throw gcnew System::Exception("Некорректный ввод размера");
	    }
		
		if (size <= 0) {
			throw gcnew System::Exception("Не допустимый размер");
		}
		else if (size < 2) {
			throw gcnew System::Exception("Минимальный размер для данной реализации метода равен 2");
		}
		else if (size <= 6) {
			allXnSelectRadioButton->Enabled = true;
			everyXnSelectRadioButton->Enabled = true;
			AddXButton->Enabled = true;
			DelXButton->Enabled = true;
		}
		else {
			this->allXnSelectRadioButton->Checked = true;
			allXnSelectRadioButton->Enabled = true;
			AddXButton->Enabled = true;
			DelXButton->Enabled = true;
			}	

	}
	catch (Exception^ err) {
		MessageBox::Show(err->Message);
	}

}

System::Void NelderMeadMethod::NelderMeadForm::seachButton_Click(System::Object^  sender, System::EventArgs^  e) {

}

System::Void NelderMeadMethod::NelderMeadForm::CleanButton_Click(System::Object^  sender, System::EventArgs^  e) {
	functionResultTextBox->Text = "";
	sigmaResultTextBox->Text = "";
	timeResultTextBox->Text = "";
	iterResultTextBox->Text = "";
	XTextbox->Text = "";
	XResultListview->Items->Clear();
}

System::Void NelderMeadMethod::NelderMeadForm::AddXButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (XTextbox->Text != ""&& XListView->Items->Count < size && everyXnSelectRadioButton->Checked == true) {
		double item;
		try {
			item = double::Parse(XTextbox->Text);
			XListView->Items->Add(item.ToString());
			//timeResultTextBox->Text = XListView->Items[0]->SubItems[0]->Text;
		}
		catch (System::Exception^ err) {
			MessageBox::Show(err->Message);
		}
	}
	else if (XTextbox->Text != ""&& XListView->Items->Count < 1 && allXnSelectRadioButton->Checked == true) {
		double item;
		try {
			item = double::Parse(XTextbox->Text);
			XListView->Items->Add(item.ToString());
		}
		catch (System::Exception^ err) {
			MessageBox::Show(err->Message);
		}
	}
	else if (XListView->Items->Count >= size&&everyXnSelectRadioButton->Checked == true) {
		MessageBox::Show("Ячейки заполнены!");
	}
	else if (XListView->Items->Count <= 1 && allXnSelectRadioButton->Checked == true) {
		MessageBox::Show("Ячейки заполнены!");
	}
	else if (XTextbox->Text == "") {
		MessageBox::Show("Введите значение!");
	}
	XTextbox->Text = "";
}

System::Void NelderMeadMethod::NelderMeadForm::DelXButton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		XListView->Items->Remove(XListView->SelectedItems[0]);
	}
	catch (Exception^ err) {
		MessageBox::Show("Не выбран элемент для удаления!");
	}
}

System::Void NelderMeadMethod::NelderMeadForm::allXnSelectRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	XTextbox->Text = "";
	XListView->Items->Clear();
}

System::Void NelderMeadMethod::NelderMeadForm::everyXnSelectRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	XTextbox->Text = "";
	XListView->Items->Clear();
}
