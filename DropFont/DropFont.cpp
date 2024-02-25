#include <CtrlLib/CtrlLib.h>

#include "DropFont.h"


namespace Upp {

DropFont_DisplayFont& DropFont_DisplayFont::GetDefaultDisplay() { return Single<DropFont_DisplayFont>(); }
DropFont_DisplayFont::DropFont_DisplayFont() : fontColor(Null) {}

// =========================================================
void DropFont_DisplayFont::Paint(Draw& w, const Rect& r, const Value& q, Color ink, Color paper, dword style) const {
	Font fnt;
	fnt.Face((int)q);
	fnt.Height(r.Height() - 4);
	w.DrawRect(r, paper);
	w.DrawText(r.left, r.top + (r.Height() - fnt.Info().GetHeight()) / 2,
	           Font::GetFaceName((int)q), fnt, (IsNull(fontColor) ? ink: fontColor));
}

void DropFont_DisplayFont::PaintBackground(Draw& w, const Rect& r, const Value& q, Color ink, Color paper, dword style) const
{
	w.DrawRect(r, paper);
}

Size DropFont_DisplayFont::GetStdSize(const Value& q) const { return Size(48, 16); }
Size DropFont_DisplayFont::RatioSize(const Value& q, int cx, int cy) const { return GetStdSize(q); }


// =========================================================
DropFont_ValueDisplayFont& DropFont_ValueDisplayFont::GetDefaultDisplay() { return Single<DropFont_ValueDisplayFont>(); }
DropFont_ValueDisplayFont::DropFont_ValueDisplayFont() : fontColor(Null) {}

void DropFont_ValueDisplayFont::Paint(Draw& w, const Rect& r, const Value& q, Color ink, Color paper, dword style) const {
	w.DrawRect(r, paper);
	w.DrawText(r.left, r.top + (r.Height() - StdFont().Info().GetHeight()) / 2,
	           Font::GetFaceName((int)q), StdFont(), (IsNull(fontColor) ? ink: fontColor));
}

void DropFont_ValueDisplayFont::PaintBackground(Draw& w, const Rect& r, const Value& q, Color ink, Color paper, dword style) const
{
	w.DrawRect(r, paper);
}

Size DropFont_ValueDisplayFont::GetStdSize(const Value& q) const { return Size(48, 16); }
Size DropFont_ValueDisplayFont::RatioSize(const Value& q, int cx, int cy) const { return GetStdSize(q); }

// =========================================================


DropFont::DropFont() {
	SetDisplay( display );
	Add(Font::ARIAL);
	Add(Font::ROMAN);
	Add(Font::COURIER);
	SetIndex(0);
}

/*
RichEdit& RichEdit::FontFaces(const Vector<int>& ff)
{
	ffs <<= ff;
	face.ClearList();
	for(int i = 0; i < ff.GetCount(); i++)
		face.Add(ff[i]);
	return *this;
}

void SetupFaceList(DropList& face)
{
	face.ValueDisplay(Single<ValueDisplayFont>());
	face.SetDisplay(Single<DisplayFont>());
	face.SetLineCy(20);
}


void init() {
	SetupFaceList(face);
	face <<= THISBACK(SetFace);
	face.Tip(t_("Font face"));
	Vector<int> ff;
	ff.Add(Font::ARIAL);
	ff.Add(Font::ROMAN);
	ff.Add(Font::COURIER);
	FontFaces(ff);

}
*/

END_UPP_NAMESPACE
