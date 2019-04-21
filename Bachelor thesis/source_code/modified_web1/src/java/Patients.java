

import java.io.IOException;
import java.io.PrintWriter;
import static java.lang.System.out;
import java.net.URLDecoder;
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
 * Servlet implementation class LoginCheck
 */
@WebServlet("/Patients")
public class Patients extends HttpServlet {
	private static final long serialVersionUID = 1L;
        public Connection con;
    /**
     * @see HttpServlet#HttpServlet()
     */
        public void search_table_Html(String pid,HttpServletRequest request, HttpServletResponse response) throws IOException, SQLException{
             boolean found=false;
                 int count=0;
                try{
                Class.forName("com.mysql.jdbc.Driver");
                  String url="jdbc:mysql://localhost:3306/hospital?useUnicode=true&characterEncoding=UTF-8";
                    con=DriverManager.getConnection(url,"root","");    
                 }catch(Exception e){
                     System.out.println("error"+e);
                }
              
                if(!pid.equals("")){
                String table ="";
                    table+="<div class='panel'><div class=\"table-responsive\">";
                table += "<table class=\"table table-striped\">";
                table+="<thead  style=\"background-color:#F8F8F8\">\n" +
"    <tr style=\"color:black\">\n" +
"      <th scope=\"col\">ID</th>\n" +
"      <th scope=\"col\">Ονοματεπώνυμο</th>\n" +
"      <th scope=\"col\">Πατρώνυμο</th>\n" +
"      <th scope=\"col\">Μητρώνυμο</th>\n" +
"      <th scope=\"col\">ΑΜΚΑ</th>\n" +
 "      <th scope=\"col\">Ημ. Γέννησης</th>\n" +
 "      <th scope=\"col\">Διεύθυνση</th>\n" +
 "      <th scope=\"col\">Τηλέφωνου</th>\n" +
 "      <th scope=\"col\">Τηλέφωνο Συγγενούς</th>\n" +                        
"    </tr>\n" +
"  </thead> <tbody>";

            try {
                 String sql_query="SELECT * FROM patients WHERE FullName LIKE ?";
                
              
              
                PreparedStatement smt=con.prepareStatement(sql_query);
                smt.setString(1, "%"+pid+"%");
                ResultSet rs=smt.executeQuery();
              
                while(rs.next()){
                    count++;
                    found=true;                   
                    table += "<tr>";
                    table += "<td id='tab_id'> <a href=\"#\" onclick='document.getElementById(\""+rs.getString("pid")+"\").submit()'>";
                    table +=  rs.getString("pid");
                    table+="<form id='"+rs.getString("pid")+"' action=\"history.jsp\" method='get'>"
                            + "<input type='hidden' name='pid-h' value='"+rs.getString("pid")+"'></form>";
                                
                    table += "</td>";
                    table += "<td><a href=\"#\" onclick='document.getElementById(\""+rs.getString("pid")+"\").submit()'>";
                    table +=    rs.getString("FullName");
                    table += "</td>";
                    table += "<td style='color:black'>";
                    table +=    rs.getString("fathersName");
                    table += "</td>";
                    table += "<td style='color:black'>";
                    table +=    rs.getString("mothersName");
                    table += "</td>";
                    table += "<td style='color:black'>";
                    table +=    rs.getString("amka");
                    table += "</td>";
                    table += "<td style='color:black'>";
                    table +=    rs.getString("bday");
                    table += "</td>";
                    table += "<td style='color:black'>";
                    table +=    rs.getString("Address");
                    table += "</td>";
                    table += "<td style='color:black'>";
                    table +=    rs.getString("phone");
                    table += "</td>";
                    table += "<td style='color:black'>";
                    table +=    rs.getString("relPhone");
                    table += "</td>";
                    table += "</tr>";
                }
                 table+="</tbody>";
                 table += "</table>";
                 table+="</div></div>";
                         
            } catch (SQLException ex) {
                Logger.getLogger(Events.class.getName()).log(Level.SEVERE, null, ex);
            }
             response.setContentType("text/html;charset=UTF-8");
              
              response.setCharacterEncoding("UTF-8");
              request.setCharacterEncoding("UTF-8");
                PrintWriter out = response.getWriter();
                 if(found){
                       table="   <h1>Βρέθηκαν "+count+" αποτελέσματα</h1>"+table;
                 out.println(table);
                    con.close();
                 }else{
                     table="";
                     table+="<div class=\"alert alert-info\">\n" +
"   Patient not found \n" +
"</div>"; 
                    
                       table="   <h1>Βρέθηκαν "+count+" αποτελέσματα </h1>"+table;
                      out.println(table);
                         con.close();
                 }
                 
        }
               
        }
        public void get_patient_Html(String pid,HttpServletRequest request, HttpServletResponse response) throws IOException{
            try{
                Class.forName("com.mysql.jdbc.Driver");
                  String url="jdbc:mysql://localhost:3306/hospital?useUnicode=true&characterEncoding=UTF-8";
                    con=DriverManager.getConnection(url,"root","");    
                 }catch(Exception e){
                     System.out.println("error"+e);
                }
              
                if(!pid.equals("")){
                String table ="";
                    table+="<div class=\"table-responsive\">";
                table += "<table id='patient_table' class=\"table table-striped\">";
                table+="<thead>\n" +
                        "<tr class=\"bg-primary\">\n" +
                        "      <th scope=\"col\">Info</th>\n" +
                        "</tr>\n" +
                        "</thead> <tbody>";

            try {
                 String sql_query="SELECT * FROM patients WHERE InStr('"+pid+"', FullName) > 0";
                PreparedStatement smt=con.prepareStatement(sql_query);
                ResultSet rs=smt.executeQuery();
              
                if(rs.next()){              
                    table += "<tr>";
                    table+="<th scope=\"row\">Patient ID:</th>";
                    table += "<td style='color:black' >";
                    table +=  rs.getString("pid");
                    table += "</td></tr>";
                    
                     table += "<tr>";
                      table+="<th scope=\"row\">FullName:</th>";
                    table += "<td style='color:black'>";
                    table +=  rs.getString("FullName");
                    table += "</td></tr>";
                    
                     table += "<tr>";
                      table+="<th scope=\"row\">History:</th>";
                    table += "<td style='color:black'>";
                    table +=    rs.getString("History");
                   table += "</td></tr>";
                   table += "<tr>";
                      table+="<th scope=\"row\">Details:</th>";
                    table += "<td style='color:black'>";
                    table +=    rs.getString("Details");
                     table += "</td></tr>";
                     
                     table += "<tr>";
                     table+="<th scope=\"row\">Age:</th>";
                     table += "<td style='color:black'>";
                    table +=    rs.getInt("Age");
                   table += "</td></tr>";
                     
                     table += "<tr>";
                     table+="<th scope=\"row\">Birth Date::</th>";
                    table += "<td style='color:black'>";
                    table +=    rs.getString("bday");
                   table += "</td></tr>";
                   table += "<tr>";
                     table+="<th scope=\"row\">Address:</th>";
                    table += "<td style='color:black'>";
                    table +=    rs.getString("Address");
                    table += "</td>";
                    table += "</td></tr>";
                }
                 table+="</tbody>";
                 table += "</table>";
                 table+="</div>";
                         
            } catch (SQLException ex) {
                Logger.getLogger(Events.class.getName()).log(Level.SEVERE, null, ex);
            }
            
       response.setContentType("text/html;charset=UTF-8");
              
              response.setCharacterEncoding("UTF-8");
                PrintWriter out = response.getWriter();
                 out.println(table);

        }
            
            
            
        }
        
