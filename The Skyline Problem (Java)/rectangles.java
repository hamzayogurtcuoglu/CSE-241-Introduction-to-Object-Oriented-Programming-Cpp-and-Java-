// 171044086 _HAMZA _YOĞURTCUOĞLU   15:30 10.06.2018 

//Programın açıklamasını ve yorumlarını "commends.pdf"de bulabilirsiniz. 

//DİKKAT data.txt dosyasındaki formatta test ediniz.

/*
	COMPILER (MAKEFILE) :
			make (dosyaları derler)	
			make clean  (obje kodları siler)
Dikkat--->  java main (main dosyasını çalıştırır)	

*/
public class rectangles{

	private int end ;
	private int height ;
	private int position ;
	private static int numberOfRectangles = 0;

	public void setEnd(int a){
		end = a;
	}
	public void setHeight(int b){
		height = b;
	}
	public void setPosition(int c){
		position = c ;
	}
	public int getEnd(){
		return end; 
	}
	public int getHeight(){
		return height;
	}
	public int getPosition(){
		return position;
	}
	public static void setNumberOfRectangles(){
		numberOfRectangles++;
	}
	public static int getNumberOfRectangles(){
		return numberOfRectangles;
	}

}
