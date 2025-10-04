#include <iostream>
#include <algorithm>

using namespace std;

long long lcm(long long a, long long b) {
    return (a * b) / __gcd(a, b);
}

int main() {
    long long A, B, C;
    
    cin >> A >> B >> C;
    
    long long lcm_ab = lcm(A, B);
    
    long long count = C / lcm_ab;
    
    cout << count << endl;
    
    return 0;
}