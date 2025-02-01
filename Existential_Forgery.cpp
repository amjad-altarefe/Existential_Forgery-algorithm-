/******************************************************************************

                    • Existential Forgery algorithm in c++.
                            
        An Elliptic Curve attack algorithm using El-Gamal in C++, 
       designed to break elliptic curve cryptography by leveraging 
                    the El-Gamal encryption scheme.

*******************************************************************************/


#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// دالة لحساب القوة مع المود (Modular Exponentiation)
long long modExp(long long base, long long exp, long long mod) 
{
    long long result = 1;
    base = base % mod;

    while (exp > 0) 
    {
        if (exp % 2 == 1) 
            result = (result * base) % mod;
        
        exp = exp / 2;
        base = (base * base) % mod;
    }

    return result;
}

int main() 
{
    // المفاتيح العامة (n, e)
    long long n; 
    cout << "Please enter a value of n: " ;
    cin >> n;
    long long e;
    cout << "Please enter a value of e: ";
    cin >> e;
    
    // المهاجم يختار توقيعًا عشوائيًا s
    long long s = rand() % n; // اختيار قيمة عشوائية أقل من n

    // حساب الرسالة المقابلة للتوقيع
    long long x = modExp(s, e, n); // x = s^e mod n

    // طباعة النتائج
    cout << "Public Key (n, e): (" << n << ", " << e << ")" << endl;
    cout << "Chosen Signature (s): " << s << endl;
    cout << "Computed Message (x): " << x << endl;

    // التحقق من صحة التوقيع
    cout << "Verification: (s^e mod n == x): " << (modExp(s, e, n) == x ? "Valid" : "Invalid") << endl;

    return 0;
}
