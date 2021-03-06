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
    <title>Προσθήκη Καρτέλας</title>
    <link rel="stylesheet" href="Calendar/build/aui-css/css/bootstrap.css">
    <script src="Calendar/build/aui/aui.js"></script>
    <script src="Calendar/build/aui/aui-min.js"></script>
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
   <script type="text/javascript" src="//cdn.jsdelivr.net/jquery/1/jquery.min.js"></script>
<script type="text/javascript" src="//cdn.jsdelivr.net/momentjs/latest/moment.min.js"></script>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  <script src="ajax.js"></script>
 
<!-- Include Date Range Picker -->
<script type="text/javascript" src="//cdn.jsdelivr.net/bootstrap.daterangepicker/2/daterangepicker.js"></script>
<link rel="stylesheet" type="text/css" href="//cdn.jsdelivr.net/bootstrap.daterangepicker/2/daterangepicker.css" />
  <script src="ajax.js"></script>
  
<style>
  * {box-sizing: border-box;}

            body {
                margin: 0;
                font-family: Arial, Helvetica, sans-serif;
            }
            
          
            .daterangepicker{
                color:black;
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
         <div class="panel-heading" style="background-color:#F8F8F8;color:black;"><b>Δημιουργία Καρτέλας Ασθενούς</b></div>
      <div class="panel-body">
    
          <form class="form-block" action="Patients" method="post" accept-charset="UTF-8">
            <input  type="hidden" name="action" value="register_patient">
    <div class="form-group">
      <input id='user' type="text" class="form-control" placeholder="Ονοματεπώνυμο "  name="fullname"  required>
    </div>
            <div class="form-group">
      <input id='user' type="text" class="form-control" placeholder="Ον. Λατινικούς χαρακτήρες "  name="FullNameEn" pattern="[^0-9]+" required>
    </div>
    <div class="form-group">
      <input id='fathersName' type="text" class="form-control" placeholder="Πατρώνυμο"  name="fathersName"  required>
    </div>
     <div class="form-group">
      <input id='mothersName' type="text" class="form-control" placeholder="Μητρώνυμο"  name="mothersName"  required>
    </div>
             <div class="form-group">
      <select class="form-control" name="gender">
        <option value="Άντρας">Άντρας</option>
        <option value="Γυναίκα">Γυναίκα</option>
      </select>
              </div>
            
            <div class="form-group">
      <select class="form-control" name="marState">
        <option value="Έγγαμος">'Εγγαμος</option>
        <option value="Άγαμος">'Αγαμος</option>
      </select>
              </div>
            <div class="form-group">
              <select class="form-control" name="Insurance">
        <option value="ΙΚΑ">ΙΚΑ</option>
        <option value="ΟΓΑ">ΟΓΑ</option>
        <option value="ΟΑΕΕ">OAEE</option>
      </select>
              </div>
      <div class="form-group"> 
      <input type="text" class="form-control" placeholder="ΑΜΑ "  name="insId"  required>
    </div>
      <div class="form-group"> 
       <input type="text" class="form-control" placeholder="ΑΜKΑ "  name="amka"  required>
    </div>
      <div class="form-group"> 
       <input type="text" class="form-control" placeholder="Επάγγελμα "  name="job"  required>
    </div>
     <div class="form-group"> 
         
      <input type="text" class="form-control" placeholder="Διεύθυνση "  name="address"  required>
    </div>
      <div class="form-group">
      <input  type="text" class="form-control" placeholder="Τηλέφωνο "  name="phone"  required>
    </div>
     <div class="form-group">
      <input  type="text" class="form-control" placeholder="Τηλέφωνο Συγγενούς "  name="relPhone"  required>
    </div>
    
    <div class="form-group">
     <textarea placeholder="Σχολια..." name="details" style="overflow:auto;resize:none;color:black" rows="5" cols="60" ></textarea>
    </div>
   <div class="form-group">
     <input placeholder="Ημ. Γέννησης" name="bday" s type="date" clas="form-control" style="color:black;width:230px;font-size: 2rem" size></textarea>
    </div>
   
      
                  <br>
                  <br>
    <button id='regBtn' type="submit" class="btn btn-success">Καταχώρηση</button>
  </form>
          
        
          </div>
      </div>
        </div>
</div>
</body>
</html>