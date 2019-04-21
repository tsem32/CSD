/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import com.itextpdf.text.Document;
import com.itextpdf.text.*;
import com.itextpdf.text.pdf.BaseFont;
import com.itextpdf.text.pdf.PdfPCell;
import com.itextpdf.text.pdf.PdfPTable;
import com.itextpdf.text.pdf.PdfWriter;

import java.io.FileOutputStream;
public class pdfManager {
    private Document doc;
    private  PdfPTable table;
    private  PdfWriter writer;
    private  PdfPTable hist_table ;
    
    void close_descriptors(){
        doc.close();
           writer.close();
    }
    
    
    public pdfManager(String fullName,String amka,String address,String fathers,String mothers,String bday,String marState,String job,String ama,String phone,String relphone,String gender,String service){
          doc=new Document();
     
       try{
         writer =PdfWriter.getInstance(doc, new FileOutputStream("c:\\temp\\ "+fullName+".pdf"));
           doc.open();
           BaseFont fonty = BaseFont.createFont("RobotoCondensed-Bold.ttf", BaseFont.IDENTITY_H,BaseFont.NOT_EMBEDDED);
     fonty.setSubset(true);
     Phrase myName = new Phrase("ΚΑΡΤΕΛΑ ΑΣΘΕΝΟΥΣ", new Font(fonty,14));
        table = new PdfPTable(2);
         doc.add(myName);
        fonty = BaseFont.createFont("RobotoCondensed-Regular.ttf", BaseFont.IDENTITY_H,BaseFont.NOT_EMBEDDED);
         BaseFont fontyb = BaseFont.createFont("RobotoCondensed-Bold.ttf", BaseFont.IDENTITY_H,BaseFont.NOT_EMBEDDED);
       table.addCell(new Phrase("Ονοματεπώνυμο",new Font(fonty,14)));
        table.addCell(new Phrase(fullName,new Font(fontyb,14)));
        table.addCell(new Phrase("AMKA",new Font(fonty,14)));
        table.addCell(new Phrase(amka,new Font(fontyb,14)));
        table.addCell(new Phrase("Διεύθυνση",new Font(fonty,14)));
        table.addCell(new Phrase(address,new Font(fontyb,14)));
        table.addCell(new Phrase("Πατρώνυμο",new Font(fonty,14)));           
        table.addCell(new Phrase(fathers,new Font(fontyb,14)));
        table.addCell(new Phrase("Μητρώνυμο",new Font(fonty,14)));
        table.addCell(new Phrase(mothers,new Font(fontyb,14)));
        table.addCell(new Phrase("Ημ. Γέννησης",new Font(fonty,14)));
        table.addCell(new Phrase(bday,new Font(fontyb,12)));
        table.addCell(new Phrase("Οικ. Κατάσταση",new Font(fonty,14)));
        table.addCell(new Phrase(marState,new Font(fontyb,14)));
        table.addCell(new Phrase("Επάγγελμα",new Font(fonty,14)));
        table.addCell(new Phrase(job,new Font(fontyb,14)));
        table.addCell(new Phrase("ΑΜΑ",new Font(fonty,14)));
        table.addCell(new Phrase(ama,new Font(fontyb,14)));
        table.addCell(new Phrase("Τηλέφωνο",new Font(fonty,14)));
        table.addCell(new Phrase(phone,new Font(fontyb,14)));
        table.addCell(new Phrase("Τηλέφωνο Συγγενούς",new Font(fonty,14)));
        table.addCell(new Phrase(relphone,new Font(fontyb,14)));
        table.addCell(new Phrase("Φύλλο",new Font(fonty,14)));
        table.addCell(new Phrase(gender,new Font(fontyb,14)));
         doc.add(table);
         fonty = BaseFont.createFont("RobotoCondensed-Bold.ttf", BaseFont.IDENTITY_H,       BaseFont.NOT_EMBEDDED);
        Phrase reason = new Phrase("\n ΛΟΓΟΣ ΕΠΙΣΚΕΨΗΣ \n", new Font(fonty,14));
         doc.add(reason);
          fonty = BaseFont.createFont("RobotoCondensed-Regular.ttf", BaseFont.IDENTITY_H,       BaseFont.NOT_EMBEDDED);
          Phrase reason_text = new Phrase(service, new Font(fonty,14));
        doc.add(reason_text);
         fonty = BaseFont.createFont("RobotoCondensed-Bold.ttf", BaseFont.IDENTITY_H,       BaseFont.NOT_EMBEDDED);
        Phrase hist_title = new Phrase("\n \nΙΣΤΟΡΙΚΟ", new Font(fonty,14));
         doc.add(hist_title);
         
         float[] columnWidths = {2, 2, 2, 2};
          hist_table = new PdfPTable(columnWidths);
        hist_table.setWidthPercentage(100);
          hist_table.addCell(new Phrase("Ημερομηνία",new Font(fonty,14)));
         hist_table.addCell(new Phrase("Υπηρεσία",new Font(fonty,14)));
         hist_table.addCell(new Phrase("Περιγραφή",new Font(fonty,14)));
         hist_table.addCell(new Phrase("Αγωγή",new Font(fonty,14)));
         
         
         
       }catch(Exception e){
           
       }
    }
    
    
    void addHistoryRow (String date,String Service,String Description,String Medication,BaseFont fonty){
        
        hist_table.addCell(new Phrase(date,new Font(fonty,14)));
         hist_table.addCell(new Phrase(Service,new Font(fonty,14)));
         hist_table.addCell(new Phrase(Description,new Font(fonty,14)));
         hist_table.addCell(new Phrase(Medication,new Font(fonty,14)));
    }
    void close(){
        try{
            doc.add(hist_table);
            close_descriptors();
        }catch (Exception e){
            
        }
    
}
}
