/* Написать программу, которая вычисляет сумму первых n целых положительных чётных целых чисел. 
   Количество суммируемых чисел вводит пользователь. */

#include <iostream>
#include <clocale> //для вывода на кириллице
using std::cout; using std::cin; using std::endl; 

// функция получает от пользователя целое положительное число
int getUsersNumber()
{
	cout << "Введите количество суммируемых чисел: ";
	int usersNumber{ 0 };
	cin >> usersNumber;
	while (cin.fail() || (usersNumber < 0))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Вы ввели нечто некорректное, введите положительное целое число: ";
		cin >> usersNumber;
	}
	return usersNumber;
}

int main()
{
	//для вывода на кириллице
	setlocale(LC_CTYPE, "rus");

	while (true) // пока пользователь хочет играть
	{
		//получаем число суммируемых чисел от пользователя
		int numberOfNumbers = getUsersNumber();

		unsigned positiveEvenNumberCounter{ 0 };
		unsigned next_even_number{ 0 };            
		unsigned summ{ 0 };                   // искомая сумма положительных чётных чисел
		while (positiveEvenNumberCounter < numberOfNumbers)
		{
			next_even_number += 2;          // переходим к следующему чётному числу
			summ += next_even_number;       // добавляем его к сумме
			positiveEvenNumberCounter++;   // добавили очередное число, увеличиваем наш счётчик чисел в сумме
		}
		cout << "Сумма первых " << numberOfNumbers << " положительных чётных чисел равна " << summ << "." << endl << endl;
	}
	return 0;
}
