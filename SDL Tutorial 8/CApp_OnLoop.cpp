//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnLoop() {
    //--------------------------------------------------------------------------
    // Entities
    //--------------------------------------------------------------------------
    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnLoop();
    }

    CFPS::FPSControl.OnLoop();

    char Buffer[255];
    sprintf(Buffer, "%d", CFPS::FPSControl.GetFPS());
    SDL_WM_SetCaption(Buffer, Buffer);
}

//==============================================================================
