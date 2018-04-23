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
		printf("\t\t----Введите номер задания: ");
		scanf_s("%d", &N);
		cin.get();
		printf("\n");
		switch (N)
		{
		case 1:
			/*1.Описать структуру с именем NOTE1, содержащую поля:
			a.	Name – фамилия и инициалы
			b.	TELE – номер телефона
			c.	DATE – дата рождения (год, месяц, число)

			Написать программу, выполняющую:
			•	ввод с клавиатуры данных в массив BLOCK, состоящий из 9 элементов типа NOTE1, записи должны быть
			упорядочены по инициалам;
			•	вывод на экран информации о людях, чьи дни рождения приходятся на месяц, значение которого введено
			с клавиатуры; если такого человека нет – выдать сообщение.*/
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
				printf("Введите месяц:\n");
				scanf("%d", &mon);
				printf("\----------------------------------------\n");
				for (size_t i = 0; i < 8; i++)
				{
					if (*(BLOCK + i)->date->month == mon)
					{
						printf("Ф.И.О: %s %s\n", (BLOCK + i)->fName, (BLOCK + i)->sName);
						printf("№ телефона: %d\n", *(BLOCK + i)->TELE);
						printf("Дата рождения: %d.%d.%d\n",
							*(BLOCK + i)->date->day,
							*(BLOCK + i)->date->month,
							*(BLOCK + i)->date->year);
						printf("******************************************\n");
						flag = 1;
					}
				}
				if (flag == 0)
					printf("Такого человека нет\n");

				printf("\----------------------------------------\n");
			}
			free(BLOCK);
		}
		printf("\n");
		break;

		case 2:
			/*2.Описать структуру с именем TOVAR, содержащую поля:
			a.	название товара;
			b.	количество единиц товара;
			c.	стоимость товара;
			d.	дата поступления товара в виде структуры (год, месяц, день).

			Написать функции:
			•	создания массива SPISOK не более чем из 10 записей (структур) данных о товарах (ввод данных с клавиатуры);
			•	вычисления средней стоимости товара;
			•	расположения записей по возрастанию стоимости товаров;
			•	вывода сведений о товарах, поступивших более 10 месяцев назад.
			*/
		{
			int length = 10;
			double temp, sum = 0;
			TOVAR *tovar = generateTOVAR(&length);
			for (size_t i = 0; i < length; i++)
				printInfo(tovar + i);
			printf("\nСведения о товарах, поступивших более 10 месяцев назад:\n");
			tenMon(tovar, length);
			printf("\n--------------------------------------------------------\n");
			printf("Средняя стоимость: %4.2f\n", MediumPrice(&sum, length));

		}
		printf("\n");
		break;

		case 3:
			/*3.	Описать структуру с именем MARSHRUT, содержащую поля:
			a.	номер маршрута;
			b.	начальный пункт маршрута;
			c.	конечный пункт маршрута;
			d.	длина маршрута.
			Написать функции:
			•	создания массива не более чем из 10 записей (структур) сведений о маршрутах (ввод данных с клавиатуры);
			•	определения маршрута с максимальной длиной;
			•	расположения записей по возрастанию номеров маршрутов;
			•	вывода сведений о маршрутах, которые начинаются или заканчиваются в пункте, название которого вводится с
			клавиатуры.*/
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


		default: {printf("Задания с таким номером не существует\n"); }
		}
	} while (N > 0 && N < 3);
	printf("\t\t\t\t\tКОНЕЦ.\n");
	system("pause");
}