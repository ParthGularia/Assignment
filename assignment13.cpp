#include<iostream>
using namespace std;
class MenuItem {
private:
    string itemName;
    int quantity;
    int pricePerItem;
public:
    MenuItem(string name, int price) : itemName(name), pricePerItem(price), quantity(0) {}
    void addQuantity(int qty) {
        quantity += qty;
    }
    int getQuantity() const {
        return quantity;
    }
    string getItemName() const {
        return itemName;
    }
    int getPricePerItem() const {
        return pricePerItem;
    }
    int calculateCost() const {
        return quantity * pricePerItem;
    }
};
class Pizza : public MenuItem {
public:
    Pizza() : MenuItem("Pizza", 120) {}
};
class Drink : public MenuItem {
public:
    Drink() : MenuItem("Coke", 55) {}
};
class Burger : public MenuItem {
public:
    Burger() : MenuItem("Burger", 60) {}
};
class Wrap : public MenuItem {
public:
    Wrap() : MenuItem("Wrap", 80) {}
};
class BillingSystem {
private:
    Pizza pizza;
    Drink drink;
    Burger burger;
    Wrap wrap;
public:
    BillingSystem() {}
    void addPizza(int qty) {
        pizza.addQuantity(qty);
    }
    void addDrink(int qty) {
        drink.addQuantity(qty);
    }
    void addBurger(int qty) {
        burger.addQuantity(qty);
    }
    void addWrap(int qty) {
        wrap.addQuantity(qty);
    }
    void printInvoice() const {
        int totalCost = pizza.calculateCost() + drink.calculateCost() + burger.calculateCost() + wrap.calculateCost();
        cout << "------------------------" << endl;
        cout << "        INVOICE         " << endl;
        cout << "------------------------" << endl;
        cout << "Item        Quantity     Cost" << endl;
        cout << "------------------------" << endl;
        cout << pizza.getItemName() << "          " << pizza.getQuantity() << "          " << pizza.calculateCost() << endl;
        cout << drink.getItemName() << "           " << drink.getQuantity() << "          " << drink.calculateCost() << endl;
        cout << burger.getItemName() << "         " << burger.getQuantity() << "          " << burger.calculateCost() << endl;
        cout << wrap.getItemName() << "           " << wrap.getQuantity() << "          " << wrap.calculateCost() << endl;
        cout << "------------------------" << endl;
        cout << "Total Cost: " << totalCost << endl;
    }
};
int main() {
    BillingSystem billSystem;  
    int pizzaQty, drinkQty, burgerQty, wrapQty;
    cout << "Enter the quantity of pizzas: ";
    cin >> pizzaQty;
    billSystem.addPizza(pizzaQty);
    cout << "Enter the quantity of drinks: ";
    cin >> drinkQty;
    billSystem.addDrink(drinkQty);
    cout << "Enter the quantity of burgers: ";
    cin >> burgerQty;
    billSystem.addBurger(burgerQty);
    cout << "Enter the quantity of wraps: ";
    cin >> wrapQty;
    billSystem.addWrap(wrapQty);
    billSystem.printInvoice();
    return 0;
}

