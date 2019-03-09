/***************************************************************
 * Name:      ClientApp.h
 * Purpose:   Defines Application Class
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-09
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#ifndef CLIENTAPP_H
#define CLIENTAPP_H

#include <wx/app.h>

class ClientApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // CLIENTAPP_H
