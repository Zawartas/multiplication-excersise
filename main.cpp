#include "librarySZ.h"

extern int _max, _time, _a;
extern double _winCount;
bool _error, _timeOut = false, _calcDone,_threadOneFinished;
int _numberOfQuestions;

int main()
{
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

    if (_numberOfQuestions > _max){
        cout << "\n\nCan't have more tasks than maximum allowed numbers range. Program terminated.\n\n";
        return 0;
    }

    int *_questions = new int[_numberOfQuestions];
    pair_of_numbers *_questionsSet = new pair_of_numbers[_numberOfQuestions];


    make_table_of_questions (_questions, _numberOfQuestions, _max);
    make_set_of_questions (_questionsSet, _numberOfQuestions, _max);

//    for (int i = 0; i < _numberOfQuestions; i++)
    cout << _questionsSet->x << " " << _questionsSet->y << endl;

    do
    {
        cout << "How much time per one question? " ;
    }
    while (getNumber(_time) == false);


    for (int i = 0; i < _numberOfQuestions; i++)
    {

        thread first (question, _max, *(_questions + i), ref(_timeOut), ref(_calcDone), ref(_threadOneFinished));
        thread second (wait, _time, ref(_timeOut), ref(_calcDone), ref(_threadOneFinished));

        first.join();
        second.join();
    }

    cout << "Your score: " << _winCount << endl;

    return 0;
}
