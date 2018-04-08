# Zadanie zostało wykonane na potrzeby rekrutacji.

Film prezentacyjny (może zostać odtworzony z poziomu przeglądarki): https://www.dropbox.com/s/6d39girjq5sy25d/zadanie_rekrutacyjne.mp4?dl=0 

## Serwer potrafi:
- Obsługiwać każdego klienta TCP na oddzielnym wątku
- Odczytywać informacje od klienta w formacie XML
- Łączyc się z bazą danych PostgreSQL, umożliwia tworzenie kont (wpisy w tabeli accounts), umożliwia też weryfikacje danych logowania,
jeżeli tabela accounts nie istnieje, zostanie ona utworzona w bazie "rekrutacja" (w kodzie jest prosta możliwość zmiany danych do bazy)
- Szyfrować hasła używając algorytmu Sha384

## Klient potrafi:
- Wyświetlić panel logowania
- Weryfikować postawową poprawność danych (to czy inputy są pusty, to czy hasła się zgadzają itp) bez konieczności łączenia z serwerem
- Nawiązać połączenie z serwerem, wysłać opowiednie dane w formacie XML, odebrać dane w formacie XML i wyświetlić możliwe błędy jeżeli występują
- Tworzyć konta w bazie wysyłając odpowiedni request XML do serwera
- Po zalogowaniu w przypadku odpowiednich danych, wyświetli widok na którym zanjduje się SwipeView i TabBar 
(znajdują się też w oknie logowania w trochę innej formie)

## Przykłady rozmowy server-client client-server:

### Client -> Server
```
<request type="register">
    <data login="user" password="pass" />
</request>
```

### Server -> Client
```
<response type="success">
    <info info="Account created successfully"/>
</response> 
```
