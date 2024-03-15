#ifndef _DropFont_DropFont_h_
#define _DropFont_DropFont_h_

namespace Upp {

class DropFont : public DropList
{
	private:
	Font font;
	
	public:
	DropFont();
	virtual ~DropFont() {}

	virtual void   SetData(const Value& data) {
		font = ValueTo(data, StdFont().Height(30));
		DropList::SetData(font.GetFace());
	}
	
	virtual Value  GetData() const {
		int faceNum = (int) DropList::GetData();
		Font fout(faceNum, font.GetHeight() );
		if (font.IsBold()) fout.Bold();
		if (font.IsUnderline()) fout.Underline();
		return Value(fout);
	}
	
	template<class LIST>
	void SetValues( LIST& v)
	{
		ClearList();
		for (int c=0; c<v.GetCount(); ++c) {
			Add(v[c]); // v[c] must be int  (face)
		}
	}
};

END_UPP_NAMESPACE

#endif
