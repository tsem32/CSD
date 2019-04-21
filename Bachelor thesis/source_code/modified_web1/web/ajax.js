/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


"use strict";
var current_view='personal';



function redirectPage(pageName, value) {
    window.location.href = pageName;

}

function show_users() {
    $('#scheduler').hide();
    $('#profile').hide();
    $('#ajax').empty();
    var xhr = new XMLHttpRequest();
    xhr.onload = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {
            document.getElementById('ajax').innerHTML = xhr.responseText;
        } else if (xhr.status !== 200) {
            alert('Request failed. Returned status of ' + xhr.status);
        }
    };
    xhr.open('GET', 'Users?username=all*' + '&action=show_all');
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded;charset=utf-8');
    xhr.send();
}



function ajaxSearch(value) {
    $('#scheduler').hide();
    $('#profile').hide();
    $('#ajax').empty();
    var xhr = new XMLHttpRequest();
    xhr.onload = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {
            document.getElementById('ajax').innerHTML = xhr.responseText;
        } else if (xhr.status !== 200) {
            alert('Request failed. Returned status of ' + xhr.status);
        }
    };
    xhr.open('GET', 'Patients?pid=' + value + '&action=search');
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded;charset=utf-8');
    xhr.send();
}


function historySearch(value) {
    $('#scheduler').hide();
    $('#profile').hide();
    $('#ajax').empty();
    var xhr = new XMLHttpRequest();
    xhr.onload = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {
            document.getElementById('ajax').innerHTML = xhr.responseText;
        } else if (xhr.status !== 200) {
            alert('Request failed. Returned status of ' + xhr.status);
        }
    };
    xhr.open('GET', 'Histories?pid-h=' + value);
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded;charset=utf-8');
    xhr.send();
}

function openSearch() {
    var nw = window.open('search.jsp', '__blank', 'height=400,width=900');
    nw.pass = document.getElementById("search_bar").value;

}

function show_patient(x) {
    var f = window.open('ShowPatient.jsp', 'new', 'height=400,width=900');
    f.pid = x.innerHTML;

}

function getPatient(value) {
    var xhr = new XMLHttpRequest();
    xhr.onload = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {
            document.getElementById('ajax').innerHTML = xhr.responseText;
        } else if (xhr.status !== 200) {
            alert('Request failed. Returned status of ' + xhr.status);
        }
    };
    xhr.open('GET', 'Patients?pid=' + value + '&action=get_patient');
    xhr.send();

}

function cancel() {
    $('#ajax').empty();
    $('#scheduler').show();
}

