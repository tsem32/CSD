<%-- 
    Document   : index
    Created on : Mar 4, 2018, 5:46:53 PM
    Author     : laptop
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title></title>
    <link rel="stylesheet" href="build/aui-css/css/bootstrap.css">
    <script src="build/aui/aui.js"></script>
    <script src="../ajax.js"></script>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
</head>
<body>
    <h1>AlloyUI - Scheduler</h1>
    <div id="scheduler"></div>
    <script>
    YUI({ filter: 'raw' }).use('aui-scheduler', function(Y) {

        var items = [
            {
                content: 'Wake Early'
				
            },
            {
                content: 'Exercise'
            },
            {
                content: 'Review or (even better) Rewrite Your Goals',
                startDate: new Date(2018, 1, 4, 12),
                endDate: new Date(2018, 1, 4, 16)
            },
            {
                content: 'Event 1',
                startDate: new Date(2018, 1, 8),
                endDate: new Date(2018, 1, 8),
                allDay: true
            },
            {
                content: 'Event 2',
                startDate: new Date(2014, 6, 4),
                endDate: new Date(2014, 6, 20),
                allDay: true
            },
            {
                content: 'Event 3',
                startDate: new Date(2014, 6, 4),
                endDate: new Date(2014, 6, 20),
                allDay: true
            },
            {
                content: 'Other event',
                startDate: new Date(2014, 6, 20),
                endDate: new Date(2014, 6, 22),
                allDay: true
            },
            {
                content: 'Other event 2',
                startDate: new Date(2014, 6, 23),
                endDate: new Date(2014, 6, 28),
                allDay: true
				
            }
        ];

        var schedulerViews = [
            new Y.SchedulerWeekView(),
            new Y.SchedulerDayView(),
            new Y.SchedulerMonthView(),
            new Y.SchedulerAgendaView()
        ];
		 var eventRecorder = new Y.SchedulerEventRecorder({
    on: {
      save: function(event) {
        alert('Save Event:' + this.isNew() + ' --- ' + this.getContentNode().val());
        ajaxPost(this.getContentNode().val());
      },
      edit: function(event) {
        alert('Edit Event:' + this.isNew() + ' --- ' + this.getFormattedDate());
    
      },
      delete: function(event) {
        alert('Delete Event:' + this.isNew() + ' --- ' + this.getContentNode().val());
      },
      click:function(event){
          alert("click");
      }
    }
  });
  

        new Y.Scheduler({
            boundingBox: '#scheduler',
            items: items,
            views: schedulerViews,
            activeView: schedulerViews[2],
            eventRecorder: eventRecorder
            // firstDayOfWeek: 1,
            // activeView: weekView,
            // views: [dayView, weekView, monthView, agendaView]
        }).render();
 
    var editButton;
$(".scheduler-event-content").click(function() {
  alert( "Handler for .click() called."+ $(this).html());
});
    Y.Do.after(function() {

        var toolbarBtnGroup = Y.one('#scheduler .btn-toolbar-content .btn-group');
        toolbarBtnGroup.appendChild('<button id="show" type="button">Show</button>');

        editButton = new Y.Button({
            label: 'Show',
            srcNode: '#show',
        }).render();

        editButton.on('click', function(event) {
            alert(this.getContentNode().val());
            eventRecorder.hidePopover();
        });
    }, eventRecorder, 'showPopover');
    
    Y.Do.after(function() {
        
        // Make sure that the editButton is destroyed to avoid a memory leak.
        if (editButton) {
            editButton.destroy();
        }
    }, eventRecorder, 'hidePopover');

    });
   
    </script>
    <script>$('body').on('click', 'div.scheduler-event-content', function({
  alert( "Handler for .click() called."+ $(this).html());
}) {
    // do something
});
</script>
</body>
</html>