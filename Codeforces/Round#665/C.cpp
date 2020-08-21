#include <bits/stdc++.h>
int _, n, a[100010], b[100010], flag;
int main() {
	for(scanf("%d", &_); _--; flag=0) {
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", a+i),
			b[i]=a[i];
		std::sort(a, a+n);
		for(int i=0; i<n; i++)
			if (a[i] != b[i] && b[i]%a[0])
				flag=1;
		puts(!flag?"YES":"NO");
	}
}
