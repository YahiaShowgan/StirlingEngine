#pragma once
#include "PerformanceGraphForm.h"
#include "ElectricalPowerByCurrentGraphForm.h"
namespace Project17 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Windows::Forms;
	using namespace OpenGL_on_a_Windows_Form;

	/// <summary>
	/// Summary for ChooseGraphForm
	/// </summary>
	public ref class ChooseGraphForm : public System::Windows::Forms::Form
	{
	public:
		ChooseGraphForm(Form^ prevForm)
		{
			this->prevForm = prevForm;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ChooseGraphForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
		Form^ prevForm;
	private: System::Windows::Forms::Button^  enginePerformanceButton;
	protected:

	private: System::Windows::Forms::Button^  backButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChooseGraphForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->enginePerformanceButton = (gcnew System::Windows::Forms::Button());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(468, 335);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"PE(I)";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ChooseGraphForm::button1_Click);
			// 
			// enginePerformanceButton
			// 
			this->enginePerformanceButton->Location = System::Drawing::Point(83, 335);
			this->enginePerformanceButton->Name = L"enginePerformanceButton";
			this->enginePerformanceButton->Size = System::Drawing::Size(126, 23);
			this->enginePerformanceButton->TabIndex = 1;
			this->enginePerformanceButton->Text = L"Engine Performance";
			this->enginePerformanceButton->UseVisualStyleBackColor = true;
			this->enginePerformanceButton->Click += gcnew System::EventHandler(this, &ChooseGraphForm::enginePerformanceButton_Click);
			// 
			// backButton
			// 
			this->backButton->Location = System::Drawing::Point(83, 382);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(75, 23);
			this->backButton->TabIndex = 2;
			this->backButton->Text = L"Back";
			this->backButton->UseVisualStyleBackColor = true;
			this->backButton->Click += gcnew System::EventHandler(this, &ChooseGraphForm::backButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(231, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(225, 33);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Choose Graph to Display";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(8, 100);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(316, 229);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &ChooseGraphForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(344, 100);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(320, 229);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// ChooseGraphForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(677, 425);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->enginePerformanceButton);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ChooseGraphForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Graphs";
			this->Load += gcnew System::EventHandler(this, &ChooseGraphForm::ChooseGraphForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ChooseGraphForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void backButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		prevForm->Show();
		this->Close();
	}
	private: System::Void enginePerformanceButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		PerformanceGraphForm^ form1 = gcnew PerformanceGraphForm(this);
		this->Hide();
		form1->ShowDialog();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		ElectricalPowerByCurrentGraphForm^ form1 = gcnew ElectricalPowerByCurrentGraphForm(this);
		this->Hide();
		form1->ShowDialog();
	}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
