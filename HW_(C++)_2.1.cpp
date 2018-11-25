//                          Курс. Объектно - ориентированное программирование на C++.
//                             Модуль 2. Указатель this и конструктор копирования.
//                                               Домашнее задание.
//                                                   Задание.
// Создайте программу, имитирующую многоквартирный дом.
// Необходимо иметь классы “Человек”, “Квартира”, “Дом”.
// Класс “Квартира” содержит динамический массив объектов класса “Человек”.
// Класс “Дом” содержит массив объектов класса “Квартира”.
// Каждый из классов содержит переменные - члены и функции - члены, которые необходимы для предметной области класса.
// Обращаем ваше внимание, что память под строковые значения выделяется динамически.
// Например, для ФИО в классе “Человек”. Не забывайте обеспечить классы различными конструкторами (конструктор копирования обязателен), деструкторами.
// В main() протестировать работу полученного набора классов.
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

class Human
{
private:
	int N1, N2, N3;
public:
	char *lastName, *name, *otch;
	Human()                      // конструктор по умолчанию
	{
		N1 = N2 = N3 = 80;
		lastName = new char[N1 + 1];
		name = new char[N2 + 1];
		otch = new char[N3 + 1];
	}
	Human(int n)                 // конструктор, позволяющий создавать все строки произвольного размера
	{
		N1 = N2 = N3 = n;
		lastName = new char[N1 + 1];
		name = new char[N2 + 1];
		otch = new char[N3 + 1];
	}
	Human(char *s)              // конструктор, который получает строку в формате ФИО (вида: Иванов Иван Иванович) 
	{                           // разделяет ее и записывает в соответствующие переменные
		char *word, *next;
		word = strtok_s(s, " ", &next);
		N1 = strlen(word) + 1;
		lastName = new char[N1];             // получаем фамилию
		strcpy_s(lastName, N1, word);
		word = strtok_s(NULL, " ", &next);
		N2 = strlen(word) + 1;
		name = new char[N2];                 // получаем имя
		strcpy_s(name, N2, word);
		word = strtok_s(NULL, " ", &next);
		N3 = strlen(word) + 1;
		otch = new char[N3];                 // получаем отчество
		strcpy_s(otch, N3, word);
	}
	Human(const Human& ob)                   // конструктор копии
	{
		// копируем фамилию
		lastName = new char;
		*lastName = *ob.lastName;           
		int i = 0;
		while (ob.lastName[i] != '\0') {
			lastName[i] = ob.lastName[i];
			i++;
		}
		lastName[i] = '\0';
		// копируем имя
		name = new char;
		*name = *ob.name;                 
		i = 0;
		while (ob.name[i] != '\0') {
			name[i] = ob.name[i];
			i++;
		}
		name[i] = '\0';
		// копируем отчество
		otch = new char;
		*otch = *ob.otch;                 
		i = 0;
		while (ob.otch[i] != '\0') {
			otch[i] = ob.otch[i];
			i++;
		}
		otch[i] = '\0';
	}
	~Human()                     // деструктор
	{
		delete lastName;
		delete name;
		delete otch;
	}
	void inter(size_t n)                  // метод для ввод строк ФИО
	{
		cout << "\nВведите данные по " << n+1 << " человеку\n";
		cout << "Введите фамилию: ";
		scanf_s("%s", lastName, N1);
		cout << "Введите имя: ";
		scanf_s("%s", name, N2);
		cout << "Введите отчество: ";
		scanf_s("%s", otch, N3);
	}
	void show()                   // метод для вывода строки на экран
	{
		cout << "Фамилия: " << lastName << endl;
		cout << "Имя: " << name << endl;
		cout << "Отчество: " << otch << endl;
	}
};
class Flat
{
	
public:
	Human*human;
	size_t *number_flat = new size_t;   // номер квартиры
	size_t *kol_human = new size_t;     // количество проживающих людей
	size_t *value = new size_t;         // стоимость квартиры
	size_t *cost = new size_t;          // затраты на квартиру
	size_t *rent = new size_t;          // доход от аренды с квартиры
	bool *free_status = new bool;                   // статус квартиры (true - свободна, false - занята)
	bool *lease_status = new bool;                  // статус аренды (true - квартира в аренде, false - не в аренде)
	void check(size_t *&n) {                  // функция проверки ввода отрицательных чисел
		do {
			cin >> *n;
			if (*n < 0)
				cout << "\nОшибка! Число меньше 0!\n";
		} while (*n < 0);
	}
	void check(bool *&n) { // функция проверки ввода отрицательных чисел
		do {
			cout << "1 - да\t0 - нет\n";
			cout << "Ваш выбор: ";
			cin >> *n;
			if (*n != 0 && *n!=1)
				cout << "\nОшибка! Неверный ввод! Введите 0 или 1!\n";
		} while (*n != 0 && *n != 1);
	}
	void check(int &n) { // функция проверки ввода отрицательных чисел
		do {
			cout << "1 - да\t0 - нет\n";
			cout << "Ваш выбор: ";
			cin >> n;
			if (n != 0 && n != 1)
				cout << "\nОшибка! Неверный ввод! Введите 0 или 1!\n";
		} while (n != 0 && n != 1);
	}
	void init_Rand(size_t &n, int max, int min) { // функция, предназначенная инициализации случайных чисел 
		n = rand() % (int)(max - min + 1) + min;
	}
	void init_Rand(bool &n, int max, int min) { // функция, предназначенная инициализации случайных чисел 
		n = rand() % (int)(max - min + 1) + min;
	}
	void init_flat(size_t numb) {
		cout << "===================== Квартира " << numb << " =====================\n";
		cout << "Введите номер квартиры: ";
		check(number_flat);
		cout << "Введите стоимость квартиры: ";
		check(value);
		cout << "Введите количество проживающих людей: ";
		check(kol_human);
		if (*kol_human) {        // если квартира занята
			human = new Human[*kol_human];
			for (size_t i = 0; i < *kol_human; i++) {
				human->inter(i); // инициализируем ФИО людей
			}
			*free_status = false;
			*cost = 0;
			cout << "Квартира сдается в аренду?\n";
			check(lease_status);
			if (*lease_status) {
				cout << "Введите доход от сдачи квартиры в аренду: ";
				check(rent);
			}
			else
				*rent = 0;
		}
		else {                  // если квартира свободна
			cout << "Введите затраты на квартиру: ";
			check(cost);
			*rent = 0;
			*free_status = true;
			*lease_status = false;
		}
	}
	void init_fl(size_t number_flat, size_t kol_human, size_t value, 
		         size_t cost, size_t rent, bool lease_status) {
		size_t fam, imya, ot;
		char lastName[10][30] = { "Иванов", "Петров", "Сидоров", "Антонов", "Павлов",
			"Терешко", "Воеводов", "Карпенко", "Лукин", "Валуев" };
		char name[10][30] = { "Николай", "Петр", "Антон", "Павел", "Юрий",
			"Дмитрий", "Иван", "Сергей", "Андрей", "Василий" };
		char otch[10][30] = { "Николаевич", "Петрович", "Антонович", "Павлович", "Юрьевич",
			"Дмитриевич", "Иванович", "Сергеевич", "Андреевич", "Васильевич" };
		*this->number_flat = number_flat;
		*this->value = value;
		*this->kol_human = kol_human;
		if (*this->kol_human != 0) {        // если квартира занята
			human = new Human[kol_human];
			for (size_t i = 0; i < kol_human; i++) {
				init_Rand(fam, 9, 0);
				init_Rand(imya, 9, 0);
				init_Rand(ot, 9, 0);
				strcpy_s(human[i].lastName, 30, lastName[fam]); // инициализируем ФИО людей
				strcpy_s(human[i].name, 30, name[imya]);
				strcpy_s(human[i].otch, 30, otch[ot]);
			}
			*free_status = false;
			*this->cost = 0;
			*this->lease_status = lease_status;
			if (*this->lease_status) {
				*this->rent = rent;
			}
			else
				*this->rent = 0;
		}
		else {                  // если квартира свободна
			*this->cost = cost;
			*this->rent = 0;
			*free_status = true;
			*this->lease_status = false;
		}
	}
	Flat() {}                                                          // конструктор по умолчанию
	Flat(size_t numb)                                            // конструктор ручной
	{
		init_flat(numb);
	}
	Flat(size_t number_flat, size_t kol_human, size_t value, // конструктор автоматический
		size_t cost, size_t rent, bool lease_status)        
	{
		init_fl(number_flat, kol_human, value, cost, rent, lease_status);
	}
	Flat(const Flat & ob)                               // конструктор копии
	{
		size_t *number_flat = new size_t;   // номер квартиры
		*number_flat = *ob.number_flat;
		size_t *kol_human = new size_t;     // количество проживающих людей
		*kol_human = *ob.kol_human;
		size_t *value = new size_t;         // стоимость квартиры
		*value = *ob.value;
		size_t *cost = new size_t;          // затраты на квартиру
		*cost = *ob.cost;
		size_t *rent = new size_t;          // доход от аренды с квартиры
		*rent = *ob.rent;
		bool *free_status = new bool;                   // статус квартиры (true - свободна, false - занята)
		*free_status = *ob.free_status;
		bool *lease_status = new bool;                  // статус аренды (true - квартира в аренде, false - не в аренде)
		*lease_status = *ob.lease_status;
		if (*kol_human) {                               // если квартира занята
			Human *human = new Human[*kol_human];
			for (size_t i = 0; i < *kol_human; i++) {
				strcpy_s(human[i].lastName, 30, ob.human[i].lastName);
				strcpy_s(human[i].name, 30, ob.human[i].name);
				strcpy_s(human[i].otch, 30, ob.human[i].otch);
			}
		}
	}
	~Flat()                     // деструктор
	{
		if (*kol_human) {       // если были люди
			delete human;
		}
		delete kol_human;
		delete number_flat;
		delete value;
		delete cost;
		delete rent;
		delete free_status;
		delete lease_status;
	}
	void show(Flat &ob)                   // метод для показа на экран
	{
		cout << "\nКвартира №: " << *ob.number_flat << endl;
		cout << "Количество проживающих: " << *ob.kol_human << endl;
		if (*ob.kol_human != 0) {
			for (size_t i = 0; i < *ob.kol_human; i++) {
				cout << "Проживающий № " << i+1 << ": " << ob.human[i].lastName << " " << ob.human[i].name << " " << ob.human[i].otch << endl;
			}
			if (*ob.lease_status) {
				cout << "Доход от аренды с квартиры: " << *ob.rent << endl;
			}
		}
		else {
			cout << "Затраты на квартиру: " << *ob.cost << endl;
			cout << "Квартира свободна и не в аренде" << endl;
		}
		cout << "Cтоимость квартиры: " << *ob.value << endl;
		cout << "===============================================================================\n";
	}
};
class House
{	
	size_t kol_flat;              // количество квартир в доме
public:
	Flat * flat;
	House(size_t kol_flat)                            // конструктор по умолчанию
	{
		this->kol_flat = kol_flat;
		flat = new Flat[kol_flat];
		for (size_t i = 0; i < kol_flat; i++) {
			flat[i].init_flat(i+1);
		}
	}
	House(size_t kol_flat, size_t automation)  // конструктор автоматический
	{
		size_t kol_human, value, cost, rent, lease_status;
		this->kol_flat = kol_flat;
		flat = new Flat[kol_flat];
		for (size_t i = 0, j = 1; i < kol_flat; i++) {
			flat[i].init_Rand(kol_human, 5, 0);
			flat[i].init_Rand(value, 100000, 15000);
			flat[i].init_Rand(cost, 300, 50);
			flat[i].init_Rand(rent, 500, 100);
			flat[i].init_Rand(lease_status, 1, 0);
			flat[i].init_fl(i+j, kol_human, value, cost, rent, lease_status);
		}
	}
	~House()                     // деструктор
	{
		delete flat;
	}
	size_t get_kol_flat() {
		return kol_flat;
	}
	void search_by_number_flat(size_t kol_flat, size_t number_flat)       // функция поиска квартиры по номеру
	{
		bool f = false;
		for (size_t i = 0; i < kol_flat; i++) {
			if (*this->flat[i].number_flat == number_flat) {
				flat[i].show(flat[i]);
				f = true;
			}
		}
		if (f == false) cout << "Квартиры с номером " << number_flat << " не найдено\n";
	}
	void search_by_lastName (size_t kol_flat, char* lastName)                   // функция поиска квартиры по фамилии
	{
		bool f = false;
		for (size_t i = 0; i < kol_flat; i++) {
			bool a = false;
			for (int j = *flat[i].kol_human-1; j > -1; j--) {
				if (strcmp(flat[i].human[j].lastName, lastName) == 0) {
					if (a == false) {
						flat[i].show(flat[i]);
						f = true;
						a = true;
					}
				}
			}
		}
		if (f == false) cout << "Квартиры с проживающим в ней человеком по фамилии " << lastName << " не найдено\n";
	}
	void show_flat_by_rent(size_t kol_flat) {         // функция поиска квартир в аренде
		bool f = false;
		for (size_t i = 0; i < kol_flat; i++) {
			if (*flat[i].lease_status== true) {
				if (f == false) {
					cout << "===============================================================================\n";
					cout << "Квартиры находящиеся в аренде:\n"; 
					cout << "===============================================================================\n";
				}
				f = true;
				flat[i].show(flat[i]);
			}
		}
		if (f == false) cout << "Квартир находящихся в аренде не найдено\n";
	}
	void show_free_flat(size_t kol_flat) {            // функция поиска свободных квартир
		bool f = false;
		for (size_t i = 0; i < kol_flat; i++) {
			if (*flat[i].free_status == true) {
				if (f == false) {
					cout << "===============================================================================\n";
					cout << "Свободные квартиры:\n";
					cout << "===============================================================================\n";
				}
				f = true;
				flat[i].show(flat[i]);
			}
		}
		if (f == false) cout << "Свободных квартир не найдено\n";
	}
	int count_kol_human(size_t kol_flat) {            // функция подсчета количества проживающих людей
		size_t n=0;
		for (size_t i = 0; i < kol_flat; i++) {
			n += *flat[i].kol_human;
		}
		return n;
	}
	int count_value(size_t kol_flat) {                // функция подсчета общей стоимости квартир
		size_t n = 0;
		for (size_t i = 0; i < kol_flat; i++) {
			n += *flat[i].value;
		}
		return n;
	}
	int count_cost(size_t kol_flat) {                 // функция подсчета общих затрат на квартиры
		size_t n = 0;
		for (size_t i = 0; i < kol_flat; i++) {
			n += *flat[i].cost;
		}
		return n;
	}
	int count_rent(size_t kol_flat) {                 // функция подсчета общих доходов от квартир в аренде
		size_t n = 0;
		for (size_t i = 0; i < kol_flat; i++) {
			n += *flat[i].rent;
		}
		return n;
	}
	int count_rent_flat(size_t kol_flat) {            // функция подсчета количества квартир в аренде
		size_t n = 0;
		for (size_t i = 0; i < kol_flat; i++) {
			if (*flat[i].lease_status)
				n++;
		}
		return n;
	}
	int count_free_flat(size_t kol_flat) {            // функция подсчета количества свободных квартир
		size_t n = 0;
		for (size_t i = 0; i < kol_flat; i++) {
			if (*flat[i].free_status)
				n++;
		}
		return n;
	}
};
void quit() {                          // функция выхода
	cout << "Завершение работы!\n";
	system("pause");
	exit(0);
}
void init_check1 (size_t &kol_flat) {
	do {
		cin >> kol_flat;
		if (kol_flat < 1)
			cout << "\nОшибка! Число меньше 1!\n";
	} while (kol_flat < 1);
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((size_t)time(0));
	int a = -1, vyb = 0, n;
	size_t kol_flat, automation;
	House *home;
	cout << "Необходимо ввести данные по дому\n";
	while (vyb < 1 || vyb>2) {
		cout << "Выберите способ ввода:\n";
		cout << "1 - ручной ввод;\n";
		cout << "2 - автоматический ввод.\n";
		cout << "Ваш выбор: ";
		cin >> vyb;
		switch (vyb)
		{
		// ручной ввод
		case 1:
			system("cls");
			cout << "Введите количество квартир: ";
			init_check1(kol_flat);
			home = new House(kol_flat);
			cout << "Данные о доме внесены успешно!\n";
			system("pause");
			break;
		// автоматический ввод
		case 2:
			system("cls");
			cout << "Введите количество квартир: ";
			init_check1(kol_flat);
			home = new House (kol_flat, automation);
			cout << "Данные о доме внесены успешно!\n";
			system("pause");
			break;
		default:
			while (cin.get() != '\n');
			cout << "Неверно! Повторите ввод!\n";
		}
	}
	while (a) {
		int menu = -1, v = -1;
		system("cls");
		cout << "1 - поиск квартиры по параметрам\n";
		cout << "2 - общая статистика по всему дому\n";
		cout << "0 - выход\n";
		cout << "Ваш выбор: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			while (v) {
				system("cls");
				cout << "1 - поиск квартиры по номеру\n";
				cout << "2 - поиск квартиры по фамилии\n";
				cout << "3 - поиск квартир в находящихся в аренде\n";
				cout << "4 - поиск свободных квартир\n";
				cout << "0 - выход в предыдущее меню\n";
				cout << "Ваш выбор: ";
				cin >> v;
				if (v == 1) {
					size_t number_flat;
					cout << "\nВведите номер квартиры: ";
					init_check1(number_flat);
					home->search_by_number_flat(kol_flat, number_flat);
					system("pause");
				}
				else if (v == 2) {
					char lastName[30];
					cout << "\nВведите фамилию: ";
					scanf_s("%s", &lastName, 30);
					home->search_by_lastName(kol_flat, lastName);
					system("pause");
				}
				else if (v == 3) {
					home->show_flat_by_rent(kol_flat);
					system("pause");
				}
				else if (v == 4) {
					home->show_free_flat(kol_flat);
					system("pause");
				}
				else if (v == 0) { v = 0; }
				else {
					while (cin.get() != '\n');
					cout << "Неверно! Повторите ввод!\n";
				}
			}
			break;
		case 2:
			cout << "\n===============================================================\n";
			cout << "\t\tОбщая статистика по всему дому:\n\n";
			cout << "Количество квартир: \t\t\t" << home->get_kol_flat() << "\n";
			cout << "Количество проживающих людей: \t\t" << home->count_kol_human(kol_flat) << "\n";
			cout << "Общая стоимость квартир: \t\t" << home->count_value(kol_flat) << "\n";
			cout << "Общая стоимость затрат на квартиры: \t" << home->count_cost(kol_flat) << "\n";
			cout << "Общее количество квартир в аренде: \t" << home->count_rent_flat(kol_flat) << "\n";
			cout << "Общий доход от квартир в аренде: \t" << home->count_rent(kol_flat) << "\n";
			cout << "Общее количество свободных квартир: \t" << home->count_free_flat(kol_flat) << "\n";
			cout << "\nПоказать развернутую статистику:\n";
			home->flat->check(n);
			if (n && home->get_kol_flat()>0) {
				for (size_t i = 0; i < home->get_kol_flat(); i++) {
					home->flat[i].show(home->flat[i]);
				}
			}
			system("pause");
			break;
		case 0:
			quit();
			break;
		default:
			while (cin.get() != '\n');
			cout << "Неверно! Повторите ввод!\n";
		}
	}
	system("pause");
	return 0;
}
