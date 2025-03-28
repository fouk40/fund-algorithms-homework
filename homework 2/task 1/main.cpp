#include "warehouse.h"
#include "product.h"
#include "menu.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    srand(time(0));

    int n, opt;
    input_max_products(n);

    Warehouse w1(center, 72, 65, 10, n);
    Warehouse w2(west, 23, 44, 20, n);
    Warehouse w3(east, 138, 55, 30, n);

    Warehouse list[3] = {w1, w2, w3};

    do {
        menu(opt);

        switch (opt) {
            case 1:
                insert_product(list);
                break;
            case 2:
                print_list(list);
                break;
            case 3:
                search_product(list);
                break;
            case 4:
                delete_product(list);
                break;
            case 5:
                cout << "Exit from programm!" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while (opt != 5);
}