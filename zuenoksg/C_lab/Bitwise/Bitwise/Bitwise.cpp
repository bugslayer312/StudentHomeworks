// Bitwise.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include <stdio.h>
#include <tchar.h>
#include <stdint.h>
#include <Locale.h>

enum Style {
	// (B Ц bold), (I Ц italic), (U Ц underline)
	NONE = 0,				// 0000
	B = 1,					// 0001
	I = 1 << 1,				// 0010
	U = 1 << 2,				// 0100
	ALL = B | I | U			// 0111
};

enum StlPrgf {
	bold = 0x100,						//		0001 0000 0000
	italic = 0x100 << 1,				//		0010 0000 0000
	underline = 0x100 << 2,				//		0100 0000 0000
	all = bold | italic | underline,	//		0111 0000 0000

	Left = 0x800,						// 0000 1000 0000 0000
	Center = 0x800 << 1,				// 0001 0000 0000 0000
	Right = 0x800 << 2,					// 0010 0000 0000 0000
	Justify = 0x800 << 3,				// 0100 0000 0000 0000
};

void PrintHtml(char const*, int);
void SetTextParagraphDisplay(uint32_t);

int main() {
	setlocale(LC_ALL, "Russian");
	char const* simple_string;

	simple_string = "ѕривет";
	PrintHtml(simple_string, ALL);
	printf("\n");

	simple_string = "Hello, World";
	PrintHtml(simple_string, U | I);
	printf("\n");

	SetTextParagraphDisplay(bold | italic | underline | Left | 100);
	printf("\n");

	return 0;
}

void PrintHtml(char const* string, int style) {
	char *out_B, *out_I, *out_U,
		*out__B, *out__I, *out__U;

	out_B = (style&B) ? "<B>" : "";
	out_I = (style&I) ? "<I>" : "";
	out_U = (style&U) ? "<U>" : "";
	out__B = (style&B) ? "</B>" : "";
	out__I = (style&I) ? "</I>" : "";
	out__U = (style&U) ? "</U>" : "";

	printf("%s%s%s%s%s%s%s", out_B, out_I, out_U, string, out__U, out__I, out__B);
};

void SetTextParagraphDisplay(uint32_t flags) {
	char *out__b, *out__i, *out__u,
		*out__L, *out__C, *out__R, *out__J;

	printf("\nText paragraph display settings: %d\n", flags);

	out__b = (flags&bold) ? "bold" : "";
	out__i = (flags&italic) ? "italic" : "";
	out__u = (flags&underline) ? "underline" : "";
	out__L = (flags&Left) ? "Left" : "";
	out__C = (flags&Center) ? "Center" : "";
	out__R = (flags&Right) ? "Right" : "";
	out__J = (flags&Justify) ? "Justify" : "";

	if (flags & 0xFF00) {
		printf("\nStyle: %s %s %s", out__b, out__i, out__u);
		printf("\nHorAlign: %s %s %s %s", out__L, out__C, out__R, out__J);
	}
	printf("\nSize: %d", flags & 0xFF);
};