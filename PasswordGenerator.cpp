#include <iostream>
#include <fstream>
#include <string>
#include <random>
using namespace std;
int main()
{   
    string service = "...";
    string login  = "...";
    string user_file = "qwerty.txt"; 
    bool spec_char = false;
    int length = 25; 
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    if (spec_char == true)
        chars += "!@#$%^&*()_+-=[]{}|;:,.<>?";

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(0, chars.size()-1);

    string pass;
    for (int i = 0;i != length-1; i++)
    {
        pass += chars[dist(gen)]; 
    }
    // --unique symbols-- 
    for (int i = 0;i < length-1;i++)
    {
        for(int j = 0 ;j < i;j++)
        {
            if(pass[i] == pass[j])
            {
                pass[i] = chars[dist(gen)];
                j = -1;
            }
        }
    }
    // --unique symbols--
    ofstream file(user_file, ofstream::app); // open file and start writing
    file << "==================================" << endl;
    file << "Service: " << service << endl;
    file << "login: " << login << endl;
    file << "Password: " << pass << endl;
    file.close(); 
    cout << "Data written." << endl; return 0;
}