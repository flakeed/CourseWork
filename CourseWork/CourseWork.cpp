//course work variant 11
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;
void viewFile(char* file1, ofstream& fout) {
	char s[250];
	FILE* f;
	f = fopen(file1, "r");
	if (f == NULL)
	{
		cout << "Error!\n ";
		return;
	}
	cout << "Просмотр файла" << ' ' << file1 << endl << endl;
	fout << "Просмотр файла" << ' ' << file1 << endl;
	while (fgets(s, 250, f))
	{
		s[strlen(s) - 1] = '\0';
		puts(s);
		fout << s << endl;
	}
	fclose(f);
	cout << endl;
	fout << endl;
}
void sizeMatrix(char* file1, int& N, int& M)
{
	char s[100], * t;
	int n = 0, m;
	FILE* f;
	f = fopen(file1, "r");
	if (f == NULL)
	{
		cout << "Error!\n ";
		return;
	}
	while (fgets(s, 100, f))
	{
		m = 0;
		t = strtok(s, " \t");
		while (t != NULL)
		{
			t = strtok(NULL, " \t");
			m++;
		}
		n++;
	}
	M = m;
	N = n;
	fclose(f);
}
void createMatrix(char* name, double** arr)
{
	FILE* f;
	char s[100], * t;
	int i = 0, j;
	f = fopen(name, "r");
	if (f == NULL)
	{
		cout << "Error!\n ";
		return;
	}
	while (fgets(s, 100, f))
	{
		j = 0;
		t = strtok(s, " \t");

		while (t != NULL)
		{
			arr[i][j] = atof(t);
			t = strtok(NULL, " \t");
			j++;
		}
		i++;
	}
	fclose(f);
}
void outputMatrix(double** const arr, int N, int M, ofstream& fout)
{
	int i, j;
	cout << "Просмотр матрици" << endl;
	fout << "Просмотр матрици" << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cout << arr[i][j] << "\t";
			fout << arr[i][j] << " ";
		}
		cout << endl;
		fout << endl;
	}
	cout << endl << endl;
	fout << endl << endl;
}
void minimalElement(double** const arr, int N, int M, ofstream& fout) {
	int min = 10000;
	int p = 0;
	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++) {
			if (arr[i][j] < min && arr[i][j]>0) {
				min = arr[i][j];
			}
		}
	}
	cout << "Задание 1.1\n" << endl;
	fout << "Задание 1.1\n" << endl;
	cout << "Наименьший элемент матрици:\n " << min << endl << endl;
	fout << "Наименьший элемент матрици:\n " << min << endl << endl;
}
void vectorAverage(double** const arr, int N, int M, ofstream& fout)
{
	double* v = new double[N];
	double arif;
	for (int i = 0; i < N; i++)
	{
		double sum = 0.0, count = 0.0;
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] > 0)
			{
				sum += arr[i][j];
				count++;
			}
			arif = sum / count;
		}
		v[i] = arif;
	}
	cout << "Задание 1.2\n" << endl;
	fout << "Задание 1.2\n" << endl;
	cout << "Елементы вектора как среднее арифметическое положительных елементов строк матрици: " << endl;
	fout << "Елементы вектора как среднее арифметическое положительных елементов строк матрици: " << endl;
	for (int j = 0; j < N; j++) {
		cout << v[j] << "\t";
		fout << v[j] << "\t";
	}
	cout << endl;
	fout << endl;
}
void ifNegative(double** const arr, int N, int M, ofstream& fout) {
	cout << "Задание 1.3\n" << endl;
	fout << "Задание 1.3\n" << endl;
	cout << "Сумма елементов где есть хотя бы один негативный елемент: " << endl;
	fout << "Сумма елементов где есть хотя бы один негативный елемент: " << endl;
	for (int i = 0; i < N; i++) {
		double sum = 0;
		bool check = false;
		for (int j = 0; j < M; j++) {
			sum += arr[i][j];
			if (arr[i][j] < 0)
				check = true;
		}
		if (check) {
			cout << sum << "\t";
			fout << sum << "\t";
		}
	}
	cout << "\n";
	fout << "\n";
}
void powElements(double** const arr, int N, int M, ofstream& fout) {
	double** pp = new double* [N];
	for (int i = 0; i < N; i++)
	{
		pp[i] = new double[M];
	}
	int c = 0;
	int k = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			pp[i][j] = arr[i][j];
			if (arr[i][j] < 0)
			{
				pp[i][j] *= 0;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; ++j) {
			if (pp[i][j] > 0)
			{
				c++;
			}
		}
	}
	double* kv = new double[c];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; ++j) {
			if (pp[i][j] > 0)
			{
				kv[k++] = pow(pp[i][j], 2);
			}
		}
	}
	cout << "Задание 2.1" << endl;
	fout << "Задание 2.1" << endl;
	cout << "Одномерный массив из квадратов положительных элементов матриц " << endl;
	fout << "Одномерный массив из квадратов положительных элементов матриц " << endl;
	for (int i = 0; i < c; i++) {
		cout << kv[i] << "\t";
		fout << kv[i] << "\t";
	}
	cout << endl;
	fout << endl;
}
void newMatrix(double** const arr, int N, int M, ofstream& fout) {
	int u = -1;
	int e = 0;
	for (int j = 0; j < M; j++)
	{
		int p = 0;
		for (int i = 0; i < N; i++)
			if (arr[i][j] == 11 || arr[i][j] == 22) {
				p = 1; break;
			}
		if (p == 0) e++;
	}
	if (e)
	{
		int** b = new int* [N];
		for (int i = 0; i < N; i++)
			b[i] = new int[e];
		for (int j = 0; j < M; j++)
		{
			int p = 0;
			for (int i = 0; i < N; i++)
				if (arr[i][j] == 11 || arr[i][j] == 22) {
					p = 1; break;
				}
			if (p == 0)
			{
				u++;
				for (int i = 0; i < N; i++)
					b[i][u] = arr[i][j];
			}
		}
		cout << "Задание 2.2\n" << endl;
		fout << "Задание 2.2\n" << endl;
		cout << "Новая матрица из столбцов заданной матрицы, которые не содержат ни одного элемента '11' или '22': " << endl;
		fout << "Новая матрица из столбцов заданной матрицы, которые не содержат ни одного элемента '11' или '22': " << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < e; j++) {
				cout << b[i][j] << "\t";
				fout << b[i][j] << " " << "\t";
			}
			cout << endl;
			fout << endl;
		}
		for (int i = 0; i < N; i++)
			delete[]b[i];
		delete[]b;
	}
	else
		cout << "Столбы не содержат елементов '11' или '22'.\n";
	fout << "Столбы не содержат елементов '11' или '22'.\n";
}
void extraSpaces(string file2, ofstream& fout) {
	ifstream f2;
	string s;
	int c = 0;
	f2.open(file2);
	if (f2.is_open())
	{
		while (getline(f2, s))
		{
			for (int i = 1; i < s.length(); i++) {

				if (s[i] == ' ' && s[i - 1] == ' ') c++;
			}
		}
	}
	cout << "Задание 3.1\n" << endl;
	fout << "Задание 3.1\n" << endl;
	cout << "Количество лишних пробелов: " << endl;
	fout << "Количество лишних пробелов: " << endl;
	cout << c << endl;
	fout << c << endl;
	f2.close();
}
void insertChars(string file2, ofstream& fout) {
	string s1;
	string s2;
	string help_str = "";
	bool sym_before = false;
	int half_of_s1_index;
	ifstream f2;
	f2.open(file2);
	if (f2.is_open())
	{
		cout << "Задание 3.2\n" << endl;
		fout << "Задание 3.2\n" << endl;
		getline(f2, s1);
		getline(f2, s2);
		half_of_s1_index = s1.length() / 2;
	}
	for (int i = 0; i < s2.length(); i++) {
		if (!isalpha(s2[i]) && !isdigit(s2[i])) {
			if (sym_before) {
				help_str += " ";
			}
			help_str += s2[i];
			sym_before = true;
		}
	}
	cout << "Все символы из s2 которые не являються буквами и цифрами вставив в средину строки s1 учитывая пробелы: " << endl;
	fout << "Все символы из s2 которые не являються буквами и цифрами вставив в средину строки s1 учитывая пробелы: " << endl;
	s1.insert(half_of_s1_index, help_str);
	cout << s1 << endl;
	fout << s1 << endl;
	f2.close();
}
void shrtWordStr(string file2, ofstream& fout) {
	string s;
	char ch[10000];
	string help_str = "";
	bool sym_before = false;
	bool is_start = true;
	string shrt_word, shrt_word_str;
	ifstream f2;
	f2.open(file2);
	if (f2.is_open())
	{
		cout << "Задание 4.1\n" << endl;
		fout << "Задание 4.1\n" << endl;
	}
	while (!f2.eof())
	{
		getline(f2, s);
		strcpy(ch, s.c_str() + '\0');
		char* now_word = strtok(ch, " ,.:;!?");
		do {
			if (is_start || string(now_word).length() < shrt_word.length()) {
				shrt_word = string(now_word);
				shrt_word_str = s;
				is_start = false;
			}
			now_word = strtok(NULL, " ,.:;!?");
		} while (now_word != NULL);
	}
	cout << "Строка которая имеет самое маленькое слово в тексте: " << endl;
	fout << "Строка которая имеет самое маленькое слово в тексте: " << endl;
	cout << shrt_word_str << endl;
	fout << shrt_word_str << endl;
	f2.close();
}
int main() {
	setlocale(LC_ALL, "Russian");
	int N;
	int M;
	int i, j = 0;
	char file1[] = "F1.txt";
	char file2[] = "F2.txt";
	char file3[] = "F3.txt";
	ofstream fout;
	fout.open("f3.txt");
	sizeMatrix(file1, N, M);
	double** arr = new double* [N];
	for (i = 0; i < N; i++)
	{
		arr[i] = new double[M];
	}
	viewFile(file1, fout);
	createMatrix(file1, arr);
	outputMatrix(arr, N, M, fout);
	minimalElement(arr, N, M, fout);
	vectorAverage(arr, N, M, fout);
	ifNegative(arr, N, M, fout);
	powElements(arr, N, M, fout);
	newMatrix(arr, N, M, fout);
	viewFile(file2, fout);
	extraSpaces(file2, fout);
	insertChars(file2, fout);
	shrtWordStr(file2, fout);
	fout.close();
	for (i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}
