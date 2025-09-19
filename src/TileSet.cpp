#include "TileSet.h"

TileSet::TileSet(const int tileWidth, const int tileHeight, const string &file) {
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    this->tileSet = Sprite(file);
    const int cols = tileSet.GetWidth() / tileWidth;
    const int rows = tileSet.GetHeight() / tileHeight;
    this->tileCount = cols * rows;
    tileSet.SetFrameCount(cols, rows);
}

void TileSet::RenderTile(const unsigned index, const float x, const float y) {
    if (index >= tileCount) {
        fprintf(stderr, "Erro: índice de tile inválido %d\n", index);
        return;
    }

    tileSet.SetFrame(static_cast<int>(index));
    tileSet.Render(static_cast<int>(x), static_cast<int>(y), tileWidth, tileHeight);
}

int TileSet::GetTileWidth() const {
    return tileWidth;
}

int TileSet::GetTileHeight() const {
    return tileHeight;
}
