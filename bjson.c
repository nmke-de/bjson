#include <stdio.h>

#define TABS for (int i = 0; i < indent; i++) fputc('\t', stdout);

int main() {
	char c;
	int indent = 0;
	int quoted = 0;
	char prev = 0;
	while((c = fgetc(stdin)) != EOF) {
		if (!quoted && (c == '}' || c == ']')) {
			fputc('\n', stdout);
			--indent;
			TABS
		}
		fputc(c, stdout);
		switch (c) {
			case '"':
				if (prev != '\\')
					quoted = !quoted;
				break;
			case '{':
			case '[':
				if (quoted)
					break;
				fputc('\n', stdout);
				++indent;
				TABS
				break;
			case ',':
			case '}':
			case ']':
				if (quoted)
					break;
				fputc('\n', stdout);
				TABS
				break;
			default:
				break;
		}
		prev = c;
	}
}
