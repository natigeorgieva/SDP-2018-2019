#include <iostream>

#include "database.h"

using namespace std;

int main()
{
    Database db;
    ISIC card1("SU", "Peter Mitev", "9902125052", "FMI", 51999, "ASD1234FOOBAR555", 6, 2020);
    ISIC card2("SU", "Alexander Radev", "9906106558", "FMI", 51998, "ASD1224FOOBAR555", 6, 2020);
    ISIC card3("SU", "Rumen Stanev", "9923425452", "FMI", 51997, "ASD1234FOODBAR55", 6, 2020);

    db.add(card1);
    db.add(card2);
    db.add(card3);

    db.print();

    cout << endl << "after sorting" << endl << endl;

    db.sortByNames();
    db.print();

    return 0;
}
