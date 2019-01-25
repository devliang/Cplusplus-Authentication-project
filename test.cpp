#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
//exception throwing
class Invalid{
};
class AuthcodeFail{
};

int main(){
	
    ifstream fin;
    string email, code;
    cout << "Enter your email address: \n";
    cin >> email;

    fin.open("recordfile.txt");

    try{
        if(fin.fail()){
            throw Invalid();
        }
        
        string line1, line2;
        while (!fin.eof()){
        	getline(fin, line1);
        //compare email address user entered with the one recorded on file
        if(email == line1){
 			cout << "Email verified!" << endl;
 			break;
		}
		else{
			throw AuthcodeFail();
			break;
		}
		}
		
	cout << "Enter the code you received:\n";
    cin >> code;
    
		while (fin>>line2){
        }
		//compare authentication code user entered with the one recorded on file
        if(code == line2){
			cout << "\nSuccess! Code is verified! You can login now!";
		}
		else{
			throw AuthcodeFail();
		}
		
    }
    catch(Invalid){
        cout << "Invalid!!" << endl;
        exit(1);        
    }
    
    catch(AuthcodeFail){
    	cout << "Code is not correct or has already expired!" << endl;
		exit(1);
	}
    fin.close();    
    
    return 0;
    
}

