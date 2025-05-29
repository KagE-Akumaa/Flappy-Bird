#include <SFML/Graphics.hpp>

class Pipe {
   private:

   sf::Sprite pipeSprite;
   public:

   Pipe(const sf::Texture& texture);
   void update();
   void reset();

   bool checkColision(const sf::FloatRect& otherBounds) const;
   const sf::Sprite& getSprite() const;
   
};