# BinarySweeper <!-- omit in toc -->

## Inhoudstafel <!-- omit in toc -->

- [GitHub classroom](#github-classroom)
- [Afspraken](#afspraken)
  - [Gedragscode](#gedragscode)
  - [Forum](#forum)
  - [Indienen](#indienen)
- [Introductie](#introductie)
- [Voorbereiding](#voorbereiding)
- [Structuur](#structuur)
  - [src/include](#srcinclude)
  - [src/cli](#srccli)
  - [src/test](#srctest)
  - [src/api](#srcapi)
- [Interne representatie](#interne-representatie)
  - [Mijnenbord](#mijnenbord)
  - [Vlaggenbord](#vlaggenbord)
  - [Zichtbaarheidsbord](#zichtbaarheidsbord)
  - [Waarden van cellen](#waarden-van-cellen)
- [Oefeningen](#oefeningen)
  - [Indienen](#indienen-1)
  - [Oefening 1](#oefening-1)
    - [Voorkennis](#voorkennis)
    - [Oefening](#oefening)
    - [Tips](#tips)
  - [Oefening 2](#oefening-2)
    - [Voorkennis](#voorkennis-1)
    - [Oefening](#oefening-1)
  - [Oefening 3](#oefening-3)
    - [Voorkennis](#voorkennis-2)
    - [Oefening](#oefening-2)
    - [Tips](#tips-1)

## GitHub classroom

Voor dit project zullen jullie weer werken in een eigen GitHub classroom repository.

Je kan een repository aanmaken met behulp van deze link: https://classroom.github.com/a/OYnDjy2F.

## Afspraken

Overloop eerst de afspraken vooraleer je begint aan de opgave.

### Gedragscode

De practica worden gequoteerd, en het examenreglement is dan ook van toepassing.
Soms is er echter wat onduidelijkheid over wat toegestaan is en niet inzake samenwerking bij opdrachten zoals deze.

De oplossing en/of programmacode die ingediend wordt moet volledig het resultaat zijn van werk dat je zelf gepresteerd hebt.
Je mag je werk uiteraard bespreken met andere studenten, in de zin dat je praat over algemene oplossingsmethoden of algoritmen, maar de bespreking mag niet gaan over specifieke code of verslagtekst die je aan het schrijven bent, noch over specifieke resultaten die je wenst in te dienen.
Als je het met anderen over je practicum hebt, mag dit er dus *nooit* toe leiden, dat je op om het even welk moment in het bezit bent van een geheel of gedeeltelijke kopie van het opgeloste practicum of verslag van anderen, onafhankelijk van of die code of verslag nu op papier staat of in elektronische vorm beschikbaar is, en onafhankelijk van wie de code of het verslag geschreven heeft (mede-studenten, eventueel uit andere studiejaren, volledige buitenstaanders, internet-bronnen, e.d.).
Dit houdt tevens ook in dat er geen enkele geldige reden is om je code of verslag door te geven aan mede-studenten, noch om dit beschikbaar te stellen via publiek bereikbare directories of websites. De git-repository die we jullie ter beschikking stellen is standaard op privaat ingesteld.

Elke student is verantwoordelijk voor de code en het werk dat hij of zij indient.
Als tijdens de beoordeling van het practicum er twijfels zijn over het feit of het practicum zelf gemaakt is (bvb. gelijkaardige code, of oplossingen met andere practica), zal de student gevraagd worden hiervoor een verklaring te geven.
Indien dit de twijfels niet wegwerkt, zal er worden overgegaan tot het melden van een onregelmatigheid, zoals voorzien in het onderwijs- en examenreglement (zie http://www.kuleuven.be/onderwijs/oer/).

**Alle inzendingen worden automatisch met elkaar vergeleken met behulp van plagiaatsoftware voor code.
Deze software geeft een score van gelijkaardigheid aan projecten.
De projecten die het meest op elkaar lijken worden nadien manueel nagekeken.**

### Forum

Alle vragen over het practicum, *inclusief vragen aan medestudenten*, moeten gesteld worden via het **discussieforum** op [Toledo](https://p.cygnus.cc.kuleuven.be/webapps/discussionboard/do/forum?action=list_threads&course_id=_948319_1&nav=discussion_board_entry&conf_id=_1668620_1&forum_id=_939598_1).

Alle antwoorden van assistenten op het discussieforum worden beschouwd als **deel van de opgave** en kunnen bijgevolg aanvullingen of correcties bevatten.
Zorg ervoor dat je deze posts leest!

Tip: open het forum en klik bovenaan op *subscribe* om een e-mail te krijgen wanneer nieuwe threads worden toegevoegd aan het forum.

### Indienen

De *deadline* voor dit practicum is **zondag 13 december 2020** om **23u59**.
Het practicum wordt ingediend met behulp van _Git_.
Push de oplossingen van de verschillende oefeningen *in aparte commits* naar je repository.

Wijzigingen aan jullie repository na de deadline zullen niet aanvaard worden.



## Introductie

In dit C project gaan we verder kijken naar een spel dat jullie ondertussen zeer goed kennen: Mijnenveger!

Ditmaal moeten jullie het spel niet zelf implementeren - dat hebben wij al voor jullie gedaan.
In dit project zullen jullie onze implementatie gebruiken vanuit C code in een reeks kleinere opgaven.
Deze opgaven zullen worden vrijgegeven in parallel met de lessen die je nodig hebt om de opgaven te kunnen oplossen.

## Voorbereiding

Voordat je ons spel kan spelen moet je eerst `ncurses` installeren.
Dat is een bibliotheek waarmee we onze *command line interface* hebben geschreven.
Gebruik onderstaand commando voor deze installatie:

```bash
sudo apt install libncurses-dev
```

> :information_source: Dit installatiecommando zorgt ervoor dat de header-file `ncurses.h` toegevoegd wordt aan je `/usr/include` folder.
Daarnaast wordt de `ncurses`-library toegevoegd aan je `/usr/lib` folder, zodat deze statisch of dynamisch gelinkt kan worden aan je programma. Op deze manier kan je dus C-libraries installeren in Ubuntu.

Nadat je `ncurses` hebt geïnstalleerd, kan je het spel compileren en spelen. Veel plezier!

```bash
$ cd repository
$ make
$ ./binarysweeper-cli
```
> :information_source: Het commando `make` gebruikt een `Makefile`-script om alle build-commando's automatisch uit te voeren. Een toekomstige les zal hier dieper op ingaan. De commando's die uitgevoerd worden, zullen geprint worden naar de console. Deze zou je na les 2 moeten kunnen begrijpen (met uitzondering van enkele flags).

## Structuur

Onze spelimplementatie heeft een strikte scheiding tussen de grafische interface (in dit geval een command line interface of `cli`) en de interne representatie.
De `cli` gebruikt de functies gedefinieerd in `src/include/game.h` en `src/include/state.h` om het spel te spelen.
De spellogica zelf (de functiedefinities) zitten in de library `libbinarysweeper.a`.

> :information_source: Een `.a` bestand is een library (zoals we zagen in les 2, zeer gelijkaardig aan een `.o` bestand) die enkel statisch gelinkt kan worden. Een `.so` bestand is een library die dynamisch gelinkt kan worden.

De broncode van onze spellogica hebben we niet meegegeven.
Jullie hebben enkel toegang tot de gecompileerde library.
Wel hebben jullie toegang tot de header files, de code van de `cli` en de code van een simpele testsuite.

### src/include

De `src/include` folder bevat de publieke functiedeclaraties die we gebruikt hebben bij onze implementatie van minesweeper.
Je kan deze header-files includen in je eigen code en vervolgens de gedeclareerde functies oproepen.

Ze vormen de *Application Programming Interface* ([API](https://en.wikipedia.org/wiki/API)) van het spel.
Gedurende het project zal je de API van BinarySweeper moeten gebruiken om programmeeropgaven op te lossen.

> :bulb: Je kan reeds een kijkje nemen in de verschillende `.h` bestanden in de API om te ontdekken welke functies aangeboden worden. Op het moment dat je bepaalde functies nodig zal hebben, zullen wij hun nut verduidelijken.

### src/cli

In de `src/cli` folder kan je de volledige broncode van onze command line interface terugvinden.
Het is niet nodig dit bestand te begrijpen of aan te passen.
De `CLI` gebruikt intern wel volop de `API` functies aangeboden door ons spel.
Indien je jezelf op een bepaald moment dus afvraagt hoe je een bepaalde functie uit de `API` moet gebruiken, kan je eens gaan kijken naar de code in de `CLI`.

> :bulb: Met het commando `grep -r "naam-van-functie"` kan je snel terugvinden in welke bestanden een bepaalde functie gebruikt wordt.

Op het moment dat je `make` uitvoert, wordt de code in deze folder gecompileerd en gelinkt aan onze library.
Het resultaat is het uitvoerbare bestand `binarysweeper-cli`.
Met `make cli` compileer je de code en run je nadien automatisch de `cli`.

### src/test

In de `src/test` folder vind je de broncode van enkele automatische tests die we geschreven hebben.
Ook deze tests gebruiken volop de interne `API`.

De testsuite is niet compleet.
Doorheen het project zullen jullie soms gevraagd worden tests toe te voegen.

Op het moment dat je `make` uitvoert, wordt de code in deze folder gecompileerd en gelinkt aan onze library.
Het resultaat is het uitvoerbare bestand `binarysweeper-test`.
Met `make test` compileer je de code en run je nadien automatisch de testsuite.

### src/api

De folder `src/api` wordt de voornaamste werkfolder van je project.
Hierin zal je de meeste van je eigen code schrijven. Op dit moment vind je hier enkel een simpel C-bestand met main-functie.

Op het moment dat je `make` uitvoert, wordt de code in deze folder gecompileerd en gelinkt aan onze library.
Het resultaat is het uitvoerbare bestand `binarysweeper-api`.
Met `make api` compileer je de code en run je nadien automatisch de de api.

## Interne representatie

Tijd om onze interne representatie voor te stellen.
Hoewel de API niet rechtstreeks vereist dat je de interne representatie snapt, zal je deze in de oefeningen wel moeten begrijpen en gebruiken.

> :information_source: Voor deze interne representatie hebben we ons laten inspireren door het JavaScript project van één van jullie medestudenten. Om privacyredenen gaan we de naam van de student hier niet rechtstreeks vermelden, maar de student zelf zal de representatie zeker herkennen.

Het BinarySweeper spelbord heeft een vaste grootte: 8 x 8.
Deze grootte kan *niet* aangepast worden.
Daar is een goede reden voor.
Het volledige 8 x 8 spelbord kan hierdoor voorgesteld worden door 3 getallen, elk 64 bit lang.

Elk getal komt overeen met een subbord.
We hebben een vlaggenbord, een mijnenbord en een zichtbaarheidsbord.

### Mijnenbord

Het mijnenbord (mine board) is een 64-bit getal.
Aangezien het spelbord 8 x 8 groot, heeft het spelbord 64 vakjes.
Elk vakje kan dus rechtstreeks gelinkt worden aan 1 bit.
Indien de bit van een vakje op 1 staat, bevat dit vakje een mijn.
Indien de bit van een vakje op 0 staat, bevat dit vakje geen mijn.

Indien je het 64-bit getal opsplitst in 8 delen van 8 bits, komt elk deel overeen met 1 rij van het spelbord.

> :bulb: Er komt een volledige sessie waarin jullie zullen leren werken met bitoperaties in C. Let tijdens die sessie dus goed op, jullie zullen dit nodig hebben in het project.

We geven een voorbeeld.
Het hexadecimale getal `0x100000000070587` kunnen we binair voorstellen als 64-bit getal (hiervoor kan je bijvoorbeeld `python` gebruiken):

```python
$ python
>>> format(0x100000000070587, '064b')
'0000000100000000000000000000000000000000000001110000010110000111'
```

Beschouw dit 64-bit binaire getal als een array/lijst van 64 booleaanse waarden (`true` of `false`).
Elke bit heeft een specifieke index, we noemen dit even `bit_index`.
Wanneer we binaire getallen indexeren, gebeurt dit traditioneel *van rechts naar links*, ofwel van *least significant bit* naar *most significant bit*.
In bovenstaand getal heeft bit met index 0 dus de waarde `1`.

In onze representatie hebben we besloten om de volgende formule te gebruiken om een bit index om te zetten naar een rij- en kolomnummer: `bit_index = rij_index*8+kolom_index`.
Zo heeft de cel op rij 0, kolom 0 een bit index van 0, rij 1 kolom 0 een bit-index van 8, enzovoort.

Je kan vervolgens verifiëren dat het hexadecimale getal `0x100000000070587` het onderstaande spelbord voorstelt:

| | | | | | | | |
|---|---|---|---|---|---|---|---|
| \* | \* | \* | 2  |    |    | 1  | \* |
| \* | 8  | \* | 3  |    |    | 1  | 1  |
| \* | \* | \* | 2  |    |    |    |    |
|  2 |  3 | 2  | 1  |    |    |    |    |
|  &#x200B;  |    |    |    |    |    |    |    |
|  &#x200B;  |    |    |    |    |    |    |    |
|  1 | 1  |    |    |    |    |    |    |
| \* | 1  |    |    |    |    |    |    |

### Vlaggenbord

Het vlaggenbord (flag board) is ook een 64-bit getal.
Dit bord werkt exact hetzelfde als het mijnenbord.
Een `1`-bit wil zeggen dat er een vlag staat op die positie op het spelbord.
We gebruiken dezelfde omzetting tussen bordcoördinaten en bit indices als in het mijnenbord.

### Zichtbaarheidsbord

Het zichtbaarheidsbord (visibility board) is ons laatste 64-bit getal.
Opnieuw komt elke bit overeen met een cel op het spelbord, met dezelfde omzettingsformule.
In dit bord betekent de waarde `1` dat de waarde van een vakje zichtbaar is voor een speler.
Bij de start van een mijnenvegerspel is bord dus gelijk aan `0` (alle bits van het getal staan op 0).
Wanneer we klikken op een cel, wordt de bit die bij de cel hoort op `1` gezet.
Indien de waarde van de aangeklikte cel gelijk is aan 0, worden ook alle buurvakjes op `1` gezet.

### Waarden van cellen

De waarden van cellen worden nergens bewaard.
Voor elk (al dan niet zichtbaar vakje) kan de waarde berekend worden met de functie `calc_cell_value`.
Dit is een bewuste keuze: we houden onze interne representatie zo compact mogelijk, met minimale info.
De volledige spelbordrepresentatie zit omvat in 3 getallen van 64-bit.

Het nadeel is natuurlijk dat, elke keer wanneer we het bord tekenen, we alle waarden opnieuw moeten uitrekenen.
Deze representatie is dus niet beter of slechter dan de representaties die velen van jullie gebruikt hebben in het JavaScript-project.
Het is een representatie die geheugengebruik minimaliseert ten koste van processorcycli.

## Oefeningen

In deze sectie zullen de oefeningen die jullie moeten maken in dit project komen te staan.
Hier zullen gradueel oefeningen bijkomen in parallel met de verschillende lessen die zullen verschijnen.

Bij elke oefening zullen we aangeven welke voorkennis je nodig hebt om deze te kunnen oplossen.
Zodra je de voorkennislessen doorlopen hebt, maak dan zo snel mogelijk de oefening.
Het is geen goed idee om hiermee te wachten tot de laatste week.

### Indienen

**Maak voor elke oefening een aparte commit**.
Voeg de relevante bestanden toe met `git add`, zet de nummer van de oefening in je commit message en push de commit zodra je de oefening hebt afgewerkt.
Je verliest geen punten indien je afwijkt van deze procedure, maar ervoor zorgen dat elke commit gerelateerd is aan exact één wijziging/oefening is gewoon *good practice*.

### Oefening 1

#### Voorkennis

* Begrip van binaire, decimale en hexadecimale getalvoorstellingen.

#### Oefening

In de eerste oefening van dit project moet je nog niets programmeren.
Het doel van deze oefening is om manueel een spelbord op te stellen.
Het spelbord moet voldoen aan de volgende eigenschappen:

* In totaal staan er tien bommen op het spelbord
* Er zijn *exact* vier cellen met waarde 4

Zoek een getal dat, wanneer we het lezen als een 64-bit binair getal, een mijnenbord voorstelt dat voldoet aan bovenstaande eigenschappen.
Uiteraard volg je de regels van de interne representatie zoals hierboven neergeschreven.

Bewaar dit getal in een tekstbestand genaamd `oefening1` in de root-folder van je Git-repository.
Bewaar het getal in zijn hexadecimale representatie.
Start het getal met `0x` om duidelijk te maken dat het een hexadecimaal getal is.

#### Tips

Met python kan je eenvoudig de omzetting maken tussen hexadecimale, decimale en binaire getallen:

```python
$ python
>>> hex(16)
'0x10'
>>> bin(16)
'0b10000'
>>> bin(0x10)
'0b10000'
>>> 0b11001100
204
>>> 0x10
16
>>> hex(0b10101011100010)
'0x2ae2'
```

### Oefening 2

#### Voorkennis

* [Les 1: Pure C][les1]
* [Les 2: C Build Tools][les2]

#### Oefening

* Maak een bestand `util.c` in de folder `src/api`.
* Schrijf een functie `bit_index_from_coordinates` in dit C-bestand.

Deze functie moet:

* twee `int` parameters nemen als input, genaamd `row` en `col`;
* één `int` returnen, namelijk de overeenkomstige bit index

De twee parameters komen overeen met een rij en een kolom op het 8 x 8 spelbord.
De return waarde stelt een bit-index voor op een 64-bit spelbord.
Deze representatie is beschreven in de sectie interne representatie van dit document.

De functie zet dus coördinaten om in bit indices.

### Oefening 3

#### Voorkennis

* [Les 1: Pure C][les1]
* [Les 2: C Build Tools][les2]
* [Les 3: Bits & bytes][les3]

#### Oefening

* Maak een bestand `binary.c` in de folder `src/api`.
* Schrijf een functie `int is_flag_at_coordinates(uint64_t board, int row, int col)` in dit C-bestand.

Het inputargument `board` is een 64-bit getal.

Deze functie moet:

* `row` en `col` omzetten naar een bit-index met de functie uit `oefening 2`. Hierbij is het *niet* de bedoeling dat je de functie copy-paste naar `binary.c`. Gebruik header files! 
* Met behulp van binaire operaties achterhalen of een bepaald coördinaat op het spelbord al dan niet een vlag bevat. Gebruik hiervoor uiteraard ook de bit-index die je berekent hebt.
* De returnwaarde van de functie moet 0 zijn indien er geen vlag staat en 1 indien er wel een vlag staat.

#### Tips

* Maak gebruik van een mask. Indien je een mask wilt opstellen van het type `uint64_t`, doe dit als volgt: `uint64_t mask = 1ull << idx`. Indien je gewoon `1` zou gebruiken, wordt dit opgevat als een signed int en is het mogelijk dat het resultaat van je bit shift undefined is.  Met `1ull` zorg je ervoor dat het resultaat van je expressie een `unsigned long long` is die gegarandeed minstens `64-bit` zal bevatten.
* Je kan je functie testen door hem op te roepen vanuit main (`api/api.c`). Geef bijvoorbeeld het bord mee dat je hebt opgesteld hebt in oefening 1.
* De `Makefile` zal elk van je `.c` bestanden compileren en de resulterende `.o` bestanden automatisch linken. Hiervoor moet je gewoon het commando `make` uitvoeren in de root folder van je repo. De binary binarysweeper-api is het resultaat van dat linkcommando. Als je deze uitvoert wordt de main-functie in `api/api.c` uitgevoerd:
  
```bash
$ cd binarysweeper-NaamStudent
$ make
$ ./binarysweeper-cli
```

* Indien bovenstaand commando errors geeft, *lees de errors* en probeer ze te begrijpen. Dit kunnen bijvoorbeeld compiler errors zijn (fout geschreven code) of linker errors (ontbrekende functies of functiedeclaraties).
* Gebruik het forum indien je een error message niet begrijpt. Post enkel de error message, niet je code.

[les1]: https://github.com/informaticawerktuigen/oefenzitting-c#les-1-pure-c]
[les2]: https://github.com/informaticawerktuigen/oefenzitting-c/tree/main/les2-c-build-tools
[les3]: https://github.com/informaticawerktuigen/oefenzitting-c/tree/main/les3-bits-and-bytes
[les4]: https://github.com/informaticawerktuigen/oefenzitting-c/tree/main/les4-afgeleide-datatypes