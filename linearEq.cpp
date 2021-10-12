#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void MainMenu()
{
    cout << "\nMAIN MENU";
    string MainMenu[3] = {"End", "Edit LE constant", "Show the solution"};
    for (int i = 0; i < 3; i++)
    {
        cout << "\n"
             << i << ". " << MainMenu[i];
    }
}
float Const[3][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
void View()
{
    cout << setw(2) << "|" << setw(3) << Const[0][0] << setw(6) << Const[0][1] << setw(6) << Const[0][2] << "| |x|   |" << setw(8) << Const[0][3] << "|" << endl;
    cout << setw(2) << "|" << setw(3) << Const[1][0] << setw(6) << Const[1][1] << setw(6) << Const[1][2] << "| |y| = |" << setw(8) << Const[1][3] << "|" << endl;
    cout << setw(2) << "|" << setw(3) << Const[2][0] << setw(6) << Const[2][1] << setw(6) << Const[2][2] << "| |z|   |" << setw(8) << Const[2][3] << "|" << endl;
}
void Edit()
{
    for (int e = 0; e < 3; e++)
    {
        cout << "Equation " << e + 1 << endl;
        cout << "insert X constant\t:";
        cin >> Const[e][0];
        cout << "insert Y constant\t:";
        cin >> Const[e][1];
        cout << "insert Z constant\t:";
        cin >> Const[e][2];
        cout << "insert total of Eq." << e + 1 << "\t:";
        cin >> Const[e][3];
    }
}
void Result(float Const[3][4])
{
    for (int g = 0; g < 3; g++)
    {
        for (int h = 3; h >= g; h--)
            Const[g][h] /= Const[g][g];
        for (int i = 0; i < 3; i++)
        {
            if (g == i)
                continue;
            for (int j = 3; j >= g; j--)
                Const[i][j] -= Const[i][g] * Const[g][j];
        }
    }
    string v[3] = {"X", "Y", "Z"};
    for (int i = 0; i < 3; i++)
        cout << v[i] << " = " << Const[i][3] << endl;
}

int main()
{
    int main;
    do
    {
        View();
        MainMenu();
        cout << "\n\nWhat do you want	:";
        cin >> main;
        switch (main)
        {
        case 0:
        {
            cout << "\nMerci Beaucoup...\n\n";
            break;
        }
        case 1:
            Edit();
            break;
        case 2:
            Result(Const);
            break;
        default:
        {
            cout << "\nError!!!" << endl;
        }
        }
    } while (main != 0);
    system("pause");
    return 0;
}
