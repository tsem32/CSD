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
        <title>Ημερολόγιο</title>
        <link rel="stylesheet" href="Calendar/build/aui-css/css/bootstrap.css">
        <script src="Calendar/build/aui/aui.js"></script>
        <script src="Calendar/build/aui/aui-min.js"></script>
        <script src="Calendar/build/aui-scheduler-touch/aui-scheduler-touch.js"></script> 
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
        <script src="ajax.js"></script>
        <script src="events.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/bootbox.js/4.4.0/bootbox.min.js"></script>
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
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
            #ul {

                margin-left:-40px;
                list-style-type:none;
            }

            .input-color {
                position: relative;
            }
            .input-color input {
                padding-left: 20px;
                border-style: none;
            }
            .input-color .color-box {

                width: 10px;
                height: 10px;
                display: inline-block;
                background-color: #ccc;
                position: absolute;
                left: 5px;
                top: 5px;
            }

        </style>
        <style type="text/css">

            .modal-confirm {		
                color: #434e65;
                width: 525px;
            }
            .modal-confirm .modal-content {
                padding: 20px;
                font-size: 16px;
                border-radius: 5px;
                border: none;
            }
            .modal-confirm .modal-header {
                background: #47c9a2;
                border-bottom: none;   
                position: relative;
                text-align: center;
                margin: -20px -20px 0;
                border-radius: 5px 5px 0 0;
                padding: 35px;
            }
            .modal-confirm h4 {
                text-align: center;
                font-size: 36px;
                margin: 10px 0;
            }
            .modal-confirm .form-control, .modal-confirm .btn {
                min-height: 40px;
                border-radius: 3px; 
            }
            .modal-confirm .close {
                position: absolute;
                top: 15px;
                right: 15px;
                color: #fff;
                text-shadow: none;
                opacity: 0.5;
            }
            .modal-confirm .close:hover {
                opacity: 0.8;
            }
            .modal-confirm .icon-box {
                color: #fff;		
                width: 95px;
                height: 95px;
                display: inline-block;
                border-radius: 50%;
                z-index: 9;
                border: 5px solid #fff;
                padding: 15px;
                text-align: center;
            }
            .modal-confirm .icon-box i {
                font-size: 64px;
                margin: -4px 0 0 -4px;
            }
            .modal-confirm.modal-dialog {
                margin-top: 80px;
            }
            .modal-confirm .btn {
                color: #fff;
                border-radius: 4px;
                background: #eeb711;
                text-decoration: none;
                transition: all 0.4s;
                line-height: normal;
                border-radius: 30px;
                margin-top: 10px;
                padding: 6px 20px;
                border: none;
            }
            .modal-confirm .btn:hover, .modal-confirm .btn:focus {
                background: #eda645;
                outline: none;
            }
            .modal-confirm .btn span {
                margin: 1px 3px 0;
                float: left;
            }
            .modal-confirm .btn i {
                margin-left: 1px;
                font-size: 20px;
                float: right;
            }
            .trigger-btn {
                display: inline-block;
                margin: 100px auto;
            }
        </style>


    </head>
