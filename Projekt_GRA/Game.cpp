#include "Game.h"

void Game::initVariables()
{
	this->endGame = true;
	this->startGame = false;
	this->action = 0;
	this->zero_one = 0;
	this->count = 1;
	this->change = 0.0f;
	this->points = 0;
	this->ent = 0;
	this->etimermax = 125.f;
	this->etimer = etimermax;
	this->minutes = 0;
	this->pos = 0;
	this->space = -5.0f;
	this->atimer = 0.0f;
	this->atimermax = 15.0f;
	this->jumpmax = 150.0f;
	this->jumpmove = -3.5f;
}

void Game::initWindow()
{

	this->resolution.height = 1080;
	this->resolution.width = 1920;
	this->window = new sf::RenderWindow(this->resolution, "Trojan", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	if (!this->icon.loadFromFile("./graphics/icon.jpg")) {
		std::cout << "ERROR: nie mozna zaladowac ikonki";
	}
	this->window->setIcon(200, 200, icon.getPixelsPtr());
	this->window->setFramerateLimit(120);
}

void Game::initEntities()
{
	if (!this->TextureOfEntity[0].loadFromFile("./graphics/tree.png")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury drzewa";
	}
	if (!this->TextureOfEntity[1].loadFromFile("./graphics/bugcut.png")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury robaka";
	}
	if (!this->TextureOfEntity[2].loadFromFile("./graphics/bird.png")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury ptaka";
	}
	this->Entity[0].setTexture(this->TextureOfEntity[0]);
	this->Entity[1].setTexture(this->TextureOfEntity[1]);
	this->Entity[2].setTexture(this->TextureOfEntity[2]);
}

void Game::initHitboxes()
{
	if (!this->TextureOfHitboxes[0].loadFromFile("./graphics/hitbox1.png")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury hitboxu drwala";
	}
	if (!this->TextureOfHitboxes[1].loadFromFile("./graphics/hitbox2.png")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury hitboxu drwala";
	}
	if (!this->TextureOfHitboxes[2].loadFromFile("./graphics/timbermaninaction.png")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury hitboxu drwala";
	}
	if (!this->TextureOfHitboxes[3].loadFromFile("./graphics/timbermancrouch.png")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury hitboxu drwala";
	}
	this->Hitboxes[0].setTexture(TextureOfHitboxes[0]);
	this->Hitboxes[0].setPosition(50, this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfHitboxes[0].getSize().y);
	this->Hitboxes[1].setTexture(TextureOfHitboxes[1]);
	this->Hitboxes[1].setPosition(50+54, this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfHitboxes[1].getSize().y);
	this->Hitboxes[2].setTexture(TextureOfHitboxes[2]);
	this->Hitboxes[2].setPosition(50, this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfHitboxes[2].getSize().y);
	this->Hitboxes[3].setTexture(TextureOfHitboxes[3]);
	this->Hitboxes[3].setPosition(50, this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfHitboxes[3].getSize().y);
}

void Game::initBackground()
{
	//switch (this->change) {
	//case 1:
	//	if (!this->TextureOfBackground[1].loadFromFile("./graphics/1920backgroundXP2.jpg")) {
	//		std::cout << "ERROR: nie mozna zaladowac tekstury tla";
	//	}
	//	//std::cout << "1";
	//	break;
	//case 2:
	//	if (!this->TextureOfBackground[1].loadFromFile("./graphics/1920backgroundXP3.jpg")) {
	//		std::cout << "ERROR: nie mozna zaladowac tekstury tla";
	//	}
	//	//std::cout << "2";
	//	break;
	//default:
	//	if (!this->TextureOfBackground[1].loadFromFile("./graphics/1920backgroundXP.jpg")) {
	//		std::cout << "ERROR: nie mozna zaladowac tekstury tla";
	//	}
	//	this->change = 0;
	//}
	//this->change++;
	if (!this->TextureOfBackground[1].loadFromFile("./graphics/1920backgroundXP.jpg")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury tla";
	}
	this->background[1].setTexture(this->TextureOfBackground[1]);
	this->background[1].setOrigin(0, 0);
	if (!this->TextureOfBackground[3].loadFromFile("./graphics/thefloor.png")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury tla";
	}

	this->background[3].setTexture(this->TextureOfBackground[3]);
	this->background[3].setPosition(0, this->resolution.height-this->TextureOfBackground[3].getSize().y);
	if (!this->TextureOfBackground[5].loadFromFile("./graphics/thegrass.png")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury tla";
	}
	this->background[4].setTexture(this->TextureOfBackground[5]);
	this->background[4].setPosition(0, this->resolution.height - this->TextureOfBackground[3].getSize().y- this->TextureOfBackground[5].getSize().y);
}

void Game::initMenu()
{
	this->TextureOfButtons[0].loadFromFile("./graphics/start2.png");
	this->TextureOfButtons[1].loadFromFile("./graphics/start1.png");
	this->TextureOfButtons[2].loadFromFile("./graphics/wyjscie2.png");
	this->TextureOfButtons[3].loadFromFile("./graphics/wyjscie1.png");
	this->buttons[0].setTexture(this->TextureOfButtons[0]);
	this->buttons[0].setPosition((this->resolution.width - this->TextureOfButtons[0].getSize().x)/2, this->resolution.height / 2 - 150);
	this->buttons[1].setTexture(this->TextureOfButtons[2]);
	this->buttons[1].setPosition((this->resolution.width - this->TextureOfButtons[0].getSize().x)/2, this->resolution.height / 2);

}

void Game::initEndMenu()
{
	this->TextureOfBackground[2].loadFromFile("./graphics/GameOver.png");
	this->background[2].setTexture(this->TextureOfBackground[2]);
	this->TextureOfButtons[4].loadFromFile("./graphics/restart2.png");
	this->TextureOfButtons[5].loadFromFile("./graphics/restart1.png");
	this->buttons[2].setTexture(this->TextureOfButtons[4]);
	this->buttons[2].setPosition((this->resolution.width - this->TextureOfButtons[0].getSize().x)/2, this->resolution.height / 2);
	this->buttons[3].setTexture(this->TextureOfButtons[2]);
	this->buttons[3].setPosition((this->resolution.width - this->TextureOfButtons[0].getSize().x)/2, this->resolution.height / 2 + 150);
}

void Game::initFont()
{
	this->font.loadFromFile("./fonts/Arial.ttf");
}

void Game::initText()
{
	//timer
	this->text[0].setFont(font);
	this->text[0].setCharacterSize(48);
	this->text[0].Bold;
	this->text[0].setFillColor(sf::Color::Black);
	this->text[0].setPosition(0, 0);
	//score
	this->text[1].setFont(font);
	this->text[1].setCharacterSize(48);
	this->text[1].Bold;
	this->text[1].setFillColor(sf::Color::Color(196, 180, 84));
	this->text[1].setOutlineColor(sf::Color::Black);
	this->text[1].setPosition(0, 50);
	//end menu timer
	this->text[2].setFont(font);
	this->text[2].setCharacterSize(50);
	this->text[2].Bold;
	this->text[2].setFillColor(sf::Color::Yellow);
	this->text[2].setPosition(this->resolution.width/2-375,this->resolution.height/2-100);
}

void Game::Start()
{
	this->initVariables();
	this->endGame = false;
	this->startGame = true;
	this->time = clock.restart();
}

void Game::Death()
{
	this->endGame = true;
	this->startGame = true;
}

void Game::initCharacter(unsigned char i)
{
	if (!this->TextureOfCharacter[0].loadFromFile("./graphics/timberman1test.png")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury drwala";
	}
	if (!this->TextureOfCharacter[1].loadFromFile("./graphics/timberman2test.png")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury drwala";
	}
	if (!this->TextureOfCharacter[2].loadFromFile("./graphics/timbermantest.png")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury drwala";
	}
	if (!this->TextureOfCharacter[3].loadFromFile("./graphics/timbermaninaction.png")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury drwala";
	}
	if (!this->TextureOfCharacter[4].loadFromFile("./graphics/timbermancrouch.png")) {
		std::cout << "ERROR: nie mozna zaladowac tekstury drwala";
	}
	this->Character.setTexture(TextureOfCharacter[i]);
}


//konstruktor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initBackground();
	this->initCharacter(2);
	this->initHitboxes();
	this->initEntities();
	this->initFont();
	this->initText();
	this->initMenu();
	this->initEndMenu();
}

