#pragma once

#include <iostream>
#include <Windows.h>
#include <string>

value struct Client {
	HANDLE pipe;
	int client_id;

	Client(HANDLE pipe, int client_id) : pipe(pipe), client_id(client_id) {}
};

namespace Server5 {

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

	private: HANDLE mutexBarber;
	private: HANDLE mutexBrother;
	private: HANDLE eventRelaxBarber;
	private: HANDLE eventRelaxBrother;
	private: int customers = 0;
	private: int clientNum = 1;
	private: int served_barber = 0;
	private: int served_brother = 0;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label_barber;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label_brother;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label_count;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label_barber = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label_brother = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label_count = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Ravie", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(207, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(403, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Парикмахерская открыта!";
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->label_barber);
			this->panel1->Location = System::Drawing::Point(58, 197);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(355, 441);
			this->panel1->TabIndex = 1;
			// 
			// label_barber
			// 
			this->label_barber->AutoSize = true;
			this->label_barber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_barber->Location = System::Drawing::Point(1, 0);
			this->label_barber->MinimumSize = System::Drawing::Size(330, 10000);
			this->label_barber->Name = L"label_barber";
			this->label_barber->Size = System::Drawing::Size(330, 10000);
			this->label_barber->TabIndex = 2;
			// 
			// panel2
			// 
			this->panel2->AutoScroll = true;
			this->panel2->Controls->Add(this->label_brother);
			this->panel2->Location = System::Drawing::Point(446, 197);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(349, 441);
			this->panel2->TabIndex = 3;
			// 
			// label_brother
			// 
			this->label_brother->AutoSize = true;
			this->label_brother->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_brother->Location = System::Drawing::Point(-4, 0);
			this->label_brother->MinimumSize = System::Drawing::Size(330, 10000);
			this->label_brother->Name = L"label_brother";
			this->label_brother->Size = System::Drawing::Size(330, 10000);
			this->label_brother->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Playbill", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(165, 141);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(154, 28);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Парикмахер";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Playbill", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(527, 141);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(159, 28);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Брат мясник";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Ravie", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(299, 76);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(153, 38);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Очередь:";
			// 
			// label_count
			// 
			this->label_count->AutoSize = true;
			this->label_count->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_count->Location = System::Drawing::Point(476, 82);
			this->label_count->Name = L"label_count";
			this->label_count->Size = System::Drawing::Size(31, 32);
			this->label_count->TabIndex = 7;
			this->label_count->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(183)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->ClientSize = System::Drawing::Size(858, 692);
			this->Controls->Add(this->label_count);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"BarberShop";
			this->Activated += gcnew System::EventHandler(this, &MyForm::MyForm_Activated);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MyForm_Activated(System::Object^ sender, System::EventArgs^ e) {
	System::Threading::Thread^ readThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &MyForm::ReadFromPipe));
	readThread->Start();
}

	   void ReadFromPipe() {
		   DWORD cbWritten;
		   DWORD cbRead;
		   char buf[512] = " ";

		   mutexBrother = CreateMutex(NULL, 0, NULL);
		   mutexBarber = CreateMutex(NULL, 0, NULL);

		   eventRelaxBrother = CreateEvent(NULL, TRUE, TRUE, NULL);
		   eventRelaxBarber = CreateEvent(NULL, TRUE, TRUE, NULL);

		   while (true) {
			   HANDLE pipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\MyPipe"), PIPE_ACCESS_DUPLEX,
				   PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, PIPE_UNLIMITED_INSTANCES,
				   512, 512, 5000, NULL);

			   if (pipe == INVALID_HANDLE_VALUE) {
				   return;
			   }

			   ConnectNamedPipe(pipe, NULL);

			   label_count->Text = System::Convert::ToString(++customers);

			   _itoa_s(customers, buf, 10);
			   if (!WriteFile(pipe, buf, sizeof(buf), &cbWritten, NULL)) {
				   MessageBox::Show(this, "Ошибка записи в канал!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }

			   _itoa_s(clientNum, buf, 10);
			   if (!WriteFile(pipe, buf, sizeof(buf), &cbWritten, NULL)) {
				   MessageBox::Show(this, "Ошибка записи в канал!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }

			   Client cl(pipe, clientNum++);
			   HANDLE thread;
			   if (customers > 2 && clientNum % 2 == 0) {
				   System::Threading::Thread^ readThread = gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(this, &MyForm::workerBrother));
				   readThread->Start(cl);
			   }
			   else {
				   System::Threading::Thread^ readThread = gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(this, &MyForm::workerBarber));
				   readThread->Start(cl);
			   }
		   }

		   CloseHandle(mutexBrother);
		   CloseHandle(mutexBarber);
	   }

	   void workerBarber(Object^ parameter) {
		   Client^ client = safe_cast<Client^>(parameter);
		   HANDLE pipe = client->pipe;
		   int client_id = client->client_id;
		   DWORD dwWritten, dwWaitResult;

		   label_barber->Text += "Добро пожаловать, процесс ";
		   label_barber->Text += System::Convert::ToString(client_id); 
		   label_barber->Text += "\n";

		   WaitForSingleObject(eventRelaxBarber, INFINITE);
		   WaitForSingleObject(mutexBarber, INFINITE);
		   bool barber = true;
		   if (!WriteFile(pipe, &barber, sizeof(barber), &dwWritten, NULL)) {
			   label_barber->Text += "Клиент номер ";
			   label_barber->Text += System::Convert::ToString(client_id);
			   label_barber->Text += " не выстоял в очереди =(\n";
			   disConnect(pipe, true);
		   }
		   if (!WriteFile(pipe, "Здраствуйте! Сегодня именно я, парикмахер этого знатного заведения, возьмусь за ваше прекрасное волосатое убранство.", 216, &dwWritten, NULL)) {
			   label_barber->Text += "Клиент номер ";
			   label_barber->Text += System::Convert::ToString(client_id);
			   label_barber->Text += " не выстоял в очереди =(\n";
			   disConnect(pipe, true);
		   }
		   label_barber->Text += "Начинает стричь клиента ";
		   label_barber->Text += System::Convert::ToString(client_id);
		   label_barber->Text += "\n";
		   Sleep(8000);
		   if (!WriteFile(pipe, "Всего вам доброго!", 34, &dwWritten, NULL)) {
			   label_barber->Text += "Клиент номер ";
			   label_barber->Text += System::Convert::ToString(client_id);
			   label_barber->Text += " внезапно ушёл =(\n";
			   disConnect(pipe, true);
		   }
		   label_barber->Text += "Закончил стричь клиента ";
		   label_barber->Text += System::Convert::ToString(client_id);
		   label_barber->Text += "\n";
		   label_count->Text = System::Convert::ToString(--customers);
		   if (++served_barber % 4 == 0) {
			   ResetEvent(eventRelaxBarber);
			   label_barber->Text += "Отдыхает...\n";
			   Sleep(10000);
			   label_barber->Text += "Закончил отдыхать\n";
			   SetEvent(eventRelaxBarber);
		   }
		   ReleaseMutex(mutexBarber);
		   CloseHandle(pipe);
	   }

	   void workerBrother(Object^ parameter) {
		   Client^ client = safe_cast<Client^>(parameter);
		   HANDLE pipe = client->pipe;
		   int client_id = client->client_id;
		   DWORD dwWritten, dwWaitResult;

		   //UpdateLabelBarber("Добро пожаловать, процесс ");
		   label_brother->Text += "Добро пожаловать, процесс ";
		   label_brother->Text += System::Convert::ToString(client_id);
		   label_brother->Text += "\n";

		   WaitForSingleObject(eventRelaxBrother, INFINITE);
		   WaitForSingleObject(mutexBrother, INFINITE);
		   bool barber = false;
		   if (!WriteFile(pipe, &barber, sizeof(barber), &dwWritten, NULL)) {
			   label_brother->Text += "Клиент номер ";
			   label_brother->Text += System::Convert::ToString(client_id);
			   label_brother->Text += " не выстоял в очереди =(\n";
			   disConnect(pipe, false);
		   }
		   if (!WriteFile(pipe, "Здраствуйте! Сегодня именно я, брат мясник парикмахера, возьмусь за ваше прекрасное волосатое убранство.", 193, &dwWritten, NULL)) {
			   label_brother->Text += "Клиент номер ";
			   label_brother->Text += System::Convert::ToString(client_id);
			   label_brother->Text += " не выстоял в очереди =(\n";
			   disConnect(pipe, false);
		   }
		   label_brother->Text += "Начинает стричь клиента ";
		   label_brother->Text += System::Convert::ToString(client_id);
		   label_brother->Text += "\n";
		   Sleep(8000);
		   if (!WriteFile(pipe, "Всего вам доброго!", 34, &dwWritten, NULL)) {
			   label_brother->Text += "Клиент номер ";
			   label_brother->Text += System::Convert::ToString(client_id);
			   label_brother->Text += " внезапно ушёл =(\n";
			   disConnect(pipe, false);
		   }
		   label_brother->Text += "Закончил стричь клиента ";
		   label_brother->Text += System::Convert::ToString(client_id);
		   label_brother->Text += "\n";
		   label_count->Text = System::Convert::ToString(--customers);
		   if (++served_barber % 4 == 0) {
			   ResetEvent(eventRelaxBrother);
			   label_brother->Text += "Отдыхает...\n";
			   Sleep(10000);
			   label_brother->Text += "Закончил отдыхать\n";
			   SetEvent(eventRelaxBrother);
		   }
		   ReleaseMutex(mutexBrother);
		   CloseHandle(pipe);
	   }

	   void UpdateLabelBarber(String^ text) {
		   label_barber->Text += text;
	   }

	   void disConnect(HANDLE pipe, bool barber) {
		   label_count->Text = System::Convert::ToString(--customers);
		   if (barber) ReleaseMutex(mutexBrother);
		   else ReleaseMutex(mutexBarber);
		   CloseHandle(pipe);
	   }
};
}
