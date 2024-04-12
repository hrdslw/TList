//#include "TPolinom.h"
//#include<vector>
//#include<locale.h>
//
//void PrintVector(vector<TPolinom> v, int EmptyIdx)
//{
//	cout << "������ ���������:\n\n";
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
//	int a, EmptyIdx = 0;//��������� �� ��������� ������ ������� �������
//	int IndexP1, IndexP2;//��������� � 1
//	while (1)
//	{
//		cout << "1-��������� �������\n2-��������\n3-���������\n4-��������� �� ���������\n5- +=\n6-������� ������\n7-�������� ������\n8-����� �� ���������\n";
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
//			cout << "������� ������ ��������� � ������� �� ������ �������\n";
//			cin >> IndexP1 >> IndexP2;
//			if (IndexP1 < 1 || IndexP1 > EmptyIdx || IndexP2 < 1 || IndexP2 > EmptyIdx) {
//				cout << "������ ��������� ������ ���� � ��������� �� 1 �� " << EmptyIdx << "\n";
//				continue;
//			}
//			vect.push_back(vect[IndexP1 - 1] + vect[IndexP2 - 1]);
//			EmptyIdx++;
//			cout << "\n��������� ��������: " << vect[EmptyIdx - 1] << endl;
//			break;
//		case 3:
//			cout << "������� ����������� � ����������\n";
//			cin >> IndexP1 >> IndexP2;
//			if (IndexP1 < 1 || IndexP1 > EmptyIdx || IndexP2 < 1 || IndexP2 > EmptyIdx) {
//				cout << "������ ��������� ������ ���� � ��������� �� 1 �� " << EmptyIdx << "\n";
//				continue;
//			}
//			vect.push_back(vect[IndexP1 - 1] - vect[IndexP2 - 1]);
//			EmptyIdx++;
//			cout << "\n��������� ���������: " << vect[EmptyIdx - 1] << endl;
//			break;
//		case 4:
//			cout << "������� ������ �������� � ���������\n";
//			cin >> IndexP1 >> IndexP2;
//			if (IndexP1 < 1 || IndexP1 > EmptyIdx) {
//				cout << "����� �������� ������ ���� � ��������� �� 1 �� " << EmptyIdx << "\n";
//				continue;
//			}
//			vect.push_back(vect[IndexP1 - 1] * IndexP2);
//			EmptyIdx++;
//			cout << "\n��������� ���������: " << vect[EmptyIdx - 1] << endl;
//			break;
//		case 6:
//			PrintVector(vect, EmptyIdx);
//			break;
//		case 7:
//			vect.clear();
//			EmptyIdx = 0;
//			cout << "������ ������.\n";
//			break;
//		case 8:
//			return 0;
//		default:
//			cout << "�������� ����. ����������, ������� ����� �� 1 �� 8.\n";
//			break;
//		}
//	}
//}


#include "TPolinom.h"
#include<vector>
#include<locale.h>
void PrintV(vector<TPolinom> v, int EmptyIdx)
{
	cout << "������ ���������:\n\n";

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
		cout << "1 - �������� ������� � ������\n2 - �������� ���������\n3 - ��������� ���������\n4 - ��������� �� ���������\n5 - ���������� ������\n6 - �������� ������\n7 - �����\n";
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
			cout << "������� ������ ������� ��������:" << endl;
			cin >> IndexP1;
			cout << "������� ������ ������� ��������:" << endl;
			cin >> IndexP2;
			if (IndexP1 < 1 || IndexP1 > EmptyIdx || IndexP2 < 1 || IndexP2 > EmptyIdx) {
				cout << "������������ ������, ������� ������ ���� �� 1 �� " << EmptyIdx << endl;
				continue;
			}

			vector[EmptyIdx] = vector[IndexP1 - 1] + vector[IndexP2 - 1];
			EmptyIdx++;
			cout << "���������: " << vector[EmptyIdx - 1] << endl;
			break;
		case 3:
			cout << "������� ������ ������������:" << endl;
			cin >> IndexP1;
			cout << "������� ������ �����������:" << endl;
			cin >> IndexP2;

			vector[EmptyIdx] = vector[IndexP1 - 1] - vector[IndexP2 - 1];
			EmptyIdx++;
			cout << "���������: " << vector[EmptyIdx - 1] << endl;

			break;
		case 4:
			cout << "������� ����� ��������:" << endl;
			cin >> IndexP1;
			cout << "������� �����:" << endl;
			cin >> Const;

			vector[EmptyIdx] = vector[IndexP1 - 1] * Const;
			EmptyIdx++;
			cout << "���������: " << vector[EmptyIdx - 1] << endl;
			break;
		case 5:
			PrintV(vector, EmptyIdx);
			break;

		case 6:
			vector.clear();
			EmptyIdx = 0;
			cout << "������ ������." << endl;
			break;
		case 7:
			return 0;
		default:
			cout << "�������� ����. ����������, ������� ����� �� 1 �� 8." << endl;
			break;
		}
	}
}