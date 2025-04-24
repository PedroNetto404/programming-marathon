import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class policripto {

	private static final int A_CODE = 97;
	private static final int Z_CODE = 122;
	private static String delta;
	private static int deltaIndex = 0;
	private static int signal = 1;

	public static void main(String[] args) throws IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String code = in.readLine().replace("w", " ");
		delta = in.readLine();

		if (code.isEmpty()) {
			System.out.println("");
			return;
		}

		// a - 97
		// z - 122
		String result = "";

		for (int i = 0; i < code.length(); i++) {
			int charCode = code.charAt(i);
			if (code.charAt(i) == ' ') {
				result += " ";
				continue;
			}

			int delta = nextDigit();
			charCode += delta;
			if (charCode < A_CODE)
				charCode = Z_CODE + charCode - A_CODE + 1;
			else if (charCode > Z_CODE)
				charCode = A_CODE + charCode - Z_CODE - 1;
			result += (char) charCode;
		}

		System.out.println(result);
	}

	public static int nextDigit() {
		if (delta.charAt(deltaIndex) == '-') {
			signal = -1;
			int result = signal * Integer.valueOf(delta.substring(deltaIndex + 1, deltaIndex + 2));
			deltaIndex += 2;
			return result;
		} else if (delta.charAt(deltaIndex) == '+') {
			signal = 1;
			int result = signal * Integer.valueOf(delta.substring(deltaIndex + 1, deltaIndex + 2));
			deltaIndex += 2;
			return result;
		}
		int result = signal * Integer.valueOf(delta.substring(deltaIndex, deltaIndex + 1));
		deltaIndex += 1;
		return result;
	}       

}
