# chonkAP

FOR EDUCATIONAL AND INSTRUCTIONAL PURPOSES ONLY

<h1>NodeMCU / 8266 Captive Portal with cred harvester</h1>

A very simple 8266 credential harvester with captive portal. Do not use this for anything illegal, it is just a proof of concept.<BR>
Change "BumbleStore" and "PrimeMesh" to whatever you want. The nasty looking for/if loop in credTailStart() is there for a reason, if you use an sprintf or concat function it would lag out the entire box and cause latency on other GET/POST requests. Direct string copy seems to work a bit better for whatever reason.

Additions to be added later (Maybe @_@): <BR>
-SD card mount and write (for use with ESP32-CAM boards) <BR>
-enhanced cred harvester page (JS client side input validation) <BR>
-logo graphics in progmem (nothing hi res, simple base64 stuff) <BR>
-SSL/TLS integration (Try to get HTTPS requests to atleast show a cert error) <BR>
-Multiple cred harvester pages that all look different (with option to change through /chizzard/) <BR>
  
  mentalburden.com <BR>
  tasks@mentalburden.com
  
  AGAIN, DONT USE THIS FOR ILLEGAL OR IMMORAL ACTIVITIES. <BR>
  FOR EDUCATIONAL AND INSTRUCTIONAL PURPOSES ONLY
