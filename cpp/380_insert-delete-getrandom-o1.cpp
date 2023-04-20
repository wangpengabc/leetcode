// https://leetcode.cn/problems/insert-delete-getrandom-o1/
// 数据结构设计； hash map + 数组

class RandomizedSet {
public:
    vector<int> item_v;
    unordered_map<int, int> numToidx;
    random_device rd;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        // cout << "insert" << endl;
        if (numToidx.count(val)) {
            return false;
        }
        numToidx.insert({val, item_v.size()});
        item_v.push_back(val);
        
        // cout << "Insert item_v: ";
        // for_each(item_v.begin(), item_v.end(), [](int item_num){ cout << item_num << " ";});
        // cout << endl;

        return true;
    }
    
    bool remove(int val) {
        // cout << "remove" << endl;
        if (!numToidx.count(val)) {
            // cout << "false" << endl;
            return false;
        }
        // cout << "remove" << endl;
        int last_val = item_v.back();
        // cout << "remove" << endl;

        int val_idx = numToidx[val];
        // swap(item_v[val_idx], item_v.end());
        item_v[val_idx] = last_val;
        item_v.pop_back();
        numToidx.erase(val);
        if (numToidx.size() == 0) {
            return true;
        }
        numToidx[last_val] = val_idx;
        return true;
    }
    
    int getRandom() {
        if (item_v.size() == 1) {
            return item_v[0];
        }
        uniform_int_distribution<int> uid(0, item_v.size()-1);
        int idx = uid(rd);

        // cout << "idx: " << idx << endl;
        // cout << "getRandom item_v: ";
        // for_each(item_v.begin(), item_v.end(), [](int item_num){ cout << item_num << " ";});
        // cout << endl;

        return item_v.at(idx);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
