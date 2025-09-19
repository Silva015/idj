#ifndef TILESET_H
#define TILESET_H
#include "Sprite.h"
#include <string>

using namespace std;

class TileSet {
public:
    TileSet(int tileWidth, int tileHeight, const string &file);

    void RenderTile(unsigned index, float x, float y);

    int GetTileWidth() const;

    int GetTileHeight() const;

private:
    Sprite tileSet;
    int tileWidth;
    int tileHeight;
    int tileCount;
};

#endif