function test2() {

    var username = document.getElementById('user').value;

    if (username !== "") {
        var xmlhttp = new XMLHttpRequest();

        var url = "Exists?username=" + username + '&action=user';
        xmlhttp.onreadystatechange = function () {
            if (xmlhttp.readyState === 4 && xmlhttp.status === 200) {
                var response = xmlhttp.responseText;
                if (response === "found") {
                    $("#error").show();
                    document.getElementById('user').style.border = "2px solid #ff4954";
                    document.getElementById('regBtn').disabled = true;
                } else {
                    $("#error").hide();
                    document.getElementById('user').style.border = "none";
                    document.getElementById('regBtn').disabled = false;
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
}

function profile_view(username) {

    $('#scheduler').hide();
    $('#ajax').hide();
    $('#profile').empty();
    var xhr = new XMLHttpRequest();
    xhr.onload = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {
            $('#profile').append(xhr.responseText);
        } else if (xhr.status !== 200) {
            alert('Request failed. Returned status of ' + xhr.status);
        }
    };
    xhr.open('GET', 'Users?username=' + username + '&action=view');
    xhr.send();
}


//update User credentials and data
function userUpdate_form(username) {
    $('#scheduler').hide();
    $('#ajax').hide();
    $('#profile').empty();
    var xhr = new XMLHttpRequest();
    xhr.onload = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {
            var credentials = xhr.responseText.split("|");

            document.getElementById("name").value = credentials[0];
            document.getElementById("lname").value = credentials[1];
            document.getElementById("user").value = credentials[2];

        } else if (xhr.status !== 200) {
            alert('Request failed. Returned status of ' + xhr.status);
        }
    };
    xhr.open('GET', 'Users?username=' + username + '&action=update');
    xhr.send();

}


function view_all_users() {

    $('#scheduler').hide();
    $('#ajax').hide();
    $('#profile').empty();
    var xhr = new XMLHttpRequest();
    xhr.onload = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {
            $('#profile').append(xhr.responseText);
        } else if (xhr.status !== 200) {
            alert('Request failed. Returned status of ' + xhr.status);
        }
    };
    xhr.open('GET', 'Users?username=' + username);
    xhr.send();
}

function show_scheduler() {
    $('#ajax').empty();
    $('#scheduler').show();
}

//toggles visibility of delete user button 
function show_delete() {
    $("#del-pat").hide();
    $("#history-form").hide();
    $("#del_btn").click(function () {
        $("#del").toggle();
        $('#username').tooltip('hide');
        $('#username').attr('title', 'Όνομα Χρήστη');
    });


}
//toogles visibility of delete patient button 
function show_delete_pat() {
    $("#del").hide();
    $("#history-form").hide();
    $("#del-btn-pat").click(function () {

        $("#del-pat").toggle();
        $('#pid').tooltip('hide');
        $('#pid').attr('title', 'ID Ασθενούς');

    });
}
//toogles visibility of show patient's history butotn 
function show_history_form() {

    $("#del").hide();
    $("#del-pat").hide();
    $("#history-btn-show").click(function () {

        $("#history-form").toggle();
        $('#pid').tooltip('hide');
        $('#pid').attr('title', 'ID Ασθενούς');

    });
}

function test3() {
    var username = document.getElementById('username').value;

    if (username !== "") {
        var xmlhttp = new XMLHttpRequest();

        var url = "Exists?username=" + username + '&action=user';
        xmlhttp.onreadystatechange = function () {
            if (xmlhttp.readyState === 4 && xmlhttp.status === 200) {
                var response = xmlhttp.responseText;
                if (response !== "found") {

                    document.getElementById('username').style.border = "2px solid #ff4954";
                    $('#username').attr('title', 'Μη έγκυρο username');
                    $('#username').tooltip('show');
                    document.getElementById('del-btn').disabled = true;
                } else {

                    document.getElementById('username').style.border = "2px solid black";
                    document.getElementById('del-btn').disabled = false;
                    $('#username').attr('title', '');
                    $('#username').tooltip('destroy');
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
}

function test4() {
    var username = document.getElementById('pid').value;
    if (username !== "") {
        var xmlhttp = new XMLHttpRequest();

        var url = "Exists?pid=" + username + '&action="patient"';
        xmlhttp.onreadystatechange = function () {
            if (xmlhttp.readyState === 4 && xmlhttp.status === 200) {
                var response = xmlhttp.responseText;
                if (response !== "found") {

                    document.getElementById('pid').style.border = "2px solid #ff4954";
                    $('#pid').attr('title', 'Μη έγκυρο ID');
                    $('#pid').tooltip('show');
                    document.getElementById('del-btn_pat').disabled = true;
                } else {
                    document.getElementById('pid').style.border = "2px solid black";
                    document.getElementById('del-btn_pat').disabled = false;
                    $('#pid').attr('title', '');
                    $('#pid').tooltip('destroy');
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
}
//used search of history patient 
function history_pid_validate() {
    var username = document.getElementById('pid-h').value;
    if (username !== "") {
        var xmlhttp = new XMLHttpRequest();

        var url = "Exists?pid=" + username + '&action="patient"';
        xmlhttp.onreadystatechange = function () {
            if (xmlhttp.readyState === 4 && xmlhttp.status === 200) {
                var response = xmlhttp.responseText;
                if (response !== "found") {

                    document.getElementById('pid-h').style.border = "2px solid #ff4954";
                    $('#pid-h').attr('title', 'Μη έγκυρο ID');
                    $('#pid-h').tooltip('show');
                    document.getElementById('history-btn-submit').disabled = true;
                } else {
                    document.getElementById('pid-h').style.border = "2px solid black";
                    document.getElementById('history-btn-submit').disabled = false;
                    $('#pid-h').attr('title', '');
                    $('#pid-h').tooltip('destroy');
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
}
//creates a form used to register a new patients medical history
function history_reg_show() {
    $('#scheduler').hide();
    $('#profile').hide();
    $('#ajax').empty();
    document.getElementById('ajax').innerHTML =
            '<div class="panel" style="border:1px solid #222222">'
            + '<div class="panel-heading" style=background-color:#F8F8F8;color:black;"><b>Δημιουργία Ιστορικού</b></div>'
            + '<div class="panel-body">  '
            + '<form class="form-block" action="Histories" method="post" accept-charset="UTF-8">'
            + '<input type="hidden"  value="post" name="action">'
            + '<input type="hidden" id="hid_rows" value=0 name="hid_rows">'
            + '<input type="hidden" id="pid-h" value ="" name=\"pid-h\" >'
            + "<div class=\"table-responsive\">"
            + "<table id='table' class=\"table table-striped\">"
            + "<thead  style=\"background-color:#F8F8F8\">\n"
            + "<tr id='row0' style=\"color:black\">\n"
            + "<th scope=\"col\">Υπηρεσία</th>\n"
            + "<th scope=\"col\">Ημερομηνία</th>\n"
            + "<th scope=\"col\">Περιγραφή</th>\n"
            + "<th scope=\"col\">Αγωγή</th>\n"
            + "</tr>\n"
            + "</thead> <tbody>"
            + "<tr id='row1'>"
            + "<td><div class='form-group'>"
            + "<input id='ser1' type='text' class=\"form-control\"  name=\"ser1\" required>"
            + " </div></td>"
            + "<td><div class='form-group'>"
            + "<input id='date1' type='date' class=\"form-control\"    name=\"date1\" required>"
            + " </div></td>"
            + "<td><div class='form-group'>"
            + "<input id='descript1' type='text' class=\"form-control\"    name=\"descript1\" required>"
            + " </div></td>"
            + "<td><div class='form-group'>"
            + "<input id='medic1' type='text' class=\"form-control\"    name=\"medic1\" required>"
            + " </div></td>"
            + "</tr></tbody></table></div>"
            + '<div class="row"><div class="col-lg-6 col-lg-offset-3 text-center">'
            + '<button id="regBtn" onclick="getRows()" type="submit" class="btn btn-success">Καταχώρηση</button>'
            + '</div></div><br>'
            + '</form>'
            + '<div class="row"><div class="col-lg-6 col-lg-offset-3 text-center">'
            + '<button onclick=\'location.href="Admin.jsp"\' id="cancel-btn" type="submit" class="btn btn-success">Άκυρο</button>'
            + '</div></div>'
            + '<button id="add-btn" type="submit" class="btn btn-success" style="width:40px; height:40px" onclick="add_row()">+</button>'
            + '&nbsp &nbsp &nbsp&nbsp &nbsp &nbsp<button id="add-btn" type="submit" class="btn btn-success" style="width:40px; height:40px" onclick="rem_row()">-</button>'
            + '</div></div>'
            + '</div>';
}



//used when updating credentials to check new password matches the confirmation
function check_password() {
    var pass = document.getElementById('new_pass').value;
    var confirm = document.getElementById('confirm_pass').value;

    if (pass !== confirm) {
        document.getElementById('confirm_pass').style.border = "2px solid #ff4954";
        document.getElementById('new_pass').style.border = "2px solid #ff4954";
        $('#confirm_pass').attr('title', 'Η κωδικοί δεν ταιριάζουν');
        $('#confirm_pass').tooltip('show');
        document.getElementById('upd-btn').disabled = true;
    } else {
        document.getElementById('confirm_pass').style.border = "2px solid #ccffcc";
        document.getElementById('new_pass').style.border = "2px solid #ccffcc";
        document.getElementById('upd-btn').disabled = false;
        $('#confirm_pass').attr('title', '');
        $('#confirm_pass').tooltip('destroy');
    }
}
//used when deleting a user to verify it is a valid username
function check_user() {
    var initial = document.getElementById('init').value;
    var username = document.getElementById('user').value;
    if (username !== "" && username !== initial) {
        var xmlhttp = new XMLHttpRequest();

        var url = "Exists?username=" + username + '&action=user';
        xmlhttp.onreadystatechange = function () {
            if (xmlhttp.readyState === 4 && xmlhttp.status === 200) {
                var response = xmlhttp.responseText;
                if (response === "found") {
                    $("#error").show();
                    document.getElementById('user').style.border = "2px solid #ff4954";
                    document.getElementById('upd-btn').disabled = true;
                } else {
                    $("#error").hide();
                    document.getElementById('user').style.border = "2px solid #ccffcc";
                    document.getElementById('upd-btn').disabled = false;
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
}


//copy patients id when hitting copy button in patient overview modal
function cp() {
    var td_elem = document.getElementById('td-pid');
    td_elem.select();
    document.execCommand("Copy");
    $("#success-alert").fadeTo(1000, 300).slideUp(300, function () {
        $("#success-alert").slideUp(300);
    });


}

$('#HistModal').on('hide', function () {
    window.location.reload();
});

function formatDate(date) {
    var d = new Date(date),
            month = '' + (d.getMonth() + 1),
            day = '' + d.getDate(),
            year = d.getFullYear();

    if (month.length < 2)
        month = '0' + month;
    if (day.length < 2)
        day = '0' + day;

    return [year, month, day].join('-');
}

function switch_calendars(){
      $('#scheduler').empty();
    if(current_view==='personal'){
        current_view='full';
    }else{
        current_view='personal';
    }
    
}