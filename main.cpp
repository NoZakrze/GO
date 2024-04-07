#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
#include"functions.h"
int main() {
    bool koniec_gry = 0;
    settitle("Norbert, Zakrzewski, 193391");
    _setcursortype(_NOCURSOR);
    do
    {
        unsigned char **tab, **tab_1, **tab_2;
        int znak = 0, rozmiar_w_prawo = 0, rozmiar_w_dol = 0, wynik_bialego = 0, wynik_czarnego = 0;
        int* wskaznik_rozmiar_w_prawo = &rozmiar_w_prawo,*wskaznik_rozmiar_w_dol = &rozmiar_w_dol;
        int Kursor_X = PlanszaX, Kursor_Y = PlanszaY, zn = 0, runda = Runda_Czarnego;
        int* wskaznik_Kursor_X = &Kursor_X,*wskaznik_Kursor_Y = &Kursor_Y, *wsk_rundy= &runda;
        unsigned char swoj_kamien, przeciwny_kamien;
        unsigned char *w_swoj_k=&swoj_kamien, *w_przeciwny_k=&przeciwny_kamien;
        int *wsk_wynik_B =& wynik_bialego, *wsk_wynik_C =& wynik_czarnego;

        Wybor_Rozmiaru(*wskaznik_rozmiar_w_prawo, *wskaznik_rozmiar_w_dol);
        tab=stworz_tablice(rozmiar_w_prawo,rozmiar_w_dol);
        tab_1=stworz_tablice(rozmiar_w_prawo,rozmiar_w_dol);
        tab_2=stworz_tablice(rozmiar_w_prawo,rozmiar_w_dol);
        Stworz_Plansze(tab, rozmiar_w_dol, rozmiar_w_prawo);
        Stworz_Plansze(tab_1, rozmiar_w_dol, rozmiar_w_prawo);
        Stworz_Plansze(tab_2, rozmiar_w_dol, rozmiar_w_prawo);

        wybor_handicupa(tab,*wskaznik_Kursor_X,*wskaznik_Kursor_Y,*wskaznik_rozmiar_w_prawo,*wskaznik_rozmiar_w_dol, *wsk_rundy);
        przepisz_tablice(tab,tab_2,rozmiar_w_prawo,rozmiar_w_dol);
        przepisz_tablice(tab,tab_1,rozmiar_w_prawo,rozmiar_w_dol);

        while (zn != 'q' && zn != 'n')
        {
            kogo_runda(*wsk_rundy, *w_swoj_k, *w_przeciwny_k);
            przerysuj_plansze(tab,rozmiar_w_dol,rozmiar_w_prawo, Kursor_X, Kursor_Y, wynik_bialego,wynik_czarnego);
            zn = getch();
            if (zn == 'q')
            {
                koniec_gry = 1;
                free(tab);
                free(tab_1);
                free(tab_2);
                Koniec_gry();
            }
            if (zn == 'n')
            {
                free(tab);
                free(tab_1);
                free(tab_2);
            }
            ruszanie_strzalkami(zn,*wskaznik_Kursor_X,*wskaznik_Kursor_Y,tab,*wskaznik_rozmiar_w_prawo,*wskaznik_rozmiar_w_dol);
            if (zn == 'i')
            {
               stawianie_kamienia(tab, tab_1, tab_2, Kursor_X, Kursor_Y, rozmiar_w_prawo, rozmiar_w_dol, *wsk_rundy, swoj_kamien, przeciwny_kamien, wynik_bialego, wynik_czarnego, *wsk_wynik_B, *wsk_wynik_C);
            }
            if(zn=='s')
            {
               zapis ( rozmiar_w_prawo , rozmiar_w_dol,  wynik_bialego, wynik_czarnego, runda, tab,  tab_1,  tab_2);
            }
            if(zn=='l')
            {
                char nazwa[50];
                nazwa_pliku(nazwa);
                FILE * f = fopen( nazwa, "r" );
                fscanf(f,"%d",&rozmiar_w_prawo);
                fscanf(f,"%d",&rozmiar_w_dol);
                fscanf(f,"%d",&wynik_bialego);
                fscanf(f,"%d",&wynik_czarnego);
                fscanf(f,"%d",&runda);
                free(tab);
                free(tab_1);
                free(tab_2);
                tab=stworz_tablice(rozmiar_w_prawo,rozmiar_w_dol);
                tab_1=stworz_tablice(rozmiar_w_prawo,rozmiar_w_dol);
                tab_2=stworz_tablice(rozmiar_w_prawo,rozmiar_w_dol);
                for(int i=0;i<rozmiar_w_dol;i++)
                {
                    for(int j=0;j<rozmiar_w_prawo;j++)
                        fscanf(f,"%hhu",&tab[i][j]);
                }
                for(int i=0;i<rozmiar_w_dol;i++)
                {
                    for(int j=0;j<rozmiar_w_prawo;j++)
                        fscanf(f,"%hhu",&tab_1[i][j]);
                }
                for(int i=0;i<rozmiar_w_dol;i++)
                {
                    for(int j=0;j<rozmiar_w_prawo;j++)
                        fscanf(f,"%hhu",&tab_2[i][j]);
                }
                fclose(f);
                Kursor_X=PlanszaX;
                Kursor_Y=PlanszaY;
            }
        }
    } while (koniec_gry == 0);
    _setcursortype(_NORMALCURSOR);
    return 0;
}
