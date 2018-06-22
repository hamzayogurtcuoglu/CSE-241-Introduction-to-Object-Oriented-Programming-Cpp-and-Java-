// 171044086 _HAMZA _YOĞURTCUOĞLU   15:30 10.06.2018 

//Programın açıklamasını ve yorumlarını "commends.pdf"de bulabilirsiniz. 

//DİKKAT data.txt dosyasındaki formatta test ediniz.

/*
	COMPILER (MAKEFILE) :
			make (dosyaları derler)	
			make clean  (obje kodları siler)
Dikkat--->  java main (main dosyasını çalıştırır)	

*/

import java.io.File;
import java.util.*;
import javax.swing.JFrame;
import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;

public class printConsolePoint{

	public printConsolePoint(Vector<pairPoint> pairPointObject){

		for (int i = 0; pairPointObject.size()>i ;i++ ) {
			
			System.out.print( "(" );
			System.out.print(  pairPointObject.get(i).getX());
			System.out.print( ", " );
			System.out.print(  pairPointObject.get(i).getY());
			System.out.print( ")");

			if (i != pairPointObject.size()-1) {
				System.out.print(", ");
			}
		}
	}
}