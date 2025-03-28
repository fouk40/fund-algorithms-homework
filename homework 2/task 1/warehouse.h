#pragma once
#include "product.h"

extern int code;
enum Category {center, west, east};

class Warehouse {
    public:
        char id[5];
        Category type;
        double longitude;
        double lattitude;
        int capacity;
        int stock;
        int free_space;
        Product *list;
        int size;
        int max_size;
    
    public:
        Warehouse();
        Warehouse(Category type, double longitude, double lattitude, int capacity, int max_size);
        Warehouse(const Warehouse &w);
        ~Warehouse();
        void normalize_position(double &longitude, double &lattitude, Category &type);
        void insert_product(const char description[51], double price, int quantity, double longitude, double lattitude);
        Product get_product(int pos);
        void print_products();
        int search_product(const char description[51]);
        void delete_product(const char description[51]);
};

void input_max_products(int &n);
double calc_distance(const Warehouse &w, double longitude, double lattitude);