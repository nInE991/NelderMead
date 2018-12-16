#include "NelderMeadForm.h"
#include <string>
#include <msclr\marshal_cppstd.h>

System::Void NelderMeadMethod::NelderMeadForm::Clear() {
	functionResultTextBox->Text="";
	functionResultTextBox->Text = "";
	sigmaResultTextBox->Text = "";
	timeResultTextBox->Text = "";
	iterResultTextBox->Text = "";
	//XTextbox->Text = "";
	XResultListview->Items->Clear();
	progressBar1->Visible = false;
	progressBar1->MarqueeAnimationSpeed = 0;
}

System::Void NelderMeadMethod::NelderMeadForm::focus(System::Object^ sender, System::EventArgs^ e) {
	try {
		everyXnSelectRadioButton->Enabled = true;
		editDataGrigView = 0;
		try {
			
			dataGridView1->Columns->Clear();
			size = Int32::Parse(sizeEditTextBox->Text);
			dataGridView1->Columns->Add("X","X");

		}
		catch (System::Exception^ ferr) {
			dataGridView1->Columns->Clear();
			throw gcnew System::Exception("Некорректный ввод размера");
	    }
		
		if (size <= 0) {
			dataGridView1->Columns->Clear();
			throw gcnew System::Exception("Не допустимый размер");
		}
		else if (size < 2) {
			dataGridView1->Columns->Clear();
			throw gcnew System::Exception("Минимальный размер для данной реализации метода равен 2");
		}
		else if (size > 6) {
			allXnSelectRadioButton->Checked = true;
			everyXnSelectRadioButton->Enabled = false;
			dataGridView1->Rows->Add("");
		}
		else {
			if (allXnSelectRadioButton->Checked == true) {
					dataGridView1->Rows->Add("");
			}
			else {
				for (int i = 0; i <size; i++) {
					dataGridView1->Rows->Add("");
				}
			}
			
		}
	}
	catch (Exception^ err) {
		MessageBox::Show(err->Message);
	}
}

System::Void NelderMeadMethod::NelderMeadForm::seachButton_Click(System::Object^  sender, System::EventArgs^  e) {

	if (!button) {
	ds = DateTime::UtcNow;
	Clear();
	button = true;
	cond = false;
	progressBar1->Visible = true;
	progressBar1->MarqueeAnimationSpeed = 25;
	try {
		
		msclr::interop::marshal_context context;
		neldearMead->function = context.marshal_as<std::string>(functionEditTextBox->Text);
		neldearMead->size = size;
		neldearMead->tol = Double::Parse(tolEditTextBox->Text);
		neldearMead->alpha = Double::Parse(alphaEditTextBox->Text);
		neldearMead->betha = Double::Parse(betaEditTextBox->Text);
		neldearMead->gamma = Double::Parse(gammaEditTextBox->Text);
		neldearMead->iterlim = Int32::Parse(iterLimTextBox->Text);
		neldearMead->timelim = Int32::Parse(timeLimEditTextBox->Text);
		neldearMead->x = new Polyhedron[neldearMead->size + 5];
		for (int k = 0; k < neldearMead->size + 6; k++) {
			neldearMead->x[k].j = new double[neldearMead->size];
		}
		if (editDataGrigView == size && everyXnSelectRadioButton->Enabled == true) {
			for (int i = 0; i < neldearMead->size; i++) {
				neldearMead->x[0].j[i] = Double::Parse(dataGridView1->Rows[i]->Cells[0]->Value->ToString());
				for (int k = 1; k <= neldearMead->size; k++) {
					for (int i = 0; i < neldearMead->size; i++) {
						if (k == i) {
							neldearMead->x[k].j[i] = neldearMead->x[0].j[i] + (1 / (k * sqrt(2))*(sqrt(k + 1) + k - 1));
						}
						else {
							neldearMead->x[k].j[i] = neldearMead->x[0].j[i] + (1 / (k * sqrt(2))*(sqrt(k + 1) - 1));
						}
					}
				}
			}
		}
		else if (editDataGrigView == 1 && allXnSelectRadioButton->Enabled == true) {
			for (int i = 0; i < neldearMead->size; i++) {
				neldearMead->x[0].j[i] = Double::Parse(dataGridView1->Rows[0]->Cells[0]->Value->ToString());
				for (int k = 1; k <= neldearMead->size; k++) {
					for (int i = 0; i < neldearMead->size; i++) {
						if (k == i) {
							neldearMead->x[k].j[i] = neldearMead->x[0].j[i] + (1 / (k * sqrt(2))*(sqrt(k + 1) + k - 1));
						}
						else {
							neldearMead->x[k].j[i] = neldearMead->x[0].j[i] + (1 / (k * sqrt(2))*(sqrt(k + 1) - 1));
						}
					}
				}
			}
		}
		else {
			throw gcnew System::Exception("Не заполнены значения Xn!");
		}
		neldearMead->iter = 0;
		backgroundWorker->RunWorkerAsync();
	}
	catch (System::Exception^ err) {
		Clear();
		MessageBox::Show(err->Message);
		button = false;
		backgroundWorker->CancelAsync();
		}
	}
}

System::Void NelderMeadMethod::NelderMeadForm::CleanButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!button) {
		functionResultTextBox->Text = "";
		functionResultTextBox->Text = "";
		sigmaResultTextBox->Text = "";
		timeResultTextBox->Text = "";
		iterResultTextBox->Text = "";
		XResultListview->Items->Clear();
		progressBar1->Visible = false;
		progressBar1->MarqueeAnimationSpeed = 0;
	}	
}


System::Void NelderMeadMethod::NelderMeadForm::allXnSelectRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	focus(sender,  e);

}

System::Void NelderMeadMethod::NelderMeadForm::everyXnSelectRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	focus(sender, e);
}

System::Void NelderMeadMethod::NelderMeadForm::backgroundWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	try {
		do {
			neldearMead->Method();
		} while (neldearMead->Epsilon() > neldearMead->tol && neldearMead->iter <neldearMead->iterlim && TimeSpan(DateTime::UtcNow - ds).Seconds<neldearMead->timelim);
		cond = true;
	}
	catch (System::Exception^ err) {
		MessageBox::Show(err->Message);
	}
	finally{
		button = false;
	}

}

System::Void NelderMeadMethod::NelderMeadForm::backgroundWorker_RunWorkerComleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
	if (cond) {
		for (int i = 0; i < neldearMead->size; i++) {
			XResultListview->Items->Add(neldearMead->x[neldearMead->xl].j[i].ToString());
		}
		functionResultTextBox->Text = neldearMead->Fuction(neldearMead->x[neldearMead->xl]).ToString();
		sigmaResultTextBox->Text = neldearMead->Epsilon().ToString();
		iterResultTextBox->Text = neldearMead->iter.ToString();
		timeResultTextBox->Text = TimeSpan(DateTime::UtcNow - ds).Seconds.ToString();
	}
	button = false;
	progressBar1->Visible = false;
}
