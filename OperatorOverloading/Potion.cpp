#include "raylib.h"
#include "MyHero.h"
#include <string>
using std::string;

Potion::Potion()
{
	name = "Juggernog";
	HPModifier = 2;
	quality = 5;
	useByDate = 100;
}

Potion::~Potion()
{

}