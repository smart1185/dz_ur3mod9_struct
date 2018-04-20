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

void generateDate(Date *date);
void genetrateName(char *name);
void genetrateName2(char *name2);
void genetrateNum(int *num);

struct TOVAR
{
	char *prodName;
	int *Qnt;
	double *Price;
	Date *date;
};

void SPISOK(char *productN);
void generateDateAr(Date *date);
void generateQnt(int *qnt);
void generatePrice(double *price);
double MediumPrice(double *sum, int length);
TOVAR * generateTOVAR(int *length);
void tenMon(TOVAR *tovar, int length);
void printInfo(TOVAR *tovar);

//void sortSpisok(TOVAR *price, int length);
//
//void TenMon(Date *dat, int length);


struct MARSHRUT
{
	int *mNum;
	char *Orign;
	char *Arrival;
	int *mLength;
};
void genOrign(char *orign);
void genAr(char *arrival);
MARSHRUT * generateMARSH(int *length);
void printInfoMar(MARSHRUT *m);
void searchMarch(MARSHRUT *m, int *length);
void MaxLengthMarch(MARSHRUT *m, int *length);
