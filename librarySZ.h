#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>

using namespace std;

#ifndef librarySZ_h
#define librarySZ_h 1

class pair_of_numbers {
public:
    int x;
    int y;
};

bool getNumber (int &);
int random_number (int);
void make_set_of_questions (pair_of_numbers *, int, int);
void question (int, int, bool &, bool &, bool &);
void wait (int, bool &, bool &, bool &);

#endif // librarySZ_h
