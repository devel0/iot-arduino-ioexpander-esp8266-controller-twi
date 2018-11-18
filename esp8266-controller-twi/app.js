//==============================================================================
//
//-------------------- PLEASE REVIEW FOLLOW VARIABLES ------------------
//

// automatic replaced to debug = false during compilation
// this is used to debug page index.htm locally
var debug = true;

//==============================================================================

var baseurl = '';
if (debug) baseurl = 'http://10.10.4.111';

async function myfn() {
    $.fn.maphilight.defaults = {
        fill: true,
        fillColor: 'EFFF00',
        fillOpacity: 0.0,
        stroke: true,
        strokeColor: 'FFBB00',
        strokeOpacity: 1,
        strokeWidth: 2,
        fade: true,
        alwaysOn: false,
        neverOn: false,
        groupBy: false,
        wrapClass: true,
        shadow: false,
        shadowX: 0,
        shadowY: 0,
        shadowRadius: 6,
        shadowColor: '000000',
        shadowOpacity: 0.8,
        shadowPosition: 'outside',
        shadowFrom: false
    };
    $('.map').maphilight();   
    $('map').find('area').each(function(idx,val) {
        $(val).mouseover(function() {
           console.log(this.alt); 
        });
    });
}

myfn();