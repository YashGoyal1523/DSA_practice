//lc 3403


// approach
// har index pe dekho and sabme se ans nikalo :
// har index se start hone wla longest substring jo bana skte (ie longest which is satisfying the condition of no of partions equals numFriends) voh lelo
// sabka max lelo


//tarika 1 to implement : khud
class Solution {
public:
    string answerString(string word, int numFriends) {

        if(numFriends == 1) return word;  //in our implementation yeh case alag handle krna padega

        string ans = "";
        int n = word.size();
        
        for(int i = 0; i < n; i++) {
            //curr idx se phle ke har element ko 1 length ka partition lelege // i partions bangye
            int prevcnt = i; // no of partitions bangye jo 
            int remcnt = numFriends - prevcnt; // rem no of partitions

            string temp="";
            if(remcnt <= 0 ) { // numFriends<=prevcnt //pichle partitons mein sabko 1 size ka hona zruri nhi // pichle 1 size ke partitions ke sizing adjust krlege and new partitions banalege (cnt>=1) such that rem cnt becomes 1 
            //and then ek partition bacha h voh
                temp = word.substr(i);  // Take the rest of the string as a single partition
            } else {
                // last se 1 size ke remcnt-1 partitions banadege  
                // ek partition bacha h... voh curr idx se rem string ka banadege
               // int len = (n - i) - (remcnt - 1);
               //or
               int len=n-(numFriends-1);
                temp = word.substr(i, len);
            }

            ans = max(ans, temp);
        }
        
        return ans;
    }
};


//tarika 2 to implement: mik
// https://youtu.be/P74WiyWY3Pk?si=lJ8KwO1i6LflqaU4

// class Solution {
// public:
//     string answerString(string word, int numFriends) {
//          if( numFriends == 1) // our implementation m yeh case alag se handle krna pdega
//             return word;

//         int n = word.length();

//         string result="";

//         // ek partition ka longest Len possible  :
//         // baaki sab 1 size ke partition banadiya
//         // numFriends-1 elements use krlie....
//         // rem elemnts is n - (numFriends - 1);
//         // so longest length possible of a partition :
//         int longestLenPossible = n - (numFriends - 1);

//         for(int i = 0; i < n; i++) {
//             int canTakeLongestLength = min(longestLenPossible, n-i);  // maybe uss index se aage longlenpossible jitne characters hi na bache ho......yaani iss case mein is idx se piche elements unused hai.....iss case mein hum iss partition m jitne isse aage bache h voh dedege and baaki sabko 1 size na deke unki sizing adjust krlege to fill up remaining elements in partitions 

//             result = max(result, word.substr(i, canTakeLongestLength));
//         }

//         return result;
//     }
// };


// humara method required partition ke aage and piche ke partitions ke handling khud hi krre and mik wale mein voh apne aap hori h