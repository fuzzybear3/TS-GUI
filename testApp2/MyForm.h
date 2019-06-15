#pragma once

namespace testApp2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			findPorts();

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::ComboBox^ COM_Ports;
	private: System::Windows::Forms::ComboBox^ Baud_Rate;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ Init_Port;

	private: System::Windows::Forms::Button^ Close_Port;

	private: System::Windows::Forms::TextBox^ messageIn;
	private: System::Windows::Forms::TextBox^ messageOut;
	private: System::Windows::Forms::Button^ Send_Button;
	private: System::Windows::Forms::Button^ Read_Button;







	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label3;
	private: System::ComponentModel::IContainer^ components;
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
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->COM_Ports = (gcnew System::Windows::Forms::ComboBox());
			this->Baud_Rate = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Init_Port = (gcnew System::Windows::Forms::Button());
			this->Close_Port = (gcnew System::Windows::Forms::Button());
			this->messageIn = (gcnew System::Windows::Forms::TextBox());
			this->messageOut = (gcnew System::Windows::Forms::TextBox());
			this->Send_Button = (gcnew System::Windows::Forms::Button());
			this->Read_Button = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox1->Location = System::Drawing::Point(177, 41);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(163, 29);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"Steven\'s test app";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(465, 41);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(144, 55);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Reset Text Box";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(393, 149);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 17);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::CheckBox1_CheckedChanged);
			// 
			// COM_Ports
			// 
			this->COM_Ports->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->COM_Ports->FormattingEnabled = true;
			this->COM_Ports->Location = System::Drawing::Point(696, 59);
			this->COM_Ports->Name = L"COM_Ports";
			this->COM_Ports->Size = System::Drawing::Size(121, 21);
			this->COM_Ports->TabIndex = 3;
			this->COM_Ports->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ComboBox1_SelectedIndexChanged);
			// 
			// Baud_Rate
			// 
			this->Baud_Rate->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Baud_Rate->FormattingEnabled = true;
			this->Baud_Rate->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"9600", L"115200" });
			this->Baud_Rate->Location = System::Drawing::Point(696, 130);
			this->Baud_Rate->Name = L"Baud_Rate";
			this->Baud_Rate->Size = System::Drawing::Size(121, 21);
			this->Baud_Rate->TabIndex = 4;
			this->Baud_Rate->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ComboBox2_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(610, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"COM Ports";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(610, 138);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Baud Rate";
			// 
			// Init_Port
			// 
			this->Init_Port->Location = System::Drawing::Point(696, 198);
			this->Init_Port->Name = L"Init_Port";
			this->Init_Port->Size = System::Drawing::Size(86, 46);
			this->Init_Port->TabIndex = 7;
			this->Init_Port->Text = L"init port";
			this->Init_Port->UseVisualStyleBackColor = true;
			this->Init_Port->Click += gcnew System::EventHandler(this, &MyForm::Init_Port_Button_Click);
			// 
			// Close_Port
			// 
			this->Close_Port->Enabled = false;
			this->Close_Port->Location = System::Drawing::Point(696, 276);
			this->Close_Port->Name = L"Close_Port";
			this->Close_Port->Size = System::Drawing::Size(86, 46);
			this->Close_Port->TabIndex = 8;
			this->Close_Port->Text = L"close port";
			this->Close_Port->UseVisualStyleBackColor = true;
			this->Close_Port->Click += gcnew System::EventHandler(this, &MyForm::Close_Port_ButtonClick);
			// 
			// messageIn
			// 
			this->messageIn->Enabled = false;
			this->messageIn->Location = System::Drawing::Point(49, 170);
			this->messageIn->Name = L"messageIn";
			this->messageIn->ReadOnly = true;
			this->messageIn->Size = System::Drawing::Size(185, 20);
			this->messageIn->TabIndex = 9;
			this->messageIn->Text = L"reciveed here";
			this->messageIn->TextChanged += gcnew System::EventHandler(this, &MyForm::MessageIn_TextChanged);
			// 
			// messageOut
			// 
			this->messageOut->Enabled = false;
			this->messageOut->Location = System::Drawing::Point(49, 264);
			this->messageOut->Name = L"messageOut";
			this->messageOut->Size = System::Drawing::Size(185, 20);
			this->messageOut->TabIndex = 10;
			this->messageOut->Text = L"Enter here";
			this->messageOut->TextChanged += gcnew System::EventHandler(this, &MyForm::messageOut_TextChanged);
			// 
			// Send_Button
			// 
			this->Send_Button->Enabled = false;
			this->Send_Button->Location = System::Drawing::Point(49, 220);
			this->Send_Button->Name = L"Send_Button";
			this->Send_Button->Size = System::Drawing::Size(75, 23);
			this->Send_Button->TabIndex = 11;
			this->Send_Button->Text = L"Send";
			this->Send_Button->UseVisualStyleBackColor = true;
			this->Send_Button->Click += gcnew System::EventHandler(this, &MyForm::Send_Button_Click);
			// 
			// Read_Button
			// 
			this->Read_Button->Enabled = false;
			this->Read_Button->Location = System::Drawing::Point(159, 219);
			this->Read_Button->Name = L"Read_Button";
			this->Read_Button->Size = System::Drawing::Size(75, 23);
			this->Read_Button->TabIndex = 12;
			this->Read_Button->Text = L"Read";
			this->Read_Button->UseVisualStyleBackColor = true;
			this->Read_Button->Click += gcnew System::EventHandler(this, &MyForm::Read_Button_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(49, 103);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(100, 34);
			this->progressBar1->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(49, 67);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Port Status";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(923, 361);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->Read_Button);
			this->Controls->Add(this->Send_Button);
			this->Controls->Add(this->messageOut);
			this->Controls->Add(this->messageIn);
			this->Controls->Add(this->Close_Port);
			this->Controls->Add(this->Init_Port);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Baud_Rate);
			this->Controls->Add(this->COM_Ports);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"Terminal GUI";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void findPorts(void)
	{
		array<Object^>^ objectArray = SerialPort::GetPortNames();

		this->COM_Ports->Items->AddRange(objectArray);

	}


	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {

		this->textBox1->Text = L"Steven\'s test app";
	}
	private: System::Void CheckBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ComboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}



	private: System::Void ComboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
		private: System::Void messageOut_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void Read_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void Send_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		 }
		private: System::Void Init_Port_Button_Click(System::Object^ sender, System::EventArgs^ e) {

			this->messageOut->Text = String::Empty;
			this->messageIn->Text = String::Empty;
			if (this->COM_Ports->Text == String::Empty || this->Baud_Rate->Text == String::Empty)
			{
				this->messageIn->Text = "Please Slelect Port Settings";
			}
			else
			{
		
				try {

					if (!this->serialPort1->IsOpen)
					{
						this->serialPort1->PortName = this->COM_Ports->Text;
						this->serialPort1->BaudRate = Int32::Parse(this->Baud_Rate->Text);

						this->messageOut->Text = "Enter Message Here";

						this->serialPort1->Open();
						this->progressBar1->Value = 100;

						//enable init button
						this->Send_Button->Enabled = true;
						this->Read_Button->Enabled = true;
						this->Close_Port->Enabled = true;
						this->messageOut->Enabled = true;

						//disble buttons
						this->Init_Port->Enabled = false;
					}
					else {
						this->messageIn->Text = "port isn't open";
					}
		

				}
				catch (UnauthorizedAccessException^) {
					this->messageIn->Text = "UnauthorizedAccess";
				}
			}
		}
		private: System::Void MessageIn_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void Close_Port_ButtonClick(System::Object^ sender, System::EventArgs^ e) {

			this->serialPort1->Close();

			this->progressBar1->Value = 0;
			//enable init button
			this->Init_Port->Enabled = true;
			//disble buttons
			this->Send_Button->Enabled = false;
			this->Read_Button->Enabled = false;
			this->Close_Port->Enabled = false;
			this->messageOut->Enabled = false;
		}

	};
}
