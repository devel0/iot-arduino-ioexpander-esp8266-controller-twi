F("\
var debug = false;\
\
\
var baseurl = '';\
if (debug) baseurl = 'http://10.10.4.111';\
\
async function myfn() {\
$.fn.maphilight.defaults = {\
fill: true,\
fillColor: '000000',\
fillOpacity: 0.2,\
stroke: true,\
strokeColor: '00D7FF',\
strokeOpacity: 1,\
strokeWidth: 1,\
fade: true,\
alwaysOn: false,\
neverOn: false,\
groupBy: false,\
wrapClass: true,\
shadow: false,\
shadowX: 0,\
shadowY: 0,\
shadowRadius: 6,\
shadowColor: '000000',\
shadowOpacity: 0.8,\
shadowPosition: 'outside',\
shadowFrom: false\
};\
$('.map').maphilight();\
}\
\
myfn();\
")
