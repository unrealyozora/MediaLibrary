---
date: March 14, 2025
---
# Servizi utilizzati
- Ide: Visual Studio 2022
- Git/ Github
- [Dia](http://dia-installer.de/)
- Cppcheck and Visual Studio Address Sanitizer
- Qt Designer
# Risorse
- [Lezioni su qt di Marco Zanella](https://stem.elearning.unipd.it/course/view.php?id=10189#section-4)
- [Documentazione ufficiale Qt](https://doc.qt.io/)
- [Libro Mastering Qt5](https://mega.nz/fm/6ddFjQAT)
- [Libro Introduction to Design Patterns in Qt](https://mega.nz/fm/6ddFjQAT)
# Overview struttura
## Modello Logico
Il prgetto si sviluppa a partire da una classe virtuale AbstractItem, che rappresenta un qualunque oggetto multimediale presente nella libreria, da questa classe ereditano 5 classi: Album, Book, Comic, Movie e Videogame, ognuna con dei campi dati specifici.
Successivamente abbiamo implementato una classe Library, che presenta una lista di puntatori ad AbstractItem e dei metodi per aggiungere ed eliminare un elemento e restituire il riferimento alla lista. Inoltre la libreria si occupa dell'inizializzazione dei processi di salvataggio e apertura di file Json/Xml, con dei metodi appositi che preparano il file e chiamano un tra i metodi JsonReader/XmlReader oppure uno tra i metodi JsonWriter/Xmlwriter.
### Punto interessante:
Per fare in modo che la libreria fosse univoca durante tutta l'esecuzione del programma abbiamo implementato un pattern singleton, fornendo dunque a chiunque richiedesse l'accesso alla libreria un metodo getInstance() che restituisce un riferimento all'unica istanza della libreria. Abbiamo disabilitato il costruttore di copia e quello di assegnazione.

## Gestione file Json e Xml
### Lettura da file
Per leggere da file json/xml abbiamo implementato due classi JsonReader e XmlReader, ognuna con 5 metodi per le 5 classi derivate, questi metodi leggono il file aspettandosi di trovare i campi dati corretti a seconda dell'oggetto e costruiscono un oggetto della classe adeguata per ogni oggetto trovato nel file, restituendo un puntatore ad un oggetto del tipo concreto corretto, che viene poi aggiunto alla lista della classe Library tramite il metodo fromJson/fromXml (sempre della classe Libary).
### Scrittura su file
Per scrivere da file json/xml abbiamo implementato l'utilizzo del pattern visitor, dunque una classe JsonWriter/XmlWriter avrà un metodo writeJson/writeXml che scorrerà ogni oggetto nella lista della Libreria e, tramite il metodo accept del rispettivo JsonVisitor/XmlVisitor andrà a scrivere sul file json/xml tramite il metodo corretto a seconda del tipo concreto dell'oggetto.
