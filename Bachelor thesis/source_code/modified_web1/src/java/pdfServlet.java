/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import com.itextpdf.text.pdf.BaseFont;
import com.itextpdf.text.pdf.ByteBuffer;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import static java.nio.charset.StandardCharsets.ISO_8859_1;
import static java.nio.charset.StandardCharsets.UTF_16;
import static java.nio.charset.StandardCharsets.UTF_8;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.swing.JOptionPane;


/**
 *
 * @author laptop
 */
@WebServlet(urlPatterns = {"/pdfServlet"})
public class pdfServlet extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

       
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
         response.setCharacterEncoding("UTF-8");
        request.setCharacterEncoding("UTF-8");
        String pid=request.getParameter("pid");
        String patient_query="SELECT * from patients where pid=?";
        String history_query="SELECT * from history where pid=?";
        String fileName=null;
        String filePrompt=new String();
        pdfManager mg=null;
        Connection con = null;
      
      PreparedStatement ps = null;
      ResultSet rs = null;
          String driverName = "com.mysql.jdbc.Driver";
            String url = "jdbc:mysql://localhost/hospital?useUnicode=true&characterEncoding=UTF-8";
            String user = "root";
            String dbpsw = "";
            try {
                    Class.forName(driverName);
                    con = DriverManager.getConnection(url, user, dbpsw);
                     ps=con.prepareStatement(patient_query);
                     ps.setString(1,pid);
                     rs=ps.executeQuery();
                       BaseFont fonty=BaseFont.createFont("RobotoCondensed-Regular.ttf", BaseFont.IDENTITY_H,BaseFont.NOT_EMBEDDED);
                     if(rs.next()){      
                       
                         mg=new pdfManager(rs.getString("FullName"),rs.getString("amka"),
                                 rs.getString("Address"),rs.getString("fathersName"),
                                 rs.getString("mothersName"),rs.getString("bday"),
                                 rs.getString("marState"),rs.getString("job"),
                                 rs.getString("ama"),rs.getString("phone"),
                                 rs.getString("relPhone"),rs.getString("gender"),rs.getString("Details"));   
                                 fileName=new String();
                                 fileName="c:\\temp\\ "+rs.getString("FullName")+".pdf";
                             
                                 filePrompt=rs.getString("FullNameEn")+".pdf";
                                  
                       }
                     ps.close();
                     ps=con.prepareStatement(history_query);
                     ps.setString(1, pid);
                     rs=ps.executeQuery();
                     while(rs.next()){

                         mg.addHistoryRow(rs.getString("date"),rs.getString("service"),rs.getString("description"), rs.getString("medication"), fonty);
                     }
                     mg.close();
                    String pdfFileName = fileName;
		//String contextPath = getServletContext().getRealPath(File.separator);
		File pdfFile = new File(pdfFileName);
              java.nio.ByteBuffer byteBuffer = Charset.forName("UTF-8").encode(filePrompt);
                System.out.println(filePrompt);
		response.setContentType("application/pdf;charset=UTF-8");
		response.addHeader("Content-Disposition", "attachment; filename=\"" + filePrompt+"\"");
                System.out.println( pdfFileName);
		response.setContentLength((int) pdfFile.length());
              
		FileInputStream fileInputStream = new FileInputStream(pdfFile);
		OutputStream responseOutputStream = response.getOutputStream();
		int bytes;
		while ((bytes = fileInputStream.read()) != -1) {
			responseOutputStream.write(bytes);
		}

                         
                        
            }catch (Exception e){
                System.out.println(e);
            }
        
        
        
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
         try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet pdfServlet</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet pdfServlet at " + request.getContextPath() + "</h1>");
            out.println("</body>");
            out.println("</html>");
        }
        
        
        
        
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
