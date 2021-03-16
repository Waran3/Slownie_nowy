/* Kwota s³ownie (PL) ver 1.2.0 do wartoœci 9999.99 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> 


char* jednosci[] = { "zero", "jeden","dwa", "trzy","cztery", "piêæ", "szeœæ", "siedem", "osiem", "dziewiêæ" };
char* nascie[] = { "jedenaœcie", "dwanaœcie", "trzynaœcie", "czternaœcie","piêtnaœcie","szesnaœcie","siedemnaœcie","osiemnaœcie", "dziewiêtnaœcie" };
char* dziesiatki[] = { "dziesiêæ","dwadzieœcia","trzydzieœci", "czterdzieœci", "piêædziesi¹t", "szeœædziesi¹t", "siedemdziesi¹t", "osiemdziesi¹t","dziewiêædziesi¹t" };
char* setki[] = { "sto", "dwieœcie", "trzysta", "czterysta", "piêæset", "szeœæset", "siedemset", "osiemset","dziewiêæset" };
char* tysiace[] = { "tysi¹c", "tysi¹ce","tysiêcy" };
char* grosze[] = { "grosz","grosze", "groszy" };
char* zlote[] = { "z³oty","z³ote","z³otych" };

double kwota;
double kwota2;
char kwota_char[20];


int i, j, d, u, t, cz, zl, gr, p;
int ilosc_cyfr, ilosc, ilosc_cyfr_ulamek;

int pierwsza_cyfra, druga_cyfra, trzecia_cyfra, czwarta_cyfra, piata_cyfra, szosta_cyfra, siodma_cyfra, osma_cyfra; dziewiata_cyfra;
int pierwsza_cyfra_u, druga_cyfra_u;

int czesc_calkowita, cz_c, cz_u;
long long czesc_ulamkowa; // long long ze wzgledu na wielkoœæ liczby ( od 9 cyfr)
int c, licznik, licznik_2, c_u;

void zero(void);
void jednosci_(void);
void dziesiatki_(void);
void setki_(void);
void tysiace_(void);
void grosze_(void);

double atof_plus(char kwota[]);




int main(void)
{
    setlocale(LC_ALL, "polish"); // w³aczenie polskich znaków
    printf("Podaj kwotê ( aktualnie przedzia³ 0-9999.99z³ ) =");
    setlocale(LC_ALL, "en-US"); // w³aczenie znaków USA ( w³aczenie kropki  dziesiêtnej) 
    scanf("%s", kwota_char); // kwota wejœciowa
    double zmienna;
    zmienna = atof_plus(kwota_char); // zamiana znaku 


    kwota = zmienna;

    setlocale(LC_ALL, "polish"); // lokalizacja - Polska (ponowne w³¹czenie polskich znaków)

    if (kwota > 9999.99 || kwota < 0)
    {
        printf("Kwota poza dozwolonym zakresem !!!");
        goto stop;
    }
    //printf("kwota na poczatku %Lf\n", kwota);
    //printf("\n");

    czesc_calkowita = (int)kwota;                       //czêœæ ca³kowita
    cz_c = czesc_calkowita;
    //printf("Czesc calkowita %d\n", czesc_calkowita);

    czesc_ulamkowa = kwota * 100;                     //czêœæ u³amkowa
                                                                               //printf("Czesc ulamkowa *100 = %lld\n", czesc_ulamkowa);
    czesc_ulamkowa %= 100;   //sama reszta ulamkowa z dzielenia ( modulo)
    cz_u = czesc_ulamkowa;
    //printf("Czesc ulamkowa %%100 = %lld\n", czesc_ulamkowa);


    //printf("kwota %f\n", kwota);
    //printf("\n");

    for (i = 0; kwota >= 1; i++) // pêtla sprawdzaj¹ca iloœc cyfr w czesci ca³kowitej
        kwota = kwota / 10;

    ilosc_cyfr = i;
    //printf("Ilosc cyfr = %d\n", ilosc_cyfr); //ilosc cyfr
    //printf("\n"); 

    licznik = ilosc_cyfr;

    for (i = 1; i <= ilosc_cyfr; i++)  //pêtla generuj¹ca kolejne cyfry, liczby "kwota". 
    {
        c = cz_c % 10;
        cz_c = cz_c / 10;



        if (licznik == 1)        //przypisywanie zmiennym poszczegolnych cyfr, kolejnych wartoœci.
            pierwsza_cyfra = c;
        if (licznik == 2)
            druga_cyfra = c;
        if (licznik == 3)
            trzecia_cyfra = c;
        if (licznik == 4)
            czwarta_cyfra = c;
        if (licznik == 5)
            piata_cyfra = c;
        if (licznik == 6)
            szosta_cyfra = c;
        if (licznik == 7)
            siodma_cyfra = c;
        if (licznik == 8)
            osma_cyfra = c;
        if (licznik == 9)
            dziewiata_cyfra = c;

        licznik--;



    }

    //printf(" Wszystkie cyfry diesietne  %d %d %d %d %d %d %d %d %d\n", pierwsza_cyfra, druga_cyfra, trzecia_cyfra, czwarta_cyfra, piata_cyfra, szosta_cyfra, siodma_cyfra, osma_cyfra, dziewiata_cyfra);


    if (czesc_ulamkowa < 10)
        licznik_2 = 1;
    else
        licznik_2 = 0;

    for (i = licznik_2; czesc_ulamkowa >= 1; i++)       // pêtla sprawdzaj¹ca iloœc cyfr w czesci u³amkowej 
        czesc_ulamkowa = czesc_ulamkowa / 10;

    ilosc_cyfr_ulamek = i;
    licznik = ilosc_cyfr_ulamek;

    for (i = 1; i <= ilosc_cyfr_ulamek; i++)  //pêtla generuj¹ca kolejne cyfry z wartosci czesci ulamkowej (grosze) 
    {
        c_u = cz_u % 10;
        cz_u = cz_u / 10;

        if (licznik == 1)        //przypisywanie zmiennym poszczegolnych cyfr, kolejnych wartoœci.
            pierwsza_cyfra_u = c_u;
        if (licznik == 2)
            druga_cyfra_u = c_u;

        licznik--;
    }
    //printf(" Wszystkie cyfry po przecinku %d %d\n", pierwsza_cyfra_u, druga_cyfra_u);

    /*printf("\n");
    printf("\n");
    printf("Posiadane informacje kluczowe\n");
    printf("\n");
    printf("Ilosc cyfr dziesietnych = %d\n", ilosc_cyfr);
    printf("\n");
    printf("Wszystkie cyfry diesietne  %d %d %d %d %d %d %d %d %d\n",
        pierwsza_cyfra, druga_cyfra, trzecia_cyfra, czwarta_cyfra, piata_cyfra,
        szosta_cyfra, siodma_cyfra, osma_cyfra, dziewiata_cyfra);
    printf("\n");
    printf("Wszystkie cyfry po przecinku %d %d\n", pierwsza_cyfra_u, druga_cyfra_u);
    printf("Ilosc cyfr w ulamku = %d\n", ilosc_cyfr_ulamek);
    printf("\n");*/


    // Czêœæ ca³kowita - POCZ¥TEK **********************************************************

    zero();
    jednosci_();
    dziesiatki_();
    setki_();
    tysiace_();

    // Czêœæ u³amkowa(grosze) POCZATEK *****************************************************
    grosze_();

    //printf("pierwsza_cyfra_u = %d druga_cyfra_u = %d\n", pierwsza_cyfra_u, druga_cyfra_u);


