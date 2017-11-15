/*
 * author adward
 * Mar 16, 2013
 */

#ifndef _COLORTERM_HPP_
#define _COLORTERM_HPP_

#include <ostream>
#include <set>

#include <cstring>

#define _CT_END_STR "\033[0m"

#define _CT_ATTR_BUF_LEN 20
#define _CT_STYLE_BUF_LEN_ 38

namespace ColorTerm {

namespace Color {
enum Enum {
	Black, Red, Green, Yellow, Blue, Magenta, Cyan, Gray, Default = 9
};
}

namespace Attr {
enum Enum {
	Reset,
	Bold,
	Dim,
	Underline,

	_UNUSED_D1,
	Blink,
	_UNUSED_D2,
	Inverse,
	Hidden,
	Strike
};
}

class AttrSet: public std::set<Attr::Enum> {
private:
	char attrStr[_CT_ATTR_BUF_LEN];

	void buildAttrStr() {
		std::set<Attr::Enum>::iterator it = begin();
		char* ptr = attrStr;

		*ptr = '\0';
		for (; it != end(); ++it, ptr += 2)
			sprintf(ptr, "%d;", *it);
	}

public:
	AttrSet(Attr::Enum attr1 = Attr::Reset, Attr::Enum attr2 = Attr::Reset,
			Attr::Enum attr3 = Attr::Reset, Attr::Enum attr4 = Attr::Reset) {
		set(attr1, attr2, attr3, attr4);
	}

	void set(Attr::Enum attr1 = Attr::Reset, Attr::Enum attr2 = Attr::Reset,
			Attr::Enum attr3 = Attr::Reset, Attr::Enum attr4 = Attr::Reset) {
		if (attr1 != Attr::Reset)
			insert(attr1);
		if (attr2 != Attr::Reset)
			insert(attr2);
		if (attr3 != Attr::Reset)
			insert(attr3);
		if (attr4 != Attr::Reset)
			insert(attr4);

		buildAttrStr();
	}

	void clear() {
		std::set<Attr::Enum>::clear();
		set();
	}

	const char* toString() {
		return attrStr;
	}
};

class TermStyleManipulator {
	friend std::ostream& operator <<(std::ostream& o,
			const TermStyleManipulator& tc);
private:

	AttrSet* attr;
	Color::Enum foreColor;
	Color::Enum backColor;

	bool brightFore;
	bool brightBack;

	char styleBuf[_CT_STYLE_BUF_LEN_];

	void buildStyleStr() {
		if (attr->empty() && foreColor == Color::Default
				&& backColor == Color::Default && !brightFore && !brightBack) {
			strcpy(styleBuf, _CT_END_STR);
		} else {
			const char* attrStr = attr->toString();
			int foreColorCode = brightFore ? foreColor + 90 : foreColor + 30;
			int backColorCode = brightBack ? backColor + 100 : backColor + 40;
			sprintf(styleBuf, "\033[%s%d;%dm", attrStr, foreColorCode,
					backColorCode);
		}
	}

public:
	TermStyleManipulator() {
		attr = new AttrSet;
		clear();
	}

	TermStyleManipulator(AttrSet& aset, Color::Enum foreColor = Color::Default,
			Color::Enum backColor = Color::Default, bool brightFore = false,
			bool brightBack = false) {
		attr = new AttrSet;
		set(aset, foreColor, backColor, brightFore, brightBack);
	}

	TermStyleManipulator(const TermStyleManipulator& tc) {
		this->attr = new AttrSet(*tc.attr);
		this->foreColor = tc.foreColor;
		this->backColor = tc.backColor;
		this->brightFore = tc.brightFore;
		this->brightBack = tc.brightBack;

		memcpy(styleBuf, tc.styleBuf, _CT_STYLE_BUF_LEN_);
	}

	~TermStyleManipulator() {
		delete attr;
	}

	const char* set(AttrSet& aset, Color::Enum foreColor = Color::Default,
			Color::Enum backColor = Color::Default, bool brightFore = false,
			bool brightBack = false) {
		*attr = aset;
		this->foreColor = foreColor;
		this->backColor = backColor;
		this->brightFore = brightFore;
		this->brightBack = brightBack;

		buildStyleStr();

		return styleBuf;
	}

	const char* setColor(Color::Enum foreColor = Color::Default,
			Color::Enum backColor = Color::Default, bool brightFore = false,
			bool brightBack = false) {
		set(getAttr(), foreColor, backColor, brightFore, brightBack);

		return styleBuf;
	}

	const char* setBrightness(bool fore = false, bool back = false) {
		set(getAttr(), foreColor, backColor, fore, back);

		return styleBuf;
	}

	AttrSet& getAttr() {
		return *attr;
	}

	void clear() {
		attr->clear();
		set(*attr);
	}
};

const TermStyleManipulator CT_END;

std::ostream& operator <<(std::ostream& o, const TermStyleManipulator& tc) {
	o << tc.styleBuf;
	return o;
}
}

#endif /* _COLORTERM_HPP_ */

