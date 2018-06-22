
// 171044086 _HAMZA _YOĞURTCUOĞLU   15:30 10.06.2018 

//Programın açıklamasını ve yorumlarını "commends.pdf"de bulabilirsiniz. 

//DİKKAT data.txt dosyasındaki formatta test ediniz.

/*
	COMPILER (MAKEFILE) :
			make (dosyaları derler)	
			make clean  (obje kodları siler)
Dikkat--->  java main (main dosyasını çalıştırır)	

*/


/*
The Skyline Problem
From a distance, the view of a collection of high-rise buildings reveals a profile. With sufficient simplifications, this
observation turns into a problem called the skyline problem. The objective is to find the profile created by the roofs
of the buildings. The simplifications are: All of the buildings are represented by rectangles and the profile is on 2D
plane.
*/


import java.io.File;
import java.util.*;
import javax.swing.JFrame;
import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;

public class main {
  public int index = 0;	//Rectangle sayısı tutulur.

  public static void main(String[] args) throws Exception
  {
    Vector<rectangles> objectList = new Vector<rectangles>();
    File file = new File("data.txt");	//dosya açılır
    Scanner sc = new Scanner(file);
 	
    String tempLine ;
    int index = 0;  

    while (sc.hasNextLine()){
      	int stringIndex = 0;
      	String tempWidth = "";
      	rectangles objectRectangle = new rectangles();
      	objectList.add(objectRectangle);	
      	tempLine = sc.nextLine();			
      	
      	while(tempLine.charAt(stringIndex) != ' '){
      		tempWidth = tempWidth + tempLine.charAt(stringIndex);
      		stringIndex++;
      	}
    	stringIndex++;
    	String tempHeight = "";
    	while(tempLine.charAt(stringIndex) != ' '){
    		tempHeight = tempHeight + tempLine.charAt(stringIndex);
    		stringIndex++;			
      		
      	}
      	stringIndex++;
      	String tempPosition = "";
      	while(tempLine.length()!= stringIndex){
      		tempPosition =tempPosition + tempLine.charAt(stringIndex);
      		stringIndex++;
      	}
      	
      	objectList.get(index).setHeight(Integer.parseInt(tempHeight));
      	objectList.get(index).setPosition(Integer.parseInt(tempPosition));	
    	objectList.get(index).setEnd(Integer.parseInt(tempWidth)+ objectList.get(index).getPosition());
    	index++;
    }
  		Vector<pairPoint> pairPointObject = new Vector<pairPoint>();

  		currentAdressAndFindPoint currentObject = new currentAdressAndFindPoint(pairPointObject,objectList,index);
  		
  		new printConsolePoint(pairPointObject);  		
  			
  		System.out.println();
 
  		windowClass.setLastPosition(currentObject.getLastPosition());
  		windowClass.setMaxHeight(currentObject.getMaxHeight());

  		new windowClass(pairPointObject);


  }
}
