/* 
* Game namespace, contains.. 
*
* Player obj, 
* enemy obj,
* projectile obj ...
* 
*/

#include "raylib.h"
#include "declare.h"
#include <cstdio>


bool Game::pause = false;
bool Game::over = false;
unsigned short Game::score = 0;


Game::Sprite::Sprite( Vector2 pos, float radius, Vector2 vel, Color color )
{
	
	this->pos = pos;
	this->vel = vel;
	this->radius = radius;
	this->color = color;
	this->lastUpdatedTime = 0;
}

void Game::Sprite::draw()
{

		DrawCircle( this->pos.x, this->pos.y, this->radius, this-> color );
}

void Game::Sprite::update( void )
{

	this->draw();
	this->pos.x += this->vel.x;
	this->pos.y += this->vel.y;
}

bool Game::Sprite::IsOffScreen( int screenX, int screenY )
{

	return(
		this->pos.x < 0 || this->pos.x > screenX
		|| this->pos.y < 0 || this->pos.y > screenY );
}


//Random values between 0 and 1 generation to build random circlar enemies.
static std::default_random_engine e;
static std::uniform_real_distribution<double> RAND(0, 1);

void Game::spawnEnemies(std::vector< Game::Sprite >& enemies)
{
	Vector2 pos;

	if ( RAND(e) < .5 ) 
	{
		pos.x = RAND(e) < .5 ? 0 : (float)screenX;
		pos.y = RAND(e) * screenY;
	}
	else 
	{
		pos.x = RAND(e) * screenX;
		pos.y = RAND(e) < .5 ? 0 : (float)screenX;
	}

	double angle = atan2( (float)screenY / 2 - pos.y,
						  (float)screenX / 2 - pos.x);

	Vector2 vel
	{
		(float)cos(angle) * 4,
		(float)sin(angle) * 4
	};


	enemies.push_back(
		Game::Sprite( pos,
					 RAND(e) * (50 - 10) + 10,
					 vel,
					 Color{ 255,0,0,255 } ));
}


void Game::displayScore(unsigned short& score) 
{

	Vector2 fontSize = MeasureTextEx(Game::font, "My Score :", 25.0f, 1.0f);
	DrawTextEx( Game::font, "My Score :", Vector2{15.0f, 15.0f}, 25.0f, 1.0f, Color{0,0,255,255} );

	char buffer[4];
	sprintf(buffer, "%3d", score );

	DrawTextEx
	(
		Game::font,
		buffer, 
		Vector2
		{
			(float)(15 + fontSize.x + 5),
			15.0f
		},
		25,
		1.0f,
		Color{255,255,255,255}
	);	
}


Game::Health::Health( const char* imagePath, Vector2 pos, float scale, unsigned short value )
{
	this->imagePath = imagePath;
	this->scale = scale;
	this->pos = pos;
	this->value = value;

	this->image = LoadImage( imagePath );
	this->texture = LoadTextureFromImage(image);
	UnloadImage(this->image);
}

Game::Health::~Health()
{
	UnloadTexture(this->texture);
}

void Game::Health::draw() 
{
	//Player's health texture component.
	DrawTextureEx
	(
		this->texture, 
		this->pos,
		.0f,
		this->scale,
		Color{255,255,255,255} 
	);
}


void Game::displayHealth(unsigned short& health) 
{
	//Player's health numeric value displayer
	char buffer[4];
	sprintf(buffer, "%3d", health);

	DrawTextEx
	(
		Game::font,
		buffer,
		Vector2
		{
			(float)screenX - 110.0f,
			15.0f
		},
		25,
		1.0f,
		Color{ 255,255,255,255 }
	);

	}
