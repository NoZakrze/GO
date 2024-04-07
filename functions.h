#define LegendaX 5
#define LegendaY 2
#define Wybor_PlanszyX 10
#define Wybor_PlanszyY 10
#define PlanszaX 80
#define PlanszaY 2
#define lewyGornyRog 218
#define lewyDolnyRog 192
#define prawyGornyRog 191
#define prawyDolnyRog 217
#define gornyBok 194
#define dolnyBok 193
#define lewyBok 195
#define prawyBok 180
#define przeciecie 197
#define KoniecX 20
#define KoniecY 5
#define Runda_Bialego 1
#define Runda_Czarnego 0
#define Bialy_Kamien 254
#define Czarny_Kamien 79
#define Klawisz_Escape 27
#define RamkaX 79
#define RamkaY 1
#define GoraRamki 196
#define BokRamki 179
#define Enter 0x0d
#define Strzalka_gora 0x48
#define Strzalka_dol 0x50
#define Strzalka_prawo 0x4d
#define Strzalka_lewo 0x4b

    void Legenda(int wsk_x,int wsk_y, int b, int c); //wypisanie legendy
    void Reset_Konsoli();
    void Wybor_Planszy_Legenda();
    void Stworz_Plansze(unsigned char **t, int size_w_dol, int size_w_prawo);
    void Narysuj_Plansze( unsigned char **t, int size_w_dol, int size_w_prawo, int x, int y);
    void Kolorowanie_obecnego_punktu(int x, int y, unsigned char **t); // obecna pozycja kursora jest narysowana innym kolorem
    void Koniec_gry();
    void Wybor_Rozmiaru(int &wsk_p, int &wsk_d); //sekwencja wyboru rozmiaru planszy
    void Strzalka_w_gore(int &wsk_x, int &wsk_y, unsigned char **t);
    void Strzalka_w_dol(int &wsk_x, int &wsk_y, unsigned char **t, int &roz);
    void Strzalka_w_lewo(int &wsk_x, int &wsk_y, unsigned char **t);
    void Strzalka_w_prawo(int &wsk_x, int &wsk_y, unsigned char **t, int &roz);
    bool zycia_kamienia(int index_i, int index_j, unsigned char swoj_kamien, unsigned char przeciwny_kamien, unsigned char **t, int &n, int rozmiar_prawo, int rozmiar_dol, int **poprzednie, int rozmiar_tablicy); //funkcja sprawdza czy kamien posiada jakis oddech czy nie
    unsigned char jaki_znak(int i, int j,int size_w_dol, int size_w_prawo); // przypisanie elementowi planszy odpowiedzniego znaku obramowania
    void zerowanie_tablicy (int **t,int rozmiar,int &w);
    bool czy_mozna_postawic(int X, int Y, unsigned char kamien_1, unsigned char kamien_2, unsigned char **t, int &n,int size_p, int size_d, int **p, int size_tablicy);
    void usuwanie_sasiada(int X, int Y, unsigned char kamien_1, unsigned char kamien_2, unsigned char **t, int &n,int size_p, int size_d, int **p, int size_tablicy, int runda, int &nb, int &nc);
    void ruszanie_strzalkami(int znak, int &wskX, int &wskY, unsigned char **t,int &wsk_p, int &wsk_d); //obsluga strzalek
    void przerysuj_plansze(unsigned char **t,int  size_d,int  size_p, int X, int Y, int wb,int wc); // narysowanie planszy na ekranie
    void handicup_legenda();
    void wybor_handicupa(unsigned char **t, int &wsk_x, int &wsk_y, int &roz_p, int &roz_d, int &r); //sekwencja wyboru gry z handicupem lub nie
    unsigned char** stworz_tablice(int roz_p, int roz_d); //dynamiczne tworzenie tablicy o podanych rozmiarach
    void kogo_runda(int &n, unsigned char &k1, unsigned char &k2);
    void przepisz_tablice(unsigned char **t, unsigned char **t2, int roz_p, int roz_d); // przepisuje wartosci w tablicy t do tablicy t2
    bool czy_takie_same(unsigned char **t, unsigned char **t2, int roz_p, int roz_d); // sprawdzanie czy dwie tablice sa identyczne
    void usuwanie_sasiadow(int X, int Y, unsigned char kamien_1, unsigned char kamien_2, unsigned char **t, int &n,int size_p, int size_d, int **p, int size_tablicy, int runda, int &nb, int &nc);
    void usuwanie_sasiadow_sym(int X, int Y, unsigned char kamien_1, unsigned char kamien_2, unsigned char **t, int &n,int size_p, int size_d, int **p, int size_tablicy); //symulacja usuwanie sasiednich kamieni uzywana przy zasadzie KO
    void usuwanie_sasiada_sym(int X, int Y, unsigned char kamien_1, unsigned char kamien_2, unsigned char **t, int &n,int size_p, int size_d, int **p, int size_tablicy);
    void wybor_dowolnego_rozmiaru (int &wsk_p, int &wsk_d);
    void menu_dlugosci();
    void menu_szerokosci();
    int zamiana_int(int t[10], int roz); //ciag cyfr jest zamieniany na liczbe
    void zapis (int roz_p ,int roz_d, int w1, int w2, int r, unsigned char **t, unsigned char **t1, unsigned char **t2); // zapis stanu gry do pliku
    void stawianie_kamienia(unsigned char **tab, unsigned char **tab_1, unsigned char **tab_2, int Kursor_X, int Kursor_Y, int rozmiar_w_prawo, int rozmiar_w_dol, int &wsk_rundy, unsigned char swoj_kamien, unsigned char przeciwny_kamien, int wynik_bialego, int wynik_czarnego, int &wsk_wynik_B, int &wsk_wynik_C);
    void menu_zapisu();
    void nazwa_pliku (char* tablica); //umozliwienie uzytkownikowi na wpisanie nazwy pliku
