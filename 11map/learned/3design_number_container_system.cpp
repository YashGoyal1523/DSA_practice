//lc 2349

//https://youtu.be/689qj769Gt4?si=Gjsw9nck86dmEKoV

class NumberContainers {
public:
    unordered_map<int, set<int>> valueIdx;
    unordered_map<int,int>idxValue;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        int prevValue=idxValue[index];
        if(prevValue!=0){ // phle se number h index pe
            // no hatao
            idxValue[index]=0;
            valueIdx[prevValue].erase(index);
        }
        // no lagao
        idxValue[index]=number;
        valueIdx[number].insert(index);
    }
    
    int find(int number) {
       if(valueIdx[number].empty()) return -1;

       return *valueIdx[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */