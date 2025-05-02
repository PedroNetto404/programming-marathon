import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class licenseplates {

	public static void main(String[] args) throws IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String line;
		while ((line = in.readLine()) != null) {
			String[] parts = line.split(" ");

			boolean finishedAnalysis = false;
			for (int i = 0; i < 3; i++) {
				char item = getChar(parts[i]);
				if (!isLetter(item)) {
					System.out.println("ERRO");
					finishedAnalysis = true;
					break;
				}
			}
			if (!finishedAnalysis) {
				char item = getChar(parts[3]);
				if (!isNumber(item)) {
					System.out.println("ERRO");
					continue;
				}
				
				item = getChar(parts[4]);
				boolean mercosul;
				if (isLetter(item)) {
					mercosul = true;
				} else if (isNumber(item)) {
					mercosul = false;
				} else {
					System.out.println("ERRO");
					continue;
				}

				for (int i = 5; i < parts.length; i++) {
					item = getChar(parts[i]);
					if (!isNumber(item)) {
						System.out.println("ERRO");
						finishedAnalysis = true;
						break;
					}
				}

				if (!finishedAnalysis) {
					if (mercosul) {
						System.out.println("MERCOSUL");
					} else {
						System.out.println("ANTIGA");
					}
				}

			}

		}
	}

	private static char getChar(String value) {
		return (char) Integer.parseInt(value);
	}

	private static boolean isLetter(char value) {
		return (value >= 65 && value <= 90);
	}

	private static boolean isNumber(char value) {
		return (value >= 48 && value <= 57);
	}

}
