#pragma once

#include <iostream>
#include <Windows.h>
#include <thread>

using namespace std;

namespace lab6server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: cli::array<HANDLE>^ hPipe = gcnew cli::array<HANDLE>(3);
	private: int count = 0;
	private: cli::array<bool>^ flag = gcnew cli::array<bool>(3);
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label_count;


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label_client1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label_client2;
	private: System::Windows::Forms::Label^ label_client3;
	private: System::Windows::Forms::Panel^ panel3;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label_count = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label_client1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label_client2 = (gcnew System::Windows::Forms::Label());
			this->label_client3 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Ravie", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(12, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(710, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Текущее количество подключенных клиентов:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Cyan;
			this->label2->Location = System::Drawing::Point(146, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 22);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Клиент 1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::Fuchsia;
			this->label4->Location = System::Drawing::Point(551, 106);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(93, 22);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Клиент 2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::Yellow;
			this->label3->Location = System::Drawing::Point(962, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 22);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Клиент 3";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Cyan;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(94, 153);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(205, 40);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Подключить";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Fuchsia;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(494, 153);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(205, 40);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Подключить";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Yellow;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(903, 153);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(205, 40);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Подключить";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label_count
			// 
			this->label_count->AutoSize = true;
			this->label_count->Font = (gcnew System::Drawing::Font(L"Arial Black", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_count->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label_count->Location = System::Drawing::Point(838, 23);
			this->label_count->Name = L"label_count";
			this->label_count->Size = System::Drawing::Size(36, 40);
			this->label_count->TabIndex = 11;
			this->label_count->Text = L"0";
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->label_client1);
			this->panel1->Location = System::Drawing::Point(34, 213);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(369, 516);
			this->panel1->TabIndex = 12;
			// 
			// label_client1
			// 
			this->label_client1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_client1->ForeColor = System::Drawing::Color::Cyan;
			this->label_client1->Location = System::Drawing::Point(-4, 0);
			this->label_client1->MaximumSize = System::Drawing::Size(350, 1000000);
			this->label_client1->MinimumSize = System::Drawing::Size(340, 400);
			this->label_client1->Name = L"label_client1";
			this->label_client1->Size = System::Drawing::Size(350, 65535);
			this->label_client1->TabIndex = 5;
			// 
			// panel2
			// 
			this->panel2->AutoScroll = true;
			this->panel2->Controls->Add(this->label_client2);
			this->panel2->Location = System::Drawing::Point(437, 213);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(369, 516);
			this->panel2->TabIndex = 13;
			// 
			// label_client2
			// 
			this->label_client2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_client2->ForeColor = System::Drawing::Color::Fuchsia;
			this->label_client2->Location = System::Drawing::Point(-4, 0);
			this->label_client2->MaximumSize = System::Drawing::Size(350, 1000000);
			this->label_client2->MinimumSize = System::Drawing::Size(340, 400);
			this->label_client2->Name = L"label_client2";
			this->label_client2->Size = System::Drawing::Size(349, 65535);
			this->label_client2->TabIndex = 6;
			// 
			// label_client3
			// 
			this->label_client3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_client3->ForeColor = System::Drawing::Color::Yellow;
			this->label_client3->Location = System::Drawing::Point(-4, 0);
			this->label_client3->MaximumSize = System::Drawing::Size(350, 1000000);
			this->label_client3->MinimumSize = System::Drawing::Size(340, 400);
			this->label_client3->Name = L"label_client3";
			this->label_client3->Size = System::Drawing::Size(350, 65535);
			this->label_client3->TabIndex = 15;
			// 
			// panel3
			// 
			this->panel3->AutoScroll = true;
			this->panel3->Controls->Add(this->label_client3);
			this->panel3->Location = System::Drawing::Point(831, 213);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(369, 516);
			this->panel3->TabIndex = 14;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)));
			this->ClientSize = System::Drawing::Size(1240, 761);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label_count);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"EchoPrint";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->button1->Text == "Отключить") {
			flag[0] = false;
			label_client1->Text = "";
			button1->Text = "Подключить";
			return;
		}
		flag[0] = true;
		System::Threading::Thread^ readThread = gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(this, &MyForm::ReadFromPipe));
		readThread->Start(1);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->button2->Text == "Отключить") {
			flag[1] = false;
			label_client2->Text = "";
			button2->Text = "Подключить";
			return;
		}
		flag[1] = true;
		System::Threading::Thread^ readThread = gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(this, &MyForm::ReadFromPipe));
		readThread->Start(2);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->button3->Text == "Отключить") {
			flag[2] = false;
			label_client2->Text = "";
			button2->Text = "Подключить";
			return;
		}
		flag[2] = true;
		System::Threading::Thread^ readThread = gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(this, &MyForm::ReadFromPipe));
		readThread->Start(3);
	}

		   void ReadFromPipe(Object^ parameter) {
			   cli::array<Label^>^ clientLabels = { this->label_client1, this->label_client2, this->label_client3 };
			   cli::array<Button^>^ clientButtons = { this->button1, this->button2, this->button3 };
			   int num = safe_cast<int>(parameter);
			   wchar_t buffer;
			   DWORD dwRead;
			   DWORD dwWritten;

			   hPipe[num - 1] = CreateNamedPipe(TEXT("\\\\.\\pipe\\EchoNamedPipe"), PIPE_ACCESS_DUPLEX,
				   PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
				   PIPE_UNLIMITED_INSTANCES, 0, 0, NMPWAIT_USE_DEFAULT_WAIT, NULL);

			   if (hPipe[num - 1] == INVALID_HANDLE_VALUE) {
				   MessageBox::Show(this, "Ошибка создания канала!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   clientButtons[num - 1]->Text = "Подключить";
				   return;
			   }

			   clientLabels[num - 1]->Text = "Ожидание подключения...";
			   ConnectNamedPipe(hPipe[num - 1], NULL);

			   count++;
			   countClientToLabel();
			   clientLabels[num - 1]->Text = "";
			   clientButtons[num - 1]->Text = "Отключить";

			   if (!WriteFile(hPipe[num - 1], &num, sizeof(int), &dwWritten, NULL)) {
				   MessageBox::Show(this, "Ошибка записи в канал!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   disConect(num);
			   }

			   do {
				   if (!ReadFile(hPipe[num - 1], &buffer, sizeof(buffer), &dwRead, NULL)) {
					   MessageBox::Show(this, "Ошибка чтения из канала!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					   break;
				   }
				   if (buffer == L'\b') {
					   if (!String::IsNullOrEmpty(clientLabels[num - 1]->Text)) {
						   clientLabels[num - 1]->Text = clientLabels[num - 1]->Text->Remove(clientLabels[num - 1]->Text->Length - 1);
					   }
				   }
				   else if (buffer == L'\r') {
					   clientLabels[num - 1]->Text += "\n";
				   }
				   else {
					   clientLabels[num - 1]->Text += buffer.ToString();
				   }
			   } while (flag[num - 1]);

			   disConect(num);
		   }

		   void countClientToLabel() {
			   this->label_count->Text = System::Convert::ToString(this->count);
		   }

		   void disConect(int num) {
			   if (num == 1) {
				   button1->Text = "Подключить";
				   label_client1->Text = "";
			   }
			   if (num == 2) {
				   button2->Text = "Подключить";
				   label_client2->Text = "";
			   }
			   if (num == 3) {
				   button3->Text = "Подключить";
				   label_client3->Text = "";
			   }
			   count--;
			   countClientToLabel();
			   CloseHandle(hPipe[num - 1]);
		   }
private: System::Void MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {

}
};
}
