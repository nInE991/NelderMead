#pragma once
#include "NeldearMead.h"

namespace NelderMeadMethod {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// —водка дл€ NelderMeadForm
	/// </summary>
	
	public ref class NelderMeadForm : public System::Windows::Forms::Form
	{
	public:
		
		NelderMeadForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктор
			
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~NelderMeadForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  functionEditLabel;
	private: System::Windows::Forms::Label^  XnEditLabel;
	private: System::Windows::Forms::Label^  sizeEditLabel;
	private: System::Windows::Forms::Label^  alphaEditLabel;
	private: System::Windows::Forms::Label^  betaEditLabel;
	private: System::Windows::Forms::Label^  gammaEditLabel;

	protected:
	private: System::Windows::Forms::Label^  tolEditLabel;
	private: System::Windows::Forms::Label^  iterLimEditLabel;
	private: System::Windows::Forms::Label^  timeLimEditLabel;
	private: System::Windows::Forms::TextBox^  functionEditTextBox;
	private: System::Windows::Forms::TextBox^  sizeEditTextBox;
	private: System::Windows::Forms::TextBox^  alphaEditTextBox;
	private: System::Windows::Forms::TextBox^  betaEditTextBox;
	private: System::Windows::Forms::TextBox^  gammaEditTextBox;
	private: System::Windows::Forms::TextBox^  tolEditTextBox;
	private: System::Windows::Forms::TextBox^  iterLimTextBox;
	private: System::Windows::Forms::TextBox^  timeLimEditTextBox;
	private: System::Windows::Forms::TextBox^  functionResultTextBox;

	private: System::Windows::Forms::Label^  xResultLabel;
	private: System::Windows::Forms::Label^  functionResultLabel;
	private: System::Windows::Forms::Label^  sigmaResultLabel;
	private: System::Windows::Forms::Label^  iterResultLabel;
	private: System::Windows::Forms::TextBox^  sigmaResultTextBox;
	private: System::Windows::Forms::TextBox^  iterResultTextBox;
	private: System::Windows::Forms::TextBox^  timeResultTextBox;
	private: System::Windows::Forms::Label^  timeResultLabel;

	private: System::Windows::Forms::Button^  seachButton;
	private: System::Windows::Forms::Button^  CleanButton;
	private: System::Windows::Forms::RadioButton^  allXnSelectRadioButton;
	private: System::Windows::Forms::RadioButton^  everyXnSelectRadioButton;
	private: System::Windows::Forms::DataGridView^  dataGridViewX;
	private: System::Windows::Forms::DataGridView^  dataGridViewXResullt;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->functionEditLabel = (gcnew System::Windows::Forms::Label());
			this->XnEditLabel = (gcnew System::Windows::Forms::Label());
			this->sizeEditLabel = (gcnew System::Windows::Forms::Label());
			this->alphaEditLabel = (gcnew System::Windows::Forms::Label());
			this->betaEditLabel = (gcnew System::Windows::Forms::Label());
			this->gammaEditLabel = (gcnew System::Windows::Forms::Label());
			this->tolEditLabel = (gcnew System::Windows::Forms::Label());
			this->iterLimEditLabel = (gcnew System::Windows::Forms::Label());
			this->timeLimEditLabel = (gcnew System::Windows::Forms::Label());
			this->functionEditTextBox = (gcnew System::Windows::Forms::TextBox());
			this->sizeEditTextBox = (gcnew System::Windows::Forms::TextBox());
			this->alphaEditTextBox = (gcnew System::Windows::Forms::TextBox());
			this->betaEditTextBox = (gcnew System::Windows::Forms::TextBox());
			this->gammaEditTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tolEditTextBox = (gcnew System::Windows::Forms::TextBox());
			this->iterLimTextBox = (gcnew System::Windows::Forms::TextBox());
			this->timeLimEditTextBox = (gcnew System::Windows::Forms::TextBox());
			this->functionResultTextBox = (gcnew System::Windows::Forms::TextBox());
			this->xResultLabel = (gcnew System::Windows::Forms::Label());
			this->functionResultLabel = (gcnew System::Windows::Forms::Label());
			this->sigmaResultLabel = (gcnew System::Windows::Forms::Label());
			this->iterResultLabel = (gcnew System::Windows::Forms::Label());
			this->sigmaResultTextBox = (gcnew System::Windows::Forms::TextBox());
			this->iterResultTextBox = (gcnew System::Windows::Forms::TextBox());
			this->timeResultTextBox = (gcnew System::Windows::Forms::TextBox());
			this->timeResultLabel = (gcnew System::Windows::Forms::Label());
			this->seachButton = (gcnew System::Windows::Forms::Button());
			this->CleanButton = (gcnew System::Windows::Forms::Button());
			this->allXnSelectRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->everyXnSelectRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->dataGridViewX = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewXResullt = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewXResullt))->BeginInit();
			this->SuspendLayout();
			// 
			// functionEditLabel
			// 
			this->functionEditLabel->AutoSize = true;
			this->functionEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->functionEditLabel->Location = System::Drawing::Point(80, 41);
			this->functionEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->functionEditLabel->Name = L"functionEditLabel";
			this->functionEditLabel->Size = System::Drawing::Size(93, 18);
			this->functionEditLabel->TabIndex = 0;
			this->functionEditLabel->Text = L"Function(Xn)";
			// 
			// XnEditLabel
			// 
			this->XnEditLabel->AutoSize = true;
			this->XnEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->XnEditLabel->Location = System::Drawing::Point(103, 112);
			this->XnEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->XnEditLabel->Name = L"XnEditLabel";
			this->XnEditLabel->Size = System::Drawing::Size(26, 18);
			this->XnEditLabel->TabIndex = 1;
			this->XnEditLabel->Text = L"Xn";
			// 
			// sizeEditLabel
			// 
			this->sizeEditLabel->AutoSize = true;
			this->sizeEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sizeEditLabel->Location = System::Drawing::Point(433, 38);
			this->sizeEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->sizeEditLabel->Name = L"sizeEditLabel";
			this->sizeEditLabel->Size = System::Drawing::Size(37, 18);
			this->sizeEditLabel->TabIndex = 2;
			this->sizeEditLabel->Text = L"Size";
			// 
			// alphaEditLabel
			// 
			this->alphaEditLabel->AutoSize = true;
			this->alphaEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->alphaEditLabel->Location = System::Drawing::Point(432, 77);
			this->alphaEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->alphaEditLabel->Name = L"alphaEditLabel";
			this->alphaEditLabel->Size = System::Drawing::Size(44, 18);
			this->alphaEditLabel->TabIndex = 3;
			this->alphaEditLabel->Text = L"Alpha";
			// 
			// betaEditLabel
			// 
			this->betaEditLabel->AutoSize = true;
			this->betaEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->betaEditLabel->Location = System::Drawing::Point(434, 112);
			this->betaEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->betaEditLabel->Name = L"betaEditLabel";
			this->betaEditLabel->Size = System::Drawing::Size(38, 18);
			this->betaEditLabel->TabIndex = 4;
			this->betaEditLabel->Text = L"Beta";
			// 
			// gammaEditLabel
			// 
			this->gammaEditLabel->AutoSize = true;
			this->gammaEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->gammaEditLabel->Location = System::Drawing::Point(424, 148);
			this->gammaEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->gammaEditLabel->Name = L"gammaEditLabel";
			this->gammaEditLabel->Size = System::Drawing::Size(62, 18);
			this->gammaEditLabel->TabIndex = 5;
			this->gammaEditLabel->Text = L"Gamma";
			// 
			// tolEditLabel
			// 
			this->tolEditLabel->AutoSize = true;
			this->tolEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tolEditLabel->Location = System::Drawing::Point(81, 222);
			this->tolEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->tolEditLabel->Name = L"tolEditLabel";
			this->tolEditLabel->Size = System::Drawing::Size(74, 18);
			this->tolEditLabel->TabIndex = 6;
			this->tolEditLabel->Text = L"Tolerance";
			// 
			// iterLimEditLabel
			// 
			this->iterLimEditLabel->AutoSize = true;
			this->iterLimEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->iterLimEditLabel->Location = System::Drawing::Point(410, 222);
			this->iterLimEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->iterLimEditLabel->Name = L"iterLimEditLabel";
			this->iterLimEditLabel->Size = System::Drawing::Size(95, 18);
			this->iterLimEditLabel->TabIndex = 7;
			this->iterLimEditLabel->Text = L"Iteration Limit";
			// 
			// timeLimEditLabel
			// 
			this->timeLimEditLabel->AutoSize = true;
			this->timeLimEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->timeLimEditLabel->Location = System::Drawing::Point(421, 186);
			this->timeLimEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->timeLimEditLabel->Name = L"timeLimEditLabel";
			this->timeLimEditLabel->Size = System::Drawing::Size(76, 18);
			this->timeLimEditLabel->TabIndex = 8;
			this->timeLimEditLabel->Text = L"Time Limit";
			// 
			// functionEditTextBox
			// 
			this->functionEditTextBox->Location = System::Drawing::Point(189, 38);
			this->functionEditTextBox->Margin = System::Windows::Forms::Padding(4);
			this->functionEditTextBox->Name = L"functionEditTextBox";
			this->functionEditTextBox->Size = System::Drawing::Size(199, 24);
			this->functionEditTextBox->TabIndex = 9;
			// 
			// sizeEditTextBox
			// 
			this->sizeEditTextBox->Location = System::Drawing::Point(526, 35);
			this->sizeEditTextBox->Margin = System::Windows::Forms::Padding(4);
			this->sizeEditTextBox->Name = L"sizeEditTextBox";
			this->sizeEditTextBox->Size = System::Drawing::Size(175, 24);
			this->sizeEditTextBox->TabIndex = 10;
			this->sizeEditTextBox->TextChanged += gcnew System::EventHandler(this, &NelderMeadForm::sizeEditTextBox_TextChanged);
			this->sizeEditTextBox->Leave += gcnew System::EventHandler(this, &NelderMeadForm::focus);
			// 
			// alphaEditTextBox
			// 
			this->alphaEditTextBox->Location = System::Drawing::Point(526, 74);
			this->alphaEditTextBox->Margin = System::Windows::Forms::Padding(4);
			this->alphaEditTextBox->Name = L"alphaEditTextBox";
			this->alphaEditTextBox->Size = System::Drawing::Size(175, 24);
			this->alphaEditTextBox->TabIndex = 11;
			// 
			// betaEditTextBox
			// 
			this->betaEditTextBox->Location = System::Drawing::Point(526, 109);
			this->betaEditTextBox->Margin = System::Windows::Forms::Padding(4);
			this->betaEditTextBox->Name = L"betaEditTextBox";
			this->betaEditTextBox->Size = System::Drawing::Size(175, 24);
			this->betaEditTextBox->TabIndex = 12;
			// 
			// gammaEditTextBox
			// 
			this->gammaEditTextBox->Location = System::Drawing::Point(526, 145);
			this->gammaEditTextBox->Margin = System::Windows::Forms::Padding(4);
			this->gammaEditTextBox->Name = L"gammaEditTextBox";
			this->gammaEditTextBox->Size = System::Drawing::Size(175, 24);
			this->gammaEditTextBox->TabIndex = 13;
			// 
			// tolEditTextBox
			// 
			this->tolEditTextBox->Location = System::Drawing::Point(189, 219);
			this->tolEditTextBox->Margin = System::Windows::Forms::Padding(4);
			this->tolEditTextBox->Name = L"tolEditTextBox";
			this->tolEditTextBox->Size = System::Drawing::Size(196, 24);
			this->tolEditTextBox->TabIndex = 14;
			// 
			// iterLimTextBox
			// 
			this->iterLimTextBox->Location = System::Drawing::Point(526, 219);
			this->iterLimTextBox->Margin = System::Windows::Forms::Padding(4);
			this->iterLimTextBox->Name = L"iterLimTextBox";
			this->iterLimTextBox->Size = System::Drawing::Size(175, 24);
			this->iterLimTextBox->TabIndex = 15;
			// 
			// timeLimEditTextBox
			// 
			this->timeLimEditTextBox->Location = System::Drawing::Point(526, 183);
			this->timeLimEditTextBox->Margin = System::Windows::Forms::Padding(4);
			this->timeLimEditTextBox->Name = L"timeLimEditTextBox";
			this->timeLimEditTextBox->Size = System::Drawing::Size(175, 24);
			this->timeLimEditTextBox->TabIndex = 16;
			// 
			// functionResultTextBox
			// 
			this->functionResultTextBox->Location = System::Drawing::Point(189, 459);
			this->functionResultTextBox->Margin = System::Windows::Forms::Padding(4);
			this->functionResultTextBox->Name = L"functionResultTextBox";
			this->functionResultTextBox->ReadOnly = true;
			this->functionResultTextBox->Size = System::Drawing::Size(200, 24);
			this->functionResultTextBox->TabIndex = 17;
			// 
			// xResultLabel
			// 
			this->xResultLabel->AutoSize = true;
			this->xResultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->xResultLabel->Location = System::Drawing::Point(103, 387);
			this->xResultLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->xResultLabel->Name = L"xResultLabel";
			this->xResultLabel->Size = System::Drawing::Size(26, 18);
			this->xResultLabel->TabIndex = 19;
			this->xResultLabel->Text = L"Xn";
			// 
			// functionResultLabel
			// 
			this->functionResultLabel->AutoSize = true;
			this->functionResultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->functionResultLabel->Location = System::Drawing::Point(81, 461);
			this->functionResultLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->functionResultLabel->Name = L"functionResultLabel";
			this->functionResultLabel->Size = System::Drawing::Size(93, 18);
			this->functionResultLabel->TabIndex = 20;
			this->functionResultLabel->Text = L"Function(Xn)";
			// 
			// sigmaResultLabel
			// 
			this->sigmaResultLabel->AutoSize = true;
			this->sigmaResultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->sigmaResultLabel->Location = System::Drawing::Point(87, 492);
			this->sigmaResultLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->sigmaResultLabel->Name = L"sigmaResultLabel";
			this->sigmaResultLabel->Size = System::Drawing::Size(50, 18);
			this->sigmaResultLabel->TabIndex = 21;
			this->sigmaResultLabel->Text = L"Sigma";
			// 
			// iterResultLabel
			// 
			this->iterResultLabel->AutoSize = true;
			this->iterResultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->iterResultLabel->Location = System::Drawing::Point(432, 384);
			this->iterResultLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->iterResultLabel->Name = L"iterResultLabel";
			this->iterResultLabel->Size = System::Drawing::Size(60, 18);
			this->iterResultLabel->TabIndex = 22;
			this->iterResultLabel->Text = L"Iteration";
			// 
			// sigmaResultTextBox
			// 
			this->sigmaResultTextBox->Location = System::Drawing::Point(189, 492);
			this->sigmaResultTextBox->Margin = System::Windows::Forms::Padding(4);
			this->sigmaResultTextBox->Name = L"sigmaResultTextBox";
			this->sigmaResultTextBox->ReadOnly = true;
			this->sigmaResultTextBox->Size = System::Drawing::Size(200, 24);
			this->sigmaResultTextBox->TabIndex = 23;
			// 
			// iterResultTextBox
			// 
			this->iterResultTextBox->Location = System::Drawing::Point(526, 381);
			this->iterResultTextBox->Margin = System::Windows::Forms::Padding(4);
			this->iterResultTextBox->Name = L"iterResultTextBox";
			this->iterResultTextBox->ReadOnly = true;
			this->iterResultTextBox->Size = System::Drawing::Size(175, 24);
			this->iterResultTextBox->TabIndex = 24;
			// 
			// timeResultTextBox
			// 
			this->timeResultTextBox->Location = System::Drawing::Point(526, 347);
			this->timeResultTextBox->Margin = System::Windows::Forms::Padding(4);
			this->timeResultTextBox->Name = L"timeResultTextBox";
			this->timeResultTextBox->ReadOnly = true;
			this->timeResultTextBox->Size = System::Drawing::Size(175, 24);
			this->timeResultTextBox->TabIndex = 25;
			// 
			// timeResultLabel
			// 
			this->timeResultLabel->AutoSize = true;
			this->timeResultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->timeResultLabel->Location = System::Drawing::Point(433, 350);
			this->timeResultLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->timeResultLabel->Name = L"timeResultLabel";
			this->timeResultLabel->Size = System::Drawing::Size(49, 18);
			this->timeResultLabel->TabIndex = 26;
			this->timeResultLabel->Text = L"Times";
			// 
			// seachButton
			// 
			this->seachButton->Location = System::Drawing::Point(242, 272);
			this->seachButton->Margin = System::Windows::Forms::Padding(4);
			this->seachButton->Name = L"seachButton";
			this->seachButton->Size = System::Drawing::Size(150, 39);
			this->seachButton->TabIndex = 28;
			this->seachButton->Text = L"SeachButton";
			this->seachButton->UseVisualStyleBackColor = true;
			this->seachButton->Click += gcnew System::EventHandler(this, &NelderMeadForm::seachButton_Click);
			// 
			// CleanButton
			// 
			this->CleanButton->Location = System::Drawing::Point(417, 272);
			this->CleanButton->Margin = System::Windows::Forms::Padding(4);
			this->CleanButton->Name = L"CleanButton";
			this->CleanButton->Size = System::Drawing::Size(120, 39);
			this->CleanButton->TabIndex = 29;
			this->CleanButton->Text = L"CleanButton";
			this->CleanButton->UseVisualStyleBackColor = true;
			this->CleanButton->Click += gcnew System::EventHandler(this, &NelderMeadForm::CleanButton_Click);
			// 
			// allXnSelectRadioButton
			// 
			this->allXnSelectRadioButton->AutoSize = true;
			this->allXnSelectRadioButton->Enabled = false;
			this->allXnSelectRadioButton->Location = System::Drawing::Point(242, 185);
			this->allXnSelectRadioButton->Name = L"allXnSelectRadioButton";
			this->allXnSelectRadioButton->Size = System::Drawing::Size(41, 22);
			this->allXnSelectRadioButton->TabIndex = 30;
			this->allXnSelectRadioButton->Text = L"All";
			this->allXnSelectRadioButton->UseVisualStyleBackColor = true;
			// 
			// everyXnSelectRadioButton
			// 
			this->everyXnSelectRadioButton->AutoSize = true;
			this->everyXnSelectRadioButton->Checked = true;
			this->everyXnSelectRadioButton->Enabled = false;
			this->everyXnSelectRadioButton->Location = System::Drawing::Point(298, 185);
			this->everyXnSelectRadioButton->Name = L"everyXnSelectRadioButton";
			this->everyXnSelectRadioButton->Size = System::Drawing::Size(63, 22);
			this->everyXnSelectRadioButton->TabIndex = 31;
			this->everyXnSelectRadioButton->TabStop = true;
			this->everyXnSelectRadioButton->Text = L"Every";
			this->everyXnSelectRadioButton->UseVisualStyleBackColor = true;
			// 
			// dataGridViewX
			// 
			this->dataGridViewX->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewX->Location = System::Drawing::Point(189, 77);
			this->dataGridViewX->Name = L"dataGridViewX";
			this->dataGridViewX->Size = System::Drawing::Size(199, 102);
			this->dataGridViewX->TabIndex = 32;
			// 
			// dataGridViewXResullt
			// 
			this->dataGridViewXResullt->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewXResullt->Location = System::Drawing::Point(189, 347);
			this->dataGridViewXResullt->Name = L"dataGridViewXResullt";
			this->dataGridViewXResullt->Size = System::Drawing::Size(199, 102);
			this->dataGridViewXResullt->TabIndex = 33;
			// 
			// NelderMeadForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(771, 558);
			this->Controls->Add(this->dataGridViewXResullt);
			this->Controls->Add(this->dataGridViewX);
			this->Controls->Add(this->everyXnSelectRadioButton);
			this->Controls->Add(this->allXnSelectRadioButton);
			this->Controls->Add(this->CleanButton);
			this->Controls->Add(this->seachButton);
			this->Controls->Add(this->timeResultLabel);
			this->Controls->Add(this->timeResultTextBox);
			this->Controls->Add(this->iterResultTextBox);
			this->Controls->Add(this->sigmaResultTextBox);
			this->Controls->Add(this->iterResultLabel);
			this->Controls->Add(this->sigmaResultLabel);
			this->Controls->Add(this->functionResultLabel);
			this->Controls->Add(this->xResultLabel);
			this->Controls->Add(this->functionResultTextBox);
			this->Controls->Add(this->timeLimEditTextBox);
			this->Controls->Add(this->iterLimTextBox);
			this->Controls->Add(this->tolEditTextBox);
			this->Controls->Add(this->gammaEditTextBox);
			this->Controls->Add(this->betaEditTextBox);
			this->Controls->Add(this->alphaEditTextBox);
			this->Controls->Add(this->sizeEditTextBox);
			this->Controls->Add(this->functionEditTextBox);
			this->Controls->Add(this->timeLimEditLabel);
			this->Controls->Add(this->iterLimEditLabel);
			this->Controls->Add(this->tolEditLabel);
			this->Controls->Add(this->gammaEditLabel);
			this->Controls->Add(this->betaEditLabel);
			this->Controls->Add(this->alphaEditLabel);
			this->Controls->Add(this->sizeEditLabel);
			this->Controls->Add(this->XnEditLabel);
			this->Controls->Add(this->functionEditLabel);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"NelderMeadForm";
			this->Text = L"NelderMeadForm";
			this->Load += gcnew System::EventHandler(this, &NelderMeadForm::NelderMeadForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewXResullt))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
public: System::Void sizeEditTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void focus(System::Object^ sender, System::EventArgs^ e);
private: System::Void seachButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void CleanButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void NelderMeadForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};

}