stop:;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Program zakoñczy³ dzia³anie");
    printf("\n");
    printf("\n");
    printf("\n");

    return 0;
}

void zero()
{
    if (ilosc_cyfr == 0) // zero <-----------------
    {
        j = 0;
        zl = 2;
        printf("%s %s ", jednosci[j], zlote[zl]);
    }

}

void jednosci_()
{
    if (ilosc_cyfr == 1)  // jednoœci <-------------------
    {
        j = pierwsza_cyfra;
        if (pierwsza_cyfra == 1)
            zl = 0;
        if (pierwsza_cyfra > 1 && pierwsza_cyfra < 5)
            zl = 1;
        if (pierwsza_cyfra >= 5)
            zl = 2;
        printf("%s %s ", jednosci[j], zlote[zl]);
    }
}

void dziesiatki_()
{
    // 2 cyfry ( pe³ne  dziesi¹tki ) 

    if (ilosc_cyfr == 2 && pierwsza_cyfra != 0 && druga_cyfra == 0) // pe³ne dziesi¹tki (10,20...90) <-------------------

    {
        d = pierwsza_cyfra - 1;
        zl = 2;
        printf("%s %s ", dziesiatki[d], zlote[zl]);
    }

    // 2 cyfry ( naœcie ) 

    if (ilosc_cyfr == 2 && pierwsza_cyfra == 1 && druga_cyfra != 0) // naœcie (11 - 19) <-----------------
    {
        d = druga_cyfra - 1;
        zl = 2;
        printf("%s %s ", nascie[d], zlote[zl]);
    }

    // 2 cyfry ( dziesi¹tki i jednoœci ) 
    if (ilosc_cyfr == 2 && pierwsza_cyfra != 0 && pierwsza_cyfra != 1 && druga_cyfra != 0) //21 - 99 < ---------------------

    {
        p = pierwsza_cyfra - 1;
        d = druga_cyfra;
        if (druga_cyfra == 1)
            zl = 2;
        if (druga_cyfra > 1 && druga_cyfra < 5)
            zl = 1;
        if (druga_cyfra >= 5)
            zl = 2;
        printf("%s %s %s ", dziesiatki[p], jednosci[d], zlote[zl]);
    }
}

