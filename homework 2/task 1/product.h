#pragma once

class Product {
    public:
        char code[14];
        char description[51];
        double price;
        int quantity;
        double longitude;
        double lattitude;
    
    public:
        Product();
        Product(const char description[51], double price, int quantity, double longitude, double lattitude);
        Product(const Product &p);
        ~Product();
        void normalize_position(double &longitude, double &lattitude);
        void normalize_longitude(double &longitude);
        void normalize_lattitude(double &lattitude);
        void set_code();
        const char* get_code();
        void set_description(const char description[51]);
        const char* get_description();
        void set_price(double price);
        double get_price();
        void set_quantity(int quantity);
        int get_quantity();
        void set_longitude(double longitude);
        double get_longitude();
        void set_lattitude(double lattitude);
        double get_lattitude();
        void print();
};