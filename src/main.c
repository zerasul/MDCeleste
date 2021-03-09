/**
 * Hello World Example
 * Created With Genesis-Code extension for Visual Studio Code
 * Use "Genesis Code: Compile" command to compile this program.
 **/
#include <genesis.h>
#include "sprites.h"
#include "tiles.h"
#include "gfx.h"


int main()
{
    VDP_drawText("Hello Sega!!", 10,13);
    SPR_init();
    u16 ind=TILE_USERINDEX;
    VDP_loadTileSet(&tileset,ind,DMA);
    VDP_setPalette(PAL1, tileset_pal.data);
    int i,j;

    for (i = 0; i < 40; i++)
    {
        for (j = 0; j < 28; j++)
        {
            VDP_setTileMapXY(BG_A, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind-1 + tiles[i + 40 * j]), i, j);
        }
    }
    ind+=tileset.numTile;
    Sprite * player_sprt = SPR_addSprite(&player,20,20,TILE_ATTR_FULL(PAL2,TRUE,FALSE,FALSE,ind));
    VDP_setPalette(PAL2,player.palette->data);
    SPR_setAnim(player_sprt,2);
    while(1)
    {
        SPR_update();
        //For versions prior to SGDK 1.60 use VDP_waitVSync instead.
        SYS_doVBlankProcess();
    }
    return (0);
}
