vector<string> Solution::fizzBuzz(int A) {
    vector<string> out;
    for(int i=1; i<=A; i++){
        if(i %15 ==0){
            out.push_back("FizzBuzz");
        }else if(i%5 == 0){
            out.push_back("Buzz");
        }else if(i%3 ==0){
            out.push_back("Fizz");
        }else{
            out.push_back(to_string(i));
        }
    }
    return out;
}