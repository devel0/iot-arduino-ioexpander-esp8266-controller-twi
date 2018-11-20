F("\
var debug = false;\
\
\
var baseurl = '';\
if (debug) baseurl = 'http://10.10.3.11';\
\
async function myfn() {\
\
$('map').find('area').each(function (idx, val) {\
$(val).mouseenter(function () {\
console.log('mouse over ' + this.alt);\
let je = $('#port-' + this.alt);\
if (je[0] != null) return;\
\
let imgdiv = $('#imgdiv')[0];\
let coords = $.map(this.coords.split(','), (x) => parseInt(x));\
\
var canvas = document.createElement('canvas');\
$(canvas).click(function () {\
console.log('mouse leave');\
let jel = $(this);\
let issel = jel.hasClass('port-selected');\
jel.removeClass('port-selected');\
\
if (!issel) {\
jel.addClass('port-selected');\
jel.removeClass('port');\
} else {\
jel.addClass('port');\
jel.removeClass('port-selected');\
}\
\
if ($('.port-selected').length > 0)\
$('.port-actions').removeClass('collapse');\
else\
$('.port-actions').addClass('collapse');\
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
});\
});\
\
{\
let tb = $('#ports-tbody')[0];\
if (tb.children.length == 0) {\
let ports = [\
\"D2\", \"D3\", \"D4\", \"D5\", \"D6\", \"D7\", \"D8\", \"D9\", \"D10\", \"D11\", \"D12\", \"D13\",\
\"A0\", \"A1\", \"A2\", \"A3\"\
];\
$.each(ports, function (idx, val) {\
let tr = document.createElement(\"tr\"); {\
let td = document.createElement(\"td\");\
td.innerHTML = '<b>' + val +'</b>';\
tr.appendChild(td);\
} {\
let td = document.createElement(\"td\");\
let sp = document.createElement(\"span\");\
sp.id = \"pm-\" + val;\
td.appendChild(sp);\
tr.appendChild(td);\
} {\
let td = document.createElement(\"td\");\
let sp = document.createElement(\"span\");\
sp.id = \"pv-\" + val;\
td.appendChild(sp);\
tr.appendChild(td);\
}\
tb.appendChild(tr);\
});\
}\
}\
\
try {\
$('.j-spin').removeClass(\"collapse\");\
res = await $.ajax({\
url: baseurl + \"/api/scan\",\
type: 'GET'\
});\
$('.j-spin').addClass(\"collapse\");\
$.each(res, function (idx, val) {\
let l = document.createElement('label');\
l.classList = \"btn btn-link slave-sel\";\
l.id = \"bus-\" + val;\
let r = document.createElement('input');\
r.type = \"radio\";\
r.name = \"options\";\
r.autocomplete = \"off\";\
l.innerHTML = '0x' + val.toString(16);\
l.appendChild(r);\
$('#buslst')[0].appendChild(l);\
\
$(l).click(function (e) {\
$('.slave-selected').removeClass('collapse');\
});\
});\
} catch (e) {\
console.log(e);\
}\
\
$('.j-ports-refresh').click(async function (e) {\
try {\
let busnr = $('.slave-sel.active')[0].id.substring(4);\
\
$('.j-spin').removeClass(\"collapse\");\
\
res = await $.ajax({\
url: baseurl + \"/api/getportmodes/\" + busnr,\
type: 'GET'\
});\
$('.j-spin').addClass(\"collapse\");\
$.each(res, function (idx, val) {\
let port = val.port;\
let mode = val.mode;\
\
let jpm = $('#pm-' + port);\
if (jpm[0] != null) jpm[0].innerHTML = mode;\
});\
} catch (e) {\
console.log(e);\
}\
\
try {\
let busnr = $('.slave-sel.active')[0].id.substring(4);\
\
$('.j-spin').removeClass(\"collapse\");\
\
res = await $.ajax({\
url: baseurl + \"/api/getportvalues/\" + busnr,\
type: 'GET'\
});\
$('.j-spin').addClass(\"collapse\");\
$.each(res, function (idx, val) {\
let port = val.port;\
let v = val.value;\
\
let jpm = $('#pv-' + port);\
if (jpm[0] != null) jpm[0].innerHTML = v;\
});\
} catch (e) {\
console.log(e);\
}\
});\
\
}\
\
myfn();\
")
