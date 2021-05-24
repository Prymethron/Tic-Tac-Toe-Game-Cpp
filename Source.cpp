#include <iostream>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include<MMsystem.h>

using namespace std;


void MatrisBas(string Matris[4][4])
{
    cout << endl << "\t\t";
    for (int i = 1;i <= 3;i++)
    {
        for (int j = 1;j <= 3;j++)
        {
            cout << " " << Matris[i][j] << " ";
            if (j != 3)
            {
                cout << "|";
            }
        }
        if (i != 3)
            cout << endl << "\t\t __ ___ __" << endl << endl;
        cout << "\t\t";
    }
    cout << endl;
}

bool oxKontrol(char ox)
{
    if (ox == 'O' || ox == 'X' || ox == 'R')
    {
        return true;
    }
    else
    {
        cout << "\tYanlis bir deger girdiniz, tekrar deneyiniz." << endl << endl;
        return false;
    }

}

bool degerKontrol(int x, int y)
{
    switch (x)
    {
    case 1:
        return true;
    case 2:
        return true;
    case 3:
        return true;
    default:
        cout << "\t\tYanlis bir deger girdiniz." << endl << endl;
        Sleep(2000);
        return false;
    }
    switch (y)
    {
    case 1:
        return true;
    case 2:
        return true;
    case 3:
        return true;
    default:
        cout << "\t\tYanlis bir deger girdiniz." << endl << endl;
        Sleep(2000);
        return false;
    }
}

int Kazanma(string Matris[4][4])
{
    int point = 0;
    for (int i = 1;i <= 3;i++)
    {
        if (Matris[i][1] == "\033[92mO\033[0m" && Matris[i][2] == "\033[92mO\033[0m" && Matris[i][3] == "\033[92mO\033[0m") //yatay
        {
            return 1;
        }
        if (Matris[i][1] == "\033[91mX\033[0m" && Matris[i][2] == "\033[91mX\033[0m" && Matris[i][3] == "\033[91mX\033[0m")
        {
            return 2;
        }
        if (Matris[1][i] == "\033[92mO\033[0m" && Matris[2][i] == "\033[92mO\033[0m" && Matris[3][i] == "\033[92mO\033[0m") //dikey
        {
            return 1;
        }
        if (Matris[1][i] == "\033[91mX\033[0m" && Matris[2][i] == "\033[91mX\033[0m" && Matris[3][i] == "\033[91mX\033[0m")
        {
            return 2;
        }
    }
    if (Matris[1][1] == "\033[92mO\033[0m" && Matris[2][2] == "\033[92mO\033[0m" && Matris[3][3] == "\033[92mO\033[0m") //Soldan sa�a �apraz
    {
        return 1;
    }
    if (Matris[1][1] == "\033[91mX\033[0m" && Matris[2][2] == "\033[91mX\033[0m" && Matris[3][3] == "\033[91mX\033[0m")
    {
        return 2;
    }
    if (Matris[1][3] == "\033[92mO\033[0m" && Matris[2][2] == "\033[92mO\033[0m" && Matris[3][1] == "\033[92mO\033[0m") //sa�dan sola �apraz
    {
        return 1;
    }
    if (Matris[1][3] == "\033[91mX\033[0m" && Matris[2][2] == "\033[91mX\033[0m" && Matris[3][1] == "\033[91mX\033[0m")
    {
        return 2;
    }

    point = 0;
    for (int i = 1;i <= 3;i++)
        for (int j = 1;j <= 3;j++)
        {
            if (Matris[i][j] == "\033[91mX\033[0m" || Matris[i][j] == "\033[92mO\033[0m")
            {
                point++;
            }
        }
    if (point == 9)
    {
        return 3;
    }
}

