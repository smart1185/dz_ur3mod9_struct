#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)


struct Date
{
	int *day;
	int *month;
	int *year;
};
struct NOTE1
{
	char *fName;
	char *sName;
	int *TELE;
	Date *date;
};

void generateDate(Date *date)
{
	date->day = (int*)malloc(sizeof(int));
	date->month = (int*)malloc(sizeof(int));
	date->year = (int*)malloc(sizeof(int));

	*date->day = 1 + rand() % 31;
	*date->month = 1 + rand() % 12;
	*date->year = 1950 + rand() % 60;
}
void genetrateName(char *name)
{
	char *nam[] = { "Иванов","Иванов","Петров", "Гробовский",
		"Чумабеков", "Кукерман", "Крузенштерн", "Зилипукин" };
	strcpy(name, nam[rand() % 8]);
}
void genetrateName2(char *name2)
{
	char *nam2[] = { "И.И","Е.П","П.Н", "А.О" };
	strcpy(name2, nam2[rand() % 4]);
}
void genetrateNum(int *num)
{
	*num = 70150000 + rand() % 10000;
}


struct TOVAR
{
	char *prodName;
	int *Qnt;
	double *Price;
	Date *date;
};

void SPISOK(char *productN)
{
	char *pro[] = { "Рубашка", "Штаны", "Куртка", "Ботинки", "Пиджак", "Кофта", "Трусы" };
	strcpy(productN, pro[rand() % 7]);
}
void generateDateAr(Date *date)
{
	date->day = (int*)malloc(sizeof(int));
	date->month = (int*)malloc(sizeof(int));
	date->year = (int*)malloc(sizeof(int));

	*date->day = 1 + rand() % 31;
	*date->month = 1 + rand() % 12;
	*date->year = 2016 + rand() % 3;
}
double MediumPrice(double *sum, int length)
{
	return *sum / length;
}
void generateQnt(int *qnt)
{
	*qnt = rand() % 99 + 1;
}
void generatePrice(double *price)
{
	*price = rand() % 7000 * 1.33;
}
void printInfo(TOVAR *tovar)
{
	printf("******************************************\n");
	printf("Наименование: %s\n", tovar->prodName);
	printf("Количество: %d\n", *tovar->Qnt);
	printf("Стоимость: %4.2f\n", *tovar->Price);
	printf("Дата поступления: %d.%d.%d\n",
		*tovar->date->day,
		*tovar->date->month,
		*tovar->date->year);
}

//void sort(TOVAR* p, int length) {
//	double tmp, tmp2, tmp3, tmp4;
//	for (int i = 0; i < length - 1; i++) {
//		for (int j = 0; j < length - i; j++) 
//		/*{
//			if (*(p+j)->Price > *(p+(j + 1))->Price)
//				swap(*(p+j), *(p+(j+1)));
//		}*/
//	}
//}


TOVAR * generateTOVAR(int *length)
{
	TOVAR *tov = (TOVAR*)malloc(sizeof(TOVAR) * *length);
	double sum = 0;
	if (tov != NULL)
	{
		for (size_t i = 0; i < *length; i++)
		{
			(tov + i)->prodName = (char*)malloc(sizeof(char) * 7);
			SPISOK((tov + i)->prodName);

			(tov + i)->Qnt = (int*)malloc(sizeof(int));
			generateQnt((tov + i)->Qnt);

			(tov + i)->Price = (double*)malloc(sizeof(double));
			generatePrice((tov + i)->Price);

			(tov + i)->date = (Date*)malloc(sizeof(Date));
			generateDateAr((tov + i)->date);
			sum += *(tov + i)->Price;
		}
	}

	return tov;
}
void tenMon(TOVAR *tovar, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		if (*tovar->date->year <= 2017)
			printInfo(tovar);
		tovar++;
	}
}
void generateYear(int *year)
{
	*year = 2016 + rand() % 2;
}


struct MARSHRUT
{
	int *mNum;
	char *Orign;
	char *Arrival;
	int *mLength;
};
void genOrign(char *orign)
{
	char * or [] = { "Барахолка", "Орбита", "Аксай", "Каскелен", "Талгар", "Алмагуль", "ЦПКиО" };
	strcpy(orign, or [rand() % 7]);
}
void genAr(char *arrival)
{
	char * ar[] = { "Мега", "Думан", "Аэропорт", "Сайран", "Вокзал", "АДК", "Таугуль" };
	strcpy(arrival, ar[rand() % 7]);
}
MARSHRUT * generateMARSH(int *length)
{
	MARSHRUT *m = (MARSHRUT*)malloc(sizeof(MARSHRUT) * *length);
	if (m != NULL)
	{
		for (size_t i = 0; i < *length; i++)
		{
			(m + i)->mNum = (int*)malloc(sizeof(int));
			generateQnt((m + i)->mNum);

			(m + i)->Orign = (char*)malloc(sizeof(char) * 7);
			genOrign((m + i)->Orign);

			(m + i)->Arrival = (char*)malloc(sizeof(char) * 7);
			genAr((m + i)->Arrival);

			(m + i)->mLength = (int*)malloc(sizeof(int));
			generateQnt((m + i)->mLength);
		}
	}

	return m;
}
void printInfoMar(MARSHRUT *m)
{
	printf("******************************************\n");
	printf("№ маршрута: %d\n", *m->mNum);
	printf("Маршрут: : %s-----%s\n", m->Orign, m->Arrival);
	printf("Длина: %d\n", *m->mLength);

}
void searchMarch(MARSHRUT *m, int *length)
{
	char point[20];
	int chk = 0;
	printf("\nВведите пункт:\n");
	scanf("%s", point);
	for (size_t i = 0; i < *length; i++)
	{
		if (!strcmp((m + i)->Orign, point) || !strcmp((m + i)->Arrival, point))
		{
			printInfoMar(m + i);
			chk = 1;
		}
	}
	if (chk == 0)
		printf("Нет информации\n");
}

void MaxLengthMarch(MARSHRUT *m, int *length)
{
	int max = *m->mLength;
	int index;
	printf("\n==============================\n");
	printf("\nМаршрут с максимальной длиной:\n");
	printf("\n==============================\n");
	for (size_t i = 0; i < *length; i++)
	{
		if (*(m + i)->mLength >= max)
		{
			max = *(m + i)->mLength;
			index = i;
		}
	}
	printInfoMar(m + index);
}


struct ABON
{
	char FIO;
	int nomer;
	Date *date;
	int *sumNach;
	int *sumSchet;
};