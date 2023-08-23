class RandomizedCollection {
    vector<int> valArr;
    unordered_map<int, set<int>> indMap; //value to indices in array
public:
    RandomizedCollection() {
        
    }
    
        bool insert(int val) {
        bool ret = true;
        valArr.push_back(val);
        if(indMap.count(val)){
            ret = false;
        }
        indMap[val].insert(valArr.size()-1);
        return ret;
    }
    
    bool remove(int val) {
         if(indMap.count(val)){
            int index = *indMap[val].rbegin();
            indMap[val].erase(index);
            cout << val << " " << index << endl;
            if(index != valArr.size()-1){
                valArr[index] = valArr.back();
                indMap[valArr[index]].insert(index);
                indMap[valArr[valArr.size()-1]].erase(valArr.size()-1);
            }
            valArr.pop_back();
            if(indMap[val].size() == 0)
                indMap.erase(val);      
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int rnd = rand()%valArr.size();
        return valArr[rnd];
    }
};
/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */