#ifndef MAIN_H
#define MAIN_H

#include <wx/wx.h>
#include <wx/sizer.h>
#include <vector>
#include "counter.h"
#include "mängija.h"

using std::vector;

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
    int count{};
    Counter counter;
    vector<Mängija> players;
    vector<int> kaardipakk;

    wxImage m_image;
    wxBitmap m_scaled;


private:
    void DestroyAllStaticTexts(wxPanel* parent);

    void OnStart(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    
    void OnHit(wxCommandEvent& event);
    void OnStand(wxCommandEvent& event);

    void OnImagePanelPaint(wxPaintEvent&);
    void CreateScaled();

    void busted();
    void võit();

    wxPanel* mainPanel;
    wxButton* startButton;
    wxButton* exitButton;
    wxButton* hitButton;
    wxButton* standButton;

    void ShowGameUI();
};

class wxWidgetsApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxDECLARE_APP(wxWidgetsApp);

enum
{
    ID_START = 1,
    ID_EXIT = 2,
    ID_HIT = 3,
    ID_STAND = 4
};

#endif 
