#pragma once
#include "warehouse.h"
#include "product.h"
#include <cmath>
#include <iostream>

void insert_product(Warehouse list[3]);
void search_product(Warehouse list[3]);
void delete_product(Warehouse list[3]);
void print_list(Warehouse list[3]);
void menu(int &opt);