#include<iostream>
using namespace std;
int main(){
string str;
cin>>str;
char ch;
cin.ignore();
cin>>ch;

for(int i=0;i<str.size();i++){
    if(str[i]==ch){
        cout<<str.erase(i,1);
    }
}
// cout<<str;
}