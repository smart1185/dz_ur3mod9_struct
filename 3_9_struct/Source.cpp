#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include <ctime>
#include <string.h>

#include "Header.h"



#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)


using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int  N;
	do
	{
		printf("\t\t----������� ����� �������: ");
		scanf_s("%d", &N);
		cin.get();
		printf("\n");
		switch (N)
		{
		case 1:
			/*1.������� ��������� � ������ NOTE1, ���������� ����:
			a.	Name � ������� � ��������
			b.	TELE � ����� ��������
			c.	DATE � ���� �������� (���, �����, �����)

			�������� ���������, �����������:
			�	���� � ���������� ������ � ������ BLOCK, ��������� �� 9 ��������� ���� NOTE1, ������ ������ ����
			����������� �� ���������;
			�	����� �� ����� ���������� � �����, ��� ��� �������� ���������� �� �����, �������� �������� �������
			� ����������; ���� ������ �������� ��� � ������ ���������.*/
		{
			NOTE1 *BLOCK = (NOTE1*)malloc(sizeof(NOTE1) * 8);
			int mon = 0, flag = 0;
			if (BLOCK != NULL)
			{
				for (size_t i = 0; i < 8; i++)
				{
					(BLOCK + i)->fName = (char*)malloc(sizeof(char) * 8);
					(BLOCK + i)->sName = (char*)malloc(sizeof(char) * 4);
					(BLOCK + i)->TELE = (int*)malloc(sizeof(int));
					(BLOCK + i)->date = (Date*)malloc(sizeof(Date));

					/*scanf("%s", (BLOCK + i)->fName);*/genetrateName((BLOCK + i)->fName);
					/*scanf("%s", (BLOCK + i)->sName);*/genetrateName2((BLOCK + i)->sName);
					generateDate((BLOCK + i)->date);
					genetrateNum((BLOCK + i)->TELE);
				}
				printf("������� �����:\n");
				scanf("%d", &mon);
				printf("\----------------------------------------\n");
				for (size_t i = 0; i < 8; i++)
				{
					if (*(BLOCK + i)->date->month == mon)
					{
						printf("�.�.�: %s %s\n", (BLOCK + i)->fName, (BLOCK + i)->sName);
						printf("� ��������: %d\n", *(BLOCK + i)->TELE);
						printf("���� ��������: %d.%d.%d\n",
							*(BLOCK + i)->date->day,
							*(BLOCK + i)->date->month,
							*(BLOCK + i)->date->year);
						printf("******************************************\n");
						flag = 1;
					}
				}
				if (flag == 0)
					printf("������ �������� ���\n");

				printf("\----------------------------------------\n");
			}
			free(BLOCK);
		}
		printf("\n");
		break;

		case 2:
			/*2.������� ��������� � ������ TOVAR, ���������� ����:
			a.	�������� ������;
			b.	���������� ������ ������;
			c.	��������� ������;
			d.	���� ����������� ������ � ���� ��������� (���, �����, ����).

			�������� �������:
			�	�������� ������� SPISOK �� ����� ��� �� 10 ������� (��������) ������ � ������� (���� ������ � ����������);
			�	���������� ������� ��������� ������;
			�	������������ ������� �� ����������� ��������� �������;
			�	������ �������� � �������, ����������� ����� 10 ������� �����.
			*/
		{
			int length = 10;
			double temp, sum = 0;
			TOVAR *tovar = generateTOVAR(&length);
			for (size_t i = 0; i < length; i++)
				printInfo(tovar + i);
			printf("\n�������� � �������, ����������� ����� 10 ������� �����:\n");
			tenMon(tovar, length);
			printf("\n--------------------------------------------------------\n");
			printf("������� ���������: %4.2f\n", MediumPrice(&sum, length));

		}
		printf("\n");
		break;

		case 3:
			/*3.	������� ��������� � ������ MARSHRUT, ���������� ����:
			a.	����� ��������;
			b.	��������� ����� ��������;
			c.	�������� ����� ��������;
			d.	����� ��������.
			�������� �������:
			�	�������� ������� �� ����� ��� �� 10 ������� (��������) �������� � ��������� (���� ������ � ����������);
			�	����������� �������� � ������������ ������;
			�	������������ ������� �� ����������� ������� ���������;
			�	������ �������� � ���������, ������� ���������� ��� ������������� � ������, �������� �������� �������� �
			����������.*/
		{
			int length = 4;
			MARSHRUT *mar = generateMARSH(&length);
			for (size_t i = 0; i < length; i++)
			{
				printInfoMar(mar + i);
			}
			MaxLengthMarch(mar, &length);
			searchMarch(mar, &length);
		}
		printf("\n");
		break;


		default: {printf("������� � ����� ������� �� ����������\n"); }
		}
	} while (N > 0 && N < 3);
	printf("\t\t\t\t\t�����.\n");
	system("pause");
}