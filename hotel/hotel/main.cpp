#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>

int main()
{
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
       
       //ikona parking
         sf::Texture texture6;
         if (!texture6.loadFromFile("/Users/aleksandrawitek/Documents/Projekt cpp/Projekt-cpp/hotel/hotel/logo/parking.png")) {
           std::cout << "Could not load enemy texture" << std::endl;
           return 0;
         }
         sf::Sprite parking;
         parking.setTexture(texture6);
         parking.setPosition(sf::Vector2f(a*0.7,b*0.5));
      

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
        App.draw(parking);
        App.draw(platnosc);
        App.display();
    }

    return 0;
}
