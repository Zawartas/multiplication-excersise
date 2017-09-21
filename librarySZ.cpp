#include "librarySZ.h"

int _max, _loop, _time, _a;
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

void make_table_of_questions (int *_questions, int table_size, int max_value)
{
    for (int *i = _questions; i != _questions + table_size; i++)
    {
        bool values_not_repeated = true;
        do
        {
            *i = rand()%max_value + 1;
            for (int *j = _questions; j != i; j++)
            {
                if (*j == *i)
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

void make_set_of_questions (pair_of_numbers *pair, int table_size, int max_value)
{
    for (pair_of_numbers *i = pair; i < pair + table_size; i++){

        bool values_not_repeated = true;

        do
        {
            (pair->x) = rand()%max_value + 1;
            (pair->y) = rand()%max_value + 1;
            for (pair_of_numbers *j = pair; j != i; j++)
            {
                if (j->x == i->x && j->y == i->y)
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

void question (int x,  int _a, bool &_timeOut, bool &_calcDone, bool &_threadOneFinished)
{
    srand(time(nullptr));

    int _c, _b = random_number(x);
    _calcDone = false;
    _threadOneFinished = false;

    do
    {
        cout << _a << " x " << _b << " = ";
    }
    while (getNumber(_c) == false);

    _threadOneFinished = true;

    _calcDone = ((_a * _b == _c) ? true : false);

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
