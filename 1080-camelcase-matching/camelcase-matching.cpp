class Solution {
public:

/*
step 1: Create a function taking 2 strings and give output if pattern is matching
step 2: In the function I have to go through the query 
        - If there's a match, increment the patterns,queries pointer
        - Else
            -if lower case letter is required, increment the query alone
            - if capital letter is there in the query, return false
step 3: Continue step 2 until the pattern pointer reaches end/the query pointer reaches end.
step 3.5: go through query checking for capital letters, return false if any

step 4: Call the function for every element in the camelMatch array

Q = "FooBarTest"
         |
P = "FB"
       |

*/

//FooBarTest, FB
//    |

    bool helperFn(string query, string pattern){
        int ptr1=0,ptr2=0;

        while(ptr1<query.length() && ptr2<pattern.length()){
            if(query[ptr1]==pattern[ptr2]){
                ptr1++;
                ptr2++;
            }else{
                if(query[ptr1]>='a'&&query[ptr2]<='z'){
                    ptr1++;
                }else{
                    return false;
                }
            }
        }

        while(ptr1<query.length()){
            if(query[ptr1]>='A'&&query[ptr1]<='Z'){
                return false;
            }
            ptr1++;
        }
        return ptr2==pattern.length();
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {

        vector<bool> answer;
        for(auto query:queries){
            answer.push_back(helperFn(query,pattern));
        }

        return answer;
    }
};