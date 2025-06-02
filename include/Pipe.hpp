#include <SFML/Graphics.hpp>

class Pipe {
   private:
    const sf::Texture* pipeTexture;
    sf::Sprite topPipe;
    sf::Sprite bottomPipe;
    float gap = 150.f;
    float speed = 100.f;

   public:
    Pipe(const sf::Texture& texture);
    void update(float dt);
    void Draw(sf::RenderWindow& window) const;
    bool isOffScreen() const;

    bool checkColision(const sf::FloatRect& otherBounds) const;
    const sf::Sprite& getSprite() const;
};