![Logo of the project](https://raw.githubusercontent.com/jehna/readme-best-practices/master/sample-logo.png)

# MotorArduino
## subproject gasklephuis RIDEX 158T0040
### onderdeel: Arduino sketch om de stationairklep te regelen.

Nadat we de SU-carburateur van de Morris 1098 cc hadden verwijderd, hebben we verschillende gaskleppen geprobeerd. Tot nu toe waren die alle te groot qua diameter. Bovendien waren het types met een restspleet voor het stationair toerental. Gecombineerd was een van de effecten dat we het laagste toerental niet onder de 1500RPM konden krijgen. Het huidige model stamt van rond 2000, heeft een kabelbediende klep die geheel sluit en een omloopstationairklep met een stappenmotor. Verder is er een potmeter die de met 1 loper de stand van de gasklep kan melden en een NTC weerstand voor het melden van de temperatuur van de inlaatlucht. Proef ondervindelijk is bepaald wat het aantal stappen van de stationairklep is tussen open en dicht: 90, en wat een acceptabele stroom lijkt voor de stappenmotor: 200mA. De eigenschappen van de potmeter zijn nagemeten en de NTC is geijkt.

## Installing / Getting started

A quick introduction of the minimal setup you need to get a hello world up &
running.

```Upload de sketch vanuit de Arduino IDE naar de Arduino Nano en het loopt

```

De sketch bepaalt eerst het nulpunt van de geheel geopende stationairklep. Het werkingsbereik is in de software ingesteld tussen 10, bijna geheel open, en 80 bijna geheel gesloten. De klep wordt initieel op 10 ingesteld. Daarna wacht de software tot via de serial monitor een aantal stappen voor bijstelling van de klepstand wordt ingegeven, enz. 

### Initial Configuration

Some projects require initial configuration (e.g. access tokens or keys, `npm i`).
This is the section where you would document those requirements.

## Developing

Here's a brief intro about what a developer must do in order to start developing
the project further:

```shell
https://github.com/Treurwilg/MotorArduino.git
repository: StepByStepValveControlFromSerialMonitor
```

And state what happens step-by-step.

### Building
Verbind de klemmen op klemmenstrook X2 met de stappenmotor 
Verbind de plus en min op klemmenstrook X3 met de accu of een andere 12volt bron.
De klemmen op X1 zijn bedoeld voor externe schakelaars voor het stap voor stap verstellen van
de stationairklep. De worden in de huidige opzet niet gebruikt.
Verbind Arduino via een USB kabel met een pc en open de serial monitor


### Deploying / Publishing

In case there's some step you have to take that publishes this project to a
server, this is the right time to state it.

```shell
packagemanager deploy awesome-project -s server.com -u username -p password
```

And again you'd need to tell what the previous code actually does.

## Features

Het enige dat de gebruiker kan doen is vai de serial monitor waarden  ingeven voor het
verstellen van de stationairklep.

## Configuration

De ontwikkelomgeving nu gebruikt gekoppeld aan een pc op linux debian11:

#### Arguments

Board: `Arduino Nano`  
Poort: `/Dev/ttyUSB0`  
Processor: `ATmega 326P`
Programmer: `ArduinoISP`

## Contributing

Iedereen is welkom, zowel om kennis te nemen van onze ervaring als om ons van 
kennis te voorzien.

## Links

https://www.youtube.com/@ecu-club


## Licensing

One really important part: Give your project a proper license. Here you should
state what the license is and how to find the text version of the license.
Something like:

"The code in this project is licensed under MIT license."
