int C(int n, int m) {
	if(m > n / 2) m = n - m;
	int a = 1, b = 1; 
	for(int i = 1; i <= m; i++) {
		a *= n + 1 - i;
		b *= i;
		if(a % b == 0) a /= b, b = 1;
	}
	return a / b;
}


