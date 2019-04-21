YUI.add("aui-timepicker",function(e,t){function r(){}var n=e.Lang;r.ATTRS={autocomplete:{setter:"_setAutocomplete",value:{},writeOnce:!0},dateSeparator:{value:", "},mask:{value:"%I:%M %p"},popoverCssClass:{value:e.getClassName("timepicker-popover")},values:{setter:"_setValues",value:["00:00","00:30","01:00","01:30","02:00","02:30","03:00","03:30","04:00","04:30","05:00","05:30","06:00","06:30","07:00","07:30","08:00","08:30","09:00","09:30","10:00","10:30","11:00","11:30","12:00","12:30","13:00","13:30","14:00","14:30","15:00","15:30","16:00","16:30","17:00","17:30","18:00","18:30","19:00","19:30","20:00","20:30","21:00","21:30","22:00","22:30","23:00","23:30"],validator:n.isArray}},e.mix(r.prototype,{autocomplete:null,clearSelection:function(){var e=this;e._handleSelection()},getAutoComplete:function(t){var n=this,r=n.autocomplete,i=n.get("autocomplete");return r&&r.destroy(),i.inputNode=t,r=new e.AutoComplete(i),r.render(n.getPopover().bodyNode).sendRequest(),n.autocomplete=r,r.after("select",n._afterAutocompleteSelect,n),r},selectDates:function(e){var t=this;t._handleSelection(e)},useInputNode:function(e){var t=this,n=t.get("activeInput"),r=t.getPopover();n!==e&&(t.set("activeInput",e),r.set("trigger",e),t.getAutoComplete(e)),t.alignTo(e),t.selectDates(t.getParsedDatesFromInputValue())},_afterAutocompleteSelect:function(e){var t=this,n=t.getParsedDatesFromInputValue(),r=t.getParsedDatesFromInputValue(e.result.raw);n.length&&r.length&&(n.pop(),n.push(r.pop())),t.selectDates(n),t.get("autoHide")&&t.hide()},_handleSelection:function(e){var t=this;e&&t.fire("selectionChange",{newSelection:e})},_setAutocomplete:function(t){var n=this,r=n.get("dateSeparator"),i=n.get("values");return e.merge({align:!1,allowTrailingDelimiter:!0,alwaysShowList:!0,minQueryLength:0,queryDelimiter:r,source:i,tabSelect:!1,width:"auto"},t)},_setValues:function(t){var n=this,r=[];return e.Array.each(t,function(t){r.push(e.Date.format(e.Date.parse("%H:%M",t),{format:n.get("mask")}))}),r}},!0),e.TimePickerBase=r,e.TimePicker=e.Base.create("timepicker",e.Base,[e.DatePickerDelegate,e.DatePickerPopover,e.TimePickerBase])},"3.0.1",{requires:["autocomplete","aui-datepicker-delegate","aui-datepicker-popover"],skinnable:!0});
