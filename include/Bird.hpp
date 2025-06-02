#pragma once
#include <SFML/Graphics.hpp>

class Bird {
   private:
    std::vector<sf::Texture> bird_frames;
    sf::Sprite bird_sprite;
    int currentFrame = 0;
    float animationTimer = 0.f;
    const float frameDuration = 0.1f;
    float velocityY;
    const float gravity = 1000.f;
    const float jumpStrength = -350.0f;
    int score = 0;

   public:
    Bird();

    void update(float dt);
    void jump();
    void reset();
    void draw(sf::RenderWindow& window) const;

    bool checkCollision(const sf::FloatRect& otherBounds);
    void increaseScore();
    int getScore() const;
    sf::FloatRect getBounds() const;

    const sf::Texture& getBirdTexture() const;
    const sf::Sprite& getBirdSprite() const;
};