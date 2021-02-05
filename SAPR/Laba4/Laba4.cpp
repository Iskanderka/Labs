#include <iostream>
#include <string>

using namespace std;

struct Stack {
    string word;
    struct Stack* next;
};

string Pop_Stack(Stack*& Top_Stack) {
    string elem = Top_Stack->word;
    struct Stack* tmp = Top_Stack;
    Top_Stack = Top_Stack->next;
    delete tmp;
    return elem;
}

void Print_Stack(struct Stack*& Top_Stack) {
    while (Top_Stack != NULL) {
        cout << Pop_Stack(Top_Stack) << "\t";
    }
    cout << "\n";
}

void Push_Stack(string NewElem, struct Stack*& Top_Stack) {
    struct Stack* tmp = new Stack;
    tmp->word = NewElem;
    tmp->next = Top_Stack;
    Top_Stack = tmp;
}

void  Make_Stack(int n, struct Stack*& Top_Stack) {
    if (n > 0) {
        string tmp;
        cout << "Введите значение ";
        cin >> tmp;
        Push_Stack(tmp, Top_Stack);
        Make_Stack(n - 1, Top_Stack);
    }
}

void remov(struct Stack* Top_Stack1, struct Stack* Top_Stack2, struct Stack*& Top_Stack3) {
    int flag = -1;
    struct Stack* tmp1 = Top_Stack1;
    struct Stack* tmp2 = Top_Stack2;
    while ((tmp1 != NULL) || (tmp2 != NULL)) {
        if (flag == -1 && tmp1 != NULL) {
            if (tolower(tmp1->word[0]) == tolower(tmp1->word[tmp1->word.size() - 1])) {
                Push_Stack(tmp1->word, Top_Stack3);
            }
            tmp1 = tmp1->next;
        }
        else if (flag == 1 && tmp2 != NULL) {
            if (tolower(tmp2->word[0]) == tolower(tmp2->word[tmp2->word.size() - 1])) {
                Push_Stack(tmp2->word, Top_Stack3);
            }
            tmp2 = tmp2->next;
        }
        flag = flag * -1;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    struct Stack* Stack1 = NULL;
    struct Stack* Stack2 = NULL;
    struct Stack* Stack3 = NULL;
    int n1, n2;

    cout << "Введите количество элементов в 1 списке: ";
    cin >> n1;

    cout << "Введите количество элементов в 2 списке: ";
    cin >> n2;

    cout << "1" << endl;
    Make_Stack(n1, Stack1);
    cout << "2" << endl;
    Make_Stack(n2, Stack2);

    remov(Stack1, Stack2, Stack3);

    Print_Stack(Stack3);
    delete Stack1;
    delete Stack2;
    delete Stack3;
}