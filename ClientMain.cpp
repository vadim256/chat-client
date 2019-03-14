/***************************************************************
 * Name:      ClientMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-09
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "ClientMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(ClientFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ClientFrame)
const long ClientFrame::ID_TEXTCTRL2 = wxNewId();
const long ClientFrame::ID_TEXTCTRL1 = wxNewId();
const long ClientFrame::ID_BUTTON1 = wxNewId();
const long ClientFrame::ID_BUTTON2 = wxNewId();
const long ClientFrame::ID_PANEL1 = wxNewId();
const long ClientFrame::idMenuConnect = wxNewId();
const long ClientFrame::idMenuDisconnect = wxNewId();
const long ClientFrame::idMenuQuit = wxNewId();
const long ClientFrame::idMenuAbout = wxNewId();
const long ClientFrame::ID_STATUSBAR1 = wxNewId();
//*)
const long ClientFrame::idSocketClient = wxNewId();
const long ClientFrame::MSG_SIZE = 1024;

BEGIN_EVENT_TABLE(ClientFrame,wxFrame)
    //(*EventTable(ClientFrame)
    //*)
    EVT_SOCKET(idSocketClient, ClientFrame::OnClientSocketEvent)
    EVT_UPDATE_UI(ID_BUTTON1, ClientFrame::OnExportMessageUpdateUI)
    EVT_UPDATE_UI(ID_BUTTON2, ClientFrame::OnCleanMessageUpdateUI)

END_EVENT_TABLE()

ClientFrame::ClientFrame(wxWindow* parent,wxWindowID id)
: m_Client(nullptr)
{
    //(*Initialize(ClientFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("chat-client"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(500,500));
    SetMinSize(wxSize(350,350));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("/home/ameliepulen/project1/chat-client/client_icon.png"))));
    	SetIcon(FrameIcon);
    }
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer2->Add(TextCtrl2, 1, wxALL|wxEXPAND, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_RICH|wxTE_RICH2|wxSIMPLE_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer3->Add(TextCtrl1, 1, wxALL|wxEXPAND, 1);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("send"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer4->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("clean"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer4->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuConnect, _("Connect"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, idMenuDisconnect, _("Disconnect"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    SetSizer(BoxSizer1);
    Layout();
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ClientFrame::OnExportMessage);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ClientFrame::OnCleanMessage);
    Connect(idMenuConnect,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ClientFrame::OnMenuConnect);
    Connect(idMenuDisconnect,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ClientFrame::OnMenuDisconnect);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ClientFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ClientFrame::OnAbout);
    //*)
    TextCtrl1->SetValidator(wxGenericValidator(&m_ClientMsg));
    this->Connect(idSocketClient, wxEVT_SOCKET, (wxObjectEventFunction)&ClientFrame::OnClientSocketEvent);
}

ClientFrame::~ClientFrame()
{
    //(*Destroy(ClientFrame)
    //*)
    if(m_Client)
        m_Client->Destroy();
}

void ClientFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ClientFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void ClientFrame::OnMenuConnect(wxCommandEvent& event)
{
    if(m_Client){
        TextCtrl2->AppendText(wxT("[warning] already joined\n"));
        return;
    }
    wxString hostname = wxGetTextFromUser(wxT("Enter address server"),
                                          wxT("Connection"), wxT("localhost"));
    if(hostname.IsEmpty()){
        TextCtrl2->AppendText(wxT("[error] server address not entered\n"));
        return;
    }
    wxIPV4address address;
    address.Service(3000);
    address.Hostname(hostname);

    m_Client = new wxSocketClient();
    if(!m_Client){
        TextCtrl2->AppendText(wxT("[error] no memory allocated for client\n"));
        return;
    }
    m_Client->SetEventHandler(*this, idSocketClient);
    m_Client->SetNotify(wxSOCKET_LOST_FLAG|wxSOCKET_INPUT_FLAG);
    m_Client->Notify(TRUE);

    if(m_Client->Connect(address, false) == FALSE) return;

    m_Client->WaitOnConnect(3);
    if(m_Client->IsConnected()){
        TextCtrl2->AppendText(wxT("[success] connected to the server\n"));
    } else {
	if(m_Client)
	        delete m_Client;
        m_Client = nullptr;
        TextCtrl2->AppendText(wxT("[error] not connected to server\n"));
    }
}

void ClientFrame::OnMenuDisconnect(wxCommandEvent& event)
{
    if(!m_Client){
        TextCtrl2->AppendText(wxT("[warning] already disconnected\n"));
        return;
    }
    if(m_Client->IsOk()){
        if(m_Client->IsConnected())
            m_Client->Close();
        m_Client->Destroy();
    }
    m_Client = nullptr;
}

void ClientFrame::OnClientSocketEvent(wxSocketEvent & event){
    auto socket_slave = event.GetSocket();
    wxIPV4address address;
    socket_slave->GetLocal(address);
    char msg_buffer[MSG_SIZE];

    switch(event.GetSocketEvent()){
        case wxSOCKET_INPUT:
        socket_slave->Read(msg_buffer, MSG_SIZE*sizeof(char));
        if(socket_slave->Error()){
            TextCtrl2->AppendText(wxT("[error] сould not read message\n"));
        } else {
            msg_buffer[(size_t)ceil((double)socket_slave->LastCount()/sizeof(char))] = wxT('\0');
            TextCtrl2->AppendText(wxString::Format(wxT("%s\n"), msg_buffer));
        }
        break;
        case wxSOCKET_LOST:
        if(m_Client == socket_slave){
            m_Client = nullptr;
        }
        if(socket_slave->IsOk())
            socket_slave->Destroy();
        TextCtrl2->AppendText(wxT("[good] disconnected from the server\n"));
        break;
    }
}

void ClientFrame::OnExportMessage(wxCommandEvent& event)
{
    TransferDataFromWindow();
    if(m_ClientMsg.IsEmpty()){
        return;
    }
    if(m_Client){
        m_Client->Write(m_ClientMsg.GetData(), m_ClientMsg.Len()/sizeof(char));
    }
    m_ClientMsg.Clear();
    TransferDataToWindow();
}

void ClientFrame::OnCleanMessage(wxCommandEvent& event) { }

void ClientFrame::OnExportMessageUpdateUI(wxUpdateUIEvent & event){
    event.Enable(m_Client);
}

void ClientFrame::OnCleanMessageUpdateUI(wxUpdateUIEvent & event){
    event.Enable(FALSE);
}
