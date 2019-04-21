<%-- 
    Document   : new_login
    Created on : Mar 13, 2018, 7:00:53 PM
    Author     : laptop
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en" >

<head>
  <meta charset="UTF-8">
  <title>Είσοδος</title>
  
  
  <link rel='stylesheet prefetch' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css'>

      <link rel="stylesheet" href="css/style.css">

  
</head>

<body class="bg-primary">

  <div class="modal-dialog">
      
		<div class="modal-content">
			<div class="modal-heading">
                            <div class="alert alert-success">
                                <% session.invalidate();%>
   Έξοδος Επιτυχής!
</div>
				<h2 class="text-center">Είσοδος</h2>
			</div>
			<hr />
			<div class="modal-body">
				<form action="login.jsp" role="form" method="post">
					<div class="form-group">
						<div class="input-group">
							<span class="input-group-addon">
							<span class="glyphicon glyphicon-user"></span>
							</span>
							<input type="text" name="username" class="form-control" placeholder="Όνομα χρήστη" required />
						</div>
					</div>
					<div class="form-group">
						<div class="input-group">
							<span class="input-group-addon">
							<span class="glyphicon glyphicon-lock"></span>
							</span>
                                                    <input type="password" name="pass" class="form-control" placeholder="Κωδικός" required />

						</div>

					</div>

					<div class="form-group text-center">
						<button type="submit" class="btn btn-primary btn-lg">Είσοδος</button>
						
					</div>

				</form>
			</div>
		</div>
	</div>
  <script src='https://code.jquery.com/jquery-2.2.4.min.js'></script>
<script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js'></script>

  

</body>

</html>
