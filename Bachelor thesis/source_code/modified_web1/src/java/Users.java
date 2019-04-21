/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.io.PrintWriter;
import static java.lang.System.out;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;
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
@WebServlet(urlPatterns = {"/Users"})
public class Users extends HttpServlet {

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
        response.setContentType("text/html;charset=UTF-8");
        response.setCharacterEncoding("UTF-8");
        request.setCharacterEncoding("UTF-8");

    }
   protected void updateEventUsername(String newUsername,String oldUsername,Connection con) throws SQLException{
       String sql= "UPDATE events SET user_id=? where user_id=?";
       PreparedStatement smt=con.prepareStatement(sql);
      
       try{
            smt.setString(1, newUsername);
             smt.setString(2, oldUsername);
             smt.execute();
             smt.close();
       }  catch (SQLException sqe) {

            out.println(sqe);

        }
       
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
        Connection con = null;

        PreparedStatement ps = null;

        ResultSet rs = null;

        String driverName = "com.mysql.jdbc.Driver";

        String url = "jdbc:mysql://localhost/hospital?useUnicode=true&characterEncoding=UTF-8";

        String user = "root";

        String dbpsw = "";

        String exists = "select * from users where Username=?";
        String action = request.getParameter("action");
        String username = request.getParameter("username");
        try {
            Class.forName(driverName);
            con = DriverManager.getConnection(url, user, dbpsw);
            ps = con.prepareStatement(exists);
            ps.setString(1, username);
            rs = ps.executeQuery();
            String table = "";
            if (action.equals("update")) {
                if (rs.next()) {
                    table = rs.getString("Name") + "|" + rs.getString("Lastname") + "|" + rs.getString("Username") + "|";
                }
            }
            if (action.equals("show_all")) {

                getAll(request, response);
            } else {
                table += "<div class='panel' style='border:none'><div class=\"table-responsive\"  >";
                table += "<table id='patient_table' class=\"table \" style=\"border:2px solid #F8F8F8\">";
                table += "<thead>\n"
                        + "</thead> <tbody>";
                if (rs.next()) {
                    table += "<tr>";
                    table += "<th  class=\"col-xs-3\" style=\"background-color:#F8F8F8; color:black;\" scope=\"row\">Όνομα:</th>";
                    table += "<td  style='color:black'>";
                    table += rs.getString("Name");
                    table += "</td></tr>";
                    table += "<tr>";
                    table += "<th  class=\"col-xs-3\" style=\"background-color:#F8F8F8; color:black;\" scope=\"row\">Επίθετο:</th>";
                    table += "<td style='color:black'>";
                    table += rs.getString("Lastname");
                    table += "</td></tr>";

                    table += "<tr>";
                    table += "<th  class=\"col-xs-3\" style= \"background-color:#F8F8F8; color:black;\" scope=\"row\">Όνομα Χρήστη:</th>";
                    table += "<td style='color:black'>";
                    table += rs.getString("Username");
                    table += "</td></tr>";
                    table += "<tr>";
                    table += "<th  class=\"col-xs-3\" style=\"background-color:#F8F8F8; color:black;\" scope=\"row\">E-mail:</th>";
                    table += "<td style='color:black'>";
                    table += rs.getString("email");
                    table += "</td></tr>";
                }
                table += "</tbody>";
                table += "</table>";
                table += "</div></div>";
            }
            try (PrintWriter out = response.getWriter()) {
                out.print(table);
            }
            ps.close();

        } catch (SQLException sqe) {

            out.println(sqe);

        } catch (ClassNotFoundException ex) {
            Logger.getLogger(Users.class.getName()).log(Level.SEVERE, null, ex);
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
        Connection con = null;
        PreparedStatement ps = null;

        ResultSet rs = null;

        String driverName = "com.mysql.jdbc.Driver";

        String url = "jdbc:mysql://localhost/hospital?useUnicode=true&characterEncoding=UTF-8";

        String user = "root";

        String dbpsw = "";

        String sql = "Insert into users(Username,Password,Name,Lastname,isAdmin,email) values(?,?,?,?,?,?)";
      
        String username = request.getParameter("username");

        String action = request.getParameter("action");
        String password = request.getParameter("pass");
        String name = request.getParameter("name");
        String lname = request.getParameter("lname");
        String type = request.getParameter("type");
        String email=request.getParameter("email");
        boolean isAdmin = false;

        if (action.equals("delete")) {
            doDelete(request, response);
        } else if (action.equals("update")) {
            doUpdate(request, response);
        }else if(action.equals("register")){
            String check="select * from staff where ama=?";
            PreparedStatement pr=null;
            try {
                     Class.forName(driverName);
                con = DriverManager.getConnection(url, user, dbpsw);
                pr = con.prepareStatement(check);
                  pr.setInt(1, Integer.parseInt(username));
                  ResultSet res=pr.executeQuery();
                  if(res.next()){
                      if(!res.getBoolean("hasActive")){
                      pr=con.prepareStatement("Insert into users(Username,Password,Name,Lastname,isAdmin,email) values(?,?,?,?,?,?)");
                       Random r = new Random();
                        String uname="";
                        String pwd="";
                        String alphabet = "1234567890abcdefghijklmnopqrstvuwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                            for (int i = 0; i < 4; i++) {
                    uname+=alphabet.charAt(r.nextInt(alphabet.length()));
                 } 
                      for (int i = 0; i < 4; i++) {
                    pwd+=alphabet.charAt(r.nextInt(alphabet.length()));
                 } 
                    pr.setString(1, uname);
                    pr.setString(2, encPass(pwd));
                    pr.setString(3, name);
                    pr.setString(4, lname);
                    pr.setBoolean(5, false);
                    pr.setString(6, email);
                  
                    mailSender ms=new mailSender();
                    ms.send(email, uname, pwd);
                      pr.execute();
                      String updateActive="update staff set hasActive=? where ama=?";
                      pr=con.prepareStatement(updateActive);
                      pr.setBoolean(1, true);
                    
                      pr.setInt(2, Integer.parseInt(username));
                      pr.execute();
                      }else{
                           mailSender ms=new mailSender();
                           ms.send_AlreadyActive(email);
                      }
                  }else{
                          mailSender ms=new mailSender();
                           ms.send_NonValid(email);
                  }
                  response.sendRedirect("ApplySuccess.html");
            } catch (SQLException ex) {
                Logger.getLogger(Users.class.getName()).log(Level.SEVERE, null, ex);
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(Users.class.getName()).log(Level.SEVERE, null, ex);
            }
          
            
        }
        else {
            try {

                Class.forName(driverName);
                con = DriverManager.getConnection(url, user, dbpsw);
                if (type.equals("true")) {
                    isAdmin = true;
                }
                ps = con.prepareStatement(sql);
                ps.setString(1, username);
                ps.setString(2, encPass(password));
                ps.setString(3, name);
                ps.setString(4, lname);
                ps.setBoolean(5, isAdmin);
                   ps.setString(6, email);
                ps.execute();
 mailSender sender=new mailSender();
           // sender.send(request.getParameter("email"), username, password);
                ps.close();

                response.sendRedirect("success.jsp");
            } catch (SQLException sqe) {

                out.println(sqe);

            } catch (ClassNotFoundException ex) {
                Logger.getLogger(Users.class.getName()).log(Level.SEVERE, null, ex);
            }

        }

    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    protected void doDelete(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
        Connection con = null;
        PreparedStatement ps = null;

        ResultSet rs = null;

        String driverName = "com.mysql.jdbc.Driver";

        String url = "jdbc:mysql://localhost/hospital?useUnicode=true&characterEncoding=UTF-8";

        String user = "root";

        String dbpsw = "";

        String sql = "DELETE FROM users where Username=?";
        String event_del = "DELETE FROM events where user_id=?";

        String username = request.getParameter("username");

        try {

            Class.forName(driverName);
            con = DriverManager.getConnection(url, user, dbpsw);
            ps = con.prepareStatement(sql);
            ps.setString(1, username);
            ps.execute();
            ps = con.prepareStatement(event_del);
            ps.setString(1, username);
            ps.execute();
            ps.close();
            response.sendRedirect("success.jsp");
        } catch (SQLException sqe) {

            out.println(sqe);

        } catch (ClassNotFoundException ex) {
            Logger.getLogger(Users.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

    protected void doUpdate(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
        Connection con = null;
        PreparedStatement ps = null;
        String username = request.getParameter("username");

        String action = request.getParameter("action");
        String password = encPass(request.getParameter("pass"));
        String name = request.getParameter("name");
        String lname = request.getParameter("lname");
        String initial = request.getParameter("init");

        String driverName = "com.mysql.jdbc.Driver";

        String url = "jdbc:mysql://localhost/hospital?useUnicode=true&characterEncoding=UTF-8";

        String user = "root";

        String dbpsw = "";

        String sql = "UPDATE users SET Username=?,Password=?,Name=?,Lastname=? WHERE Username=?";

        try {

            Class.forName(driverName);
            con = DriverManager.getConnection(url, user, dbpsw);
            ps = con.prepareStatement(sql);
            ps.setString(1, username);
            ps.setString(2, password);
            ps.setString(3, name);
            ps.setString(4, lname);
            ps.setString(5, initial);
            ps.execute();
            ps.close();
            updateEventUsername(username,initial,con);
          request.getSession().setAttribute("username", username);
          request.getSession().setAttribute("pass", password);
        
            response.sendRedirect("success.jsp");
        } catch (SQLException sqe) {

            out.println(sqe);

        } catch (ClassNotFoundException ex) {
            Logger.getLogger(Users.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    protected void getAll(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
        Connection con = null;
        PreparedStatement ps = null;

        String driverName = "com.mysql.jdbc.Driver";

        String url = "jdbc:mysql://localhost/hospital?useUnicode=true&characterEncoding=UTF-8";

        String user = "root";

        String dbpsw = "";

        String sql = "select * from users order by Name ASC";
        String table = "";
        table += "<div class='panel' style='border:none'> <div class=\"table-responsive\">";
        table += "<table class=\"table table-striped\">";
        table += "<thead  style=\"background-color:#F8F8F8\">\n"
                + "    <tr style=\"color:black\">\n"
                + "      <th scope=\"col\">Ον.Χρήστη</th>\n"
                + "      <th scope=\"col\">Ονομα</th>\n"
                + "      <th scope=\"col\">Επίθετο</th>\n"
                + "    </tr>\n"
                + "  </thead> <tbody>";

        try {

            Class.forName(driverName);
            con = DriverManager.getConnection(url, user, dbpsw);
            ps = con.prepareStatement(sql);
            ResultSet rs = ps.executeQuery();
            while (rs.next()) {
                table += "<tr>";
                table += "<td style='color:black'>";
                table += rs.getString("Username");
                table += "</td>";
                table += "<td style='color:black'>";
                table += rs.getString("Name");
                table += "</td>";
                table += "<td style='color:black'>";
                table += rs.getString("Lastname");
                table += "</td>";
                table += "</tr>";
            }
            table += "</tbody>";
            table += "</table>";
            table += "</div></div>";
            PrintWriter out = response.getWriter();
            out.print(table);
            ps.close();

        } catch (SQLException sqe) {

            out.println(sqe);

        } catch (ClassNotFoundException ex) {
            Logger.getLogger(Users.class.getName()).log(Level.SEVERE, null, ex);
        }

    }
    public  String encPass(String pass) 
	{
		String passwordToHash = pass;
		String generatedPassword = new String();
		try {
			// Create MessageDigest instance for MD5
			MessageDigest md = MessageDigest.getInstance("MD5");
			//Add password bytes to digest
			md.update(passwordToHash.getBytes());
			//Get the hash's bytes 
			byte[] bytes = md.digest();
			//This bytes[] has bytes in decimal format;
			//Convert it to hexadecimal format
			StringBuilder sb = new StringBuilder();
			for(int i=0; i< bytes.length ;i++)
			{
				sb.append(Integer.toString((bytes[i] & 0xff) + 0x100, 16).substring(1));
			}
			//Get complete hashed password in hex format
			generatedPassword = sb.toString();
		} 
		catch (NoSuchAlgorithmException e) 
		{
			e.printStackTrace();
		}
		return (generatedPassword);
	}

}
