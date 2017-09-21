#include "librarySZ.h"

int _max, _loop, _time;
double _winCount = 0;

bool getNumber (int &x)
{
    cin.clear();
    cin.sync();

    cin >> x;
    return cin.good();
}

int random_number (int to)
{
    return rand()%to + 1;
}

void make_set_of_questions (pair_of_numbers *pair, int table_size, int max_value)
{
    for (pair_of_numbers *ptr = pair; ptr < pair + table_size; ptr++){
        bool values_not_repeated = true;
        do
        {
            (ptr->x) = rand()%max_value + 1;
            (ptr->y) = rand()%max_value + 1;

            for (pair_of_numbers *j = pair; j != ptr; j++)
            {
                if (j->x == ptr->x && j->y == ptr->y)
                {
                    values_not_repeated = false;
                    break;
                }
                else
                    values_not_repeated = true;
            }
        }
        while(!values_not_repeated);
    }
}

void question (int setSize,  pair_of_numbers *ptr, bool &_timeOut, bool &_calcDone, bool &_threadOneFinished)
{
    _calcDone = false;
    _threadOneFinished = false;

    int _c;

    do
    {
        cout << (ptr + setSize)->x << " x " << (ptr + setSize)->y << " = ";
    }
    while (getNumber(_c) == false);

    _threadOneFinished = true;

    _calcDone = (((ptr + setSize)->x * (ptr + setSize)->y == _c) ? true : false);

    if (_timeOut == false && _calcDone == true)
        _winCount += 1;
    else if (_timeOut == true && _calcDone == true)
        _winCount += 0.5;
}

void wait (int x, bool &_timeOut, bool &_calcDone, bool &_threadOneFinished)
{
    _timeOut = false;

    int start = clock();
    while ((x * 1000) > (clock() - start) && !_threadOneFinished)
    {
        //wait
    }

    if (_threadOneFinished)
        cout << "\nIn time! Wait for next.\n";
    else if (!_threadOneFinished)
        cout << "\nYou're out of time! Answer correct and you'll get half a point.\n";

    _timeOut = true;

}
