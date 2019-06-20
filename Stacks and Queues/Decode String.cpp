string decodeString(string s) {
    assert(s.size()<=100000);
    string res="";
    int number = 0;
    stack<int> numstack;
    stack<string> charstack;
    string characterCopy ="";
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>='0' && s[i]<='9')
                number = number*10 +(s[i]-'0');
        else if(s[i] == '['){
                numstack.push(number);
                number =0;
                charstack.push(characterCopy);
                characterCopy = "";
        }
        else if(s[i] == ']'){
                string temp = "";
                int n = numstack.top();
                numstack.pop();
                for(int i=0;i<n;i++)
                    temp+=characterCopy;
                characterCopy = charstack.top()+temp;
                charstack.pop();
            }
        else
            characterCopy+=s[i];
        }
    assert(characterCopy.size()<=200000);
    return characterCopy;
}

string Solution::solve(string A) {
    return decodeString(A);
}