import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Vector;
import java.io.*;

public class contagem{
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String args[]){
        try {
            int n = Integer.parseInt(in.readLine());
            int arr[] = new int[n];
            for (int i=0; i<n; i++){
                arr[i]=Integer.parseInt(in.readLine());
            }
            in.close();
            myContagem(arr);
        } catch (Exception e){

        }

    }
    public static void myContagem(int[] arr) {
        int k=1;
        boolean gw = true;
        for (int i = 0; i < arr.length; i++) {
            while (k <= arr[i]) {
                if (k < arr[i]) {
                    System.out.println(k);
                    gw = false;
                }
                k++;
            }
        }
        if (gw) {
            System.out.println("bom trabalho");
        }
    }
}


