#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Globals.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird");
    Game game(window);
    game.startGameLoop();

    window.close();
}