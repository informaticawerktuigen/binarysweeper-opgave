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
  - [Oefening 4](#oefening-4)
    - [Voorkennis](#voorkennis-3)
    - [Opgave](#opgave)
    - [Hints](#hints)
  - [Oefening 5](#oefening-5)
    - [Voorkennis](#voorkennis-4)
    - [Oefening](#oefening-3)
    - [Hints](#hints-1)
  - [Oefening 6](#oefening-6)
    - [Voorkennis](#voorkennis-5)
    - [Opgave](#opgave-1)
    - [Hints](#hints-2)
  - [Oefening 7](#oefening-7)
    - [Voorkennis](#voorkennis-6)
    - [Opgave](#opgave-2)
    - [Voorbeeld](#voorbeeld)
    - [Hulp](#hulp)
    - [Hints](#hints-3)

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

Installeer ook `pkg-config` om het project correct te kunnen builden:

```bash
sudo apt install pkg-config
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
$ ./binarysweeper-api
```

* Indien bovenstaand commando errors geeft, *lees de errors* en probeer ze te begrijpen. Dit kunnen bijvoorbeeld compiler errors zijn (fout geschreven code) of linker errors (ontbrekende functies of functiedeclaraties).
* Gebruik het forum indien je een error message niet begrijpt. Post enkel de error message, niet je code.

### Oefening 4

#### Voorkennis

* [Les 1: Pure C][les1]
* [Les 2: C Build Tools][les2]
* [Les 3: Bits & bytes][les3]
* [Les 4: Afgeleide datatypes][les4]

#### Opgave

In `include/state.h` kan je de definitie van de `struct game_state` terugvinden.

* Voeg de functies `is_victory(struct game_state state)` en `is_loss(struct game_state state)` toe aan `binary.c`.

Deze functies moeten `0` (false) of `1` (true) returnen.
Gebruik de meegegeven `struct game_state` om te bepalen of een spelstate al dan niet gewonnen/verloren is.

Een spelstate wordt beschouwd als *verloren* indien het `visibility_board` ervoor zorgt dat een mijn van het `mine_board` zichtbaar is.

Een spelstate wordt beschouwd als *gewonnen* indien alle cellen zichtbaar zijn in het `visibility_board` *behalve* de cellen die een mijn bevatten.

Gebruik *binaire operatoren* om beide functies te implementeren. Je mag *geen* lussen gebruiken.

#### Hints

* Merk op dat `is_victory(state)` niet hetzelfde is als `!is_loss(state)`
* Het `flag_board` is irrelevant om te bepalen of een spel al dan niet gewonnen is.
* Combineer het `mine_board` en het `visibility_board` met binaire operatoren. Denk na over de betekenis van elke operator op deze borden.

### Oefening 5

#### Voorkennis

* [Les 1: Pure C][les1]
* [Les 2: C Build Tools][les2]
* [Les 3: Bits & bytes][les3]
* [Les 4: Afgeleide datatypes][les4]
* [Les 5: Scopes and lifetimes][les5]

#### Oefening

In `include/game.h` kan je een interface vinden waarmee je een spel BinarySweeper kan starten en spelen.

* Maak een bestand `autoplay.c`.
* Schijf in dit bestand een functie `void play_custom_game()`.

Deze functie moet de BinarySweeper interface gebruiken om een spel met vaste seed te spelen van start tot overwinning.
Kies zelf een seed naar keuze voor je implementatie.
Je mag deze hard-coden in je functie.

> :information_source: Onze BinarySweeper implementatie genereert willekeurige borden met behulp van een Pseudo Random Number Generator (PRNG). De getallen die gegenereerd worden zijn niet echt willekeurig, maar worden gegenereerd door een mathematische functie. Afhankelijk van de `seed` (zaadje) dat je meegeeft aan deze functie, zal een volledig andere reeks "willekeurige" getallen gegenereerd worden. Elke `seed` zal dus een uniek spelbord genereren. [Meer info](https://stats.stackexchange.com/questions/354373/what-exactly-is-a-seed-in-a-random-number-generator)

De functie moet:

* De starting state printen.
* De state printen na elke uitgevoerde zet op het spelbord.
* Het eindbord printen.

Wanneer je de functie oproept zou dus het volledige spelverloop moeten geprint worden naar de console.

> :warning: Het is niet de bedoeling dat je user input vraagt om het spel te spelen. Je functie moet volledig zelfstandig alle zetten uitvoeren om het spel correct op te lossen.

> :warning: Speel het spel met de interface in `game.h`, niet met de interface in `state.h`.

#### Hints

* Je kan gebruik maken van de functie `print_game_state` in `include/state.h` om een state van een spel te printen.
* De code in `cli/cli.c` gebruikt ook de interface in `include/game.h`. Indien je twijfelt hoe een functie gebruikt moet worden, kan je een kijkje nemen in deze code voor inspiratie. Als het dan nog steeds onduidelijk is, vraag gerust op het forum.
* Indien je veel zetten nodig hebt zal de output van je programma lang zijn. Je kan het programma uitvoeren en pipen naar `less` om er gemakkelijk door te scrollen: `./binarysweeper-api | less`
* Vergeet niet om `delete_game` op te roepen wanneer je klaar bent met het spel.

### Oefening 6

#### Voorkennis

* [Les 1: Pure C][les1]
* [Les 2: C Build Tools][les2]
* [Les 3: Bits & bytes][les3]
* [Les 4: Afgeleide datatypes][les4]
* [Les 5: Scopes and lifetimes][les5]
* [Les 6: Dynamische structuren][les6]

#### Opgave

Voeg en functie `struct game *solve_seed(unsigned seed)` toe aan `autoplay.c`.
Deze functie krijgt als input een `seed`, en zal vervolgens automatisch het spel met deze seed oplossen.
Maak opnieuw gebruik van de interface in `include/game.h`.

* Het is *niet* verplicht om de kortst mogelijke oplossing te vinden.
* Je auto-solver *mag* gebruik maken van de `undo`-functionaliteit.

Voeg vervolgens een functie `void print_full_game(struct game *game)` toe aan `util.c`.

* Deze functie neemt als invoer een spel en zal elke state in de *history* van dit spel printen naar de console.

Gebruik `print_full_game` met het resultaat van `solve_seed` om het resultaat van je auto-solver te printen.

> :warning: `print_full_game` mag het spel niet aanpassen of spelen. Een oproep naar `print_full_game` mag er nooit toe leiden dat het spel zich nadien in een andere toestand bevindt. Print functies in het algemeen mogen hun parameters niet aanpassen. Stel je voor dat `printf` de waarden van meegegeven variabelen zou wijzigen, dat zou niet erg handig zijn.

> :warning: `print_full_game` moet werken voor eender welk geldig spel. Dit kan een spel zijn dat net gestart is met maar 1 toestand, of een volledig uitgespeeld spel, of alles daartussen.

#### Hints

* BinarySweeper gebruikt intern een [*doubly linked list*](https://en.wikipedia.org/wiki/Doubly_linked_list) van `struct history_element`s. Elk history element bevat 1 state. Dit biedt ons de mogelijkheid undo en redo-functionaliteit te implementeren.


### Oefening 7

#### Voorkennis

* [Les 1: Pure C][les1]
* [Les 2: C Build Tools][les2]
* [Les 3: Bits & bytes][les3]
* [Les 4: Afgeleide datatypes][les4]
* [Les 5: Scopes and lifetimes][les5]
* [Les 6: Dynamische structuren][les6]
* [Les 7: System interaction][les7]

#### Opgave

Voor de laatste en meest complexe oefening van dit project zullen jullie een save-functie moeten schrijven voor BinarySweeper.

Maak een bestand `api/save.c` aan. Schrijf in dit bestand de functie `int save_game(struct game *game, const char *filename)`.

* De parameter `game` is een pointer naar een BinarySweeper spel. Het spel kan zich in eender welke toestand bevinden: net begonnen, verloren, gewonnen, ... .
* De parameter `filename` is de naam van een bestand

De functie moet een bestand aanmaken met naam `filename`.
Naar dit bestand moet elke state van het BinarySweeper spel geschreven worden.
Dit moet in volgorde gebeuren, startend bij de allereerste state in de history en eindigend met de allerlaatste state.

Een state moet naar een bestand geschreven worden als volgt:

* Schrijf eerst het mijnenbord naar het bestand
* Schrijf vervolgens het vlaggenbord naar het bestand
* Schrijf ten slotte het zichtbaarheidsbord naar het bestand

Elk van deze borden zijn `uint64_t` getallen.
Het is de bedoeling dat deze getallen rechtstreeks geschreven worden volgens hun interne, binaire representatie.
Het is dus niet de bedoeling dat ze eerst worden omgezet naar strings en vervolgens in een leesbaar formaat in het bestand geschreven worden.
Wanneer je het bash-commando `file` uitvoert op je outputbestand, willen we geen `ASCII` file te zien krijgen, wel gewoon `data`.

#### Voorbeeld

Stel dat we een spel hebben met een spelbord met exact 1 bom op positie (0, 0).
Het spel is net gestart, en de speler heeft geklikt op (0, 0).
De speler is verloren.
Op dat moment hebben we een `game` met twee states in de history van het spel.

De eerste state bevat een mijnenbord met hexadecimale waarde `0x1`, en een vlaggenbord en zichtbaarheidsbord met beide de hexadecimale waarde `0x0`.
De tweede state bevat een mijnenbord met hexadecimale waarde `0x1`, een vlaggenbord met hexadecimale waarde `0x0` en een zichtbaarheidsbord met hexadecimale waarde `0x1`.

Indien we dit spel saven, krijgen we een bestand van `aantal_states * 3 * 8` bytes groot, dus exact 48 bytes groot.

* Bytes 0 - 7 stellen het mijnenbord voor van state 0, dus `0x1`
* Bytes 8 - 15 stellen het vlaggenbord voor van state 0, dus `0x0`
* Bytes 16 - 23 stellen het zichtbaarheidsbord voor van state 0, dus `0x0`
* Bytes 24 - 31 stellen het mijnenbord voor van state 1, dus `0x1`
* Bytes 32 - 39 stellen het vlaggenbord voor van state 1, dus `0x0`
* Bytes 40 - 47 stellen het zichtbaarheidsbord voor van state 1, dus `0x1`

#### Hulp

Onderstaande code maakt een bestand aan dat het voorbeeldspel dat we zonet beschreven hebben voorstelt:

```C
#include <stdio.h>
#include <stdint.h>

int main(void)
{

    uint64_t example_game[] = {0x1ull, 0x0ull, 0x0ull, 0x1ull, 0x0ull, 0x1ull};

    FILE *file = fopen("example_game", "wb");
    if (file == NULL)
    {
        return -1;
    }

    if (fwrite(example_game, sizeof(example_game), 1, file) != 1)
    {
        return -1;
    }
    fclose(file);
    return 0;
}
```

Indien je deze code compileert en uitvoert krijg je een bestand genaamd `example_game`, dat exact 48 bytes groot is.
Dit kan je nakijken met `ls -a`.

Je kan de inhoud van dit bestand inspecteren met `hd -v`:

```bash
$ hd -v example_game
00000000  01 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00000010  00 00 00 00 00 00 00 00  01 00 00 00 00 00 00 00  |................|
00000020  00 00 00 00 00 00 00 00  01 00 00 00 00 00 00 00  |................|
00000030
```

Om het eenvoudiger te maken om jullie oplossing na te kijken, hebben we een nieuwe versie van `cli.c` online gezet, in de repository van deze opgave. Deze nieuwe versie kan je downloaden met onderstaande commando's:

```bash
$ cd src/cli
$ wget -N https://raw.githubusercontent.com/informaticawerktuigen/binarysweeper-opgave/main/cli.c
```
> :information_source: GitHub classroom laat het helaas niet toe om rechtstreeks updates te pushen naar jullie repository, vandaar dat we de nieuwe cli.c op deze manier moeten doorgeven. Dat is zeker niet hoe het normaal zou horen met `git`.

De nieuwe `cli` laat je toe om een bestand mee te geven als argument van het programma.
De `cli` zal aannemen dat dit bestand een geldig spel voorstelt en dit vervolgens als spel tonen:

```bash
$ make
$ ./binarysweeper-cli example_game
```
Indien je dus de `example_game` file aanmaakt met de code die we hierboven meegaven, zou je het spel moeten zien dat we in het voorbeeld beschreven hebben.

Ten slotte hebben we nog een uitgebreidere save-file meegegeven: we hebben de seed `344372342` manueel opgelost en deze oplossing bewaard.
Je kan dit gehele spel bekijken door het bestand `playthrough_344372342` te laden:

```bash
$ wget https://github.com/informaticawerktuigen/binarysweeper-opgave/raw/main/playthrough_344372342
$ ./binarysweeper-cli playthrough_344372342
```

Met undo kan je het gehele spel terugspoelen naar de initiële state.

> :information_source: Merk op dat de seed telkens als 0 wordt weergegeven. Dit doen we omdat we de seed niet bewaren in een bestand en dus onmogelijk kunnen achterhalen op basis van een save file.

> :information_source: Het kan interessant zijn om eens willekeurige bestanden (geen save files) mee te geven aan de `cli`.
> Aangezien we op geen enkele manier controleren of de bestanden wel geldige spellen voorstellen, zal onze `cli` de files toch interpreteren als binarysweeper spellen. Kan je de vreemde spellen die je te zien krijgt verklaren? Dit is nog maar eens een voorbeeld dat de manier waarop je data interpreteert, bepaalt wat de betekenis is van deze data.

> :information_source: Misschien is het je opgevallen dat de bytes van elke `uint64_t` van rechts naar links geschreven worden naar het bestand.
> Het getal `0x1` als 64-bit getal wordt `01 00 00 00 00 00 00 00` wanneer we het byte per byte naar een bestand schrijven.
> Dit heeft te maken met de [endianness](https://en.wikipedia.org/wiki/Endianness) van de onderliggende processor.
> De meeste populaire processorarchitecturen gebruiken de `little endian byte order`, waarbij bytes bewaard worden in de volgorde least significant naar most significant.
> Indien je een BinarySweeper save file zou laden op een machine met `big endian byte order` zou het plots een ander spel tonen (horizontaal gespiegeld, de bytes zullen in andere volgordes zitten en elke byte stelt een rij voor).
> We zouden die inconsistentie kunnen vermijden door byte per byte te schrijven en te laden, maar dat zou ons voor deze opgave te ver leiden.

#### Hints

* Zorg ervoor dat je `fwrite` goed begrijpt (`man fwrite`). Probeer niet gewoon de code van hierboven te copy-pasten. Jullie code zal geen array schrijven naar een bestand.
* Het is mogelijk om een struct in één enkele schrijfoperatie naar een bestand te schrijven. Voor structs met padding kan dit er echter toe leiden dat de padding ook in het bestand terecht komt. Indien je verschillende compilers zou gebruiken met verschillende paddings, kan het zijn dat je save-file plots niet meer werkt. Gebruik daarom drie schrijfoperaties per state, één schrijfoperatie per bord.
* Zorg ervoor dat je het save-file formaat goed begrijpt. Inspecteer de meegegeven save files `example_game` en `playthrough_344372342` met `hd -v` (hexdump) en probeer te begrijpen wat de verschillende bytes betekenen. Kan je een manier bedenken om het formaat te verkleinen (minder bytes per spel)?

[les1]: https://github.com/informaticawerktuigen/oefenzitting-c/tree/main/les1-purec
[les2]: https://github.com/informaticawerktuigen/oefenzitting-c/tree/main/les2-c-build-tools
[les3]: https://github.com/informaticawerktuigen/oefenzitting-c/tree/main/les3-bits-and-bytes
[les4]: https://github.com/informaticawerktuigen/oefenzitting-c/tree/main/les4-afgeleide-datatypes
[les5]: https://github.com/informaticawerktuigen/oefenzitting-c/tree/main/les5-scopes-and-lifetimes
[les6]: https://github.com/informaticawerktuigen/oefenzitting-c/tree/main/les6-dynamische-structuren
[les7]: https://github.com/informaticawerktuigen/oefenzitting-c/tree/main/les7-system-interaction
