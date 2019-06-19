#include "pch.h"
#include "MyForm.h"



using namespace testApp2;

void testApp2::MyForm::findPorts(void)
{
	array<Object^>^ objectArray = SerialPort::GetPortNames();

	this->COM_Ports->Items->AddRange(objectArray);

}

 TS_GUI::Settings MyForm::getSettings(void)
{
	// clean buffer
	this->serialPort1->DiscardOutBuffer();
	this->serialPort1->DiscardInBuffer();

	const int length = 8;
	TS_GUI::Settings currentSettings;
	String^ configComand = "show config";
	String^ message;
	//Write to serial
	this->serialPort1->WriteLine(configComand);

	try
	{
		for (int i = 0; i < length; i++)
		{
			message = this->serialPort1->ReadLine();
			//maxc
			if (message->Contains("maxc"))
			{
				
				this->Max_Current->Text = message->Substring(12, 4);
				this->messageIn->Text = message->Substring(12, 4);
				this->numericUpDown1->Value = Convert::ToInt32(message->Substring(12, 4));
				currentSettings.maxVoltage = Convert::ToInt32(message->Substring(12, 4));
			} 

			//maxv
			if (message->Contains("maxv"))
			{
				this->Max_Voltage->Text = message->Substring(12, 4);
				currentSettings.maxCurrent = Convert::ToInt32(message->Substring(12, 4));
			}

	
		}
		
	}
	catch (TimeoutException^)
	{
		this->messageIn->Text = "TimeoutException";
	}
	catch (ArgumentOutOfRangeException^)
	{
		this->messageIn->Text = "ArgumentOutOfRangeException";
	}
	catch (FormatException^)
	{
		this->messageIn->Text = "FormatException";
	}


	return currentSettings;

}

		

	Void MyForm::Init_Port_Button_Click(Object^ sender, EventArgs^ e) {

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
			//catch (UnauthorizedAccessException^) {
			//catch (...) {
			catch (IO::IOException^) {
				// getting weird Exception when connecting to some com ports.
				this->messageIn->Text = "Exception thrown";
			}
			catch (UnauthorizedAccessException^)
			{
				this->messageIn->Text = "UnauthorizedAccessException";
			}
		
		}
	}
	Void MyForm::Close_Port_ButtonClick(Object^ sender, EventArgs^ e) {

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
	Void MyForm::Read_Button_Click(Object^ sender, EventArgs^ e) {

		try {
			this->messageIn->Text = this->serialPort1->ReadLine();
		}
		catch (TimeoutException^) {
			this->messageIn->Text = "Timeout Exception";
		}


	}
	Void MyForm::Send_Button_Click(Object^ sender, EventArgs^ e) {

		///String^ name = this->serialPort1->PortName;
		//grab test and add it to send buffer
		String^ message = this->messageOut->Text;
		//Write to serial
		this->serialPort1->WriteLine(message);


	}

Void MyForm::Apply_settings_Click(Object^ sender, EventArgs^ e) {
	this->serialPort1->DiscardOutBuffer();
	this->serialPort1->DiscardInBuffer();

	const int length = 4;
	String^ message;
		// set maxc
	for (int i = 0; i < length; i++)
	{
		String^ message = "set maxc " + this->Max_Current->Text;
		this->serialPort1->WriteLine(message);


		
		//set maxv
	
		message = "set maxv " + this->Max_Voltage->Text;
		this->serialPort1->WriteLine(message);
	}

}

Void testApp2::MyForm::Get_Settings_Click(Object^ sender, EventArgs^ e)
{
	TS_GUI::Settings MySettings = getSettings();
	//this->Max_Voltage->Text = Convert::ToString(MySettings.maxVoltage);
//	this->Max_Current->Text = Convert::ToString(MySettings.maxCurrent);
	//return System::Void();
}

