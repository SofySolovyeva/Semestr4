#include <iostream>
class cashRegister
{
    private:
		int cashOnHand = 500; 
    public:
		cashRegister();
		cashRegister(int cashIn); 
		int getCurrentBalance();
		void acceptAmount(int amountIn);

};

class dispenserType
{
	private:
		int numberOfItems; 
		int cost;
	public:
		dispenserType();
		dispenserType(int setNoOfItems, int setCost);
		int getNoOfItems();	
		int getCost();
		void makeSale(); 
};

cashRegister::cashRegister(int cashIn)
{
	cashOnHand = cashIn;
}

int cashRegister::getCurrentBalance()
{
	return cashOnHand;
}

void cashRegister::acceptAmount(int amountIn)
{

	cashOnHand = cashOnHand + amountIn;
}

dispenserType::dispenserType()
{
	numberOfItems = 50;
	cost = 50;
}

dispenserType::dispenserType(int setNoOfItems, int setCost)
{
	numberOfItems = setNoOfItems;
	cost = setCost;
}

int dispenserType::getNoOfItems()
{
	return numberOfItems;
}

int dispenserType::getCost()
{
	return cost;
}

void dispenserType::makeSale()
{
	numberOfItems--;
}

void showSelection();
void sellProduct(dispenserType& product, cashRegister& pCounter);
int main()
{
	cashRegister counter;
	dispenserType candy(100, 50);
	dispenserType chokolate(100, 65);
	dispenserType gum(75, 45);
	dispenserType cookies(50, 85);
	int choice;
	showSelection();
	std::cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
			case 1:
				sellProduct(candy, counter);
				break;
			case 2:
				sellProduct(chokolate , counter);
				break;
			case 3:
				sellProduct(gum, counter);
				break;
			case 4:
				sellProduct(cookies, counter);
				break;
			default:
				std::cout << "Чё та такого нема" << std::endl;
		}
		showSelection();
		std::cin >> choice;
	}	
	return 0;
}

void showSelection()
{
	std::cout << "Жмякни: 1, если хочешь канфетку; 2, если шаколадку; 3 - жваченьку; 4 - печенку; 5, если потопал домой" << std::endl;
}

void sellProduct(dispenserType& product, cashRegister& pCounter)
{
	int amount; 
	int amount2;
	if (product.getNoOfItems() > 0) 
	{
		std::cout << "Please deposit " << product.getCost() << " центов" << std::endl;
		std::cin >> amount;
		if (amount < product.getCost())
		{
			std::cout << "Please deposit another " << product.getCost()- amount << " cents" << std::endl;
			std::cin >> amount2;
			amount = amount + amount2;
		}
		
		if (amount >= product.getCost())
		{
			pCounter.acceptAmount(amount);
			product.makeSale();
			std::cout << "Collect your item at the bottom and " << std::endl;
		}

		else
			std::cout << "Деняг не достчно " << "Collect what you deposited." << std::endl;
	}
	else
		std::cout << "Вкусняха закончилася()" << std::endl;
}
