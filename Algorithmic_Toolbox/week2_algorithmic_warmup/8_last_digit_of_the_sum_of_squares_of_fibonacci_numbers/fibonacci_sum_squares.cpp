#include <iostream>
#include <vector>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

/*int get_fibonacci_last_digit(long long n) {
    // write your code here
    std::vector<int> numbers(n+1);
    if (n <= 1)
      return n;

    numbers[0] = 0;
    numbers[1] = 1;
    for(int i=2; i < n+1; i++) {
      numbers[i] = (numbers[i-1] + numbers[i-2])%10;
    }

    return numbers[n];
}*/



long long get_fibonacci_last_digit_fast(long long pisano_period_length, long long n, long long m) {
    // write your code here
    std::vector<long long> numbers(pisano_period_length+1);
    
    numbers[0] = 0;
    numbers[1] = 1;
    for(int i=2; i < pisano_period_length+1; i++) {
      numbers[i] = (numbers[i-1]%m + numbers[i-2]%m)%m;
    }

    return (long long) (numbers[n]);
}


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

int fibonacci_sum_squares_fast(long long n) {
    if (n <= 1)
        return n;

    int fibonacci_last_digit_n = get_fibonacci_huge_fast(n, 10);
    int fibonacci_last_digit_n_1 = get_fibonacci_huge_fast(n+1, 10);
    //std::cout << "n last_digit " << fibonacci_last_digit_n << " n_1 last digit " << fibonacci_last_digit_n_1 << " \n";
    return ((fibonacci_last_digit_n * fibonacci_last_digit_n_1)%10);
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_squares_naive(n);
    std::cout << fibonacci_sum_squares_fast(n);
}
