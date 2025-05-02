#include <iostream>

using namespace std;

int main() {
	int n, v, i = 1, j, flg=0;

	cin >> n;
	while (cin >> v) {
		if (v > i) {
			for (j=i; j<v; j++)
				cout << j << endl;
			flg = 1;
		}
		i=v+1;
	}

	if (!flg)
		cout << "bom trabalho" << endl;
	return 0;
}
