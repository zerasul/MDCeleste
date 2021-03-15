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
    // Set screen width
    VDP_setScreenWidth320();
    SPR_init();
    u16 ind=TILE_USERINDEX;
    VDP_drawImageEx(BG_B,&celestec1,TILE_ATTR_FULL(PAL0,TRUE,FALSE,FALSE,ind),0,0,FALSE,TRUE);
    VDP_setPalette(PAL0,celestec1.palette->data);
    ind+=celestec1.tileset->numTile;
    //VDP_loadTileSet(&tileset,ind,DMA);
    //VDP_setPalette(PAL1, tileset_pal.data);
    int i,j=0;
    for(;i<40;i++){
        for(;j<28;j++){
            VDP_setTileMapXY(BG_A,TILE_ATTR_FULL(PAL2,TRUE,FALSE,FALSE,ind-1, tiles[i+40*j]),i,j);
        }
    }
    
    Sprite * player_sprt = SPR_addSprite(&player,190,170,TILE_ATTR_FULL(PAL2,TRUE,FALSE,FALSE,ind));
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
