#include <iostream>
#include "Date.h"

int main(int, char**){
    Date date {2026, 2, 25};
    date.print();

    Date date1 {};
    date1.print();

    Date date2 {date};
    date2.print();
}
