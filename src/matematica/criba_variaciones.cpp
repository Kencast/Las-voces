// Criba de totiente
//
// Encontra el valor de la funcion
// totiente de Euler
//
// O(n log(log(n)))

int tot[MAX];

void criba(int lim) {
	for (int i = 1; i <= lim; i++) {
		tot[i] += i;
		for (int j = 2*i; j <= lim; j += i)
			tot[j] -= tot[i];
	}
}

// Criba de funcion de mobius
//
// O(n log(log(n)))

char meb[MAX];

void criba(int lim) {
	for (int i = 2; i <= lim; i++) meb[i] = 2;
	meb[1] = 1;
	for (int i = 2; i <= lim; i++) if (meb[i] == 2)
		for (int j = i; j <= lim; j += i) if (meb[j]) {
			if (meb[j] == 2) meb[j] = 1;
			meb[j] *= j/i%i ? -1 : 0;
		}
}
