/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.io.PrintWriter;
import static java.lang.System.out;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.swing.JOptionPane;
 import java.sql.SQLException;
 import java.sql.DriverManager;
 import java.sql.ResultSet;
 import java.sql.PreparedStatement;
 import java.sql.Connection;
import java.util.logging.Level;
import java.util.logging.Logger;
/**
 *
 * @author laptop
 */
@WebServlet(urlPatterns = {"/Exists"})
public class Exists extends HttpServlet {

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
            
//        try (PrintWriter out = response.getWriter()) {
//            /* TODO output your page here. You may use following sample code. */
//            out.println("<!DOCTYPE html>");
//            out.println("<html>");
//            out.println("<head>");
//            out.println("<title>Servlet Exists</title>");            
//            out.println("</head>");
//            out.println("<body>");
//            out.println("<h1>Servlet Exists at " + request.getContextPath() + "</h1>");
//            out.println("</body>");
//            out.println("</html>");
//        }
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
        response.setContentType("text/html;charset=UTF-8");
             request.setCharacterEncoding("UTF-8");
            Connection con = null;

            PreparedStatement ps = null;

            ResultSet rs = null;

            String driverName = "com.mysql.jdbc.Driver";

            String url = "jdbc:mysql://localhost/hospital?useUnicode=true&characterEncoding=UTF-8";

            String user = "root";

            String dbpsw = "";
            String exists="select * from users where Username=?";
            String patient_exists="select * from patients where pid=?";
          
            String action=request.getParameter("action");
             
                try {

                    Class.forName(driverName);

                    con = DriverManager.getConnection(url, user, dbpsw);
                    if(action.equals("user")){
                          String username = request.getParameter("username");
                         ps = con.prepareStatement(exists);
                         ps.setString(1, username);
                    }else{
                        
                          String pid = request.getParameter("pid");
                              ps = con.prepareStatement(patient_exists);
                       
                         ps.setString(1, pid);
                         
                    }
                  

                   rs=ps.executeQuery();
                   if(rs.next()){
                      
                    try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.print("found");
                      

            
        }
                       
                   }

                    ps.close();
            }catch (SQLException sqe) {
          
                    out.println(sqe);

                } catch (ClassNotFoundException ex) {
            Logger.getLogger(Exists.class.getName()).log(Level.SEVERE, null, ex);
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
