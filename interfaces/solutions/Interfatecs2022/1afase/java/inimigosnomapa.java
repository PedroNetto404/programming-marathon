import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class inimigosnomapa {

	public static void main(String[] args) throws IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int howMany = Integer.valueOf(in.readLine());
		int amountI = 0;
		int amountII = 0;
		int amountIII = 0;
		int amountIV = 0;
		String[] parts;
		for (int i = 0; i < howMany; i++) {
			parts = in.readLine().split(" ");
			int x = Integer.valueOf(parts[0]);
			int y = Integer.valueOf(parts[1]);
			if (x < 0) {
				if (y < 0)
					amountIII++;
				else
					amountIV++;
			} else {
				if (y < 0)
					amountII++;
				else
					amountI++;
			}
		}

		System.out.printf("I = %d\n", amountI);
		System.out.printf("II = %d\n", amountII);
		System.out.printf("III = %d\n", amountIII);
		System.out.printf("IV = %d\n", amountIV);

	}

}
