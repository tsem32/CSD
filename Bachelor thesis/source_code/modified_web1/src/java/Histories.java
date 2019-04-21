/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.io.PrintWriter;
import static java.lang.System.out;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author laptop
 */
@WebServlet(urlPatterns = {"/Histories"})
public class Histories extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
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

        String sql = "SELECT * from history where pid=? ORDER BY date DESC LIMIT 10";
        String patient_sql = "select *from patients where pid=?";
        String pid = request.getParameter("pid-h");

        try {
            Class.forName(driverName);
            con = DriverManager.getConnection(url, user, dbpsw);
            ps = con.prepareStatement(sql);
            ps.setString(1, pid);
            rs = ps.executeQuery();
            PreparedStatement pat_ps = con.prepareStatement(patient_sql);
            pat_ps.setString(1, pid);
            ResultSet pat_rs = pat_ps.executeQuery();
            String table = "";
            if (pat_rs.next()) {

                table += ""
                        + "  <button type=\"button\" class=\"btn btn-default btn-lg\" data-toggle=\"modal\" data-target=\"#myModal\">" + pat_rs.getString("FullName") + "&nbsp;&nbsp;<img src=\"images/icons/menu.png\" width=\"20\" height=\"20\"/> </button>\n"
                        + "  <div class=\"modal fade\" id=\"myModal\" role=\"dialog\" data-show=\"true\">\n"
                        + "    <div class=\"modal-dialog\">\n"
                        + "      <div class=\"modal-content\">\n"
                        + "        <div class=\"modal-header\">\n"
                        + "          <button type=\"button\" class=\"close \" data-dismiss=\"modal\">&times;</button>\n"
                        + "          <h4 class=\"modal-title\" style='color:black'>Καρτέλα</h4>\n"
                        + "        </div>\n"
                        + "        <div class=\"modal-body\">\n"
                        + "<div class=\"alert alert-success\" id=\"success-alert\">\n"
                        + "   \n"
                        + "    <strong>Copied to clipboard! </strong>\n"
                        + "</div>"
                        + "          <div class='panel'/>\n";
                table += "<div class='panel' style='border:none'><div class=\"table-responsive\"  >";
                table += "<table id='patient_table' class=\"table \" >";
                table += "<thead>\n"
                        + "</thead> <tbody>";

                table += "<tr>";
                table += "<th style='color:black' class=\"col-xs-3\"   scope=\"row\">ID:</th>";
                table += "<td  style='color:black'><input id='td-pid' style=\"border:none\" readonly value='"
                        + pat_rs.getString("pid") + "'>";
                table += "</input></td></tr>";
                table += "<tr>";
                table += "<th  style='color:black' class=\"col-xs-3\"   scope=\"row\">Ονοματεπώνυμο:</th>";
                table += "<td style='color:black'>";
                table += pat_rs.getString("FullName");
                table += "</td></tr>";

                table += "<tr>";
                table += "<th style='color:black' class=\"col-xs-3\"  scope=\"row\">Λεπτομέριες:</th>";
                table += "<td style='color:black'><mark style=\"background-color:#cceeff\">";
                table += pat_rs.getString("Details");
                table += "</mark></td></tr>";
                table += "<tr>";
                table += "<th style='color:black' class=\"col-xs-3\" scope=\"row\">Πατρώνυμο:</th>";
                table += "<td style='color:black'>";
                table += pat_rs.getString("fathersName");
                table += "</td></tr>";
                table += "<th style='color:black'  class=\"col-xs-3\" scope=\"row\">Μητρώνυμο:</th>";
                table += "<td style='color:black'>";
                table += pat_rs.getString("mothersName");
                table += "</td></tr>";
                table += "<th style='color:black' class=\"col-xs-3\" scope=\"row\">AMKA:</th>";
                table += "<td style='color:black'>";
                table += pat_rs.getString("amka");
                table += "</td></tr>";
                table += "<th style='color:black' class=\"col-xs-3\" scope=\"row\">Ημ. Γέννησης:</th>";
                table += "<td style='color:black'>";
                table += pat_rs.getString("bday");
                table += "</td></tr>";
                table += "<th style='color:black' class=\"col-xs-3\" scope=\"row\">Διεύθυνση:</th>";
                table += "<td style='color:black'>";
                table += pat_rs.getString("Address");
                table += "</td></tr>";
                table += "<th style='color:black' class=\"col-xs-3\" scope=\"row\">Τηλέφωνο:</th>";
                table += "<td style='color:black'>";
                table += pat_rs.getString("phone");
                table += "</td></tr>";
                table += "<th style='color:black' class=\"col-xs-3\" scope=\"row\">Τηλ. Συγγενούς:</th>";
                table += "<td style='color:black'>";
                table += pat_rs.getString("relPhone");
                table += "</td></tr>";

                table += "</tbody>";
                table += "</table>";
                table += "</div></div>";

                table += "		  </div>\n"
                        + "        </div>\n"
                        + "        <div class=\"modal-footer  justify-content-between\" >\n"
                        + "          <button type=\"button\" class=\"btn btn-primary\" data-dismiss=\"modal\">Close</button>\n"
                        + " <button id='copy-btn' type=\"button\" class=\"btn btn-default pull-left\" onclick='cp()'>Copy ID</button>\n"
                        + "<form class=\"col-xs-4 col-md-2 col-md-push-3\" method='get' action='pdfServlet'><input type='hidden' value='" + pat_rs.getString("pid") + "' name='pid'  accept-charset=\"UTF-8\"> "
                        + "<input type='submit'  class=\"btn  btn-danger \" value='PDF'></form>\n"
                        + "        </div>\n"
                        + "      </div>\n"
                        + "      \n"
                        + "    </div>\n"
                        + "  </div>\n"
                        + "  \n"
                        + "</div>";

            }

            if (!rs.next()) {
                table += "<div class=\"row\">\n"
                        + "\n"
                        + "<div class=\"col-lg-6 col-lg-offset-3 text-center\">"
                        + "<div class=\" text-center alert alert-info\"><strong>Καμία καταχώρηση ιστορικού για τον Ασθενή</strong><br><br><br>";
                if (request.getSession().getAttribute("isAdmin").equals(true)) {
                    table += "<button id=\"history-reg-btn\" onclick=\"history_reg_show()\" type=\"submit\" class=\"btn btn-success btn-lg\">Προσθήκη</button>";

                }
                table += "</div></div></div>";
            } else {
                table += "<h2>Ιστορικό:</h2><div class='panel'><div class=\"table-responsive\" >";
                table += "<table class=\"table table-striped  \" >";
                table += "<thead  style=\"background-color:#F8F8F8\" >\n"
                        + " <tr style=\"color:black\" style='border:1px solid #222222'>\n"
                        + " <th scope=\"col\">Ημερομηνία</th>\n"
                        + " <th scope=\"col\">Υπηρεσία</th>\n"
                        + " <th scope=\"col\">Περιγραφή</th>\n"
                        + " <th scope=\"col\">Αγωγή</th>\n"
                        + " </tr>\n"
                        + " </thead> <tbody>";
                rs.previous();
                while (rs.next()) {

                    table += "<tr >";
                    table += "<td style='color:black'>";
                    table += rs.getString("date");
                    table += "</td>";
                    table += "<td style='color:black'>";
                    table += rs.getString("service");
                    table += "</td>";
                    table += "<td style='color:black'>";
                    table += rs.getString("description");
                    table += "</td>";
                    table += "<td style='color:black'>";
                    table += rs.getString("medication");
                    table += "</td>";
                    table += "</tr>";
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
        String sql = "Insert into history(pid,service,description,date,medication) values(?,?,?,?,?)";
        if (request.getParameter("action").equals("post")) {
            String pid = request.getParameter("pid-h");
            int rows = Integer.parseInt(request.getParameter("hid_rows"));

            for (int i = 1; i <= rows - 1; i++) {

                String service = "ser" + i;
                String description = "descript" + i;
                String date = "date" + i;
                String medication = "medic" + i;

                try {

                    Class.forName(driverName);
                    con = DriverManager.getConnection(url, user, dbpsw);
                    ps = con.prepareStatement(sql);
                    ps.setString(1, pid);
                    ps.setString(2, request.getParameter(service));

                    ps.setString(3, request.getParameter(description));
                    ps.setString(4, request.getParameter(date));
                    ps.setString(5, request.getParameter(medication));
                    ps.execute();
                      ps.close();
                } catch (SQLException sqe) {

                    out.println(sqe);

                } catch (ClassNotFoundException ex) {
                    Logger.getLogger(Users.class.getName()).log(Level.SEVERE, null, ex);
                }

            }
           

            response.sendRedirect("Success.html");

        }else if(request.getParameter("action").equals("complete")){
            
                try {
                    String pid=request.getParameter("hid-pid");
                    String service=request.getParameter("service");
                    String description=request.getParameter("desc");
                   String date=request.getParameter("date");
                   
                    
                    String medication=request.getParameter("medication");
                    String evid=request.getParameter("hid-evid");
                    Class.forName(driverName);
                    con = DriverManager.getConnection(url, user, dbpsw);
                    ps = con.prepareStatement(sql);
                    ps.setString(1, pid);
                    ps.setString(2,(service));
                    ps.setString(3,(description));
                    ps.setString(4,(date));
                    ps.setString(5,(medication));
                    ps.execute();
                    
                    sql="delete from events where evID=?";
                    ps=con.prepareStatement(sql);
                    ps.setString(1, evid);
                    ps.execute();
                   response.getWriter().print("done");
                } catch (SQLException sqe) {

                    out.println(sqe);

                } catch (ClassNotFoundException ex) {
                Logger.getLogger(Histories.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
