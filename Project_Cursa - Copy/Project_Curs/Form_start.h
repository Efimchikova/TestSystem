#pragma once
#include <iostream>
#include "Form1.h"
#include "Form_Decode.h"
namespace Project_Curs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form_start
	/// </summary>
	public ref class Form_start : public System::Windows::Forms::Form
	{
	public:
		std::string sys2str(String ^str)
		{
			std::string s = "";
			for (int i = 0; i<str->Length; i++)
				s += str[i];
			return s;

		}
		Form_start(void)
		{
			InitializeComponent();
			System::IO::StreamReader^ sr = gcnew System::IO::StreamReader("data.bin");
			System::Collections::ArrayList^ list = gcnew  System::Collections::ArrayList();
			while (!sr->EndOfStream)
			{
				File^ file = gcnew File();
				file->nameTest = sr->ReadLine();
				file->locationFileQuestion = sr->ReadLine();
				file->locationFileVariable = sr->ReadLine();
				file->locationFileAnswer = sr->ReadLine();
				list->Add(file);
			}
			sr->Close();
			listBox1->DataSource = list;
			
		}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form_start()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button_decode;
	private: System::Windows::Forms::Button^  button_choseTest;

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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button_decode = (gcnew System::Windows::Forms::Button());
			this->button_choseTest = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(12, 2);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(213, 276);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form_start::listBox1_SelectedIndexChanged);
			this->listBox1->DoubleClick += gcnew System::EventHandler(this, &Form_start::listBox1_DoubleClick);
			// 
			// button_decode
			// 
			this->button_decode->Location = System::Drawing::Point(231, 2);
			this->button_decode->Name = L"button_decode";
			this->button_decode->Size = System::Drawing::Size(99, 36);
			this->button_decode->TabIndex = 1;
			this->button_decode->Text = L"Decode";
			this->button_decode->UseVisualStyleBackColor = true;
			this->button_decode->Click += gcnew System::EventHandler(this, &Form_start::button1_Click);
			// 
			// button_choseTest
			// 
			this->button_choseTest->Location = System::Drawing::Point(231, 44);
			this->button_choseTest->Name = L"button_choseTest";
			this->button_choseTest->Size = System::Drawing::Size(99, 43);
			this->button_choseTest->TabIndex = 2;
			this->button_choseTest->Text = L"Chose test";
			this->button_choseTest->UseVisualStyleBackColor = true;
			this->button_choseTest->Click += gcnew System::EventHandler(this, &Form_start::button_choseTest_Click);
			// 
			// Form_start
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(342, 290);
			this->Controls->Add(this->button_choseTest);
			this->Controls->Add(this->button_decode);
			this->Controls->Add(this->listBox1);
			this->Name = L"Form_start";
			this->Text = L"Form_start";
			this->Load += gcnew System::EventHandler(this, &Form_start::Form_start_Load);
			this->ResumeLayout(false);

		}
		ref struct File
		{
			System::String^ nameTest;
			System::String^ locationFileQuestion;
			System::String^ locationFileVariable;
			System::String^ locationFileAnswer;
			
			

			virtual System::String^ ToString() override{ return nameTest; }
		};
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {


			 }
			 
	private: System::Void Form_start_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 
			 }
	private: System::Void listBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) 
			{
					 File^ selected=(File^)listBox1->SelectedItem;
				 
					 Form1^ form = gcnew Form1(sys2str(selected->locationFileQuestion), sys2str(selected->locationFileVariable),
						 sys2str(selected->locationFileAnswer));
					 this->Visible = false;
					 try
					 {
						 form->ShowDialog();
					 }
					 catch (Exception^ exa)
					 {
						 MessageBox::Show(exa->Message);
					 }
					 catch (exception e)
					 {
						 MessageBox::Show(gcnew String(e.what()));
					 }
					 this->Visible = true;
				 

			}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
				 Form_Decode form;
				 try
				 {
					 form.ShowDialog();
					 if (form.fileInput != "" && form.fileOutput != "")
					 {
						 Decoder* d = new PrimitiveDecoder();
						 d->Encrypt_File(sys2str(form.fileInput),
							 sys2str(form.fileOutput), 5);
						 delete d;
						 MessageBox::Show("Decoded! :)");
					 }
				 }
				 catch (Exception^ exa)
				 {
					// MessageBox::Show(exa->Message);
				 }
	}
private: System::Void button_choseTest_Click(System::Object^  sender, System::EventArgs^  e) {
			 listBox1_DoubleClick(sender,e);
	}
};
}
