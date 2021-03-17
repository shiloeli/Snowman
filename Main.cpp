#include "snowman.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
using namespace ariel;

int main() {
    
    cout<<"Hello, please type number between 1-10 to get amount snowman depending on the number"<< endl;
    int in = 0;
    cin >> in;
    
    for(int i = 0; i < in; i++ ){
    int max_index = 8;
    int index = 0;
    string number = "";

    while(index < max_index){
        number += to_string(rand() % 4 + 1);
        index++;
    }

    std::cout<<"the number of snowman:"+number<<endl;
    int num = stoi( number );
    
    cout << ariel::snowman(num) << endl;
    }
    return 0;
}