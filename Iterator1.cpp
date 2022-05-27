#include "List.h"
#include <iostream>
#include <list>
#include <time.h>
#include <windows.h>
#include <vector>
using namespace std;


unsigned counting(ListIterator* li) {
    unsigned cnt = 0;
    if (li->first())
        do {
            cnt++;
            cerr << li->currentItem() << " ";
        } while (li->next());
        cerr << endl;
        return cnt;
}

bool usl(int _pr)
{
    if (_pr + 5 == 8)
    {
        return true;
    }
    return false;
}

int main()
{
    list <int> lst;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(0));
    unsigned capacity, count;
    cout << "Введите объём стека: ";
    cin >> capacity;
    List list(capacity);
    cout << "Введите количество элементов для заполнения стека: ";
    cin >> count;
    for (unsigned i = 0; i < count; i++) {
        int x = rand() % 5;
        if (list.append(x))
            cout << x << " ";
    }
    cout << endl;



    ListIterator* litS3;
    ListIterator* litV4;
    ListIterator* litPred;

    try
    {
        litS3 = list.createIterator(Iterators::STEP, 3);
        litV4 = list.createIterator(Iterators::VALUE, 4);
        litPred = list.createIterator(Iterators::PREDICATE, 4, usl);
    }
    catch (exception& exc)
    {
        cout << exc.what();
        return 0;
    }

    cout << counting((ListIteratorStep*)litS3) << endl;
    cout << counting((ListIteratorValue*)litV4) << endl;
    cout << counting((ListIteratorPredicate*)litPred) << endl;


    delete litS3;
    delete litV4;
    delete litPred;


}
