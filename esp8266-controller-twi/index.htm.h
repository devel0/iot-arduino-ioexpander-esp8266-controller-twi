/* GENERATED FILE BY gen-h UTIL - DO NOT EDIT THIS */
F("<html>\
\
<head>\
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\
\
<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.1.3/css/bootstrap.min.css\"\
integrity=\"sha256-eSi1q2PG6J7g7ib17yAaWMcrr5GrtohYChqibrV7PBE=\" crossorigin=\"anonymous\" />\
<link rel=\"stylesheet\" href=\"https://use.fontawesome.com/releases/v5.5.0/css/all.css\" integrity=\"sha384-B4dIYHKNBt8Bc12p+WXckhzcICo0wtJAoU8YZTY5qE0Id1GSseTk6S+L3BlXeVIU\"\
crossorigin=\"anonymous\">\
\
<style>\
.port:hover {\
background-color: rgba(0, 0, 0, .1);\
}\
\
.port-selected {\
background-color: rgba(255, 183, 0, .2);\
}\
</style>\
\
</head>\
\
<body>\
<div class=\"container\">\
<div class=\"row mt-3\">\
<div class=\"col-auto\">\
<h1>Arduino nano ESP8266 TWI controlled demo</h1>\
</div>\
<div class=\"col\"><i class=\"fas fa-spin fa-spinner j-spin collapse\"></i></div>\
</div>\
\
<div class=\"row\">\
<div class=\"col-auto\">\
<div class=\"row\">\
<div class=\"col-auto\">\
<h2>slave selector</h2>\
\
<div class=\"btn-group btn-group-toggle\" data-toggle=\"buttons\" id=\"buslst\">\
</div>\
</div>\
</div>\
<div class=\"row mt-3 slave-selected collapse\">\
<div class=\"col-auto\" style=\"padding:0\">\
<div id=\"imgdiv\">\
<img id='mapimg' src=\"image.png\" width=\"430\" height=\"741\" border=\"0\" usemap=\"#map\" />\
\
<map name=\"map\">\
<area shape=\"rect\" coords=\"0,74,107,104\" alt=\"D13\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"323,493,430,523\" alt=\"D2\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"323,451,430,481\" alt=\"D3\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"323,409,430,439\" alt=\"D4\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"323,366,430,396\" alt=\"D5\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"323,324,430,354\" alt=\"D6\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"323,282,430,312\" alt=\"D7\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"323,114,430,144\" alt=\"D11\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"323,72,430,102\" alt=\"D12\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"323,241,430,271\" alt=\"D8\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"0,324,107,354\" alt=\"A3\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"0,284,107,314\" alt=\"A2\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"0,240,107,270\" alt=\"A1\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"1,198,108,228\" alt=\"A0\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"323,199,430,229\" alt=\"D9\" nohref=\"nohref\" />\
<area shape=\"rect\" coords=\"323,156,430,186\" alt=\"D10\" nohref=\"nohref\" />\
</map>\
</div>\
</div>\
</div>\
</div>\
\
<div class=\"col-auto\">\
\
<div class=\"row mt-3 port-selector collapse\">\
<div class=\"col-auto\">\
<h2>port selector</h2>\
</div>\
</div>\
\
<div class=\"row mt-3\">\
<div class=\"col-auto slave-selected collapse\">\
<h2>port actions</h2>\
<div class=\"list-group port-actions collapse\" id='buslst'>\
<button class='btn btn-link mt-2 j-set-as-input'>set as INPUT</button>\
<button class='btn btn-link mt-2 j-set-as-output'>set as OUTPUT</button>\
<button class='btn btn-link mt-2 j-set-as-input-pullup'>set as INPUT (pullup)</button>\
<button class='btn btn-link mt-2 j-write-low'>write LOW</button>\
<button class='btn btn-link mt-2 j-write-high'>write HIGH</button>\
</div>\
</div>\
<div class=\"col-auto slave-selected collapse\">\
<h2>ports</h2>\
<div class=\"row\">\
<div class=\"col-auto\">\
<button class=\"btn btn-link j-ports-refresh\">read</button>\
</div>\
</div>\
<div class=\"row mt-2\">\
<div class=\"col-auto\">\
<div class=\"table-container\">\
<div class=\"table table-striped\">\
<table class=\"table\">\
<thread>\
<tr>\
<th scope=\"col\"><b>Port</b></th>\
<th scope=\"col\"><b>Mode</b></th>\
<th scope=\"col\"><b>Value</b></th>\
</tr>\
</thread>\
<tbody id='ports-tbody' />\
</table>\
</div>\
</div>\
</div>\
</div>\
</div>\
</div>\
</div>\
</div>\
\
\
\
</div>\
\
<script src=\"https://cdnjs.cloudflare.com/ajax/libs/jquery/3.3.1/jquery.min.js\" integrity=\"sha256-FgpCb/KJQlLNfOu91ta32o/NMZxltwRo8QtmkMRdAu8=\"\
crossorigin=\"anonymous\"></script>\
<script src=\"https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.1.3/js/bootstrap.min.js\" integrity=\"sha256-VsEqElsCHSGmnmHXGQzvoWjWwoznFSZc6hs7ARLRacQ=\"\
crossorigin=\"anonymous\"></script>\
<!-- <script src=\"app.js\"></script> -->\
<script src=\"/opensource/devel0/iot-arduino-ioexpander-esp8266-controller-twi/esp8266-controller-twi/app.js\"></script>\
</body>\
\
</html>")
