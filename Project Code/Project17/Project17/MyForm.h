#pragma once
#include "RawData.h"
#include "CalculatedData.h"
#include "DataController.h"
#include "EngineInfoForm.h"
#include <vector>
#include <msclr\marshal_cppstd.h>
using namespace msclr::interop;


namespace Project17 
{

	static std::vector <Cycle> cycleList;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:	
		
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	public:

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		int runNum;
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  ImportButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  StatusLabel;
	private: int flag;
	private: System::Windows::Forms::Label^  label3;
	public: System::Windows::Forms::ProgressBar^  progressBar1;
	private:


	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->ImportButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->StatusLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"CSV Files|*.csv";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(127, 286);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Choose CSV File";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(127, 315);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(106, 21);
			this->comboBox1->TabIndex = 1;
			// 
			// ImportButton
			// 
			this->ImportButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ImportButton->Location = System::Drawing::Point(254, 286);
			this->ImportButton->Name = L"ImportButton";
			this->ImportButton->Size = System::Drawing::Size(75, 23);
			this->ImportButton->TabIndex = 2;
			this->ImportButton->Text = L"Import";
			this->ImportButton->UseVisualStyleBackColor = true;
			this->ImportButton->Click += gcnew System::EventHandler(this, &MyForm::ImportButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(84, 170);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 3;
			// 
			// StatusLabel
			// 
			this->StatusLabel->AutoSize = true;
			this->StatusLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StatusLabel->Location = System::Drawing::Point(74, 354);
			this->StatusLabel->Name = L"StatusLabel";
			this->StatusLabel->Size = System::Drawing::Size(40, 13);
			this->StatusLabel->TabIndex = 4;
			this->StatusLabel->Text = L"Status:";
			this->StatusLabel->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(44, 318);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Run Number:";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(127, 374);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(106, 23);
			this->progressBar1->TabIndex = 6;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(110, 130);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(151, 132);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(101, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(169, 39);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Stirling Engine";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click_1);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(100, 62);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(172, 63);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(370, 419);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->StatusLabel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ImportButton);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Stirling Engine";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
	{
		std::string path = marshal_as<std::string>(this->openFileDialog1->FileName);
		int runCount;
		try
		{
			runCount = DataController::getExcelRunCount(path);
			StatusLabel->Text = "Status: File Found";
		}
		catch (std::exception e)
		{
			System:String ^msg= gcnew String(e.what());
			StatusLabel->Text = "Status: " + msg;
		}
		comboBox1->Items->Clear();
		for (int i = 0; i < runCount; i++)
			comboBox1->Items->Add(i + 1);
		comboBox1->SelectedIndex = 0;
		//this->Hide();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		openFileDialog1->ShowDialog();
	}

		/*	 */

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{

	}

	private: System:: Void importData()
	{
		DataController::averageCycleList.clear();
		DataController::averageElectricalPowerByCurrentList.clear();
		DataController::calculatedDataList.clear();
		DataController::cycleList.clear();
		DataController::dataList.clear();
		std::string path = marshal_as<std::string>(this->openFileDialog1->FileName);
		try
		{
			DataController::getDataFromExcel(path, runNum);
			flag = 1;
		}
		catch (std::exception e)
		{
			flag = -1;
		}
	}
	private: System::Void ImportButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (this->openFileDialog1->FileName == "")
			return;
		flag = 0;
		this->progressBar1->Value = 0;
		this->StatusLabel->Text = gcnew System::String("Status: Importing");
		//this->StatusLabel->Refresh();
		runNum = comboBox1->SelectedIndex + 1;
		backgroundWorker1->RunWorkerAsync(1);
		int pointCount=0;
		while (flag==0)
		{
			if (progressBar1->Value != progressBar1->Maximum)  //if the progress bar value reached maximum
			{
				Thread::Sleep(200);   //wait for 1 second
				this->progressBar1->Value += 1;
				if (progressBar1->Value % 5 == 0)
				{
					if (pointCount == 3)
					{
						this->StatusLabel->Text = gcnew System::String("Status: Importing");
						//this->StatusLabel->Refresh();
						pointCount = 0;
					}
					else
					{
						this->StatusLabel->Text += ".";
						this->StatusLabel->Refresh();
						pointCount++;
					}
				}
			}
		}
		this->progressBar1->Value = 0;
		this->StatusLabel->Text = "Status:";
		EngineInfoForm^ engineInfoForm = gcnew EngineInfoForm(this);		
		this->Hide();
		engineInfoForm->Show();
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) 
	{

	}


private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) 
{
	try
	{
		importData();
	}
	catch (std::exception e)
	{
		flag = -1;
	}
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
};
}
