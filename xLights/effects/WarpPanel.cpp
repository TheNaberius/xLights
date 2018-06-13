#include "WarpPanel.h"
#include "xlGLCanvas.h"

//(*InternalHeaders(WarpPanel)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(WarpPanel)
const long WarpPanel::ID_TEXTCTRL1 = wxNewId();
const long WarpPanel::ID_STATICTEXT1 = wxNewId();
const long WarpPanel::ID_CHOICE_Warp_Type = wxNewId();
const long WarpPanel::ID_STATICTEXT2 = wxNewId();
const long WarpPanel::ID_CHOICE_Warp_Treatment = wxNewId();
const long WarpPanel::ID_STATICTEXT3 = wxNewId();
const long WarpPanel::ID_SLIDER_Warp_X = wxNewId();
const long WarpPanel::ID_TEXTCTRL_Warp_X = wxNewId();
const long WarpPanel::ID_STATICTEXT4 = wxNewId();
const long WarpPanel::ID_SLIDER_Warp_Y = wxNewId();
const long WarpPanel::ID_TEXTCTRL_Warp_Y = wxNewId();
const long WarpPanel::ID_STATICTEXT7 = wxNewId();
const long WarpPanel::ID_SLIDER_Warp_Cycle_Count = wxNewId();
const long WarpPanel::ID_TEXTCTRL_Warp_Cycle_Count = wxNewId();
const long WarpPanel::ID_STATICTEXT6 = wxNewId();
const long WarpPanel::ID_SLIDER_Warp_Speed = wxNewId();
const long WarpPanel::ID_TEXTCTRL_Warp_Speed = wxNewId();
const long WarpPanel::ID_STATICTEXT5 = wxNewId();
const long WarpPanel::ID_SLIDER_Warp_Frequency = wxNewId();
const long WarpPanel::ID_TEXTCTRL_Warp_Frequency = wxNewId();
//*)

WarpPreview::WarpPreview( wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style, const wxString &name, bool coreProfile)
   : xlGLCanvas( parent, id, pos, size, style, name, coreProfile )
{

}

WarpPreview::~WarpPreview()
{

}

void WarpPreview::InitializeGLCanvas()
{
   SetCurrentGLContext();

   mIsInitialized = true;
}

BEGIN_EVENT_TABLE(WarpPanel,wxPanel)
	//(*EventTable(WarpPanel)
	//*)
END_EVENT_TABLE()

WarpPanel::WarpPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(WarpPanel)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer3;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(1);
	FlexGridSizer3 = new wxFlexGridSizer(1, 1, 0, 0);
	FlexGridSizer3->AddGrowableCol(0);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("The warp effect distorts the pixels in the layers below it. The Canvas option in Layer Blending must be enabled for it to work."), wxDefaultPosition, wxDLG_UNIT(this,wxSize(99,32)), wxTE_NO_VSCROLL|wxTE_MULTILINE|wxTE_READONLY|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl1->Disable();
	TextCtrl1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
	FlexGridSizer3->Add(TextCtrl1, 1, wxEXPAND, 2);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxTOP|wxLEFT|wxRIGHT|wxEXPAND, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer2->AddGrowableCol(1);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Warp Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Choice_Warp_Type = new wxChoice(this, ID_CHOICE_Warp_Type, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_Warp_Type"));
	Choice_Warp_Type->Append(_("water drops"));
	Choice_Warp_Type->Append(_("dissolve"));
	Choice_Warp_Type->Append(_("circle reveal"));
	Choice_Warp_Type->Append(_("banded swirl"));
	Choice_Warp_Type->Append(_("ripple"));
	FlexGridSizer2->Add(Choice_Warp_Type, 1, wxALL|wxEXPAND, 2);
	FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Treatment"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Choice_Warp_Treatment = new wxChoice(this, ID_CHOICE_Warp_Treatment, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE_Warp_Treatment"));
	Choice_Warp_Treatment->Append(_("constant"));
	Choice_Warp_Treatment->Append(_("in"));
	Choice_Warp_Treatment->Append(_("out"));
	FlexGridSizer2->Add(Choice_Warp_Treatment, 1, wxALL|wxEXPAND, 2);
	FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("X"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer2->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Warp_X = new BulkEditSlider(this, ID_SLIDER_Warp_X, 50, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_Warp_X"));
	FlexGridSizer2->Add(Slider_Warp_X, 1, wxALL|wxEXPAND, 2);
	TextCtrl_Warp_X = new BulkEditTextCtrl(this, ID_TEXTCTRL_Warp_X, _("50"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL_Warp_X"));
	FlexGridSizer2->Add(TextCtrl_Warp_X, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Y"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer2->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Warp_Y = new BulkEditSlider(this, ID_SLIDER_Warp_Y, 50, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_Warp_Y"));
	FlexGridSizer2->Add(Slider_Warp_Y, 1, wxALL|wxEXPAND, 2);
	TextCtrl_Warp_Y = new BulkEditTextCtrl(this, ID_TEXTCTRL_Warp_Y, _("50"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL_Warp_Y"));
	FlexGridSizer2->Add(TextCtrl_Warp_Y, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Cycle Count"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer2->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Warp_Cycle_Count = new BulkEditSlider(this, ID_SLIDER_Warp_Cycle_Count, 1, 1, 10, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_Warp_Cycle_Count"));
	FlexGridSizer2->Add(Slider_Warp_Cycle_Count, 1, wxALL|wxEXPAND, 5);
	TextCtrl_Warp_Cycle_Count = new BulkEditTextCtrl(this, ID_TEXTCTRL_Warp_Cycle_Count, _("1"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL_Warp_Cycle_Count"));
	FlexGridSizer2->Add(TextCtrl_Warp_Cycle_Count, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Speed"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer2->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Warp_Speed = new BulkEditSlider(this, ID_SLIDER_Warp_Speed, 20, 0, 40, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_Warp_Speed"));
	FlexGridSizer2->Add(Slider_Warp_Speed, 1, wxALL|wxEXPAND, 2);
	TextCtrl_Warp_Speed = new BulkEditTextCtrl(this, ID_TEXTCTRL_Warp_Speed, _("20"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL_Warp_Speed"));
	FlexGridSizer2->Add(TextCtrl_Warp_Speed, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Frequency"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Slider_Warp_Frequency = new BulkEditSlider(this, ID_SLIDER_Warp_Frequency, 20, 0, 40, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_Warp_Frequency"));
	FlexGridSizer2->Add(Slider_Warp_Frequency, 1, wxALL|wxEXPAND, 2);
	TextCtrl_Warp_Frequency = new BulkEditTextCtrl(this, ID_TEXTCTRL_Warp_Frequency, _("20"), wxDefaultPosition, wxDLG_UNIT(this,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL_Warp_Frequency"));
	FlexGridSizer2->Add(TextCtrl_Warp_Frequency, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 2);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	//*)
}

WarpPanel::~WarpPanel()
{
	//(*Destroy(WarpPanel)
	//*)
}
void WarpPanel::OnChoice_Warp_TypeSelect(wxCommandEvent& event)
{
}
