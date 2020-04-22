#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::cout;
using std::endl;

int repeatedNumber(int *v, int s){
    unordered_map<int, int> hash;
    unordered_map<int, int>::iterator it;

    for(int i=0; i<s; i++){
        it = hash.find(v[i]);

        if(it == hash.end()){
            hash[v[i]] = 1;
        }
        else{
            it->second++;
        }
    }

    int max = -1;
    int key = -1;

    for(it=hash.begin(); it!=hash.end(); it++){
        if(it->second > max){
            max = it->second;
            key = it->first;
        }
    }

    return key;
}

int main(int argc, char const *argv[]){
    
    int v[] = {1, 2, 3, 4, 5, 6, 7, 9, 1, 3, 2, 3, 3, 2, 2, 2, 2};
    int s = sizeof(v)/sizeof(v[0]);
    
    int r = repeatedNumber(v, s);
    cout << "Max: " << r << endl;

    return 0;
}
