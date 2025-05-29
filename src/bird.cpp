#include "Bird.hpp"

#include <iostream>

#include "Globals.hpp"

Bird::Bird() : velocityY(0.f) {
    std::vector<std::string> framePaths = {"assets/bird1.png", "assets/bird2.png",
                                           "assets/bird3.png"};

    for (const auto& path : framePaths) {
        sf::Texture bird_texture;
        if (!bird_texture.loadFromFile(path)) {
            std::cerr << "Failed to load " << path << std::endl;
            exit(1);
        }
        bird_frames.push_back(bird_texture);
    }

    bird_sprite.setTexture(bird_frames[0]);
    bird_sprite.setScale(SET_SCALE_BIRD_X, SET_SCALE_BIRD_Y);
    bird_sprite.setPosition(0.f, 15.f);
}

void Bird::draw(sf::RenderWindow& window) const { window.draw(bird_sprite); }

void Bird::update(float dt) {
    velocityY += gravity * dt;
    bird_sprite.move(0.f, velocityY * dt);

    animationTimer += dt;

    if (animationTimer >= frameDuration) {
        animationTimer = 0.f;
        // circlur implementaion of array
        currentFrame = (currentFrame + 1) % bird_frames.size();

        bird_sprite.setTexture(bird_frames[currentFrame]);
    }
}
void Bird::jump() { velocityY = jumpStrength; }

const sf::Sprite& Bird::getBirdSprite() const { return bird_sprite; }