#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Game
{
private:
	//zmienne sf
	sf::RenderWindow* window;
	sf::VideoMode resolution;
	sf::Event event;
	sf::Image icon;
	sf::Time time;
	sf::Clock clock;
	sf::Text text[3];
	sf::Font font;

	//myszka
	sf::Vector2i mousePos;
	sf::Vector2f mousePosView;

	//tlo
	sf::Texture TextureOfBackground[6];
	sf::Sprite background[5];
	sf::Texture TextureOfButtons[6];
	sf::Sprite buttons[4];

	//zmienne
	bool action;
	bool zero_one;
	bool startGame;
	bool endGame;
	unsigned short points;
	float ctimer;
	float etimer;
	float etimermax;
	float space;
	float atimer;
	float atimermax;
	float jumpmax;
	float jumpmove;
	unsigned char change;
	unsigned char count;
	unsigned char ent;
	unsigned char pos;
	unsigned char minutes;

	//obiekty w grze
	std::vector<sf::Sprite> Entities;
	sf::Texture TextureOfEntity[3];
	sf::Texture TextureOfCharacter[5];
	sf::Texture TextureOfHitboxes[4];
	sf::Sprite Entity[3];
	sf::Sprite Character;
	sf::Sprite Hitboxes[4];

	//funkcje prywatne
	void initVariables();
	void initWindow();
	void initCharacter(unsigned char);
	void initEntities();
	void initHitboxes();
	void initBackground();
	void initMenu();
	void initEndMenu();
	void initFont();
	void initText();
	void Start();
	void Death();

public:
	//konstruktor i destruktor
	Game();
	virtual ~Game();

	//czy okno jest otwarte
	const bool running() const;

	//funkcje do renderowania
	void SpawnEntities(unsigned char);

	void pollEvents();
	std::string updateTimer();
	void updateDifficulty();
	void updateText();
	void updateEntities();
	void updateCharacter();
	void updateMousePosition();
	void updateMenu();
	void update();

	void renderMenu(sf::RenderTarget& target);
	void renderEndMenu(sf::RenderTarget& target);
	void renderScoreboard(sf::RenderTarget& target);
	void renderBackground(sf::RenderTarget& target);
	void renderEntities(sf::RenderTarget& target);
	void renderCharacter(sf::RenderTarget& target);
	void renderGrass(sf::RenderTarget& target);
	void render();


};

#endif
