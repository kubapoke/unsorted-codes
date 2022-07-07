#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned long long n;
    cin >> n;
    double gg=sqrt(n);
    for(int i=1; i<=gg; i++) 
    {
        if(n % i == 0)
            cout << i << '\n';
    }
    for(int i=int(gg); i>=2; i--) 
    {
        if(n % i == 0)
            cout << n / i << '\n';
    }
    cout.flush();
    return 0;
}
