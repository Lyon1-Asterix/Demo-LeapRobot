<div id="table-of-contents">
<h2>Table des matières</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#orgheadline1">1. Your-Robot</a></li>
<li><a href="#orgheadline2">2. Prérequis</a></li>
<li><a href="#orgheadline3">3. Circuit</a></li>
<li><a href="#orgheadline4">4. How it works ?</a></li>
<li><a href="#orgheadline5">5. Troubleshooting</a></li>
</ul>
</div>
</div>

![img](./resources/fhack.png)

# Your-Robot<a id="orgheadline1"></a>

Robot piloté par un Leap Motion et pilotable aussi à l'aide d'un module Bluetooth
à travers une application Android (Ardudroid) installée sur votre smartphone.

# Prérequis<a id="orgheadline2"></a>

-   Arduino Uno
-   Leap Motion
-   Module Bluetooth HC-06
-   2 moteurs DC
-   8 diodes LED
-   Circuit intégré L298 ou L293

# Circuit<a id="orgheadline3"></a>

![img](./resources/circuit.jpg)

# How it works ?<a id="orgheadline4"></a>

-   Télécharger et installer [Processing](https://processing.org/download/) et [Arduino IDE](https://www.arduino.cc/en/Main/Software).
-   Ouvrer dans [Arduino IDE](https://www.arduino.cc/en/Main/Software) le code se trouvant dans le dossier Arduino.
    -   Connecter l'Arduino à votre ordinateur et téléverser le code.
-   Ouvrer dans [Processing](https://processing.org/download/) le code se trouvant dans le dossier Processing.
    -   Brancher le Leap Motion <sup><a id="fnr.1" class="footref" href="#fn.1">1</a></sup>
    -   Exécuter le code.

# Troubleshooting<a id="orgheadline5"></a>

-   Sous Linux, vous aurez peut-être un problème du type :
    
        Arduino IDE error - avrdude: ser_open(): can't open device "/dev/ttyACM0": Permission denied
    
    -   Pour régler ce problème, entrer cette commande: 
        
            sudo chmod a+rw /dev/ttyACM0

<div id="footnotes">
<h2 class="footnotes">Notes de bas de page: </h2>
<div id="text-footnotes">

<div class="footdef"><sup><a id="fn.1" class="footnum" href="#fnr.1">1</a></sup> <div class="footpara">Sous Linux il faut lancer la commande `sudo leapd`</div></div>


</div>
</div>
