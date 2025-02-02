void reverse(string &s,int size,int i){
    if(i > size/2){
        return;
    }
    swap(s[i],s[size-i]);
    return reverse(s,size,i+1);
}

int main(){
    string s;
    getline(cin,s);
    reverse(s,s.size()-1,0);
    cout << s;
}
//ekdum chillax beats 100%
