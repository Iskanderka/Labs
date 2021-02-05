#include <iostream>
#include <string>

using namespace std;

struct Word {
    string word;
    struct Word* next;
};

void make_list(int n, struct Word** head) {
    if (n > 0) {
        (*head) = new Word();
        cout << "Введите слова: ";
        cin >> (*head)->word;
        (*head)->next = NULL;
        make_list(n - 1, &((*head)->next));
    }
}

void print_list(struct Word* head) {
    if (head != NULL) {
        cout << head->word << "\t";
        print_list(head->next);
    }
    else cout << "\n";
}

int count_words(struct Word* head) {
    int c = 0;
    struct Word *ptr, *next;
    ptr = head;
    while (ptr != NULL) {
        if (ptr->next != NULL) {
            next = ptr->next;
            if (ptr->word[0] == next->word[0]) c++;
        }
        ptr = ptr->next;
    }
    return c;
}

void delete_list(struct Word* head) {
    if (head != NULL) {
        delete_list(head->next);
        delete head;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    struct Word* head;
    int n;
    string word;

    cout << "Введите количество элементов в списке: ";
    cin >> n;
    
    make_list(n, &head);

    print_list(head);

    cout << "Количество искомых слов - " << count_words(head) << endl;

    delete_list(head);
}