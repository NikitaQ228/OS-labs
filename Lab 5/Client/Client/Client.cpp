#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	HANDLE pipe;
	bool barber;
	DWORD dwRead;
	DWORD dwWritten;
	char buf[512];

	try {
		pipe = CreateFile(TEXT("\\\\.\\pipe\\MyPipe"), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);;
		if (pipe == INVALID_HANDLE_VALUE) 
			throw "Не удалось подключиться к каналу.\n";

		if (!ReadFile(pipe, &barber, sizeof(barber), &dwRead, NULL))
			throw "Ошибка чтения из канала\n";
		if (!ReadFile(pipe, buf, 512, &dwRead, NULL))
			throw "Ошибка чтения из канала\n";
		cout << "Вы встали в очередь: " << buf << endl;

		if (!ReadFile(pipe, buf, 512, &dwRead, NULL))
			throw "Ошибка чтения из канала\n";
		cout << "Ваш номер: " << buf << endl;

		cout << "Здраствуйте, господин цирюльник!" << endl;
		if (!ReadFile(pipe, buf, 512, &dwRead, NULL))
			throw "Ошибка чтения из канала\n";
		cout << buf << endl;

		cout << "О, как чудесно! Сердцем и душой я вверяю ваши умелые руки." << endl;

		if (!ReadFile(pipe, buf, 512, &dwRead, NULL))
			throw "Ошибка чтения из канала\n";
		cout << buf << endl;
	}
	catch (const char* error_message) {
		cout << error_message;
	}
	
	CloseHandle(pipe);
	system("pause");
	return 0;
}