#pragma once
#include "EngineInfo.h"
#include "DataController.h"
#include "RawData.h"
#include "CalculatedData.h"
#include "CyclesForm.h"
//#include <msclr\marshal_cppstd.h>

//#include "MyForm.h"
//using namespace msclr::interop;


namespace Project17
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;


	/// <summary>
	/// Summary for EngineInfo
	/// </summary>
	public ref class EngineInfoForm : public System::Windows::Forms::Form
	{
	public:
		EngineInfoForm(Form^ prevForm)
		{
			this->prevForm = prevForm;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	public:

	protected:
		double hotPistonArea, hotMinCylinderVolume, hotCrankShaftRadius, coldPistonArea, coldMinCylinderVolume, coldCrankShaftRadius;
		bool noException = true;
		String ^error;
	private: System::Windows::Forms::Label^  statusLabel;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	protected:

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		Form^ prevForm;
		~EngineInfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  NextButton;
	protected:

	private: System::Windows::Forms::TextBox^  hotPistonAreaTextBox;
	private: System::Windows::Forms::TextBox^  hotMinCylinderVolumeTextBox;
	private: System::Windows::Forms::TextBox^  hotCrankShaftRadiusTextBox;
	private: System::Windows::Forms::TextBox^  coldCrankShaftRadiusTextBox;




	private: System::Windows::Forms::TextBox^  coldMinCylinderVolumeTextBox;

	private: System::Windows::Forms::TextBox^  coldPistonAreaTextBox;
	private: System::Windows::Forms::ComboBox^  coldCrankShaftRadiusCombobox;


	private: System::Windows::Forms::ComboBox^  hotCrankShaftRadiusCombobox;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  hotCrankShaftRadiusLabel;

	private: System::Windows::Forms::Button^  BackButton;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		int flag;
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(EngineInfoForm::typeid));
			this->NextButton = (gcnew System::Windows::Forms::Button());
			this->hotPistonAreaTextBox = (gcnew System::Windows::Forms::TextBox());
			this->hotMinCylinderVolumeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->hotCrankShaftRadiusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->coldCrankShaftRadiusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->coldMinCylinderVolumeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->coldPistonAreaTextBox = (gcnew System::Windows::Forms::TextBox());
			this->coldCrankShaftRadiusCombobox = (gcnew System::Windows::Forms::ComboBox());
			this->hotCrankShaftRadiusCombobox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->hotCrankShaftRadiusLabel = (gcnew System::Windows::Forms::Label());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->statusLabel = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// NextButton
			// 
			this->NextButton->Location = System::Drawing::Point(250, 423);
			this->NextButton->Name = L"NextButton";
			this->NextButton->Size = System::Drawing::Size(102, 23);
			this->NextButton->TabIndex = 0;
			this->NextButton->Text = L"Calculate Data";
			this->NextButton->UseVisualStyleBackColor = true;
			this->NextButton->Click += gcnew System::EventHandler(this, &EngineInfoForm::button1_Click);
			// 
			// hotPistonAreaTextBox
			// 
			this->hotPistonAreaTextBox->Location = System::Drawing::Point(147, 142);
			this->hotPistonAreaTextBox->Name = L"hotPistonAreaTextBox";
			this->hotPistonAreaTextBox->Size = System::Drawing::Size(81, 20);
			this->hotPistonAreaTextBox->TabIndex = 1;
			this->hotPistonAreaTextBox->Text = L"216.666";
			// 
			// hotMinCylinderVolumeTextBox
			// 
			this->hotMinCylinderVolumeTextBox->Location = System::Drawing::Point(147, 168);
			this->hotMinCylinderVolumeTextBox->Name = L"hotMinCylinderVolumeTextBox";
			this->hotMinCylinderVolumeTextBox->Size = System::Drawing::Size(82, 20);
			this->hotMinCylinderVolumeTextBox->TabIndex = 2;
			this->hotMinCylinderVolumeTextBox->Text = L"435.39";
			// 
			// hotCrankShaftRadiusTextBox
			// 
			this->hotCrankShaftRadiusTextBox->Location = System::Drawing::Point(147, 193);
			this->hotCrankShaftRadiusTextBox->Name = L"hotCrankShaftRadiusTextBox";
			this->hotCrankShaftRadiusTextBox->Size = System::Drawing::Size(82, 20);
			this->hotCrankShaftRadiusTextBox->TabIndex = 3;
			this->hotCrankShaftRadiusTextBox->Text = L"6";
			// 
			// coldCrankShaftRadiusTextBox
			// 
			this->coldCrankShaftRadiusTextBox->Location = System::Drawing::Point(148, 302);
			this->coldCrankShaftRadiusTextBox->Name = L"coldCrankShaftRadiusTextBox";
			this->coldCrankShaftRadiusTextBox->Size = System::Drawing::Size(80, 20);
			this->coldCrankShaftRadiusTextBox->TabIndex = 4;
			this->coldCrankShaftRadiusTextBox->Text = L"6";
			// 
			// coldMinCylinderVolumeTextBox
			// 
			this->coldMinCylinderVolumeTextBox->Location = System::Drawing::Point(148, 277);
			this->coldMinCylinderVolumeTextBox->Name = L"coldMinCylinderVolumeTextBox";
			this->coldMinCylinderVolumeTextBox->Size = System::Drawing::Size(81, 20);
			this->coldMinCylinderVolumeTextBox->TabIndex = 5;
			this->coldMinCylinderVolumeTextBox->Text = L"435.39";
			// 
			// coldPistonAreaTextBox
			// 
			this->coldPistonAreaTextBox->Location = System::Drawing::Point(148, 251);
			this->coldPistonAreaTextBox->Name = L"coldPistonAreaTextBox";
			this->coldPistonAreaTextBox->Size = System::Drawing::Size(80, 20);
			this->coldPistonAreaTextBox->TabIndex = 6;
			this->coldPistonAreaTextBox->Text = L"216.666";
			// 
			// coldCrankShaftRadiusCombobox
			// 
			this->coldCrankShaftRadiusCombobox->FormattingEnabled = true;
			this->coldCrankShaftRadiusCombobox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"mm", L"cm", L"m" });
			this->coldCrankShaftRadiusCombobox->Location = System::Drawing::Point(238, 302);
			this->coldCrankShaftRadiusCombobox->Name = L"coldCrankShaftRadiusCombobox";
			this->coldCrankShaftRadiusCombobox->Size = System::Drawing::Size(44, 21);
			this->coldCrankShaftRadiusCombobox->TabIndex = 7;
			this->coldCrankShaftRadiusCombobox->SelectedIndexChanged += gcnew System::EventHandler(this, &EngineInfoForm::coldCrankShaftRadiusCombobox_SelectedIndexChanged);
			// 
			// hotCrankShaftRadiusCombobox
			// 
			this->hotCrankShaftRadiusCombobox->FormattingEnabled = true;
			this->hotCrankShaftRadiusCombobox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"mm", L"cm", L"m" });
			this->hotCrankShaftRadiusCombobox->Location = System::Drawing::Point(238, 192);
			this->hotCrankShaftRadiusCombobox->Name = L"hotCrankShaftRadiusCombobox";
			this->hotCrankShaftRadiusCombobox->Size = System::Drawing::Size(44, 21);
			this->hotCrankShaftRadiusCombobox->TabIndex = 8;
			this->hotCrankShaftRadiusCombobox->SelectedIndexChanged += gcnew System::EventHandler(this, &EngineInfoForm::hotCrankShaftRadiusCombobox_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(33, 145);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Piston Area:";
			this->label1->Click += gcnew System::EventHandler(this, &EngineInfoForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(145, 230);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 16);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Cold Piston:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(33, 171);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(105, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Min Cylinder Volume:";
			this->label3->Click += gcnew System::EventHandler(this, &EngineInfoForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(151, 116);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(76, 16);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Hot Piston:";
			this->label4->Click += gcnew System::EventHandler(this, &EngineInfoForm::label4_Click);
			// 
			// hotCrankShaftRadiusLabel
			// 
			this->hotCrankShaftRadiusLabel->AutoSize = true;
			this->hotCrankShaftRadiusLabel->Location = System::Drawing::Point(33, 196);
			this->hotCrankShaftRadiusLabel->Name = L"hotCrankShaftRadiusLabel";
			this->hotCrankShaftRadiusLabel->Size = System::Drawing::Size(102, 13);
			this->hotCrankShaftRadiusLabel->TabIndex = 13;
			this->hotCrankShaftRadiusLabel->Text = L"Crank Shaft Radius:";
			// 
			// BackButton
			// 
			this->BackButton->Location = System::Drawing::Point(33, 423);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(102, 23);
			this->BackButton->TabIndex = 15;
			this->BackButton->Text = L"Back";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &EngineInfoForm::BackButton_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &EngineInfoForm::backgroundWorker1_DoWork);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(143, 394);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(102, 23);
			this->progressBar1->TabIndex = 16;
			// 
			// statusLabel
			// 
			this->statusLabel->AutoSize = true;
			this->statusLabel->Location = System::Drawing::Point(95, 363);
			this->statusLabel->Name = L"statusLabel";
			this->statusLabel->Size = System::Drawing::Size(40, 13);
			this->statusLabel->TabIndex = 17;
			this->statusLabel->Text = L"Status:";
			this->statusLabel->Click += gcnew System::EventHandler(this, &EngineInfoForm::label5_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(97, 34);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(180, 33);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Engine Information";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(35, 254);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(64, 13);
			this->label6->TabIndex = 19;
			this->label6->Text = L"Piston Area:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(33, 279);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(105, 13);
			this->label7->TabIndex = 20;
			this->label7->Text = L"Min Cylinder Volume:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(33, 305);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(102, 13);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Crank Shaft Radius:";
			// 
			// EngineInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(380, 462);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->statusLabel);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->hotCrankShaftRadiusLabel);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->hotCrankShaftRadiusCombobox);
			this->Controls->Add(this->coldCrankShaftRadiusCombobox);
			this->Controls->Add(this->coldPistonAreaTextBox);
			this->Controls->Add(this->coldMinCylinderVolumeTextBox);
			this->Controls->Add(this->coldCrankShaftRadiusTextBox);
			this->Controls->Add(this->hotCrankShaftRadiusTextBox);
			this->Controls->Add(this->hotMinCylinderVolumeTextBox);
			this->Controls->Add(this->hotPistonAreaTextBox);
			this->Controls->Add(this->NextButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"EngineInfoForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Engine Information";
			this->Load += gcnew System::EventHandler(this, &EngineInfoForm::EngineInfo_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void EngineInfo_Load(System::Object^  sender, System::EventArgs^  e)
	{
		this->hotCrankShaftRadiusCombobox->SelectedIndex = 0;
		this->coldCrankShaftRadiusCombobox->SelectedIndex = 0;

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			statusLabel->Text = "Status: Calculating Data..";
			statusLabel->Refresh();
			flag = 0;
			hotPistonArea = System::Convert::ToDouble(this->hotPistonAreaTextBox->Text);
			hotMinCylinderVolume = System::Convert::ToDouble(this->hotMinCylinderVolumeTextBox->Text);
			hotCrankShaftRadius = System::Convert::ToDouble(this->hotCrankShaftRadiusTextBox->Text);
			if (this->hotCrankShaftRadiusCombobox->SelectedIndex == 1)
				hotCrankShaftRadius *= 10;
			if (this->hotCrankShaftRadiusCombobox->SelectedIndex == 2)
				hotCrankShaftRadius *= 1000;
			coldPistonArea = System::Convert::ToDouble(this->coldPistonAreaTextBox->Text);
			coldMinCylinderVolume = System::Convert::ToDouble(this->coldMinCylinderVolumeTextBox->Text);
			coldCrankShaftRadius = System::Convert::ToDouble(this->coldCrankShaftRadiusTextBox->Text);
			if (this->coldCrankShaftRadiusCombobox->SelectedIndex == 1)
				hotCrankShaftRadius *= 10;
			if (this->coldCrankShaftRadiusCombobox->SelectedIndex == 2)
				hotCrankShaftRadius *= 1000;
			backgroundWorker1->RunWorkerAsync(1);
			this->progressBar1->Value = 0;
			while ((flag == 0)&&(noException))
			{
				if (progressBar1->Value != progressBar1->Maximum)  //if the progress bar value reached maximum
				{
					Thread::Sleep(20);
					this->progressBar1->Value += 1;
				}
			}
			if (noException == false)
			{
				statusLabel->Text = "Status: " + error+"\nPlease go back and choose another.";
				statusLabel->Refresh();
				this->progressBar1->Value = 0;
				this->progressBar1->Refresh();
			}
			else
			{
				CyclesForm^ cyclesForm = gcnew CyclesForm(this);
				this->progressBar1->Value = 0;
				this->Hide();
				cyclesForm->Show();
				statusLabel->Text = "Status:";
				statusLabel->Refresh();
			}
		}
		catch (std::exception e)
		{
			String ^error = gcnew String(e.what());
			statusLabel->Text = "Status: " + error;
			statusLabel->Refresh();
		}
	}
	private: System::Void BackButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		prevForm->Show();
		this->Close();
	}


	private: System::Void coldCrankShaftRadiusCombobox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void calculate()
	{

		try
		{
			EngineInfo engineInfo(hotPistonArea, hotMinCylinderVolume, hotCrankShaftRadius,
				coldPistonArea, coldMinCylinderVolume, coldCrankShaftRadius);
			DataController dataController;
			DataController::calculatedDataList = dataController.calculateData
			(DataController::dataList, engineInfo);
			DataController::cycleList = dataController.calculateCycles(DataController::calculatedDataList);
			flag = 1;
		}
		catch (std::exception e)
		{
			throw e;
		}
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
	{
		try { calculate(); }
		catch (std::exception e)
		{		
			this->error = gcnew String(e.what());
			this->noException = false;
		}
	}
	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void hotCrankShaftRadiusCombobox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
