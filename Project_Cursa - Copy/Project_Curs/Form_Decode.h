#pragma once

namespace Project_Curs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form_Decode
	/// </summary>
	public ref class Form_Decode : public System::Windows::Forms::Form
	{
	public:
		Form_Decode(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form_Decode()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Button^  button_inputFile;
	private: System::Windows::Forms::Button^  button_outputFile;
	private: System::Windows::Forms::Button^  button_Decode;



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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->button_inputFile = (gcnew System::Windows::Forms::Button());
			this->button_outputFile = (gcnew System::Windows::Forms::Button());
			this->button_Decode = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button_inputFile
			// 
			this->button_inputFile->Location = System::Drawing::Point(12, 12);
			this->button_inputFile->Name = L"button_inputFile";
			this->button_inputFile->Size = System::Drawing::Size(272, 50);
			this->button_inputFile->TabIndex = 0;
			this->button_inputFile->Text = L"InputFile";
			this->button_inputFile->UseVisualStyleBackColor = true;
			this->button_inputFile->Click += gcnew System::EventHandler(this, &Form_Decode::button_inputFile_Click);
			// 
			// button_outputFile
			// 
			this->button_outputFile->Location = System::Drawing::Point(12, 74);
			this->button_outputFile->Name = L"button_outputFile";
			this->button_outputFile->Size = System::Drawing::Size(272, 50);
			this->button_outputFile->TabIndex = 1;
			this->button_outputFile->Text = L"Output File";
			this->button_outputFile->UseVisualStyleBackColor = true;
			this->button_outputFile->Click += gcnew System::EventHandler(this, &Form_Decode::button_outputFile_Click);
			// 
			// button_Decode
			// 
			this->button_Decode->Location = System::Drawing::Point(12, 130);
			this->button_Decode->Name = L"button_Decode";
			this->button_Decode->Size = System::Drawing::Size(272, 50);
			this->button_Decode->TabIndex = 2;
			this->button_Decode->Text = L"Decode";
			this->button_Decode->UseVisualStyleBackColor = true;
			this->button_Decode->Click += gcnew System::EventHandler(this, &Form_Decode::button_Decode_Click);
			// 
			// Form_Decode
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 188);
			this->Controls->Add(this->button_Decode);
			this->Controls->Add(this->button_outputFile);
			this->Controls->Add(this->button_inputFile);
			this->Name = L"Form_Decode";
			this->Text = L"Form_Decode";
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		String^ fileOutput;
		String^ fileInput;
	private: System::Void button_inputFile_Click(System::Object^  sender, System::EventArgs^  e) 
	{
				 if (openFileDialog1->ShowDialog().ToString() == "OK")
					 fileInput = openFileDialog1->FileName;
	}

	private: System::Void button_outputFile_Click(System::Object^  sender, System::EventArgs^  e) 
	{
				 if (saveFileDialog1->ShowDialog().ToString() == "OK")
					 fileOutput = saveFileDialog1->FileName;
	}

private: System::Void button_Decode_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}
};
}
