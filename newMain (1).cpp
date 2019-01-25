#include <iostream>
#include <unistd.h>
#include <string>
#include <ctime>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    //write data to file
    ofstream fout;
    
    fout.open("recordfile.txt",ios::app);
    string input_name;
    
    cout<<"Register your name:\n";
    cin>>input_name;
    
    int secretKey=1;
    
    char input_nameArrary[input_name.length()];
    strcpy(input_nameArrary, input_name.c_str());
    
    for (int i=0; i<input_name.length(); i++){
        secretKey = secretKey * (int)input_nameArrary[i] ;
    }
    //write user email address and secret key to the file (server).
    input_name = input_name + "\n"+ to_string(abs(secretKey))+"\n";
    fout<< input_name;
    
    long newKey = 0;
    for(;;){
        int newKey_array[6];//6 digits array.
        for(int i=18; i<28; i++){
            std::time_t real_time = std::time(nullptr);//epoch time
            newKey= abs(real_time/i-secretKey);
            for (int i = 0; i <6; i++) {
                newKey_array[i] = newKey % 10;
                newKey /= 10;
            }
            //conver char to string
            char outputKey[6];
            string str;
            for (int i = 5; i>=0; i--){
                outputKey[i] = ((char)newKey_array[i]+48);//In ascii table, number starts from 48
                str= str+ outputKey[i];
            }
            cout << str;
            cout << endl;
            
            //write to file, make sure each line is string
            fout << str << endl;
            fout.close();
            fout.open("recordfile.txt",ios::app);
            
            sleep(10);//for test purpose, we use delay 10 seconds
        }
        
    }
    
    return 0;
    
}

