#include <iostream>
#include <vector>
#include <cmath>

long long get_fibonacci_last_digit_fast(long long pisano_period_length, long long n, long long m) {
    // write your code here
    std::vector<long long> numbers(pisano_period_length+1);
    
    /*std::cout << "nth fibonacci number " << n;
    std::cout << "pisano_period_length " << pisano_period_length;
    std::cout << "m is " << m;*/
 
    numbers[0] = 0;
    numbers[1] = 1;
    for(int i=2; i < pisano_period_length+1; i++) {
      numbers[i] = (numbers[i-1]%m + numbers[i-2]%m)%m;
      //numbers[i] = (numbers[i-1] + numbers[i-2]);
    }

    //std::cout << "n th fibonacci number n: " << n << " num is " << numbers[n] << "\n";

    return (long long) (numbers[n]);
}


/*long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}*/

/*long long get_pisano_period_length_overflow(long long m) {
  long long a = 0, b = 1, rem0 = 0, rem1 = 0 , found = 0, i = 0;
  while(found == 0) {
    long long c = a+b;
    a = b;
    b = c;
    rem0 = a%m;
    rem1 = b%m;
    //rem0 = rem1;
    //rem1 = c % m;
    i = i+1;
    std::cout << " " << rem0 << " " << rem1 << " \n";
    if(rem0 == 0 && rem1 == 1) {
        found = 1;
        return i;
    }
  }
}*/

//Saving the reminders should do the trick
long long get_pisano_period_length_no_overflow(long long m) {
    long long a = 0, b = 1, c = 0;
    for (int len = 0; len < m * m; len++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return len+1;
    }
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;
    long long pisano_period_length = get_pisano_period_length_no_overflow(m);
    long long nprime = n % pisano_period_length;
    //std::cout << "nprime is " << nprime << " m is " << m << " pisano length is " << pisano_period_length << " \n" ;
    return (long long) get_fibonacci_last_digit_fast(pisano_period_length, nprime, m);

}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
