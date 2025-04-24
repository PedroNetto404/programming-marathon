import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Vector;
import java.io.*;


public class licenseplates {

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

	public static void main(String args[]){
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String line;
		//ProblemaA
		try{
			while ((line = in.readLine()) != null) {
				String vet[] = line.split(" ");
				problemaA(Integer.parseInt(vet[0]), Integer.parseInt(vet[1]), Integer.parseInt(vet[2]), Integer.parseInt(vet[3]), Integer.parseInt(vet[4]), Integer.parseInt(vet[5]), Integer.parseInt(vet[6]));
			}
		} catch (Exception ex){
		
		}
		
	}



    public static void problemaA(int A1, int A2, int A3, int A4, int A5, int A6, int A7) {
        if (
                (A1 >= 65 && A1 <= 90 ? true : false) &&
                        (A2 >= 65 && A3 <= 90 ? true : false) &&
                        (A3 >= 65 && A3 <= 90 ? true : false) &&
                        (A4 >= 48 && A4 <= 57 ? true : false) &&
                        (A5 >= 48 && A5 <= 57 ? true : false) &&
                        (A7 >= 48 && A6 <= 57 ? true : false) &&
                        (A3 >= 48 && A7 <= 57 ? true : false)
        ) {
            System.out.println("ANTIGA");
        } else if (
                (A1 >= 65 && A1 <= 90 ? true : false) &&
                        (A2 >= 65 && A3 <= 90 ? true : false) &&
                        (A3 >= 65 && A3 <= 90 ? true : false) &&
                        (A4 >= 48 && A4 <= 57 ? true : false) &&
                        (A5 >= 65 && A5 <= 90 ? true : false) &&
                        (A7 >= 48 && A6 <= 57 ? true : false) &&
                        (A3 >= 48 && A7 <= 57 ? true : false)
        ) {
            System.out.println("MERCOSUL");
        } else {
            System.out.println("ERRO");
        }
    }
}