vector<string> kirp(string str){
    vector<string> result;
    if (str.length() == 0)     return result;

    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    string indent = "";
    string curr = "";
    int i = 0, len = str.length();
    
    while (i < len){
        curr.push_back(str[i]);
        switch(str[i]){
            case ',':
                result.push_back(curr);
                curr = indent;
                i++;
                break;

            case ':':
                i++;
                if (str[i] == '{' || str[i] == '['){
                    result.push_back(curr);
                    curr = indent;
                }
                break;

            case '{':
            case '[':
                i++;
                result.push_back(curr);
                if (i < len && (str[i] != '}' || str[i] != ']')){
                    indent.push_back('\t');
                }
                curr = indent;
                break;

            case '}':
            case ']':
                i++;
                if (i < len && str[i] == ',') break;
                result.push_back(curr);
                if (i < len && (str[i] == '}' || str[i] == ']')){
                    if (!indent.empty()) indent.pop_back();
                }
                curr = indent;
                break;

            default : 
                i++;
                if (i < len && (str[i] == '}' || str[i] == ']')){
                    result.push_back(curr);
                    if (!indent.empty()) indent.pop_back();
                    curr = indent;
                }
        }
    }
    return result;
}


vector<string> Solution::prettyJSON(string A) {
    return kirp(A);
}