
#include "GameMechs.h"
#include "objPos.h"

using namespace std;

class Food
{
    private:
        objPos foodPos;

    public:
        Food();
        ~Food();

        void generateFood(objPos blockOff, GameMechs board);
        objPos getFoodPos() const;

};
