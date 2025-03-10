#include "declare.h"
#include "raylib.h"
#include <random>


Tools::Interval::Interval(void) :lastUpdatedTime(0) {}


bool Tools::Interval::set( double interval )
{
	this->currentTime = GetTime();
	if( this->currentTime - this->lastUpdatedTime >= interval )
	{
		this->lastUpdatedTime = this->currentTime;
		return true;
	} 
	return false;
}


Tools::Timeout::Timeout(void) :stop(false) {}


bool Tools::Timeout::set( float timeout )
{
	this->currentTime = GetTime();
	if( this->currentTime - this->lastUpdatedTime >= timeout && 
	!this->stop )
	{
		this->lastUpdatedTime = this->currentTime;
		this->stop = true;
		return true;
	}
	return false;
}


void Tools::Timeout::reset(void)
{
	this->stop = false;
}