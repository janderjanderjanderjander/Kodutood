#include "main.h"
#include "counter.h"
#include "mängija.h"
#include "master.h"

#include <wx/graphics.h>
#include <memory>

bool wxWidgetsApp::OnInit()
{
    MainFrame* mainFrame = new MainFrame("Blackjack Game");
    mainFrame->Show(true);
    return true;
}

MainFrame::MainFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxPoint(0, 0), wxSize(1600, 900))
{
    ::wxInitAllImageHandlers();

    players = setup();
    kaardipakk = kaardipakk_template;
    sega_kaardid(&kaardipakk);

    mainPanel = new wxPanel(this, wxID_ANY);

    m_image = wxImage("laud.jpg", wxBITMAP_TYPE_JPEG);
    if (!m_image.IsOk()) {
        return;
    }

    CreateScaled();
    mainPanel->Bind(wxEVT_PAINT, &MainFrame::OnImagePanelPaint, this);

    startButton = new wxButton(mainPanel, ID_START, "Start", wxPoint(650, 700), wxDefaultSize);
    exitButton = new wxButton(mainPanel, ID_EXIT, "Exit", wxPoint(850, 700), wxDefaultSize);

    hitButton = new wxButton(mainPanel, ID_HIT, "Hit", wxPoint(650, 700), wxDefaultSize);
    standButton = new wxButton(mainPanel, ID_STAND, "Stand", wxPoint(850, 700), wxDefaultSize);

    Bind(wxEVT_BUTTON, &MainFrame::OnHit, this, ID_HIT);
    Bind(wxEVT_BUTTON, &MainFrame::OnStand, this, ID_STAND);
    Bind(wxEVT_BUTTON, &MainFrame::OnStart, this, ID_START);
    Bind(wxEVT_BUTTON, &MainFrame::OnExit, this, ID_EXIT);

    hitButton->Hide();
    standButton->Hide();
}


void MainFrame::OnStart(wxCommandEvent& event){
    DestroyAllStaticTexts(mainPanel);
    count = 200;
    if (kaardipakk.size() < 10) {
        kaardipakk = kaardipakk_template;
        sega_kaardid(&kaardipakk);
    }

    startButton->Hide();
    exitButton->Hide();

    //mängu algus
    jaga_kaardid(&players, &kaardipakk, &counter);

    //double scale = GetDPIScaleFactor();

    //wxBitmap bitmap;
    //bitmap.CreateWithDIPSize(GetClientRect().GetSize() * GetContentScaleFactor(), scale, 32);
    //bitmap.UseAlpha();

    //wxMemoryDC dc(bitmap);
    //dc.SetUserScale(scale, scale);
    
    //DrawOnContext(*mainPanel);

    /*wxImage image("kaardid/pngtest.png", wxBITMAP_TYPE_PNG);
    double scale = GetDPIScaleFactor();
    int scaledWidth = 500 * scale;
    int scaledHeight = 726 * scale;

    image = image.Scale(scaledWidth, scaledHeight, wxIMAGE_QUALITY_HIGH);

    wxBitmap esimeneKaart(image, 32);
    esimeneKaart.UseAlpha();
    wxSize sz = wxSize(500, 726);
    */

    //wxStaticBitmap* DiileriKaartEssa = new wxStaticBitmap(mainPanel, wxID_ANY, esimeneKaart, wxPoint(100, 100));

    wxStaticText* DiileriKaartEssa = new wxStaticText(mainPanel, wxID_ANY, players[0].get_kaart(0), wxPoint(100, 100));
    wxStaticText* DiileriKaartTeine = new wxStaticText(mainPanel, wxID_ANY, players[0].get_kaart(1), wxPoint(300, 100));

    wxStaticText* PlayerKaartEssa = new wxStaticText(mainPanel, wxID_ANY, players[1].get_kaart(0), wxPoint(100, 600));
    wxStaticText* PlayerKaartTeine = new wxStaticText(mainPanel, wxID_ANY, players[1].get_kaart(1), wxPoint(300, 600));

    hitButton->Show();
    standButton->Show();
    }


void MainFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

void MainFrame::OnHit(wxCommandEvent& event) {
    int seis{};
    seis = hit(&(players[1]), &kaardipakk, &counter);
    wxStaticText* Sinulisakaardid = new wxStaticText(mainPanel, wxID_ANY, players[1].get_kaart(-1), wxPoint(300 + count, 600));
    count += 200;
    if (seis == 5) {
        busted();
    }
}

void MainFrame::OnStand(wxCommandEvent& event) {
    count = 200;
    while (players[0].get_summa() < 17) {
        anna_kaart(&kaardipakk , &(players[0]), &counter);
        wxStaticText* Diilerilisakaardid = new wxStaticText(mainPanel, wxID_ANY, players[0].get_kaart(-1), wxPoint(300 + count, 100));
    }
    if (players[1].get_summa() < 22 && (players[1].get_summa() > players[0].get_summa() || players[0].get_summa() > 21)) {
        võit();
    }
    else {
        busted();
    }
}

void MainFrame::busted() {
    hitButton->Hide();
    standButton->Hide();

    wxStaticText* seis = new wxStaticText(mainPanel, wxID_ANY, "KAOTUS!", wxPoint(450, 700));
    startButton->Show();
    exitButton->Show();
}

void MainFrame::võit() {
    hitButton->Hide();
    standButton->Hide();

    wxStaticText* seis = new wxStaticText(mainPanel, wxID_ANY, "Võit!", wxPoint(450, 700));
    startButton->Show();
    exitButton->Show();
}

void MainFrame::DestroyAllStaticTexts(wxPanel* parent) {
    if (parent == nullptr) {
        return;
    }
    wxWindowList children = parent->GetChildren();

    for (auto child : children) {
        if (wxDynamicCast(child, wxStaticText) != nullptr) {
            child->Destroy();
        }
        else {
            DestroyAllStaticTexts(wxDynamicCast(child, wxPanel));
        }
    }
}

void MainFrame::OnImagePanelPaint(wxPaintEvent& event) {
    if (mainPanel->GetSize() != m_scaled.GetSize()) {
        CreateScaled();
    }
    wxPaintDC dc(mainPanel);
    dc.DrawBitmap(m_scaled, 0, 0);
}

void MainFrame::CreateScaled() {
    wxSize sz = mainPanel->GetSize();
    m_scaled = wxBitmap(m_image.Scale(sz.GetWidth(), sz.GetHeight(), wxIMAGE_QUALITY_NORMAL));
}












wxIMPLEMENT_APP(wxWidgetsApp);