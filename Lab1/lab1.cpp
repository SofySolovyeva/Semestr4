#include <iostream>

class cashRegister {
private:
    int cashOnHand = 300;
public:
    cashRegister() {}
    cashRegister(int cashIn) : cashOnHand(cashIn) {}
    int getCurrentBalance() { return cashOnHand; }
    void acceptAmount(int amountIn) { cashOnHand += amountIn; }
};

class dispenserType {
private:
    int numberOfItems;
    int cost;
public:
    dispenserType() : numberOfItems(50), cost(50) {}
    dispenserType(int setNoOfItems, int setCost) : numberOfItems(setNoOfItems), cost(setCost) {}
    int getNoOfItems() { return numberOfItems; }
    int getCost() { return cost; }
    void makeSale() { numberOfItems--; }
};

void showSelection();
void sellProduct(dispenserType& product, cashRegister& pCounter);

int main() {
    cashRegister counter;
    dispenserType candy(100, 50);
    dispenserType chocolate(100, 65);
    dispenserType gum(75, 45);
    dispenserType cookies(50, 85);

    int choice;
    showSelection();

    std::cin >> choice;

    while (choice != 5) {
        switch (choice) {
        case 1:
            sellProduct(candy, counter);
            break;
        case 2:
            sellProduct(chocolate, counter);
            break;
        case 3:
            sellProduct(gum, counter);
            break;
        case 4:
            sellProduct(cookies, counter);
            break;
        default:
            std::cout << "No such option available" << std::endl;
        }
        showSelection();
        std::cin >> choice;
    }

    return 0;
}

void showSelection() {
    std::cout << "Press: 1 for candy; 2 for chocolate; 3 for gum; 4 for cookies; 5 to go home" << std::endl;
}

void sellProduct(dispenserType& product, cashRegister& pCounter) {
    int amount, amount2;

    if (product.getNoOfItems() > 0) {
        std::cout << "Please deposit " << product.getCost() << " cents" << std::endl;
        std::cin >> amount;

        if (amount < product.getCost()) {
            std::cout << "Please deposit another " << product.getCost() - amount << " cents" << std::endl;
            std::cin >> amount2;
            amount += amount2;
        }

        if (amount >= product.getCost()) {
            int change = amount - product.getCost();
            if (change > 0) {
                std::cout << "Collect your change of " << change << " cents." << std::endl;
            }
            pCounter.acceptAmount(amount);
            product.makeSale();
            std::cout << "Collect your item at the bottom." << std::endl;
        }
        else {
            std::cout << "Insufficient funds. Collect what you deposited." << std::endl;
        }
    }
    else {
        std::cout << "Item is out of stock." << std::endl;
    }
}