#define RAYGUI_IMPLEMENTATION

#include "raylib.h"
#include "raygui.h"
#include "declare.h"

#include <vector>
#include <cmath>


//Screen size   
unsigned short screenX = 1300;
unsigned short screenY = 750;


//Fonts
Font Game::font;



int main( /*int argc, char **argv*/void )
{
    // Game Window and target fps set...
    InitWindow( screenX, screenY, "Circular Wars" );
    SetTargetFPS(60);
    Game::font = LoadFont("../fonts/BAUHS93.TTF");

    InitAudioDevice();
    Sound shoot = LoadSound("../audio/laser-gun-81720.mp3");
    Sound game_over = LoadSound("../audio/game-over-deep-robotic-voice-tomas-herudek-1-1-00-03.mp3");
    Music background_music = LoadMusicStream("../audio/Warriyo - Mortals (feat. Laura Brehm).mp3");
    PlayMusicStream(background_music);  



    //Player and it's health instance, 
    // projectile array, enemy array(projectile and enemy are many ) 
    Game::Sprite player
    (
        Vector2{
            screenX / 2.0f, 
            screenY / 2.0f 
        },
        50.0f,
        Vector2{
            0,
            0
        },
        Color{ 255, 255, 255, 255 }
    );

    //Player's Health instance
    Game::Health health
    (   
        "../assets/health.png", 
        Vector2{
            (float)screenX - 150,
            15.0f,
        },
        .09f,
        100 //Max health value
    );

    //Arrays of multiple instances of game entities... 
    std::vector<Game::Sprite> projectiles;
    std::vector<Game::Sprite> enemies;
    std::vector<Tools::Interval>intervals(2);
    std::vector<Tools::Timeout>timeouts(1);


    while( !WindowShouldClose() ) 
    {
        UpdateMusicStream(background_music);
        //Game::Projectiles creation..
        if( IsMouseButtonPressed( MOUSE_RIGHT_BUTTON ) || IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) )
        {
            PlaySound(shoot);

            double angle = atan2(
            GetMouseY() - screenY/2, 
            GetMouseX() - screenX/2);

            Vector2 velocity
            { 
                (float)cos(angle)*8, 
                (float)sin(angle)*8 
            };

            projectiles.push_back( Game::Sprite( 
                Vector2{
                    screenX / 2.0f, 
                    screenY / 2.0f
                }, 
                10.0f, 
                velocity, 
                BLUE));
        }

        //Checking if projectile is off screen
        for(int i = 0; i < projectiles.size(); ++i )
        {
            if ( projectiles[i].IsOffScreen( screenX, screenY ) )
            {
                projectiles.erase( projectiles.begin() + i );
                --i;
            };
        }

        //Enemy spawning...
        intervals[0].set(1) ? 
            Game::spawnEnemies(enemies) : (void)0;


        //All windows preset set : OK, post settings in progress...
        BeginDrawing();
        ClearBackground(Color{ 0, 0, 0, 255 });
        //GuiButton(Rectangle{40,40,40,60}, "hello");
        


        if (!Game::over)
        {
            if (!Game::pause)
            {

                //Draw Score and it's current value
                Game::displayScore(Game::score);

                //Draw player...
                player.draw();

                //Draw Player's Health texture and value
                health.draw();
                Game::displayHealth(health.value);

                //Draw projectiles
                for (int i = 0; i < projectiles.size(); ++i)
                {
                    projectiles[i].update();
                }

                //Draw enemies
                for (int i = 0; i < enemies.size(); ++i)
                {
                    enemies[i].update();
                    bool removeEnemy = false;

                    //Projectile hitting enemy check...
                    for (int j = 0; j < projectiles.size(); ++j)
                    {
                        float dist = hypot(
                            projectiles[j].pos.x - enemies[i].pos.x,
                            projectiles[j].pos.y - enemies[i].pos.y);

                        if (dist - enemies[i].radius - projectiles[j].radius <= 0 )
                        {
                            projectiles.erase(projectiles.begin() + j);
                            enemies.erase(enemies.begin() + i);
                            removeEnemy = true;
                            break;
                        }

                        if (removeEnemy) break;
                    }


                    //Enemy hitting player check...
                    float dist = hypot(player.pos.x - enemies[i].pos.x,
                        player.pos.y - enemies[i].pos.y);

                    if (health.value <= 0 && dist - player.radius - enemies[i].radius <= 0 )
                    {
                        enemies.erase(enemies.begin() + i);
                        Game::over = true;
                        StopSound(shoot);
                        StopMusicStream(background_music);
                        PlaySound(game_over);
                        break;
                    }
                    else if( dist - player.radius - enemies[i].radius <= 0 )
                    {
                        enemies.erase(enemies.begin() + i);
                        if( timeouts[0].set(1.0f) )
                        {
                            health.value -= 20;
                            timeouts[0].reset();
                        } 
                    }

                }

                //Increase current score according to interval...
                intervals[1].set(.2) ?
                    Game::score++ : (unsigned short )0;
            }
        }
        else
        {
            Font font = LoadFont("../fonts/impact.ttf");
            Vector2 fontSize = MeasureTextEx(font, "Game Over!", 100.0f, 1.0f);

            DrawRectangle(
                screenX / 2 - 200,
                screenY / 2 - 90,
                400,
                180,
                Color{ 255, 255, 255, 255 }
            );

            DrawTextEx(
                font,
                "Game Over",
                Vector2
                {
                    (float)screenX / 2 - fontSize.x / 2,
                    (float)screenY / 2 - fontSize.y / 2
                },
                100.0f,
                1.0f,
                Color{ 0, 0, 0, 255 }
            );
            //TraceLog(LOG_INFO, "Game Over font Size, x : %.1f, y : %.1f", Game::fontSize.x, Game::fontSize.y);
        }
        
        EndDrawing();  
    }

    UnloadMusicStream(background_music);
    UnloadSound(shoot);
    UnloadSound(game_over);
    CloseAudioDevice();

    UnloadFont(Game::font);
    CloseWindow();
    return 0;
}