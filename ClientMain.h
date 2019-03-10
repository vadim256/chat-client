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
#include <wx/htmllbox.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)
#include <wx/socket.h>
#include <memory>

class ClientFrame: public wxFrame
{
    public:

        ClientFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ClientFrame();

    private:

        //(*Handlers(ClientFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuConnect(wxCommandEvent& event);
        void OnMenuDisconnect(wxCommandEvent& event);
        //*)

        //(*Identifiers(ClientFrame)
        static const long ID_SIMPLEHTMLLISTBOX1;
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

        //(*Declarations(ClientFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxPanel* Panel1;
        wxSimpleHtmlListBox* SimpleHtmlListBox1;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        //*)
        std::unique_ptr<wxSocketClient> m_Client;
        wxString m_ClientMsg;
        DECLARE_EVENT_TABLE()
};

#endif // CLIENTMAIN_H
