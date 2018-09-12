#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long get_pisano_period_length(long long m) {
    long long a = 0, b = 1, c = 0;
    for (int len = 0; len < m * m; len++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return len+1;
    }
}

long long get_fibonacci_last_digit_fast(long long pisano_period_length, long long n) {
    // write your code here
    std::vector<long long> numbers(pisano_period_length+1);
    
    /*std::cout << "nth fibonacci number " << n;
    std::cout << "pisano_period_length " << pisano_period_length;
    std::cout << "m is " << m;*/
 
    numbers[0] = 0;
    numbers[1] = 1;
    for(int i=2; i < pisano_period_length+1; i++) {
      numbers[i] = (numbers[i-1]%10 + numbers[i-2]%10)%10;
      //numbers[i] = (numbers[i-1] + numbers[i-2]);
    }

    //std::cout << "n th fibonacci number n: " << n << " num is " << numbers[n] << "\n";

    return (long long) (numbers[n]);
}

int get_fibonacci_sum_last_digit(long long n)  {

    long long pisano_period_length = get_pisano_period_length(10);
    long long nprime = n % pisano_period_length;
    //std::cout << "nprime is " << nprime << " m is " << m << " pisano length is " << pisano_period_length << " \n" ;
    return (long long) get_fibonacci_last_digit_fast(pisano_period_length, nprime);
}

int fibonacci_last_digit_sum_fast(long long n) {
    if(n <= 1)
        return n;

    int last_digit = get_fibonacci_sum_last_digit(n+2);
    
    last_digit = (last_digit == 0) ? 9 : (last_digit-1);

    return last_digit;

}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n);
    std::cout << fibonacci_last_digit_sum_fast(n);
}
