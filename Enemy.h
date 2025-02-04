#ifndef GRADIUS_ENEMY_H
#define GRADIUS_ENEMY_H

#include <SFML/Graphics.hpp>

namespace Gradius
{
    class Enemy
    {
    public:
        Enemy(sf::RenderWindow& window);
        ~Enemy(){}
        void Draw() const;
        void Update(float deltaTime);
        bool isActive();
        void Activate();
        void Randomize();
		const sf::Vector2f& getPosition() const;

    private:
        bool active;
        float x;
        float wavePeriod;
        float waveAmplitude;
        float mouvementSpeed;
        sf::RenderWindow& window;
        sf::Vector2f position;
        sf::Vector2f screenLimit;
        sf::Texture enemyTexture;
        sf::Sprite enemySprite;
    };
}

#endif //GRADIUS_ENEMY_H
