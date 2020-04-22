#include <iostream>

using std::cout;
using std::endl;

int missingNumber(int *v, int s){
    int sumFormula = ((s+2)*(s+1))/2;
    int sumVector = 0;

    for(int i=0; i<s; i++){
        sumVector += v[i];
    }

    return (sumFormula - sumVector);
}

int main(int argc, char const *argv[]){
    
    int v[] = {1, 2, 3, 4, 5, 6, 7, 9};
    int s = sizeof(v)/sizeof(v[0]);

    int m = missingNumber(v, s);

    cout << "Missing: " << m << endl;
    
    return 0;
}