    public Patients()  {
        super();
        
        }
        
    
        
        // TODO Auto-generated constructor stub
    

	/**
     * @param request  
     * @param response  
     * @throws javax.servlet.ServletException  
     * @throws java.io.IOException  
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
        @Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
                request.setCharacterEncoding("UTF-8");
                response.setContentType("text/html;charset=UTF-8");
                response.setCharacterEncoding("UTF-8");
       
		String pid=request.getParameter("pid");
                String action=request.getParameter("action");
                
                if(action.equals("search")){
                    try {
                        this.search_table_Html(pid, request, response);
                    } catch (SQLException ex) {
                        Logger.getLogger(Patients.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }else if(action.equals("get_patient")){ 
                    this.get_patient_Html(pid, request, response);
                }
                
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
                request.setCharacterEncoding("UTF-8");
                response.setContentType("text/html;charset=UTF-8");
                response.setCharacterEncoding("UTF-8");
               String driverName = "com.mysql.jdbc.Driver";
            String url = "jdbc:mysql://localhost/hospital?useUnicode=true&characterEncoding=UTF-8";
            String user = "root";
            String dbpsw = "";
             String action =request.getParameter("action");
                     
                String sql_query="SELECT COUNT(pid) from patients";
                 String sql_insert="INSERT INTO patients(pid,FullName,fathersName,mothersName,gender,marState,Insurance,amka,ama,relPhone,job,Details,bday,phone,Address,FullNameEn) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
                 int records=0;
                 PreparedStatement smt=null;
                 if(action.equals("delete")){
                     doDelete(request,response);
                 }else{
            try {
                 Class.forName(driverName);
                 con = DriverManager.getConnection(url, user, dbpsw); 
                //smt = con.prepareStatement(sql_query);
                 //ResultSet rs=smt.executeQuery();
                // if(rs.next())records=rs.getInt("COUNT(pid)");
                 //records++;
                 Random r = new Random();
                 String pid="";
                    String alphabet = "1234567890abcdefghijklmnopqrstvuwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                 for (int i = 0; i < 4; i++) {
                    pid+=alphabet.charAt(r.nextInt(alphabet.length()));
                 } 
                 System.out.println(request.getParameter("FullNameEn"));
                 smt=con.prepareStatement(sql_insert);
                 smt.setString(1, pid);
                 smt.setString(2, request.getParameter("fullname"));
                 smt.setString(3, request.getParameter("fathersName"));
                 smt.setString(4, request.getParameter("mothersName"));
                 smt.setString(5, request.getParameter("gender"));
                 smt.setString(6, request.getParameter("marState"));
                 smt.setString(7, request.getParameter("Insurance"));
                 smt.setString(8, request.getParameter("amka"));
                 smt.setString(9, request.getParameter("insId"));
                 smt.setString(10,request.getParameter("relPhone"));
                 smt.setString(11,request.getParameter("job"));
                 smt.setString(12,request.getParameter("details"));
                 smt.setString(13,request.getParameter("bday"));
                 smt.setString(14,request.getParameter("phone"));
                 smt.setString(15,request.getParameter("address"));
                 smt.setString(16,request.getParameter("FullNameEn"));
                 smt.execute();
                 smt.close();
                 con.close();
                 response.sendRedirect("Success.html");
               
            } catch (SQLException ex) {
                Logger.getLogger(Patients.class.getName()).log(Level.SEVERE, null, ex);
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(Patients.class.getName()).log(Level.SEVERE, null, ex);
            }
                 }
               
              
	}
        
        @Override
    protected void doDelete(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException{
         request.setCharacterEncoding("UTF-8");
                response.setContentType("text/html;charset=UTF-8");
                response.setCharacterEncoding("UTF-8");
               
        Connection con = null;
        PreparedStatement ps = null;

          ResultSet rs = null;

            String driverName = "com.mysql.jdbc.Driver";

            String url = "jdbc:mysql://localhost/hospital?useUnicode=true&characterEncoding=UTF-8";

            String user = "root";

            String dbpsw = "";

            String sql ="DELETE FROM patients where pid=?";
            String hist_del="DELETE FROM history where pid=?";
            String username = request.getParameter("pid");

 
          
            try {

                    Class.forName(driverName);
                    con = DriverManager.getConnection(url, user, dbpsw);                 
                    ps = con.prepareStatement(sql);
                    ps.setString(1, username);
                   ps.execute();
                   ps=con.prepareStatement(hist_del);
                   ps.setString(1, username);
                   ps.execute();
                   
                    ps.close();
                    response.sendRedirect("Success.html");
                } catch (SQLException sqe) {
          
                    out.println(sqe);

                } catch (ClassNotFoundException ex) {
            Logger.getLogger(Users.class.getName()).log(Level.SEVERE, null, ex);
        }
            
        
        
    }

}

