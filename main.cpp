#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <Windows.h>
#include <string>

using namespace std;

void creator() {
	setlocale(LC_ALL, "Russian");
	string put, format, name, all;
	cout << "Введите путь к месту создания файла: ";
	SetConsoleCP(1251);
	cin >> put;
	cout << "Введите название файла: ";
	cin >> name;
	cout << "Введите формат файла: ";
	cin >> format;
	all = put + "\\" + name + "." + format;
	ofstream test(all);
	if (test.is_open()) {
		cout << "Файл успешно создан!" << endl;
	}
	else {
		cout << "Файл не создан!" << endl;
	}
	test.close();
	SetConsoleCP(866);
}

void eraser(char filename[255]) {
	ofstream eraser(filename);
	if (eraser.is_open()) {
		cout << "Файл успешно очищен!" << endl;
	}
	else {
		cout << "Файл не очищен!" << endl;
	}
	eraser.close();
}

void reader(char filename[255]) {
	setlocale(LC_ALL, "Russian");
	string line;
	ifstream in(filename);
	if (in.is_open()) {
		SetConsoleCP(1251);
		while (getline(in, line)) {
			cout << line << endl;
		}
		SetConsoleCP(866);
		cout << "Программа успешно завершена!" << endl;
	}
	else {
		system("cls");
		cout << "Ошибка, файл не удаётся открыть!" << endl;
	}
	in.close();
}

void writer(char filename[255]) {
	setlocale(LC_ALL, "Russian");
	int strok;
	string enter;
	ofstream out(filename, ios::app);
	cout << "Введите количество строк для ввода: ";
	cin >> strok;
	if (out.is_open()) {
		SetConsoleCP(1251);
		for (int i = 0; i < strok; i++) {
			system("cls");
			cout << "Введите строку: ";
			cin >> enter;
			out << enter << endl;
		}
		SetConsoleCP(866);
		cout << "Программа успешно завершена!" << endl;
	}
	else {
		system("cls");
		cout << "Ошибка, файл не удаётся открыть!" << endl;
	}
	out.close();
}

void deleter(string filename) {
	remove(filename.c_str());
	ifstream test1(filename);
	if (test1.is_open()) {
		cout << "Файл не удалён!" << endl;
	}
	else {
		cout << "Файл успешно удалён!" << endl;
	}
	test1.close();
}

int main() {
	setlocale(LC_ALL, "Russian");
	int choice;
	char file[255];
	cout << "Выберите:\n1. Прочитать файл,\n2. Запись в  файл\n3. Создание файла,\n4. Очистка файла,\n5. Удаление файла;\nВыбор: ";
	cin >> choice;
	switch (choice) {
	case (1): {
		cout << "Введите путь к файлу: ";
		SetConsoleCP(1251);
		cin >> file;
		system("cls");
		reader(file);
		break;
	}
	case (2): {
		cout << "Введите путь к файлу: ";
		SetConsoleCP(1251);
		cin >> file;
		system("cls");
		SetConsoleCP(866);
		writer(file);
		break;
	}
	case (3): {
		system("cls");
		creator();
		break;
	}
	case (4): {
		cout << "Введите путь к файлу: ";
		SetConsoleCP(1251);
		cin >> file;
		system("cls");
		SetConsoleCP(866);
		eraser(file);
		break;
	}
	case (5): {
		cout << "Введите путь к файлу: ";
		SetConsoleCP(1251);
		cin >> file;
		system("cls");
		SetConsoleCP(866);
		deleter(file);
		break;
	}
	default: {
		system("cls");
		cout << "Другого не дано.\n";
		break;
	}
	}
	system("pause");
	return 0;
}
