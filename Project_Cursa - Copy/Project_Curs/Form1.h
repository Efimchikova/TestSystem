#pragma once
#include "Question.h";
#include "FileOperation.h"
#include "Test.h"
#include "Variable.h"
#include <iostream>
#include "Decoder.h"
namespace Project_Curs {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Test* test;
		int currentQuestion;
		Decoder* decoder;
		String^ answerLocation;
		Form1(std::string LocationQuestion, std::string LocationVariable, std::string ansnwerLocation)
		{
			
			InitializeComponent();
			test = new Test(LocationQuestion, LocationVariable);
			decoder = new PrimitiveDecoder();
			currentQuestion=0;
			this->answerLocation=gcnew String(ansnwerLocation.c_str());
			// constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button_finishTest;
	private: System::Windows::Forms::Label^  label_percent;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button_finishTest = (gcnew System::Windows::Forms::Button());
			this->label_percent = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(198, 351);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(97, 22);
			this->textBox1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(304, 348);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 29);
			this->button1->TabIndex = 3;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(439, 348);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(82, 29);
			this->button2->TabIndex = 4;
			this->button2->Text = L"prev";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(530, 348);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(78, 29);
			this->button3->TabIndex = 5;
			this->button3->Text = L"next";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button_finishTest
			// 
			this->button_finishTest->Location = System::Drawing::Point(620, 348);
			this->button_finishTest->Name = L"button_finishTest";
			this->button_finishTest->Size = System::Drawing::Size(78, 29);
			this->button_finishTest->TabIndex = 6;
			this->button_finishTest->Text = L"end test";
			this->button_finishTest->UseVisualStyleBackColor = true;
			this->button_finishTest->Click += gcnew System::EventHandler(this, &Form1::button_finishTest_Click);
			// 
			// label_percent
			// 
			this->label_percent->AutoSize = true;
			this->label_percent->Location = System::Drawing::Point(704, 348);
			this->label_percent->Name = L"label_percent";
			this->label_percent->Size = System::Drawing::Size(56, 17);
			this->label_percent->TabIndex = 7;
			this->label_percent->Text = L"percent";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(961, 400);
			this->Controls->Add(this->label_percent);
			this->Controls->Add(this->button_finishTest);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void uploadQuestion()
		{
			if(currentQuestion >= test->getSize())
				currentQuestion = 0;
			else if(currentQuestion<0)
				currentQuestion = test->getSize()-1;
			label_percent->Text=gcnew String(test->getUserAnswers().size().ToString()+
				" / "+test->getSize().ToString());

					this->label1->Text=gcnew String(test->getQuestion(currentQuestion).getQuestion().c_str());
					String^ str="";

					Question answers = test->getQuestion(currentQuestion);
					for (int i = 0; i < answers.getAnswers().size(); i++)
					{
						str+= ((wchar_t)('A'+i));
						str+="  ";
						str += gcnew String(answers.getAnswers()[i].c_str());
						str += "\n";
					}
					label2->Text=str;
		}
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
					test->uploadQuestion();
					uploadQuestion();
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if(textBox1->Text->Length==0 || textBox1->Text[0] - 'A'< 0 ||
					 textBox1->Text[0] - 'A' >= test->getQuestion(currentQuestion).getAnswers().size())
				 {
					 MessageBox::Show("Make correct chose");
					 return;
				 }
				 test->setAnswerToQuestion(currentQuestion++,  textBox1->Text[0]);
				 uploadQuestion();
				 //textBox1->Text="";
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 currentQuestion++;
			 uploadQuestion();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 currentQuestion--;
			 uploadQuestion();
		 }
		 private:
			 std::string sys2str(String ^str)
			 {
				 std::string s="";
				 for(int i=0;i<str->Length;i++)
					 s+=str[i];
				 return s;

			 }
private: System::Void button_finishTest_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 for(int i=0;i<test->getSize();i++)
			 {
				if(!test->isGiveAnswer(i))
				{
					currentQuestion=i;
					uploadQuestion();
					MessageBox::Show("Give all answer");
					return;
				}
			 }
			String^ t=gcnew String(FileOperation::computeResult(sys2str(this->answerLocation),decoder,5,test->getUserAnswers(),
				test->getVariables()).output_text.c_str());
			MessageBox::Show(t); 
		 }
};
}
