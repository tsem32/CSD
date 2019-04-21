<%-- 
    Document   : new_scheduler
    Created on : Mar 13, 2018, 7:17:34 PM
    Author     : laptop
--%>

<%@page import="javax.swing.JOptionPane"%>
<%@page contentType="text/html charset=\"UTF-8\"" pageEncoding="UTF-8" %>
<!DOCTYPE html> 
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Διαχείρηση</title>
    <link rel="stylesheet" href="Calendar/build/aui-css/css/bootstrap.css">
    <script src="Calendar/build/aui/aui.js"></script>
    <script src="Calendar/build/aui/aui-min.js"></script>
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  <script src="ajax.js"></script>
  
<style>
      * {box-sizing: border-box;}

            body {
                margin: 0;
                font-family: Arial, Helvetica, sans-serif;
            }
            
          .tooltip-inner {
      background-color: #ff4954; 
      color: white;
      border: 1px solid #ff4954;
  }

.navbar-default {
    background-color: white;
    border-color: #E7E7E7;
	
}
.navbar-default .navbar-nav > li > a {
    color: #777777;
	border-radius:5px;
}
.navbar-default .navbar-nav > .active > a, .navbar-default .navbar-nav > .active > a:hover, .navbar-default .navbar-nav > .active > a:focus {
   
    color: #555555;
}
  #scheduler{
  width:40px;
  }

</style>
</head>
<body class="bg-primary">
    <%  
    String pageName = "logout.jsp";  
request.setCharacterEncoding("UTF-8");
response.setContentType("text/html;charset=UTF-8");

%>
    <%  
 
    String home="Admin.jsp";
     session = request.getSession(false);
        if (session.getAttribute("username") == null) {
            response.sendRedirect("new_login.jsp");
        }else if(session.getAttribute("isAdmin").equals(false)){
         response.sendRedirect("new_login.jsp");
    }
%>

	<nav class="navbar navbar-default">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="Admin.jsp"><%=session.getAttribute("name")%>  <%=session.getAttribute("lname")%></a>
    </div>
    <ul class="nav navbar-nav">
      <li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" href="#">Προφίλ <span class="caret"></span></a>
        <ul class="dropdown-menu">
            <li><a href="#" onclick="location.href = 'admin_profile.jsp';" >Προβολή</a></li>
          <li><a href="UpdateCredentials.jsp">Αλλαγή Στοιχείων</a></li>
        </ul>
      </li>
    </ul>
     <ul class="nav navbar-nav navbar-right">
      <form class="navbar-form navbar-left" action="Search" method="post" accept-charset="UTF-8">
          
        <input id='search_text' type="text" class="form-control" placeholder="Search" name="search">
        <input id='action' type="hidden" class="form-control" placeholder="Search" name="action" value="search"  >
        <button   id='search_btn' type="submit" class="btn btn-default glyphicon glyphicon-search" ></button>
      
          
    </form>
      <li><a href="#"onclick="redirectPage('<%=pageName%>')" ><span class="glyphicon glyphicon-log-in"></span> Έξοδος</a></li>
      
    </ul>
   
  </div>
</nav>


    <div id="scheduler"></div>
    <div id="ajax">
     
     <div class="row">
        <div class="col-lg-6 col-lg-offset-3 text-center">
            
             <div   id="profile">  </div>
              <div   id="admin-panel"> 
                   <div class="panel" style="border:1px solid #222222">
      <div class="panel-heading" style="background-color:#e6e6e6;color:black;">Νοσηλευτές</div>
      <div class="panel-body">
    
                  <a href="ShowNurse.jsp" class="btn btn-sq-sm btn-warning " style="width:150px;height:65px;" >
              <i class="fa fa-user fa-2x"></i><br/>
                Προβολή
            </a>
                 <a href="register_user.jsp"  class="btn btn-sq-sm btn-success" style="width:150px;height:65px;">
              <i class="fa fa-plus-square fa-2x"></i><br/>
              Προσθήκη Χρήστη
            </a> 
                  <a  id="del_btn" onclick="show_delete()" class="btn btn-sq-sm btn-danger"style="width:150px;height:65px;" >
              <i class="fa fa-remove fa-2x"></i><br/>
                Διαγραφή
            </a>
          <br><br>
          
          <form id="del" method="post" action="Users" style="display:none">
           
                <input style="color:black" data-placement="top" title="Μη έγκυρο ID!" id="username" oninput="test3()" type="text" placeholder="Όνομα χρήστη"  name="username" required>
                
                <input type="hidden" name="action" value="delete" />
                <button  id="del-btn"type="submit" class="btn btn-primary">Διαγραφή</button>
                
          </form>
          </div>
      </div>
                  <br>
                  <br>
                   <div class="panel" style="border:1px solid #222222" >
      <div class="panel-heading"  style="background-color:#e6e6e6;color:black;">Ασθενείς</div>
      <div class="panel-body">
                  <a id="history-btn-show" onclick="show_history_form()" class="btn btn-sq-sm btn-warning "  style="width:150px;height:65px;" >
              <i class="fa fa-user fa-2x"></i><br/>
                Ιστορικό 
            </a>

               <a href="register_patient.jsp" class="btn btn-sq-sm btn-success" style="width:150px;height:65px;" >
              <i class="fa fa-plus-square fa-2x"></i><br/>
                Προσθήκη Καρτέλας
            </a>
                 <a id="del-btn-pat" onclick="show_delete_pat()" class="btn btn-sq-sm btn-danger"  style="width:150px;height:65px;">
              <i class="fa fa-remove fa-2x"></i><br/>
                Διαγραφή
            </a>  
           <br><br>
          
          <form id="del-pat" method="post" action="Patients" style="display:none">
                
                <input style="color:black" data-placement="top" title="Μη έγκυρο ID!" id="pid" oninput="test4()" type="text" placeholder="ID Ασθενούς"  name="pid" required>
                
                <input type="hidden" name="action" value="delete"/>
                <button  id="del-btn_pat"type="submit" class="btn btn-primary">Διαγραφή</button>
                
          </form>
           <form id="history-form" action="history.jsp" style="display:none">
                
                <input  style="color:black"data-placement="top" title="Μη έγκυρο ID!" id="pid-h" oninput="history_pid_validate()" type="text" placeholder="ID Ασθενούς"  name="pid-h" required>
                <button  id="history-btn-submit"type="submit" class="btn btn-success">Προβολή</button>
                
          </form>
      </div>
   </div>
   
              </div>
        </div>
</div>
       
</body>
</html>