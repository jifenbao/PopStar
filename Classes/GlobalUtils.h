#ifndef GLOBALUTILS_H
#define GLOBALUTILS_H

class GlobalUtils
{
public:
	static const int g_groundHeight = 57;
	static const int g_runnerStartX = 80;
	static const int g_MAX_LONG = 4294967295;

    enum TagOfLayer
    {
        background = 0,
        Animation,
        Status

    };

    enum SpriteTag
    {
        runner = 0,
        coin,
        rock
    };
};


#endif
