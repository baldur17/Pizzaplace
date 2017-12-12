#include "DrinksRepository.h"
#include <fstream>

void DrinksRepository::addDrink(const Drinks& drinks) {

    ofstream fout;
    fout.open("drinks.txt", ios::app);
    if (fout.is_open()) {
        fout << drinks;
        fout.close();
    }
}