//destruktor
Game::~Game()
{
	delete this->window;
}

//tester
const bool Game::running() const
{
	return this->window->isOpen();
}


void Game::SpawnEntities(unsigned char i)
{
	this->pos = rand() % 2 + 1;
	switch (pos) {
		case 1:
			pos = 250;
			break;
		case 2:
			pos = 200;
			break;
		case 3:
			pos = 125;
			break;
	}
	this->Entity[0].setPosition(this->resolution.width, this->resolution.height - (this->TextureOfBackground[3].getSize().y + this->TextureOfEntity[0].getSize().y ));
	this->Entity[1].setPosition(this->resolution.width, this->resolution.height - (this->TextureOfBackground[3].getSize().y + this->TextureOfEntity[1].getSize().y ));
	this->Entity[2].setPosition(this->resolution.width, this->resolution.height - (this->TextureOfBackground[3].getSize().y + this->TextureOfEntity[2].getSize().y + pos));

	this->Entities.push_back(this->Entity[i]);
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			//if (this->event.key.code == sf::Keyboard::Delete)
			//	this->initBackground();
			//if (this->event.key.code == sf::Keyboard::Up) {
			//	this->endGame = true;
			//	this->startGame = false;
			//}
			//if (this->event.key.code == sf::Keyboard::Down) {
			//	this->endGame = true;
			//	this->startGame = true;
			//}
			//if (this->event.key.code == sf::Keyboard::Enter) {
			//	this->endGame = false;
			//	this->startGame = true;
			//}
			if (this->event.key.code == sf::Keyboard::S || this->event.key.code == sf::Keyboard::Down) {
				//this->action = 1;
				//this->initCharacter(3);
				this->action = 1;
				this->initCharacter(4);
			}
			if (this->event.key.code == sf::Keyboard::W || this->event.key.code == sf::Keyboard::Up) {
				//this->action = 1;
				//this->initCharacter(3);
				this->action = 1;
				this->initCharacter(2);
			}
			break;
		case sf::Event::KeyReleased:
			if (this->event.key.code == sf::Keyboard::Space) {
				this->action = 1;
				this->initCharacter(3);
				/*this->action = 0;
				this->initCharacter(1);*/
				this->Character.setPosition(50, this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfCharacter[3].getSize().y);
			}
			if (this->event.key.code == sf::Keyboard::S || this->event.key.code == sf::Keyboard::Down) {
				this->action = 0;
				this->initCharacter(1);
				//this->Character.setPosition(50, this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfCharacter[3].getSize().y);
			}
		break;
		}
	}
}


