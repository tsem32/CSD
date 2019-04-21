"use strict";




//event attributes
var user_evt_date;
var username, service, content, evid, action;

//event set function 
function setEvent(user, serv, cont, act) {
    username = user;
    service = serv;
    content = cont;
    action = act;
}
//event id and date set and helper functions. implemented seperately 

//sets (currently being proccessed) event id
function setEvid(id) {
    evid = id;
}
//returns (currently being proccessed)event id
function getEvid() {
    return evid;
}

//sets (currently being proccessed) event date
function setUserEvDate(value) {
    user_evt_date = value;
}
//returns (currently being proccessed) event date
function getUserEvDate() {
    return user_evt_date;
}

//used mainly to update event hour using the HourModal
function updateUserEVDate() {
    var end, start, start_min, end_min;      //start-end hour:minutes
    end = document.getElementById('endHour').value;
    end_min = document.getElementById('endMin').value;
    start = document.getElementById('startHour').value;
    start_min = document.getElementById('startMin').value;
    if (user_evt_date.includes("-")) {       //checks if event has end date
        var cur = user_evt_date.split(",");  //get hourModal data and hide 
        cur[2] = start + ":" + start_min + " - " + end + ":" + end_min;
        user_evt_date = "";
        user_evt_date = cur.join(",");
        $('#HourModal').modal('hide');
        if (action === 'save') { //if new event call PostEvent with save parame
            PostEvent(content, getUserEvDate(), username, 'save', service);
        } else if (action === 'edit') {//else call PostEvent with edit param
            ajaxPost(service, getUserEvDate(), getEvid(), 'edit');
        }
        return user_evt_date;

    } else {
        user_evt_date = user_evt_date + ", " + start + ":" + start_min + " - " + end + ":" + end_min; //else crate an end date 
        //and perform same actions with if code
        $('#HourModal').modal('hide');
        if (action === 'save') {
            PostEvent(content, getUserEvDate(), username, 'save', service);
        } else if (action === 'edit') {
            ajaxPost(service, getUserEvDate(), getEvid(), 'edit');
        }
        return  user_evt_date;
    }
}

//Updates an event when edited
function ajaxPost(service, date, user, action) {

    var xhr = new XMLHttpRequest();
    xhr.onload = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {

            window.location.reload();
        } else if (xhr.status !== 200) {
            alert('Request failed. Returned status of ' + xhr.status);
        }
    };
    xhr.open('POST', 'Events');
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded;charset=utf-8');
    xhr.send('cont=' + service + '&date=' + date + '&user=' + user + '&action=' + action);
}

//Updates History when completing an event
function CompleteEvent() {
    var xhr = new XMLHttpRequest();
    var hidpid = document.getElementById('hid-pid').value;
    var date = formatDate(document.getElementById('date').value);
    var service = document.getElementById('service').value;
    var desc = document.getElementById('desc').value;
    var medication = document.getElementById('medication').value;
    var hidevid = document.getElementById('hid-evid').value;
    xhr.onload = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {
            if (xhr.responseText === 'done') {
                $("#HistModal").modal();
                window.setTimeout(function () {
                    window.location.href = "new_scheduler.jsp";

                }, 3000);

            }

        } else if (xhr.status !== 200) {
            alert('Request failed. Returned status of ' + xhr.status);
        }
    };
    xhr.open('POST', 'Histories');
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded;charset=utf-8');
    xhr.send('hid-pid=' + hidpid + '&date=' + date + '&service=' + service + '&desc=' + desc + '&hid-evid=' + hidevid + '&medication=' + medication + '&action=complete');
}

//deletes and event
function DeleteEvent(eventID) {

    var xhr = new XMLHttpRequest();
    xhr.onload = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {

            window.location.reload();
        } else if (xhr.status !== 200) {
            alert('Request failed. Returned status of ' + xhr.status);
        }
    };
    xhr.open('POST', 'Events');
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded;charset=utf-8');
    xhr.send('&evid=' + eventID + '&action=delete');
}

//posts an event
function PostEvent(value, date, user, action, service) {

    var xhr = new XMLHttpRequest();
    xhr.onload = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {

            window.location.reload();
        } else if (xhr.status !== 200) {
            alert('Request failed. Returned status of ' + xhr.status);
        }
    };
    xhr.open('POST', 'Events');
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded;charset=utf-8');
    xhr.send('cont=' + value + '&date=' + date + '&user=' + user + '&action=' + action + '&service=' + service);
}


function getEvents(value) {
    var items;
    var xhr = new XMLHttpRequest();
    xhr.onload = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {
            items = xhr.responseText;
            alert(JSON.parse(JSON.stringify(items)));
            return items;

        } else if (xhr.status !== 200) {
            alert('Request failed. Returned status of ' + xhr.status);
        }
    };
    xhr.open('GET', 'Events?user=' + value);
    xhr.setRequestHeader('Content-type', 'application/json;charset=utf-8');
    xhr.send();

}

