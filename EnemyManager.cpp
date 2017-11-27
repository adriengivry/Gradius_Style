#include "EnemyManager.h"

using namespace Gradius;

EnemyManager::EnemyManager(sf::RenderWindow *window)
{
    this->window = window;
    Enemy *newEnemy = new Enemy(this->window, 1280, 720);
    enemyList.push_back(*newEnemy);
}

void EnemyManager::Draw()
{
    if(enemyList.empty())
        return;
    std::list<Enemy>::iterator it = enemyList.begin();

    while (it != enemyList.end())
    {
        if(it->isActive())
            it->Draw();
        ++it;
    }
}

void EnemyManager::Update(float deltaTime)
{
    if(enemyList.empty())
        return;
    std::list<Enemy>::iterator it = enemyList.begin();

    while (it != enemyList.end())
    {
        if(it->isActive())
            it->Update(deltaTime);
        ++it;
    }
}

sf::Vector2f* EnemyManager::getEnemyPosition()
{
	return this->enemyList.front().getEnemyPosition();
}

void EnemyManager::Randomize()
{
	for(auto it = this->enemyList.begin(); it != this->enemyList.end(); ++it)
	{
		it->Randomize();
	}
}
