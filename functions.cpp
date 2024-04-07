#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
#include"functions.h"

void Reset_Konsoli()
{
    textbackground(BLACK);
    clrscr();
    textcolor(7);
}
void Legenda(int wsk_x,int wsk_y, int b, int c)
{
    gotoxy(LegendaX, LegendaY);
    cputs("Norbert Zakrzewski 193391");
    gotoxy(LegendaX, LegendaY+1);
    cputs("implemented functionalities: a,b,c,d,e,f,g,h,j,k");
    gotoxy(LegendaX, LegendaY+2);
    cputs("arrows: move");
    gotoxy(LegendaX, LegendaY+3);
    cputs("q: close the program");
    gotoxy(LegendaX, LegendaY+4);
    cputs("n: start a new game");
    gotoxy(LegendaX, LegendaY+5);
    cputs("enter: confirm the choice and end the player's turn");
    gotoxy(LegendaX, LegendaY+6);
    cputs("esc: cancel  the current action ");
    gotoxy(LegendaX, LegendaY+7);
    cputs("i: put a stone on the board");
    gotoxy(LegendaX, LegendaY+8);
    cputs("s: save the game");
    gotoxy(LegendaX, LegendaY+9);
    cputs("l: load the game");
    gotoxy(LegendaX, LegendaY+10);
    cputs("f: end the game");
    gotoxy(LegendaX, LegendaY+11);
    cputs("Current cursor position: ");
    char buffor_x[20],buffor_y[20], buffor_b[20], buffor_c[20];
    sprintf(buffor_x, "%d", wsk_x-PlanszaX);
    sprintf(buffor_y, "%d", wsk_y-PlanszaY);
    sprintf(buffor_b, "%d", b);
    sprintf(buffor_c, "%d",c);
    cputs(buffor_x);
    cputs(",");
    cputs(buffor_y);
    gotoxy(LegendaX, LegendaY + 12);
    cputs("White's score: ");
    cputs(buffor_b);
    gotoxy(LegendaX, LegendaY + 13);
    cputs("Black's score: ");
    cputs(buffor_c);
}
void Wybor_Planszy_Legenda()
{
    gotoxy(Wybor_PlanszyX, Wybor_PlanszyY);
    cputs("Select board size:");
    gotoxy(Wybor_PlanszyX, Wybor_PlanszyY+1);
    cputs("1) 19x19");
    gotoxy(Wybor_PlanszyX, Wybor_PlanszyY+2);
    cputs("2) 13x13");
    gotoxy(Wybor_PlanszyX, Wybor_PlanszyY+3);
    cputs("3) 9x9");
    gotoxy(Wybor_PlanszyX, Wybor_PlanszyY+4);
    cputs("4) Other");
}
void Narysuj_Plansze(unsigned char **t, int size_w_dol, int size_w_prawo, int x, int y)
{
    for(int i=0;i<size_w_dol;i++)
        {
            for(int j=0;j<size_w_prawo;j++)
            {
                gotoxy(PlanszaX+j,PlanszaY+i);
                putch(t[i][j]);
            }
        }
    gotoxy(RamkaX,RamkaY);
    putch(lewyGornyRog);
    for(int j=1;j<=size_w_prawo;j++)
    {
        gotoxy(RamkaX+j,RamkaY);
        putch(GoraRamki);
        gotoxy(RamkaX+j,RamkaY+size_w_dol+1);
        putch(GoraRamki);
    }
    gotoxy(RamkaX+size_w_prawo+1,RamkaY);
    putch(prawyGornyRog);
    for(int j=1;j<=size_w_dol;j++)
    {
        gotoxy(RamkaX+size_w_prawo+1,RamkaY+j);
        putch(BokRamki);
        gotoxy(RamkaX,RamkaY+j);
        putch(BokRamki);
    }
    gotoxy(RamkaX+size_w_prawo+1,RamkaY+size_w_dol+1);
    putch(prawyDolnyRog);
    gotoxy(RamkaX,RamkaY+size_w_dol+1);
    putch(lewyDolnyRog);
    gotoxy(x,y);
}
void Stworz_Plansze(unsigned char **t, int size_w_dol, int size_w_prawo)
{
    for(int i=0;i<size_w_dol;i++)
        {
            for(int j=0;j<size_w_prawo;j++)
            {
                t[i][j]=jaki_znak(i,j,size_w_dol,size_w_prawo);
            }
        }
}
void Kolorowanie_obecnego_punktu(int x, int y, unsigned char **t)
{
            gotoxy(x,y);
            textcolor(LIGHTBLUE);
            int znak=t[y-PlanszaY][x-PlanszaX];
            putch(znak);
            textcolor(BLACK);
}
void Koniec_gry()
{
    Reset_Konsoli();
    gotoxy(KoniecX,KoniecY);
    cputs("PROGRAM CLOSED");
    for(int i=1;i<7;i++)
    {
        gotoxy(KoniecX,KoniecY+i);
        insline();
    }
}
void Wybor_Rozmiaru(int &wsk_p, int &wsk_d)
{
    char znak=0;
    do {
            Reset_Konsoli();
            Wybor_Planszy_Legenda();
            znak = getch();
            if(znak=='1')
            {
               wsk_p=19;
               wsk_d=19;
            }
            if(znak=='2')
            {
               wsk_p=13;
               wsk_d=13;
            }
            if(znak=='3')
            {
               wsk_p=9;
               wsk_d=9;
            }
            if(znak=='4')
            {
                wybor_dowolnego_rozmiaru(wsk_p,wsk_d);
            }
           } while (znak<'1' || znak>'4');
}
void Strzalka_w_gore(int &wsk_x, int &wsk_y, unsigned char **t)
{
    if(wsk_y!=PlanszaY)
    {
        unsigned char znak=t[wsk_y-PlanszaY][wsk_x-PlanszaX];
        textcolor(BLACK);
        putch(znak);
        wsk_y-=1;
    }
}
void Strzalka_w_dol(int &wsk_x, int &wsk_y, unsigned char **t, int &roz)
{
    if(wsk_y!=PlanszaY+roz-1)
    {
        unsigned char znak=t[wsk_y-PlanszaY][wsk_x-PlanszaX];
        textcolor(BLACK);
        putch(znak);
        wsk_y+=1;
    }
}
void Strzalka_w_lewo(int &wsk_x, int &wsk_y, unsigned char **t)
{
    if(wsk_x!=PlanszaX)
    {
        unsigned char znak=t[wsk_y-PlanszaY][wsk_x-PlanszaX];
        textcolor(BLACK);
        putch(znak);
        wsk_x-=1;
    }
}
void Strzalka_w_prawo(int &wsk_x, int &wsk_y, unsigned char **t, int &roz)
{
    if(wsk_x!=PlanszaX+roz-1)
    {
        unsigned char znak=t[wsk_y-PlanszaY][wsk_x-PlanszaX];
        textcolor(BLACK);
        putch(znak);
        wsk_x+=1;
    }
}
bool zycia_kamienia(int index_i, int index_j, unsigned char swoj_kamien, unsigned char przeciwny_kamien, unsigned char **t, int &n, int rozmiar_prawo, int rozmiar_dol, int **poprzednie, int rozmiar_tablicy)
{
    poprzednie[n][0]=index_i;
    poprzednie[n][1]=index_j;
    n++;
    if(index_i>0)
    {
        if(t[index_i-1][index_j]!=swoj_kamien && t[index_i-1][index_j]!=przeciwny_kamien)
            return true;
        if(t[index_i-1][index_j]==swoj_kamien)
        {
            bool sprawdzone=0;
            for(int i=0;i<rozmiar_tablicy;i++)
            {
                if(poprzednie[i][0]==index_i-1 && poprzednie[i][1]==index_j)
                    sprawdzone=1;
            }
            if(sprawdzone==0)
            {
               if(zycia_kamienia(index_i-1,index_j,swoj_kamien,przeciwny_kamien,t,n,rozmiar_prawo,rozmiar_dol,poprzednie,rozmiar_tablicy)==1)
                   return true;
            }
        }
    }
    if(index_j<rozmiar_prawo-1)
    {
        if(t[index_i][index_j+1]!=swoj_kamien && t[index_i][index_j+1]!=przeciwny_kamien)
            return true;
        if(t[index_i][index_j+1]==swoj_kamien)
        {
            bool sprawdzone=0;
            for(int i=0;i<rozmiar_tablicy;i++)
            {
                if(poprzednie[i][0]==index_i && poprzednie[i][1]==index_j+1)
                    sprawdzone=1;
            }
            if(sprawdzone==0)
            {
              if(zycia_kamienia(index_i,index_j+1,swoj_kamien,przeciwny_kamien,t,n,rozmiar_prawo,rozmiar_dol,poprzednie,rozmiar_tablicy)==1)
                   return true;
            }
        }
    }
    if(index_i<rozmiar_dol-1)
    {
        if(t[index_i+1][index_j]!=swoj_kamien && t[index_i+1][index_j]!=przeciwny_kamien)
            return true;
        if(t[index_i+1][index_j]==swoj_kamien)
        {
            bool sprawdzone=0;
            for(int i=0;i<rozmiar_tablicy;i++)
            {
                if(poprzednie[i][0]==index_i+1 && poprzednie[i][1]==index_j)
                    sprawdzone=1;
            }
            if(sprawdzone==0)
            {
               if(zycia_kamienia(index_i+1,index_j,swoj_kamien,przeciwny_kamien,t,n,rozmiar_prawo,rozmiar_dol,poprzednie,rozmiar_tablicy)==1)
                   return true;
            }
        }
    }
    if(index_j>0)
    {
        if(t[index_i][index_j-1]!=swoj_kamien && t[index_i][index_j-1]!=przeciwny_kamien)
            return true;
        if(t[index_i][index_j-1]==swoj_kamien)
        {
            bool sprawdzone=0;
            for(int i=0;i<rozmiar_tablicy;i++)
            {
                if(poprzednie[i][0]==index_i && poprzednie[i][1]==index_j-1)
                    sprawdzone=1;
            }
            if(sprawdzone==0)
            {
               if(zycia_kamienia(index_i,index_j-1,swoj_kamien,przeciwny_kamien,t,n,rozmiar_prawo,rozmiar_dol,poprzednie,rozmiar_tablicy)==1)
                 return true;
            }
        }
    }
    return false;
}
unsigned char jaki_znak(int i, int j, int size_w_dol, int size_w_prawo)
{
            if(i==0 && j==0)
               return lewyGornyRog;
            else if(i==size_w_dol-1 && j==0)
                return lewyDolnyRog;
            else if(i==0 && j==size_w_prawo-1)
                return prawyGornyRog;
            else if(i==size_w_dol-1 && j==size_w_prawo-1)
                return prawyDolnyRog;
            else if(i==0)
                return gornyBok;
            else if(j==0)
                return lewyBok;
            else if(i==size_w_dol-1)
                return dolnyBok;
            else if(j==size_w_prawo-1)
                return prawyBok;
            else
                return przeciecie;
}
void zerowanie_tablicy (int **t, int rozmiar,int &w)
{
   w=0;
   for(int i=0;i<rozmiar;i++)
    {
        t[i][0]=-1;
        t[i][1]=-1;
    }
}
bool czy_mozna_postawic(int X, int Y, unsigned char kamien_1, unsigned char kamien_2, unsigned char **t, int &n,int size_p, int size_d, int **p, int size_tablicy)
{
        if (zycia_kamienia(Y - PlanszaY, X - PlanszaX, kamien_1, kamien_2, t, n, size_p, size_d, p, size_tablicy) == true)
            return true;
        if (Y != PlanszaY)
        {
            zerowanie_tablicy(p, size_tablicy, n);
            if (zycia_kamienia(Y - PlanszaY - 1, X - PlanszaX, kamien_2, kamien_1, t, n, size_p, size_d, p, size_tablicy) == 0)
                return true;
        }
        if (X - PlanszaX < size_p - 1)
        {
            zerowanie_tablicy(p, size_tablicy, n);
            if (zycia_kamienia(Y - PlanszaY, X - PlanszaX + 1, kamien_2, kamien_1, t, n, size_p, size_d, p, size_tablicy) == 0)
                return true;
        }
        if (Y - PlanszaY < size_d - 1)
        {
            zerowanie_tablicy(p, size_tablicy, n);
            if (zycia_kamienia(Y - PlanszaY + 1, X - PlanszaX, kamien_2, kamien_1, t, n, size_p, size_d, p, size_tablicy) == 0)
                return true;
        }
        if (X != PlanszaX)
        {
            zerowanie_tablicy(p, size_tablicy, n);
            if (zycia_kamienia(Y - PlanszaY, X - PlanszaX - 1, kamien_2, kamien_1, t, n, size_p, size_d, p, size_tablicy) == 0)
                return true;
        }
        return false;
}
void usuwanie_sasiada(int X, int Y, unsigned char kamien_1, unsigned char kamien_2, unsigned char **t, int &n,int size_p, int size_d, int **p, int size_tablicy, int runda, int &nb, int &nc)
{
    zerowanie_tablicy(p, size_tablicy, n);
    if (zycia_kamienia(Y, X, kamien_2, kamien_1, t, n, size_p, size_d, p, size_tablicy) == 0)
        {
            for (int i = 0; i < n && n <= size_tablicy; i++)
                {
                    unsigned char kamien=t[p[i][0]][p[i][1]];
                    if(kamien==kamien_2)
                    {
                        t[p[i][0]][p[i][1]] = jaki_znak(p[i][0], p[i][1], size_d, size_p);
                        if (runda==Runda_Bialego)
                            nb++;
                        if (runda==Runda_Czarnego)
                            nc++;
                    }
                }
        }
}
void ruszanie_strzalkami(int znak, int &wskX, int &wskY, unsigned char **t,int &wsk_p, int &wsk_d)
{
    if (znak == 0)
            {
                znak = getch();
                if (znak == Strzalka_gora)
                {
                    Strzalka_w_gore(wskX, wskY,t);
                }
                else if (znak == Strzalka_dol)
                {
                    Strzalka_w_dol(wskX, wskY,t, wsk_d);
                }
                else if (znak == Strzalka_lewo)
                {
                    Strzalka_w_lewo(wskX, wskY,t);
                }
                else if (znak == Strzalka_prawo)
                {
                    Strzalka_w_prawo(wskX, wskY,t, wsk_p);
                }
            }
}
void przerysuj_plansze(unsigned char **t,int  size_d,int  size_p, int X, int Y, int wb,int wc)
{
    Reset_Konsoli();
    Narysuj_Plansze(t, size_d, size_p, X, Y);
    Legenda(X, Y, wb, wc);
    Kolorowanie_obecnego_punktu(X, Y, t);
}
void handicup_legenda()
{
    gotoxy(Wybor_PlanszyX, Wybor_PlanszyY);
    cputs("Game with handicup?");
    gotoxy(Wybor_PlanszyX, Wybor_PlanszyY+1);
    cputs("1) Yes");
    gotoxy(Wybor_PlanszyX, Wybor_PlanszyY+2);
    cputs("2) No");
}
void wybor_handicupa(unsigned char **t, int &wsk_x, int &wsk_y, int &roz_p, int &roz_d, int &r)
{
    int znak=0,wb=0,wc=0;
    do {
            Reset_Konsoli();
            handicup_legenda();
            znak = getch();
            if(znak=='1')
            {
               int zn=3;
               bool koniec=0;
               while(koniec==0)
               {
                   przerysuj_plansze(t,roz_d,roz_p,wsk_x,wsk_y,wb,wc);
                   zn=getch();
                   ruszanie_strzalkami(zn,wsk_x,wsk_y,t,roz_p,roz_d);
                   if(zn==Enter)
                   {
                       koniec=1;
                   }
                   if(zn=='i')
                   {
                     r=Runda_Bialego;
                     if(t[wsk_y-PlanszaY][wsk_x-PlanszaX]!=Czarny_Kamien)
                     {
                        t[wsk_y-PlanszaY][wsk_x-PlanszaX]=Czarny_Kamien;
                     }
                   }
               }
            }
           } while (znak<'1' || znak>'2');
}
unsigned char** stworz_tablice(int roz_p, int roz_d)
{
    unsigned char **t;
    t = ( unsigned char**)malloc(roz_d * sizeof( unsigned char*));
        for (int i = 0; i < roz_d; i++)
        {
            t[i] = ( unsigned char*)malloc(roz_p * sizeof( unsigned char));
        }
    return t;
}
void kogo_runda(int &n, unsigned char &k1, unsigned char &k2)
{
    if (n == Runda_Czarnego)
            {
                k1 = Czarny_Kamien;
                k2 = Bialy_Kamien;
            }
            else
            {
                k1 = Bialy_Kamien;
                k2 = Czarny_Kamien;
            }
}
void przepisz_tablice(unsigned char **t, unsigned char **t2, int roz_p, int roz_d)
{
   for(int i=0;i<roz_d;i++)
        {
            for(int j=0;j<roz_p;j++)
            {
                t2[i][j]=t[i][j];
            }
        }
}
bool czy_takie_same(unsigned char **t, unsigned char **t2, int roz_p, int roz_d)
{
    for(int i=0;i<roz_d;i++)
        {
            for(int j=0;j<roz_p;j++)
            {
                if(t2[i][j]!=t[i][j])
                    return false;
            }
        }
    return true;
}
void usuwanie_sasiadow(int X, int Y, unsigned char kamien_1, unsigned char kamien_2, unsigned char **t, int &n,int size_p, int size_d, int **p, int size_tablicy, int runda, int &nb, int &nc)
{
    if (Y != PlanszaY)
    {
        usuwanie_sasiada(X - PlanszaX,Y - PlanszaY - 1,kamien_1,kamien_2,t,n,size_p,size_d,p,size_tablicy,runda,nb,nc);
    }
    if (X - PlanszaX < size_p - 1)
    {
        usuwanie_sasiada(X - PlanszaX + 1,Y - PlanszaY,kamien_1,kamien_2,t,n,size_p,size_d,p,size_tablicy,runda,nb,nc);
    }
    if (Y - PlanszaY < size_d - 1)
    {
        usuwanie_sasiada(X - PlanszaX,Y - PlanszaY + 1,kamien_1,kamien_2,t,n,size_p,size_d,p,size_tablicy,runda,nb,nc);
    }
    if (X != PlanszaX)
    {
        usuwanie_sasiada(X - PlanszaX - 1,Y - PlanszaY,kamien_1,kamien_2,t,n,size_p,size_d,p,size_tablicy,runda,nb,nc);
    }
}
void usuwanie_sasiadow_sym(int X, int Y, unsigned char kamien_1, unsigned char kamien_2, unsigned char **t, int &n,int size_p, int size_d, int **p, int size_tablicy)
{
    if (Y != PlanszaY)
    {
        usuwanie_sasiada_sym(X - PlanszaX,Y - PlanszaY - 1,kamien_1,kamien_2,t,n,size_p,size_d,p,size_tablicy);
    }
    if (X - PlanszaX < size_p - 1)
    {
        usuwanie_sasiada_sym(X - PlanszaX + 1,Y - PlanszaY,kamien_1,kamien_2,t,n,size_p,size_d,p,size_tablicy);
    }
    if (Y - PlanszaY < size_d - 1)
    {
        usuwanie_sasiada_sym(X - PlanszaX,Y - PlanszaY + 1,kamien_1,kamien_2,t,n,size_p,size_d,p,size_tablicy);
    }
    if (X != PlanszaX)
    {
        usuwanie_sasiada_sym(X - PlanszaX - 1,Y - PlanszaY,kamien_1,kamien_2,t,n,size_p,size_d,p,size_tablicy);
    }
}
void usuwanie_sasiada_sym(int X, int Y, unsigned char kamien_1, unsigned char kamien_2, unsigned char **t, int &n,int size_p, int size_d, int **p, int size_tablicy)
{
    zerowanie_tablicy(p, size_tablicy, n);
    if (zycia_kamienia(Y, X, kamien_2, kamien_1, t, n, size_p, size_d, p, size_tablicy) == 0)
        {
            for (int i = 0; i < n && n <= size_tablicy; i++)
                {
                    unsigned char kamien=t[p[i][0]][p[i][1]];
                    t[p[i][0]][p[i][1]] = jaki_znak(p[i][0], p[i][1], size_d, size_p);
                }
        }
}
void wybor_dowolnego_rozmiaru (int &wsk_p, int &wsk_d)
{
    int td[10],ts[10],znak,i=0,j=0,koniec1=0,koniec2=0;
    Reset_Konsoli();
    menu_dlugosci();
    while(koniec1==0)
    {
        znak=getche();
        if(znak==Enter)
            koniec1=1;
        else
        {
            znak=znak-'0';
            td[i]=znak;
            i++;
        }
    }
    znak=0;
    Reset_Konsoli();
    menu_szerokosci();
    while(koniec2==0)
    {
        znak=getche();
        if(znak==Enter)
            koniec2=1;
        else
        {
            znak=znak-'0';
            ts[j]=znak;
            j++;
        }
    }
    wsk_p=zamiana_int(ts,j);
    wsk_d=zamiana_int(td,i);
}
void menu_dlugosci()
{
    gotoxy(Wybor_PlanszyX, Wybor_PlanszyY);
    cputs("Enter the length of the board:");
    gotoxy(Wybor_PlanszyX, Wybor_PlanszyY+1);
}
void menu_szerokosci()
{
    gotoxy(Wybor_PlanszyX, Wybor_PlanszyY);
    cputs("Enter the width of the board:");
    gotoxy(Wybor_PlanszyX, Wybor_PlanszyY+1);
}
int zamiana_int(int t[10], int roz)
{
    int w=0;
    for(int i=0;i<roz;i++)
    {
        w=w*10+t[i];
    }
    return w;
}
void zapis (int roz_p ,int roz_d, int w1, int w2, int r, unsigned char **t, unsigned char **t1, unsigned char **t2)
{
    char nazwa[50];
    nazwa_pliku(nazwa);
    Reset_Konsoli();
    menu_zapisu();

    FILE * f = fopen( nazwa, "w" );
    fprintf(f,"%d ",roz_p);
    fprintf(f,"\n");
    fprintf(f,"%d ",roz_d);
    fprintf(f,"\n");
    fprintf(f,"%d ",w1);
    fprintf(f,"\n");
    fprintf(f,"%d ",w2);
    fprintf(f,"\n");
    fprintf(f,"%d ",r);
    fprintf(f,"\n");
    for(int i=0;i<roz_d;i++)
    {
        for(int j=0;j<roz_p;j++)
        {
            fprintf(f,"%u ",t[i][j]);
        }
        fprintf(f,"\n");
    }
    fprintf(f,"\n");
    for(int i=0;i<roz_d;i++)
    {
        for(int j=0;j<roz_p;j++)
        {
            fprintf(f,"%u ",t1[i][j]);
        }
        fprintf(f,"\n");
    }
    fprintf(f,"\n");
    for(int i=0;i<roz_d;i++)
    {
        for(int j=0;j<roz_p;j++)
        {
            fprintf(f,"%u ",t2[i][j]);
        }
        fprintf(f,"\n");
    }

    fclose(f);
}
void stawianie_kamienia(unsigned char **tab, unsigned char **tab_1, unsigned char **tab_2, int Kursor_X, int Kursor_Y, int rozmiar_w_prawo, int rozmiar_w_dol, int &wsk_rundy, unsigned char swoj_kamien, unsigned char przeciwny_kamien, int wynik_bialego, int wynik_czarnego, int &wsk_wynik_B, int &wsk_wynik_C)
{
                bool mozna_postawic = 0, wolne = 1;
                unsigned char poprzedni_znak = tab[Kursor_Y - PlanszaY][Kursor_X - PlanszaX];
                tab[Kursor_Y - PlanszaY][Kursor_X - PlanszaX] = swoj_kamien;
                int licznik_elementow = 0,rozmiar_ilosci = rozmiar_w_dol * rozmiar_w_prawo;
                int* wskaznik_licznik_elementow = &licznik_elementow;
                int** poprzednie;
                poprzednie = (int**)malloc(rozmiar_ilosci * sizeof(int*));
                for (int i = 0; i < rozmiar_ilosci; i++)
                {
                    poprzednie[i] = (int*)malloc(2 * sizeof(int));
                }
                zerowanie_tablicy(poprzednie, rozmiar_ilosci, *wskaznik_licznik_elementow);
                if (poprzedni_znak == swoj_kamien || poprzedni_znak == przeciwny_kamien)
                    wolne = false;
                mozna_postawic=czy_mozna_postawic(Kursor_X,Kursor_Y,swoj_kamien,przeciwny_kamien,tab,*wskaznik_licznik_elementow,rozmiar_w_prawo,rozmiar_w_dol,poprzednie,rozmiar_ilosci);
                usuwanie_sasiadow_sym(Kursor_X,Kursor_Y,swoj_kamien,przeciwny_kamien,tab,*wskaznik_licznik_elementow,rozmiar_w_prawo,rozmiar_w_dol,poprzednie,rozmiar_ilosci);
                if(czy_takie_same(tab,tab_2,rozmiar_w_prawo,rozmiar_w_dol)==true)
                {
                    mozna_postawic=0;
                }
                przepisz_tablice(tab_1,tab,rozmiar_w_prawo,rozmiar_w_dol);
                tab[Kursor_Y - PlanszaY][Kursor_X - PlanszaX] = swoj_kamien;
                if (mozna_postawic == 1 && wolne == 1)
                {
                    przerysuj_plansze(tab,rozmiar_w_dol,rozmiar_w_prawo, Kursor_X, Kursor_Y, wynik_bialego,wynik_czarnego);
                    unsigned char klawisz = 1;
                    while (klawisz != Klawisz_Escape && klawisz != Enter)
                    {
                        klawisz = getch();
                        if (klawisz == Klawisz_Escape)
                        {
                            tab[Kursor_Y - PlanszaY][Kursor_X - PlanszaX] = poprzedni_znak;
                        }
                        if (klawisz == Enter)
                        {
                            usuwanie_sasiadow(Kursor_X,Kursor_Y,swoj_kamien,przeciwny_kamien,tab,*wskaznik_licznik_elementow,rozmiar_w_prawo,rozmiar_w_dol,poprzednie,rozmiar_ilosci,wsk_rundy,wsk_wynik_B,wsk_wynik_C);
                            if (wsk_rundy == Runda_Czarnego)
                                wsk_rundy = Runda_Bialego;
                            else
                                wsk_rundy = Runda_Czarnego;
                            przepisz_tablice(tab_1,tab_2,rozmiar_w_prawo,rozmiar_w_dol);
                            przepisz_tablice(tab,tab_1,rozmiar_w_prawo,rozmiar_w_dol);
                        }
                    }
                }
                else
                {
                    tab[Kursor_Y - PlanszaY][Kursor_X - PlanszaX] = poprzedni_znak;
                }
                for (int i = 0; i < rozmiar_ilosci; i++)
                {
                    free(poprzednie[i]);
                }
                free(poprzednie);
}
void menu_zapisu()
{
    gotoxy(Wybor_PlanszyX, Wybor_PlanszyY);
    cputs("Enter name of the board:");
    gotoxy(Wybor_PlanszyX, Wybor_PlanszyY+1);
}
void nazwa_pliku (char *tablica)
{
    Reset_Konsoli();
    menu_zapisu();
    int i=0, koniec=0, znak=5;
    while(koniec==0)
    {
        znak=getche();
        if(znak==Enter)
            koniec=1;
        else
        {
            tablica[i]=znak;
            i++;
        }
    }
    tablica[i]='\0';
}
