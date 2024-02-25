#ifndef _DropFont_DropFont_h_
#define _DropFont_DropFont_h_

namespace Upp {

struct DropFont_DisplayFont : public Display {
	Color fontColor;
	virtual void PaintBackground(Draw& w, const Rect& r, const Value& q, Color ink, Color paper, dword style) const;
	virtual void Paint(Draw& w, const Rect& r, const Value& q, Color ink, Color paper, dword style) const;
	virtual Size GetStdSize(const Value& q) const;
	virtual Size RatioSize(const Value& q, int cx, int cy) const;
	
	DropFont_DisplayFont();
	virtual	~DropFont_DisplayFont() {}

	static DropFont_DisplayFont& GetDefaultDisplay();
};


struct DropFont_ValueDisplayFont : public Display {
	Color fontColor;
	virtual void PaintBackground(Draw& w, const Rect& r, const Value& q, Color ink, Color paper, dword style) const;
	void Paint(Draw& w, const Rect& r, const Value& q, Color ink, Color paper, dword style) const;
	virtual Size GetStdSize(const Value& q) const;
	virtual Size RatioSize(const Value& q, int cx, int cy) const;

	DropFont_ValueDisplayFont();
	virtual	~DropFont_ValueDisplayFont() {}

	static DropFont_ValueDisplayFont& GetDefaultDisplay();
};



class DropFont : public DropList
{
	private:
	DropFont_DisplayFont display;
	//DropFont_ValueDisplayFont display;
	
	public:
	DropFont();
	virtual ~DropFont() {}
	
	void SetColor(Color c) { display.fontColor = c; }
	
	template<class LIST>
	void SetValues( LIST& v)
	{
		ClearList();
		for (int c=0; c<v.GetCount(); ++c)
		{
			Add(v[c]);
		}
	}
};

END_UPP_NAMESPACE

#endif
