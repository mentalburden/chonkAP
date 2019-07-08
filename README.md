# chonkAP

FOR EDUCATIONAL AND INSTRUCTIONAL PURPOSES ONLY

NodeMCU / 8266 Captive Portal with cred harvester

A very simple 8266 credential harvester with captive portal. Do not use this for anything illegal, it is just a proof of concept.
Change "BumbleStore" and "PrimeMesh" to whatever you want. The nasty looking for/if loop in credTailStart() is there for a reason, if you use an sprintf or concat function it would lag out the entire box and make server the other pages very slow. Direct string copy seems to work a bit better for whatever reason.

-Additions to come later (Maybe): 
  -SD card mount and write (for use with ESP32-CAM boards)
  -enhanced cred harvester page (JS client side input validation)
  -logo graphics in progmem (nothing hi res, simple base64 stuff)
  -SSL/TLS integration (Try to get HTTPS requests to atleast show a cert error)
  -Multiple cred harvester pages that all look different (with option to change through /chizzard/)
  
  AGAIN, DONT USE THIS FOR ILLEGAL OR IMMORAL ACTIVITIES.
  FOR EDUCATIONAL AND INSTRUCTIONAL PURPOSES ONLY
