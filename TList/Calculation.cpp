//#include "TPolinom.h"
//#include<vector>
//#include<locale.h>
//
//void PrintVector(vector<TPolinom> v, int EmptyIdx)
//{
//	cout << "Вектор полиномов:\n\n";
//
//	for (int i = 0; i < EmptyIdx; i++)
//	{
//		cout << "|" << i + 1 << "| " << v[i] << endl;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	vector<TPolinom> vect;
//	TPolinom pol;
//	int a, EmptyIdx = 0;//указывает на последний пустой элемент вектора
//	int IndexP1, IndexP2;//нумерация с 1
//	while (1)
//	{
//		cout << "1-добавиьть полином\n2-сложение\n3-вычитание\n4-умножение на константу\n5- +=\n6-вывести вектор\n7-очистить вектор\n8-выйти из программы\n";
//		cin >> a;
//		switch (a)
//		{
//		case 1:
//			pol.EnterPolinom();
//			vect.push_back(pol);
//			EmptyIdx++;
//			PrintVector(vect, EmptyIdx);
//			pol.DelList();
//			break;
//		case 2:
//			cout << "Введите номера полиномов с которые вы хотите сложить\n";
//			cin >> IndexP1 >> IndexP2;
//			if (IndexP1 < 1 || IndexP1 > EmptyIdx || IndexP2 < 1 || IndexP2 > EmptyIdx) {
//				cout << "Номера полиномов должны быть в диапазоне от 1 до " << EmptyIdx << "\n";
//				continue;
//			}
//			vect.push_back(vect[IndexP1 - 1] + vect[IndexP2 - 1]);
//			EmptyIdx++;
//			cout << "\nРезультат сложения: " << vect[EmptyIdx - 1] << endl;
//			break;
//		case 3:
//			cout << "Введите уменьшаемое и вычитаемое\n";
//			cin >> IndexP1 >> IndexP2;
//			if (IndexP1 < 1 || IndexP1 > EmptyIdx || IndexP2 < 1 || IndexP2 > EmptyIdx) {
//				cout << "Номера полиномов должны быть в диапазоне от 1 до " << EmptyIdx << "\n";
//				continue;
//			}
//			vect.push_back(vect[IndexP1 - 1] - vect[IndexP2 - 1]);
//			EmptyIdx++;
//			cout << "\nРезультат вычитания: " << vect[EmptyIdx - 1] << endl;
//			break;
//		case 4:
//			cout << "Введите номера полинома и константу\n";
//			cin >> IndexP1 >> IndexP2;
//			if (IndexP1 < 1 || IndexP1 > EmptyIdx) {
//				cout << "Номер полинома должен быть в диапазоне от 1 до " << EmptyIdx << "\n";
//				continue;
//			}
//			vect.push_back(vect[IndexP1 - 1] * IndexP2);
//			EmptyIdx++;
//			cout << "\nРезультат умножения: " << vect[EmptyIdx - 1] << endl;
//			break;
//		case 6:
//			PrintVector(vect, EmptyIdx);
//			break;
//		case 7:
//			vect.clear();
//			EmptyIdx = 0;
//			cout << "Вектор очищен.\n";
//			break;
//		case 8:
//			return 0;
//		default:
//			cout << "Неверный ввод. Пожалуйста, введите число от 1 до 8.\n";
//			break;
//		}
//	}
//}


#include "TPolinom.h"
#include<vector>
#include<locale.h>
void PrintV(vector<TPolinom> v, int EmptyIdx)
{
	cout << "вектор полиномов:\n\n";

	for (int i = 0; i < EmptyIdx; i++)
	{

		cout << "[" << i + 1 << "] " << v[i] << endl;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_CTYPE, "russian");
	vector<TPolinom> vector(10);
	TPolinom TP;
	int command;
	int EmptyIdx = 0;
	int IndexP1, IndexP2;
	int Const;
	while (1)
	{
		cout << "1 - Добавить полином в вектор\n2 - Сложение полиномов\n3 - Вычитание полиномов\n4 - Умножение на константу\n5 - Напечатать вектор\n6 - Очистить вектор\n7 - Выйти\n";
		cin >> command;
		switch (command)
		{
		case 1:
			TP.EnterPolinom();
			vector[EmptyIdx] = TP;
			EmptyIdx++;
			PrintV(vector, EmptyIdx);
			TP.DelList();
			break;
		case 2:
			cout << "Введите индекс первого полинома:" << endl;
			cin >> IndexP1;
			cout << "Введите индекс второго полинома:" << endl;
			cin >> IndexP2;
			if (IndexP1 < 1 || IndexP1 > EmptyIdx || IndexP2 < 1 || IndexP2 > EmptyIdx) {
				cout << "Неправильный индекс, индексы должны быть от 1 до " << EmptyIdx << endl;
				continue;
			}

			vector[EmptyIdx] = vector[IndexP1 - 1] + vector[IndexP2 - 1];
			EmptyIdx++;
			cout << "Результат: " << vector[EmptyIdx - 1] << endl;
			break;
		case 3:
			cout << "Введите индекс уменьшаемого:" << endl;
			cin >> IndexP1;
			cout << "Введите индекс вычитаемого:" << endl;
			cin >> IndexP2;

			vector[EmptyIdx] = vector[IndexP1 - 1] - vector[IndexP2 - 1];
			EmptyIdx++;
			cout << "Результат: " << vector[EmptyIdx - 1] << endl;

			break;
		case 4:
			cout << "Введите номер полинома:" << endl;
			cin >> IndexP1;
			cout << "Введите число:" << endl;
			cin >> Const;

			vector[EmptyIdx] = vector[IndexP1 - 1] * Const;
			EmptyIdx++;
			cout << "Результат: " << vector[EmptyIdx - 1] << endl;
			break;
		case 5:
			PrintV(vector, EmptyIdx);
			break;

		case 6:
			vector.clear();
			EmptyIdx = 0;
			cout << "Вектор очищен." << endl;
			break;
		case 7:
			return 0;
		default:
			cout << "Неверный ввод. Пожалуйста, введите число от 1 до 8." << endl;
			break;
		}
	}
}