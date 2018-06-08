#pragma once
#include "NeldearMead.h"

namespace NelderMeadMethod {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
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
	private: System::Windows::Forms::ListView^  XListView;
	private: System::Windows::Forms::TextBox^  XTextbox;
	private: System::Windows::Forms::Button^  AddXButton;
	private: System::Windows::Forms::Button^  DelXButton;


	private: System::Windows::Forms::ListView^  XResultListview;
	private: System::Windows::Forms::Label^  XLabel;
	private: System::Windows::Forms::Label^  EditxLabel;
	bool cond = false;
	bool button = false;
	int size;
	DateTime ds;
	static NeldearMead *neldearMead = new NeldearMead;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker;


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
			this->XListView = (gcnew System::Windows::Forms::ListView());
			this->XTextbox = (gcnew System::Windows::Forms::TextBox());
			this->AddXButton = (gcnew System::Windows::Forms::Button());
			this->DelXButton = (gcnew System::Windows::Forms::Button());
			this->XResultListview = (gcnew System::Windows::Forms::ListView());
			this->XLabel = (gcnew System::Windows::Forms::Label());
			this->EditxLabel = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->backgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// functionEditLabel
			// 
			this->functionEditLabel->AutoSize = true;
			this->functionEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->functionEditLabel->Location = System::Drawing::Point(56, 37);
			this->functionEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->functionEditLabel->Name = L"functionEditLabel";
			this->functionEditLabel->Size = System::Drawing::Size(93, 18);
			this->functionEditLabel->TabIndex = 60;
			this->functionEditLabel->Text = L"Function(Xn)";
			// 
			// XnEditLabel
			// 
			this->XnEditLabel->AutoSize = true;
			this->XnEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->XnEditLabel->Location = System::Drawing::Point(106, 179);
			this->XnEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->XnEditLabel->Name = L"XnEditLabel";
			this->XnEditLabel->Size = System::Drawing::Size(44, 18);
			this->XnEditLabel->TabIndex = 33;
			this->XnEditLabel->Text = L"Xn(0)";
			// 
			// sizeEditLabel
			// 
			this->sizeEditLabel->AutoSize = true;
			this->sizeEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sizeEditLabel->Location = System::Drawing::Point(398, 40);
			this->sizeEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->sizeEditLabel->Name = L"sizeEditLabel";
			this->sizeEditLabel->Size = System::Drawing::Size(79, 18);
			this->sizeEditLabel->TabIndex = 32;
			this->sizeEditLabel->Text = L"Dimension";
			// 
			// alphaEditLabel
			// 
			this->alphaEditLabel->AutoSize = true;
			this->alphaEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->alphaEditLabel->Location = System::Drawing::Point(434, 108);
			this->alphaEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->alphaEditLabel->Name = L"alphaEditLabel";
			this->alphaEditLabel->Size = System::Drawing::Size(44, 18);
			this->alphaEditLabel->TabIndex = 31;
			this->alphaEditLabel->Text = L"Alpha";
			// 
			// betaEditLabel
			// 
			this->betaEditLabel->AutoSize = true;
			this->betaEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->betaEditLabel->Location = System::Drawing::Point(440, 143);
			this->betaEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->betaEditLabel->Name = L"betaEditLabel";
			this->betaEditLabel->Size = System::Drawing::Size(38, 18);
			this->betaEditLabel->TabIndex = 30;
			this->betaEditLabel->Text = L"Beta";
			// 
			// gammaEditLabel
			// 
			this->gammaEditLabel->AutoSize = true;
			this->gammaEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->gammaEditLabel->Location = System::Drawing::Point(416, 179);
			this->gammaEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->gammaEditLabel->Name = L"gammaEditLabel";
			this->gammaEditLabel->Size = System::Drawing::Size(62, 18);
			this->gammaEditLabel->TabIndex = 29;
			this->gammaEditLabel->Text = L"Gamma";
			// 
			// tolEditLabel
			// 
			this->tolEditLabel->AutoSize = true;
			this->tolEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tolEditLabel->Location = System::Drawing::Point(75, 253);
			this->tolEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->tolEditLabel->Name = L"tolEditLabel";
			this->tolEditLabel->Size = System::Drawing::Size(74, 18);
			this->tolEditLabel->TabIndex = 28;
			this->tolEditLabel->Text = L"Tolerance";
			// 
			// iterLimEditLabel
			// 
			this->iterLimEditLabel->AutoSize = true;
			this->iterLimEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->iterLimEditLabel->Location = System::Drawing::Point(383, 253);
			this->iterLimEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->iterLimEditLabel->Name = L"iterLimEditLabel";
			this->iterLimEditLabel->Size = System::Drawing::Size(95, 18);
			this->iterLimEditLabel->TabIndex = 27;
			this->iterLimEditLabel->Text = L"Iteration Limit";
			// 
			// timeLimEditLabel
			// 
			this->timeLimEditLabel->AutoSize = true;
			this->timeLimEditLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->timeLimEditLabel->Location = System::Drawing::Point(402, 217);
			this->timeLimEditLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->timeLimEditLabel->Name = L"timeLimEditLabel";
			this->timeLimEditLabel->Size = System::Drawing::Size(76, 18);
			this->timeLimEditLabel->TabIndex = 26;
			this->timeLimEditLabel->Text = L"Time Limit";
			// 
			// functionEditTextBox
			// 
			this->functionEditTextBox->Location = System::Drawing::Point(165, 37);
			this->functionEditTextBox->Margin = System::Windows::Forms::Padding(4);
			this->functionEditTextBox->Name = L"functionEditTextBox";
			this->functionEditTextBox->Size = System::Drawing::Size(196, 24);
			this->functionEditTextBox->TabIndex = 0;
			// 
			// sizeEditTextBox
			// 
			this->sizeEditTextBox->Location = System::Drawing::Point(499, 37);
			this->sizeEditTextBox->Margin = System::Windows::Forms::Padding(4);
			this->sizeEditTextBox->Name = L"sizeEditTextBox";
			this->sizeEditTextBox->Size = System::Drawing::Size(175, 24);
			this->sizeEditTextBox->TabIndex = 1;
			this->sizeEditTextBox->Leave += gcnew System::EventHandler(this, &NelderMeadForm::focus);
			// 
			// alphaEditTextBox
			// 
			this->alphaEditTextBox->Location = System::Drawing::Point(499, 105);
			this->alphaEditTextBox->Margin = System::Windows::Forms::Padding(4);
			this->alphaEditTextBox->Name = L"alphaEditTextBox";
			this->alphaEditTextBox->Size = System::Drawing::Size(175, 24);
			this->alphaEditTextBox->TabIndex = 10;
			this->alphaEditTextBox->Text = L"1";
			// 
			// betaEditTextBox
			// 
			this->betaEditTextBox->Location = System::Drawing::Point(499, 140);
			this->betaEditTextBox->Margin = System::Windows::Forms::Padding(4);
			this->betaEditTextBox->Name = L"betaEditTextBox";
			this->betaEditTextBox->Size = System::Drawing::Size(175, 24);
			this->betaEditTextBox->TabIndex = 11;
			this->betaEditTextBox->Text = L"0,5";
			// 
			// gammaEditTextBox
			// 
			this->gammaEditTextBox->Location = System::Drawing::Point(499, 176);
			this->gammaEditTextBox->Margin = System::Windows::Forms::Padding(4);
			this->gammaEditTextBox->Name = L"gammaEditTextBox";
			this->gammaEditTextBox->Size = System::Drawing::Size(175, 24);
			this->gammaEditTextBox->TabIndex = 12;
			this->gammaEditTextBox->Text = L"2";
			// 
			// tolEditTextBox
			// 
			this->tolEditTextBox->Location = System::Drawing::Point(165, 250);
			this->tolEditTextBox->Margin = System::Windows::Forms::Padding(4);
			this->tolEditTextBox->Name = L"tolEditTextBox";
			this->tolEditTextBox->Size = System::Drawing::Size(196, 24);
			this->tolEditTextBox->TabIndex = 9;
			this->tolEditTextBox->Text = L"1e-28";
			// 
			// iterLimTextBox
			// 
			this->iterLimTextBox->Location = System::Drawing::Point(499, 250);
			this->iterLimTextBox->Margin = System::Windows::Forms::Padding(4);
			this->iterLimTextBox->Name = L"iterLimTextBox";
			this->iterLimTextBox->Size = System::Drawing::Size(175, 24);
			this->iterLimTextBox->TabIndex = 14;
			this->iterLimTextBox->Text = L"200";
			// 
			// timeLimEditTextBox
			// 
			this->timeLimEditTextBox->Location = System::Drawing::Point(499, 214);
			this->timeLimEditTextBox->Margin = System::Windows::Forms::Padding(4);
			this->timeLimEditTextBox->Name = L"timeLimEditTextBox";
			this->timeLimEditTextBox->Size = System::Drawing::Size(175, 24);
			this->timeLimEditTextBox->TabIndex = 13;
			this->timeLimEditTextBox->Text = L"100";
			// 
			// functionResultTextBox
			// 
			this->functionResultTextBox->Location = System::Drawing::Point(165, 492);
			this->functionResultTextBox->Margin = System::Windows::Forms::Padding(4);
			this->functionResultTextBox->Name = L"functionResultTextBox";
			this->functionResultTextBox->ReadOnly = true;
			this->functionResultTextBox->Size = System::Drawing::Size(196, 24);
			this->functionResultTextBox->TabIndex = 18;
			// 
			// xResultLabel
			// 
			this->xResultLabel->AutoSize = true;
			this->xResultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->xResultLabel->Location = System::Drawing::Point(123, 418);
			this->xResultLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->xResultLabel->Name = L"xResultLabel";
			this->xResultLabel->Size = System::Drawing::Size(24, 18);
			this->xResultLabel->TabIndex = 24;
			this->xResultLabel->Text = L"X*";
			// 
			// functionResultLabel
			// 
			this->functionResultLabel->AutoSize = true;
			this->functionResultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->functionResultLabel->Location = System::Drawing::Point(56, 495);
			this->functionResultLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->functionResultLabel->Name = L"functionResultLabel";
			this->functionResultLabel->Size = System::Drawing::Size(91, 18);
			this->functionResultLabel->TabIndex = 23;
			this->functionResultLabel->Text = L"Function(X*)";
			// 
			// sigmaResultLabel
			// 
			this->sigmaResultLabel->AutoSize = true;
			this->sigmaResultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->sigmaResultLabel->Location = System::Drawing::Point(99, 527);
			this->sigmaResultLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->sigmaResultLabel->Name = L"sigmaResultLabel";
			this->sigmaResultLabel->Size = System::Drawing::Size(50, 18);
			this->sigmaResultLabel->TabIndex = 19;
			this->sigmaResultLabel->Text = L"Sigma";
			// 
			// iterResultLabel
			// 
			this->iterResultLabel->AutoSize = true;
			this->iterResultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->iterResultLabel->Location = System::Drawing::Point(363, 418);
			this->iterResultLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->iterResultLabel->Name = L"iterResultLabel";
			this->iterResultLabel->Size = System::Drawing::Size(129, 18);
			this->iterResultLabel->TabIndex = 23;
			this->iterResultLabel->Text = L"NumberOfIteration";
			// 
			// sigmaResultTextBox
			// 
			this->sigmaResultTextBox->Location = System::Drawing::Point(165, 524);
			this->sigmaResultTextBox->Margin = System::Windows::Forms::Padding(4);
			this->sigmaResultTextBox->Name = L"sigmaResultTextBox";
			this->sigmaResultTextBox->ReadOnly = true;
			this->sigmaResultTextBox->Size = System::Drawing::Size(196, 24);
			this->sigmaResultTextBox->TabIndex = 20;
			// 
			// iterResultTextBox
			// 
			this->iterResultTextBox->Location = System::Drawing::Point(499, 415);
			this->iterResultTextBox->Margin = System::Windows::Forms::Padding(4);
			this->iterResultTextBox->Name = L"iterResultTextBox";
			this->iterResultTextBox->ReadOnly = true;
			this->iterResultTextBox->Size = System::Drawing::Size(175, 24);
			this->iterResultTextBox->TabIndex = 22;
			// 
			// timeResultTextBox
			// 
			this->timeResultTextBox->Location = System::Drawing::Point(499, 381);
			this->timeResultTextBox->Margin = System::Windows::Forms::Padding(4);
			this->timeResultTextBox->Name = L"timeResultTextBox";
			this->timeResultTextBox->ReadOnly = true;
			this->timeResultTextBox->Size = System::Drawing::Size(175, 24);
			this->timeResultTextBox->TabIndex = 21;
			// 
			// timeResultLabel
			// 
			this->timeResultLabel->AutoSize = true;
			this->timeResultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->timeResultLabel->Location = System::Drawing::Point(381, 384);
			this->timeResultLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->timeResultLabel->Name = L"timeResultLabel";
			this->timeResultLabel->Size = System::Drawing::Size(94, 18);
			this->timeResultLabel->TabIndex = 17;
			this->timeResultLabel->Text = L"ElapsedTime";
			// 
			// seachButton
			// 
			this->seachButton->Location = System::Drawing::Point(211, 328);
			this->seachButton->Margin = System::Windows::Forms::Padding(4);
			this->seachButton->Name = L"seachButton";
			this->seachButton->Size = System::Drawing::Size(150, 39);
			this->seachButton->TabIndex = 15;
			this->seachButton->Text = L"Run";
			this->seachButton->UseVisualStyleBackColor = true;
			this->seachButton->Click += gcnew System::EventHandler(this, &NelderMeadForm::seachButton_Click);
			// 
			// CleanButton
			// 
			this->CleanButton->Location = System::Drawing::Point(390, 328);
			this->CleanButton->Margin = System::Windows::Forms::Padding(4);
			this->CleanButton->Name = L"CleanButton";
			this->CleanButton->Size = System::Drawing::Size(120, 39);
			this->CleanButton->TabIndex = 16;
			this->CleanButton->Text = L"Clear Output";
			this->CleanButton->UseVisualStyleBackColor = true;
			this->CleanButton->Click += gcnew System::EventHandler(this, &NelderMeadForm::CleanButton_Click);
			// 
			// allXnSelectRadioButton
			// 
			this->allXnSelectRadioButton->AutoSize = true;
			this->allXnSelectRadioButton->Location = System::Drawing::Point(528, 73);
			this->allXnSelectRadioButton->Name = L"allXnSelectRadioButton";
			this->allXnSelectRadioButton->Size = System::Drawing::Size(41, 22);
			this->allXnSelectRadioButton->TabIndex = 2;
			this->allXnSelectRadioButton->Text = L"All";
			this->allXnSelectRadioButton->UseVisualStyleBackColor = true;
			this->allXnSelectRadioButton->CheckedChanged += gcnew System::EventHandler(this, &NelderMeadForm::allXnSelectRadioButton_CheckedChanged);
			// 
			// everyXnSelectRadioButton
			// 
			this->everyXnSelectRadioButton->AutoSize = true;
			this->everyXnSelectRadioButton->Checked = true;
			this->everyXnSelectRadioButton->Location = System::Drawing::Point(584, 73);
			this->everyXnSelectRadioButton->Name = L"everyXnSelectRadioButton";
			this->everyXnSelectRadioButton->Size = System::Drawing::Size(63, 22);
			this->everyXnSelectRadioButton->TabIndex = 3;
			this->everyXnSelectRadioButton->TabStop = true;
			this->everyXnSelectRadioButton->Text = L"Every";
			this->everyXnSelectRadioButton->UseVisualStyleBackColor = true;
			this->everyXnSelectRadioButton->CheckedChanged += gcnew System::EventHandler(this, &NelderMeadForm::everyXnSelectRadioButton_CheckedChanged);
			// 
			// XListView
			// 
			this->XListView->HideSelection = false;
			this->XListView->Location = System::Drawing::Point(165, 143);
			this->XListView->MultiSelect = false;
			this->XListView->Name = L"XListView";
			this->XListView->Size = System::Drawing::Size(196, 95);
			this->XListView->TabIndex = 9;
			this->XListView->UseCompatibleStateImageBehavior = false;
			this->XListView->View = System::Windows::Forms::View::SmallIcon;
			// 
			// XTextbox
			// 
			this->XTextbox->Location = System::Drawing::Point(165, 73);
			this->XTextbox->Name = L"XTextbox";
			this->XTextbox->Size = System::Drawing::Size(196, 24);
			this->XTextbox->TabIndex = 4;
			// 
			// AddXButton
			// 
			this->AddXButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddXButton->Location = System::Drawing::Point(188, 103);
			this->AddXButton->Name = L"AddXButton";
			this->AddXButton->Size = System::Drawing::Size(63, 29);
			this->AddXButton->TabIndex = 5;
			this->AddXButton->Text = L"Add";
			this->AddXButton->UseVisualStyleBackColor = true;
			this->AddXButton->Click += gcnew System::EventHandler(this, &NelderMeadForm::AddXButton_Click);
			// 
			// DelXButton
			// 
			this->DelXButton->Location = System::Drawing::Point(272, 103);
			this->DelXButton->Name = L"DelXButton";
			this->DelXButton->Size = System::Drawing::Size(63, 29);
			this->DelXButton->TabIndex = 7;
			this->DelXButton->Text = L"Del";
			this->DelXButton->UseVisualStyleBackColor = true;
			this->DelXButton->Click += gcnew System::EventHandler(this, &NelderMeadForm::DelXButton_Click);
			// 
			// XResultListview
			// 
			this->XResultListview->Activation = System::Windows::Forms::ItemActivation::OneClick;
			this->XResultListview->HoverSelection = true;
			this->XResultListview->Location = System::Drawing::Point(165, 381);
			this->XResultListview->Name = L"XResultListview";
			this->XResultListview->Size = System::Drawing::Size(196, 97);
			this->XResultListview->TabIndex = 8;
			this->XResultListview->UseCompatibleStateImageBehavior = false;
			this->XResultListview->View = System::Windows::Forms::View::SmallIcon;
			// 
			// XLabel
			// 
			this->XLabel->AutoSize = true;
			this->XLabel->Location = System::Drawing::Point(110, 75);
			this->XLabel->Name = L"XLabel";
			this->XLabel->Size = System::Drawing::Size(44, 18);
			this->XLabel->TabIndex = 1;
			this->XLabel->Text = L"Xn(0)";
			// 
			// EditxLabel
			// 
			this->EditxLabel->AutoSize = true;
			this->EditxLabel->Location = System::Drawing::Point(431, 75);
			this->EditxLabel->Name = L"EditxLabel";
			this->EditxLabel->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->EditxLabel->Size = System::Drawing::Size(47, 18);
			this->EditxLabel->TabIndex = 0;
			this->EditxLabel->Text = L"Edit X";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(211, 290);
			this->progressBar1->MarqueeAnimationSpeed = 0;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(385, 23);
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Marquee;
			this->progressBar1->TabIndex = 61;
			this->progressBar1->Visible = false;
			// 
			// backgroundWorker
			// 
			this->backgroundWorker->WorkerSupportsCancellation = true;
			this->backgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &NelderMeadForm::backgroundWorker_DoWork);
			this->backgroundWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &NelderMeadForm::backgroundWorker_RunWorkerComleted);
			// 
			// NelderMeadForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(744, 587);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->EditxLabel);
			this->Controls->Add(this->XLabel);
			this->Controls->Add(this->XResultListview);
			this->Controls->Add(this->DelXButton);
			this->Controls->Add(this->AddXButton);
			this->Controls->Add(this->XTextbox);
			this->Controls->Add(this->XListView);
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void focus(System::Object^ sender, System::EventArgs^ e);
	private: System::Void seachButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void CleanButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AddXButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DelXButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void allXnSelectRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void everyXnSelectRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	public: System::Void  Clear();
	private: System::Void backgroundWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e); 
	private: System::Void backgroundWorker_RunWorkerComleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e);
};
}
