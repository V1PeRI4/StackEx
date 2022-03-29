#include <iostream>
#include <cstring>

using namespace std;

struct Stack{
    int info;
    Stack* next;
} *beginStack, * t;


Stack* InStack(Stack* p, int in) {
    Stack* t = new Stack; 
    t->info = in; 
    t->next = p; 
    return t;
}


void viewStack(Stack* p) {
    Stack* t = p;
    while (t != NULL) {
        cout << " " << t->info << endl;
        t = t->next;
    }
}


void delStack(Stack** p) {
    while (*p != NULL) {
        t = *p;
        *p = (*p)->next;
        delete t;
    }
}


int findMaxEl(Stack* p) {
    int  result = 0;
    Stack* t = p;
    while (t != NULL) {
        if (result < t->info)
            result = t->info;

        t = t->next;
    }
    return result;
}


int findMinEl(Stack* p) {
    int  result = 99999;
    Stack* t = p;
    while (t != NULL) {
        if (result > t->info)
            result = t->info;

        t = t->next;
    }
    return result;
}


void delElBetweenMinAndMax(Stack* p) {
    int valueMaxEl = findMaxEl(beginStack);
    int valueMinEl = findMinEl(beginStack);

    cout << "Элементы между {" << valueMaxEl << "} и {" << valueMinEl << "} удалены..." << endl;
    
    Stack* t = p;
    while (t != NULL) {

        if (t->info == valueMinEl || t->info == valueMaxEl)
        {
            while (true)
            {
                t = t->next;

                if (t->info == valueMinEl || t->info == valueMaxEl)
                {
                    break;
                }
                t->info = NULL;
            }
        }
        t = t->next;
    }
}


int main() 
{
    setlocale(LC_ALL, "Russian");

    int i, in, n, command;

    while (true) {
        system("cls");
        
        cout << "\n1. Создать стэк."
            "\n2. Добавить элементы в стэк."
            "\n3. Посмотреть стэк."
            "\n4. Найти максимальный и минимальный элементы и удалить значения между ними."
            "\n5. Удалить стек."
            "\n0. Выход.\n" << endl;
        cin >> command;
        switch (command) {
        default:
            cout << "Неизвестная команда" << endl;
            break;

        case 1: case 2:
            
            if (command == 1 && beginStack != NULL) {
                cout << "Очистка памяти" << endl;

                system("pause");
                break;
            }
            cout << "Введите кол-во элементов: ";
            cin >> n;
            for (i = 1; i <= n; i++) {
                in = rand();
                beginStack = InStack(beginStack, in);
            }
            if (command == 1)
                cout << "Создано " << n << " эл." << endl;
            else cout << "Добавлено " << n << " эл." << endl;

            system("pause");
            break;

        case 3:
            if (!beginStack) {
                cout << "Стэк пуст!" << endl;

                system("pause");
                break;
            }

            cout << "\n---Stack ---" << endl;
            viewStack(beginStack);

            system("pause");
            break;

        case 4:
            if (!beginStack) {
                cout << "Стэк пуст!" << endl;

                system("pause");
                break;
            }
            
            delElBetweenMinAndMax(beginStack);

            system("pause");
            break;

        case 5:
            delStack(&beginStack);
            cout << "Память чиста!" << endl;

            system("pause");
            break;

        case 0:
            if (beginStack != NULL)
                delStack(&beginStack);

            system("pause");
            return 0;
        }
    }


}