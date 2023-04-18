#include <stdio.h>

// This macro is used to generate indentation.
#define TABS for (int i = 0; i < indent; i++) fputc('\t', stdout);

int main() {
	// Currently read character
	char c;
	// Indentation level
	int indent = 0;
	// Boolean. Whether current section is quoted or not
	int quoted = 0;
	// Previously read character
	char prev = 0;
	// Iterate over all characters
	while((c = fgetc(stdin)) != EOF) {
		// Do stuff before printing the current character.
		// Print newline before closing brackets.
		if (!quoted && (c == '}' || c == ']')) {
			fputc('\n', stdout);
			--indent;
			TABS
		}
		// Print the current character.
		fputc(c, stdout);
		// Do stuff after printing the current character.
		switch (c) {
			// Switch quoted.
			case '"':
				if (prev != '\\')
					quoted = !quoted;
				break;
			// Print newline after opening brackets.
			case '{':
			case '[':
				if (quoted)
					break;
				fputc('\n', stdout);
				++indent;
				TABS
				break;
			// Print newline after commas.
			case ',':
				if (quoted)
					break;
				fputc('\n', stdout);
				TABS
				break;
			// Print space after colons.
			case ':':
				if (!quoted)
					fputc(' ', stdout);
				break;
			default:
				break;
		}
		// Assign prev. This is important to check for escaped characters.
		prev = c;
	}
	// Print newline at the end.
	fputc('\n', stdout);
}
