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
import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;
import javax.swing.JFrame;
import java.awt.Graphics;
import java.awt.Color;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.LinkedList;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;


public class windowClass extends  JFrame
{
  Vector<pairPoint> pairPointObjectCopy = new Vector<pairPoint>();
  static private int lastPosition = 0;
  static private int maxHeight = 0;
  int rateShapeHeight = 0;
  int rateShapeWidth = 0;
  public static void setLastPosition(int a){
      lastPosition = a;
  }
  
  public static void setMaxHeight(int b){
    maxHeight = b ;
  }
  

	public void paint(Graphics line){
    
   line.translate(0, maxHeight*(rateShapeHeight));

   for (int i = 0; pairPointObjectCopy.size()-1 > i ; i++ ) {
       
        line.drawLine(pairPointObjectCopy.get(i).getX()*rateShapeWidth,-pairPointObjectCopy.get(i).getY()*rateShapeHeight
          ,pairPointObjectCopy.get(i+1).getX()*rateShapeWidth,-pairPointObjectCopy.get(i+1).getY()*rateShapeHeight);
   }
  }

  public windowClass(Vector<pairPoint> pairPointObject){
    
    for (int i = 0;pairPointObject.size()>i ;i++ ) {
        pairPoint pair = new pairPoint();
        pair.setX(pairPointObject.get(i).getX());
        pair.setY(pairPointObject.get(i).getY());
        pairPointObjectCopy.add(pair);
    }

    if(maxHeight<30) {
      rateShapeHeight = 29 ;
    }else if (maxHeight>30&&maxHeight<100) {
      rateShapeHeight = 9;
    }else if (maxHeight>100&&maxHeight<250) {
      rateShapeHeight = 4;
    }else if (maxHeight>250&&maxHeight<500) {
      rateShapeHeight = 2;
    }else {
      rateShapeHeight = 1;
    }

    if(lastPosition<30) {
      rateShapeWidth = 29 ;
    }else if (lastPosition>30&&lastPosition<100) {
      rateShapeWidth = 9;
    }else if (lastPosition>100&&lastPosition<250) {
      rateShapeWidth = 4;
    }else if (lastPosition>250&&lastPosition<500) {
      rateShapeWidth = 2;
    }else {
      rateShapeWidth = 1;
    }

    setTitle("The SkyLine Problem");
    setSize(lastPosition*(rateShapeWidth+1),maxHeight*(rateShapeHeight));
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setVisible(true);
    
	}
}