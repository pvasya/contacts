#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void create(int &id, int size, string &filename, string *name, string *surname, string *address, string *email, string *company, string *birthday);
void open(int& id, int size, string &filename, string* name, string* surname, string* address, string* email, string* company, string* birthday);
void add(int& id, int size, string filename, string* name, string* surname, string* address, string* email, string* company, string* birthday);
void deletefunc(int& id, int size, string filename, string* name, string* surname, string* address, string* email, string* company, string* birthday);
void edit(int id, int size, string filename, string* name, string* surname, string* address, string* email, string* company, string* birthday);
void print(int const size, int const id, string name[], string sourname[], string address[], string email[], string company[], string birthday[]);

int main(){
    int id = 0;
    int const size = 25, arr_size = 1000;
    string current_command, temp, filename;
    string *name = new string[arr_size];
    string *surname = new string[arr_size];
    string *address = new string[arr_size];
    string *email = new string[arr_size];
    string *company = new string[arr_size];
    string *birthday = new string[arr_size];
    cout << "Hi!" << endl;
    cout << "Select or create new system" << endl;
    cout << "Use these commands: " << endl;
    cout << "Create a new system - create" << endl;
    cout << "Open - open" << endl;
    cout << "Add - add" << endl;
    cout << "Delete - delete" << endl;
    cout << "Edit - edit" << endl;
    cout << "Remove the system - remove" << endl;
    cout << "Close - close" << endl;
    while (1) {
        cout << ">>> ";
        cin >> current_command;
        if (current_command == "create") create(id, size, filename, name, surname, address, email, company, birthday);
        else if (current_command == "open") open(id, size, filename, name, surname, address, email, company, birthday);
        else if (current_command == "add") add(id, size, filename, name, surname, address, email, company, birthday);
        else if (current_command == "delete") deletefunc(id, size, filename, name, surname, address, email, company, birthday);
        else if (current_command == "edit") edit(id, size, filename, name, surname, address, email, company, birthday);
        else if (current_command == "remove") remove((filename+".txt").c_str());
        else if (current_command == "print") print(size, id, name, surname, address, email, company, birthday);
        else if (current_command == "close") exit(0);
        else cout << "Error, try again" << endl;
    }
}

void create(int& id, int size, string &filename, string* name, string* surname, string* address, string* email, string* company, string* birthday) {
    id = 0;
    fstream f;
    string str;
    cout << "Write a file name for cteating" << endl;
    cout << ">>> ";
    cin >> filename;
    f.open(filename + ".txt", ios::out);
    f.close();
    print(size, id, name, surname, address, email, company, birthday);
    cout << "File " << filename << ".txt" << " was created" << endl;
}

void open(int& id, int size, string &filename, string* name, string* surname, string* address, string* email, string* company, string* birthday) {
    id = 0;
    fstream f;
    string str;
    cout << "Write a file name for opening" << endl;
    cout << ">>> ";
    cin >> filename;
    f.open(filename + ".txt", ios::in);
    while (f.peek()!=EOF) {
        f >> str;
        if (!f.eof()) {
        name[id] = str;
        f >> str;
        surname[id] = str;
        f >> str;
        address[id] = str;
        f >> str;
        email[id] = str;
        f >> str;
        company[id] = str;
        f >> str;
        birthday[id] = str;
        id++;
        }
    }
    f.close();
    print(size, id, name, surname, address, email, company, birthday);
}

void edit(int id, int size, string filename, string* name, string* surname, string* address, string* email, string* company, string* birthday) {
    cout << "Enter ID to edit" << endl << ">>> ";
    string temp;
    int ie;
    cin >> ie;
    ie--;
    cout << "Enter what you want to edit" << endl << ">>> ";
    cin >> temp;
    if (temp == "name") cin >> name[ie];
    else if (temp == "surname")cin >> surname[ie];
    else if (temp == "address")cin >> address[ie];
    else if (temp == "email")cin >> email[ie];
    else if (temp == "company")cin >> company[ie];
    else if (temp == "birthday")cin >> birthday[ie];
    else cout << "Wrong"<<endl;
    ofstream f(filename+".txt", ios::out);
    for (int i = 0; i < id;i++) {
        f << name[i] << " " << surname[i] << " " << address[i] << " " << email[i] << " " << company[i] << " " << birthday[i] << endl;
    }
    f.close();
    print(size, id, name, surname, address, email, company, birthday);
}

void add(int& id, int size, string filename, string* name, string* surname, string* address, string* email, string* company, string* birthday) {
    cout << "Adding... name" << endl << ">>> ";
    cin >> name[id];
    cout << "Adding... surname" << endl << ">>> ";
    cin >> surname[id];
    cout << "Adding... address" << endl << ">>> ";
    cin >> address[id];
    cout << "Adding... email" << endl << ">>> ";
    cin >> email[id];
    cout << "Adding... company" << endl << ">>> ";
    cin >> company[id];
    cout << "Adding... birthdate" << endl << ">>> ";
    cin >> birthday[id];
    ofstream f(filename+".txt", ios::app);
    f << name[id] << " " << surname[id] << " " << address[id] << " " << email[id] + " " << company[id] << " " << birthday[id] << endl;
    f.close();
    id++;
    print(size, id, name, surname, address, email, company, birthday);
}

void deletefunc(int& id, int size, string filename, string* name, string* surname, string* address, string* email, string* company, string* birthday) {
    cout << "What ID do you want to delete?" << endl;
    int i;
    cin >> i;
    i--;
    id--;
    for (i; i < id; i++) {
        name[i] = name[i + 1];
        surname[i] = surname[i + 1];
        address[i] = address[i + 1];
        email[i] = email[i + 1];
        company[i] = company[i + 1];
        birthday[i] = birthday[i + 1];
    }
    ofstream f(filename+".txt", ios::out);
    for (int i = 0; i < id; i++) {
        f << name[i] << " " << surname[i] << " " << address[i] + " " << email[i] + " " << company[i] << " " << birthday[i] << endl;
    }
    f.close();
    print(size, id, name, surname, address, email, company, birthday);
}

void print(int const size, int const id, string name[], string surname[], string address[], string email[], string company[], string birthday[]) {
    cout << string(114, '-') << endl;
    cout << setw(size - 22) << "#" << setw(size - 15) << "NAME" << "|" << setw(size - 10) << "SURNAME" << "|" << setw(size) << "ADDRESS" << "|" << setw(size) << "EMAIL" << "|" << setw(size-10) << "COMPANY" << "|" << setw(size - 10) << "BIRTHDAY" << setw(size - 22)<<endl;
    cout << string(114, '-') << endl;
    for (int i = 0; i < id; i++) {
        cout <<setw(size - 22) << i+1 << setw(size - 15) << name[i] << "|" << setw(size - 10) << surname[i] << "|" << setw(size) << address[i] << "|" << setw(size) << email[i] << "|" << setw(size - 10) << company[i] << "|" << setw(size - 10) << birthday[i] << setw(size - 22)<< endl;
        cout << string(114, '-') << endl;
    }
}