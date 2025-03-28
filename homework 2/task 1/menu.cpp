#include "warehouse.h"
#include "product.h"
#include "menu.h"
#include <iostream>

using namespace std;

void insert_product(Warehouse list[3]) {
    char description[51];
    int quantity;
    double price, longitude, lattitude;

    cout << "Insert new product" <<endl;

    cout << "Description: ";
    cin >> description;

    do {
        cout<< "Price: ";
        cin >> price;
    } while (price < 0);

    do {
        cout << "Quantity: ";
        cin >> quantity;
    } while (quantity <= 0);

    do {
        cout << "Longitude: ";
        cin >> longitude;
    } while (longitude < 19 || longitude > 169);

    do {
        cout<< "Lattitude: ";
        cin >> lattitude;
    } while (lattitude < 41 || lattitude > 82);

    if (calc_distance(list[0], longitude, lattitude) < calc_distance(list[1], longitude, lattitude) 
    && calc_distance(list[0], longitude, lattitude) < calc_distance(list[2], longitude, lattitude)) {
        if (list[0].size < list[0].max_size && list[0].free_space > 0) {
            list[0].insert_product(description, price, quantity, longitude, lattitude);
        } else {
            cout<< "Unable to insert into 1st warehouse!" <<endl;
        } 
    }

    if (calc_distance(list[1], longitude, lattitude) < calc_distance(list[0], longitude, lattitude) 
    && calc_distance(list[1], longitude, lattitude) < calc_distance(list[2], longitude, lattitude)) {
        if (list[1].size < list[1].max_size && list[1].free_space > 0) {
            list[1].insert_product(description, price, quantity, longitude, lattitude);
        } else {
            cout<< "Unable to insert into 2nd warehouse!" <<endl;
        }
    }

    if (calc_distance(list[2], longitude, lattitude) < calc_distance(list[0], longitude, lattitude) 
    && calc_distance(list[2], longitude, lattitude) < calc_distance(list[1], longitude, lattitude)) {
        if (list[2].size < list[2].max_size && list[2].free_space > 0) {
            list[2].insert_product(description, price, quantity, longitude, lattitude);
        } else {
            cout<< "Unable to insert into 3rd warehouse!" <<endl;
        }
    }
}

void search_product(Warehouse list[3]){
    char description[51];
    cout << "Search by description: ";
    cin >> description;

    for (int i = 0; i < 3; i++) {
        cout << "---------------" << list[i].id << "---------------" << endl;
        int pos = list[i].search_product(description);
        if (pos != -1) {
            list[i].get_product(pos).print();
        } else {
            cout<< "Product is not found!" << endl;
        }
    }
}

void delete_product(Warehouse list[3]) {
    int opt;
    char description[51];

    do {
        cout << "Choose warehouse: ";
        cin >> opt;
    } while (opt < 1 || opt > 3);

    cout << "Delete by description: "; 
    cin >> description;

    switch (opt) {
        case 1:
            list[0].delete_product(description);
            break;
        case 2:
            list[1].delete_product(description);
            break;
        case 3:
            list[2].delete_product(description);
            break;
    }
}

void print_list(Warehouse list[3]) {
    int opt;

    do {
        cout << "Choose warehouse: ";
        cin >> opt;
    } while (opt < 1 || opt > 3);

    switch (opt) {
        case 1:
            list[0].print_products();
            break;
        case 2:
            list[1].print_products();
            break;
        case 3:
            list[2].print_products();
            break;
    }  
}

void menu(int &opt)
{
    cout << left;
    cout << "--------------------" << endl;
    cout << "MENU OF PRODUCTS" << endl;
    cout << "--------------------" << endl;
    cout << "[1]. Insert product" << endl;
    cout << "[2]. Print list of products" << endl;
    cout << "[3]. Search product by description" << endl;
    cout << "[4]. Delete product" << endl;
    cout << "[5]. Exit" << endl;
    cout << "---------------------------------" << endl;
    cout << "Enter option: ";
    cin >> opt;  
}