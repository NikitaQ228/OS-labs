#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>

namespace lab6client {

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
			CloseHandle(hPipe);
		}

	private: HANDLE hPipe;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label_count;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::RichTextBox^ richTextBox1;

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
			this->label_count = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Ravie", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(100, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(318, 38);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Добро пожаловать!";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Ravie", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(29, 146);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(198, 38);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Ваш номер:";
			// 
			// label_count
			// 
			this->label_count->AutoSize = true;
			this->label_count->Font = (gcnew System::Drawing::Font(L"Arial Black", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_count->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label_count->Location = System::Drawing::Point(270, 146);
			this->label_count->Name = L"label_count";
			this->label_count->Size = System::Drawing::Size(36, 40);
			this->label_count->TabIndex = 12;
			this->label_count->Text = L"0";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Lime;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(36, 81);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(443, 44);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Подключиться";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->richTextBox1);
			this->panel1->Location = System::Drawing::Point(70, 206);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(369, 516);
			this->panel1->TabIndex = 14;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)));
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->ForeColor = System::Drawing::Color::White;
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(340, 12500);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = L"";
			this->richTextBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::richTextBox1_KeyPress_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)));
			this->ClientSize = System::Drawing::Size(520, 776);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label_count);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"EchoPrint";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->button1->Text == "Отключиться") {
			disConect();
			return;
		}
		creatPipe();
	}
		   void creatPipe() {
			   wchar_t buffer;
			   DWORD dwRead;
			   int count;

			   richTextBox1->Enabled = true;

			   hPipe = CreateFile(TEXT("\\\\.\\pipe\\EchoNamedPipe"), PIPE_ACCESS_DUPLEX,
				   0, NULL, OPEN_EXISTING, 0, NULL);

			   if (hPipe == INVALID_HANDLE_VALUE) {
				   MessageBox::Show(this, "Ошибка подключения к каналу!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }

			   button1->Text = "Отключиться";
			   button1->BackColor = Color::Red;

			   if (!ReadFile(hPipe, &count, sizeof(int), &dwRead, NULL)) {
				   MessageBox::Show(this, "Ошибка чтения из канала!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   disConect();
				   return;
			   }

			   label_count->Text = System::Convert::ToString(count);
		   }

	private: System::Void richTextBox1_KeyPress_1(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		DWORD dwWritten;
		wchar_t buffer = e->KeyChar;
		if (!WriteFile(hPipe, &buffer, sizeof(buffer), &dwWritten, NULL) || dwWritten <= 0) {
			MessageBox::Show(this, "Ошибка записи в канал!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			disConect();
		}
	}
		   void disConect() {
			   richTextBox1->Enabled = false;
			   richTextBox1->Clear();
			   label_count->Text = "0";
			   button1->BackColor = Color::Lime;
			   button1->Text = "Подключиться";
			   CloseHandle(hPipe);
		   }
};
}
