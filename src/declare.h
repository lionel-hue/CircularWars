#ifndef DECLARE_H
#define DECLARE_H

#include "./raylib/raylib.h"
#include <vector>
#include <random>


extern unsigned short screenX;
extern unsigned short screenY;



namespace Tools 
{
    class Interval
    {
        public:
            double lastUpdatedTime;
            double currentTime;

            Interval(void);
            bool set(double);      
    };

    class Timeout : public Interval
    {
        private:
            bool stop;

        public:
            Timeout(void);
            bool set(float);
            void reset(void);
    };
}



namespace Game
{
    extern bool pause;
    extern bool over;
    extern unsigned short score;
    extern unsigned short health;
    extern Font font;

    class Sprite
    {
        public:    
            Vector2 pos;
            float radius;
            Vector2 vel;
            Color color;
            bool IsOffScreen( int, int );
            double lastUpdatedTime;

            Sprite( Vector2, float, Vector2, Color );
            void draw( void );
            void update( void );
    };

    void spawnEnemies( std::vector<Sprite>& );

    void displayScore(unsigned short&);


    class Health
    {
        public:
            Image image;
            Texture2D texture;
            const char* imagePath;
            Vector2 pos;
            float scale;
            unsigned short value;

            Health( const char*, Vector2, float, unsigned short );
            ~Health();
            void draw( void );
    };

    void displayHealth(unsigned short&);


}
#endif