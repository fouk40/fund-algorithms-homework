#include "warehouse.h"
#include "product.h"
#include "int_to_char.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int code = 100;

void input_max_products(int &n) {
    do {
        cout << "Max products: ";
        cin >> n;
    } while (n <= 0);
}

Warehouse::Warehouse() {
    char tmp[4];
    strcpy(id, "W");
    strcat(id, int_to_char(code++, tmp));
    type = center;
    longitude = 94;
    lattitude = 61.5;
    capacity = 0;
    stock = 0;
    free_space = 0;
    list = nullptr;
    size = 0;
    max_size = 0;
}

Warehouse::Warehouse(Category type, double longitude, double lattitude, int capacity, int max_size) {
    char tmp[4];
    strcpy(id, "W");
    strcat(id, int_to_char(code++, tmp));
    normalize_position(longitude, lattitude, type);
    this->type = type;
    this->longitude = longitude;
    this->lattitude = lattitude;
    this->capacity = capacity;
    stock = 0;
    free_space = capacity;
    list = new Product[max_size];
    size = 0;
    this->max_size = max_size;
}

Warehouse::Warehouse(const Warehouse &w) {
    strcpy(id, w.id);
    type = w.type;
    longitude = w.longitude;
    lattitude = w.lattitude;
    capacity = w.capacity;
    stock = w.stock;
    free_space = capacity - stock;
    list = new Product[w.max_size];

    for (int i = 0; i < w.size; i++) {
        list[i] = w.list[i];
    }

    size = w.size;
    max_size = w.max_size;
}

Warehouse::~Warehouse() {
    delete [] list;
}

void Warehouse::normalize_position(double &longitude, double &lattitude, Category &type) {
    if (longitude < 19) {
        longitude = 19;
    } else if (longitude > 169) {
        longitude = 169;
    }

    if (lattitude < 41) {
        lattitude = 41;
    } else if (lattitude > 82) {
        lattitude = 82;
    }

    if (longitude > 19 && longitude < 69) {
        type = west;
    } else if (longitude > 69 && longitude < 119) {
        type = center;
    } else {
        type = east;
    }
}

void Warehouse::insert_product(const char description[51], double price, int quantity, double longitude, double lattitude){
    list[size].set_code();
    strcpy(list[size].description, description);
    list[size].price = price;
    list[size].quantity = quantity;

    if (list[size].quantity > free_space){
        list[size].quantity = free_space;
        free_space = 0;
    } else {
        free_space -= list[size].quantity;
    }

    stock += list[size].quantity;

    list[size].longitude = longitude;
    
    list[size].lattitude = lattitude;
    
    size++;
}

Product Warehouse::get_product(int pos) {
    return list[pos];
}

void Warehouse::print_products() {
    cout << left;
    cout << setw(15) << "Code" <<
            setw(15) << "Description" <<
            setw(10) << "Price" <<
            setw(10) << "Quantity" <<
            setw(10) << "Longitude" << 
            setw(10) << "Lattitude" << endl;
    cout << "-------------------------------------------------" << endl;

    for (int i = 0; i < size; i++){
        list[i].print();
    }
}

int Warehouse::search_product(const char description[51]) {
    int pos;

    for (int i = 0; i < size; i++) {
        if (strcmp(list[i].description, description) == 0) {
            pos = i;
            return pos;
        }
    }
    
    return -1;
}

void Warehouse::delete_product(const char description[51]) {
    int pos = search_product(description);

    if (pos != -1) {
        stock -= list[pos].quantity;
        free_space += list[pos].quantity;

        for (int i = pos; i < size - 1; i++) {
            list[i] = list[i+1];
        }
        size--;

        cout << "Product is deleted!" << endl;
    } else {
        cout << "Product is not found!" << endl;
    }
}

double calc_distance(const Warehouse &w, double longitude, double lattitude) {
    return abs(w.lattitude - lattitude) + abs(w.longitude - longitude);
}