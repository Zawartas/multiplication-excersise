#include "librarySZ.h"

int random_number (int from, int to){

return rand()%to + from;
}

void question (int a, int b, bool d){
    cout << a << " x " << b << " = ";
    int c;
    cin >> c;

    d = (a*b == c)?true:false;
}