int main()
{
    bool devam, oxkontrol;
    int scorex = 0, scoreo = 0;
    char oxsec;
    int x, y, botx, boty;
    string Matris[4][4];
    int oyunmodu;
    srand(time(NULL));

    cout << "\t\t" << endl;
    cout << "\t\t";

    for (int i = 1;i <= 3;i++)
        for (int j = 0;j <= 3;j++)
            Matris[i][j] = " ";

    while (true)
    {
        system("CLS");
        cout << endl << "\t\t     \033[93mTIC-TAC-TOE\033[0m " << endl << endl;
        cout << "              \033[96mTek Oyunculu(1'i tuslayiniz)" << endl << endl;
        cout << "             Cok Oyunculu(2'yi tuslayiniz)" << endl << endl;
        cout << "                 Cikis (3'u tuslayiniz)\033[0m" << endl << endl;
        cin >> oyunmodu;
        Sleep(2000);


        if (oyunmodu == 1)
        {
            scoreo = 0;
            scorex = 0;

            while (true)
            {
                for (int i = 1;i <= 3;i++)
                    for (int j = 0;j <= 3;j++)
                        Matris[i][j] = " ";

                system("CLS");


                cout << endl << "\t   \033[92mO\033[0m veya \033[91mX\033[0m seciniz." << endl;
                cout << endl << "\t  Menuye donmek icin R" << endl;
                oxkontrol = false;
                while (oxkontrol != true)
                {
                    cin >> oxsec;
                    Sleep(2000);
                    oxkontrol = oxKontrol(oxsec);
                }

                if (oxsec == 'R')
                {
                    break;
                }

                system("CLS");

                while (true)
                {
                    MatrisBas(Matris);
                    cout << endl;
                    cout << "\t== \033[91mX\033[0m'in puani=" << scorex << " \033[92mO\033[0m'nun puani=" << scoreo << " ==" << endl << endl;

                    devam = false;
                    while (devam != true)
                    {
                        cout << "\t==Bir yatay koordinat giriniz.==" << endl;
                        cin >> x;
                        cout << "\t==Bir dikey koordinat giriniz.==" << endl;
                        cin >> y;
                        devam = degerKontrol(x, y);
                    }

                    if (Matris[x][y] == " ")
                    {
                        if (oxsec == 'O')
                        {

                            Matris[x][y] = "\033[92mO\033[0m";
                            cout << ("\tAI sirasi...") << endl << endl;

                            while (true)
                            {
                                botx = rand() % 3 + 1;
                                boty = rand() % 3 + 1;
                                Sleep(2000);
                                if (Kazanma(Matris) == 1 || Kazanma(Matris) == 2 || Kazanma(Matris) == 3)
                                {
                                    system("CLS");
                                    break;
                                }
                                if (Matris[botx][boty] == " ")
                                {
                                    Matris[botx][boty] = "\033[91mX\033[0m";
                                    //PlaySound(TEXT("cizik.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                    break;
                                }
                            }
                        }
                        else
                        {
                            Matris[x][y] = "\033[91mX\033[0m";
                            cout << ("\tAI sirasi...") << endl << endl;

                            while (true)
                            {
                                botx = rand() % 3 + 1;
                                boty = rand() % 3 + 1;
                                Sleep(2000);

                                if (Kazanma(Matris) == 1 || Kazanma(Matris) == 2 || Kazanma(Matris) == 3)
                                {
                                    system("CLS");
                                    break;
                                }

                                if (Matris[botx][boty] == " ")
                                {
                                    Matris[botx][boty] = "\033[92mO\033[0m";
                                    //PlaySound(TEXT("cizik.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << "\033[91mSectiginiz koordinat daha once kullanilmis!\033[0m" << endl;
                        Sleep(2000);
                    }


                    if (Kazanma(Matris) == 1 || Kazanma(Matris) == 2 || Kazanma(Matris) == 3)
                    {
                        if (Kazanma(Matris) == 1)
                        {
                            cout << "\t\t\033[92m  O\033[0m kazandi" << endl;
                            scoreo++;
                        }
                        if (Kazanma(Matris) == 2)
                        {
                            cout << "\t\t\033[91m  X\033[0m kazandi" << endl;
                            scorex++;
                        }
                        if (Kazanma(Matris) == 3)
                        {
                            cout << endl << "\t\t  BERABERE!" << endl;
                        }
                        //PlaySound(TEXT("cizik.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        MatrisBas(Matris);
                        Sleep(2000);
                        break;
                    }

                    system("CLS");
                }
            }
        }


        if (oyunmodu == 2)
        {
            scoreo = 0;
            scorex = 0;

            while (true)
            {
                for (int i = 1;i <= 3;i++)
                    for (int j = 0;j <= 3;j++)
                        Matris[i][j] = " ";

                system("CLS");


                cout << endl << "\t  Birinci oyuncu \033[92mO\033[0m veya \033[91mX\033[0m seciyor." << endl;
                cout << endl << "\t      Menuye donmek icin R" << endl;

                oxkontrol = false;
                while (oxkontrol != true)
                {
                    cin >> oxsec;
                    oxkontrol = oxKontrol(oxsec);
                }

                if (oxsec == 'R')
                {
                    break;
                }

                system("CLS");

                while (true)
                {
                    while (true)
                    {
                        MatrisBas(Matris);
                        cout << endl;
                        cout << "\t== \033[91mX\033[0m'in puani=" << scorex << " \033[92mO\033[0m'nun puani=" << scoreo << " ==" << endl << endl;

                        devam = false;
                        while (devam != true)
                        {
                            cout << "\t== Birinci oyuncu icin yatay koordinat giriniz. ==" << endl;
                            cin >> x;
                            cout << "\t== Birinci oyuncu icin dikey koordinat giriniz. ==" << endl;
                            cin >> y;
                            devam = degerKontrol(x, y);
                        }

                        if (Matris[x][y] == " ")
                        {
                            if (oxsec == 'O')
                            {
                                Matris[x][y] = "\033[92mO\033[0m";
                                //PlaySound(TEXT("cizik.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                break;
                            }
                            else
                            {
                                Matris[x][y] = "\033[91mX\033[0m";
                                //PlaySound(TEXT("cizik.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                break;
                            }
                        }
                        else
                        {
                            cout << "\033[91mSectiginiz koordinat daha once kullanilmis!\033[0m" << endl;
                            Sleep(2000);
                        }
                        system("CLS");
                    }
                    system("CLS");

                    while (true)
                    {
                        if (Kazanma(Matris) == 1 || Kazanma(Matris) == 2 || Kazanma(Matris) == 3)
                            break;

                        MatrisBas(Matris);

                        cout << endl << "\t==\033[91mX\033[0m'in puani=" << scorex << " \033[92mO\033[0m'nun puani=" << scoreo << " ==" << endl << endl;

                        devam = false;
                        while (devam != true)
                        {
                            cout << "\t== Ikinci oyuncu icin yatay koordinat giriniz. ==" << endl;
                            cin >> x;
                            cout << "\t== Ikinci oyuncu icin dikey koordinat giriniz. ==" << endl;
                            cin >> y;
                            devam = degerKontrol(x, y);
                        }

                        if (Matris[x][y] == " ")
                        {
                            if (oxsec == 'O')
                            {
                                Matris[x][y] = "\033[91mX\033[0m";
                                //PlaySound(TEXT("cizik.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                break;
                            }
                            else
                            {
                                Matris[x][y] = "\033[92mO\033[0m";
                                //PlaySound(TEXT("cizik.wav"), NULL, SND_FILENAME | SND_ASYNC);
                                break;
                            }
                        }
                        else
                        {
                            cout << "\033[91mSectiginiz koordinat daha once kullanilmis!\033[0m" << endl;
                            Sleep(2000);
                            system("CLS");
                        }
                    }

                    if (Kazanma(Matris) == 1 || Kazanma(Matris) == 2 || Kazanma(Matris) == 3 )
                    {
                        if (Kazanma(Matris) == 1)
                        {
                            system("CLS");
                            cout << endl << "\t\t\033[92m  O\033[0m kazandi" << endl;
                            scoreo++;
                        }
                        if (Kazanma(Matris) == 2)
                        {
                            system("CLS");
                            cout << endl << "\t\t\033[91m  X\033[0m kazandi" << endl;
                            scorex++;
                        }
                        if (Kazanma(Matris) == 3)
                        {
                            cout << endl << "\t\t  BERABERE!" << endl;
                        }
                        //PlaySound(TEXT("cizik.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        MatrisBas(Matris);
                        Sleep(2000);
                        break;
                    }

                    system("CLS");
                }
            }
        }

        if (oyunmodu == 3)
        {
            break;
        }

    }

}