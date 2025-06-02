#pragma once
#include <SFML/Graphics.hpp>

#include "Bird.hpp"
#include "Pipe.hpp"

class Game {
   private:
    std::vector<Pipe> pipes;
    float spawnTimer = 0.f;
    float spawnInterval = 2.0f;
    sf::RenderWindow& win;
    sf::Texture bg_texture;
    sf::Sprite bg_sprites[2];
    sf::Texture pipeTexture;

    Bird bird;
    Pipe pipe(const sf::Texture& pipeTexture);
    float scrollSpeed;

   public:
    Game(sf::RenderWindow& window);

    // To draw entities
    void draw();
    // Game loop
    void startGameLoop();

    void updateBackground(float dt);
};