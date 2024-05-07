#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

struct Client {
	HANDLE pipe;
	int client_id;

	Client(HANDLE pipe, int client_id, bool barber) {
		this->pipe = pipe;
		this->client_id = client_id;
	}
};

HANDLE mutexBarber;
HANDLE mutexBrother;
HANDLE eventRelaxBarber;
HANDLE eventRelaxBrother;

int customers = 0;
int clientNum = 1;
int served_barber = 0;
int served_brother = 0;

DWORD WINAPI workerBarber(LPVOID lpParam) {
	Client* client = (Client*)lpParam;
	HANDLE pipe = client->pipe;
	int client_id = client->client_id;
	DWORD dwWritten, dwWaitResult;

	cout << "Добро пожаловать, процесс " << client_id << endl;

	WaitForSingleObject(eventRelaxBarber, INFINITE);
	WaitForSingleObject(mutexBarber, INFINITE);

	try {
		if (!WriteFile(pipe, "Здраствуйте! Сегодня именно я, парикмахер этого знатного заведения, возьмусь за ваше прекрасное волосатое убранство.", 216, &dwWritten, NULL))
			throw string("Клиент номер " + to_string(client_id) + " не выстоял в очереди =(\n");
		cout << "Парикмахер начинает стричь клиента " << client_id << endl;
		Sleep(8000);
		if (!WriteFile(pipe, "Всего вам доброго!", 34, &dwWritten, NULL))
			throw string("Клиент номер " + to_string(client_id) + " внезапно ушёл =(\n");
		cout << "Парикмахер закончил стричь клиента " << client_id << endl;
		cout << "\t\t\t\t\t\tОчередь:" << --customers << endl;
		if (++served_barber % 4 == 0) {
			ResetEvent(eventRelaxBarber);
			cout << "Парикмахер отдыхает..." << endl;
			Sleep(10000);
			cout << "Парикмахер закончил отдыхать" << endl;
			SetEvent(eventRelaxBarber);
		}
	}
	catch (const string& error_message) {
		cout << error_message;
		cout << "\t\t\t\t\t\tОчередь:" << --customers << endl;
	}

	if (!ReleaseMutex(mutexBarber)) {
		cout << "Ошибка освобождения мьютекса" << endl;
		ExitThread(1);
	}
	CloseHandle(pipe);
	ExitThread(0);
}

DWORD WINAPI workerBrother(LPVOID lpParam) {
	Client* client = (Client*)lpParam;
	HANDLE pipe = client->pipe;
	int client_id = client->client_id;
	DWORD dwWritten, dwWaitResult;

	cout << "Добро пожаловать, процесс " << client_id << endl;

	WaitForSingleObject(eventRelaxBrother, INFINITE);
	WaitForSingleObject(mutexBrother, INFINITE);

	try {
		if (!WriteFile(pipe, "Здраствуйте! Сегодня именно я, брат мясник парикмахера, возьмусь за ваше прекрасное волосатое убранство.", 193, &dwWritten, NULL))
			throw string("Клиент номер " + to_string(client_id) + " не выстоял в очереди =(\n");
		cout << "Брат начинает стричь клиента " << client_id << endl;
		Sleep(8000);
		if (!WriteFile(pipe, "Всего вам доброго!", 34, &dwWritten, NULL))
			throw string("Клиент номер " + to_string(client_id) + " внезапно ушёл =(\n");
		cout << "Брат закончил стричь клиента " << client_id << endl;
		cout << "\t\t\t\t\t\tОчередь:" << --customers << endl;
		if (++served_brother % 4 == 0) {
			ResetEvent(eventRelaxBrother);
			cout << "Брат мясник отдыхает..." << endl;
			Sleep(10000);
			cout << "Брат мясник закончил отдыхать" << endl;
			SetEvent(eventRelaxBrother);
		}
	}
	catch (const string& error_message) {
		cout << error_message;
		cout << "\t\t\t\t\t\tОчередь:" << --customers << endl;
	}

	if (!ReleaseMutex(mutexBrother)) {
		cout << "Ошибка освобождения мьютекса" << endl;
		ExitThread(1);
	}
	CloseHandle(pipe);
	ExitThread(0);
}

int main() {
	setlocale(LC_ALL, "Russian");
	DWORD cbWritten;
	DWORD cbRead;
	char buf[512] = " ";

	mutexBrother = CreateMutex(NULL, 0, NULL);
	mutexBarber = CreateMutex(NULL, 0, NULL);

	eventRelaxBrother = CreateEvent(NULL, TRUE, TRUE, NULL);
	eventRelaxBarber = CreateEvent(NULL, TRUE, TRUE, NULL);

	cout << "Парикмахерская открылась!" << endl;

	while (true) {
		HANDLE pipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\MyPipe"), PIPE_ACCESS_DUPLEX, 
			PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, PIPE_UNLIMITED_INSTANCES, 
			512, 512, 5000, NULL);

		if (pipe == INVALID_HANDLE_VALUE) {
			cerr << "Не удалось создать именованный канал. Код ошибки: " << GetLastError() << endl;
			return 1;
		}

		ConnectNamedPipe(pipe, NULL);

		cout << "\t\t\t\t\t\tОчередь:" << ++customers << endl;

		_itoa_s(customers, buf, 10);
		if (!WriteFile(pipe, buf, sizeof(buf), &cbWritten, NULL)) {
			cerr << "Ошибка при передачи данных на сервере!" << endl;
			return 0;
		}

		_itoa_s(clientNum, buf, 10);
		if (!WriteFile(pipe, buf, sizeof(buf), &cbWritten, NULL)) {
			cerr << "Ошибка при передачи данных на сервере!" << endl;
			return 0;
		}

		Client cl(pipe, clientNum++, 1);
		HANDLE thread;
		if (customers > 2 && clientNum % 2 == 0)
			thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)workerBrother, (LPVOID)&cl, 0, NULL);
		else thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)workerBarber, (LPVOID)&cl, 0, NULL);

		if (thread == NULL) {
			cout << "Ошибка при создании потока!" << endl;
			return 0;
		}
	}

	CloseHandle(mutexBrother);
	CloseHandle(mutexBarber);
	cout << "Парикмахерская закрыта! До свидания!" << endl;
	return 0;
}
