import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Vector;
import java.io.*;


public class retangulo {

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

	public static void main(String args[]){
        try {
            //ProblemaF
			String line;
            ArrayList<String> arr = new ArrayList<>();
            while ((line = in.readLine()) != null) {
                arr.add(line);
            }
            in.close();
            problemaF(arr.get(0), arr.get(1));
		} catch (Exception e){
		
		}
		
	}



    public static void problemaF(String l1, String l2) {
        int QL = Integer.parseInt(l1.split(" ")[0]);
        int QC = Integer.parseInt(l1.split(" ")[1]);
        int L  = Integer.parseInt(l2.split(" ")[0]);
        int C  = Integer.parseInt(l2.split(" ")[1]);
        long [][] arr = new long[QL][QC];
        for (int i=0; i<QL; i++){
            for(int k=0; k<QC; k++){
                if (i==0){
                    arr[i][k]=0;
                } else if (k==QC-1){
                    arr[i][k]=1;
                } else if(i==QL-1){
                    arr[i][k]=2;
                } else if(k==0){
                    arr[i][k]=3;
                } else
                    arr[i][k]=arr[i-1][k]+arr[i][k-1]+arr[i-1][k-1];
            }
        }
        System.out.println(arr[L-1][C-1]);
    }
}