std::string Game::updateTimer()
{
	std::string t = "";
	this->time = clock.getElapsedTime();
	if (static_cast<int>(this->time.asSeconds()) >= 60) {
		this->minutes += 1;
		this->time = clock.restart();
		this->count = 1;
	}
	if (this->minutes <= 9) {
		t += std::to_string(this->minutes)+":";
	}
	else {
		t += std::to_string(this->minutes) + ":";
	}
	if (static_cast<int>(this->time.asSeconds()) <= 9) {
		t += "0"+std::to_string(static_cast<int>(this->time.asSeconds())) + ":";
	}
	else {
		t += std::to_string(static_cast<int>(this->time.asSeconds())) + ":";
	}
	if ((this->time.asMilliseconds() % 1000 / 10) <= 9) {
		t += "0" + std::to_string(this->time.asMilliseconds() % 1000 / 10);
	}
	else {
		t += std::to_string(this->time.asMilliseconds() % 1000 / 10);
	}
	return t;
}

void Game::updateDifficulty()
{
	if (static_cast<int>(this->time.asSeconds())/this->count>=5) {
		this->space -= 0.5f;
		this->etimermax -= 2.5f;
		this->count++;
		std::cout << "Speed changes: " << this->space<<" per tick\n";
		std::cout << "Max time changes: " << this->etimermax << "\n";
		//std::cout << this->Character.getGlobalBounds().getPosition().x << " " << this->Character.getGlobalBounds().getPosition().y<<"\n";
	}
}

