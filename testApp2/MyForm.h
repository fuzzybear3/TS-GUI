#pragma once

#include "Settings_TS.h"


namespace testApp2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
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
	private: System::Windows::Forms::TextBox^ Max_Current;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ Apply_settings;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ Max_Voltage;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Button^ Get_Settings;


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
			this->Max_Current = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Apply_settings = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Max_Voltage = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->Get_Settings = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// serialPort1
			// 
			this->serialPort1->ReadTimeout = 500;
			this->serialPort1->WriteTimeout = 500;
			// 
			// COM_Ports
			// 
			this->COM_Ports->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->COM_Ports->FormattingEnabled = true;
			this->COM_Ports->Location = System::Drawing::Point(906, 90);
			this->COM_Ports->Margin = System::Windows::Forms::Padding(6);
			this->COM_Ports->Name = L"COM_Ports";
			this->COM_Ports->Size = System::Drawing::Size(238, 33);
			this->COM_Ports->TabIndex = 3;
			// 
			// Baud_Rate
			// 
			this->Baud_Rate->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Baud_Rate->FormattingEnabled = true;
			this->Baud_Rate->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"9600", L"115200" });
			this->Baud_Rate->Location = System::Drawing::Point(906, 209);
			this->Baud_Rate->Margin = System::Windows::Forms::Padding(6);
			this->Baud_Rate->Name = L"Baud_Rate";
			this->Baud_Rate->Size = System::Drawing::Size(238, 33);
			this->Baud_Rate->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(734, 106);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 25);
			this->label1->TabIndex = 5;
			this->label1->Text = L"COM Ports";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(738, 212);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 25);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Baud Rate";
			// 
			// Init_Port
			// 
			this->Init_Port->Location = System::Drawing::Point(936, 322);
			this->Init_Port->Margin = System::Windows::Forms::Padding(6);
			this->Init_Port->Name = L"Init_Port";
			this->Init_Port->Size = System::Drawing::Size(172, 88);
			this->Init_Port->TabIndex = 7;
			this->Init_Port->Text = L"init port";
			this->Init_Port->UseVisualStyleBackColor = true;
			this->Init_Port->Click += gcnew System::EventHandler(this, &MyForm::Init_Port_Button_Click);
			// 
			// Close_Port
			// 
			this->Close_Port->Enabled = false;
			this->Close_Port->Location = System::Drawing::Point(936, 462);
			this->Close_Port->Margin = System::Windows::Forms::Padding(6);
			this->Close_Port->Name = L"Close_Port";
			this->Close_Port->Size = System::Drawing::Size(172, 88);
			this->Close_Port->TabIndex = 8;
			this->Close_Port->Text = L"close port";
			this->Close_Port->UseVisualStyleBackColor = true;
			this->Close_Port->Click += gcnew System::EventHandler(this, &MyForm::Close_Port_ButtonClick);
			// 
			// messageIn
			// 
			this->messageIn->Enabled = false;
			this->messageIn->Location = System::Drawing::Point(35, 491);
			this->messageIn->Margin = System::Windows::Forms::Padding(6);
			this->messageIn->Name = L"messageIn";
			this->messageIn->ReadOnly = true;
			this->messageIn->Size = System::Drawing::Size(366, 31);
			this->messageIn->TabIndex = 9;
			this->messageIn->Text = L"reciveed here";
			// 
			// messageOut
			// 
			this->messageOut->Enabled = false;
			this->messageOut->Location = System::Drawing::Point(35, 626);
			this->messageOut->Margin = System::Windows::Forms::Padding(6);
			this->messageOut->Name = L"messageOut";
			this->messageOut->Size = System::Drawing::Size(366, 31);
			this->messageOut->TabIndex = 10;
			// 
			// Send_Button
			// 
			this->Send_Button->Enabled = false;
			this->Send_Button->Location = System::Drawing::Point(35, 552);
			this->Send_Button->Margin = System::Windows::Forms::Padding(6);
			this->Send_Button->Name = L"Send_Button";
			this->Send_Button->Size = System::Drawing::Size(150, 44);
			this->Send_Button->TabIndex = 11;
			this->Send_Button->Text = L"Send";
			this->Send_Button->UseVisualStyleBackColor = true;
			this->Send_Button->Click += gcnew System::EventHandler(this, &MyForm::Send_Button_Click);
			// 
			// Read_Button
			// 
			this->Read_Button->Enabled = false;
			this->Read_Button->Location = System::Drawing::Point(251, 552);
			this->Read_Button->Margin = System::Windows::Forms::Padding(6);
			this->Read_Button->Name = L"Read_Button";
			this->Read_Button->Size = System::Drawing::Size(150, 44);
			this->Read_Button->TabIndex = 12;
			this->Read_Button->Text = L"Read";
			this->Read_Button->UseVisualStyleBackColor = true;
			this->Read_Button->Click += gcnew System::EventHandler(this, &MyForm::Read_Button_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(35, 71);
			this->progressBar1->Margin = System::Windows::Forms::Padding(6);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(200, 65);
			this->progressBar1->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(30, 30);
			this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(118, 25);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Port Status";
			// 
			// Max_Current
			// 
			this->Max_Current->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Max_Current->Location = System::Drawing::Point(525, 99);
			this->Max_Current->MaxLength = 4;
			this->Max_Current->Name = L"Max_Current";
			this->Max_Current->Size = System::Drawing::Size(100, 44);
			this->Max_Current->TabIndex = 15;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(300, 99);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(189, 37);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Set Current:";
			// 
			// Apply_settings
			// 
			this->Apply_settings->Location = System::Drawing::Point(448, 340);
			this->Apply_settings->Name = L"Apply_settings";
			this->Apply_settings->Size = System::Drawing::Size(177, 53);
			this->Apply_settings->TabIndex = 17;
			this->Apply_settings->Text = L"Apply Settings";
			this->Apply_settings->UseVisualStyleBackColor = true;
			this->Apply_settings->Click += gcnew System::EventHandler(this, &MyForm::Apply_settings_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(236, 182);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(253, 37);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Set max voltage:";
			// 
			// Max_Voltage
			// 
			this->Max_Voltage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Max_Voltage->Location = System::Drawing::Point(525, 182);
			this->Max_Voltage->Name = L"Max_Voltage";
			this->Max_Voltage->Size = System::Drawing::Size(100, 44);
			this->Max_Voltage->TabIndex = 19;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->numericUpDown1->Location = System::Drawing::Point(440, 613);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(161, 44);
			this->numericUpDown1->TabIndex = 20;
			// 
			// Get_Settings
			// 
			this->Get_Settings->Location = System::Drawing::Point(206, 340);
			this->Get_Settings->Name = L"Get_Settings";
			this->Get_Settings->Size = System::Drawing::Size(195, 53);
			this->Get_Settings->TabIndex = 21;
			this->Get_Settings->Text = L"Retreve Settings";
			this->Get_Settings->UseVisualStyleBackColor = true;
			this->Get_Settings->Click += gcnew System::EventHandler(this, &MyForm::Get_Settings_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1186, 700);
			this->Controls->Add(this->Get_Settings);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->Max_Voltage);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Apply_settings);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Max_Current);
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
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MyForm";
			this->Text = L"Terminal GUI";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: void findPorts(void);
		private: TS_GUI::Settings getSettings(void);

		private: System::Void Init_Port_Button_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void Close_Port_ButtonClick(System::Object^ sender, System::EventArgs^ e);
		private: System::Void Read_Button_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void Send_Button_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void Apply_settings_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void Get_Settings_Click(System::Object^ sender, System::EventArgs^ e);
};
}
