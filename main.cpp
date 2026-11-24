#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

const double PI = 3.14;

// ---------------- оголошення функцій ----------------
// Завдання 1, Proc16
void SphereVS(double R, double &V, double &S);      // об'єм і площа кулі
void task_Proc16();                                 // задача Proc16 цілком

// Завдання 1, Proc33
int Quarter(double x, double y);                    // номер координатної чверті
void task_Proc33();                                 // задача Proc33 цілком

// Завдання 2, Integer7
bool in_N(int &pN);                                 // введення з перевіркою Integer7
void calc_digits(int pN, int &pSum, int &pProd);    // підрахунок Integer7
void out_res(int pSum, int pProd);                  // виведення результатів Integer7
void task_Int7();                                   // задача Integer7 цілком

// ---------------- головна функція (меню) ----------------
int main()
{
    int choice;

    do
    {
        cout << endl << "МЕНЮ:" << endl;
        cout << "1 - Proc16 (об'єм і площа кулі)" << endl;
        cout << "2 - Proc33 (координатна чверть)" << endl;
        cout << "3 - Integer7 (сума/добуток цифр)" << endl;
        cout << "0 - Вихід" << endl;
        cout << "Your choice: ";
        cin >> choice;

        if (cin.eof())                  // ввід закрито (Ctrl+D / Ctrl+Z) - вихід
            break;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wrong menu item!" << endl;
            choice = -1; // продовжити цикл меню
            continue;
        }

        switch (choice)
        {
        case 1:
            task_Proc16();
            break;
        case 2:
            task_Proc33();
            break;
        case 3:
            task_Int7();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Wrong menu item!" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}

// ---------------- визначення функцій – після main() ----------------

// ===== Proc16 =====
void SphereVS(double R, double &V, double &S)
{
    V = (4.0 / 3.0) * PI * R * R * R;
    S = 4.0 * PI * R * R;
}

void task_Proc16()
{
    double r1, r2, r3;                  // радіуси трьох куль
    double v1, s1, v2, s2, v3, s3;      // об'єми і площі

    cout << endl << "Proc16." << endl;
    cout << "Enter three radii: ";
    cin >> r1 >> r2 >> r3;

    if (cin.fail() || r1 < 0.0 || r2 < 0.0 || r3 < 0.0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Radii must be non-negative numbers!" << endl;
        return;
    }

    // виклики процедури (без циклів)
    SphereVS(r1, v1, s1);
    SphereVS(r2, v2, s2);
    SphereVS(r3, v3, s3);

    cout << "R = " << r1 << ": V = " << v1 << ", S = " << s1 << endl;
    cout << "R = " << r2 << ": V = " << v2 << ", S = " << s2 << endl;
    cout << "R = " << r3 << ": V = " << v3 << ", S = " << s3 << endl;
}

// ===== Proc33 =====
int Quarter(double x, double y)
{
    if (x > 0.0 && y > 0.0)
        return 1;
    else if (x < 0.0 && y > 0.0)
        return 2;
    else if (x < 0.0 && y < 0.0)
        return 3;
    else
        return 4;
}

void task_Proc33()
{
    double x1, y1, x2, y2, x3, y3;

    cout << endl << "Proc33." << endl;
    cout << "Enter three points (x y), nonzero: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (cin.fail() || x1 == 0.0 || y1 == 0.0 || x2 == 0.0 || y2 == 0.0 || x3 == 0.0 || y3 == 0.0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Coordinates must be nonzero numbers!" << endl;
        return;
    }

    // виклики функції (без циклів)
    cout << "Quarter: " << Quarter(x1, y1) << " ";
    cout << Quarter(x2, y2) << " ";
    cout << Quarter(x3, y3) << endl;
}

// ===== Integer7 =====
// повертає true, якщо дані некоректні
bool in_N(int &pN)
{
    cout << endl << "Integer7." << endl;
    cout << "N (two-digit) = ";
    cin >> pN;

    if (cin.fail())                     // перевірка помилок консольного введення
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }

    int absN = abs(pN);                 // не змінюємо вхідне значення pN
    if (absN < 10 || absN > 99)
        return true;

    return false;
}

void calc_digits(int pN, int &pSum, int &pProd)
{
    int absN = abs(pN);
    int d1 = absN / 10;                 // цифра десятків
    int d2 = absN % 10;                 // цифра одиниць
    pSum = d1 + d2;
    pProd = d1 * d2;
}

void out_res(int pSum, int pProd)
{
    cout << "Sum = " << pSum << endl;
    cout << "Product = " << pProd << endl;
}

void task_Int7()
{
    int N, sum, prod;

    if (in_N(N))                        // некоректні дані
        cout << "N must be a two-digit integer!" << endl;
    else
    {
        // підрахунок і виведення результату
        calc_digits(N, sum, prod);
        out_res(sum, prod);
    }
}