void Game::updateText()
{
	//std::cout << updateTimer()+"\n";;
	this->text[0].setString("Time: "+ this->updateTimer());
	this->text[1].setString("Score: " + std::to_string(this->points));
}
void Game::updateEntities()
{
	this->ent = rand() % 3;
	/*if (this->Entities.size() < this->maxentities) {*/
		if (this->etimer >= this->etimermax) {
			this->SpawnEntities(ent);
			this->etimer = 0.f+rand()%25;
		}
		else {
			this->etimer+= 1.f;
		}
	/*}*/

	for (int i = 0; i < this->Entities.size(); i++) {
		this->Entities[i].move(this->space, 0);
		if (this->Entities[i].getPosition().x+this->Entities[i].getGlobalBounds().getSize().x <= 0) {
			this->Entities.erase(this->Entities.begin() + i);
		}
		if (!this->action) {
			if (this->Entities[i].getGlobalBounds().intersects(this->Hitboxes[0].getGlobalBounds()) || this->Entities[i].getGlobalBounds().intersects(this->Hitboxes[1].getGlobalBounds())) {
				if (this->Entities[i].getTexture() == &this->TextureOfEntity[0]) {
					if (this->Hitboxes[1].getGlobalBounds().contains(this->Entities[i].getGlobalBounds().getPosition().x + 189, this->Entities[i].getGlobalBounds().getPosition().y + 525)) {
						//this->Entities.erase(this->Entities.begin() + i);
						Death();
					}
				}
				else {
					//this->Entities.erase(this->Entities.begin() + i);
					Death();
				}
			}
		}
		else {
			if (this->Character.getTexture() == &this->TextureOfCharacter[3]) {
				if (this->Entities[i].getGlobalBounds().intersects(this->Hitboxes[2].getGlobalBounds())) {
					if (this->Entities[i].getTexture() == &this->TextureOfEntity[0]) {
						if (this->Hitboxes[2].getGlobalBounds().contains(this->Entities[i].getGlobalBounds().getPosition().x + 189, this->Entities[i].getGlobalBounds().getPosition().y + 525)) {
							this->Entities.erase(this->Entities.begin() + i);
							this->points += 1;
						}
					}
					else {
						//this->Entities.erase(this->Entities.begin() + i);
						Death();
					}
				}
			}
			else if(this->Character.getTexture() ==&this->TextureOfCharacter[2]){
				if (this->Entities[i].getGlobalBounds().intersects(this->Hitboxes[1].getGlobalBounds()) || this->Entities[i].getGlobalBounds().intersects(this->Hitboxes[0].getGlobalBounds())) {
					if (this->Entities[i].getTexture() == &this->TextureOfEntity[0]) {
						if (this->Hitboxes[1].getGlobalBounds().contains(this->Entities[i].getGlobalBounds().getPosition().x + 189, this->Entities[i].getGlobalBounds().getPosition().y + 500) || this->Hitboxes[0].getGlobalBounds().contains(this->Entities[i].getGlobalBounds().getPosition().x + 189, this->Entities[i].getGlobalBounds().getPosition().y + 525)) {
							Death();
						}
					}
					else {
						//this->Entities.erase(this->Entities.begin() + i);
						Death();
					}
				}
			}
			else {
				if (this->Entities[i].getGlobalBounds().intersects(this->Hitboxes[3].getGlobalBounds())) {
					if (this->Entities[i].getTexture() == &this->TextureOfEntity[0]) {
						if (this->Hitboxes[3].getGlobalBounds().contains(this->Entities[i].getGlobalBounds().getPosition().x + 189, this->Entities[i].getGlobalBounds().getPosition().y + 525)) {
							Death();
						}
					}
					else {
						//this->Entities.erase(this->Entities.begin() + i);
						Death();
					}
				}
			}
		}
			/*if (this->Entities[i].getGlobalBounds().contains()) {
				this->Entities.erase(this->Entities.begin() + i);
			}*/
	}
}

void Game::updateCharacter()
{
	if (!this->action) {
		if (this->change > 35.0f) {
			this->initCharacter(this->zero_one);
			if (this->zero_one >= 1) {
				this->zero_one = 0;
			}
			else {
				this->zero_one += 1;
			}
			this->change = 0.0f;
		}
		else {
			this->change += 1.0f;
		}
		this->Character.setPosition(50, this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfCharacter[0].getSize().y);
		this->Hitboxes[0].setPosition(50, this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfHitboxes[0].getSize().y);
		this->Hitboxes[1].setPosition(50 + 54, this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfHitboxes[1].getSize().y);
	}
	else {
		if (this->Character.getTexture() == &this->TextureOfCharacter[3]) {
			this->Character.setPosition(50, this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfCharacter[3].getSize().y);
			if (this->atimer >= this->atimermax) {
				this->Character.setPosition(50, this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfCharacter[0].getSize().y);
				this->initCharacter(1);
				this->action = 0;
				this->atimer = 0.0f;
			}
			this->atimer += 1.0f;
		}
		else if (this->Character.getTexture() == &this->TextureOfCharacter[2]) {
			if (this->Character.getPosition().y <= this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfCharacter[2].getSize().y) {
				this->Character.move(0, this->jumpmove);
				this->Hitboxes[0].move(0, this->jumpmove);
				this->Hitboxes[1].move(0, this->jumpmove);
				if (this->Character.getPosition().y <= this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfCharacter[2].getSize().y - this->jumpmax) {
					this->jumpmove = -this->jumpmove;
				}
			}
			else {
				this->action = 0;
				this->jumpmove = -this->jumpmove;
			}
		}
		else if (this->Character.getTexture()== &this->TextureOfCharacter[4]) {
			this->Character.setPosition(50, this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfCharacter[4].getSize().y);
			this->Hitboxes[0].setPosition(50, this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfHitboxes[0].getSize().y);
			this->Hitboxes[1].setPosition(50 + 54, this->resolution.height - this->TextureOfBackground[3].getSize().y - this->TextureOfHitboxes[1].getSize().y);
		}
	}
}


