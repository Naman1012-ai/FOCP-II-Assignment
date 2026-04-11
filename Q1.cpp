#include <iostream>
#include <string>
using namespace std;

// Check if we can turn OFF all bulbs with window size l in at most k operations
bool canTurnOffAllBulbs(string bulbs, int k, int l){
    int n = bulbs.length();
    int operations = 0;
    
    // Greedy approach: scan left to right
    for(int i = 0; i < n; i++){
        if(bulbs[i] == '1'){
            // We found an ON bulb, must perform an operation at index i
            operations++;
            if(operations > k) return false;
            
            // Turn OFF all bulbs in range [i, min(n-1, i+l-1)]
            for(int j = i; j < min(n, i + l); j++){
                bulbs[j] = '0';
            }
        }
    }
    
    return true;
}

int main(){
    int n, k;
    string bulbs;
    
    cin >> n >> k;
    cin >> bulbs;
    
    // Binary search on l from 1 to n
    int left = 1, right = n;
    int answer = n;
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(canTurnOffAllBulbs(bulbs, k, mid)){
            // mid works, try smaller values
            answer = mid;
            right = mid - 1;
        }else // mid doesn't work, need larger l
            left = mid + 1;
    }
    cout << answer << endl;
    return 0;
}
