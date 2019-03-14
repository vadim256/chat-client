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
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)
#include <cmath>
#include <wx/socket.h>
#include <wx/valgen.h>


class ClientFrame: public wxFrame
{
    public:

        explicit ClientFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ClientFrame();

    private:

        //(*Handlers(ClientFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuConnect(wxCommandEvent& event);
        void OnMenuDisconnect(wxCommandEvent& event);
        void OnExportMessage(wxCommandEvent& event);
        void OnCleanMessage(wxCommandEvent& event);
        //*)
        void OnClientSocketEvent(wxSocketEvent & event);
        void OnExportMessageUpdateUI(wxUpdateUIEvent & event);
        void OnCleanMessageUpdateUI(wxUpdateUIEvent & event);
        //(*Identifiers(ClientFrame)
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        static const long idMenuConnect;
        static const long idMenuDisconnect;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)
        static const long idSocketClient;
        static const long MSG_SIZE;
        //(*Declarations(ClientFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        //*)
        wxSocketClient * m_Client;
        wxString m_ClientMsg;

        DECLARE_EVENT_TABLE()
};

#endif // CLIENTMAIN_H
