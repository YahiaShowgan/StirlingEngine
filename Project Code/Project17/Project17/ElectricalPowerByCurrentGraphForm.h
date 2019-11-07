#pragma once
#include "ElectricalPowerByCurrentOpenGL.h"
namespace OpenGL_on_a_Windows_Form 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ElectricalPowerByCurrentOpenGLForm;

	/// <summary>
	/// Summary for ElectricalPowerByCurrentGraphForm
	/// </summary>
	public ref class ElectricalPowerByCurrentGraphForm : public System::Windows::Forms::Form
	{
	public:
		ElectricalPowerByCurrentGraphForm(Form^ prevForm)
		{
			this->prevForm = prevForm;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			OpenGL = gcnew ElectricalPowerByCurrentOpenGLForm::COpenGL(this, this->Width, this->Height - 100);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ElectricalPowerByCurrentGraphForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  timer1;
	protected:
		Form^ prevForm;
	private: System::Windows::Forms::Button^  backButton;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		ElectricalPowerByCurrentOpenGLForm::COpenGL ^ OpenGL;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &ElectricalPowerByCurrentGraphForm::timer1_Tick);
			// 
			// backButton
			// 
			this->backButton->Location = System::Drawing::Point(61, 425);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(75, 23);
			this->backButton->TabIndex = 0;
			this->backButton->Text = L"Back";
			this->backButton->UseVisualStyleBackColor = true;
			this->backButton->Click += gcnew System::EventHandler(this, &ElectricalPowerByCurrentGraphForm::backButton_Click);
			// 
			// ElectricalPowerByCurrentGraphForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(822, 481);
			this->Controls->Add(this->backButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"ElectricalPowerByCurrentGraphForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Electrical Power by Current Graph";
			this->Load += gcnew System::EventHandler(this, &ElectricalPowerByCurrentGraphForm::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		UNREFERENCED_PARAMETER(sender);
		UNREFERENCED_PARAMETER(e);
		OpenGL->Render();
		OpenGL->SwapOpenGLBuffers();
	}
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
	{

	}
	private: System::Void backButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		prevForm->Show();
		OpenGL->DestroyHandle();
		OpenGL->~COpenGL();
		this->Close();
	}
	};
}

