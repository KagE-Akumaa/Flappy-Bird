#include "Game.hpp"

#include <iostream>

#include "Bird.hpp"
#include "Globals.hpp"

Game::Game(sf::RenderWindow& window) : win(window), scrollSpeed(100.f) {
    if (!pipeTexture.loadFromFile("assets/pipe.png")) {
        std::cerr << "Error loading the file" << std::endl;
    }
    if (!bg_texture.loadFromFile("assets/background-day.png")) {
        std::cerr << "Failed to load background.png\n";
        exit(1);
    }
    for (int i = 0; i < 2; ++i) {
        bg_sprites[i].setTexture(bg_texture);
        bg_sprites[i].setScale(SET_SCALE_BACK_X, SET_SCALE_BACK_Y);
        bg_sprites[i].setPosition(i * bg_texture.getSize().x * SET_SCALE_BACK_X, 0.f);
    }
}
void Game::updateBackground(float dt) {
    float moveAmount = scrollSpeed * dt;

    for (int i = 0; i < 2; ++i) {
        bg_sprites[i].move(-moveAmount, 0.f);
    }

    float bgWidth = bg_texture.getSize().x * SET_SCALE_BACK_X;

    for (int i = 0; i < 2; ++i) {
        if (bg_sprites[i].getPosition().x + bgWidth < 0) {
            // circular array logic
            int j = (i + 1) % 2;
            bg_sprites[i].setPosition(bg_sprites[j].getPosition().x + bgWidth, 0.f);
        }
    }
}

void Game::startGameLoop() {
    sf::Clock clock;

    while (win.isOpen()) {
        float dt = clock.restart().asSeconds();
        sf::Event event;
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                bird.jump();
            }
        }
        bird.update(dt);
        updateBackground(dt);
        spawnTimer += dt;

        if (spawnTimer >= spawnInterval) {
            pipes.emplace_back(Pipe(pipeTexture));
            spawnTimer = 0.f;
        }

        for (auto& pipe : pipes) {
            pipe.update(dt);
        }
        pipes.erase(std::remove_if(pipes.begin(), pipes.end(),
                                   [](const Pipe& p) { return p.isOffScreen(); }),
                    pipes.end());

        // check collision
        for (const auto& pipe : pipes) {
            if (pipe.checkColision(bird.getBounds())) {
                std::cout << "collison" << std::endl;
            }
        }
        win.clear();
        draw();
        win.display();
    }
}

void Game::draw() {
    win.draw(bg_sprites[0]);
    win.draw(bg_sprites[1]);
    bird.draw(win);
    for (const auto& pipe : pipes) {
        pipe.Draw(win);
    }
}