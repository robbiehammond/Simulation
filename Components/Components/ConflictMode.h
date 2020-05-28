#pragma once
#include "GameMode.h"
class ConflictMode : public GameMode {
public:
	ConflictMode(sf::RenderWindow& _window, sf::Font& _font, Map _map);
	void setSpawnPoints();
	bool clickInRange(sf::RectangleShape& object);
	void getUserInput(sf::RenderWindow& window, sf::Event& event);
	void fillAr(int x, int y, Colony col);
	void spawn();
	void playGame();
private:
	sf::RenderWindow& window;
	sf::Font& font;
	Map map;
};