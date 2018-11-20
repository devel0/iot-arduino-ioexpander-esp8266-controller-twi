F("\
var debug = false;\
\
\
var baseurl = '';\
if (debug) baseurl = 'http://10.10.3.11';\
\
async function myfn() {\
$.fn.maphilight.defaults = {\
fill: true,\
fillColor: 'EFFF00',\
fillOpacity: 0.0,\
stroke: true,\
strokeColor: 'FFBB00',\
strokeOpacity: 1,\
strokeWidth: 2,\
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
$('map').find('area').each(function (idx, val) {\
$(val).mouseout(function () {\
/*    console.log('mouse leave ' + this.alt);\
let imgdiv = $('#imgdiv')[0];\
let canvas = $('#port-' + this.alt);\
if (canvas[0] != null) imgdiv.removeChild(canvas[0]);*/\
});\
$(val).mouseenter(function () {\
console.log('mouse over ' + this.alt);\
if ($('#port-' + this.alt)[0] != null) return;\
\
let imgdiv = $('#imgdiv')[0];\
let coords = $.map(this.coords.split(','), (x) => parseInt(x));\
\
var canvas = document.createElement('canvas');\
$(canvas).click(function () {\
console.log('mouse leave');\
$(this).addClass('port-selected');\
});\
canvas.id = 'port-' + this.alt;\
let w = coords[2] - coords[0];\
let h = coords[3] - coords[1];\
canvas.width = w;\
canvas.height = h;\
canvas.style.width = w;\
canvas.style.height = h;\
canvas.style.position = 'absolute';\
canvas.style.left = coords[0] + w / 2;\
canvas.style.top = coords[1];\
canvas.classList.add('port');\
imgdiv.appendChild(canvas);\
\
/*\
var context = canvas.getContext('2d');\
context.rect(0, 0, 70, 70);\
context.fillStyle = 'rgba(255,255,0, .2)';\
context.fill();*/\
\
});\
});\
\
try {\
res = await $.ajax({\
url: baseurl + \"/api/scan\",\
type: 'GET'\
});\
$.each(res, function (idx, val) {\
let b = document.createElement('button');\
let t = document.createTextNode(val);\
$(b).addClass('list-group-item list-group-item-action');\
b.appendChild(t);\
$('#buslst')[0].appendChild(b);\
});\
} catch (e) {\
console.log(e);\
}\
\
}\
\
myfn();\
")
