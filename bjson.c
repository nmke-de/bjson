#include <stdio.h>

#define TABS for (int i = 0; i < indent; i++) fputc('\t', stdout);

int main() {
	char c;
	int indent = 0;
	while((c = fgetc(stdin)) != EOF) {
		if (c == '}' || c == ']') {
			fputc('\n', stdout);
			--indent;
			TABS
		}
		fputc(c, stdout);
		switch (c) {
			case '{':
			case '[':
				fputc('\n', stdout);
				++indent;
				TABS
				break;
			case ',':
			case '}':
			case ']':
				fputc('\n', stdout);
				TABS
				break;
			default:
				continue;
		}
	}
}
