<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en" >

    <head>
        <meta charset="UTF-8">
        <title>Αίτημα Εγγραφής</title>


        <link rel='stylesheet prefetch' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css'>

        <link rel="stylesheet" href="css/style.css">


    </head>

    <body class="bg-primary">

        <div class="modal-dialog">

            <div class="modal-content">
                <div class="modal-heading">

                    <h2 class="text-center">Αίτημα Εγγραφής</h2>
                </div>
                <hr />
                <div class="modal-body">
                   <form class="form-block" action="Users" method="post" accept-charset="UTF-8">
                    <input type="hidden" name="action" value="register" required>
    <div class="form-group">
      <input id='user' type="text" class="form-control" placeholder="ΑΜΑ" pattern="[0-9]*" name="username" required>
    </div>
     <div class="form-group">
      <input type="text" class="form-control"  placeholder="Όνομα"  name="name" required>
    </div>
    <div class="form-group">
      <input type="text" class="form-control"  placeholder="Επίθετο"  name="lname" required>
    </div>
      <div class="form-group">
      <input type="email" class="form-control" placeholder="Email" name="email" required>
    </div>               
      
                  <br>
                  <br>
                       <div class="form-group text-center">
    <button id='regBtn' type="submit" class="btn-primary">Υποβολή</button>
                       </div>
  </form>
                </div>
            </div>
        </div>
        <script src='https://code.jquery.com/jquery-2.2.4.min.js'></script>
        <script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js'></script>



    </body>

</html>
