#pragma once
#include "DataController.h"
#include "ChooseGraphForm.h"
namespace Project17 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CyclesForm
	/// </summary>
	public ref class CyclesForm : public System::Windows::Forms::Form
	{
	public:
		CyclesForm(Form^ prevForm)
		{
			this->prevForm = prevForm;
			InitializeComponent();
		}
	private: System::Windows::Forms::Button^  nextButton;
	public:

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		Form^ prevForm;
		~CyclesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;




	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;

	private: array<System::Windows::Forms::TextBox^, 2>  ^txtGridBoxes;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  backButton;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(CyclesForm::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->nextButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::White;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(40, 84);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->Size = System::Drawing::Size(248, 329);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CyclesForm::tableLayoutPanel1_Paint);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label5->Location = System::Drawing::Point(204, 63);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(42, 16);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Watts";
			this->label5->Click += gcnew System::EventHandler(this, &CyclesForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label6->Location = System::Drawing::Point(85, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 15);
			this->label6->TabIndex = 6;
			this->label6->Text = L"RPM";
			this->label6->Click += gcnew System::EventHandler(this, &CyclesForm::label6_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(83, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(168, 25);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Thermal Power by RPM";
			// 
			// backButton
			// 
			this->backButton->BackColor = System::Drawing::SystemColors::Control;
			this->backButton->Location = System::Drawing::Point(40, 419);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(79, 23);
			this->backButton->TabIndex = 8;
			this->backButton->Text = L"Back";
			this->backButton->UseVisualStyleBackColor = false;
			this->backButton->Click += gcnew System::EventHandler(this, &CyclesForm::backButton_Click);
			// 
			// nextButton
			// 
			this->nextButton->BackColor = System::Drawing::SystemColors::Control;
			this->nextButton->Location = System::Drawing::Point(194, 419);
			this->nextButton->Name = L"nextButton";
			this->nextButton->Size = System::Drawing::Size(91, 23);
			this->nextButton->TabIndex = 9;
			this->nextButton->Text = L"Show Graphs";
			this->nextButton->UseVisualStyleBackColor = false;
			this->nextButton->Click += gcnew System::EventHandler(this, &CyclesForm::nextButton_Click);
			// 
			// CyclesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(329, 454);
			this->Controls->Add(this->nextButton);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CyclesForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Cycles";
			this->Load += gcnew System::EventHandler(this, &CyclesForm::CyclesForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loadTable()
	{
		DataController::averageCycleList = DataController::getAverageCycles(DataController::cycleList);
		this->tableLayoutPanel1->RowCount = DataController::averageCycleList.size();
		for (int i = 0; i < this->tableLayoutPanel1->RowCount; i++)
			this->tableLayoutPanel1->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20));
		this->txtGridBoxes = gcnew array<System::Windows::Forms::TextBox^, 2>(2, this->tableLayoutPanel1->RowCount);
		Cycle c;
		for (int Row = 0; Row < this->tableLayoutPanel1->RowCount; Row++)
		{
			c = DataController::averageCycleList[Row];
			for (int Column = 0; Column < 2; Column++)
			{
				this->txtGridBoxes[Column, Row] = (gcnew System::Windows::Forms::TextBox());
				this->txtGridBoxes[Column, Row]->Margin = System::Windows::Forms::Padding(0, 0, 0, 0);
				this->txtGridBoxes[Column, Row]->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->txtGridBoxes[Column, Row]->Dock = System::Windows::Forms::DockStyle::Fill;
				this->txtGridBoxes[Column, Row]->ReadOnly = true;
				this->tableLayoutPanel1->Controls->Add(this->txtGridBoxes[Column, Row], Column, Row);
			}
			this->txtGridBoxes[0, Row]->Text = System::Convert::ToString(c.getRPM());
			this->txtGridBoxes[1, Row]->Text = System::Convert::ToString(c.getCycleThermalPower());
		}
		this->tableLayoutPanel1->ResumeLayout();
		this->ResumeLayout();
		this->Show();
	}
	private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{

	}


	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e)
	{

	}
	private: System::Void CyclesForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		loadTable();
	}
	private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e)
	{

	}
	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e)
	{

	}
	private: System::Void backButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		prevForm->Show();
		this->Close();
	}
	private: System::Void nextButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		ChooseGraphForm^ formo = gcnew ChooseGraphForm(this);
		this->Hide();
		formo->ShowDialog();
	}
	};
}
