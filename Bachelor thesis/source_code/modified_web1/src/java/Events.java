/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Random;
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
@WebServlet(urlPatterns = {"/Events"})
public class Events extends HttpServlet {
    public Connection con;
   

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
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
       
        try {
            processRequest(request, response);
            // response.setContentType("text/plain");
              Class.forName("com.mysql.jdbc.Driver");
          String url="jdbc:mysql://localhost:3306/hospital?useUnicode=true&characterEncoding=UTF-8";
          
            con=DriverManager.getConnection(url,"root","");    
            String user=request.getParameter("user");
            String view=request.getParameter("view");
            String content=new String();
            String date=new String();
           // String sql_query="select *from events where pID in ( SELECT pID FROM `events` WHERE user_id=? and pID!=\"nonvalid\")";
           String sql_query=new String();
           if(view.equals("personal")){
               sql_query="select * from events where pid in (select pid from events where user_id=?)";
           }else{
               sql_query="select * from events where isSimple=? ";
           }
           
            PreparedStatement smt=con.prepareStatement(sql_query);
             
            if(view.equals("personal")){
                smt.setString(1, user);
            }else{
                smt.setBoolean(1, false);
            }
            ResultSet rs=smt.executeQuery();
              
            Date cur_date=new Date();
            Calendar da = new GregorianCalendar();
            int year = da.get(Calendar.YEAR);  
   
            Date db_date;
            
            String jsn="";
 
            if(rs.next()){
                rs.previous();
                while(rs.next()){
                    content=rs.getString("Content");
                    date=rs.getString("Date");
                    if(date.contains("-")){
                        String start[]=date.split(",");
                        String hour[]=start[2].split("-");
                        String startDate=start[0]+","+start[1]+","+year+","+hour[0];
                         String endDate=start[0]+","+start[1]+","+year+","+hour[1];
                          db_date=new Date(endDate);
                          jsn=jsn+content+"|"+startDate+"|";
                          jsn=jsn+endDate+"|";
                            if(!rs.getString("user_id").equals(user)){
                                 jsn=jsn+"#686868|";//"#7a5c52|";
                            }else
                            if(cur_date.getMonth()>db_date.getMonth()||cur_date.getYear()>db_date.getYear()){
                                jsn=jsn+"#c13630|";
                             }else if(cur_date.getMonth()==db_date.getMonth() && cur_date.getDate()>db_date.getDate()){
                                    jsn=jsn+"#c13630|";
                            }else if(cur_date.getMonth()==db_date.getMonth() && cur_date.getDate()==db_date.getDate()){
                                      jsn=jsn+"#dd8a14|";
                                }else{
                                    jsn=jsn+"#5BB85F|";
                              }   
                         jsn=jsn+"false|";
                         
                    }
                    if(!rs.getString("user_id").equals(user)){
                         jsn=jsn+"true|";
                    }else{
                         jsn=jsn+"false|";
                    }
                     jsn=jsn+rs.getString("user_id")+"|";
                      jsn=jsn+ rs.getString("evID")+"|";
                       jsn=jsn+ rs.getString("service")+"|";
                }
                 PrintWriter out = response.getWriter();
                 out.write(jsn);
            }
        } catch (SQLException | ClassNotFoundException ex) {
            Logger.getLogger(Events.class.getName()).log(Level.SEVERE, null, ex);
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
        boolean is_simple=false;
        String value=request.getParameter("cont");
        String date=request.getParameter("date");
        String user=request.getParameter("user");
        String action=request.getParameter("action");
        
        String sql_query="INSERT into events(user_id,Content,Date,evID,pID,service,isSimple)"+" values(?,?,?,?,?,?,?)";
        String name="select FullName from patients where pid=?";
        String delete="DELETE FROM events where evID=?";
        String update="update events set Date=?,service=? where evID=?";
      
        try{
            Class.forName("com.mysql.jdbc.Driver");
          String url="jdbc:mysql://localhost:3306/hospital?useUnicode=true&characterEncoding=UTF-8";

            con=DriverManager.getConnection(url,"root","");    
        }catch(Exception e){
            System.out.println("error"+e);
        }
  
            PreparedStatement smt;
            try {
                if(action.equals("delete")){
                    
                      smt=con.prepareStatement(delete);
                     String evid=request.getParameter("evid");
                      
                       smt.setString(1, evid);
                 
                smt.execute();
                }else if(action.equals("edit")){
                    
                  PreparedStatement upd_stm=con.prepareStatement(update);
                  upd_stm.setString(1, date);
                  
                  upd_stm.setString(2, value);
                  upd_stm.setString(3, user);
                 
                  upd_stm.execute();
                }
                else{
                    
               
                    smt=con.prepareStatement(sql_query);
                    PreparedStatement name_smt=con.prepareStatement(name);
                    name_smt.setString(1, value);
                    ResultSet name_rs=name_smt.executeQuery();
                     Random r = new Random();
                 String evt_id="";
                    String alphabet = "1234567890abcdefghijklmnopqrstvuwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                 for (int i = 0; i < 4; i++) {
                    evt_id+=alphabet.charAt(r.nextInt(alphabet.length()));
                 } 
                 String initial=value;
                    if(name_rs.next()){
                         value=name_rs.getString("FullName")+"-"+value+"-"+evt_id;
                    }else{
                        value=value+"-"+evt_id;
                    }         
                     if(!date.contains("-")){
                   Date cur=new Date();
                   String hours=Integer.toString(cur.getHours());
                   String mins= Integer.toString(cur.getMinutes());
                    if(mins.length()==1){
                     mins="0"+mins;
                     }
                   
                   date=date+", "+hours+":"+mins+" - "+hours+":"+mins;
               }
                      smt.setString(1, user);
                smt.setString(2, value);
                smt.setString(3, date);
                 smt.setString(4, evt_id);
                 if((initial+"-"+evt_id).equals(value)){
                     initial="noinfo"+evt_id;
                     is_simple=true;
                 }
                smt.setString(5, initial);
                smt.setString(6,request.getParameter("service"));
                smt.setBoolean(7, is_simple);
                smt.execute();
                }
              
               
            } catch (SQLException ex) {
                Logger.getLogger(Events.class.getName()).log(Level.SEVERE, null, ex);
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
