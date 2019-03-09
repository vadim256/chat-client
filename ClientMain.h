/***************************************************************
 * Name:      ClientMain.h
 * Purpose:   Defines Application Frame
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-09
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#ifndef CLIENTMAIN_H
#define CLIENTMAIN_H

//(*Headers(ClientFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class ClientFrame: public wxFrame
{
    public:

        ClientFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ClientFrame();

    private:

        //(*Handlers(ClientFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(ClientFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(ClientFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // CLIENTMAIN_H
