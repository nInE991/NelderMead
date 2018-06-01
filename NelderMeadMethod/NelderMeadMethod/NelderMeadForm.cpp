#include "NelderMeadForm.h"
#include <string>

System::Void NelderMeadMethod::NelderMeadForm::Clear() {
	functionResultTextBox->Text = "";
	sigmaResultTextBox->Text = "";
	timeResultTextBox->Text = "";
	iterResultTextBox->Text = "";
	XTextbox->Text = "";
	XResultListview->Items->Clear();
}

System::Void NelderMeadMethod::NelderMeadForm::focus(System::Object^ sender, System::EventArgs^ e) {
	try {
		this->everyXnSelectRadioButton->Enabled = true;
		try {
			if (size  > Int32::Parse(sizeEditTextBox->Text)) {
				XListView->Items->Clear();
			}
			size = Int32::Parse(sizeEditTextBox->Text);
		}
		catch (System::Exception^ ferr) {
			XListView->Items->Clear();
			throw gcnew System::Exception("Некорректный ввод размера");
	    }
		
		if (size <= 0) {
			XTextbox->Text = "";
			XListView->Items->Clear();
			throw gcnew System::Exception("Не допустимый размер");
		}
		else if (size < 2) {
			XTextbox->Text = "";
			XListView->Items->Clear();
			throw gcnew System::Exception("Минимальный размер для данной реализации метода равен 2");
		}
		else if (size > 6) {
			this->allXnSelectRadioButton->Checked = true;
			this->everyXnSelectRadioButton->Enabled = false;
		}
	}
	catch (Exception^ err) {
		MessageBox::Show(err->Message);
	}

}

System::Void NelderMeadMethod::NelderMeadForm::seachButton_Click(System::Object^  sender, System::EventArgs^  e) {
	NeldearMead neldearMead;
	Clear();
	try {
		neldearMead.function = "4*(x0-5)^2+(x1-6)^2";
		neldearMead.size = size;
		neldearMead.tol = Double::Parse(tolEditTextBox->Text);
		neldearMead.alpha = Double::Parse(alphaEditTextBox->Text);
		neldearMead.betha = Double::Parse(betaEditTextBox->Text);
		neldearMead.gamma = Double::Parse(gammaEditTextBox->Text);

		neldearMead.x = new Polyhedron[neldearMead.size + 5];
		for (int k = 0; k < neldearMead.size + 6; k++) {
			neldearMead.x[k].j = new double[neldearMead.size];
		}
		if (XListView->Items->Count == size && everyXnSelectRadioButton->Enabled == true) {
			for (int i = 0; i < neldearMead.size; i++) {
				neldearMead.x[0].j[i] = Double::Parse(XListView->Items[i]->SubItems[0]->Text);
				for (int k = 1; k <= neldearMead.size; k++) {
					for (int i = 0; i < neldearMead.size; i++) {
						if (k == i) {
							neldearMead.x[k].j[i] = neldearMead.x[0].j[i] + (1 / (k * sqrt(2))*(sqrt(k + 1) + k - 1));
						}
						else {
							neldearMead.x[k].j[i] = neldearMead.x[0].j[i] + (1 / (k * sqrt(2))*(sqrt(k + 1) - 1));
						}
					}
				}
			}

		/*	for (int i = 0; i <= neldearMead.size; i++) {
				for (int j = 0; j < neldearMead.size; j++) {
					
				}
			}*/
		}
		else if (XListView->Items->Count>0 && everyXnSelectRadioButton->Enabled == true) {
			for (int i = 0; i < neldearMead.size; i++) {
				neldearMead.x[0].j[i] = Double::Parse(XListView->Items[0]->SubItems[0]->Text);
			}
		}
		else {
			throw gcnew System::Exception("Не заполнены значения Xn!");
		}
		int iter = 0;
		double expt = 0;
		do {
			neldearMead.Max();
			neldearMead.Min();
			neldearMead.Center();
			neldearMead.Reflection();
			if (neldearMead.Fuction(neldearMead.x[neldearMead.size + 3]) <= neldearMead.Fuction(neldearMead.x[neldearMead.xl])) {
				neldearMead.Stretching();
				if (neldearMead.Fuction(neldearMead.x[neldearMead.size + 4]) < neldearMead.Fuction(neldearMead.x[neldearMead.xl])) {
					neldearMead.ChangeH(neldearMead.size + 4);
				}
				else {
					neldearMead.ChangeH((neldearMead.size + 3));
				}
			}
			else {
				if (neldearMead.Fuction(neldearMead.x[neldearMead.size + 3]) > neldearMead.Fuction(neldearMead.x[neldearMead.xg])) {
					if (neldearMead.Fuction(neldearMead.x[neldearMead.size + 3]) > neldearMead.Fuction(neldearMead.x[neldearMead.xh])) {
						neldearMead.Compression();
						if (neldearMead.Fuction(neldearMead.x[neldearMead.size + 5]) > neldearMead.Fuction(neldearMead.x[neldearMead.xh])) {
							neldearMead.Reduction();
						}
						else {
							neldearMead.ChangeH((neldearMead.size + 5));
						}
					}
					else {
						neldearMead.ChangeH((neldearMead.size + 3));
					}
				}
				else {
					neldearMead.ChangeH((neldearMead.size + 3));
				}
			}
			iter++;
		} while (neldearMead.Epsilon() > neldearMead.tol && iter < 1000);
		for (int i = 0; i < neldearMead.size; i++) {
			XResultListview->Items->Add(neldearMead.x[neldearMead.xl].j[i].ToString());
		}
		functionResultTextBox->Text = neldearMead.Fuction(neldearMead.x[neldearMead.xl]).ToString();
		sigmaResultTextBox->Text = neldearMead.Epsilon().ToString();
		iterResultTextBox->Text = iter.ToString();


	}
	catch (System::Exception^ err) {
		MessageBox::Show(err->Message);
	}

}

System::Void NelderMeadMethod::NelderMeadForm::CleanButton_Click(System::Object^  sender, System::EventArgs^  e) {

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
	else if (XTextbox->Text != "" && XListView->Items->Count < 1 && allXnSelectRadioButton->Checked == true) {
		double item;
		try {
			item = double::Parse(XTextbox->Text);
			XListView->Items->Add(item.ToString());
		}
		catch (System::Exception^ err) {
			MessageBox::Show(err->Message);
		}
	}
	else if (sizeEditTextBox->Text=="") {
		MessageBox::Show("Заполните размер!");
	}
	else if ((XListView->Items->Count >= size&&everyXnSelectRadioButton->Checked == true)||(XListView->Items->Count == 1 && allXnSelectRadioButton->Checked == true)) {
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
