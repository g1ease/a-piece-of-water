#include <iostream>
#include <fstream>
#include <iostream>
#include <limits> 

using namespace std;

void PressEnterToContinue()
{
std::cout << "Press ENTER to continue... " << flush;
std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
}

int main()
{
setlocale(LC_ALL, "Russian");
int balanceOpen=0;
int balanceClose = 0;
char fileName1[255];
char fileName2[255];
char buffer;
cout << "Введите имя файла для записи:" << endl;
cin >> fileName2;
cout << "Введите имя файла для чтения:" << endl;
cin >> fileName1;
ofstream fout(fileName2);
ifstream fin(fileName1);

if (!fin.is_open())
{
cout << "Данный файл не найден.";
fout << "Данный файл не найден.";
}
else
{
fin >> buffer;
while (fin)
{

if (buffer == '{')
{
balanceOpen++;
}
else
if (buffer == '}')
{
balanceClose++;
}
fin >> buffer;
}
fin.close();

if (balanceOpen < balanceClose)
{
cout << "Число открывающих скобок не соответствует числу закрывающих. Закрывающих скобок больше на " << balanceClose - balanceOpen << "." << endl;
fout << "Число открывающих скобок не соответствует числу закрывающих. Закрывающих скобок больше на " << balanceClose - balanceOpen << "." << endl;
}
else if (balanceOpen > balanceClose)
{
cout << "Число открывающих скобок не соответствует числу закрывающих. Открывающих скобок больше на " << balanceOpen - balanceClose << "." << endl;
fout << "Число открывающих скобок не соответствует числу закрывающих. Открывающих скобок больше на " << balanceOpen - balanceClose << "." << endl;
}
else if (balanceOpen == balanceClose && balanceOpen != 0)
{
cout << "Число открывающих скобок соответствует числу закрывающих." << endl;
fout << "Число открывающих скобок соответствует числу закрывающих." << endl;
}
else
{
cout << "В файле нет фигурных скобок." << endl;
fout << "В файле нет фигурных скобок." << endl;
}
}
fout.close();

return 0;
}
