#include "librarySZ.h"

extern int _max, _time, _a;
extern double _winCount;
bool _error, _timeOut = false, _calcDone,_threadOneFinished;
int _numberOfQuestions;

int main()
{
    srand(time(nullptr));
    do
    {
        cout << "Numbers range? " ;
    }
    while (getNumber(_max) == false);

    do
    {
        cout << "How many questions? " ;
    }
    while (getNumber(_numberOfQuestions) == false);

    if (_numberOfQuestions > _max*_max){
        cout << "\nCan't have more tasks than "<< _max << "^" <<_max <<". \nProgram terminated.\n\n";
        return 0;
    }

    pair_of_numbers *_questionsSet = new pair_of_numbers[_numberOfQuestions];
    make_set_of_questions (_questionsSet, _numberOfQuestions, _max);

    do
    {
        cout << "How much time per one question? " ;
    }
    while (getNumber(_time) == false);


    for (int i = 0; i < _numberOfQuestions; i++)
    {
        thread first (question, i, _questionsSet, ref(_timeOut), ref(_calcDone), ref(_threadOneFinished));
        thread second (wait, _time, ref(_timeOut), ref(_calcDone), ref(_threadOneFinished));

        first.join();
        second.join();
    }

    cout << "Your score: " << _winCount << endl;

    return 0;
}
