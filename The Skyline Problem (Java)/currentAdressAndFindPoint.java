
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

public class currentAdressAndFindPoint{

	private int lastPosition = 0;	//rectangle içinden en değer son tutulur
	private int maxHeight = 0;	//rectangle içinden en yüksek değer tutulur
	private int currentHeight = 0;
	private int currentPosition = 0;
	private int currentEndOfRectangle = 0; // Bu değişken bulunduğu karenin sonunu tutar.
	public currentAdressAndFindPoint(Vector<pairPoint> pairPointObject,Vector<rectangles> objectList,int rectanglesNumber){

		lastPosition = objectList.get(0).getEnd();
		maxHeight = objectList.get(0).getHeight();


		for (int i = 1;i<rectanglesNumber ; i++) {
			if (lastPosition<objectList.get(i).getEnd()) {
				lastPosition = objectList.get(i).getEnd();
			}
			if (maxHeight<objectList.get(i).getHeight()) {
				maxHeight = objectList.get(i).getHeight();
			}

		}
		
		windowClass.setLastPosition(lastPosition);
		
		while(lastPosition >=currentPosition) {
	
			int index = 0;

			if (index == 0) {
			
				int tempHeight = currentHeight ;
				int tempEnd = currentEndOfRectangle;
				int control = 0 ; // bu control bir geçiş varsa anlaşılması için
				for (int i = 0;i<rectanglesNumber ;i++ ) {
					
					if(objectList.get(i).getPosition() == currentPosition){
						
						if (objectList.get(i).getHeight() > currentHeight) {
							
							currentHeight = objectList.get(i).getHeight();
							currentEndOfRectangle =  objectList.get(i).getEnd();
							control++;
						}
					}
				}
				if (control != 0 ) {
					pairPoint pair = new pairPoint();
					pair.setX(currentPosition);
					pair.setY(tempHeight);
					pairPointObject.add(pair);
							
					pairPoint pair2 = new pairPoint();
					pair2.setX(currentPosition);
					pair2.setY(currentHeight);
					pairPointObject.add(pair2);							
					index++;
				}

			}
			if (index == 0) {
				if((currentEndOfRectangle == currentPosition)&&(currentHeight != 0)){
					
					pairPoint pair = new pairPoint();
					pair.setX(currentPosition);
					pair.setY(currentHeight);
					pairPointObject.add(pair);
					Vector<Integer >sort = new Vector<Integer>();
					
					for (int j = 0; j<rectanglesNumber ;j++ ) {
						if ((objectList.get(j).getPosition()<=currentPosition && objectList.get(j).getEnd()>=currentPosition)&&
							objectList.get(j).getEnd() != currentEndOfRectangle) {		
							
							sort.add(j);
						}	
					}
					
					if (sort.size() != 0 ) {
						int control = 0;
						int bigEnd = 0;
						int tempHeight = objectList.get(sort.get(0)).getHeight();
						int tempEnd = objectList.get(sort.get(0)).getEnd();
						for (int k = 0;sort.size()>k;k++ ) {
							
							if ((objectList.get(sort.get(k)).getHeight() != currentHeight)&&(objectList.get(sort.get(k)).getHeight()>tempHeight)) {
								tempHeight = objectList.get(sort.get(k)).getHeight();
								tempEnd = objectList.get(sort.get(k)).getEnd();
								bigEnd = k ;
								control++;			
							}		
						}	
						pairPoint pair2 = new pairPoint();
						pair2.setX(currentPosition);
						pair2.setY(tempHeight);
						if (control !=0) {
							currentEndOfRectangle = objectList.get(sort.get(bigEnd)).getEnd();							
						}else{
							currentEndOfRectangle = objectList.get(sort.get(0)).getEnd();
						}
						currentHeight = tempHeight ;
						pairPointObject.add(pair2);	
					}else{		
						currentHeight = 0;
						pairPoint pair2 = new pairPoint();
						pair2.setX(currentPosition);
						pair2.setY(currentHeight);
						currentEndOfRectangle = 0;
						pairPointObject.add(pair2);
					}
				}	
			}
			currentPosition++;
		}	
	}
	public int getLastPosition(){
		return lastPosition;
	}
	public int getMaxHeight(){
		return maxHeight;
	}

}