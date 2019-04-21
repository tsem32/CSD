<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html> 
<html lang="en">
<head>
     <%  
    String pageName = "logout.jsp";  
    String home="Admin.jsp";
    if(session.getAttribute("isAdmin").equals(false)){
        home="new_scheduler.jsp";
    }
%>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <meta http-equiv="refresh" content="3;URL='<%=home%>'">
    <link rel="stylesheet" href="Calendar/build/aui-css/css/bootstrap.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  <title>Ολοκληρώθηκε</title>
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

</style>
</head>
<body class="bg-primary">
    
    

	<nav class="navbar navbar-default">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="#"></a>
    </div>
    <ul class="nav navbar-nav">
      
    </ul>
     <ul class="nav navbar-nav navbar-right">
      
    </ul>
   
  </div>
</nav>
     
     <div class="row">
        <div class="col-lg-6 col-lg-offset-3 text-center">
              <div   id="admin-panel"> 
                   <div class="panel" style="border:1px solid #d8d8d8">
      <div class="panel-heading" style="background-color:#d8d8d8;color:white;"></div>
      <div class="panel-body">
          <div class="alert alert-success"><strong>Ολοκληρώθηκε!</strong> θα μεταφερθείτε στην αρχική σε 3 δευτερόλεπτα</div>
                  
          </div>
      </div>
                
              </div>
        </div>
</div>
       
</body>
</html>