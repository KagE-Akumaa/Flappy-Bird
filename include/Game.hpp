#pragma once
#include <SFML/Graphics.hpp>

#include "Bird.hpp"

class Game {
   private:
    sf::RenderWindow& win;
    sf::Texture bg_texture;
    sf::Sprite bg_sprites[2];
    Bird bird;
    float scrollSpeed;

   public:
    Game(sf::RenderWindow& window);

    // To draw entities
    void draw();
    // Game loop
    void startGameLoop();

    void updateBackground(float dt);
};