<%-- 
    Document   : new_scheduler
    Created on : Mar 13, 2018, 7:17:34 PM
    Author     : laptop
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Δημιουργία Λοαγαριασμού</title>
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

<script>profile_view('<%= session.getAttribute("username") %>');</script>
</head>
<body class="bg-primary" >
    <%  
    String pageName = "logout.jsp";  
%>

 <%  
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
          <li><a href="">Αλλαγή Στοιχείων</a></li>
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
    <div  id="scheduler"></div>
    <div class="row">
        <div class="col-lg-6 col-lg-offset-3 text-center">
     <div class="panel" style="border:1px solid #222222">
         <div class="panel-heading" style="background-color:#F8F8F8;color:black;"><b>Δημιουργία λογαριασμού</b></div>
      <div class="panel-body">
          <form class="form-block" action="Users" method="post" accept-charset="UTF-8">
                    <input type="hidden" name="action" value="post" required>
    <div class="form-group">
      <input id='user' type="text" class="form-control" placeholder="Όνομα χρήστη"  name="username" onchange="test2()" required>
      <div id='error'class="alert alert-danger" style="display:none">Το όνομα χρήστη χρησιμοποιείται</div>
    </div>
     <div class="form-group">
      <input type="text" class="form-control"  placeholder="Όνομα"  name="name" required>
    </div>
    <div class="form-group">
      <input type="text" class="form-control"  placeholder="Επίθετο"  name="lname" required>
    </div>
    <div class="form-group">
      <input type="password" class="form-control" placeholder="Κωδικός" name="pass" required>
    </div>
      <div class="form-group">
      <input type="email" class="form-control" placeholder="Email" name="email" required>
    </div>               
      <select class="form-control" name="type">
        <option value="true">Διαχειριστής</option>
        <option value="false">Νοσηλευτής</option>
      </select>
                  <br>
                  <br>
    <button id='regBtn' type="submit" class="btn btn-success">Δημιουργία</button>
  </form>
          </div>
      </div>
        </div>
</div>
</body>
</html>