
//计算C(n, m)的对数ln(C(n, m)) 

long double logC(int n, int m) {
	return logF[n] - logF[m] - logF[n - m];
} 
