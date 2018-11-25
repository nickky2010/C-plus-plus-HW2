//                          ����. �������� - ��������������� ���������������� �� C++.
//                             ������ 2. ��������� this � ����������� �����������.
//                                               �������� �������.
//                                                   �������.
// �������� ���������, ����������� ��������������� ���.
// ���������� ����� ������ ��������, ����������, ����.
// ����� ���������� �������� ������������ ������ �������� ������ ��������.
// ����� ���� �������� ������ �������� ������ ����������.
// ������ �� ������� �������� ���������� - ����� � ������� - �����, ������� ���������� ��� ���������� ������� ������.
// �������� ���� ��������, ��� ������ ��� ��������� �������� ���������� �����������.
// ��������, ��� ��� � ������ ��������. �� ��������� ���������� ������ ���������� �������������� (����������� ����������� ����������), �������������.
// � main() �������������� ������ ����������� ������ �������.
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
	Human()                      // ����������� �� ���������
	{
		N1 = N2 = N3 = 80;
		lastName = new char[N1 + 1];
		name = new char[N2 + 1];
		otch = new char[N3 + 1];
	}
	Human(int n)                 // �����������, ����������� ��������� ��� ������ ������������� �������
	{
		N1 = N2 = N3 = n;
		lastName = new char[N1 + 1];
		name = new char[N2 + 1];
		otch = new char[N3 + 1];
	}
	Human(char *s)              // �����������, ������� �������� ������ � ������� ��� (����: ������ ���� ��������) 
	{                           // ��������� �� � ���������� � ��������������� ����������
		char *word, *next;
		word = strtok_s(s, " ", &next);
		N1 = strlen(word) + 1;
		lastName = new char[N1];             // �������� �������
		strcpy_s(lastName, N1, word);
		word = strtok_s(NULL, " ", &next);
		N2 = strlen(word) + 1;
		name = new char[N2];                 // �������� ���
		strcpy_s(name, N2, word);
		word = strtok_s(NULL, " ", &next);
		N3 = strlen(word) + 1;
		otch = new char[N3];                 // �������� ��������
		strcpy_s(otch, N3, word);
	}
	Human(const Human& ob)                   // ����������� �����
	{
		// �������� �������
		lastName = new char;
		*lastName = *ob.lastName;           
		int i = 0;
		while (ob.lastName[i] != '\0') {
			lastName[i] = ob.lastName[i];
			i++;
		}
		lastName[i] = '\0';
		// �������� ���
		name = new char;
		*name = *ob.name;                 
		i = 0;
		while (ob.name[i] != '\0') {
			name[i] = ob.name[i];
			i++;
		}
		name[i] = '\0';
		// �������� ��������
		otch = new char;
		*otch = *ob.otch;                 
		i = 0;
		while (ob.otch[i] != '\0') {
			otch[i] = ob.otch[i];
			i++;
		}
		otch[i] = '\0';
	}
	~Human()                     // ����������
	{
		delete lastName;
		delete name;
		delete otch;
	}
	void inter(size_t n)                  // ����� ��� ���� ����� ���
	{
		cout << "\n������� ������ �� " << n+1 << " ��������\n";
		cout << "������� �������: ";
		scanf_s("%s", lastName, N1);
		cout << "������� ���: ";
		scanf_s("%s", name, N2);
		cout << "������� ��������: ";
		scanf_s("%s", otch, N3);
	}
	void show()                   // ����� ��� ������ ������ �� �����
	{
		cout << "�������: " << lastName << endl;
		cout << "���: " << name << endl;
		cout << "��������: " << otch << endl;
	}
};
class Flat
{
	
public:
	Human*human;
	size_t *number_flat = new size_t;   // ����� ��������
	size_t *kol_human = new size_t;     // ���������� ����������� �����
	size_t *value = new size_t;         // ��������� ��������
	size_t *cost = new size_t;          // ������� �� ��������
	size_t *rent = new size_t;          // ����� �� ������ � ��������
	bool *free_status = new bool;                   // ������ �������� (true - ��������, false - ������)
	bool *lease_status = new bool;                  // ������ ������ (true - �������� � ������, false - �� � ������)
	void check(size_t *&n) {                  // ������� �������� ����� ������������� �����
		do {
			cin >> *n;
			if (*n < 0)
				cout << "\n������! ����� ������ 0!\n";
		} while (*n < 0);
	}
	void check(bool *&n) { // ������� �������� ����� ������������� �����
		do {
			cout << "1 - ��\t0 - ���\n";
			cout << "��� �����: ";
			cin >> *n;
			if (*n != 0 && *n!=1)
				cout << "\n������! �������� ����! ������� 0 ��� 1!\n";
		} while (*n != 0 && *n != 1);
	}
	void check(int &n) { // ������� �������� ����� ������������� �����
		do {
			cout << "1 - ��\t0 - ���\n";
			cout << "��� �����: ";
			cin >> n;
			if (n != 0 && n != 1)
				cout << "\n������! �������� ����! ������� 0 ��� 1!\n";
		} while (n != 0 && n != 1);
	}
	void init_Rand(size_t &n, int max, int min) { // �������, ��������������� ������������� ��������� ����� 
		n = rand() % (int)(max - min + 1) + min;
	}
	void init_Rand(bool &n, int max, int min) { // �������, ��������������� ������������� ��������� ����� 
		n = rand() % (int)(max - min + 1) + min;
	}
	void init_flat(size_t numb) {
		cout << "===================== �������� " << numb << " =====================\n";
		cout << "������� ����� ��������: ";
		check(number_flat);
		cout << "������� ��������� ��������: ";
		check(value);
		cout << "������� ���������� ����������� �����: ";
		check(kol_human);
		if (*kol_human) {        // ���� �������� ������
			human = new Human[*kol_human];
			for (size_t i = 0; i < *kol_human; i++) {
				human->inter(i); // �������������� ��� �����
			}
			*free_status = false;
			*cost = 0;
			cout << "�������� ������� � ������?\n";
			check(lease_status);
			if (*lease_status) {
				cout << "������� ����� �� ����� �������� � ������: ";
				check(rent);
			}
			else
				*rent = 0;
		}
		else {                  // ���� �������� ��������
			cout << "������� ������� �� ��������: ";
			check(cost);
			*rent = 0;
			*free_status = true;
			*lease_status = false;
		}
	}
	void init_fl(size_t number_flat, size_t kol_human, size_t value, 
		         size_t cost, size_t rent, bool lease_status) {
		size_t fam, imya, ot;
		char lastName[10][30] = { "������", "������", "�������", "�������", "������",
			"�������", "��������", "��������", "�����", "������" };
		char name[10][30] = { "�������", "����", "�����", "�����", "����",
			"�������", "����", "������", "������", "�������" };
		char otch[10][30] = { "����������", "��������", "���������", "��������", "�������",
			"����������", "��������", "���������", "���������", "����������" };
		*this->number_flat = number_flat;
		*this->value = value;
		*this->kol_human = kol_human;
		if (*this->kol_human != 0) {        // ���� �������� ������
			human = new Human[kol_human];
			for (size_t i = 0; i < kol_human; i++) {
				init_Rand(fam, 9, 0);
				init_Rand(imya, 9, 0);
				init_Rand(ot, 9, 0);
				strcpy_s(human[i].lastName, 30, lastName[fam]); // �������������� ��� �����
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
		else {                  // ���� �������� ��������
			*this->cost = cost;
			*this->rent = 0;
			*free_status = true;
			*this->lease_status = false;
		}
	}
	Flat() {}                                                          // ����������� �� ���������
	Flat(size_t numb)                                            // ����������� ������
	{
		init_flat(numb);
	}
	Flat(size_t number_flat, size_t kol_human, size_t value, // ����������� ��������������
		size_t cost, size_t rent, bool lease_status)        
	{
		init_fl(number_flat, kol_human, value, cost, rent, lease_status);
	}
	Flat(const Flat & ob)                               // ����������� �����
	{
		size_t *number_flat = new size_t;   // ����� ��������
		*number_flat = *ob.number_flat;
		size_t *kol_human = new size_t;     // ���������� ����������� �����
		*kol_human = *ob.kol_human;
		size_t *value = new size_t;         // ��������� ��������
		*value = *ob.value;
		size_t *cost = new size_t;          // ������� �� ��������
		*cost = *ob.cost;
		size_t *rent = new size_t;          // ����� �� ������ � ��������
		*rent = *ob.rent;
		bool *free_status = new bool;                   // ������ �������� (true - ��������, false - ������)
		*free_status = *ob.free_status;
		bool *lease_status = new bool;                  // ������ ������ (true - �������� � ������, false - �� � ������)
		*lease_status = *ob.lease_status;
		if (*kol_human) {                               // ���� �������� ������
			Human *human = new Human[*kol_human];
			for (size_t i = 0; i < *kol_human; i++) {
				strcpy_s(human[i].lastName, 30, ob.human[i].lastName);
				strcpy_s(human[i].name, 30, ob.human[i].name);
				strcpy_s(human[i].otch, 30, ob.human[i].otch);
			}
		}
	}
	~Flat()                     // ����������
	{
		if (*kol_human) {       // ���� ���� ����
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
	void show(Flat &ob)                   // ����� ��� ������ �� �����
	{
		cout << "\n�������� �: " << *ob.number_flat << endl;
		cout << "���������� �����������: " << *ob.kol_human << endl;
		if (*ob.kol_human != 0) {
			for (size_t i = 0; i < *ob.kol_human; i++) {
				cout << "����������� � " << i+1 << ": " << ob.human[i].lastName << " " << ob.human[i].name << " " << ob.human[i].otch << endl;
			}
			if (*ob.lease_status) {
				cout << "����� �� ������ � ��������: " << *ob.rent << endl;
			}
		}
		else {
			cout << "������� �� ��������: " << *ob.cost << endl;
			cout << "�������� �������� � �� � ������" << endl;
		}
		cout << "C�������� ��������: " << *ob.value << endl;
		cout << "===============================================================================\n";
	}
};
class House
{	
	size_t kol_flat;              // ���������� ������� � ����
public:
	Flat * flat;
	House(size_t kol_flat)                            // ����������� �� ���������
	{
		this->kol_flat = kol_flat;
		flat = new Flat[kol_flat];
		for (size_t i = 0; i < kol_flat; i++) {
			flat[i].init_flat(i+1);
		}
	}
	House(size_t kol_flat, size_t automation)  // ����������� ��������������
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
	~House()                     // ����������
	{
		delete flat;
	}
	size_t get_kol_flat() {
		return kol_flat;
	}
	void search_by_number_flat(size_t kol_flat, size_t number_flat)       // ������� ������ �������� �� ������
	{
		bool f = false;
		for (size_t i = 0; i < kol_flat; i++) {
			if (*this->flat[i].number_flat == number_flat) {
				flat[i].show(flat[i]);
				f = true;
			}
		}
		if (f == false) cout << "�������� � ������� " << number_flat << " �� �������\n";
	}
	void search_by_lastName (size_t kol_flat, char* lastName)                   // ������� ������ �������� �� �������
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
		if (f == false) cout << "�������� � ����������� � ��� ��������� �� ������� " << lastName << " �� �������\n";
	}
	void show_flat_by_rent(size_t kol_flat) {         // ������� ������ ������� � ������
		bool f = false;
		for (size_t i = 0; i < kol_flat; i++) {
			if (*flat[i].lease_status== true) {
				if (f == false) {
					cout << "===============================================================================\n";
					cout << "�������� ����������� � ������:\n"; 
					cout << "===============================================================================\n";
				}
				f = true;
				flat[i].show(flat[i]);
			}
		}
		if (f == false) cout << "������� ����������� � ������ �� �������\n";
	}
	void show_free_flat(size_t kol_flat) {            // ������� ������ ��������� �������
		bool f = false;
		for (size_t i = 0; i < kol_flat; i++) {
			if (*flat[i].free_status == true) {
				if (f == false) {
					cout << "===============================================================================\n";
					cout << "��������� ��������:\n";
					cout << "===============================================================================\n";
				}
				f = true;
				flat[i].show(flat[i]);
			}
		}
		if (f == false) cout << "��������� ������� �� �������\n";
	}
	int count_kol_human(size_t kol_flat) {            // ������� �������� ���������� ����������� �����
		size_t n=0;
		for (size_t i = 0; i < kol_flat; i++) {
			n += *flat[i].kol_human;
		}
		return n;
	}
	int count_value(size_t kol_flat) {                // ������� �������� ����� ��������� �������
		size_t n = 0;
		for (size_t i = 0; i < kol_flat; i++) {
			n += *flat[i].value;
		}
		return n;
	}
	int count_cost(size_t kol_flat) {                 // ������� �������� ����� ������ �� ��������
		size_t n = 0;
		for (size_t i = 0; i < kol_flat; i++) {
			n += *flat[i].cost;
		}
		return n;
	}
	int count_rent(size_t kol_flat) {                 // ������� �������� ����� ������� �� ������� � ������
		size_t n = 0;
		for (size_t i = 0; i < kol_flat; i++) {
			n += *flat[i].rent;
		}
		return n;
	}
	int count_rent_flat(size_t kol_flat) {            // ������� �������� ���������� ������� � ������
		size_t n = 0;
		for (size_t i = 0; i < kol_flat; i++) {
			if (*flat[i].lease_status)
				n++;
		}
		return n;
	}
	int count_free_flat(size_t kol_flat) {            // ������� �������� ���������� ��������� �������
		size_t n = 0;
		for (size_t i = 0; i < kol_flat; i++) {
			if (*flat[i].free_status)
				n++;
		}
		return n;
	}
};
void quit() {                          // ������� ������
	cout << "���������� ������!\n";
	system("pause");
	exit(0);
}
void init_check1 (size_t &kol_flat) {
	do {
		cin >> kol_flat;
		if (kol_flat < 1)
			cout << "\n������! ����� ������ 1!\n";
	} while (kol_flat < 1);
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((size_t)time(0));
	int a = -1, vyb = 0, n;
	size_t kol_flat, automation;
	House *home;
	cout << "���������� ������ ������ �� ����\n";
	while (vyb < 1 || vyb>2) {
		cout << "�������� ������ �����:\n";
		cout << "1 - ������ ����;\n";
		cout << "2 - �������������� ����.\n";
		cout << "��� �����: ";
		cin >> vyb;
		switch (vyb)
		{
		// ������ ����
		case 1:
			system("cls");
			cout << "������� ���������� �������: ";
			init_check1(kol_flat);
			home = new House(kol_flat);
			cout << "������ � ���� ������� �������!\n";
			system("pause");
			break;
		// �������������� ����
		case 2:
			system("cls");
			cout << "������� ���������� �������: ";
			init_check1(kol_flat);
			home = new House (kol_flat, automation);
			cout << "������ � ���� ������� �������!\n";
			system("pause");
			break;
		default:
			while (cin.get() != '\n');
			cout << "�������! ��������� ����!\n";
		}
	}
	while (a) {
		int menu = -1, v = -1;
		system("cls");
		cout << "1 - ����� �������� �� ����������\n";
		cout << "2 - ����� ���������� �� ����� ����\n";
		cout << "0 - �����\n";
		cout << "��� �����: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			while (v) {
				system("cls");
				cout << "1 - ����� �������� �� ������\n";
				cout << "2 - ����� �������� �� �������\n";
				cout << "3 - ����� ������� � ����������� � ������\n";
				cout << "4 - ����� ��������� �������\n";
				cout << "0 - ����� � ���������� ����\n";
				cout << "��� �����: ";
				cin >> v;
				if (v == 1) {
					size_t number_flat;
					cout << "\n������� ����� ��������: ";
					init_check1(number_flat);
					home->search_by_number_flat(kol_flat, number_flat);
					system("pause");
				}
				else if (v == 2) {
					char lastName[30];
					cout << "\n������� �������: ";
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
					cout << "�������! ��������� ����!\n";
				}
			}
			break;
		case 2:
			cout << "\n===============================================================\n";
			cout << "\t\t����� ���������� �� ����� ����:\n\n";
			cout << "���������� �������: \t\t\t" << home->get_kol_flat() << "\n";
			cout << "���������� ����������� �����: \t\t" << home->count_kol_human(kol_flat) << "\n";
			cout << "����� ��������� �������: \t\t" << home->count_value(kol_flat) << "\n";
			cout << "����� ��������� ������ �� ��������: \t" << home->count_cost(kol_flat) << "\n";
			cout << "����� ���������� ������� � ������: \t" << home->count_rent_flat(kol_flat) << "\n";
			cout << "����� ����� �� ������� � ������: \t" << home->count_rent(kol_flat) << "\n";
			cout << "����� ���������� ��������� �������: \t" << home->count_free_flat(kol_flat) << "\n";
			cout << "\n�������� ����������� ����������:\n";
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
			cout << "�������! ��������� ����!\n";
		}
	}
	system("pause");
	return 0;
}
