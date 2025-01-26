#include <CtrlLib/CtrlLib.h>

#include "DropFont.h"


namespace Upp {

	struct DisplayFace : public Display {
		void Paint(Draw& w, const Rect& r, const Value& q, Color ink, Color paper, dword style) const {
			int ii = q;
			Font fnt = StdFont();
			if(!(Font::GetFaceInfo(ii) & Font::SPECIAL))
				fnt.Face(ii);
			w.DrawRect(r, paper);
			w.DrawText(r.left, r.top + (r.Height() - fnt.Info().GetHeight()) / 2,
			           Font::GetFaceName((int)q), fnt, ink);
		}
	};

DropFont::DropFont() {
	SetDisplay(Single<DisplayFace>());
	for(int i = 0; i < Font::GetFaceCount(); i++)
		if(Font::GetFaceInfo(i) & Font::SCALEABLE)
			Add(i);
	SetIndex(0);
}

END_UPP_NAMESPACE
