#include "Pipe.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

Pipe::Pipe(const sf::Texture& texture) : pipeTexture(&texture) {
    topPipe.setTexture(*pipeTexture);
    bottomPipe.setTexture(*pipeTexture);
    // pipeSprite.setScale(70.f, 70.f);
    topPipe.setScale(1.f, -1.f);
    bottomPipe.setScale(1.f, 2.f);
    float centerY = 200.f + std::rand() % 150;  // Random gap center
                                                // float pipeHeight = *pipeTexture.getSize().y;

    topPipe.setPosition(700.f, centerY - gap / 2.f);
    bottomPipe.setPosition(700.f, centerY + gap / 2.f);
}

void Pipe::Draw(sf::RenderWindow& window) const {
    window.draw(topPipe);
    window.draw(bottomPipe);
}

void Pipe::update(float dt) {
    float dx = speed * dt;
    topPipe.move(-dx, 0);
    bottomPipe.move(-dx, 0);
}

bool Pipe::isOffScreen() const {
    return topPipe.getPosition().x + topPipe.getGlobalBounds().width < 0;
}
bool Pipe::checkColision(const sf::FloatRect& otherBounds) const
{
     return topPipe.getGlobalBounds().intersects(otherBounds) || bottomPipe.getGlobalBounds().intersects(otherBounds);
}
