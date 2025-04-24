import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class retangulo {

	private static long[][] cache;

	public static void main(String[] args) throws IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String[] parts = in.readLine().split(" ");
		int linhas = Integer.valueOf(parts[0]);
		int colunas = Integer.valueOf(parts[1]);

		parts = in.readLine().split(" ");
		int lin = Integer.valueOf(parts[0]);
		int col = Integer.valueOf(parts[1]);

		cache = new long[linhas + 1][colunas + 1];
		for (int i = 0; i <= linhas; i++) {
			for (int j = 0; j <= colunas; j++) {
				cache[i][j] = -1;
			}
		}

		System.out.println(getValue(linhas, colunas, lin, col));

	}

	private static long getValue(int linhas, int colunas, int lin, int col) {
		if (cache[lin][col] == -1) {
			if (lin == 1)
				cache[lin][col] = 0;
			else if (col == colunas)
				cache[lin][col] = 1;
			else if (lin == linhas)
				cache[lin][col] = 2;
			else if (col == 1)
				cache[lin][col] = 3;
			else
				cache[lin][col] = getValue(linhas, colunas, lin - 1, col) + getValue(linhas, colunas, lin - 1, col - 1)
						+ getValue(linhas, colunas, lin, col - 1);
		}
		return cache[lin][col];
	}

}
