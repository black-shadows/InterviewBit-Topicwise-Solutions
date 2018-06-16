#define pb push_back

string genRow(vector<string> &words, int max_row_length, int cur_row_length){
    int spaceSayisi = words.size()-1;
    if(!spaceSayisi)    spaceSayisi = -1;
    int bslksz = cur_row_length - spaceSayisi;
    int base_white = (max_row_length - bslksz)/spaceSayisi;
    int kalanlar = (max_row_length - bslksz)%spaceSayisi;
    
    string row = words[0];
    for(int i=1 ; i<words.size() ; ++i){
        int cur_white = base_white;
        if(kalanlar)    cur_white++, kalanlar--;
        row += string(cur_white, ' ');
        row += words[i];
    }
    
    string pad = string( max_row_length - (int)row.size() , ' ');
    row += pad;
    return row;
}

string sonSatir(vector<string> &words, int max_row_length){
    string res = words[0];
    for(int i=1 ; i<words.size() ; ++i)     res+= " " + words[i];
    string pad = string( max_row_length - res.size() , ' ');
    return res+pad;
}

vector<string> Solution::fullJustify(vector<string> &vec, int max_row_length) {
    vector<string> res, satir;  
    if(!vec.size())     return res;
    satir.pb(vec[0]);
    int cur_len = vec[0].size();

    for(int i=1 ; i<vec.size() ; ++i){
        if(cur_len+1+vec[i].size() <= max_row_length){
            satir.pb(vec[i]);
            cur_len += 1 + vec[i].size();
        }
        else{
            res.pb(genRow(satir, max_row_length, cur_len));
            satir.clear();
            satir.pb(vec[i]);
            cur_len = vec[i].size();
        }
    }
    res.pb(sonSatir(satir, max_row_length));
    
    return res;
}