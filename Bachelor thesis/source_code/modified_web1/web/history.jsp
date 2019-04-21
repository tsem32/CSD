<%-- 
    Document   : new_scheduler
    Created on : Mar 13, 2018, 7:17:34 PM
    Author     : laptop
--%>

<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Ιστορικό</title>
    <link rel="stylesheet" href="Calendar/build/aui-css/css/bootstrap.css">
    <script src="Calendar/build/aui/aui.js"></script>
    <script src="Calendar/build/aui/aui-min.js"></script>
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  <script src="ajax.js"></script>
 
<style>
    .alert-info {
    
    background-color: #F8F8F8;
    border-color: #BCE8F1;
}
    
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
  

</style>
<script>historySearch('<%= request.getParameter("pid-h") %>');</script>
 <script>
      $(window).on('load',function(){        
        $('#myModal').modal('show');
    });
    $(document).ready (function(){
            //$("#success-alert").hide;
            $("#success-alert").css("display","none");
 });
 </script>
</head>
<body  class="bg-primary">
    <%  
    String pageName = "logout.jsp";  
    String pid_h = request.getParameter("pid-h");
    String home="Admin.jsp";
    session=request.getSession(false);
    if(session.getAttribute("username")==null)
    {
        response.sendRedirect("new_login.jsp");
    }else{
         if(session.getAttribute("isAdmin").equals(false)){
        home="new_scheduler.jsp";
    }
    }
   
%>
	<nav class="navbar navbar-default">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="<%=home %>"><%=session.getAttribute("name")%>  <%=session.getAttribute("lname")%></a>
    </div>
    <ul class="nav navbar-nav">
    </ul>
     <ul class="nav navbar-nav navbar-right">
    
     <form class="navbar-form navbar-left" action="Search" method="post" accept-charset="UTF-8">
        <input id='search_text' type="text" class="form-control" placeholder="Search" name="search">
        <input id='action' type="hidden" class="form-control" placeholder="Search" name="action" value="search"  >
        <button  id='search_btn' type="submit" class="btn btn-default glyphicon glyphicon-search" ></button>
    </form>
      
      <li><a href="#"onclick="redirectPage('<%=pageName%>')" ><span class="glyphicon glyphicon-log-in"></span> Έξοδος</a></li>
      
    </ul>
   
  </div>
</nav>


    <div id="scheduler"></div>
    <div id="ajax">

    </div>
     <div id="profile">
    </div>
</body>
   <script>
 
  function add_row(){
  var rows=$("#table tr").length;
    $("#table tr:last").after("<tr id='row"+(rows)+"'>"
        +"<td><div class='form-group'>"
       +"<input id='ser"+rows+"' type='text' class=\"form-control\"  name='ser"+rows+"' required>"
      +" </div>"
     +"</td>"
       +"<td><div class='form-group'>"
       +"<input id='date"+rows+"' type='text' class=\"form-control\"  name='date"+rows+"' required>"
      +" </div>"
     +"</td>"
      
       +"<td><div class='form-group'>"
       +"<input id='descript"+rows+"' type='text' class=\"form-control\"  name='descript"+rows+"' required>"
      +" </div>"
     +"</td>"
       +"<td><div class='form-group'>"
       +"<input id='medic"+rows+"' type='text' class=\"form-control\"  name='medic"+rows+"' required>"
      +" </div>"
     +"</td>"
  	
        
        
  +"</tr>");
 
 };
 function rem_row(){
 var rows=$("#table tr").length;
   if(rows>2){
    document.getElementById('table').deleteRow(rows-1);
      
        }
 
 };
 function getRows(){
     var rows=$("#table tr").length;
     document.getElementById('hid_rows').value=rows;
     document.getElementById('pid-h').value='<%= request.getParameter("pid-h") %>';
 }
 
 </script>
</html>