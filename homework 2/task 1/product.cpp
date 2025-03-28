#include "product.h"
#include "int_to_char.h"
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

Product::Product() {
    // Change this
    char tmp1[2];
    char tmp2[7];
    strcpy(code, "460");
    strcat(code, int_to_char(9 - rand() % 9, tmp1));
    strcat(code, "000");
    strcat(code, int_to_char(999999 - rand() % 900000, tmp2));
    strcpy(description, "");
    price = 0;
    quantity = 0;
    longitude = 94;
    lattitude = 61.5;
}

Product::Product(const char description[51], double price, int quantity, double longitude, double lattitude) {
    // Change this
    char tmp1[2];
    char tmp2[7];
    strcpy(code, "460");
    strcat(code, int_to_char(9 - rand() % 9, tmp1));
    strcat(code, "000");
    strcat(code, int_to_char(999999 - rand() % 900000, tmp2));
    strcpy(this->description, description);
    this->price = price;
    this->quantity = quantity;
    normalize_position(longitude, lattitude);
    this->longitude = longitude;
    this->lattitude = lattitude;
}

Product::Product(const Product &p) {
    strcpy(code, p.code);
    strcpy(description, p.description);
    price = p.price;
    quantity = p.quantity;
    longitude = p.longitude;
    lattitude = p.lattitude;
}

Product::~Product() {}

void Product::normalize_position(double &longitude, double &lattitude) {
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
}

void Product::normalize_longitude(double &longitude) {
    if (longitude < 19) {
        longitude = 19;
    } else if (longitude > 169) {
        longitude = 169;
    }
}

void Product::normalize_lattitude(double &lattitude) {
    if (lattitude < 41) {
        lattitude = 41;
    } else if (lattitude > 82) {
        lattitude = 82;
    }
}

void Product::set_code() {
    // Change this
    char tmp1[2];
    char tmp2[7];
    strcpy(code, "460");
    strcat(code, int_to_char(9 - rand() % 9, tmp1));
    strcat(code, "000");
    strcat(code, int_to_char(999999 - rand() % 900000, tmp2));
}

const char* Product::get_code() {
    return code;
}

void Product::set_description(const char description[51]) {
    strcpy(this->description, description);
}

const char* Product::get_description() {
    return description;
}

void Product::set_price(double price) {
    this->price = price;
}

double Product::get_price() {
    return price;
}

void Product::set_quantity(int quantity) {
    this->quantity = quantity;
}

int Product::get_quantity() {
    return quantity;
}

void Product::set_longitude(double longitude) {
    normalize_longitude(longitude);
    this->longitude = longitude;
}

double Product::get_longitude() {
    return longitude;
}

void Product::set_lattitude(double lattitude) {
    normalize_lattitude(lattitude);
    this->lattitude = lattitude;
}

double Product::get_lattitude() {
    return lattitude;
}

void Product::print() {
    cout << setw(15) << code <<
    setw(15) << description <<
    setw(10) << price <<
    setw(10) << quantity <<
    setw(10) << longitude <<
    setw(10) << lattitude << endl;
}