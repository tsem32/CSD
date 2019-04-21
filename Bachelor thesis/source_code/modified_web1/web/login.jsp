<%-- 
    Document   : login
    Created on : Mar 4, 2018, 7:29:53 PM
    Author     : laptop
--%>

<%@page import="java.security.NoSuchAlgorithmException"%>
<%@page import="java.security.MessageDigest"%>
<%@page import="javax.swing.JOptionPane"%>
<%@page import="java.sql.SQLException"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.Connection"%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>

    <head>

        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">

        <title>Login</title>

    </head>

    <body>

        <%! String userdbName=new String();

            String userdbPsw=new String();

            String dbUsertype=new String();
            
            String Name=new String();
            String Lname=new String();
             public  String encPass(String pass) 
	{
		String passwordToHash = pass;
		String generatedPassword = null;
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

        %>

        <%
          
            Connection con = null;

            PreparedStatement ps = null;

            ResultSet rs = null;

            String driverName = "com.mysql.jdbc.Driver";

            String url = "jdbc:mysql://localhost/hospital?useUnicode=true&characterEncoding=UTF-8";

            String user = "root";

            String dbpsw = "";

            String sql ="select * from users where Username=? and Password=?";

            String name = request.getParameter("username");

            String password = encPass(request.getParameter("pass"));
            

            if ((!(name.equals(null) || name.equals("")) && !(password.equals(null)
                    || password.equals("")))) {

                try {

                    Class.forName(driverName);

                    con = DriverManager.getConnection(url, user, dbpsw);

                    ps = con.prepareStatement(sql);

                    ps.setString(1, name);

                    ps.setString(2, password);

                    rs = ps.executeQuery();

                    if (rs.next()) {
                         
                        userdbName = rs.getString("Username");

                        userdbPsw = rs.getString("Password");
                    
                        
                        Name=rs.getString("Name");
                        
                        Lname=rs.getString("Lastname");
                        
                        if (name.equals(userdbName) && password.equals(userdbPsw) ) {
                          
                            session.setAttribute("username", userdbName);
                             session.setAttribute("name", Name);
                              session.setAttribute("lname", Lname);
                              session.setAttribute("pass", userdbPsw);
                              if(rs.getBoolean("isAdmin")){
                                   session.setAttribute("isAdmin", true);
                                  response.sendRedirect("Admin.jsp");
                                
                              }else{
                                  
                                  session.setAttribute("isAdmin", false);
                                response.sendRedirect("new_scheduler.jsp");
                              }
                          

                        }   else {
                         
                        response.sendRedirect("login_error.jsp");
                        }
                    }else{
                         response.sendRedirect("login_error.jsp");
                    }
                    

                    
                    rs.close();

                    ps.close();

                } catch (SQLException sqe) {
                     
                    out.println(sqe);

                }

            } else {
                 
        %>

    

        <%      response.sendRedirect("login_error.jsp");

        }

    %>

</body>

</html>