void setki_()
{
    // 3 cyfry ( setki ) ++++++++++ pocz¹tek

    if (ilosc_cyfr == 3 && pierwsza_cyfra != 0 && druga_cyfra == 0 && trzecia_cyfra == 0) //pe³ne setki (100-900) < ---------------------
    {
        p = pierwsza_cyfra - 1;
        zl = 2;
        printf("%s %s ", setki[p], zlote[zl]);
    }

    if (ilosc_cyfr == 3 && pierwsza_cyfra != 0 && druga_cyfra <= 1 && trzecia_cyfra != 0) // (101-119) < ---------------------
    {
        if (druga_cyfra == 0) // do 109 (jednoœci)
        {
            p = pierwsza_cyfra - 1;
            t = trzecia_cyfra;

            if (trzecia_cyfra == 1)
                zl = 2;
            if (trzecia_cyfra > 1 && trzecia_cyfra < 5)
                zl = 1;
            if (trzecia_cyfra >= 5)
                zl = 2;
            printf("%s %s %s ", setki[p], jednosci[t], zlote[zl]);
        }

        if (druga_cyfra == 1) // naœcie (111 - 919)
        {
            p = pierwsza_cyfra - 1;
            d = trzecia_cyfra - 1;
            zl = 2;
            printf("%s %s %s ", setki[p], nascie[d], zlote[zl]);
        }
    }


    if (ilosc_cyfr == 3 && druga_cyfra != 0 && druga_cyfra != 1 && trzecia_cyfra != 0) // 121 - 999 ( bez naœcie, dziesi¹tek i setek) 
    {
        p = pierwsza_cyfra - 1;
        d = druga_cyfra - 1;
        t = trzecia_cyfra;

        if (trzecia_cyfra == 1)
            zl = 2;
        if (trzecia_cyfra > 1 && trzecia_cyfra < 5)
            zl = 1;
        if (trzecia_cyfra >= 5)
            zl = 2;
        printf("%s %s %s %s ", setki[p], dziesiatki[d], jednosci[t], zlote[zl]);
    }

    if (ilosc_cyfr == 3 && druga_cyfra != 0 && trzecia_cyfra == 0) // 120, 130...990 (  pe³ne dziesi¹tki) 

    {
        p = pierwsza_cyfra - 1;
        d = druga_cyfra - 1;
        zl = 2;


        printf("%s %s %s ", setki[p], dziesiatki[d], zlote[zl]);
    }

    // 3 cyfry ++++++++++ KONIEC

}
void tysiace_()
{
    // 4 cyfry (tysi¹ce) ++++++++++ POCZ¥TEK

    if (ilosc_cyfr == 4 && pierwsza_cyfra != 0 && druga_cyfra == 0 && trzecia_cyfra == 0 && czwarta_cyfra == 0) //  Pe³ne  1000 ...9000 <-------------------

    {
        cz = czwarta_cyfra;
        p = pierwsza_cyfra;
        zl = 2;


        if (pierwsza_cyfra == 1)
            t = 0;
        if (pierwsza_cyfra > 1 && pierwsza_cyfra < 5)
            t = 1;
        if (pierwsza_cyfra >= 5)
            t = 2;

        printf("%s %s %s ", jednosci[p], tysiace[t], zlote[zl]);

    }


    if (ilosc_cyfr == 4 && druga_cyfra == 0 && trzecia_cyfra == 0 && czwarta_cyfra > 0) //  jednoœci 1001 ...9009 <-------------------

    {
        cz = czwarta_cyfra;
        p = pierwsza_cyfra;

        if (czwarta_cyfra == 1)
            zl = 0;
        if (czwarta_cyfra > 1 && czwarta_cyfra < 5)
            zl = 1;
        if (czwarta_cyfra >= 5)
            zl = 2;

        if (pierwsza_cyfra == 1)
            t = 0;
        if (pierwsza_cyfra > 1 && pierwsza_cyfra < 5)
            t = 1;
        if (pierwsza_cyfra >= 5)
            t = 2;

        printf("%s %s %s %s ", jednosci[p], tysiace[t], jednosci[cz], zlote[zl]);

    }

    if (ilosc_cyfr == 4 && druga_cyfra == 0 && trzecia_cyfra == 1 && czwarta_cyfra > 0) //  naœcie 1011 ...9019 <-------------------
    {
        cz = czwarta_cyfra - 1;
        p = pierwsza_cyfra;

        zl = 2;

        if (pierwsza_cyfra == 1)
            t = 0;
        if (pierwsza_cyfra > 1 && pierwsza_cyfra < 5)
            t = 1;
        if (pierwsza_cyfra >= 5)
            t = 2;

        printf("%s %s %s %s ", jednosci[p], tysiace[t], nascie[cz], zlote[zl]);
    }

    if (ilosc_cyfr == 4 && druga_cyfra == 0 && trzecia_cyfra != 0 && czwarta_cyfra == 0) //  dziesi¹tki  1010,1020 ...9090 <-------------------
    {
        t = trzecia_cyfra - 1;
        p = pierwsza_cyfra;

        zl = 2;

        if (pierwsza_cyfra == 1)
            u = 0;
        if (pierwsza_cyfra > 1 && pierwsza_cyfra < 5)
            u = 1;
        if (pierwsza_cyfra >= 5)
            u = 2;

        printf("%s %s %s %s ", jednosci[p], tysiace[u], dziesiatki[t], zlote[zl]);
    }

    if (ilosc_cyfr == 4 && druga_cyfra == 0 && trzecia_cyfra > 1 && czwarta_cyfra != 0) //  1021...9099 bez jednoœci, dziesi¹tek i naœcie <-------------------
    {
        t = trzecia_cyfra - 1;
        p = pierwsza_cyfra;
        cz = czwarta_cyfra;

        if (czwarta_cyfra == 1)
            zl = 0;
        if (czwarta_cyfra > 1 && czwarta_cyfra < 5)
            zl = 1;
        if (czwarta_cyfra >= 5)
            zl = 2;

        if (pierwsza_cyfra == 1)
            u = 0;
        if (pierwsza_cyfra > 1 && pierwsza_cyfra < 5)
            u = 1;
        if (pierwsza_cyfra >= 5)
            u = 2;

        printf("%s %s %s %s %s ", jednosci[p], tysiace[u], dziesiatki[t], jednosci[cz], zlote[zl]);
    }

    if (ilosc_cyfr == 4 && druga_cyfra > 0 && trzecia_cyfra > 1 && czwarta_cyfra != 0) //  1121...9999 bez jednoœci, dziesi¹tek i naœcie <-------------------
    {
        p = pierwsza_cyfra;
        d = druga_cyfra - 1;
        t = trzecia_cyfra - 1;
        cz = czwarta_cyfra;

        if (czwarta_cyfra == 1)
            zl = 0;
        if (czwarta_cyfra > 1 && czwarta_cyfra < 5)
            zl = 1;
        if (czwarta_cyfra >= 5)
            zl = 2;

        if (pierwsza_cyfra == 1)
            u = 0;
        if (pierwsza_cyfra > 1 && pierwsza_cyfra < 5)
            u = 1;
        if (pierwsza_cyfra >= 5)
            u = 2;

        printf("%s %s %s %s %s %s ", jednosci[p], tysiace[u], setki[d], dziesiatki[t], jednosci[cz], zlote[zl]);
    }

    if (ilosc_cyfr == 4 && druga_cyfra > 0 && trzecia_cyfra == 1 && czwarta_cyfra != 0) //  1111...9919 ( z nascie) bez jednoœci, dziesi¹tek <-------------------
    {
        p = pierwsza_cyfra;
        d = druga_cyfra - 1;
        t = trzecia_cyfra - 1;
        cz = czwarta_cyfra - 1;

        zl = 2;

        if (pierwsza_cyfra == 1)
            u = 0;
        if (pierwsza_cyfra > 1 && pierwsza_cyfra < 5)
            u = 1;
        if (pierwsza_cyfra >= 5)
            u = 2;

        printf("%s %s %s %s %s ", jednosci[p], tysiace[u], setki[d], nascie[cz], zlote[zl]);
    }

    if (ilosc_cyfr == 4 && druga_cyfra > 0 && trzecia_cyfra == 0 && czwarta_cyfra == 0) //  1100...9900  bez jednoœci i nascie <-------------------
    {
        p = pierwsza_cyfra;
        d = druga_cyfra - 1;
        t = trzecia_cyfra - 1;
        cz = czwarta_cyfra - 1;

        zl = 2;

        if (pierwsza_cyfra == 1)
            u = 0;
        if (pierwsza_cyfra > 1 && pierwsza_cyfra < 5)
            u = 1;
        if (pierwsza_cyfra >= 5)
            u = 2;

        printf("%s %s %s %s ", jednosci[p], tysiace[u], setki[d], zlote[zl]);
    }




    if (ilosc_cyfr == 4 && druga_cyfra > 0 && trzecia_cyfra > 0 && czwarta_cyfra == 0) //  1110...9910 ( z dziesi¹t) bez jednoœci i nascie <-------------------
    {
        p = pierwsza_cyfra;
        d = druga_cyfra - 1;
        t = trzecia_cyfra - 1;
        cz = czwarta_cyfra - 1;

        zl = 2;

        if (pierwsza_cyfra == 1)
            u = 0;
        if (pierwsza_cyfra > 1 && pierwsza_cyfra < 5)
            u = 1;
        if (pierwsza_cyfra >= 5)
            u = 2;

        printf("%s %s %s %s %s ", jednosci[p], tysiace[u], setki[d], dziesiatki[t], zlote[zl]);
    }

    if (ilosc_cyfr == 4 && druga_cyfra > 0 && trzecia_cyfra == 0 && czwarta_cyfra > 0) //  1101...9909 ( jednoœci ) bez dziesi¹tek i naœcie <-------------------
    {
        p = pierwsza_cyfra;
        d = druga_cyfra - 1;
        t = trzecia_cyfra - 1;
        cz = czwarta_cyfra;

        if (czwarta_cyfra == 0 || czwarta_cyfra > 4)
            zl = 2;
        else
            zl = 1;

        if (pierwsza_cyfra == 1)
            u = 0;
        if (pierwsza_cyfra > 1 && pierwsza_cyfra < 5)
            u = 1;
        if (pierwsza_cyfra >= 5)
            u = 2;

        printf("%s %s %s %s %s ", jednosci[p], tysiace[u], setki[d], jednosci[cz], zlote[zl]);
    }
    // 4 cyfry (tysi¹ce) ++++++++++ KONIEC
}
void grosze_()
{

    if (pierwsza_cyfra_u == 0 && druga_cyfra_u == 0) // zero <-----------------
    {
        u = 0;
        gr = 2;

        printf("%s %s \n", jednosci[u], grosze[gr]);
    }

    if (pierwsza_cyfra_u == 0 && druga_cyfra_u != 0)  // pojedyncze grosze <---------------------
    {

        u = druga_cyfra_u;
        if (druga_cyfra_u == 1)
            gr = 0;
        if (druga_cyfra_u > 1 && druga_cyfra_u < 5)
            gr = 1;
        if (druga_cyfra_u >= 5)
            gr = 2;

        printf("%s %s \n", jednosci[u], grosze[gr]);
    }
    if (pierwsza_cyfra_u != 0 && druga_cyfra_u == 0) // dziesi¹tki groszy <-----------------
    {

        u = pierwsza_cyfra_u - 1;
        gr = 2;

        printf("%s %s \n", dziesiatki[u], grosze[gr]);
    }
    if (pierwsza_cyfra_u == 1 && druga_cyfra_u != 0) // naœcie groszy ( 11-19 ) <-----------------
    {

        u = druga_cyfra_u - 1;
        gr = 2;

        printf("%s %s \n", nascie[u], grosze[gr]);
    }
    if (pierwsza_cyfra_u > 1 && druga_cyfra_u != 0) // 21-99 groszy, bez naœcie i dziesi¹tek <-----------------
    {

        u = pierwsza_cyfra_u - 1;
        j = druga_cyfra_u;

        if (druga_cyfra_u == 1)
            gr = 2;
        if (druga_cyfra_u > 1 && druga_cyfra_u < 5)
            gr = 1;
        if (druga_cyfra_u >= 5)
            gr = 2;

        printf("%s %s %s\n", dziesiatki[u], jednosci[j], grosze[gr]);
    }

    // Czêœæ u³amkowa - KONIEC **********************************************************     
}

double atof_plus(char kwota[])
{
    int ilosc_znakow = strlen(kwota); //d³ugoœæ ³añcucha ( kwota)

    for (int a = 0; a < ilosc_znakow; a++) // pêtla wyszukuj¹ca znak inny ni¿ cyfra
    {
        int znak = kwota[a];

        if (znak < 48 || znak > 57)
        {
            kwota[a] = '.'; // podmiana znaku dziesiêtnego na kropkê
        }
    }

    double kwota_po_zamianie = atof(kwota); //wartoœæ wynikowa
    return kwota_po_zamianie;
}