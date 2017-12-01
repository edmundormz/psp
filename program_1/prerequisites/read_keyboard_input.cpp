#include<iostream>
#include<typeinfo>

using namespace std;

int main(){
    int i;
    std::string base = "n";
    std::string node_name;
    cout << "Enter a number\n";
    cin >> i;
    cout << "The value entered is " << i <<endl;
    node_name = base + std::to_string(i);
    cout << "node name is " << node_name << endl;
    //cout << typeid(i).name() << endl;
    return 0;
}
