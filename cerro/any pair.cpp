#include <iostream>
#include <algorithm>

/*
Any pair in array of integers which sum S
Input:
    v: array
    t: size of array
    s: sum
Output:
    true or false
*/

bool havePair(int *v, int t, int s){
    std::sort(v, v+t);

    int l = 0;
    int r = t-1;
    int tmp;

    while(l - r){
        tmp = v[l] + v[r];

        if(tmp == s){
            return true;
        }
        else if(tmp < s){
            l++;
        }
        else{
            r--;
        }
    }

    return false;
}

void print(int *v, int t){
    for(int i=0; i<t; i++){
        std::cout << v[i] << " ";
    }

    std::cout << "\n";
}

int main(int argc, char const *argv[]){
    int n=10, s;

    std::cout << "number: ";
    std::cin >> s;

    int *v = new int[n];

    for(int i=0; i<n; i++){
        v[i] = rand()%100;
    }

    print(v,n);
    std::cout << (havePair(v,n,s)? "True": "False") << "\n";

    return 0;
}
