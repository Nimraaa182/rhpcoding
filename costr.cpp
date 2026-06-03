#include <iostream>
using namespace std;
int main() {
    cout<<"Enter a string:";
    string s;
    getline(cin,s);
    int k=1;
    for (int i=1;i<(1<<s.length());i++){
string p="";
for (int j=0;j<s.length();j++){
    if((i&(1<<j))>0){
        p+=s[j];
    }
}
cout<<k++<<". "<<p<<endl;
    }
}