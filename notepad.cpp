#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;
string temp = "temp.txt";
template<typename T>
class List {
public:
    class Node {
    public:
        T value;
        Node* prev;
        Node* next;

        Node(){
            value = 0;
            prev = nullptr;
            next = nullptr;
        }
        Node(T val){
            value = val;
            prev = nullptr;
            next = nullptr;
        }
        Node(T val, Node* prv, Node* nxt){
            value = val;
            prev = prv;
            next = nxt;
        }
    };
    List() {
        head = new Node();
        tail = head;
        cursor = head; 
        size = 0;
    }

    ~List() {
        Node* current = head;
        while (current!=nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    void insert(T value) {
        Node* temp = new Node(value, cursor, cursor->next);
        if (cursor->next!=nullptr)
        {
            cursor->next->prev = temp;
        }
        else 
        {
            tail = temp; 
        }
        cursor->next = temp;
        cursor = temp; 
        size++;
    }

    void _delete() {
        if (cursor == head)
        {
            return;
        }
        Node* temp = cursor;
        cursor = cursor->prev;
        cursor->next = temp->next;
        if (temp->next!=nullptr)
        {
            temp->next->prev = cursor;
        }
        else {
            tail = cursor; 
        }
        delete temp;
        size--;
    }

    void moveLeft() 
    {
        if (cursor != head) {
            cursor = cursor->prev;
        }
    }

    void moveRight() {
        if (cursor->next!=nullptr) {
            cursor = cursor->next;
        }
    }

    int currlocation()const {
        int index = 0;
        Node* current = head;
        while (current != cursor) {
            current = current->next;
            index++; 
        }
        return index;
    }

    string tostring() const {
        string result;
        Node* curr = head->next; 
        while (curr!=nullptr) {
            if (curr == cursor->next) { 
                result += "|";
            }
            result += curr->value;
            curr = curr->next;
        }
        if (cursor == tail) { 
            result += "|";
        }
        return result;
    }


    void display() const {
        system("CLS"); // Clear the console

        string displayText = tostring();
        cout << displayText << endl;
        cout << "\n\n\n\n\n\n";
        cout << "Cursor Position: " << currlocation() << endl;
    }
    Node* head;    
    Node* tail;    
    Node* cursor;  
    int size;      
};
void readfromfile(string name, List<char>& a)
{
    fstream file(name, ios::in);
    char ch;
    while (file.get(ch)) {
        a.insert(ch);
    }
    file.close();
}
void writetofile(string name, List<char>& a)
{
    fstream file(name, ios::out);
    List<char>::Node* current = a.head->next;
    while (current) {
        file.put(current->value);
        current = current->next;
    }
    file.close();
}

void notepad(string filename) 
{
    List<char> list_main;
    readfromfile(filename, list_main);
    list_main.display(); 
    while (true) {
        char c = _getch(); 

        if (c == 27) { 
            break;
        }

        if (c == 13) { 
            list_main.insert('\n');
        }
        else if (c == 8) { 
            list_main._delete();
        }
        else if (c == -32) { 
            char arrow = _getch(); 
            if (arrow == 75) { 
                list_main.moveLeft();
            }
            else if (arrow == 77) { 
                list_main.moveRight();
            }
        }
        else
        { 
            list_main.insert(c);
        }
        writetofile(filename, list_main);
        list_main.display(); 
    }
}

int main() 
{
    char a = '\0';
        cout << "Enter name of your file\n";
        string name;
        cin >> name;
        name = name + ".txt";
        fstream file(name);
        if (file.is_open())
        {
            cout << "File opened\n";
        }
        notepad(name);
    
}