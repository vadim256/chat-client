/***************************************************************
 * Name:      ClientApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-09
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "ClientApp.h"

//(*AppHeaders
#include "ClientMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ClientApp);

bool ClientApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ClientFrame* Frame = new ClientFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
