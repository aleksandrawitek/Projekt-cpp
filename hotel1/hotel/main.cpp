#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
//#include "CheckBox.h"
//#include "AssetManager.h"
//#include "SDL_TileSheet.h"
//#include "UIManager.h"
//#include "SDL_ScreenHandeler.h"
#include <TGUI/Font.hpp>


int main()
{
    //wskaźnik na baze danych
    sqlite3* db;
    int goscie = 0;
    int rezerwacja = 0;
    int pokoje = 0;
    
    //otwarcie kazdej z baz danych
    goscie = sqlite3_open("goscie.db", &db);
    rezerwacja = sqlite3_open("rezerwacja.db", &db);
    pokoje = sqlite3_open("pokoje.db", &db);
    
    sf::String playerInput;
    sf::Text playerText;
    
    //pomocnicze zmienne na szerokość i długość ekranu
    float a;
    float b;
    
    a = sf::VideoMode::getDesktopMode().width;
    b = sf::VideoMode::getDesktopMode().height;
    
    //wygenerowanie okna dopasowanego do rozmiaru ekranu
    sf::RenderWindow App(sf::VideoMode(a, b), "System hotelowy");
    
    //dodanie ikon
    
    //ikona kartoteka
    sf::Texture texture;
    if (!texture.loadFromFile("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/hotel/hotel/logo/kartoteka.png")) {
      std::cout << "Could not load enemy texture" << std::endl;
      return 0;
    }
    sf::Sprite kartoteka;
    kartoteka.setTexture(texture);
    kartoteka.setPosition(sf::Vector2f(a/10,b/10));
    
    //ikona check in
    sf::Texture texture1;
    if (!texture1.loadFromFile("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/hotel/hotel/logo/checkin.png")) {
      std::cout << "Could not load enemy texture" << std::endl;
      return 0;
    }
    sf::Sprite checkin;
    checkin.setTexture(texture1);
    checkin.setPosition(sf::Vector2f(a*0.4,b/10));
    
    //ikona check out
      sf::Texture texture2;
      if (!texture2.loadFromFile("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/hotel/hotel/logo/checkout.png")) {
        std::cout << "Could not load enemy texture" << std::endl;
        return 0;
      }
      sf::Sprite checkout;
      checkout.setTexture(texture2);
      checkout.setPosition(sf::Vector2f(a*0.7,b/10));
    
    //ikona platnosc
       sf::Texture texture4;
       if (!texture4.loadFromFile("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/hotel/hotel/logo/platnosc.png")) {
         std::cout << "Could not load enemy texture" << std::endl;
         return 0;
       }
       sf::Sprite platnosc;
       platnosc.setTexture(texture4);
    platnosc.setPosition(sf::Vector2f(a/10,b*0.5));
       
       //ikona status
       sf::Texture texture5;
       if (!texture5.loadFromFile("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/hotel/hotel/logo/status.png")) {
         std::cout << "Could not load enemy texture" << std::endl;
         return 0;
       }
       sf::Sprite status;
       status.setTexture(texture5);
       status.setPosition(sf::Vector2f(a*0.4,b*0.5));
       
       //ikona nowa rezerwacja
         sf::Texture texture6;
         if (!texture6.loadFromFile("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/hotel/hotel/logo/nowarez.png")) {
           std::cout << "Could not load enemy texture" << std::endl;
           return 0;
         }
         sf::Sprite nowarez;
         nowarez.setTexture(texture6);
         nowarez.setPosition(sf::Vector2f(a*0.7,b*0.5));
      

    //program trwa do zamknięcia okna
    while (App.isOpen())
    {
        sf::Event event;
        while (App.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                App.close();
           
        }
        
        //zmiana koloru tła
        App.clear(sf::Color::White);
        
        //wyświetlenie ikon
        App.draw(kartoteka);
        App.draw(checkin);
        App.draw(checkout);
        App.draw(status);
        App.draw(nowarez);
        App.draw(platnosc);
        App.display();
        

    //event onclick --> zrobienie przycisków do meldowania etc.
    if (event.type == sf::Event::MouseButtonPressed)
    {
        //pozycja myszki
        auto mouse_pos = sf::Mouse::getPosition(App);
        //konwersja pozycji myszki
        auto translated_pos = App.mapPixelToCoords(mouse_pos);
        //sprawdzenie czy nasza myszka klika w przycisk kartoteka
        
        kartoteka.setColor(sf::Color::Transparent);
        checkin.setColor(sf::Color::Transparent);
        checkout.setColor(sf::Color::Transparent);
        status.setColor(sf::Color::Transparent);
        nowarez.setColor(sf::Color::Transparent);
        platnosc.setColor(sf::Color::Transparent);
        App.display();
        if(kartoteka.getGlobalBounds().contains(translated_pos))
        {
            App.setTitle("Kartoteka");
            
            //do pola tekstowego
            sf::String playerInput;
            sf::Text playerText;
            if (event.type == sf::Event::TextEntered)
            {
                playerInput +=event.text.unicode;
                playerText.setString(playerInput);
                App.setTitle("Check In");
            }
            App.draw(playerText);
            App.display();
            
        }
        else if(checkin.getGlobalBounds().contains(translated_pos))
        {
            App.setTitle("Check In");
            App.display();
            
        }
        else if(checkout.getGlobalBounds().contains(translated_pos))
        {
            App.setTitle("Check Out");
            App.display();
                
        }
        else if(status.getGlobalBounds().contains(translated_pos))
        {
            App.setTitle("Status pokoju");
            App.display();
                    
        }
        else if(nowarez.getGlobalBounds().contains(translated_pos))
        {
            App.setTitle("Nowa rezerwacja");
            App.display();
        }
        else if(platnosc.getGlobalBounds().contains(translated_pos))
        {
            App.setTitle("Płatności");
            App.display();
        }
    }
    }
    
    
    sqlite3_close(db);

    return 0;
}