void Game::updateMousePosition()
{
	this->mousePos = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePos);
}

void Game::updateMenu()
{
	if (!this->startGame) {
		//Start button
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
			if (this->buttons[0].getGlobalBounds().contains(this->mousePosView)) {
				Start();
			}
		}
		if (this->buttons[0].getGlobalBounds().contains(this->mousePosView)) {
			this->buttons[0].setTexture(this->TextureOfButtons[1]);
		}
		else {
			this->buttons[0].setTexture(this->TextureOfButtons[0]);
		}

		//Quit Button
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
			if (this->buttons[1].getGlobalBounds().contains(this->mousePosView)) {
				this->window->close();
			}
		}
		if (this->buttons[1].getGlobalBounds().contains(this->mousePosView)) {
			this->buttons[1].setTexture(this->TextureOfButtons[3]);
		}
		else {
			this->buttons[1].setTexture(this->TextureOfButtons[2]);
		}
	}
	else {
		//Restart button
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
			if (this->buttons[2].getGlobalBounds().contains(this->mousePosView)) {
				Start();
			}
		}
		if (this->buttons[2].getGlobalBounds().contains(this->mousePosView)) {
			this->buttons[2].setTexture(this->TextureOfButtons[5]);
		}
		else {
			this->buttons[2].setTexture(this->TextureOfButtons[4]);
		}

		//Quit Button
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
			if (this->buttons[3].getGlobalBounds().contains(this->mousePosView)) {
				this->window->close();
			}
		}
		if (this->buttons[3].getGlobalBounds().contains(this->mousePosView)) {
			this->buttons[3].setTexture(this->TextureOfButtons[3]);
		}
		else {
			this->buttons[3].setTexture(this->TextureOfButtons[2]);
		}
	}
}

void Game::update()
{
	this->pollEvents();
	if (!this->endGame) {
		this->updateTimer();
		this->updateEntities();
		this->updateText();
		this->updateDifficulty();
		this->updateCharacter();
	}
	else {
		this->time = clock.restart();
		this->updateMousePosition();
		this->updateMenu();
	}
}

void Game::renderMenu(sf::RenderTarget& target)
{
	//target.draw(this->background[0]);
	target.draw(this->buttons[0]);
	target.draw(this->buttons[1]);
}

void Game::renderEndMenu(sf::RenderTarget& target)
{
	for (int i = 0; i < this->Entities.size(); i++) {
		this->Entities.erase(this->Entities.begin() + i);
	}
	this->text[2].setString(this->text[0].getString()+"\t\t\t" + this->text[1].getString());
	target.draw(this->background[2]);
	target.draw(this->buttons[2]);
	target.draw(this->buttons[3]);
	target.draw(this->text[2]);
}

void Game::renderScoreboard(sf::RenderTarget& target)
{
	target.draw(this->text[0]);
	target.draw(this->text[1]);
}

void Game::renderBackground(sf::RenderTarget& target)
{
	target.draw(this->background[1]);
	target.draw(this->background[3]);
}

void Game::renderEntities(sf::RenderTarget& target)
{
	for (auto& en : this->Entities) {
		target.draw(en);
	}
}

void Game::renderCharacter(sf::RenderTarget& target)
{
	target.draw(this->Character);
	//target.draw(this->Hitboxes[0]);
	//target.draw(this->Hitboxes[1]);
}

void Game::renderGrass(sf::RenderTarget& target)
{
	target.draw(this->background[4]);
}

void Game::render()
{
	this->window->clear(sf::Color(0,0,0,255));
	if (!endGame) {
		this->renderBackground(*this->window);
		this->renderEntities(*this->window);
		this->renderScoreboard(*this->window);
		this->renderCharacter(*this->window);
		this->renderGrass(*this->window);
	}
	else {
		if (!this->startGame) {
			this->renderMenu(*this->window);
		}
		else {
			this->renderEndMenu(*this->window);
		}
	}

	this->window->display();
}
