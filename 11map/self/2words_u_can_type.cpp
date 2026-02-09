//lc 1935

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,bool>m;
        for(int i=0;i<brokenLetters.size();i++){
            m[brokenLetters[i]]=true;
        }
        int count=0;
        int flag=1;
        for(int i=0;i<text.size();i++){
            if(m[text[i]]){
                flag=0; // broken key ..yeh word nhi hopayega
            }
            if(text[i]==' '){ // word khatm
                if(flag==1) count++; // koi. broken key nhi thi ...count this word
                else flag=1; //flag==0 hai mtlb broken key thi...isko count nhi krege...new word dekho ab
            }
        }
        if(flag==1) count++; // last word

        return count;
    }
};