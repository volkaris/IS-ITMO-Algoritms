#include <iostream>
#include <clocale>
using namespace std;

struct fridge
{
	int Amount_of_milk;
	int Amount_of_meat;
	int Amount_of_chees;
	int Amount_of_candies;
};

int main()
{
	struct fridge fridge1;

	struct fridge fridge2;
	setlocale(0, "");
	cout << "С каким холодильником вы хотите работать?" << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		cout <<
			"Введите первоначальное количество 1.молока,2.мяса,3.сыра,4.печенья соответсвенно.Далее,чтобы произвести какие-либо операции,обращайтесь к объектам через номера,указанные выше."<<endl;
		cin >> fridge1.Amount_of_milk;
		cin >> fridge1.Amount_of_meat;
		cin >> fridge1.Amount_of_chees;
		cin >> fridge1.Amount_of_candies;
		int exit1 = 1;
		while (exit1 == 1)
		{
			cout <<
				"Введите 1,чтобы остаться или 0,чтобы выйти.Если хотите произвести какую-либо математическую операцию,введите знак (+ или -),затем порядковый номер.Напоминание (1-молоко,2-мясо,3-сыр,4-печенье),затем число,на которое параметр будет изменён"<<endl;
			char znak;
			int nomer, amount;
			cin >> exit1;
			if (exit1 == 0) { return -1; }
			if (exit1 != 0) { cin >> znak >> nomer >> amount; }
			if (znak == '+')
			{
				if (nomer == 1)
				{
					fridge1.Amount_of_milk += amount;
				}
				if (nomer == 2)
				{
					fridge1.Amount_of_meat += amount;
				}
				if (nomer == 3)
				{
					fridge1.Amount_of_chees += amount;
				}
				if (nomer == 4)
				{
					fridge1.Amount_of_candies += amount;
				}
				cout << fridge1.Amount_of_milk << " " << fridge1.Amount_of_meat << " " << fridge1.Amount_of_chees << " "
					<< fridge1.Amount_of_candies << endl;
			}
			if (znak == '-')
			{
				if (nomer == 1)
				{
					fridge1.Amount_of_milk -= amount;
				}
				if (nomer == 2)
				{
					fridge1.Amount_of_meat -= amount;
				}
				if (nomer == 3)
				{
					fridge1.Amount_of_chees -= amount;
				}
				if (nomer == 4)
				{
					fridge1.Amount_of_candies -= amount;
				}
				cout << fridge1.Amount_of_milk << " " << fridge1.Amount_of_meat << " " << fridge1.Amount_of_chees << " "
					<< fridge1.Amount_of_candies << endl;
			}
		}
	}
	if (n == 2)
	{
		cout <<
			"Введите первоначальное количество 1.молока,2.мяса,3.сыра,4.печенья соответсвенно.Далее,чтобы произвести какие-либо операции,обращайтесь к объектам через номера,указанные выше." << endl;
		cin >> fridge2.Amount_of_milk;
		cin >> fridge2.Amount_of_meat;
		cin >> fridge2.Amount_of_chees;
		cin >> fridge2.Amount_of_candies;
		int exit1 = 1;
		while (exit1 == 1)
		{
			cout <<
				"Введите 1,чтобы остаться или 0,чтобы выйти.Если хотите произвести какую-либо математическую операцию,введите знак (+ или -),затем порядковый номер.Напоминание (1-молоко,2-мясо,3-сыр,4-печенье),затем число,на которое параметр будет изменён" << endl;
			char znak;
			int nomer, amount;
			cin >> exit1;
			if (exit1 == 0) { return -1; }
			if (exit1 != 0) { cin >> znak >> nomer >> amount; }
			if (znak == '+')
			{
				if (nomer == 1)
				{
					fridge2.Amount_of_milk += amount;
				}
				if (nomer == 2)
				{
					fridge2.Amount_of_meat += amount;
				}
				if (nomer == 3)
				{
					fridge2.Amount_of_chees += amount;
				}
				if (nomer == 4)
				{
					fridge2.Amount_of_candies += amount;
				}
				cout << fridge2.Amount_of_milk << " " << fridge2.Amount_of_meat << " " << fridge2.Amount_of_chees << " "
					<< fridge2.Amount_of_candies << endl;
			}
			if (znak == '-')
			{
				if (nomer == 1)
				{
					fridge2.Amount_of_milk -= amount;
				}
				if (nomer == 2)
				{
					fridge2.Amount_of_meat -= amount;
				}
				if (nomer == 3)
				{
					fridge2.Amount_of_chees -= amount;
				}
				if (nomer == 4)
				{
					fridge2.Amount_of_candies -= amount;
				}
				cout << fridge2.Amount_of_milk << " " << fridge2.Amount_of_meat << " " << fridge2.Amount_of_chees << " "
					<< fridge2.Amount_of_candies << endl;
			}
		}
	}
}