int primes(int limit) {
    int x = 3;
    while (x < limit) {
        int is_prime = 1;
        int y = 3;
        int z = x / 2;
        while (y < z) {
            int w = x % y;
            if (w == 0) {
                is_prime = 0;
                break;
            }
            y = y + 2;
        }
        if (is_prime) {
            print(x);
        }
        x = x + 2;
    }
}

int main() {
	primes(2147483647);
}

