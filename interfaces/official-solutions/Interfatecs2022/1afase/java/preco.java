import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class preco {

	public static void main(String[] args) throws IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		double tara = Double.valueOf(in.readLine());
		double peso = Double.valueOf(in.readLine());
		double quilo = Double.valueOf(in.readLine());
		
		System.out.printf("%.2f\n", (peso - tara) * quilo);

	}

}
