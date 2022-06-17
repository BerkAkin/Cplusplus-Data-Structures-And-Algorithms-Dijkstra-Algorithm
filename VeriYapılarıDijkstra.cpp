//BERK AKIN 191307012
#include <locale>
#include <iostream>
using namespace std;

#define MaksUzaklık 9999

void Dijkstra(int G[7][7], int n, int Kaynak)
{
    int Uzaklık[7][7];
    int Mesafe[7];
    int Dizi[7];
    int İşaretli[7];
    int Sayaç;
    int MinimumMesafe;
    int SonrakiDüğüm;
    int i, j;

    for (i = 0;i < n;i++)
    {
        for (j = 0;j < n;j++)
        {
            if (G[i][j] == 0)
            {
                Uzaklık[i][j] = MaksUzaklık;
            }
            else
            {
                Uzaklık[i][j] = G[i][j];
            }
        }
    }
    for (i = 0;i < n;i++)
    {
        Mesafe[i] = Uzaklık[Kaynak][i];
        Dizi[i] = Kaynak;
        İşaretli[i] = 0;
    }

    Mesafe[Kaynak] = 0;
    İşaretli[Kaynak] = 1;
    Sayaç = 1;

    while (Sayaç < n - 1)
    {
        MinimumMesafe = MaksUzaklık;
        for (i = 0;i < n;i++)
        {
            if (Mesafe[i] < MinimumMesafe && !İşaretli[i])
            {
                MinimumMesafe = Mesafe[i];
                SonrakiDüğüm = i;
            }
        }

        İşaretli[SonrakiDüğüm] = 1;
        for (i = 0;i < n;i++)
        {
            if (!İşaretli[i])
            {
                if (MinimumMesafe + Uzaklık[SonrakiDüğüm][i] < Mesafe[i])
                {
                    Mesafe[i] = MinimumMesafe + Uzaklık[SonrakiDüğüm][i];
                    Dizi[i] = SonrakiDüğüm;
                }
            }
        }
        Sayaç++;
    }
    cout << "Haritada İşaretli Yerler Ve Numaraları: \n 0:Gebze\n 1:Hereke\n 2:Şemsettin\n 3:İlimtepe\n 4:Körfez\n 5:Derince\n 6:İzmit\n";
    for (i = 0;i < n;i++)
    {
        if (i != Kaynak)
        {
            switch (i)
            {
            case 1:
                cout << "\n" << "Hereke'den Gebze'ye Olan En Kısa Uzaklık: " << Mesafe[i] << "km";
                cout << "\nUğranılması Gereken Yol Rotasyonu = " << i;
                break;

            case 2:
                cout << "\n" << "Şemsettin'den Gebze'ye Olan En Kısa Uzaklık: " << Mesafe[i] << "km";
                cout << "\nUğranılması Gereken Yol Rotasyonu = " << i;
                break;
            case 3:
                cout << "\n" << "İlimtepe'den Gebze'ye Olan En Kısa Uzaklık: " << Mesafe[i] << "km";
                cout << "\nUğranılması Gereken Yol Rotasyonu = " << i;
                break;
            case 4:
                cout << "\n" << "Körfez'den Gebze'ye Olan En Kısa Uzaklık: " << Mesafe[i] << "km";
                cout << "\nUğranılması Gereken Yol Rotasyonu = " << i;
                break;
            case 5:
                cout << "\n" << "Derince'den Gebze'ye Olan En Kısa Uzaklık: " << Mesafe[i] << "km";
                cout << "\nUğranılması Gereken Yol Rotasyonu = " << i;
                break;
            case 6:
                cout << "\n" << "İzmit'ten Gebze'ye Olan En Kısa Uzaklık: " << Mesafe[i] << "km";
                cout << "\nUğranılması Gereken Yol Rotasyonu = " << i;
                break;
            }
            j = i;
            do
            {
                switch (j)
                {
                case 1:
                    j = Dizi[j];
                    cout << "<----" << j;
                    break;
                    j = Dizi[j];
                    cout << "<----" << j;
                case 2:
                    j = Dizi[j];
                    cout << "<----" << j;
                    break;
                case 3:
                    j = Dizi[j];
                    cout << "<----" << j;
                    break;
                case 4:
                    j = Dizi[j];
                    cout << "<----" << j;
                    break;
                case 5:
                    j = Dizi[j];
                    cout << "<----" << j;
                    break;
                case 6:
                    j = Dizi[j];
                    cout << "<----" << j;
                    break;
                }
            } while (j != Kaynak);
            cout << endl;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Turkish");
    int g[7][7] =
    {
        {0,15,28,0,0,0,0},
        {15,0,14,0,9,0,0},
        {28,14,0,6,0,0,19},
        {0,0,6,0,3,6,0},
        {0,9,0,3,0,8,0},
        {0,0,0,6,8,0,9},
        {0,0,19,0,0,9,0},

    };
    int n = 7;
    int u = 0;
    Dijkstra(g, n, u);
    cout << endl << endl;
    return 0;
}