</head>
<body class="bg-primary" style="color:black">
    <%
        String pageName = "logout.jsp";
        session = request.getSession(false);
        if (session.getAttribute("username") == null) {
            response.sendRedirect("new_login.jsp");
        }
    %>
    <script>$(document).ready(function(){  $('#calendar_btn span').html('Πλήρες');});</script>
    <nav class="navbar navbar-default">
        <div class="container-fluid">
            <div class="navbar-header">
                <a class="navbar-brand" href="#"><%=session.getAttribute("name")%>  <%=session.getAttribute("lname")%></a>
            </div>
            <ul class="nav navbar-nav">

                <li class="dropdown"><a class="dropdown-toggle" data-toggle="dropdown" href="#">Προφίλ <span class="caret"></span></a>
                    <ul class="dropdown-menu">
                        <li><a href="#" onclick="location.href = 'profile.jsp';" >Προβολή</a></li>
                        <li><a href="UpdateCredentials.jsp" >Αλλαγή Στοιχείων</a></li>
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


   
        <ul id="ul">
            <li>
                <div class="input-color">
                    <input class="bg-primary" type="text" value="Παλαιό" readonly/>
                    <div class="color-box" style="background-color: #D45650;"></div>
                </div>
            </li>
            <li>
                <div class="input-color">
                    <input class="bg-primary" type="text" value="Σημερινό" readonly />
                    <div class="color-box" style="background-color: #EFAD4F;"></div>
                </div>
            </li>
            <li>
                <div class="input-color">
                    <input class="bg-primary" type="text" value="Μελλοντικό" readonly />
                    <div class="color-box" style="background-color:#5BB85F;"></div>
                </div>
            </li>
            <li>
                <div class="input-color">
                    <input class="bg-primary" type="text" value="Αλλου Νοσηλευτή" readonly />
                    <div class="color-box" style="background-color: #7a5c52;"></div>
                </div>
            </li>
            <li>
                <br>
                <div class="form-group">
                    <label for='calendar_btn'style='color:white'>Αλλαγή σε:</label><br>
                    <button type="button" class="btn btn-default"  style='width:130px'id='calendar_btn' value='personal'>
                       
                        <span></span>
                         <i class="fa fa-arrow-right" aria-hidden="true"></i>
                    </button>


                </div>
                <br><br>
               

            </li>

        </ul>

 <div  id="scheduler"></div>
    
    <div id="ajax">


    </div>
    <div id="profile">


    </div>
    <div class="container">


        <!-- Modal -->
        <div class="modal fade" id="myModal" role="dialog">
            <div class="modal-dialog modal-sm">
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Πληροφορίες</h4>
                    </div>
                    <div class="modal-body">
                        <form class="form-block"  accept-charset="UTF-8" id='complete-form'>
                            <input type="hidden" name="action" value="complete" required>
                            <div class="form-group">
                                <input id='service' type="text" class="form-control" placeholder="Λογος Επισκεψης"  name="service" required>
                            </div>
                            <div class="form-group">
                                <input id='date' type="text" class="form-control"  placeholder=""  name="date" required>
                            </div>
                            <div class="form-group">
                                <textarea id='medication' type="text" class="form-control"  placeholder="Αγωγή"  name="medication" maxlength="500"  rows="6" cols="50" style="resize: none" required></textarea>
                            </div>
                            <div class="form-group">
                                <textarea  id='desc' type="text" class="form-control" placeholder="Περιγραφή" name="desc" maxlength="500"  rows="6" cols="50" style="resize: none"required></textarea>
                                <input  id='hid-pid' type="hidden" class="form-control" name="hid-pid" required>
                                <input id="hid-evid" type="hidden" class="form-control" name="hid-evid" required>
                                <br>
                                <br>
                                <button id='subBtn' onclick='CompleteEvent()' type='button' class="btn btn-success " >Ολοκλήρωση</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
                        <button type="button" class="btn btn-default" onclick='show_more()'>Καρτέλα</button>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <a href="#HourModal" class="trigger-btn" data-toggle="modal">Click to Open Success Modal</a>
    <div id="HistModal" class="modal fade">
        <div class="modal-dialog modal-confirm">
            <div class="modal-content">
                <div class="modal-header">
                    <div class="icon-box">
                        <i class="material-icons">&#xE876;</i>
                    </div>
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                </div>
                <div class="modal-body text-center">
                    <h4>Ολοκληρώθηκε!</h4>	
                    <p>Το ιστορικό ανανεώθηκε επιτυχώς.</p>
                </div>
            </div>
        </div>
    </div>     
    <div id="HourModal" class="modal fade">
        <div class="modal-dialog modal-sm">
            <div class="modal-content">
                <div class="modal-header">
                    <h2>Ωρα</h2>

                </div>
                <div class="modal-body text-center">
                    <h3 style="text-align:left;">Αρχή</h3>
                    <div class="form-group row">
                        <div class="col-xs-4">

                            <select class="form-control" type="text" name="start-h" id="startHour">
                                <option value="1">1</option>   <option value="2">2</option>
                                <option value="3">3</option>  <option value="4">4</option>
                                <option value="5">5</option>     <option value="6">6</option>
                                <option value="7">7</option>    <option value="8">8</option>
                                <option value="9">9</option>   <option value="10">10</option>
                                <option value="11">11</option>  <option value="12" selected="selected">12</option> 
                                <option value="13">13</option>    <option value="14">14</option>
                                <option value="15">15</option>    <option value="16">16</option>
                                <option value="17">17</option>       <option value="18">18</option>
                                <option value="19">19</option>  <option value="20">20</option>
                                <option value="21">21</option>     <option value="21">22</option>
                                <option value="23">23</option>    
                            </select>
                        </div>
                        <div class="col-xs-4">
                            <select class="form-control" type="text" name="start-m" id="startMin">
                                <option value="00" selected="selected">00</option>  
                                <option value="05">05</option> 
                                <option value="10">10</option> 
                                <option value="15">15</option> 
                                <option value="20">20</option> 
                                <option value="25">25</option> 
                                <option value="30">30</option> 
                                <option value="35">35</option> 
                                <option value="40">40</option> 
                                <option value="45">45</option> 
                                <option value="50">50</option> 
                                <option value="55">55</option> 
                            </select>
                        </div>

                    </div>

                    <h3 style="text-align:left;">Τέλος</h3>
                    <div class="form-group row">
                        <div class="col-xs-4">
                            <select class="form-control" type="text" name="end-h" id="endHour">
                                <option value="1">1</option>   <option value="2">2</option>
                                <option value="3">3</option>  <option value="4">4</option>
                                <option value="5">5</option>     <option value="6">6</option>
                                <option value="7">7</option>    <option value="8">8</option>
                                <option value="9">9</option>   <option value="10">10</option>
                                <option value="11">11</option>  <option value="12">12</option> 
                                <option value="13" selected="selected">13</option>    <option value="14">14</option>
                                <option value="15">15</option>    <option value="16">16</option>
                                <option value="17">17</option>       <option value="18">18</option>
                                <option value="19">19</option>  <option value="20">20</option>
                                <option value="21">21</option>     <option value="21">22</option>
                                <option value="23">23</option>    
                            </select>
                        </div>
                        <div class="col-xs-4">
                            <select class="form-control" type="text" name="end-m" id="endMin">
                                <option value="00" selected="selected">00</option>  
                                <option value="05">05</option> 
                                <option value="10">10</option> 
                                <option value="15">15</option> 
                                <option value="20">20</option> 
                                <option value="25">25</option> 
                                <option value="30">30</option> 
                                <option value="35">35</option> 
                                <option value="40">40</option> 
                                <option value="45">45</option> 
                                <option value="50">50</option> 
                                <option value="55">55</option> 
                            </select>
                        </div>

                    </div>

                    <input type="button" onclick="updateUserEVDate()" class="btn btn-primary btm-sm" value="OK">


                </div>
            </div>
        </div>
    </div>   
    <script>
        function load_calendar(view){
        YUI({filter: 'raw'}).use('aui-scheduler-touch', function (Y) {

            var items = [];

            xhr = new XMLHttpRequest();
            xhr.onload = function () {
                if (xhr.readyState === 4 && xhr.status === 200) {
                    var item = xhr.responseText.split("|");

                    for (var i = 0; i < item.length - 8; i += 9) {

                        var event = {content: item[i],
                            startDate: new Date(item[i + 1]),
                            endDate: new Date(item[i + 2]),
                            color: item[i + 3],
                            allDay: item[i + 4],
                            borderColor: item[i + 3],
                            borderWidth: '1px',
                            colorBrightnessFactor: 1.7,
                            disabled: item[i + 5] === 'true',
                            user: item[i + 6],
                            evID: item[i + 7],
                            service: item[i + 8],
                            title: " ",
                            serDate: item[i + 2]
                        };
                         
                        items.push(event);
                    }

                    var schedulerViews = [
                        new Y.SchedulerWeekView({isoTime: true}, {touch: true}),
                        new Y.SchedulerDayView({isoTime: true}),
                        new Y.SchedulerMonthView({isoTime: true})
                    ];
                    var eventRecorder = new Y.SchedulerEventRecorder({
                        on: {
                            save: function (event) {
                                var service = $("#usr").val();
                                $("#HourModal").modal();
                                setUserEvDate(this.getFormattedDate());
                                setEvent('<%= session.getAttribute("username")%>', service, this.getContentNode().val(), 'save');
                            },
                            edit: function (event) {
                                var val = $("#evid").val();
                                var service = $("#usr").val();
                                var index = -1;

                                var filteredObj = items.find(function (item, i) {

                                    if (item.evID === val) {
                                        index = i;
                                        return item;
                                    }
                                });

                                if (filteredObj.disabled && filteredObj.user !== '<%= session.getAttribute("username")%>') {

                                    bootbox.alert("Το συγκεκριμένο στοιχείο ανήκει σε άλλο χρήστη!", function () {
                                        location.reload();
                                    });
                                } else if (filteredObj !== undefined) {
                                    setUserEvDate(this.getFormattedDate());
                                    setEvent('<%= session.getAttribute("username")%>', service, this.getContentNode().val(), 'edit');
                                    setEvid(filteredObj.evID);
                                    $("#HourModal").modal();
                                    // ajaxPost(service, this.getFormattedDate(), filteredObj.evID, 'edit');
                                }


                            },

                            delete: function (event) {
                                var val = $("#evid").val();

                                var index = -1;

                                var filteredObj = items.find(function (item, i) {

                                    if (item.evID === val) {

                                        index = i;
                                        return item;
                                    }
                                });

                                if (filteredObj.disabled) {

                                    bootbox.alert("Το συγκεκριμένο στοιχείο ανήκει σε άλλο χρήστη!", function () {
                                        location.reload();
                                    });
                                } else if (filteredObj !== undefined) {
                                    DeleteEvent(val);
                                    //ajaxPost(this.getContentNode().val(), this.getFormattedDate(), '<%= session.getAttribute("username")%>', 'delete');
                                }
                            }
                        }
                    });
                    new Y.Scheduler({
                        boundingBox: '#scheduler',
                        items: items,
                        views: schedulerViews,
                        activeView: schedulerViews[2],
                        eventRecorder: eventRecorder,
                        touch: true
                    }).render();

                    Y.Do.before(function () {

                    }, eventRecorder, 'showPopover');

                    Y.Do.after(function () {

                        var toolbarBtnGroup = Y.one(' .popover-title');
                        var btngroup = Y.one('.btn-toolbar-content .btn-group');
                        btngroup.appendChild("<input type='button' id='more-btn' data-toggle=\"modal\" data-target=\"#myModal\" class=\"btn btn-default btn-default-content yui3-widget yui3-btn yui3-btn-content yui3-btn-focused\" value='Info'>");
                        toolbarBtnGroup.appendChild('<br><div class="form-group"> <input type="text" class="form-control" id="usr" value="Λόγος Επίσκεψης">'
                                + '</div>' +
                                '<input class="form-group" id="evid" type="hidden"><input class="form-group" id="pid" type="hidden">'
                                );

                        $('body').on('click', 'div.scheduler-event ', function () {
                            var pid = $(this).find(".scheduler-event-content").html();
                            var pid_spl = pid.split("-");
                            var val;
                            if (pid !== 'Patient ID') {

                                var disable_input = document.querySelectorAll("input[value='" + pid + "']");
                                disable_input[0].readOnly = true;
                            }
                            if (pid_spl.length === 3) {
                                document.getElementById("pid").value = pid_spl[1];
                                document.getElementById("evid").value = pid_spl[2];
                                document.getElementById('more-btn').disabled = false;
                                val = pid_spl[2];
                            } else {
                                document.getElementById("evid").value = pid_spl[1];
                                val = pid_spl[1];
                                document.getElementById('more-btn').disabled = true;
                            }

                            var index = -1;

                            var filteredObj = items.find(function (item, i) {
                                if (item.evID === val) {
                                    index = i;

                                    return item;
                                }
                            });
                            if (filteredObj.user !== '<%= session.getAttribute("username")%>') {
                                $('#subBtn').prop('disabled', true);
                                $('#service').prop('readonly', true);
                                $('#desc').prop('readonly', true);
                                $('#date').prop('readonly', true);
                                $('#medication').prop('readonly', true);
                            } else {
                                $('#subBtn').prop('disabled', false);
                                $('#service').prop('readonly', false);
                                $('#desc').prop('readonly', false);
                                $('#date').prop('readonly', false);
                                $('#medication').prop('readonly', false);
                            }

                            document.getElementById("usr").value = filteredObj.service;
                            document.getElementById("service").value = filteredObj.service;
                            document.getElementById("date").value = filteredObj.serDate;
                            document.getElementById("hid-pid").value = $("#pid").val();
                            document.getElementById("hid-evid").value = $("#evid").val();

                        });
                    }, eventRecorder, 'showPopover');



                } else if (xhr.status !== 200) {
                    alert('Request failed. Returned status of ' + xhr.status);
                }
            };
            var value = '<%=session.getAttribute("username")%>';
            
            xhr.open('GET', 'Events?user=' + value+'&view='+view);
            xhr.setRequestHeader('Content-type', 'text/plain;charset=utf-8');
            xhr.send();

        });
        }
       
         $(document).ready(load_calendar('personal'));
        
       
      
    </script>
    <script>
        function show_more() {
            var pid = document.getElementById("pid").value;

            var xmlhttp = new XMLHttpRequest();
            var url = "Exists?pid=" + pid + '&action=patient';

            xmlhttp.onreadystatechange = function () {
                if (xmlhttp.readyState === 4 && xmlhttp.status === 200) {
                    var response = xmlhttp.responseText;
                    if (response === "found") {
                        document.getElementById('hid-input').value = pid;
                        document.getElementById('history-form').submit();


                    } else {
                        bootbox.alert("Δεν υπάρχουνε διαθέσιμες πληροφορίες");
                    }
                }
            };
            try {
                xmlhttp.open("GET", url, true);
                xmlhttp.send();
            } catch (e) {
                alert("unable to connect to server");
            }
        }
        $('#calendar_btn').click(function(){
         $('#scheduler').empty();
         
         var view=$('#calendar_btn').val();
          
         if(view==='personal'){
             view='full';
             $('#calendar_btn span').html('Προσωπικό');
         
           
         }else{
             view='personal';
             $('#calendar_btn span').html('Πλήρες');
             
         }
         $('#calendar_btn').val(view);
        
         load_calendar(view);
         
});

    </script>
    <form id="history-form" action="history.jsp" method="get">
        <input id="hid-input" type="hidden" value="" name="pid-h"> 
    </form>
</body>
</html>